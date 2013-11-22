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


// Author: Geert-Jan Giezeman

#ifndef CGAL_DISTANCE_3_2_H
#define CGAL_DISTANCE_3_2_H

#include <CGAL/Segment_3.h>
#include <CGAL/Line_3.h>
#include <CGAL/Ray_3.h>
#include <CGAL/Plane_3.h>
#include <CGAL/workaround_010.h>



template <class R>
extern R_FT_return(R)
CGAL_squared_distance(
    const CGAL_Point_3<R> &pt,
    const CGAL_Plane_3<R> &plane);

template <class R>
inline R_FT_return(R)
CGAL_squared_distance(
    const CGAL_Plane_3<R> & plane,
    const CGAL_Point_3<R> & pt)
{
    return CGAL_squared_distance(pt, plane);
}
template <class R>
extern R_FT_return(R)
CGAL_squared_distance(
    const CGAL_Line_3<R> &line,
    const CGAL_Plane_3<R> &plane);


template <class R>
inline R_FT_return(R)
CGAL_squared_distance(
    const CGAL_Plane_3<R> & p,
    const CGAL_Line_3<R> & line)
{
    return CGAL_squared_distance(line, p);
}
template <class R>
extern R_FT_return(R)
CGAL_squared_distance(
    const CGAL_Ray_3<R> &ray,
    const CGAL_Plane_3<R> &plane);


template <class R>
inline R_FT_return(R)
CGAL_squared_distance(
    const CGAL_Plane_3<R> & plane,
    const CGAL_Ray_3<R> & ray)
{
    return CGAL_squared_distance(ray, plane);
}
template <class R>
extern R_FT_return(R)
CGAL_squared_distance(
    const CGAL_Segment_3<R> &seg,
    const CGAL_Plane_3<R> &plane);


template <class R>
inline R_FT_return(R)
CGAL_squared_distance(
    const CGAL_Plane_3<R> & plane,
    const CGAL_Segment_3<R> & seg)
{
    return CGAL_squared_distance(seg, plane);
}



#ifdef CGAL_INCLUDE_TEMPLATE_CODE
#include <CGAL/squared_distance_3_2.C>
#endif


#endif
