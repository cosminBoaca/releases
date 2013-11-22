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

// Author: Stefan Schirra
// Source: cgal_convex_hull_2.lw

#ifndef CGAL_CH_SELECTED_EXTREME_POINTS_2_H
#define CGAL_CH_SELECTED_EXTREME_POINTS_2_H

#include <CGAL/ch_assertions.h>
#include <CGAL/ch_utils.h>
#ifdef CGAL_REP_CLASS_DEFINED
#include <CGAL/convex_hull_traits_2.h>
#ifdef __GNUG__
#include <CGAL/gnu_istream_iterator_value_type_fix.h>
#endif // __GNUG__
#endif // CGAL_REP_CLASS_DEFINED
#ifndef CGAL_CH_NO_POSTCONDITIONS
#include <CGAL/convexity_check_2.h>

#endif // CGAL_CH_NO_POSTCONDITIONS


/*{\Moptions
outfile=cgal_ch_I_sep.man
}*/

/*{\Mtext
\settowidth{\typewidth}{|OutputIterator|}
\addtolength{\typewidth}{\colsep}
\settowidth{\callwidth}{|CGAL_ch_|}
\computewidths
}*/

/*{\Mtext [[\#include <CGAL/ch_selected_extreme_points_2.h>]]
}*/

template <class ForwardIterator, class Traits>
void
CGAL_ch_ns_point( ForwardIterator first, ForwardIterator last,
                  ForwardIterator& n,
                  ForwardIterator& s,
                  const Traits& ch_traits);
/*{\Mfuncl traverses the range [|first|,|last|). 
After execution, the value of |n| is
an iterator in the range such that |*n| $\ge_{\rm yx}$ |*it| for
all iterators |it| in the range. Similarly, for |s| the inequation
|*s| $\le_{\rm yx}$ |*it| holds for all iterators |it| in the range.\\
{\sc traits}: uses function object types |Traits::Less_yx| and
|Traits::Greater_yx|.
}*/

template <class ForwardIterator, class Traits>
void
CGAL_ch_we_point( ForwardIterator first, ForwardIterator last,
                  ForwardIterator& w,
                  ForwardIterator& e,
                  const Traits& ch_traits);
/*{\Mfuncl traverses the range [|first|,|last|). 
After execution, the value of |w| is
an iterator in the range such that |*w| $\le_{\rm xy}$ |*it| for
all iterators |it| in the range. Similarly, for |e| the inequation
|*e| $\ge_{\rm yx}$ |*it| holds for all iterators |it| in the range.\\
{\sc traits}: uses function object types |Traits::Less_xy| and
|Traits::Greater_xy|.
}*/

template <class ForwardIterator, class Traits>
void
CGAL_ch_nswe_point( ForwardIterator first, ForwardIterator last,
                    ForwardIterator& n,
                    ForwardIterator& s,
                    ForwardIterator& w,
                    ForwardIterator& e,
                    const Traits& ch_traits);
/*{\Mfuncl traverses the range [|first|,|last|). 
After execution, the value of |n| is
an iterator in the range such that |*n| $\ge_{\rm yx}$ |*it| for
all iterators |it| in the range. Similarly, for |s|, |w|, and |e| 
the inequations |*s| $\le_{\rm yx}$ |*it|, |*w| $\le_{\rm xy}$ |*it|,
and |*e| $\ge_{\rm yx}$ |*it| hold respectively for all iterators 
|it| in the range.\\
{\sc traits}: uses |Traits::Less_xy|, |Traits::Less_yx|,
|Traits::Greater_xy|, and |Traits::Greater_yx|.
}*/

template <class ForwardIterator, class Traits>
void
CGAL_ch_n_point( ForwardIterator first, ForwardIterator last,
                 ForwardIterator& n,
                 const Traits& ch_traits);
/*{\Mfuncl traverses the range [|first|,|last|). After execution, 
the value of |n| is
an iterator in the range such that |*n| $\ge_{\rm yx}$ |*it| for
all iterators |it| in the range.\\ 
{\sc traits}: uses |Traits::Greater_yx|.
}*/

