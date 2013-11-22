// ======================================================================
//
// Copyright (c) 1999 The CGAL Consortium

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
// file          : include/CGAL/Homogeneous/distance_predicatesH2.h
// package       : H2 (2.67)
// revision      : $Revision: 1.1 $
// revision_date : $Date: 2001/10/16 16:02:29 $
// author(s)     : Stefan Schirra
//
// coordinator   : MPI, Saarbruecken
// email         : contact@cgal.org
// www           : http://www.cgal.org
//
// ======================================================================
 

#ifndef CGAL_DISTANCE_PREDICATESH2_H
#define CGAL_DISTANCE_PREDICATESH2_H

#include <CGAL/determinant.h>

CGAL_BEGIN_NAMESPACE

template < class R>
CGAL_KERNEL_MEDIUM_INLINE
Comparison_result
compare_distance_to_point(const PointH2<R>& p,
                          const PointH2<R>& q,
                          const PointH2<R>& r)
{
  typedef typename R::RT RT;

  const RT phx = p.hx();
  const RT phy = p.hy();
  const RT phw = p.hw();
  const RT qhx = q.hx();
  const RT qhy = q.hy();
  const RT qhw = q.hw();
  const RT rhx = r.hx();
  const RT rhy = r.hy();
  const RT rhw = r.hw();
  const RT RT0 = RT(0);
  const RT RT2 = RT(2);

  RT dosd =   // difference of squared distances

  //            phx * phx   *   qhw * qhw * rhw * rhw
  //   -RT(2) * phx * qhx   *   phw * qhw * rhw * rhw
  //   +        qhx * qhx   *   phw * phw * rhw * rhw
  //
  //   +        phy * phy   *   qhw * qhw * rhw * rhw
  //   -RT(2) * phy * qhy   *   phw * qhw * rhw * rhw
  //   +        qhy * qhy   *   phw * phw * rhw * rhw
  //
  // - (        phx * phx   *   qhw * qhw * rhw * rhw
  //   -RT(2) * phx * rhx   *   phw * qhw * qhw * rhw
  //   +        rhx * rhx   *   phw * phw * qhw * qhw
  //
  //   +        phy * phy   *   qhw * qhw * rhw * rhw
  //   -RT(2) * phy * rhy   *   phw * qhw * qhw * rhw
  //   +        rhy * rhy   *   phw * phw * qhw * qhw

    rhw*rhw * (         phw * ( qhx*qhx + qhy*qhy )
                - RT2 * qhw * ( phx*qhx + phy*qhy )
              )
  - qhw*qhw * (         phw * ( rhx*rhx + rhy*rhy )
                - RT2 * rhw * ( phx*rhx + phy*rhy )
              );


  if ( RT0 < dosd )
  {
      return LARGER;
  }
  else
  {
      return (dosd < RT0) ? SMALLER : EQUAL;
  }
}

template < class R>
CGAL_KERNEL_MEDIUM_INLINE
bool
has_larger_distance_to_point(const PointH2<R>& p,
                              const PointH2<R>& q,
                              const PointH2<R>& r)
{
  typedef typename R::RT RT;

  const RT phx = p.hx();
  const RT phy = p.hy();
  const RT phw = p.hw();
  const RT qhx = q.hx();
  const RT qhy = q.hy();
  const RT qhw = q.hw();
  const RT rhx = r.hx();
  const RT rhy = r.hy();
  const RT rhw = r.hw();
  const RT RT0 = RT(0);
  const RT RT2 = RT(2);

  RT dosd =   // difference of squared distances

  //            phx * phx   *   qhw * qhw * rhw * rhw
  //   -RT(2) * phx * qhx   *   phw * qhw * rhw * rhw
  //   +        qhx * qhx   *   phw * phw * rhw * rhw
  //
  //   +        phy * phy   *   qhw * qhw * rhw * rhw
  //   -RT(2) * phy * qhy   *   phw * qhw * rhw * rhw
  //   +        qhy * qhy   *   phw * phw * rhw * rhw
  //
  // - (        phx * phx   *   qhw * qhw * rhw * rhw
  //   -RT(2) * phx * rhx   *   phw * qhw * qhw * rhw
  //   +        rhx * rhx   *   phw * phw * qhw * qhw
  //
  //   +        phy * phy   *   qhw * qhw * rhw * rhw
  //   -RT(2) * phy * rhy   *   phw * qhw * qhw * rhw
  //   +        rhy * rhy   *   phw * phw * qhw * qhw

    rhw*rhw * (         phw * ( qhx*qhx + qhy*qhy )
                - RT2 * qhw * ( phx*qhx + phy*qhy )
              )
  - qhw*qhw * (         phw * ( rhx*rhx + rhy*rhy )
                - RT2 * rhw * ( phx*rhx + phy*rhy )
              );


  return ( dosd > RT0 );
}

