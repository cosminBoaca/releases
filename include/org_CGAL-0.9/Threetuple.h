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


// Source: Threetuple.h
// Author: Andreas Fabri

#ifndef CGAL__THREETUPLE_H
#define CGAL__THREETUPLE_H

template < class T >
class CGAL__Threetuple : public CGAL_Rep
{
public:

  T  e0;
  T  e1;
  T  e2;

  CGAL__Threetuple()
    {
    }
  CGAL__Threetuple(const T & a0, const T & a1, const T & a2)  :
    e0(a0), e1(a1), e2(a2)
    {
    }
  ~CGAL__Threetuple()
    {
    }
};
#endif
