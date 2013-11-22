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


// Source: basic_constructionsC2.h
// Author: Sven Schoenherr

#ifndef CGAL_BASIC_CONSTRUCTIONSC2_H
#define CGAL_BASIC_CONSTRUCTIONSC2_H 1

#ifndef CGAL_POINTC2_H
#  include <CGAL/PointC2.h>
#endif

template < class FT >
CGAL_PointC2<FT>
CGAL_midpoint( CGAL_PointC2<FT> const& p,
               CGAL_PointC2<FT> const& q )
{
    return( CGAL_PointC2<FT>( ( p.x()+q.x()) / FT( 2),
                              ( p.y()+q.y()) / FT( 2)));
}

template < class FT >
CGAL_PointC2<FT>
CGAL_circumcenter( CGAL_PointC2<FT> const& p,
                   CGAL_PointC2<FT> const& q,
                   CGAL_PointC2<FT> const& r)
{
    FT px( p.x());
    FT py( p.y());
    FT qx( q.x());
    FT qy( q.y());
    FT rx( r.x());
    FT ry( r.y());

    FT px_qx( px - qx);
    FT py_qy( py - qy);
    FT qx_rx( qx - rx);
    FT qy_ry( qy - ry);
    FT rx_px( rx - px);
    FT ry_py( ry - py);

    FT px2_py2( px*px + py*py);
    FT qx2_qy2( qx*qx + qy*qy);
    FT rx2_ry2( rx*rx + ry*ry);

    FT num_x( px2_py2*qy_ry + qx2_qy2*ry_py + rx2_ry2*py_qy);
    FT num_y( px2_py2*qx_rx + qx2_qy2*rx_px + rx2_ry2*px_qx);

    FT den_x( ( px*qy_ry + qx*ry_py + rx*py_qy) * FT( 2));
    FT den_y( ( py*qx_rx + qy*rx_px + ry*px_qx) * FT( 2));

    return( CGAL_PointC2<FT>( num_x/den_x, num_y/den_y));
}

#endif // CGAL_BASIC_CONSTRUCTIONS_2_H
