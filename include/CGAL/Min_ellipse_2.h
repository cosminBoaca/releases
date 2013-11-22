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
// file          : include/CGAL/Min_ellipse_2.h
// author(s)     : Sven Sch�nherr 
//                 Bernd G�rtner
//
// email         : cgal@cs.uu.nl
//
// ============================================================================

#ifndef CGAL_MIN_ELLIPSE_2_H
#define CGAL_MIN_ELLIPSE_2_H

// Class declaration
// =================
template < class _Traits >
class CGAL_Min_ellipse_2;

// Class interface
// ===============
// includes
#ifndef CGAL_RANDOM_H
#  include <CGAL/Random.h>
#endif
#ifndef CGAL_OPTIMISATION_ASSERTIONS_H
#  include <CGAL/optimisation_assertions.h>
#endif
#ifndef CGAL_OPTIMISATION_BASIC_H
#  include <CGAL/optimisation_basic.h>
#endif
#ifndef CGAL_PROTECT_LIST_H
#  include <list.h>
#endif
#ifndef CGAL_PROTECT_VECTOR_H
#include <vector.h>
#endif
#ifndef CGAL_PROTECT_ALGO_H
#include <algo.h>
#endif
#ifndef CGAL_PROTECT_IOSTREAM_H
#include <iostream.h>
#endif

template < class _Traits >
class CGAL_Min_ellipse_2 {
  public:
    // types
    typedef           _Traits                      Traits;
    typedef typename  _Traits::Point               Point;
    typedef typename  _Traits::Ellipse             Ellipse;
    typedef typename  list<Point>::const_iterator  Point_iterator;
    typedef           const Point *                Support_point_iterator;
    
    /**************************************************************************
    WORKAROUND: The GNU compiler (g++ 2.7.2[.*]) does not accept types
    with scope operator as argument type or return type in class template
    member functions. Therefore, all member functions are implemented in
    the class interface.
    
    // creation
    CGAL_Min_ellipse_2( const Point*  first,
                        const Point*  last,
                        bool          randomize = false,
                        CGAL_Random&  random    = CGAL_random,
                        const Traits& traits    = Traits());
    CGAL_Min_ellipse_2( list<Point>::const_iterator first,
                        list<Point>::const_iterator last,
                        bool          randomize = false,
                        CGAL_Random&  random    = CGAL_random,
                        const Traits& traits    = Traits());
    CGAL_Min_ellipse_2( istream_iterator<Point,ptrdiff_t> first,
                        istream_iterator<Point,ptrdiff_t> last,
                        bool          randomize = false,
                        CGAL_Random&  random    = CGAL_random,
                        const Traits& traits    = Traits())
    CGAL_Min_ellipse_2( const Traits& traits = Traits());
    CGAL_Min_ellipse_2( const Point&  p,
                        const Traits& traits = Traits());
    CGAL_Min_ellipse_2( const Point&  p,
                        const Point&  q,
                        const Traits& traits = Traits());
    CGAL_Min_ellipse_2( const Point&  p1,
                        const Point&  p2,
                        const Point&  p3,
                        const Traits& traits = Traits());
    ~CGAL_Min_ellipse_2( );
    
    // access functions
    int  number_of_points        ( ) const;
    int  number_of_support_points( ) const;
    
    Point_iterator  points_begin( ) const;
    Point_iterator  points_end  ( ) const;
    
    Support_point_iterator  support_points_begin( ) const;
    Support_point_iterator  support_points_end  ( ) const;
    
    const Point&  support_point( int i) const;
    
    const Ellipse&  ellipse( ) const;
    
    // predicates
    CGAL_Bounded_side  bounded_side( const Point& p) const;
    bool  has_on_bounded_side      ( const Point& p) const;
    bool  has_on_boundary          ( const Point& p) const;
    bool  has_on_unbounded_side    ( const Point& p) const;
    
    bool  is_empty     ( ) const;
    bool  is_degenerate( ) const;
    
    // modifiers
    void  insert( const Point& p);
    void  insert( const Point* first,
                  const Point* last );
    void  insert( list<Point>::const_iterator first,
                  list<Point>::const_iterator last );
    void  insert( istream_iterator<Point,ptrdiff_t> first,
                  istream_iterator<Point,ptrdiff_t> last );
    void  clear( );
    
    // validity check
    bool  is_valid( bool verbose = false, int level = 0) const;
    
    // miscellaneous
    const Traits&  traits( ) const;
    **************************************************************************/

  private:
    // private data members
    Traits       tco;                           // traits class object
    list<Point>  points;                        // doubly linked list of points
    int          n_support_points;              // number of support points
    Point*       support_points;                // array of support points
    

