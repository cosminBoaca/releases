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
// file          : include/CGAL/sorted_matrix_search.h
// author(s)     : Michael Hoffmann 
//
// email         : cgal@cs.uu.nl
//
// ============================================================================

#if ! (CGAL_SORTED_MATRIX_SEARCH_H)
#define CGAL_SORTED_MATRIX_SEARCH_H 1

#ifndef CGAL_BASIC_H
#include <CGAL/basic.h>
#endif // CGAL_BASIC_H
#ifndef CGAL_PROTECT_ALGO_H
#include <algo.h>
#define CGAL_PROTECT_ALGO_H
#endif // CGAL_PROTECT_ALGO_H
#ifndef CGAL_PROTECT_FUNCTION_H
#include <function.h>
#define CGAL_PROTECT_FUNCTION_H
#endif // CGAL_PROTECT_FUNCTION_H
#ifndef CGAL_PROTECT_VECTOR_H
#include <vector.h>
#define CGAL_PROTECT_VECTOR_H
#endif // CGAL_PROTECT_VECTOR_H
#ifndef CGAL_SORTED_MATRIX_SEARCH_TRAITS_ADAPTOR_H
#include <CGAL/Sorted_matrix_search_traits_adaptor.h>
#endif // CGAL_SORTED_MATRIX_SEARCH_TRAITS_ADAPTOR_H

template < class Matrix >
class CGAL__Padded_matrix {
public:
  typedef typename Matrix::Value Value;

  CGAL__Padded_matrix( const Matrix& m) : matrix( &m) {}

  Value
  operator()( int x, int y) const
  // padded access operator
  {
    return matrix->operator()(
      x < matrix->number_of_columns() ?
        x : matrix->number_of_columns() - 1,
      y < matrix->number_of_rows() ?
        y : matrix->number_of_rows() - 1);
  }

  bool
  is_sorted()
  // tests iff this matrix is sorted, i.e. in each column/row
  // the elements appear in increasing order
  // time complexity is proportional to the number of elements
  {
    for ( int i = 0; i < matrix->x_dimension(); ++i)
      for ( int j = 0; j < matrix->y_dimension(); ++j) {
        if ( i > 0 && (*matrix)( i - 1, j) > (*matrix)( i, j))
          return false;
        if ( j > 0 && (*matrix)( i, j - 1) > (*matrix)( i, j))
          return false;
      }
    return true;
  }

private:
  const Matrix* matrix;
};
template < class PaddedMatrix >
class CGAL__Matrix_cell {
public:
  typedef typename PaddedMatrix::Value Value;

  CGAL__Matrix_cell( PaddedMatrix m, int xpos = 0, int ypos = 0)
  : base_matrix( m), x( xpos), y( ypos)
  {}

  Value
  min() const
  { return base_matrix( x, y); }

  Value
  max( int offset) const
  // offset denotes the cell's dimension
  { return base_matrix( x + offset - 1, y + offset - 1); }

  int
  x_min() const
  { return x; }

  int
  y_min() const
  { return y; }

  PaddedMatrix
  matrix() const
  { return base_matrix; }

  void
  output( ostream& o, int dim) const
  {
    for ( int i = 0; i < dim; ++i) {
      for ( int j = 0; j < dim; ++j)
        o << base_matrix( x + i, y + j) << " ";
      o << endl;
    }
  }

private:
  PaddedMatrix base_matrix;
  int x;
  int y;
};
template < class Cell >
struct CGAL__Cell_min
: public unary_function< Cell, typename Cell::Value >
{
  typename Cell::Value
  operator()( const Cell& c) const
  { return c.min(); }
};

template < class Cell >
struct CGAL__Cell_max
: public unary_function< Cell, typename Cell::Value > {

  CGAL__Cell_max( int offset) : ofs( offset) {}

  typename Cell::Value
  operator()( const Cell& c) const
  { return c.max( ofs); }

private:
  int ofs;
};


#ifdef CGAL_CFG_RETURN_TYPE_BUG_1
template < class T >
struct CGAL_Traits_value_bug_fix1
{
  typedef typename T::Value Value;
  CGAL_Traits_value_bug_fix1( Value xt)
  { _xt = xt; }

  operator Value() const
  { return _xt; }

private:
  Value _xt;
};
#endif

