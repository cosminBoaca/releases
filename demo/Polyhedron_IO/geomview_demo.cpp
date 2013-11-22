// Copyright (c) 2002  Max Planck Institut fuer Informatik (Germany).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.3-branch/Polyhedron_IO/demo/Polyhedron_IO/geomview_demo.cpp $
// $Id: geomview_demo.cpp 37003 2007-03-10 16:55:12Z spion $
//
//
// Author(s)     : Lutz Kettner

//Borland, Microsoft and Intel compiler are excluded
#if defined(__BORLANDC__) || defined(_MSC_VER)

#include <iostream>

int main() {
  std::cout << "Geomview doesn't work on Windows, so no demo." << std::endl;
  return 0;
}
#else // not windows

#include <CGAL/Cartesian.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_geomview_ostream.h>

typedef  CGAL::Cartesian<double>               Kernel;
typedef  Kernel::Point_3                       Point;
typedef  CGAL::Polyhedron_3<Kernel>            Polyhedron;

int main() {
    Point p( 1.0, 0.0, 0.0);
    Point q( 0.0, 1.0, 0.0);
    Point r( 0.0, 0.0, 1.0);
    Point s( 0.0, 0.0, 0.0);
    Polyhedron P;
    P.make_tetrahedron( p,q,r,s);
    CGAL::Geomview_stream geo;
    geo << CGAL::GREEN << P;

    // wait for a mouse click.
    Point click;
    geo >> click;
    return 0;
}

#endif // not windows
// EOF //