    // copying and assignment not allowed!
    CGAL_Min_ellipse_2( const CGAL_Min_ellipse_2<_Traits>&);
    CGAL_Min_ellipse_2<_Traits>&
        operator = ( const CGAL_Min_ellipse_2<_Traits>&);

// ============================================================================

// Class implementation
// ====================

  public:
    // Access functions and predicates
    // -------------------------------
    // #points and #support points
    inline
    int
    number_of_points( ) const
    {
        return( points.size());
    }
    
    inline
    int
    number_of_support_points( ) const
    {
        return( n_support_points);
    }

    // is_... predicates
    inline
    bool
    is_empty( ) const
    {
        return( number_of_support_points() == 0);
    }
    
    inline
    bool
    is_degenerate( ) const
    {
        return( number_of_support_points() <  2);
    }

    // access to points and support points
    inline
    Point_iterator
    points_begin( ) const
    {
        return( points.begin());
    }
    
    inline
    Point_iterator
    points_end( ) const
    {
        return( points.end());
    }
    
    inline
    Support_point_iterator
    support_points_begin( ) const
    {
        return( support_points);
    }
    
    inline
    Support_point_iterator
    support_points_end( ) const
    {
        return( support_points+n_support_points);
    }
    
    // random access for support points
    inline
    const Point&
    support_point( int i) const
    {
        CGAL_optimisation_precondition( (i >= 0) &&
                                        (i <  number_of_support_points()));
        return( support_points[ i]);
    }
    // ellipse
    inline
    const Ellipse&
    ellipse( ) const
    {
        return( tco.ellipse);
    }
    

    // in-ellipse test predicates
    inline
    CGAL_Bounded_side
    bounded_side( const Point& p) const
    {
        return( tco.ellipse.bounded_side( p));
    }
    
    inline
    bool
    has_on_bounded_side( const Point& p) const
    {
        return( tco.ellipse.has_on_bounded_side( p));
    }
    
    inline
    bool
    has_on_boundary( const Point& p) const
    {
        return( tco.ellipse.has_on_boundary( p));
    }
    
    inline
    bool
    has_on_unbounded_side( const Point& p) const
    {
        return( tco.ellipse.has_on_unbounded_side( p));
    }

  private:
    // Privat member functions
    // -----------------------
    // compute_ellipse
    inline
    void
    compute_ellipse( )
    {
        switch ( n_support_points) {
          case 5:
            tco.ellipse.set( support_points[ 0],
                             support_points[ 1],
                             support_points[ 2],
                             support_points[ 3],
                             support_points[ 4]);
            break;
          case 4:
            tco.ellipse.set( support_points[ 0],
                             support_points[ 1],
                             support_points[ 2],
                             support_points[ 3]);
            break;
          case 3:
            tco.ellipse.set( support_points[ 0],
                             support_points[ 1],
                             support_points[ 2]);
            break;
          case 2:
            tco.ellipse.set( support_points[ 0], support_points[ 1]);
            break;
          case 1:
            tco.ellipse.set( support_points[ 0]);
            break;
          case 0:
            tco.ellipse.set( );
            break;
          default:
            CGAL_optimisation_assertion( ( n_support_points >= 0) &&
                                         ( n_support_points <= 5) ); }
    }

    void
    me( const Point_iterator& last, int n_sp)
    {
        // compute ellipse through support points
        n_support_points = n_sp;
        compute_ellipse();
        if ( n_sp == 5) return;
    
        // test first n points
        list<Point>::iterator  point_iter( points.begin());
        for ( ; last != point_iter; ) {
            const Point& p( *point_iter);
    
            // p not in current ellipse?
            if ( has_on_unbounded_side( p)) {
    
                // recursive call with p as additional support point
                support_points[ n_sp] = p;
                me( point_iter, n_sp+1);
    
                // move current point to front
                if ( point_iter != points.begin()) {            // p not first?
                    points.push_front( p);
                    points.erase( point_iter++); }
                else
                    ++point_iter; }
            else
                ++point_iter; }
    }

  public:
    // Constructors
    // ------------
    #ifndef CGAL_CFG_NO_MEMBER_TEMPLATES
    
        // STL-like constructor (member template)
        template < class InputIterator >
        CGAL_Min_ellipse_2( InputIterator first,
                            InputIterator last,
                            bool          randomize = false,
                            CGAL_Random&  random    = CGAL_random,
                            const Traits& traits    = Traits())
            : tco( traits)
        {
            // allocate support points' array
            support_points = new Point[ 5];
    
            // range not empty?
            if ( first != last) {
    
                // store points
                if ( randomize) {
    
                    // shuffle points at random
                    vector<Point> v( first, last);
                    random_shuffle( v.begin(), v.end(), random);
                    copy( v.begin(), v.end(), back_inserter( points)); }
                else
                    copy( first, last, back_inserter( points)); }
    
            // compute mc
            me( points.end(), 0);
        }
    
