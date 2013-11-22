// ======================================================================
//
// Copyright (c) 2000 The CGAL Consortium

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
// file          : include/CGAL/Cartesian/Tetrahedron_3.h
// package       : Cartesian_kernel (6.59)
// revision      : $Revision: 1.27 $
// revision_date : $Date: 2002/02/06 12:32:39 $
// author(s)     : Andreas Fabri
// coordinator   : INRIA Sophia-Antipolis
//
// email         : contact@cgal.org
// www           : http://www.cgal.org
//
// ======================================================================

#ifndef CGAL_CARTESIAN_TETRAHEDRON_3_H
#define CGAL_CARTESIAN_TETRAHEDRON_3_H

#include <CGAL/Cartesian/solve_3.h>
#include <vector>
#include <functional>

CGAL_BEGIN_NAMESPACE

template <class R_>
class TetrahedronC3
  : public R_::Tetrahedron_handle_3
{
CGAL_VC7_BUG_PROTECTED
  typedef typename R_::FT                   FT;
  typedef typename R_::Point_3              Point_3;
  typedef typename R_::Plane_3              Plane_3;
  typedef typename R_::Tetrahedron_3        Tetrahedron_3;
  typedef typename R_::Aff_transformation_3 Aff_transformation_3;

  typedef typename R_::Tetrahedron_handle_3      base;
  typedef typename base::element_type            rep;

public:
  typedef R_                                     R;

  TetrahedronC3()
    : base(rep()) {}

  TetrahedronC3(const Point_3 &p, const Point_3 &q, const Point_3 &r,
                const Point_3 &s)
    : base(rep(p, q, r, s)) {}

  const Point_3 &    vertex(int i) const;
  const Point_3 &    operator[](int i) const;

  bool       operator==(const TetrahedronC3 &t) const;
  bool       operator!=(const TetrahedronC3 &t) const;

  Bbox_3     bbox() const;

  Tetrahedron_3       transform(const Aff_transformation_3 &t) const
  {
    return TetrahedronC3<R>(t.transform(vertex(0)),
                t.transform(vertex(1)),
                t.transform(vertex(2)),
                t.transform(vertex(3)));
  }

  Orientation    orientation() const;
  Oriented_side  oriented_side(const Point_3 &p) const;
  Bounded_side   bounded_side(const Point_3 &p) const;

  bool       has_on_boundary(const Point_3 &p) const;
  bool       has_on_positive_side(const Point_3 &p) const;
  bool       has_on_negative_side(const Point_3 &p) const;
  bool       has_on_bounded_side(const Point_3 &p) const;
  bool       has_on_unbounded_side(const Point_3 &p) const;

  bool       is_degenerate() const;
  FT         volume() const;
};

#ifdef CGAL_CFG_TYPENAME_BUG
#define typename
#endif

template < class R >
bool
TetrahedronC3<R>::
operator==(const TetrahedronC3<R> &t) const
{
  if (identical(t))
      return true;
  if (orientation() != t.orientation())
      return false;

  std::vector< Point_3 > V1;
  std::vector< Point_3 > V2;
  typename std::vector< Point_3 >::iterator uniq_end1;
  typename std::vector< Point_3 >::iterator uniq_end2;
  int k;
  for ( k=0; k < 4; k++) V1.push_back( vertex(k));
  for ( k=0; k < 4; k++) V2.push_back( t.vertex(k));
  typename R::Less_xyz_3 Less_object = R().less_xyz_3_object();
  std::sort(V1.begin(), V1.end(), Less_object);
  std::sort(V2.begin(), V2.end(), Less_object);
  uniq_end1 = std::unique( V1.begin(), V1.end());
  uniq_end2 = std::unique( V2.begin(), V2.end());
  V1.erase( uniq_end1, V1.end());
  V2.erase( uniq_end2, V2.end());
  return V1 == V2;
}

template < class R >
inline
bool
TetrahedronC3<R>::
operator!=(const TetrahedronC3<R> &t) const
{
  return !(*this == t);
}

template < class R >
const typename TetrahedronC3<R>::Point_3 &
TetrahedronC3<R>::
vertex(int i) const
{
  if (i<0) i=(i%4)+4;
  else if (i>3) i=i%4;
  switch (i)
    {
    case 0: return Ptr()->e0;
    case 1: return Ptr()->e1;
    case 2: return Ptr()->e2;
    default: return Ptr()->e3;
    }
}

template < class R >
inline
const typename TetrahedronC3<R>::Point_3 &
TetrahedronC3<R>::
operator[](int i) const
{
  return vertex(i);
}

