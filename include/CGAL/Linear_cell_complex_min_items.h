// Copyright (c) 2011 CNRS and LIRIS' Establishments (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 3 of the License,
// or (at your option) any later version.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
// Author(s)     : Guillaume Damiand <guillaume.damiand@liris.cnrs.fr>
//
#ifndef CGAL_LINEAR_CELL_COMPLEX_MIN_ITEMS_H
#define CGAL_LINEAR_CELL_COMPLEX_MIN_ITEMS_H 1

#include <CGAL/Dart.h>
#include <CGAL/Cell_attribute_with_point.h>

namespace CGAL {

  /** @file Linear_cell_complex_min_items.h
   * Definition of min item class for map with points.
   */

  /** Minimal items for linear cell complexes.
   * Linear_cell_complex_min_items defines what is the item class
   * for a linear cell complex. It provides definitions for attributes
   * associated to vertices (containing points), and darts. 
   */
  template <unsigned int d>
  struct Linear_cell_complex_min_items
  {
    /// Dart_wrapper defines the type of darts used.
    template <class LCC>
    struct Dart_wrapper
    {
      typedef CGAL::Dart<d, LCC> Dart;

      typedef Cell_attribute_with_point<LCC> Vertex_attrib;    
      typedef CGAL::cpp11::tuple<Vertex_attrib> Attributes;
    };
  };

} // namespace CGAL

#endif // CGAL_LINEAR_CELL_COMPLEX_MIN_ITEMS_H //
// EOF //
