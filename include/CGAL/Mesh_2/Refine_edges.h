// Copyright (c) 2004-2006  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.3-branch/Mesh_2/include/CGAL/Mesh_2/Refine_edges.h $
// $Id: Refine_edges.h 35459 2006-12-07 15:57:16Z lrineau $
// 
//
// Author(s)     : Laurent RINEAU

#ifndef CGAL_MESH_2_REFINE_EDGES_H
#define CGAL_MESH_2_REFINE_EDGES_H

#include <CGAL/Mesher_level.h>
#include <CGAL/Mesh_2/Triangulation_mesher_level_traits_2.h>
#include <CGAL/Mesh_2/Filtered_queue_container.h>

#include <utility>
#include <iterator>
#include <boost/iterator/filter_iterator.hpp>
#include <boost/iterator/transform_iterator.hpp>

namespace CGAL {

/**
 * \namespace Mesh_2
 *   Defines classes that are not yet documented.
 * 
 * \namespace Mesh_2::details
 *   Namespace for internal use.
 */

namespace Mesh_2 {

  namespace details {

    /** This class defines several auxiliary types for \c Refine_edges. */
    template <typename Tr>
    struct Refine_edges_base_types
    {
      typedef typename Tr::Vertex_handle Vertex_handle;

      typedef std::pair<Vertex_handle,
                        Vertex_handle> Constrained_edge;

      /** Object predicate that tests if a given \c Constrained_Edge is
          really an edge of the triangulation and is constrained.
      */
      class Is_a_constrained_edge {
        const Tr& tr;
      public:
        /** \param tr_ points to the triangulation. */
        explicit Is_a_constrained_edge(const Tr& tr_) : tr(tr_) {}

        bool operator()(const Constrained_edge& ce) const
        {
          typename Tr::Face_handle fh;
          int i;
          return tr.is_edge(ce.first, ce.second, fh,i) &&
            fh->is_constrained(i);
        }
      };

      typedef ::CGAL::Mesh_2::Filtered_queue_container<Constrained_edge,
                                               Is_a_constrained_edge>
                           Default_container;
    };

  }; // end namespace details


  /**
   * Predicate class that verifies that an edge is strictly locally
   * conforming Gabriel. Moreover, This classes defines a predicate that
   * test if an edge is encroached by a given point.
   * \param Tr The type of the triangulation.
   */
  template <typename Tr>
  struct Is_locally_conforming_Gabriel
  {
    typedef typename Tr::Vertex_handle Vertex_handle;
    typedef typename Tr::Face_handle Face_handle;
    typedef typename Tr::Point Point;
    typedef typename Tr::Geom_traits Geom_traits;

    /** Operator that takes an edge (\c fh, \c index). */
    bool operator()(Tr& tr,
                    const Face_handle& fh,
                    const int i) const
    {
      const Vertex_handle& va = fh->vertex(tr. cw(i));
      const Vertex_handle& vb = fh->vertex(tr.ccw(i));

      const Vertex_handle& vi = fh->vertex(i);
      const Vertex_handle& mvi = tr.tds().mirror_vertex(fh, i);

      return( ( tr.is_infinite(vi) || 
                this->operator()(tr, va, vb, vi->point()) )
              &&
              ( tr.is_infinite(mvi) || 
                this->operator()(tr, va, vb, mvi->point()) )
              );
    }

    /** Operator that takes an edge (\c va, \c vb). */
    bool operator()(Tr& tr,
                    const Vertex_handle& va,
                    const Vertex_handle& vb) const
    {
      Face_handle fh;
      int i;
      CGAL_assertion_code( bool should_be_true = )
      tr.is_edge(va, vb, fh, i);
      CGAL_assertion( should_be_true == true );
      
      return this->operator()(tr, fh, i);
    }

    /**
     * Operator that takes an edge (\c fh, \c index) and a point \c p.
     * Tests if the point encroached the edge.
     */
    bool operator()(Tr& tr,
                    const Face_handle& fh,
                    const int i,
                    const Point& p) const
    {
      return this->operator()(tr,
                              fh->vertex(tr. cw(i)),
                              fh->vertex(tr.ccw(i)),
                              p);
    }

