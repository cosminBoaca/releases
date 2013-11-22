// Copyright (c) 2005 Foundation for Research and Technology-Hellas (Greece).
// All rights reserved.
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.4-branch/Installation/config/testfiles/CGAL_CFG_NESTED_CLASS_FRIEND_DECLARATION_BUG.cpp $
// $Id: CGAL_CFG_NESTED_CLASS_FRIEND_DECLARATION_BUG.cpp 37704 2007-03-30 08:39:31Z spion $
// 
//
// Author(s)     : Menelaos Karavelas <mkaravel@tem.uoc.gr>

// ---------------------------------------------------------------------
// A short test program to evaluate a C++ compiler.
// This program is used by install_cgal.
// The following documentation will be pasted in the generated configfile.
// ---------------------------------------------------------------------

//| The flag CGAL_CFG_NESTED_CLASS_FRIEND_DECLARATION_BUG is set
//| if the compiler cannot recognize the declaration of a nested
//| class as friend.
//| Compilers such as the Intel compiler 8.x (for linux or windows),
//| MSVC 7.1 or pgCC have this "bug". It should be noted that the C++
//| standard is a bit vague on this issue, in other words what is referred
//| to as "bug" above, may not really be a bug. Hopefully, the next standard
//| will resolve this issue.

#include <iostream>

template<class T>
struct A
{
  void do_something() const {
    std::cerr << "A's do_something" << std::endl;
    T().do_something();
  }
};

template<class T>
struct B
{
  typedef A<T> Nested;

  void do_something() const {
    std::cerr << "B's do_something" << std::endl;
    T().do_something();
  }
};


template<class T>
class C
{
  friend class B< C<T> >;
  friend class B< C<T> >::Nested;
  // the following declaration (instead of the one above) is what
  // pgCC, Intel 8.x and MSVC 7.1 would accept:
  //  friend class A< C<T> >;

 protected:
  void do_something() const {
    std::cerr << "C's do_something" << std::endl;
  }
};


int main()
{
  A< C<int> > a;
  B< C<int> > b;

  a.do_something();
  b.do_something();

  return 0;
}