template < class R >
CGAL_KERNEL_MEDIUM_INLINE
typename TetrahedronC3<R>::FT
TetrahedronC3<R>::volume() const
{
  typename R::Vector_3 v1 = vertex(1)-vertex(0);
  typename R::Vector_3 v2 = vertex(2)-vertex(0);
  typename R::Vector_3 v3 = vertex(3)-vertex(0);
  return det3x3_by_formula(v1.x(), v1.y(), v1.z(),
	                   v2.x(), v2.y(), v2.z(),
	                   v3.x(), v3.y(), v3.z())/FT(6);
}

template < class R >
Orientation
TetrahedronC3<R>::
orientation() const
{
  return CGAL::orientation(vertex(0), vertex(1), vertex(2), vertex(3));
}

template < class R >
Oriented_side
TetrahedronC3<R>::
oriented_side(const typename TetrahedronC3<R>::Point_3 &p) const
{
  Orientation o = orientation();
  if (o != ZERO)
    return Oriented_side(o * bounded_side(p));

  CGAL_assertion (!is_degenerate());
  return ON_ORIENTED_BOUNDARY;
}

template < class R >
Bounded_side
TetrahedronC3<R>::
bounded_side(const typename TetrahedronC3<R>::Point_3 &p) const
{
  FT alpha, beta, gamma;

  solve(vertex(1)-vertex(0), vertex(2)-vertex(0), vertex(3)-vertex(0),
             p - vertex(0), alpha, beta, gamma);
  if (   (alpha < FT(0)) || (beta < FT(0)) || (gamma < FT(0))
      || (alpha + beta + gamma > FT(1)) )
      return ON_UNBOUNDED_SIDE;

  if (   (alpha == FT(0)) || (beta == FT(0)) || (gamma == FT(0))
      || (alpha+beta+gamma == FT(1)) )
    return ON_BOUNDARY;

  return ON_BOUNDED_SIDE;
}

template < class R >
inline
bool
TetrahedronC3<R>::has_on_boundary
  (const typename TetrahedronC3<R>::Point_3 &p) const
{
  return oriented_side(p) == ON_ORIENTED_BOUNDARY;
}

template < class R >
inline
bool
TetrahedronC3<R>::has_on_positive_side
  (const typename TetrahedronC3<R>::Point_3 &p) const
{
  return oriented_side(p) == ON_POSITIVE_SIDE;
}

template < class R >
inline
bool
TetrahedronC3<R>::has_on_negative_side
  (const typename TetrahedronC3<R>::Point_3 &p) const
{
  return oriented_side(p) == ON_NEGATIVE_SIDE;
}

template < class R >
inline
bool
TetrahedronC3<R>::has_on_bounded_side
  (const typename TetrahedronC3<R>::Point_3 &p) const
{
  return bounded_side(p) == ON_BOUNDED_SIDE;
}

template < class R >
inline
bool
TetrahedronC3<R>::has_on_unbounded_side
  (const typename TetrahedronC3<R>::Point_3 &p) const
{
  return bounded_side(p) == ON_UNBOUNDED_SIDE;
}

template < class R >
bool
TetrahedronC3<R>::is_degenerate() const
{
  Plane_3 plane(vertex(0), vertex(1), vertex(2));
  return (plane.is_degenerate()) ? true
                                 : plane.has_on_boundary(vertex(3));
}

template < class R >
inline
Bbox_3
TetrahedronC3<R>::bbox() const
{
  return vertex(0).bbox() + vertex(1).bbox()
       + vertex(2).bbox() + vertex(3).bbox();
}

#ifndef CGAL_NO_OSTREAM_INSERT_TETRAHEDRONC3
template < class R >
std::ostream &
operator<<(std::ostream &os, const TetrahedronC3<R> &t)
{
    switch(os.iword(IO::mode)) {
    case IO::ASCII :
        return os << t[0] << ' ' << t[1] << ' ' << t[2] << ' ' << t[3];
    case IO::BINARY :
        return os << t[0]  << t[1]  << t[2] << t[3];
    default:
        os << "TetrahedronC3(" << t[0] <<  ", " << t[1] <<   ", " << t[2];
        os <<  ", " << t[3] << ")";
        return os;
    }
}
#endif // CGAL_NO_OSTREAM_INSERT_TETRAHEDRONC3

#ifndef CGAL_NO_ISTREAM_EXTRACT_TETRAHEDRONC3
template < class R >
std::istream &
operator>>(std::istream &is, TetrahedronC3<R> &t)
{
    typename R::Point_3 p, q, r, s;

    is >> p >> q >> r >> s;

    if (is)
	t = TetrahedronC3<R>(p, q, r, s);
    return is;
}
#endif // CGAL_NO_ISTREAM_EXTRACT_TETRAHEDRONC3

#ifdef CGAL_CFG_TYPENAME_BUG
#undef typename
#endif

CGAL_END_NAMESPACE

#endif // CGAL_CARTESIAN_TETRAHEDRON_3_H