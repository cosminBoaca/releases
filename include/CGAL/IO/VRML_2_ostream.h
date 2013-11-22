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
// file          : include/CGAL/IO/VRML_2_ostream.h
// author(s)     : Lutz Kettner
//
// email         : cgal@cs.uu.nl
//
// ============================================================================

#ifndef CGAL_IO_VRML_2_OSTREAM_H
#define CGAL_IO_VRML_2_OSTREAM_H

#ifndef CGAL_BASIC_H
#include <CGAL/basic.h>
#endif // CGAL_BASIC_H
#ifndef CGAL_PROTECT_IOSTREAM_H
#include <iostream.h>
#define CGAL_PROTECT_IOSTREAM_H
#endif // CGAL_PROTECT_IOSTREAM_H


class CGAL_VRML_2_ostream {
public:
    CGAL_VRML_2_ostream()           : m_os(0)  {}
    CGAL_VRML_2_ostream(ostream& o) : m_os(&o) { header();}
    ~CGAL_VRML_2_ostream()  { close(); }
    void open(ostream& o)   { m_os = &o; header(); }
    void close() {
	if ( m_os)
	    footer();
	m_os = 0;
    }
    typedef const void* Const_void_ptr;
    operator Const_void_ptr () const {
	if ( m_os)
	    return *m_os;
	return 0;
    }
    ostream& os() {
	// The behaviour if m_os == 0 could be changed to return
	// cerr or a file handle to /dev/null. The latter one would 
	// mimick the behaviour that one can still use a stream with
	// an invalid stream, but without producing any output.
	CGAL_assertion( m_os);
	return *m_os;
    }
private:
    void header() { 
	os() << "#VRML V2.0 utf8\n"
                "# File written with the help of the CGAL Library\n"
	        "#-- Begin of file header\n"
	        "Group {\n"
	        "    children [\n"
	        "        Shape {\n"
	        "            appearance\n"
	        "                Appearance {\n"
	        "                    material DEF CGAL_Material Material {}\n"
	        "                }\n"
	        "            geometry NULL\n"
	        "        }\n"
                "        #-- End of file header" << endl; 
    }
    void footer() { 
	os() << "        #-- Begin of file footer\n"
	        "    ]\n"
	        "}\n"
                "#-- End of file footer" << endl; 
    }
    ostream*  m_os;
};

#endif // CGAL_IO_VRML_2_OSTREAM_H


#ifdef CGAL_TETRAHEDRON_3_H
#ifndef CGAL_IO_VRML_2_TETRAHEDRON_3
#define CGAL_IO_VRML_2_TETRAHEDRON_3
template <class R >
CGAL_VRML_2_ostream&
operator<<(CGAL_VRML_2_ostream& os,
           const CGAL_Tetrahedron_3<R > &t)
{
  os.os() 
      << "        Group {\n"
	 "            children [\n"
	 "                Shape {\n"
	 "                    appearance\n"
	 "                        Appearance { material USE CGAL_Material}\n"
	 "                    geometry\n"
	 "                        IndexedFaceSet {\n"
	 "                            coord Coordinate {\n"
	 "                                point [ \n"
	 "                                    "
      << CGAL_to_double(t[0].x()) << " " 
      << CGAL_to_double(t[0].y()) << " " 
      << CGAL_to_double(t[0].z()) << ",\n                                    "
      << CGAL_to_double(t[1].x()) << " " 
      << CGAL_to_double(t[1].y()) << " " 
      << CGAL_to_double(t[1].z()) << ",\n                                    "
      << CGAL_to_double(t[2].x()) << " " 
      << CGAL_to_double(t[2].y()) << " " 
      << CGAL_to_double(t[2].z()) << ",\n                                    "
      << CGAL_to_double(t[3].x()) << " " 
      << CGAL_to_double(t[3].y()) << " " 
      << CGAL_to_double(t[3].z())
	 "\n                                ]\n"
	 "                            }\n"
	 "                            solid   FALSE\n"
	 "                            coordIndex  [ 0,1,2,-1, 1,3,2,-1,\n"
	 "                                          0,2,3,-1, 0,3,1,-1 ]\n"
	 "                        } #IndexedFaceSet\n"
	 "                } #Shape\n"
	 "            ] #children\n"
	 "        } #Group" << endl;
  return os;
}
#endif // CGAL_IO_VRML_2_TETRAHEDRON_3
#endif // CGAL_TETRAHEDRON_3_H