    #else
    
        // STL-like constructor for C array and vector<Point>
        CGAL_Min_ellipse_2( const Point*  first,
                            const Point*  last,
                            bool          randomize = false,
                            CGAL_Random&  random    = CGAL_random,
                            const Traits& traits    = Traits())
            : tco( traits)
        {
            // allocate support points' array
            support_points = new Point[ 5];
    
            // range not empty?
            if ( ( last-first) > 0) {
    
                // store points
                if ( randomize) {
    
                    // shuffle points at random
                    vector<Point> v( first, last);
                    random_shuffle( v.begin(), v.end(), random);
                    copy( v.begin(), v.end(), back_inserter( points)); }
                else
                    copy( first, last, back_inserter( points)); }
    
            // compute me
            me( points.end(), 0);
        }
    
        // STL-like constructor for list<Point>
        CGAL_Min_ellipse_2( list<Point>::const_iterator first,
                            list<Point>::const_iterator last,
                            bool          randomize = false,
                            CGAL_Random&  random    = CGAL_random,
                            const Traits& traits    = Traits())
            : tco( traits)
        {
            // allocate support points' array
            support_points = new Point[ 5];
    
            // compute number of points
            list<Point>::size_type n = 0;
            CGAL__distance( first, last, n);
            if ( n > 0) {
    
                // store points
                if ( randomize) {
    
                    // shuffle points at random
                    vector<Point> v;
                    v.reserve( n);
                    copy( first, last, back_inserter( v));
                    random_shuffle( v.begin(), v.end(), random);
                    copy( v.begin(), v.end(), back_inserter( points)); }
                else
                    copy( first, last, back_inserter( points)); }
    
            // compute me
            me( points.end(), 0);
        }
    
        // STL-like constructor for stream iterator istream_iterator<Point>
        CGAL_Min_ellipse_2( istream_iterator<Point,ptrdiff_t>  first,
                            istream_iterator<Point,ptrdiff_t>  last,
                            bool          randomize = false,
                            CGAL_Random&  random    = CGAL_random,
                            const Traits& traits    = Traits())
            : tco( traits)
        {
            // allocate support points' array
            support_points = new Point[ 5];
    
            // range not empty?
            if ( first != last) {
    
                // store points
                if ( randomize) {
    
                    // shuffle points at random
                    vector<Point> v;
                    copy( first, last, back_inserter( v));
                    random_shuffle( v.begin(), v.end(), random);
                    copy( v.begin(), v.end(), back_inserter( points)); }
                else
                    copy( first, last, back_inserter( points)); }
    
            // compute me
            me( points.end(), 0);
        }
    
    #endif // CGAL_CFG_NO_MEMBER_TEMPLATES
    
    // default constructor
    inline
    CGAL_Min_ellipse_2( const Traits& traits = Traits())
        : tco( traits), n_support_points( 0)
    {
        // allocate support points' array
        support_points = new Point[ 5];
    
        // initialize ellipse
        tco.ellipse.set();
    
        CGAL_optimisation_postcondition( is_empty());
    }
    
    // constructor for one point
    inline
    CGAL_Min_ellipse_2( const Point& p, const Traits& traits = Traits())
        : tco( traits), points( 1, p), n_support_points( 1)
    {
        // allocate support points' array
        support_points = new Point[ 5];
    
        // initialize ellipse
        support_points[ 0] = p;
        tco.ellipse.set( p);
    
        CGAL_optimisation_postcondition( is_degenerate());
    }
    
    // constructor for two points
    inline
    CGAL_Min_ellipse_2( const Point& p,
                        const Point& q,
                        const Traits& traits = Traits())
        : tco( traits)
    {
        // allocate support points' array
        support_points = new Point[ 5];
    
        // store points
        points.push_back( p);
        points.push_back( q);
    
        // compute me
        me( points.end(), 0);
    }
    
    // constructor for three points
    inline
    CGAL_Min_ellipse_2( const Point& p1,
                        const Point& p2,
                        const Point& p3,
                        const Traits& traits = Traits())
        : tco( traits)
    {
        // allocate support points' array
        support_points = new Point[ 5];
    
        // store points
        points.push_back( p1);
        points.push_back( p2);
        points.push_back( p3);
    
        // compute me
        me( points.end(), 0);
    }
    