template < class R>
CGAL_KERNEL_MEDIUM_INLINE
bool
has_smaller_distance_to_point(const PointH2<R>& p,
                              const PointH2<R>& q,
                              const PointH2<R>& r)
{
  typedef typename R::RT RT;

  const RT phx = p.hx();
  const RT phy = p.hy();
  const RT phw = p.hw();
  const RT qhx = q.hx();
  const RT qhy = q.hy();
  const RT qhw = q.hw();
  const RT rhx = r.hx();
  const RT rhy = r.hy();
  const RT rhw = r.hw();
  const RT RT0 = RT(0);
  const RT RT2 = RT(2);

  RT dosd =   // difference of squared distances

  //            phx * phx   *   qhw * qhw * rhw * rhw
  //   -RT(2) * phx * qhx   *   phw * qhw * rhw * rhw
  //   +        qhx * qhx   *   phw * phw * rhw * rhw
  //
  //   +        phy * phy   *   qhw * qhw * rhw * rhw
  //   -RT(2) * phy * qhy   *   phw * qhw * rhw * rhw
  //   +        qhy * qhy   *   phw * phw * rhw * rhw
  //
  // - (        phx * phx   *   qhw * qhw * rhw * rhw
  //   -RT(2) * phx * rhx   *   phw * qhw * qhw * rhw
  //   +        rhx * rhx   *   phw * phw * qhw * qhw
  //
  //   +        phy * phy   *   qhw * qhw * rhw * rhw
  //   -RT(2) * phy * rhy   *   phw * qhw * qhw * rhw
  //   +        rhy * rhy   *   phw * phw * qhw * qhw

    rhw*rhw * (         phw * ( qhx*qhx + qhy*qhy )
                - RT2 * qhw * ( phx*qhx + phy*qhy )
              )
  - qhw*qhw * (         phw * ( rhx*rhx + rhy*rhy )
                - RT2 * rhw * ( phx*rhx + phy*rhy )
              );


  return ( dosd < RT0 );
}


template < class R>
CGAL_KERNEL_INLINE
Comparison_result
compare_signed_distance_to_line(const LineH2<R>&  l,
                                const PointH2<R>& p,
                                const PointH2<R>& q)
{
  typedef typename R::RT RT;

  const RT la = l.a();
  const RT lb = l.b();
  const RT phx= p.hx();
  const RT phy= p.hy();
  const RT phw= p.hw();
  const RT qhx= q.hx();
  const RT qhy= q.hy();
  const RT qhw= q.hw();
  const RT RT0 = RT(0);

  RT scaled_dist_p_minus_scaled_dist_q =
      la*( phx*qhw - qhx*phw )
    + lb*( phy*qhw - qhy*phw );



  if ( scaled_dist_p_minus_scaled_dist_q < RT0 )
  {
      return SMALLER;
  }
  else
  {
      return ( RT0 < scaled_dist_p_minus_scaled_dist_q ) ?
             LARGER : EQUAL;
  }
}


template < class R>
CGAL_KERNEL_INLINE
bool
has_larger_signed_distance_to_line(const LineH2<R>&  l,
                                    const PointH2<R>& p,
                                    const PointH2<R>& q)
{
  typedef typename R::RT RT;

  const RT la = l.a();
  const RT lb = l.b();
  const RT phx= p.hx();
  const RT phy= p.hy();
  const RT phw= p.hw();
  const RT qhx= q.hx();
  const RT qhy= q.hy();
  const RT qhw= q.hw();
  const RT RT0 = RT(0);

  RT scaled_dist_p_minus_scaled_dist_q =
      la*( phx*qhw - qhx*phw )
    + lb*( phy*qhw - qhy*phw );



  return ( scaled_dist_p_minus_scaled_dist_q > RT0 );
}


template < class R>
CGAL_KERNEL_INLINE
bool
has_smaller_signed_distance_to_line(const LineH2<R>&  l,
                                    const PointH2<R>& p,
                                    const PointH2<R>& q)
{
  typedef typename R::RT RT;

  const RT la = l.a();
  const RT lb = l.b();
  const RT phx= p.hx();
  const RT phy= p.hy();
  const RT phw= p.hw();
  const RT qhx= q.hx();
  const RT qhy= q.hy();
  const RT qhw= q.hw();
  const RT RT0 = RT(0);

  RT scaled_dist_p_minus_scaled_dist_q =
      la*( phx*qhw - qhx*phw )
    + lb*( phy*qhw - qhy*phw );

  return ( scaled_dist_p_minus_scaled_dist_q < RT0 );
}


template < class R>
CGAL_KERNEL_MEDIUM_INLINE
Comparison_result
compare_signed_distance_to_line(const PointH2<R>& p,
                                const PointH2<R>& q,
                                const PointH2<R>& r,
                                const PointH2<R>& s)
{
  typedef typename R::RT RT;

  const RT phx= p.hx();
  const RT phy= p.hy();
  const RT phw= p.hw();
  const RT qhx= q.hx();
  const RT qhy= q.hy();
  const RT qhw= q.hw();
  const RT rhx= r.hx();
  const RT rhy= r.hy();
  const RT rhw= r.hw();
  const RT shx= s.hx();
  const RT shy= s.hy();
  const RT shw= s.hw();
  const RT RT0  = RT(0);

  RT  scaled_dist_r_minus_scaled_dist_s =
         ( rhx*shw - shx*rhw ) * (phy*qhw - qhy*phw)
       - ( rhy*shw - shy*rhw ) * (phx*qhw - qhx*phw);


  if ( scaled_dist_r_minus_scaled_dist_s < RT0 )
  {
      return SMALLER;
  }
  else
  {
      return (scaled_dist_r_minus_scaled_dist_s > RT0 ) ?
             LARGER : EQUAL;
  }
}


