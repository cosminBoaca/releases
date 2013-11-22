// ======================================================================
//
// Copyright (c) 1997, 1998, 1999, 2000 The CGAL Consortium

// This software and related documentation are part of the Computational
// Geometry Algorithms Library (CGAL).
// This software and documentation are provided "as-is" and without warranty
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
//   markets LEDA (http://www.algorithmic-solutions.com). 
// - Commercial users may apply for an evaluation license by writing to
//   (Andreas.Fabri@geometryfactory.com). 
//
// The CGAL Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Freie Universitaet Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbrucken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).
//
// ----------------------------------------------------------------------
//
// release       : CGAL-2.3
// release_date  : 2001, August 13
//
// file          : include/CGAL/Iterator_project.h
// package       : STL_Extension (2.34)
// chapter       : $CGAL_Chapter: STL Extensions for CGAL $
// source        : stl_extension.fw
// revision      : $Revision: 1.26 $
// revision_date : $Date: 2001/07/11 09:00:25 $
// author(s)     : Michael Hoffmann
//                 Lutz Kettner
//
// coordinator   : ETH
//
// An iterator adaptor performing a projection on the value type.
// email         : contact@cgal.org
// www           : http://www.cgal.org
//
// ======================================================================

#ifndef CGAL_ITERATOR_PROJECT_H
#define CGAL_ITERATOR_PROJECT_H 1

CGAL_BEGIN_NAMESPACE

// Relies on iterator traits. Quite simplified compared to earlier version.

// The pointer type and the reference type in the Iterator_project
// are based on the value type from the projector, but the base iterator
// determines whether they are const or mutable. The following template
// class and its partial specialization helps creating the derived types.
//    If partial specification isn't working, we make this adaptor always
// mutable (using const_cast). So, it will always work where the correct
// version would work, but it would allow assignments where the correct
// version would flag a correct compilation error. This workaround thus
// provides full functionality, but less protection.

// If T === T1 return R1 else return R2
template <class T, class T1, class R1, class R2>
struct I_TYPE_MATCH_IF { typedef R2 Result; };  // else clause

#ifndef CGAL_CFG_NO_PARTIAL_CLASS_TEMPLATE_SPECIALISATION
template <class T, class R1, class R2>
struct I_TYPE_MATCH_IF<T,T,R1,R2> { typedef R1 Result; }; // then clause
#endif

// keep 4 dummy template parameters around for backwards compatibility
template < class I, class Fct,
           class D1 = int, class D2 = int, class D3 = int, class D4 = int >
class Iterator_project {
protected:
  I        nt;    // The internal iterator.
public:
  typedef Iterator_project<I,Fct,D1,D2,D3,D4> Self;
  typedef I                                   Iterator; // base iterator
  typedef std::iterator_traits<I>             traits;
  typedef typename traits::difference_type    difference_type;
  typedef typename traits::iterator_category  iterator_category;
  typedef typename traits::value_type         base_value_type;
  typedef typename traits::pointer            base_pointer;
  typedef typename traits::reference          base_reference;

  typedef typename Fct::argument_type         argument_type;
  typedef typename Fct::result_type           value_type;

  // Use I_TYPE_MATCH_IF to find correct pointer and reference type.
  // Make it a mutable iterator if partial specialization doesn't
  // work. In that case, the I_TYPE_MATCH_IF returns the else type.

  typedef I_TYPE_MATCH_IF< base_reference, const base_value_type &,
    const value_type &, value_type &> Match1;
  typedef typename Match1::Result             reference;

  typedef I_TYPE_MATCH_IF< base_pointer, const base_value_type *,
    const value_type *, value_type *> Match2;
  typedef typename Match2::Result             pointer;

  // CREATION
  // --------

  Iterator_project() {}
  Iterator_project( I j) : nt(j) {}

  // make two iterators assignable if the underlying iterators are
  template <class I2, class Q1, class Q2, class Q3, class Q4>
  Iterator_project( const Iterator_project<I2,Fct,Q1,Q2,Q3,Q4>& i2)
  : nt( i2.current_iterator()) {}

  template <class I2, class Q1, class Q2, class Q3, class Q4>
  Self& operator= ( const Iterator_project<I2,Fct,Q1,Q2,Q3,Q4>& i2) {
    nt = i2.current_iterator();
    return *this;
  }

  // OPERATIONS Forward Category
  // ---------------------------

  Iterator  current_iterator() const { return nt;}
  pointer   ptr() const {
    Fct fct;
    // Use a const_cast to make the adaptor work for compilers
    // lacking partial specialization. See also comments above.
#ifndef CGAL_CFG_NO_PARTIAL_CLASS_TEMPLATE_SPECIALISATION
    return &(fct(*nt));
#else
    return const_cast<pointer>(&(fct(*nt)));
#endif
  }
  bool      operator==( const Self& i) const { return ( nt == i.nt); }
  bool      operator!=( const Self& i) const { return !(*this == i); }
  reference operator* ()               const { return *ptr(); }
  pointer   operator->()               const { return ptr(); }
  Self&     operator++() {
    ++nt;
    return *this;
  }
  Self      operator++(int) {
    Self tmp = *this;
    ++*this;
    return tmp;
  }

  // OPERATIONS Bidirectional Category
  // ---------------------------------

  Self& operator--() {
    --nt;
    return *this;
  }
  Self  operator--(int) {
    Self tmp = *this;
    --*this;
    return tmp;
  }

  // OPERATIONS Random Access Category
  // ---------------------------------

  Self& operator+=( difference_type n) {
    nt += n;
    return *this;
  }
  Self  operator+( difference_type n) const {
    Self tmp = *this;
    return tmp += n;
  }
  Self& operator-=( difference_type n) {
    return operator+=( -n);
  }
  Self  operator-( difference_type n) const {
    Self tmp = *this;
    return tmp += -n;
  }
  difference_type  operator-( const Self& i) const { return nt - i.nt; }
  reference  operator[]( difference_type n) const {
    Self tmp = *this;
    tmp += n;
    return tmp.operator*();
  }
  bool operator< ( const Self& i) const { return ( nt < i.nt); }
  bool operator> ( const Self& i) const { return i < *this; }
  bool operator<=( const Self& i) const { return !(i < *this); }
  bool operator>=( const Self& i) const { return !(*this < i); }
};

template < class Dist, class Fct, class I,
           class D1, class D2, class D3, class D4>
inline
Iterator_project<I,Fct,D1,D2,D3,D4>
operator+( Dist n, Iterator_project<I,Fct,D1,D2,D3,D4> i) {
  return i += n;
}

CGAL_END_NAMESPACE
#endif // CGAL_ITERATOR_PROJECT_H //
// EOF //
