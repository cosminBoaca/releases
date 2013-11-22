// ============================================================================
//
// Copyright (c) 1998 The CGAL Consortium
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
//   the CGAL Consortium (at cgal@cs.uu.nl).
// - Commercialization licenses grant access to the source code and the
//   right to sell development licenses. To obtain a commercialization 
//   license, please contact the CGAL Consortium (at cgal@cs.uu.nl).
//
// This software and documentation is provided "as-is" and without
// warranty of any kind. In no event shall the CGAL Consortium be
// liable for any damage of any kind.
//
// The CGAL Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Free University of Berlin (Germany),
// INRIA Sophia-Antipolis (France), Max-Planck-Institute Saarbrucken
// (Germany), RISC Linz (Austria), and Tel-Aviv University (Israel).
//
// ============================================================================
//
// release       : CGAL-1.0
// date          : 21 Apr 1998
//
// file          : include/CGAL/leda_bigfloat.h
// author(s)     : Stefan Schirra 
//
// email         : cgal@cs.uu.nl
//
// ============================================================================


#ifndef CGAL_BIGFLOAT_H
#define CGAL_BIGFLOAT_H

#ifndef CGAL_IO_IO_TAGS_H
#include <CGAL/IO/io_tags.h>
#endif // CGAL_IO_IO_TAGS_H
#ifndef CGAL_NUMBER_TYPE_TAGS_H
#include <CGAL/number_type_tags.h>
#endif // CGAL_NUMBER_TYPE_TAGS_H

#ifndef CGAL_PROTECT_LEDA_BIGFLOAT_H
#include <LEDA/bigfloat.h>
#define CGAL_PROTECT_LEDA_BIGFLOAT_H
#endif // CGAL_PROTECT_LEDA_BIGFLOAT_H

inline
double
CGAL_to_double(const leda_bigfloat & b)
{ return to_double(b); }

inline
CGAL_Number_tag
CGAL_number_type_tag(const leda_bigfloat& )
{ return CGAL_Number_tag(); }

inline
bool
CGAL_is_finite(const leda_bigfloat & b)
{ return !( isInf(b) || isNaN(b) ); }

inline
bool
CGAL_is_valid(const leda_bigfloat & b)
{ return !( isNaN(b) ); }

inline
CGAL_io_Operator
CGAL_io_tag(const leda_bigfloat &)
{ return CGAL_io_Operator(); }

#endif // CGAL_BIGFLOAT_H