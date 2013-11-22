// ======================================================================
//
// Copyright (c) 1999 The GALIA Consortium
//
// This software and related documentation is part of the
// Computational Geometry Algorithms Library (CGAL).
//
// Every use of CGAL requires a license. Licenses come in three kinds:
//
// - For academic research and teaching purposes, permission to use and
//   copy the software and its documentation is hereby granted free of  
//   charge, provided that
//   (1) it is not a component of a commercial product, and
//   (2) this notice appears in all copies of the software and
//       related documentation.
// - Development licenses grant access to the source code of the library 
//   to develop programs. These programs may be sold to other parties as 
//   executable code. To obtain a development license, please contact
//   the GALIA Consortium (at cgal@cs.uu.nl).
// - Commercialization licenses grant access to the source code and the
//   right to sell development licenses. To obtain a commercialization 
//   license, please contact the GALIA Consortium (at cgal@cs.uu.nl).
//
// This software and documentation is provided "as-is" and without
// warranty of any kind. In no event shall the CGAL Consortium be
// liable for any damage of any kind.
//
// The GALIA Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Free University of Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbrucken (Germany),
// and Tel-Aviv University (Israel).
//
// ----------------------------------------------------------------------
//
// release       : CGAL-2.0
// release_date  : 1999, June 03
//
// file          : include/CGAL/Line_2pC2.h
// package       : C2 (2.1.4)
// source        : web/Line_2pC2.fw
// revision      : $Revision: 1.20 $
// revision_date : $Date: 1999/05/24 06:43:31 $
// author(s)     : Andreas.Fabri
//                 Herve.Bronnimann
//
// coordinator   : INRIA Sophia-Antipolis
//
// email         : cgal@cs.uu.nl
//
// ======================================================================



#ifndef CGAL_Line_2pC2_H
#define CGAL_Line_2pC2_H

#ifndef CGAL_TWOTUPLE_H
#include <CGAL/Twotuple.h>
#endif // CGAL_TWOTUPLE_H
#ifndef CGAL_PREDICATES_ON_POINTS_2_H
#include <CGAL/predicates_on_points_2.h>
#endif // CGAL_PREDICATES_ON_POINTS_2_H

CGAL_BEGIN_NAMESPACE

template < class FT >
class Line_2pC2 : public Handle
{
public:
                  Line_2pC2();
                  Line_2pC2(const Line_2pC2<FT>  &l);
                  Line_2pC2(const PointC2<FT> &p,
                            const PointC2<FT> &q);
                  Line_2pC2(const FT &a, const FT &b, const FT &c);
                  Line_2pC2(const SegmentC2<FT> &s);
                  Line_2pC2(const RayC2<FT> &r);
                  Line_2pC2(const PointC2<FT> &p,
                            const DirectionC2<FT> &d);
                  ~Line_2pC2();


  Line_2pC2<FT>   &operator=(const Line_2pC2<FT> &l);

  bool            operator==(const Line_2pC2<FT> &l) const;
  bool            operator!=(const Line_2pC2<FT> &l) const;
  int             id() const;

  FT              a() const;
  FT              b() const;
  FT              c() const;

  FT              x_at_y(const FT &y) const;
  FT              y_at_x(const FT &x) const;

  Line_2pC2<FT>   perpendicular(const PointC2<FT> &p) const;
  Line_2pC2<FT>   opposite() const;
  PointC2<FT>     point(int i) const;

  PointC2<FT>     point() const;

  PointC2<FT>     projection(const PointC2<FT> &p) const;

  DirectionC2<FT> direction() const;

  Oriented_side   oriented_side(const PointC2<FT> &p) const;
  bool            has_on_boundary(const PointC2<FT> &p) const;
  bool            has_on_positive_side(const PointC2<FT> &p) const;
  bool            has_on_negative_side(const PointC2<FT> &p) const;

  bool            is_horizontal() const;
  bool            is_vertical() const;
  bool            is_degenerate() const;
  Line_2pC2<FT>   transform(const Aff_transformationC2<FT> &t) const;

private:
  PointC2<FT>     first_point() const;
  PointC2<FT>     second_point() const;
  _Twotuple_rep< PointC2<FT> >* ptr() const;
};

template < class FT >
CGAL_KERNEL_INLINE
Line_2pC2<FT>::Line_2pC2()
{
  PTR = new _Twotuple_rep< PointC2<FT> >();
}

template < class FT >
CGAL_KERNEL_INLINE
Line_2pC2<FT>::Line_2pC2(const Line_2pC2<FT>  &l) :
  Handle((Handle&)l)
{}

template < class FT >
CGAL_KERNEL_INLINE
Line_2pC2<FT>::Line_2pC2(const RayC2<FT> &r) :
  Handle((Handle&)r)
{}

template < class FT >
CGAL_KERNEL_INLINE
Line_2pC2<FT>::Line_2pC2(const SegmentC2<FT> &s) :
  Handle((Handle&)s)
{}

template < class FT >
CGAL_KERNEL_INLINE
Line_2pC2<FT>::Line_2pC2(const PointC2<FT> &p, const PointC2<FT> &q)
{
  PTR = new _Twotuple_rep< PointC2<FT> >(p, q);
  nondegeneracy_assertion();
}

template < class FT >
CGAL_KERNEL_INLINE
Line_2pC2<FT>::Line_2pC2(const PointC2<FT> &p, const DirectionC2<FT> &d)
{
  PointC2<FT> q = p + d.vector();
  PTR = new _Twotuple_rep< PointC2<FT> >(p, q);
  nondegeneracy_assertion();
}

