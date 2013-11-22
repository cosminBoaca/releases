/* 

Copyright (c) 1997 The CGAL Consortium

This software and related documentation is part of the 
Computational Geometry Algorithms Library (CGAL).

Permission to use, copy, and distribute this software and its 
documentation is hereby granted free of charge, provided that 
(1) it is not a component of a commercial product, and 
(2) this notice appears in all copies of the software and
    related documentation. 

CGAL may be distributed by any means, provided that the original
files remain intact, and no charge is made other than for
reasonable distribution costs.

CGAL may not be distributed as a component of any commercial
product without a prior license agreement with the authors.

This software and documentation is provided "as-is" and without 
warranty of any kind. In no event shall the CGAL Consortium be
liable for any damage of any kind.

The CGAL Consortium consists of Utrecht University (The Netherlands), 
ETH Zurich (Switzerland), Free University of Berlin (Germany), 
INRIA Sophia-Antipolis (France), Max-Planck-Institute Saarbrucken
(Germany), RISC Linz (Austria), and Tel-Aviv University (Israel).

*/

#ifndef CGAL_CONVEX_HULL_TRAITS_CARTESIAN_DOUBLE_2_H
#define CGAL_CONVEX_HULL_TRAITS_CARTESIAN_DOUBLE_2_H

#include <CGAL/Point_2.h>
#include <CGAL/predicates_on_points_2.h>
#include <CGAL/distance_predicates_2.h>
#include <CGAL/predicate_objects_on_points_2.h>


template <class R> class CGAL_convex_hull_traits_2;

class CGAL_convex_hull_traits_2< CGAL_Cartesian<double> > 
  : public CGAL_Cartesian<double>
{
 public:

   typedef   CGAL_Cartesian<double>                         R;
   typedef   CGAL_Point_2<R>                                Point_2;    
   typedef   CGAL_p_Less_xy<Point_2>                        Less_xy;
   typedef   CGAL_p_Less_yx<Point_2>                        Less_yx;
   typedef   CGAL_p_Greater_xy<Point_2>                     Greater_xy;
   typedef   CGAL_p_Greater_yx<Point_2>                     Greater_yx;
   typedef   CGAL_p_Right_of_line_2p_safer<Point_2>         Right_of_line;
   typedef   CGAL_p_Less_negative_dist_to_line_2p<Point_2>  Less_dist_to_line;
   typedef   CGAL_p_Less_rotate_ccw_safer<Point_2>          Less_rotate_ccw;

   bool      leftturn(const Point_2& p,const Point_2& q,const Point_2& r) const
             {
               return ::CGAL_leftturn((const R::Point_2&)p,
                                      (const R::Point_2&)q,
                                      (const R::Point_2&)r ); 
             } 
 
   bool      rightturn(const Point_2& p,const Point_2& q,const Point_2& r) const
             {
               return ::CGAL_rightturn((const R::Point_2&)p,
                                       (const R::Point_2&)q,
                                       (const R::Point_2&)r ); 
             } 
 
   typedef   CGAL_Segment_2<R>                            Segment_2;    
};


#endif // CGAL_CONVEX_HULL_TRAITS_CARTESIAN_DOUBLE_2_H
