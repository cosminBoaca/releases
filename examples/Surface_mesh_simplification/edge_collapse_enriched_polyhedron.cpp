#include <iostream>
#include <fstream>

#include <CGAL/Simple_cartesian.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h>

// Adaptor for Polyhedron_3
#include <CGAL/Surface_mesh_simplification/HalfedgeGraph_Polyhedron_3.h>

// Simplification function
#include <CGAL/Surface_mesh_simplification/edge_collapse.h>

// Extended polyhedron items which include an id() field
#include <CGAL/Polyhedron_items_with_id_3.h>

// Stop-condition policy
#include <CGAL/Surface_mesh_simplification/Policies/Edge_collapse/Count_ratio_stop_predicate.h>

// Non-default cost and placement policies
#include <CGAL/Surface_mesh_simplification/Policies/Edge_collapse/Midpoint_and_length.h> 

typedef CGAL::Simple_cartesian<double> Kernel;

typedef Kernel::Point_3 Point ;

//
// Setup an enriched polyhedron type which stores an id() field in the items
//
typedef CGAL::Polyhedron_3<Kernel,CGAL::Polyhedron_items_with_id_3> Surface; 

typedef Surface::Halfedge_handle Halfedge_handle ;

namespace SMS = CGAL::Surface_mesh_simplification ;

typedef SMS::Edge_profile<Surface> Profile ;


// The following is a Visitor that keeps track of the simplification process.
// In this example the progress is printed real-time and a few statistics are
// recorded (and printed in the end).
//
struct Visitor
{
  Visitor() 
    : collected(0)
    , processed(0)
    , collapsed(0)
    , non_collapsable(0)
    , cost_uncomputable(0) 
    , placement_uncomputable(0) 
  {} 

  // Called on algorithm entry  
  void OnStarted( Surface& ) {} 
  
  // Called on algorithm exit  
  void OnFinished ( Surface& ) { std::cerr << "\n" << std::flush ; } 
  
  // Called when the stop condition returned true
  void OnStopConditionReached( Profile const& ) {} 
  
  // Called during the collecting phase for each edge collected.
  void OnCollected( Profile const&, boost::optional<double> const& )
  {
    ++ collected ;
    std::cerr << "\rEdges collected: " << collected << std::flush ;
  }                
  
  // Called during the processing phase for each edge selected.
  // If cost is absent the edge won't be collapsed.
  void OnSelected(Profile const&          
                 ,boost::optional<double> cost
                 ,std::size_t             initial
                 ,std::size_t             current
                 )
  {
    ++ processed ;
    if ( !cost )
      ++ cost_uncomputable ;
      
    if ( current == initial )
      std::cerr << "\n" << std::flush ;
    std::cerr << "\r" << current << std::flush ;
  }                
  
  // Called during the processing phase for each edge being collapsed.
  // If placement is absent the edge is left uncollapsed.
  void OnCollapsing(Profile const&          
                   ,boost::optional<Point>  placement
                   )
  {
    if ( placement )
         ++ collapsed;
    else ++ placement_uncomputable ;
  }                
  
  // Called for each edge which failed the so called link-condition,
  // that is, which cannot be collapsed because doing so would
  // turn the surface into a non-manifold.
  void OnNonCollapsable( Profile const& )
  {
    ++ non_collapsable;
  }                
  
  std::size_t  collected
             , processed
             , collapsed
             , non_collapsable
             , cost_uncomputable  
             , placement_uncomputable ; 
} ;


int main( int argc, char** argv ) 
{
  Surface surface; 
  
  std::ifstream is(argv[1]) ; is >> surface ;

  // The items in this polyhedron have an "id()" field 
  // which the default index maps used in the algorithm
  // need to get the index of a vertex/edge.
  // However, the Polyhedron_3 class doesn't assign any value to
  // this id(), so we must do it here:
  int index = 0 ;
  
  for( Surface::Halfedge_iterator eb = surface.halfedges_begin()
     , ee = surface.halfedges_end()
     ; eb != ee
     ; ++ eb
     ) 
    eb->id() = index++;

  index = 0 ;
  for( Surface::Vertex_iterator vb = surface.vertices_begin()
     , ve = surface.vertices_end()
     ; vb != ve
     ; ++ vb
     ) 
    vb->id() = index++;
    
  // In this example, the simplification stops when the number of undirected edges
  // drops below 10% of the initial count
  SMS::Count_ratio_stop_predicate<Surface> stop(0.1);
     
  Visitor vis ;
  
  // The index maps are not explicitelty passed as in the previous
  // example because the surface items have a proper id() field.
  // On the other hand, we pass here explicit cost and placement
  // function which differ from the default policies, ommited in
  // the previous example.
  int r = SMS::edge_collapse
           (surface
           ,stop
           ,CGAL::get_cost     (SMS::Edge_length_cost  <Surface>())
                 .get_placement(SMS::Midpoint_placement<Surface>())
                 .visitor(&vis)
           );
  
  std::cout << "\nEdges collected: " << vis.collected
            << "\nEdges proccessed: " << vis.processed
            << "\nEdges collapsed: " << vis.collapsed
            << std::endl
            << "\nEdges not collapsed due to topological constrians: " 
            << vis.non_collapsable
            << "\nEdge not collapsed due to cost computation constrians: " 
            << vis.cost_uncomputable 
            << "\nEdge not collapsed due to placement computation constrians: " 
            << vis.placement_uncomputable 
            << std::endl ; 
            
  std::cout << "\nFinished...\n" << r << " edges removed.\n" 
            << (surface.size_of_halfedges()/2) << " final edges.\n" ;
        
  std::ofstream os( argc > 2 ? argv[2] : "out.off" ) ; os << surface ;
  
  return 0 ;      
}

// EOF //