    // constructor for four points
    inline
    CGAL_Min_ellipse_2( const Point& p1,
                        const Point& p2,
                        const Point& p3,
                        const Point& p4,
                        const Traits& traits = Traits())
        : tco( traits)
    {
        // allocate support points' array
        support_points = new Point[ 5];
    
        // store points
        points.push_back( p1);
        points.push_back( p2);
        points.push_back( p3);
        points.push_back( p4);
    
        // compute me
        me( points.end(), 0);
    }
    
    // constructor for five points
    inline
    CGAL_Min_ellipse_2( const Point& p1,
                        const Point& p2,
                        const Point& p3,
                        const Point& p4,
                        const Point& p5,
                        const Traits& traits = Traits())
        : tco( traits)
    {
        // allocate support points' array
        support_points = new Point[ 5];
    
        // store points
        points.push_back( p1);
        points.push_back( p2);
        points.push_back( p3);
        points.push_back( p4);
        points.push_back( p5);
    
        // compute me
        me( points.end(), 0);
    }
    

    // Destructor
    // ----------
    inline
    ~CGAL_Min_ellipse_2( )
    {
        // free support points' array
        delete[] support_points;
    }

    // Modifiers
    // ---------
    void
    insert( const Point& p)
    {
        // p not in current ellipse?
        if ( has_on_unbounded_side( p)) {
    
            // p new support point
            support_points[ 0] = p;
    
            // recompute me
            me( points.end(), 1);
    
            // store p as the first point in list
            points.push_front( p); }
        else
    
            // append p to the end of the list
            points.push_back( p);
    }
    #ifndef CGAL_CFG_NO_MEMBER_TEMPLATES
    
        template < class InputIterator >
        void
        insert( InputIterator first, InputIterator last)
        {
            for ( ; first != last; ++first)
                insert( *first);
        }
    
    #else
    
        inline
        void
        insert( const Point* first, const Point* last)
        {
            for ( ; first != last; ++first)
                insert( *first);
        }
    
        inline
        void
        insert( list<Point>::const_iterator first,
                list<Point>::const_iterator last )
        {
            for ( ; first != last; ++first)
                insert( *first);
        }
    
        inline
        void
        insert( istream_iterator<Point,ptrdiff_t>  first,
                istream_iterator<Point,ptrdiff_t>  last )
        {
            for ( ; first != last; ++first)
                insert( *first);
        }
    
    #endif // CGAL_CFG_NO_MEMBER_TEMPLATES
    void
    clear( )
    {
        points.erase( points.begin(), points.end());
        n_support_points = 0;
        tco.ellipse.set();
    }
    

    // Validity check
    // --------------
    bool
    is_valid( bool verbose = false, int level = 0) const
    {
        CGAL_Verbose_ostream verr( verbose);
        verr << endl;
        verr << "CGAL_Min_ellipse_2<Traits>::" << endl;
        verr << "is_valid( true, " << level << "):" << endl;
        verr << "  |P| = " << number_of_points()
             << ", |S| = " << number_of_support_points() << endl;
    
        // containment check (a)
        verr << "  a) containment check..." << flush;
        Point_iterator point_iter;
        for ( point_iter  = points_begin();
              point_iter != points_end();
              ++point_iter)
            if ( has_on_unbounded_side( *point_iter))
                return( CGAL__optimisation_is_valid_fail( verr,
                            "ellipse does not contain all points"));
        verr << "passed." << endl;
    
        // support set checks (b)+(c) (not yet implemented)
        
        // alternative support set check
        verr << "  +) support set check..." << flush;
        Support_point_iterator support_point_iter;
        for ( support_point_iter  = support_points_begin();
              support_point_iter != support_points_end();
              ++support_point_iter)
            if ( ! has_on_boundary( *support_point_iter))
                return( CGAL__optimisation_is_valid_fail( verr,
                            "ellipse does not have all \
                             support points on the boundary"));
        verr << "passed." << endl;
    
        verr << "  object is valid!" << endl;
        return( true);
    }

    // Miscellaneous
    // -------------
    inline
    const Traits&
    traits( ) const
    {
        return( tco);
    }
};

// Function declarations
// =====================
// I/O
// ---
template < class _Traits >
ostream& operator << ( ostream& os, const CGAL_Min_ellipse_2<_Traits>& me);

template < class _Traits >
istream& operator >> ( istream& is, CGAL_Min_ellipse_2<_Traits>      & me);

#ifdef CGAL_CFG_NO_AUTOMATIC_TEMPLATE_INCLUSION
#  include <CGAL/Min_ellipse_2.C>
#endif

#endif // CGAL_MIN_ELLIPSE_2_H

// ===== EOF ==================================================================