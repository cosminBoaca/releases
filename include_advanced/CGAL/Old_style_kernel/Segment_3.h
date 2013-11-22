// ============================================================================
//
// Copyright (c) 1999 The CGAL Consortium

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
// release       : CGAL-2.2
// release_date  : 2000, September 30
// 
// source        : web_3/advanced_3.fw
// file          : include/CGAL/Old_style_kernel/Segment_3.h
// revision      : 3.1
// revision_date : 06 Apr 2000 
// author(s)     : Stefan Schirra
//
//
// coordinator   : MPI, Saarbruecken  (<Stefan.Schirra>)
// email         : contact@cgal.org
// www           : http://www.cgal.org
//
// ======================================================================
 

#ifndef CGAL_OLD_STYLE_KERNEL_SEGMENT_3_H
#define CGAL_OLD_STYLE_KERNEL_SEGMENT_3_H

namespace CGAL {

template <class R_>
class Segment_3< R_, Old_style_tag> : public R_::Segment_3_base
{
 public:
  typedef  R_                        R;
  typedef typename R::RT             RT;
  typedef typename R::FT             FT;
  typedef typename R::Point_3_base   RPoint_3;
  typedef typename R::Segment_3_base RSegment_3;

  Segment_3() : RSegment_3() {}
  Segment_3(const RSegment_3& s) : RSegment_3(s) {}
  Segment_3(const RPoint_3& sp, const RPoint_3& ep) : RSegment_3(sp,ep) {}

  Line_3< R_, Old_style_tag>
  supporting_line() const
  { return RSegment_3::supporting_line(); }
};

} // namespace CGAL
#endif // CGAL_OLD_STYLE_KERNEL_SEGMENT_3_H