template < class InputIterator, class Traits >
#ifndef CGAL_CFG_RETURN_TYPE_BUG_1
typename Traits::Value
#else
CGAL_Traits_value_bug_fix1< Traits >
#endif
CGAL_sorted_matrix_search( InputIterator f,
                           InputIterator l,
                           Traits t)
{
  typedef typename Traits::Matrix           Matrix;
  typedef typename Traits::Value            Value;
  typedef CGAL__Padded_matrix< Matrix >     PaddedMatrix;
  typedef CGAL__Matrix_cell< PaddedMatrix > Cell;
  typedef vector< Cell >                    Cell_container;
  typedef typename Cell_container::iterator
    Cell_iterator;
  typedef typename Cell_container::reverse_iterator
    Cell_reverse_iterator;
  
  Cell_container active_cells;
  #ifdef CGAL_SORTED_MATRIX_SEARCH_TRACE
  cerr << "insert a cell for every matrix" << endl;
  #endif
  
  // set of input matrices must not be empty:
  CGAL_precondition( f != l);
  
  // for each input matrix insert a cell into active_cells:
  InputIterator i( f);
  int maxdim( -1);
  while ( i != l) {
    CGAL_expensive_precondition(
      PaddedMatrix( *i).is_sorted());
    active_cells.push_back( Cell( PaddedMatrix( *i)));
    maxdim = max( max( (*i).number_of_columns(),
                       (*i).number_of_rows()),
                  maxdim);
    ++i;
  }
  CGAL_precondition( maxdim > 0);
  
  #ifdef CGAL_SORTED_MATRIX_SEARCH_TRACE
  cerr << "\ncomputing ccd" << endl;
  #endif
  
  // current cell dimension:
  int ccd( 1);
  // set ccd to a power of two >= maxdim:
  while ( ccd < maxdim)
    ccd <<= 1;
  
  /*
  #ifdef CGAL_SORTED_MATRIX_SEARCH_TRACE
  for ( Cell_iterator j( active_cells.begin());
  j != active_cells.end();
  ++j) {
    (*j).output( cerr, ccd);
    cerr << "-------------------------------------\n";
  }
  cerr << "ccd is " << ccd << endl;
  #endif
  */
  
  

  // now start the search:
  #ifdef CGAL_SORTED_MATRIX_SEARCH_TRACE
  cerr << "start search ..." << endl;
  #endif

  for (;;) {
    if ( ccd > 1) {
      // ------------------------------------------------------
      // divide cells:
      ccd >>= 1;
    
      #ifdef CGAL_SORTED_MATRIX_SEARCH_TRACE
      cerr << "divide cells" << endl;
      #endif
    
      // reserve is required here!
      // otherwise one of the insert operations might cause
      // a reallocation invalidating j
      // (should typically result in a segfault)
      active_cells.reserve( 4 * active_cells.size());
    
      for ( Cell_reverse_iterator j( active_cells.rbegin());
            j != active_cells.rend();
            ++j) {
    
        // upper-left quarter:
        // Cell( (*j).matrix(),
        //       (*j).x_min(),
        //       (*j).y_min()) remains in active_cells,
        // since it is implicitly shortened by decreasing ccd
    
        // lower-left quarter:
        active_cells.push_back(
          Cell( (*j).matrix(),
                (*j).x_min(),
                (*j).y_min() + ccd));
    
        // upper-right quarter:
        active_cells.push_back(
          Cell( (*j).matrix(),
                (*j).x_min() + ccd,
                (*j).y_min()));
    
        // lower-right quarter:
        active_cells.push_back(
          Cell( (*j).matrix(),
                (*j).x_min() + ccd,
                (*j).y_min() + ccd));
    
      } // for all active cells
    } // if ( ccd > 1)
    else if ( active_cells.size() <= 1) //!!! maybe handle <= 3
      break;
    
    // there has to be at least one cell left:
    CGAL_assertion( active_cells.size() > 0);
    
    #ifdef CGAL_SORTED_MATRIX_SEARCH_TRACE
    cerr << "\ncurrently there are " << active_cells.size()
         << " cells\n=======================================\n";
    
    /*
    cerr << "listing active cells:\n";
    for ( Cell_iterator j( active_cells.begin());
    j != active_cells.end();
    ++j) {
      cerr << "------------------------------\n";
      (*j).output( cerr, ccd);
    }
    */
    
    cerr << "\nccd is " << ccd << endl;
    #endif
    // ------------------------------------------------------
    // compute medians of smallest and largest elements:
    
    #ifdef CGAL_SORTED_MATRIX_SEARCH_TRACE
    cerr << "compute medians" << endl;
    #endif
    
    int lower_median_rank = ( active_cells.size() - 1) >> 1;
    int upper_median_rank = ( active_cells.size() >> 1);
    
    // compute upper median of cell's minima:
    nth_element( active_cells.begin(),
                 active_cells.begin() + upper_median_rank,
                 active_cells.end(),
                 CGAL_compose2_2(
                   t.compare_strictly(),
                   CGAL__Cell_min< Cell >(),
                   CGAL__Cell_min< Cell >()));
    
    Cell_iterator lower_median_cell =
      active_cells.begin() + upper_median_rank;
    Value lower_median = (*lower_median_cell).min();
    
    // compute lower median of cell's maxima:
    nth_element( active_cells.begin(),
                 active_cells.begin() + lower_median_rank,
                 active_cells.end(),
                 CGAL_compose2_2(
                   t.compare_strictly(),
                   CGAL__Cell_max< Cell >( ccd),
                   CGAL__Cell_max< Cell >( ccd)));
    
    Cell_iterator upper_median_cell =
      active_cells.begin() + lower_median_rank;
    Value upper_median = (*upper_median_cell).max( ccd);
    // ------------------------------------------------------
    // test feasibility of medians and remove cells accordingly:
    Cell_iterator new_end;
    
    #ifdef CGAL_SORTED_MATRIX_SEARCH_TRACE
    cerr << "lower_median is " << lower_median << " and " <<
      ( t.is_feasible( lower_median) ? "f" : "inf") <<
      "easible" << "\nupper median is " << upper_median << " and " <<
      ( t.is_feasible( upper_median) ? "f" : "inf") <<
      "easible" << endl;
    #endif
    
    if ( t.is_feasible( lower_median))
      if ( t.is_feasible( upper_median)) {
        // lower_median and upper_median are feasible
    
        // discard cells with all entries greater than
        // min( lower_median, upper_median) except for
        // one cell defining this minimum
    
        Cell_iterator min_median_cell;
        Value min_median;
        if ( lower_median < upper_median) {
          min_median_cell = lower_median_cell;
          min_median = lower_median;
        }
        else {
          min_median_cell = upper_median_cell;
          min_median = upper_median;
        }
    
        // save min_median_cell:
        iter_swap( min_median_cell, active_cells.begin());
    
        new_end =
          remove_if(
            active_cells.begin() + 1,
            active_cells.end(),
            compose1(
              bind1st( t.compare_non_strictly(), min_median),
              CGAL__Cell_min< Cell >()));
    
      } // lower_median and upper_median are feasible
      else { // lower_median is feasible, but upper_median is not
    
        // discard cells with all entries greater than
        // lower_median or all entries smaller than
        // upper_median except for the lower median cell
    
        // save lower_median_cell:
        iter_swap( lower_median_cell, active_cells.begin());
    
        new_end =
          remove_if(
            active_cells.begin() + 1,
            active_cells.end(),
            compose2(
              logical_or< bool >(),
              compose1(
                bind1st(
                  t.compare_non_strictly(),
                  lower_median),
                CGAL__Cell_min< Cell >()),
              compose1(
                bind2nd(
                  t.compare_non_strictly(),
                  upper_median),
                CGAL__Cell_max< Cell >( ccd))));
    
      } // lower_median is feasible, but upper_median is not
    else
      if ( t.is_feasible( upper_median)) {
        // upper_median is feasible, but lower_median is not
    
        // discard cells with all entries greater than
        // upper_median or all entries smaller than
        // lower_median except for the upper median cell
    
        // save upper_median_cell:
        iter_swap( upper_median_cell, active_cells.begin());
    
        new_end =
          remove_if(
            active_cells.begin() + 1,
            active_cells.end(),
            compose2(
              logical_or< bool >(),
              compose1(
                bind1st(
                  t.compare_non_strictly(),
                  upper_median),
                CGAL__Cell_min< Cell >()),
              compose1(
                bind2nd(
                  t.compare_non_strictly(),
                  lower_median),
                CGAL__Cell_max< Cell >( ccd))));
    
      } // upper_median is feasible, but lower_median is not
      else { // both upper_median and lower_median are infeasible
    
        // discard cells with all entries smaller than
        // max( lower_median, upper_median)
    
        new_end =
          remove_if(
            active_cells.begin(),
            active_cells.end(),
            compose1(
              bind2nd(
                t.compare_non_strictly(),
                max( lower_median, upper_median)),
              CGAL__Cell_max< Cell >( ccd)));
    
      } // both upper_median and lower_median are infeasible
    
      active_cells.erase( new_end, active_cells.end());
  } // for (;;)

  // there must be only one cell left:
  CGAL_assertion( active_cells.size() == 1);
  CGAL_assertion( ccd == 1);

  return (*active_cells.begin()).min();
}    

#endif // ! (CGAL_SORTED_MATRIX_SEARCH_H)

// ----------------------------------------------------------------------------
// ** EOF
// ----------------------------------------------------------------------------
