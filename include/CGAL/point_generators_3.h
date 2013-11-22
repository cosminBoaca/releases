// ======================================================================
//
// Copyright (c) 1997 The CGAL Consortium

// This software and related documentation is part of the Computational
// Geometry Algorithms Library (CGAL).
// This software and documentation is provided "as-is" and without warranty
// of any kind. In no event shall the CGAL Consortium be liable for any
// damage of any kind. 
//
// Every use of CGAL requires a license. 
//
// Academic research and teaching license
// - For academic research and teaching purposes, permission to use and copy
//   the software and its documentation is hereby granted free of charge,
//   provided that it is not a component of a commercial product, and this
//   notice appears in all copies of the software and related documentation. 
//
// Commercial licenses
// - A commercial license is available through Algorithmic Solutions, who also
//   markets LEDA (http://www.algorithmic-solutions.de). 
// - Commercial users may apply for an evaluation license by writing to
//   Algorithmic Solutions (contact@algorithmic-solutions.com). 
//
// The CGAL Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Free University of Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbrucken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).
//
// ----------------------------------------------------------------------
//
// release       : CGAL-2.1
// release_date  : 2000, January 11
//
// file          : include/CGAL/point_generators_3.h
// package       : Generator (2.23)
// chapter       : $CGAL_Chapter: Geometric Object Generators $
// source        : generators.fw
// revision      : $Revision: 1.14 $
// revision_date : $Date: 1999/06/03 19:55:31 $
// author(s)     : Lutz Kettner
//
// coordinator   : INRIA, Sophia Antipolis
//
// 3D Point Generators
// email         : cgal@cs.uu.nl
//
// ======================================================================

#ifndef CGAL_POINT_GENERATORS_3_H
#define CGAL_POINT_GENERATORS_3_H 1
#ifndef CGAL_GENERATORS_H
#include <CGAL/generators.h>
#endif
#ifndef CGAL_POINT_GENERATORS_2_H
#include <CGAL/point_generators_2.h>
#endif

CGAL_BEGIN_NAMESPACE

#ifndef CGAL_CFG_NO_DEFAULT_PREVIOUS_TEMPLATE_ARGUMENTS
template < class P, class Creator = Creator_uniform_3<double,P> >
#else
template < class P, class Creator >
#endif
class Random_points_in_sphere_3 : public _Random_generator_base<P> {
    void generate_point();
public:
    typedef Random_points_in_sphere_3<P,Creator> This;
    Random_points_in_sphere_3( double r = 1, Random& rnd = default_random)
        // g is an input iterator creating points of type `P' uniformly
        // distributed in the open sphere with radius r, i.e. |`*g'| < r .
        // Three random numbers are needed from `rnd' for each point.
    : _Random_generator_base<P>( r, rnd) { generate_point(); }
    This& operator++()    {
        generate_point();
        return *this;
    }
    This  operator++(int) {
        This tmp = *this;
        ++(*this);
        return tmp;
    }
};

template < class P, class Creator >
void
Random_points_in_sphere_3<P,Creator>::
generate_point() {
    do {
        Creator creator;
        d_item = creator( d_range * ( 2 * _rnd.get_double() - 1.0),
                          d_range * ( 2 * _rnd.get_double() - 1.0),
                          d_range * ( 2 * _rnd.get_double() - 1.0));
    } while ( d_item.x() * d_item.x() + d_item.y() * d_item.y() >=
              d_range * d_range);
}


#ifndef CGAL_CFG_NO_DEFAULT_PREVIOUS_TEMPLATE_ARGUMENTS
template < class P, class Creator = Creator_uniform_3<double,P> >
#else
template < class P, class Creator >
#endif
class Random_points_on_sphere_3 : public _Random_generator_base<P> {
    void generate_point();
public:
    typedef Random_points_on_sphere_3<P,Creator> This;
    Random_points_on_sphere_3( double r = 1, Random& rnd = default_random)
        // g is an input iterator creating points of type `P' uniformly
        // distributed on the circle with radius r, i.e. |`*g'| == r . A
        // single random number is needed from `rnd' for each point.
    : _Random_generator_base<P>( r, rnd) { generate_point(); }
    This& operator++()    {
        generate_point();
        return *this;
    }
    This  operator++(int) {
        This tmp = *this;
        ++(*this);
        return tmp;
    }
};

template < class P, class Creator >
void
Random_points_on_sphere_3<P,Creator>::
generate_point() {
    double alpha = _rnd.get_double() * 2.0 * M_PI;
    double z     = 2 * _rnd.get_double() - 1.0;
    double r     = std::sqrt( 1 - z * z);
    Creator creator;
    d_item = creator( d_range * r * CGAL_CLIB_STD::cos(alpha),
                      d_range * r * CGAL_CLIB_STD::sin(alpha),
                      d_range * z);
}


#ifndef CGAL_CFG_NO_DEFAULT_PREVIOUS_TEMPLATE_ARGUMENTS
template < class P, class Creator = Creator_uniform_3<double,P> >
#else
template < class P, class Creator >
#endif
class Random_points_in_cube_3 : public _Random_generator_base<P>{
    void generate_point();
public:
    typedef Random_points_in_cube_3<P,Creator> This;
    Random_points_in_cube_3( double a = 1, Random& rnd = default_random)
    : _Random_generator_base<P>( a, rnd) { generate_point(); }
    This& operator++()    {
        generate_point();
        return *this;
    }
    This  operator++(int) {
        This tmp = *this;
        ++(*this);
        return tmp;
    }
};

template < class P, class Creator >
void
Random_points_in_cube_3<P,Creator>::
generate_point() {
    Creator creator;
    d_item = creator( d_range * ( 2 * _rnd.get_double() - 1.0),
                      d_range * ( 2 * _rnd.get_double() - 1.0),
                      d_range * ( 2 * _rnd.get_double() - 1.0));
}

CGAL_END_NAMESPACE
#endif // CGAL_POINT_GENERATORS_3_H //
// EOF //
