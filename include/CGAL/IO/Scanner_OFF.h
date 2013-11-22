// ======================================================================
//
// Copyright (c) 1999 The GALIA Consortium
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
//   the GALIA Consortium (at cgal@cs.uu.nl).
// - Commercialization licenses grant access to the source code and the
//   right to sell development licenses. To obtain a commercialization 
//   license, please contact the GALIA Consortium (at cgal@cs.uu.nl).
//
// This software and documentation is provided "as-is" and without
// warranty of any kind. In no event shall the CGAL Consortium be
// liable for any damage of any kind.
//
// The GALIA Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Free University of Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbrucken (Germany),
// and Tel-Aviv University (Israel).
//
// ----------------------------------------------------------------------
//
// release       : CGAL-2.0
// release_date  : 1999, June 03
//
// file          : include/CGAL/IO/Scanner_OFF.h
// package       : Polyhedron_IO (2.5)
// chapter       : $CGAL_Chapter: Support Library ... $
// source        : polyhedron_io.fw
// revision      : $Revision: 1.4 $
// revision_date : $Date: 1999/03/24 11:16:26 $
// author(s)     : Lutz Kettner
//
// coordinator   : Herve Bronnimann
//
// STL compliant file scanner for an object in object file format (OFF).
// email         : cgal@cs.uu.nl
//
// ======================================================================

#ifndef CGAL_IO_SCANNER_OFF_H
#define CGAL_IO_SCANNER_OFF_H 1
#ifndef CGAL_BASIC_H
#include <CGAL/basic.h>
#endif
#ifndef CGAL_PROTECT_ITERATOR
#include <iterator>
#define CGAL_PROTECT_ITERATOR
#endif
#ifndef CGAL_PROTECT_VECTOR
#include <vector>
#define CGAL_PROTECT_VECTOR
#endif
#ifndef CGAL_IO_FILE_SCANNER_OFF_H
#include <CGAL/IO/File_scanner_OFF.h>
#endif // CGAL_IO_FILE_SCANNER_OFF_H

CGAL_BEGIN_NAMESPACE

// The Facet_iterator's value type is vector<Integer32>
// that contains the vertex indices.

template <class Pt>
class _Scanner_OFF_vertex_iterator : public std::input_iterator<Pt, int> {
    File_scanner_OFF*  m_scan;
    int                m_cnt;
    Pt                 m_point;

    void next_vertex() {
        CGAL_assertion( m_scan != NULL);
        if ( m_cnt < m_scan->size_of_vertices()) {
            file_scan_vertex( *m_scan, m_point);
            m_scan->skip_to_next_vertex( m_cnt);
            ++m_cnt;
        } else
            m_cnt = m_scan->size_of_vertices() + 1;
    }
public:
    typedef Pt                                Point;
    typedef File_scanner_OFF                  Scanner;
    typedef _Scanner_OFF_vertex_iterator<Pt>  Self;

    _Scanner_OFF_vertex_iterator( int cnt) : m_scan(0), m_cnt(cnt+1) {}
    _Scanner_OFF_vertex_iterator( Scanner& s, int cnt)
        : m_scan(&s), m_cnt(cnt)
    {
        next_vertex();
    }
    int    count()                    const { return m_cnt; }
    bool   operator==( const Self& i) const { return m_cnt == i.m_cnt; }
    bool   operator!=( const Self& i) const { return m_cnt != i.m_cnt; }
    Self&  operator++() {
        next_vertex();
        return *this;
    }
    Self   operator++(int) {
        Self tmp = *this;
        ++(*this);
        return tmp;
    }
    const Point& operator*()  const {
        CGAL_assertion( m_scan != NULL);
        return m_point;
    }
    // No workaround needed for operator-> with points.
    const Point* operator->() const { return & operator*(); }
};