template <class ForwardIterator, class Traits>
void
CGAL_ch_s_point( ForwardIterator first, ForwardIterator last,
                 ForwardIterator& s,
                 const Traits& ch_traits);
/*{\Mfuncl traverses the range [|first|,|last|). After execution, 
the value of |s| is
an iterator in the range such that |*s| $\le_{\rm yx}$ |*it| for
all iterators |it| in the range.\\ 
{\sc traits}: uses |Traits::Less_yx|.
}*/

template <class ForwardIterator, class Traits>
void
CGAL_ch__e_point( ForwardIterator first, ForwardIterator last,
                  ForwardIterator& e,
                  const Traits& ch_traits);
/*{\Mfuncl traverses the range [|first|,|last|). After execution, 
the value of |e| is
an iterator in the range such that |*e| $\ge_{\rm yx}$ |*it| for
for all iterators |it| in the range.\\
{\sc traits}: uses |Traits::Greater_xy|.
}*/

template <class ForwardIterator, class Traits>
void
CGAL_ch_w_point( ForwardIterator first, ForwardIterator last,
                 ForwardIterator& w,
                 const Traits& ch_traits);
/*{\Mfuncl traverses the range [|first|,|last|). After execution, 
the value of |w| is
an iterator in the range such that |*w| $\le_{\rm yx}$ |*it| for
for all iterators |it| in the range.\\
{\sc traits}: uses |Traits::Less_yx|.
}*/

#ifdef CGAL_POINT_2_H
/*{\Moptions
outfile=cgal_ch_sep.man
}*/

/*{\Mtext 
\settowidth{\typewidth}{|OutputIterator|}
\addtolength{\typewidth}{\colsep}
\settowidth{\callwidth}{|CGAL_ch_|}
\computewidths
}*/

template <class ForwardIterator, class R>
inline
void
CGAL_ch_n_point( ForwardIterator first, ForwardIterator last,
                 ForwardIterator& n, 
                 CGAL_Point_2<R>* )
{
  CGAL_ch_n_point(first, last, n, CGAL_convex_hull_traits_2<R>() );
}

template <class ForwardIterator>
inline
void
CGAL_ch_n_point( ForwardIterator first, ForwardIterator last,
                 ForwardIterator& n)
{
  CGAL_ch__n_point(first, last, n, value_type(first) );
}
/*{\Mfuncl traverses the range [|first|,|last|). After execution, 
the value of |n| is
an iterator in the range such that |*n| $\ge_{\rm yx}$ |*it| for
all iterators |it| in the range. 
}*/

template <class ForwardIterator, class R>
inline
void
CGAL_ch__s_point( ForwardIterator first, ForwardIterator last,
                  ForwardIterator& s,
                  CGAL_Point_2<R>* )
{
  CGAL_ch_s_point(first, last, s, CGAL_convex_hull_traits_2<R>() );
}

template <class ForwardIterator>
inline
void
CGAL_ch_s_point( ForwardIterator first, ForwardIterator last,
                 ForwardIterator& s)
{
  CGAL_ch__s_point(first, last, s, value_type(first) );
}
/*{\Mfuncl traverses the range [|first|,|last|). After execution, 
the value of |s| is
an iterator in the range such that |*s| $\le_{\rm yx}$ |*it| for
all iterators |it| in the range. 
}*/

template <class ForwardIterator, class R>
inline
void
CGAL_ch__e_point( ForwardIterator first, ForwardIterator last,
                  ForwardIterator& e,
                  CGAL_Point_2<R>* )
{
  CGAL_ch__e_point(first, last, e, CGAL_convex_hull_traits_2<R>() );
}

template <class ForwardIterator>
inline
void
CGAL_ch__e_point( ForwardIterator first, ForwardIterator last,
                  ForwardIterator& e)
{
  CGAL_ch__e_point(first, last, e, value_type(first) );
}
/*{\Mfuncl traverses the range [|first|,|last|). 
After execution, the value of |e| is
an iterator in the range such that |*e| $\ge_{\rm xy}$ |*it| for
all iterators |it| in the range. 
}*/

template <class ForwardIterator, class R>
inline
void
CGAL_ch__w_point( ForwardIterator first, ForwardIterator last,
                  ForwardIterator& w,
                  CGAL_Point_2<R>* )
{
  CGAL_ch_w_point(first, last, w, CGAL_convex_hull_traits_2<R>() );
}

