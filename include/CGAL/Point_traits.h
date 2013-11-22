// Copyright (c) 2005  INRIA Sophia-Antipolis (France).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Surface_mesher/include/CGAL/Point_traits.h $
// $Id: Point_traits.h 32195 2006-07-05 06:59:41Z lrineau $
// 
//
// Author(s)     : Laurent RINEAU

#ifndef CGAL_POINT_TRAITS_H
#define CGAL_POINT_TRAITS_H

#include <CGAL/Weighted_point.h>
#include <boost/config.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/static_assert.hpp>

namespace CGAL {

  template <class P>
  struct Is_weighted : public ::boost::mpl::false_ {} ;
  
  template <class P, typename FT>
  struct Is_weighted< ::CGAL::Weighted_point<P, FT> > :
    public ::boost::mpl::true_ {} ;
  
  namespace details {

    template <class P, typename FT, bool>
    struct Point_traits_aux 
    {
      // should give errors
    };

    template <class P, typename FT>
    struct Point_traits_aux<P, FT, false>
    {
      typedef P Point;
      typedef P Bare_point;
      typedef typename ::CGAL::Weighted_point<Bare_point, FT> Weighted_point;
      typedef Tag_false Is_weighted;
     
      const Bare_point& bare_point(const Point& bp)
      {
        return bp;
      }

      Weighted_point weighted_point(const Point& bp)
      {
        return Weighted_point(bp);
      }

      const Point& point(const Bare_point& bp)
      {
        return bp;
      }

      const Point& point(const Weighted_point& wp)
      {
        return wp.point();
      }
    }; // end class Point_traits_aux<P>

    template <class P, typename FT>
    struct Point_traits_aux<P, FT, true>
    {
      typedef P Point;
      typedef P Weighted_point;
      typedef typename Point::Point Bare_point;
      typedef Tag_true Is_weighted;
     
      const Bare_point& bare_point(const Point& wp)
      {
        return wp.point();
      }

      const Weighted_point& weighted_point(const Point& wp)
      {
        return wp;
      }

      Point point(const Bare_point& bp)
      {
        return Weighted_point(bp);
      }

      const Point& point(const Weighted_point& wp)
      {
        return wp;
      }
    }; // end class Point_traits_aux<P, FT, true>

    template <class Point>
    struct FT_of_point 
    {
      typedef typename CGAL::Kernel_traits<Point>::Kernel::FT type;
    };

  } // end namespace details

template <class Point>
class Point_traits
  : public details::Point_traits_aux<
      Point,
      typename details::FT_of_point<Point>::type,
      Is_weighted<Point>::value
    >
{
}; // end class Point_traits<T>

} // end namespace CGAL

#endif // CGAL_POINT_TRAITS_H
