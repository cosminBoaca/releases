// ======================================================================
//
// Copyright (c) 2001 The CGAL Consortium

// This software and related documentation are part of the Computational
// Geometry Algorithms Library (CGAL).
// This software and documentation are provided "as-is" and without warranty
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
// - Please check the CGAL web site http://www.cgal.org/index2.html for 
//   availability.
//
// The CGAL Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Freie Universitaet Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbrucken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).
//
// ----------------------------------------------------------------------
//
// release       : CGAL-2.4
// release_date  : 2002, May 16
//
// file          : include/CGAL/IO/Segment_circle_Window_stream.h
// package       : Arrangement (2.52)
// author(s)     : Ron Wein
// coordinator   : Tel-Aviv University (Dan Halperin)
//
// email         : contact@cgal.org
// www           : http://www.cgal.org
//
// ======================================================================
#ifndef SEGMENT_CIRCLE_WINDOW_STREAM_H
#define SEGMENT_CIRCLE_WINDOW_STREAM_H

#include <CGAL/IO/Window_stream.h>

#include <CGAL/Segment_circle_2.h>

CGAL_BEGIN_NAMESPACE

template <class NT>
Window_stream& operator<<(Window_stream& os,
                          const Segment_circle_2<NT>& cv)
{
  double sx = CGAL::to_double(cv.source().x()),
         sy = CGAL::to_double(cv.source().y()),
         tx = CGAL::to_double(cv.target().x()),
         ty = CGAL::to_double(cv.target().y());

  if (cv.is_segment())
  {
    os << leda_segment(sx, sy, tx, ty);
  } 
  // The arc is circular
  else
  {
    // We need a middle point on the curve for the leda draw_arc
    // function which draws a circular arc given three points on it.
    
    double px,py; // middle point coordinates
    if (cv.is_x_monotone())
    {
      // an x-monotone circular arc 
      // the middle point is the one with average x value of endpoints.
      Segment_circle_2<NT>::Point ps[2];
      NT middle_x = (sx+tx)/2;
      cv.get_points_at_x(middle_x, ps);
      px = CGAL::to_double(middle_x);
      py = CGAL::to_double(ps[0].y());
     }
    else
    {
      // a non x-monotone circular arc
      // we use the rightmost or leftmost point as a middle point
      Segment_circle_2<NT>::Point ps[2];
      // there might be two tangency points but we care for one only
      cv.horizontal_tangency_points (ps);
      px = CGAL::to_double(ps[0].x());
      py = CGAL::to_double(ps[0].y());
    }
    
    os.draw_arc(leda_point(sx,sy), leda_point(px,py), leda_point(tx,ty));
  }

  return os; 
}

CGAL_END_NAMESPACE

#endif