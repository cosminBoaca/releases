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


// Source: TriangleC3.h
// Author: Andreas Fabri

#ifndef CGAL_TRIANGLEC3_H
#define CGAL_TRIANGLEC3_H

#include <CGAL/PlaneC3.h>
#include <CGAL/solve.h>

template <class FT>
class CGAL_TriangleC3 : public CGAL_Handle
{
public:
                      CGAL_TriangleC3();
                      CGAL_TriangleC3(const CGAL_TriangleC3<FT> &t);
                      CGAL_TriangleC3(const CGAL_PointC3<FT> &p,
                                      const CGAL_PointC3<FT> &q,
                                      const CGAL_PointC3<FT> &r);

                      ~CGAL_TriangleC3();

  CGAL_TriangleC3<FT> &operator=(const CGAL_TriangleC3<FT> &t);

  bool                operator==(const CGAL_TriangleC3<FT> &t) const;
  bool                operator!=(const CGAL_TriangleC3<FT> &t) const;
  int                 id() const;

  CGAL_PlaneC3<FT>    supporting_plane() const;


  CGAL_TriangleC3     transform(const CGAL_Aff_transformationC3<FT> &t) const;

  bool                has_on(const CGAL_PointC3<FT> &p) const;
  bool                is_degenerate() const;


  CGAL_PointC3<FT>    vertex(int i) const;
  CGAL_PointC3<FT>    operator[](int i) const;

  CGAL_Bbox_3         bbox() const;

private:
  CGAL__Threetuple< CGAL_PointC3<FT> >*   ptr() const;
};


template < class FT >
inline CGAL__Threetuple< CGAL_PointC3<FT> > *CGAL_TriangleC3<FT>::ptr() const
{
  return (CGAL__Threetuple< CGAL_PointC3<FT> >*)PTR;
}


template < class FT >
CGAL_TriangleC3<FT>::CGAL_TriangleC3()
{
  PTR = new CGAL__Threetuple< CGAL_PointC3<FT> >;
}


template < class FT >
CGAL_TriangleC3<FT>::CGAL_TriangleC3(const CGAL_TriangleC3<FT> &t) :
  CGAL_Handle(t)
{}


template < class FT >
CGAL_TriangleC3<FT>::CGAL_TriangleC3(const CGAL_PointC3<FT> &p,
                                 const CGAL_PointC3<FT> &q,
                                 const CGAL_PointC3<FT> &r)
{
  PTR = new CGAL__Threetuple< CGAL_PointC3<FT> >(p, q, r);
}


template < class FT >
inline CGAL_TriangleC3<FT>::~CGAL_TriangleC3()
{}


template < class FT >
CGAL_TriangleC3<FT> &CGAL_TriangleC3<FT>::operator=(
                                                const CGAL_TriangleC3<FT> &t)
{
  CGAL_Handle::operator=(t);
  return *this;
}
template < class FT >
bool CGAL_TriangleC3<FT>::operator==(const CGAL_TriangleC3<FT> &t) const
{
  int i;
  bool eq = false;
  for(i = 0; i <= 2; i++)
    {
      if( vertex(0) == t.vertex(i) )
        {
          eq = true;
          break;
        }
    }
  if ( eq )
    {
      return ( vertex(1) == t.vertex(i+1) && vertex(2) == t.vertex(i+2) );
    }
  return false;
}


template < class FT >
inline bool CGAL_TriangleC3<FT>::operator!=(const CGAL_TriangleC3<FT> &t) const
{
  return !(*this == t);
}


template < class FT >
int CGAL_TriangleC3<FT>::id() const
{
  return (int) PTR ;
}
template < class FT >
CGAL_PointC3<FT> CGAL_TriangleC3<FT>::vertex(int i) const
{
  switch (i)
    {
    case 0: return ptr()->e0;
    case 1: return ptr()->e1;
    case 2: return ptr()->e2;
    default: switch (i%3)
               {
               case 0: return ptr()->e0;
               case 1: return ptr()->e1;
               }
    }
  return ptr()->e2;
}


template < class FT >
inline CGAL_PointC3<FT> CGAL_TriangleC3<FT>::operator[](int i) const
{
  return vertex(i);
}

template < class FT >
inline CGAL_PlaneC3<FT> CGAL_TriangleC3<FT>::supporting_plane() const
{
  return CGAL_PlaneC3<FT>(vertex(0), vertex(1), vertex(2));
}


template < class FT >
CGAL_Bbox_3 CGAL_TriangleC3<FT>::bbox() const
{
  return vertex(0).bbox() + vertex(1).bbox() + vertex(2).bbox();
}


template < class FT >
inline CGAL_TriangleC3<FT> CGAL_TriangleC3<FT>::transform(
                                 const CGAL_Aff_transformationC3<FT> &t) const
{
  return CGAL_TriangleC3<FT>(t.transform(vertex(0)),
                             t.transform(vertex(1)),
                             t.transform(vertex(2)));
}
template < class FT >
bool CGAL_TriangleC3<FT>::has_on(const CGAL_PointC3<FT> &p) const
{
  CGAL_PointC3<FT> o = vertex(0) + supporting_plane().orthogonal_vector();
  CGAL_VectorC3<FT> v0 = vertex(0)-o,
                    v1 = vertex(1)-o,
                    v2 = vertex(2)-o;

  FT alpha, beta, gamma;

  CGAL_solve(v0, v1, v2, p-o, alpha, beta, gamma);

  return ((alpha >= FT(0)) && (beta >= FT(0))
          && (gamma >= FT(0)) && ((alpha+beta+gamma == FT(1))));
}


template < class FT >
bool CGAL_TriangleC3<FT>::is_degenerate() const
{
  return CGAL_collinear(vertex(0),vertex(1),vertex(2));
}


#ifndef CGAL_NO_OSTREAM_INSERT_TRIANGLEC3
template < class FT >
ostream &operator<<(ostream &os, const CGAL_TriangleC3<FT> &t)
{
    switch(os.iword(CGAL_IO::mode)) {
    case CGAL_IO::ASCII :
        return os << t[0] << ' ' << t[1] << ' ' << t[2];
    case CGAL_IO::BINARY :
        return os << t[0]  << t[1]  << t[2];
    default:
        os << "TriangleC3(" << t[0] <<  ", " << t[1] <<   ", " << t[2] <<")";
        return os;
    }
}
#endif // CGAL_NO_OSTREAM_INSERT_TRIANGLEC3

#ifndef CGAL_NO_ISTREAM_EXTRACT_TRIANGLEC3
template < class FT >
istream &operator>>(istream &is, CGAL_TriangleC3<FT> &t)
{
    CGAL_PointC3<FT> p, q, r;

    is >> p >> q >> r;
      
    t = CGAL_TriangleC3<FT>(p, q, r);
    return is;
}
#endif // CGAL_NO_ISTREAM_EXTRACT_TRIANGLEC3



#endif