    /**
     * Operator that takes an edge (\c va, \c vb) and a point \c p.
     * Tests if the point encroached the edge.
     */
    bool operator()(Tr& tr,
                    const Vertex_handle& va,
                    const Vertex_handle& vb,
                    const Point& p) const
      {
        typedef typename Geom_traits::Angle_2 Angle_2;

        const Angle_2 angle = tr.geom_traits().angle_2_object();

        const Point& a = va->point();
        const Point& b = vb->point();

        return( angle(a, p, b) == ACUTE );
      }
  };

  /**
   * Predicate class that verifies that an edge is strictly locally
   * conforming Delaunay.
   * \param Tr The type of the triangulation.
   */
  template <typename Tr>
  struct Is_locally_conforming_Delaunay
  {
    typedef typename Tr::Vertex_handle Vertex_handle;
    typedef typename Tr::Face_handle Face_handle;
    typedef typename Tr::Point Point;
    typedef typename Tr::Geom_traits Geom_traits;

    /** Operator that takes an edge (\c fh, \c index). */
    bool operator()(Tr& tr,
                    const Face_handle& fh,
                    const int i) const
    {
      Vertex_handle vi;
      Vertex_handle mvi;

      if(aux_get_vi_mvi(tr, fh, i, vi, mvi)) {
        return true;
      }

      const Vertex_handle& va = fh->vertex(tr. cw(i));
      const Vertex_handle& vb = fh->vertex(tr.ccw(i));

      return aux_outside_of_circle(tr, vi, vb, va, mvi);
    }

    /** Operator that takes an edge (\c va, \c vb). */
    bool operator()(Tr& tr,
                    const Vertex_handle& va,
                    const Vertex_handle& vb) const
    {
      Face_handle fh;
      int i;
      CGAL_assertion_code( bool test = )
        tr.is_edge(va, vb, fh, i);
      CGAL_assertion( test == true );

      Vertex_handle vi;
      Vertex_handle mvi;

      if(aux_get_vi_mvi(tr, fh, i, vi, mvi)) {
        return true;
      }

      return aux_outside_of_circle(tr, vi, vb, va, mvi);
    }

  private:
    /** Private function that computes the two vertex vi and mvi that are
	one each side of the edge (fh, i) (vi is in fh and mvi is in
	fh->neighbor(i)) and return true if one of them is infinite.
    */
    bool
    aux_get_vi_mvi(Tr& tr,
		   const Face_handle& fh,
		   const int i,
		   Vertex_handle& vi,
		   Vertex_handle& mvi) const
    {
      vi = fh->vertex(i);
      mvi = tr.tds().mirror_vertex(fh, i);

      return ( tr.is_infinite(vi) || tr.is_infinite(mvi) );
    }