class _Scanner_OFF_facet_iterator
    : public std::input_iterator< vector< Integer32>,
                                  vector< Integer32>::difference_type >
{
    File_scanner_OFF*  m_scan;
    int                m_cnt;
    value_type         m_indices;

    void next_facet() {
        CGAL_assertion( m_scan != NULL);
        if ( m_cnt < m_scan->size_of_facets()) {
            m_indices.erase( m_indices.begin(), m_indices.end());
            Integer32 no;
            m_scan->scan_facet( no, m_cnt);
            m_indices.reserve( no);
            Integer32 index = -1;
            for ( Integer32 i = 0; i < no; ++i) {
                m_scan->scan_facet_vertex_index( index, m_cnt);
                m_indices.push_back( index);
            }
            m_scan->skip_to_next_facet( m_cnt);
            ++ m_cnt;
        } else
            m_cnt = m_scan->size_of_facets() + 1;
    }
public:
    typedef File_scanner_OFF             Scanner;
    typedef _Scanner_OFF_facet_iterator  Self;
    typedef value_type::iterator         iterator;

    _Scanner_OFF_facet_iterator( int cnt) : m_scan(0), m_cnt(cnt+1) {}
    _Scanner_OFF_facet_iterator( Scanner& s, int cnt)
        : m_scan(&s), m_cnt(cnt)
    {
        next_facet();
    }
    int   count()                    const { return m_cnt; }
    bool  operator==( const Self& i) const { return m_cnt == i.m_cnt; }
    bool  operator!=( const Self& i) const { return m_cnt != i.m_cnt; }
    Self& operator++() {
        next_facet();
        return *this;
    }
    Self  operator++(int) {
        Self tmp = *this;
        ++(*this);
        return tmp;
    }
    value_type&       operator*()        {
        CGAL_assertion( m_scan != NULL);
        return m_indices;
    }
    const value_type& operator*()  const {
        CGAL_assertion( m_scan != NULL);
        return m_indices;
    }
    value_type*       operator->()       { return & operator*(); }
    const value_type* operator->() const { return & operator*(); }
};


// The distance function is implemented to work in
// constant time for both iterators.

#ifdef CGAL_PARTIAL_SPECIALISATION
template <class Pt, class Distance> inline
void distance( const _Scanner_OFF_vertex_iterator<Pt>& first,
               const _Scanner_OFF_vertex_iterator<Pt>& last,
               Distance& n) {
    n = Distance( last.count() - first.count());
}
template <class Distance> inline
void distance( const _Scanner_OFF_facet_iterator& first,
               const _Scanner_OFF_facet_iterator& last,
               Distance& n) {
    n = Distance( last.count() - first.count());
}
template <class Pt> inline
int distance( const _Scanner_OFF_vertex_iterator<Pt>& first,
              const _Scanner_OFF_vertex_iterator<Pt>& last) {
    return last.count() - first.count();
}
#endif // CGAL_PARTIAL_SPECIALISATION //

inline
int distance( const _Scanner_OFF_facet_iterator& first,
              const _Scanner_OFF_facet_iterator& last) {
    return last.count() - first.count();
}


template <class Pt>
class Scanner_OFF {
    File_scanner_OFF  m_scan;
public:
    typedef Pt                                     Point;
    typedef Scanner_OFF<Pt>                        Self;
    typedef _Scanner_OFF_vertex_iterator<Pt>       Vertex_iterator;
    typedef _Scanner_OFF_facet_iterator            Facet_iterator;
    typedef _Scanner_OFF_facet_iterator::iterator  Index_iterator;

    Scanner_OFF( std::istream& in, bool verbose = false)
        : m_scan( in, verbose) {}
    Scanner_OFF( std::istream& in, const File_header_OFF& header)
        : m_scan( in, header) {}

    int  size_of_vertices()   const { return m_scan.size_of_vertices(); }
    int  size_of_halfedges()  const { return m_scan.size_of_halfedges();}
    int  size_of_facets()     const { return m_scan.size_of_facets();   }

    bool verbose()            const { return m_scan.verbose();          }
    bool skel()               const { return m_scan.skel();             }
    bool off()                const { return m_scan.off();              }
    bool binary()             const { return m_scan.binary();           }
    bool ascii()              const { return m_scan.ascii();            }

    bool has_colors()         const { return m_scan.has_colors();       }
    bool has_normals()        const { return m_scan.has_normals();      }

    File_header_OFF& header()       { return m_scan;                    }
    const File_header_OFF&
         header()             const { return m_scan;                    }

    Vertex_iterator vertices_begin(){ return Vertex_iterator( m_scan,0);}
    Vertex_iterator vertices_end()  {
        return Vertex_iterator( size_of_vertices());
    }
    Facet_iterator facets_begin()   { return Facet_iterator( m_scan,0); }
    Facet_iterator facets_end()     {
        return Facet_iterator( size_of_facets());
    }
};

CGAL_END_NAMESPACE
#endif // CGAL_IO_SCANNER_OFF_H //
// EOF //
