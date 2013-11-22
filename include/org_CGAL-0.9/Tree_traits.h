/* 

Copyright (c) 1997 The CGAL Consortium

This software and related documentation is part of the 
Computational Geometry Algorithms Library (CGAL).

Permission to use, copy, and distribute this software and its 
documentation is hereby granted free of charge, provided that 
(1) it is not a component of a commercial product, and 
(2) this notice appears in all copies of the software and
    related documentation. 

CGAL may be distributed by any means, provided that the original
files remain intact, and no charge is made other than for
reasonable distribution costs.

CGAL may not be distributed as a component of any commercial
product without a prior license agreement with the authors.

This software and documentation is provided "as-is" and without 
warranty of any kind. In no event shall the CGAL Consortium be
liable for any damage of any kind.

The CGAL Consortium consists of Utrecht University (The Netherlands), 
ETH Zurich (Switzerland), Free University of Berlin (Germany), 
INRIA Sophia-Antipolis (France), Max-Planck-Institute Saarbrucken
(Germany), RISC Linz (Austria), and Tel-Aviv University (Israel).

*/

// file  : include/CGAL/Tree_traits.h
// source: include/CGAL/Tree_traits.h
// author: Gabriele Neyer
// $Revision: 1.1 $
// $Date: 1997/06/16 13:42:10 $

#ifndef __CGAL_tree_traits__
#define __CGAL_tree_traits__

// Implementation of a minimal tree traits for CGAL trees, derived from CGAL_Tree_base.h
// (e.g. CGAL_Range_tree_d.h and CGAL_Segment_tree_d.h).
// Any other interface must at least provide the interface of this class.



// Interface as it is expected for one layer of a Range Tree
template<class _Data, class _Window, class _Key,          
         class _Data_func, class _Window_left_func, 
	 class _Window_right_func, class _Compare>
class CGAL_tree_point_traits{
 public:
  typedef _Key Key;
  typedef _Data Data;
  typedef _Window Window;
  typedef _Compare Compare;

  _Key get_key(const _Data&  dt)
    const {return _Data_func()(dt);}
  _Key get_left(const _Window& dt)
    const {return _Window_left_func()(dt);}
  _Key get_right(const _Window& dt)
    const {return _Window_right_func()(dt);}

  static bool comp(_Key const& key1, _Key const& key2) 
  {return _Compare()(key1, key2);} 
  static bool key_comp(_Data const& data1, _Data const& data2)
  {
    const Key d1=_Data_func()(data1);
    const Key d2=_Data_func()(data2);
    return _Compare()(d1,d2);
  }
};


// Interface as it is expected for one layer of a Segment Tree
template<class _Data, class _Window, class _Key,  
         class _Data_left_func, class _Data_right_func, 
	 class _Window_left_func, class _Window_right_func, class _Compare>
class CGAL_tree_interval_traits{
 public:
  typedef _Data Data;
  typedef _Window Window;
  typedef _Key Key;
  typedef _Compare Compare;
  
  _Key get_left(const _Data&  dt)
    const {return _Data_left_func()(dt);}
  _Key get_right(const _Data& dt)
    const {return _Data_right_func()(dt);}
  _Key get_left_win(const _Window& dt)
    const {return _Window_left_func()(dt);}
  _Key get_right_win(const _Window& dt)
    const {return _Window_right_func()(dt);}

  static bool comp(_Key const& key1, _Key const& key2) 
    {return _Compare()(key1, key2);} 
};

#endif