    /** Private function that returns true if the vertex vs is outside the
	oriented circle passing through vp, vq and vr.
    */
    bool
    aux_outside_of_circle(Tr& tr,
			  const Vertex_handle& vp,
			  const Vertex_handle& vq,
			  const Vertex_handle& vr,
			  const Vertex_handle& vs) const
    {
      typedef typename Geom_traits::Side_of_oriented_circle_2
        Side_of_oriented_circle_2;

      Side_of_oriented_circle_2 in_circle =
        tr.geom_traits().side_of_oriented_circle_2_object();
      
      const Point& p = vp->point();
      const Point& q = vq->point();
      const Point& r = vr->point();
      const Point& s = vs->point();

      return ( in_circle(p, q, r, s) == ON_NEGATIVE_SIDE );
    }
  }; // end of struct Is_locally_conforming_Delaunay

/**
 * This class is the base for the first level of Mesh_2: the edge
 * conforming level. It does not handle clusters.
 *
 * \param Tr is the type of triangulation on which the level acts.
 * \param Is_locally_conform defines the locally conform criterion: Gabriel
 *        or Delaunay. It defaults to the Garbriel criterion.
 * \param Container is the type of container. It defaults to a filtered
 *        queue of \c Vertex_handle pair (see \c Filtered_queue_container).
 */
template <
  class Tr,
  class Is_locally_conform = Is_locally_conforming_Gabriel<Tr>,
  class Container = 
    typename details::Refine_edges_base_types<Tr>::Default_container
>
class Refine_edges_base :
    public No_private_test_point_conflict,
    public No_after_no_insertion
{
public:
  typedef typename Tr::Finite_edges_iterator Finite_edges_iterator;
  typedef typename Tr::Face_circulator Face_circulator;
  
  typedef typename Tr::Vertex_handle Vertex_handle;
  typedef typename Tr::Face_handle Face_handle;
  typedef typename Tr::Edge Edge;
  typedef typename Tr::Point Point;
  typedef typename Tr::Geom_traits Geom_traits;

  typedef Triangulation_mesher_level_traits_2<Tr> Triangulation_traits;

  typedef typename Triangulation_traits::Zone Zone;

  typedef typename details::Refine_edges_base_types<Tr>::Constrained_edge
                               Constrained_edge;

protected:
  /* --- protected datas --- */

  Tr& tr; /**< The triangulation itself. */

  /** Predicates to filter edges. */
  typedef typename details::Refine_edges_base_types<Tr>
     ::Is_a_constrained_edge Is_a_constrained_edge;

  const Is_a_constrained_edge is_a_constrained_edge;

  Container edges_to_be_conformed; /**< Edge queue */

  /** The object predicate that defines the locally conform criteria. */
  Is_locally_conform is_locally_conform;

  Vertex_handle va, vb;

  bool imperatively;

public:
  /** \name CONSTRUCTORS */

  Refine_edges_base(Tr& tr_) :
    tr(tr_), is_a_constrained_edge(tr_),
    edges_to_be_conformed(is_a_constrained_edge),
    is_locally_conform(), imperatively(false), converter(tr_)
  {
  }

  /** \name HELPING FUNCTIONS */

  void clear()
  {
    edges_to_be_conformed.clear();
  }

  void set_imperative_refinement(bool b)
  {
    imperatively = b;
  }

  /** \name Functions that this level must declare. */

  Tr& triangulation_ref_impl()
  {
    return tr;
  }

  const Tr& triangulation_ref_impl() const
  {
    return tr;
  }

  Zone conflicts_zone_impl(const Point& p, Edge edge)
  {
    Zone zone;

    typedef std::back_insert_iterator<typename Zone::Faces> OutputItFaces;
    typedef std::back_insert_iterator<typename Zone::Edges> OutputItEdges;

    OutputItFaces faces_out(zone.faces);
    OutputItEdges edges_out(zone.boundary_edges);

    const Face_handle& f = edge.first;
    const int i = edge.second;
    *faces_out++ = f;
    const Face_handle n = f->neighbor(i);
    *faces_out++ = n;
    const int ni = triangulation_ref_impl().tds().mirror_index(f, i);
    std::pair<OutputItFaces,OutputItEdges>
    pit = std::make_pair(faces_out,edges_out);
    pit = triangulation_ref_impl().propagate_conflicts(p,f,Tr::ccw(i),pit);
    pit = triangulation_ref_impl().propagate_conflicts(p,f,Tr:: cw(i),pit);
    pit = triangulation_ref_impl().propagate_conflicts(p,n,Tr::ccw(ni),pit);
    pit = triangulation_ref_impl().propagate_conflicts(p,n,Tr:: cw(ni),pit);
    return zone; 
  }

  Vertex_handle insert_impl(const Point& p, Zone& zone)
  {
    return triangulation_ref_impl().star_hole(p,
					      zone.boundary_edges.begin(),
					      zone.boundary_edges.end(),
					      zone.faces.begin(),
					      zone.faces.end()
					      );
  }

  /** Scans all constrained edges and put them in the queue if they are
      encroached. */
  void scan_triangulation_impl()
  {
    clear();
#ifndef CGAL_IT_IS_A_CONSTRAINED_TRIANGULATION_PLUS
    for(Finite_edges_iterator ei = tr.finite_edges_begin();
        ei != tr.finite_edges_end();
        ++ei)
      if(ei->first->is_constrained(ei->second) &&
         !is_locally_conform(tr, ei->first, ei->second) )
        add_constrained_edge_to_be_conformed(*ei);
    
#else
  for(typename Tr::Subconstraint_iterator it = tr.subconstraints_begin();
      it != tr.subconstraints_end(); ++it) 
    {
      const Vertex_handle& v1 = it->first.first;
      const Vertex_handle& v2 = it->first.second;
      
      if(fh->is_constrained(i) &&
         !is_locally_conform(tr, v1, v2) )
        add_constrained_edge_to_be_conformed(v1, v2);
    }
#endif
  } // end scan_triangulation_impl()

  /** Tells if the queue of edges to be conformed is empty or not. */
  bool no_longer_element_to_refine_impl()
  {
    return edges_to_be_conformed.empty();
  }

  /** Get the next edge to conform. */
  Edge get_next_element_impl() 
  {
    Constrained_edge edge = edges_to_be_conformed.get_next_element();

    Face_handle fh;
    int index;

    CGAL_assertion_code( bool should_be_true =)
    tr.is_edge(edge.first, edge.second, fh, index);
    CGAL_assertion( should_be_true == true );

    return Edge(fh, index);
  }

  /** Pop the first edge of the queue. */
  void pop_next_element_impl()
  {
    edges_to_be_conformed.remove_next_element();
  }

  /** This version computes the refinement point without handling
      clusters. The refinement point of an edge is just the middle point of
      the segment.
      Saves the handles of the edge that will be splitted.
      This function is overridden in class Refine_edge_with_clusters.
  */
  Point refinement_point_impl(const Edge& edge) 
  {
    typename Geom_traits::Construct_midpoint_2
      midpoint = tr.geom_traits().construct_midpoint_2_object();

    va = edge.first->vertex(tr.cw (edge.second));
    vb = edge.first->vertex(tr.ccw(edge.second));

    return midpoint(va->point(), vb->point());
  }

  /** Does nothing. */
  void before_conflicts_impl(const Edge&, const Point&)
  {
  }

  /**
   * Test if the edges of the boundary are locally conforming.
   * Push which that are not in the list of edges to be conformed.
   */
  Mesher_level_conflict_status
  test_point_conflict_from_superior_impl(const Point& p,
					 Zone& zone)
  {
    Mesher_level_conflict_status status = NO_CONFLICT;
    
    for(typename Zone::Edges_iterator eit = zone.boundary_edges.begin();
        eit != zone.boundary_edges.end(); ++eit)
      { 
        const Face_handle& fh = eit->first;
        const int& i = eit->second;

        if(fh->is_constrained(i) && !is_locally_conform(tr, fh, i, p))
          {
            add_constrained_edge_to_be_conformed(*eit);
	    status = CONFLICT_BUT_ELEMENT_CAN_BE_RECONSIDERED;
          }
      }

    return status;
  }

  /** Unmark as constrained. */
  void before_insertion_impl(const Edge& e, const Point&,
			     const Zone&)
  {
    const Face_handle& f = e.first;
    const int& i = e.second;

    f->set_constraint(i, false);
    (f->neighbor(i))->set_constraint(triangulation_ref_impl().tds().mirror_index(f, i), false);
  }

  /**
   * Scans the edges of the star boundary, to test if they are both
   * locally conforming. If not, push them in the list of edges to be
   * conformed.
   * 
   */
  void after_insertion_impl(const Vertex_handle& v)
  {
#ifdef CGAL_MESH_2_VERBOSE
    std::cerr << "E";
#endif
    // @todo Perhaps we should remove destroyed edges too.
    // @warning This code has been rewroten!

    Face_circulator fc = tr.incident_faces(v), fcbegin(fc);
    if( fc == 0 ) return;

    do {
      const int i = fc->index(v);
      CGAL_assertion( i>=0 && i < 4);
      if( fc->is_constrained(i) &&
          !is_locally_conform(tr, fc, i) )
        add_constrained_edge_to_be_conformed(Edge(fc, i));
      ++fc;
    } while( fc != fcbegin );

    Face_handle fh;
    int index;

    CGAL_assertion_code(bool is_edge = )
    tr.is_edge(va, v, fh, index);
    CGAL_assertion(is_edge == true);

    fh->set_constraint(index, true);
    fh->neighbor(index)->set_constraint(triangulation_ref_impl().tds().mirror_index(fh, index), true);

    CGAL_assertion_code( is_edge = )
    tr.is_edge(vb, v, fh, index);
    CGAL_assertion(is_edge == true);

    fh->set_constraint(index, true);
    fh->neighbor(index)->set_constraint(triangulation_ref_impl().tds().mirror_index(fh, index), true);

    if(!is_locally_conform(tr, va, v))
      add_constrained_edge_to_be_conformed(va, v);
    
    if(!is_locally_conform(tr, vb, v))
      add_constrained_edge_to_be_conformed(vb, v);
  } // end after_insertion_impl

protected:
  /** \name Auxiliary functions */

  /** Add an \c Edge \c e in the queue. */
  void add_constrained_edge_to_be_conformed(const Edge& e)
  {
    const Vertex_handle& va = e.first->vertex(tr. cw(e.second));
    const Vertex_handle& vb = e.first->vertex(tr.ccw(e.second));
    edges_to_be_conformed.add_element(std::make_pair(va, vb));
  }

  /** Add an edge (\c va,\c  vb) in the queue. */
  void add_constrained_edge_to_be_conformed(const Vertex_handle& va,
                                            const Vertex_handle& vb)
  {
    edges_to_be_conformed.add_element(std::make_pair(va, vb));
  }

private: /** \name DEBUGGING TYPES AND DATAS */
  class From_pair_of_vertex_to_edge 
    : public std::unary_function<Constrained_edge, Edge>
  {
    Tr& tr;
  public:
    From_pair_of_vertex_to_edge(Tr& t) : tr(t) {};

    const Edge operator()(const Constrained_edge edge) const
    {
      Face_handle fh;
      int index;
      tr.is_edge(edge.first, edge.second, fh, index);
      return Edge(fh, index);
    }
  }; // end From_pair_of_vertex_to_edge

  // -- private data member --
  From_pair_of_vertex_to_edge converter;

private:

  typedef boost::filter_iterator<Is_a_constrained_edge,
                                 typename Container::const_iterator>
    Aux_edges_filter_iterator;

public:  /** \name DEBUGGING FUNCTIONS */
  typedef boost::transform_iterator<
    From_pair_of_vertex_to_edge,
    Aux_edges_filter_iterator> Edges_const_iterator;

  Edges_const_iterator begin() const
  {
    return Edges_const_iterator(
       Aux_edges_filter_iterator(is_a_constrained_edge,
                                 this->edges_to_be_conformed.begin(),
                                 this->edges_to_be_conformed.end()),
       converter);
  }

  Edges_const_iterator end() const
  {
    return Edges_const_iterator(
       Aux_edges_filter_iterator(is_a_constrained_edge,
                                 this->edges_to_be_conformed.end(),
                                 this->edges_to_be_conformed.end()),
       converter);
  }
}; // end class Refine_edges_base

