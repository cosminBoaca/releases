// ======================================================================
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
// source        : aff_transformation_tags.fw
// file          : include/CGAL/aff_transformation_tags.h
// package       : Kernel_basic (3.14)
// revision      : 3.14
// revision_date : 15 Sep 2000 
// author(s)     : Andreas Fabri
//
// coordinator   : MPI, Saarbruecken  (<Stefan.Schirra>)
// email         : contact@cgal.org
// www           : http://www.cgal.org
//
// ======================================================================
 

#ifndef CGAL_AFF_TRANSFORMATION_TAGS_H
#define CGAL_AFF_TRANSFORMATION_TAGS_H

#ifndef CGAL_CONFIG_H
#include <CGAL/config.h>
#endif // CGAL_CONFIG_H

CGAL_BEGIN_NAMESPACE

class Translation {};
class Rotation {};
class Scaling {};
class Reflection {};
class Identity_transformation {};

extern  Translation              TRANSLATION;
extern  Rotation                 ROTATION;
extern  Scaling                  SCALING;
extern  Reflection               REFLECTION;
extern  Identity_transformation  IDENTITY;

CGAL_END_NAMESPACE

#endif // CGAL_AFF_TRANSFORMATION_TAGS_H