template < class R>
CGAL_KERNEL_MEDIUM_INLINE
bool
has_smaller_signed_distance_to_line(const PointH2<R>& p,
                                    const PointH2<R>& q,
                                    const PointH2<R>& r,
                                    const PointH2<R>& s)
{
  typedef typename R::RT RT;

  const RT phx= p.hx();
  const RT phy= p.hy();
  const RT phw= p.hw();
  const RT qhx= q.hx();
  const RT qhy= q.hy();
  const RT qhw= q.hw();
  const RT rhx= r.hx();
  const RT rhy= r.hy();
  const RT rhw= r.hw();
  const RT shx= s.hx();
  const RT shy= s.hy();
  const RT shw= s.hw();
  const RT RT0  = RT(0);

  RT  scaled_dist_r_minus_scaled_dist_s =
         ( rhx*shw - shx*rhw ) * (phy*qhw - qhy*phw)
       - ( rhy*shw - shy*rhw ) * (phx*qhw - qhx*phw);

  return ( scaled_dist_r_minus_scaled_dist_s < RT0 );
}



template < class R>
CGAL_KERNEL_MEDIUM_INLINE
bool
has_larger_signed_distance_to_line(const PointH2<R>& p,
                                    const PointH2<R>& q,
                                    const PointH2<R>& r,
                                    const PointH2<R>& s)
{
  typedef typename R::RT RT;

  const RT phx= p.hx();
  const RT phy= p.hy();
  const RT phw= p.hw();
  const RT qhx= q.hx();
  const RT qhy= q.hy();
  const RT qhw= q.hw();
  const RT rhx= r.hx();
  const RT rhy= r.hy();
  const RT rhw= r.hw();
  const RT shx= s.hx();
  const RT shy= s.hy();
  const RT shw= s.hw();
  const RT RT0  = RT(0);

  RT  scaled_dist_r_minus_scaled_dist_s =
         ( rhx*shw - shx*rhw ) * (phy*qhw - qhy*phw)
       - ( rhy*shw - shy*rhw ) * (phx*qhw - qhx*phw);


  return ( scaled_dist_r_minus_scaled_dist_s > RT0 );
}

#ifndef CGAL_NO_DEPRECATED_CODE
template < class R>
inline
Comparison_result
cmp_dist_to_point(const PointH2<R>& p,
                  const PointH2<R>& q,
                  const PointH2<R>& r)
{
   return compare_distance_to_point(p, q, r);
}

template < class R>
inline
bool
has_larger_dist_to_point(const PointH2<R>& p,
                              const PointH2<R>& q,
                              const PointH2<R>& r)
{
   return has_larger_distance_to_point(p,q,r);
}

template < class R>
inline
bool
has_smaller_dist_to_point(const PointH2<R>& p,
                               const PointH2<R>& q,
                               const PointH2<R>& r)
{
   return has_smaller_distance_to_point(p, q, r);
}

template < class R>
inline
Comparison_result
cmp_signed_dist_to_line(const LineH2<R>&  l,
                             const PointH2<R>& p,
                             const PointH2<R>& q)
{
   return compare_signed_distance_to_line(l, p, q);
}

template < class R>
inline
bool
has_larger_signed_dist_to_line(const LineH2<R>&  l,
                               const PointH2<R>& p,
                               const PointH2<R>& q)
{
   return has_larger_signed_distance_to_line(l, p, q);
}


template < class R>
inline
bool
has_smaller_signed_dist_to_line(const LineH2<R>&  l,
                                const PointH2<R>& p,
                                const PointH2<R>& q)
{
   return has_smaller_signed_distance_to_line(l, p, q);
}

template < class R>
inline
Comparison_result
cmp_signed_dist_to_line(const PointH2<R>& p, const PointH2<R>& q,
                        const PointH2<R>& r, const PointH2<R>& s)
{
   return compare_signed_distance_to_line(p,q,r,s);
}

template < class R>
inline
bool
has_smaller_signed_dist_to_line(const PointH2<R>& p,
                                const PointH2<R>& q,
                                const PointH2<R>& r,
                                const PointH2<R>& s)
{
   return has_smaller_signed_distance_to_line(p, q, r, s);
}

template < class R>
inline
bool
has_larger_signed_dist_to_line(const PointH2<R>& p,
                                    const PointH2<R>& q,
                                    const PointH2<R>& r,
                                    const PointH2<R>& s)
{
   return has_larger_signed_distance_to_line(p, q, r, s);
}
#endif

CGAL_END_NAMESPACE

#endif //CGAL_DISTANCE_PREDICATESH2_H