  namespace details {
    template <typename Tr, typename Self>
    struct Refine_edges_types
    {
      typedef Triangulation_mesher_level_traits_2<Tr> Triangulation_traits;

      typedef Mesher_level <
	Tr,
        Self,
        typename Tr::Edge,
        Null_mesher_level,
	Triangulation_traits> Edges_mesher_level;
    }; // end Refine_edges_types
  } // end namespace details

template <typename Tr,
          typename Is_locally_conform = Is_locally_conforming_Gabriel<Tr>,
          typename Base = Refine_edges_base<Tr, Is_locally_conform> >
struct Refine_edges : 
  public Base, 
  public details::Refine_edges_types<Tr, 
    Refine_edges<Tr, Is_locally_conform, Base> >::Edges_mesher_level
{
  typedef Refine_edges<Tr, Is_locally_conform, Base> Self;

  typedef typename details::Refine_edges_types<Tr,
					       Self> Types;

  typedef typename Types::Edges_mesher_level Mesher;
public:
  Refine_edges(Tr& t, 
	       Null_mesher_level& null_level)
    : Base(t), Mesher(null_level)
  {
  }
}; // end Refine_edges


} // end namespace Mesh_2

} // end namespace CGAL

#endif // CGAL_MESH_2_REFINE_EDGES_H
