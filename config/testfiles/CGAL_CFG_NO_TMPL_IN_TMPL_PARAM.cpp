// Copyright (c) 1998  Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Freie Universitaet Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbruecken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Installation/config/testfiles/CGAL_CFG_NO_TMPL_IN_TMPL_PARAM.cpp $
// $Id: CGAL_CFG_NO_TMPL_IN_TMPL_PARAM.cpp 37704 2007-03-30 08:39:31Z spion $
// 
//
// Author(s)     : Lutz Kettner

// ---------------------------------------------------------------------
// A short test program to evaluate a C++ compiler.
// This program is used by install_cgal.
// The following documentation will be pasted in the generated configfile.
// ---------------------------------------------------------------------

//| Nested templates in template parameter, such as 'template <
//| template <class T> class A>' are not supported by any compiler. 
//| The following definition is set if they are not supported.

template< class X>
struct A {
    X i;
    A( X j) : i(j) {}
};

template< template < class T> class B>
struct C {
    B<int> b;
    C( int i) : b(i) {}
};

template< class N, template < class T> class B>
struct D {
    B<N> b;
    D( N i) : b(i) {}
};

template < template < class T > class HDS>
void fct(HDS<int> h1 ) {} // here it does not compile 

template < template < class T > class HDS>
void fct2(D<double,HDS> h1 ) {}


int main() {
    C<A> c(1);
    D< double, A> d( 3.8);
    (void) c;
    fct2(d);
    return 0;
}