template < class FT >
CGAL_KERNEL_INLINE
Line_2pC2<FT>::Line_2pC2(const FT &a, const FT &b, const FT &c)
{
  PointC2<FT> p;
  if (b==FT(0))
      p = PointC2<FT>( (b-c)/a, FT(1) );
  else
      p = PointC2<FT>( FT(1), -(a+c)/b );

  PTR = new _Twotuple_rep< PointC2<FT> >(p, p + CVector<FT>(b, -a));
  nondegeneracy_assertion();
}

template < class FT >
CGAL_KERNEL_INLINE
Line_2pC2<FT>::~Line_2pC2()
{}


template < class FT >
Line_2pC2<FT> &Line_2pC2<FT>::operator=(const Line_2pC2<FT> &l)
{
  Handle::operator=(l);
  return *this;
}
template < class FT >
bool Line_2pC2<FT>::operator==(const Line_2pC2<FT> &l) const
{
  return ( is_on(l.first_point()) && (direction() == l.direction()) );
}

template < class FT >
CGAL_KERNEL_INLINE
bool Line_2pC2<FT>::operator!=(const Line_2pC2<FT> &l) const
{
  return !(*this == l);
}

template < class FT >
CGAL_KERNEL_INLINE
int Line_2pC2<FT>::id const
{
  return (int) PTR ;
}
template < class FT >
CGAL_KERNEL_INLINE
FT Line_2pC2<FT>::a() const
{
  return first_point().y() - second_point().y();
}

template < class FT >
CGAL_KERNEL_INLINE
FT Line_2pC2<FT>::b() const
{
  return second_point().x() - first_point().x();
}

template < class FT >
CGAL_KERNEL_INLINE
FT Line_2pC2<FT>::c() const
{
  return first_point().x()*second_point().y()
       - first_point().y()*second_point().x();
}

template < class FT >
CGAL_KERNEL_INLINE
FT Line_2pC2<FT>::x_at_y(const FT &y) const
{
  CGAL_kernel_precondition( a() != FT(0) );
  return ( -b() * y - c() ) / a();
}

template < class FT >
CGAL_KERNEL_INLINE
FT Line_2pC2<FT>::y_at_x(const FT &x) const
{
  CGAL_kernel_precondition( b() != FT(0) );
  return ( -a() * x - c() ) / b();
}

template < class FT >
CGAL_KERNEL_INLINE
Line_2pC2<FT> Line_2pC2<FT>::perpendicular(const PointC2<FT> &p) const
{
  return Line_2pC2<FT>(p, projection(p));
}

template < class FT >
CGAL_KERNEL_INLINE
Line_2pC2<FT> Line_2pC2<FT>::opposite() const
{
  return Line_2pC2<FT>(second_point(), first_point());
}

template < class FT >
CGAL_KERNEL_INLINE
PointC2<FT> Line_2pC2<FT>::point() const
{
  return first_point();
}

template < class FT >
PointC2<FT> Line_2pC2<FT>::point(int i) const
{
  return first_point() + FT(i) * (second_point() - first_point()) ;
}

template < class FT >
CGAL_KERNEL_INLINE
PointC2<FT> Line_2pC2<FT>::projection(const PointC2<FT> &p) const
{
  CVector<FT> w = second_point() - first_point();
  return first_point() - (((first_point() - p) * w) / (w * w)) * w;
}

template < class FT >
CGAL_KERNEL_INLINE
DirectionC2<FT> Line_2pC2<FT>::direction() const
{
  return DirectionC2<FT>( b(), -a() );
}

template < class FT >
Oriented_side Line_2pC2<FT>::oriented_side(const PointC2<FT> &p) const
{
  return orientation(first_point(), second_point(), p);
}

template < class FT >
bool Line_2pC2<FT>::has_on_boundary(const PointC2<FT> &p) const
{
  return collinear(first_point(), second_point(), p);
}

template < class FT >
bool Line_2pC2<FT>::has_on_positive_side(const PointC2<FT> &p) const
{
  return leftturn(first_point(), second_point(), p);
}


template < class FT >
bool Line_2pC2<FT>::has_on_negative_side(const PointC2<FT> &p) const
{
  return rightturn(first_point(), second_point(), p);
}


template < class FT >
bool Line_2pC2<FT>::is_horizontal() const
{
  return a() == FT(0);
}

template < class FT >
bool Line_2pC2<FT>::is_vertical() const
{
  return  b() == FT(0);
}

template < class FT >
bool Line_2pC2<FT>::is_degenerate() const
{
  return first_point() == second_point();
}

template < class FT >
CGAL_KERNEL_INLINE
Line_2pC2<FT> Line_2pC2<FT>::transform(const Aff_transformationC2<FT> &t) const
{
  return Line_2pC2<FT>(t.transform(first_point()),
                       t.transform(second_point()));
}

template < class FT >
CGAL_KERNEL_INLINE
_Twotuple_rep< PointC2<FT> >* Line_2pC2<FT>::ptr() const
{
  return (_Twotuple_rep< PointC2<FT> >*)PTR;
}

template < class FT >
CGAL_KERNEL_INLINE
PointC2<FT> Line_2pC2<FT>::first_point() const
{
  return ptr()->e0;
}

template < class FT >
CGAL_KERNEL_INLINE
PointC2<FT> Line_2pC2<FT>::second_point() const
{
  return ptr()->e1;
}


CGAL_END_NAMESPACE

#endif