template <class ForwardIterator>
inline
void
CGAL_ch_w_point( ForwardIterator first, ForwardIterator last,
                      ForwardIterator& w)
{
 CGAL_ch__w_point(first, last, w, value_type(first) );
}
/*{\Mfuncl traverses the range [|first|,|last|). After execution, 
the value of |w| is
an iterator in the range such that |*w| $\le_{\rm xy}$ |*it| for
all iterators |it| in the range. 
}*/

template <class ForwardIterator, class R>
inline
void
CGAL_ch__ns_point( ForwardIterator first, ForwardIterator last,
                   ForwardIterator& n,
                   ForwardIterator& s,
                   CGAL_Point_2<R>* )
{
  CGAL_ch_ns_point(first, last, n, s, CGAL_convex_hull_traits_2<R>() );
}

template <class ForwardIterator>
inline
void
CGAL_ch_ns_point( ForwardIterator first, ForwardIterator last,
                  ForwardIterator& n,
                  ForwardIterator& s)
{
  CGAL_ch__ns_point(first, last, n, s, value_type(first) );
}
/*{\Mfuncl traverses the range [|first|,|last|). 
After execution, the value of |n| is
an iterator in the range such that |*n| $\ge_{\rm yx}$ |*it| for
all iterators |it| in the range. Similarly, for |s| the inequation
|*s| $\le_{\rm yx}$ |*it| holds for all iterators |it| in the range.}*/

template <class ForwardIterator, class R>
inline
void
CGAL_ch__we_point( ForwardIterator first, ForwardIterator last,
                   ForwardIterator& w,
                   ForwardIterator& e,
                   CGAL_Point_2<R>* )
{
  CGAL_ch_we_point(first, last, w, e, CGAL_convex_hull_traits_2<R>() );
}

template <class ForwardIterator>
inline
void
CGAL_ch_we_point( ForwardIterator first, ForwardIterator last,
                  ForwardIterator& w,
                  ForwardIterator& e)
{
  CGAL_ch__we_point(first, last, w, e, value_type(first) );
}
/*{\Mfuncl traverses the range [|first|,|last|). 
After execution, the value of |w| is
an iterator in the range such that |*w| $\le_{\rm xy}$ |*it| for
all iterators |it| in the range. Similarly, for |e| the inequation
|*e| $\ge_{\rm yx}$ |*it| holds for all iterators |it| in the range.}*/


template <class ForwardIterator, class R>
inline
void
CGAL_ch__nswe_point( ForwardIterator first, ForwardIterator last,
                     ForwardIterator& n,
                     ForwardIterator& s,
                     ForwardIterator& w,
                     ForwardIterator& e,
                     CGAL_Point_2<R>* )
{
  CGAL_ch_nswe_point(first, last, n, s, w, e, CGAL_convex_hull_traits_2<R>());
}

template <class ForwardIterator>
inline
void
CGAL_ch_nswe_point( ForwardIterator first, ForwardIterator last,
                    ForwardIterator& n,
                    ForwardIterator& s,
                    ForwardIterator& w,
                    ForwardIterator& e)
{
  CGAL_ch__nswe_point(first, last, n, s, w, e, value_type(first) );
}
/*{\Mfuncl traverses the range [|first|,|last|). 
After execution, the value of |n| is
an iterator in the range such that |*n| $\ge_{\rm yx}$ |*it| for
all iterators |it| in the range. Similarly, for |s|, |w|, and |e| 
the inequations |*s| $\le_{\rm yx}$ |*it|, |*w| $\le_{\rm xy}$ |*it|,
and |*e| $\ge_{\rm yx}$ |*it| hold respectively for all iterators 
|it| in the range.}*/

#endif // CGAL_POINT_2_H

#ifdef CGAL_INCLUDE_TEMPLATE_CODE
#include <CGAL/ch_selected_extreme_points_2.C>
#endif // CGAL_INCLUDE_TEMPLATE_CODE

#endif // CGAL_CH_SELECTED_EXTREME_POINTS_2_H

