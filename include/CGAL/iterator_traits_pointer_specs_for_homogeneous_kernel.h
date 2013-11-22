// ======================================================================
//
// Copyright (c) 1999 The CGAL Consortium

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
// - Please check the CGAL web site http://www.cgal.org/index2.html for 
//   availability.
//
// The CGAL Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Freie Universitaet Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbrucken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).
//
// ----------------------------------------------------------------------
// release       : CGAL-2.4
// release_date  : 2002, May 16
//
// file          : include/CGAL/iterator_traits_pointer_specs_for_homogeneous_kernel.h
// package       : Kernel_basic (3.90)
// revision      : $Revision: 1.8 $
// revision_date : $Date: 2002/04/15 07:21:01 $
// author(s)     : Stefan Schirra
//
// coordinator   : MPI, Saarbruecken
// email         : contact@cgal.org
// www           : http://www.cgal.org
//
// ======================================================================


#ifndef CGAL_ITERATOR_TRAITS_POINTER_SPECS_FOR_HOMOGENEOUS_KERNEL_H
#define CGAL_ITERATOR_TRAITS_POINTER_SPECS_FOR_HOMOGENEOUS_KERNEL_H

// to be included in Homogeneous.h

#ifdef CGAL_LIMITED_ITERATOR_TRAITS_SUPPORT
#include <CGAL/user_classes.h>

#ifndef CGAL_STL_BEGIN_NAMESPACE
	#ifdef __STL_BEGIN_NAMESPACE
		#define CGAL_STL_BEGIN_NAMESPACE __STL_BEGIN_NAMESPACE
		#define CGAL_STL_END_NAMESPACE __STL_END_NAMESPACE
	#else
		#define CGAL_STL_BEGIN_NAMESPACE namespace std {
		#define CGAL_STL_END_NAMESPACE }
	#endif
#endif


#define CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H(NT)                                                \
CGAL_STL_BEGIN_NAMESPACE                                                               \
    template <>                                                                     \
    struct iterator_traits<const CGAL::Point_2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                       iterator_category; \
        typedef CGAL::Point_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                        difference_type;   \
        typedef const CGAL::Point_2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Point_2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                              \
    template <>                                                                     \
    struct iterator_traits<CGAL::Point_2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                       iterator_category; \
        typedef CGAL::Point_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                        difference_type;   \
        typedef CGAL::Point_2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Point_2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                              \
CGAL_STL_END_NAMESPACE                                                                 \
CGAL_STL_BEGIN_NAMESPACE                                                                \
    template <>                                                                      \
    struct iterator_traits<const CGAL::Vector_2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                        iterator_category; \
        typedef CGAL::Vector_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                         difference_type;   \
        typedef const CGAL::Vector_2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Vector_2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                               \
    template <>                                                                      \
    struct iterator_traits<CGAL::Vector_2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                        iterator_category; \
        typedef CGAL::Vector_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                         difference_type;   \
        typedef CGAL::Vector_2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Vector_2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                               \
CGAL_STL_END_NAMESPACE                                                                  \
CGAL_STL_BEGIN_NAMESPACE                                                                   \
    template <>                                                                         \
    struct iterator_traits<const CGAL::Direction_2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                           iterator_category; \
        typedef CGAL::Direction_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                            difference_type;   \
        typedef const CGAL::Direction_2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Direction_2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                  \
    template <>                                                                         \
    struct iterator_traits<CGAL::Direction_2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                           iterator_category; \
        typedef CGAL::Direction_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                            difference_type;   \
        typedef CGAL::Direction_2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Direction_2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                  \
CGAL_STL_END_NAMESPACE                                                                     \
CGAL_STL_BEGIN_NAMESPACE                                                              \
    template <>                                                                    \
    struct iterator_traits<const CGAL::Line_2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                      iterator_category; \
        typedef CGAL::Line_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                       difference_type;   \
        typedef const CGAL::Line_2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Line_2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                             \
    template <>                                                                    \
    struct iterator_traits<CGAL::Line_2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                      iterator_category; \
        typedef CGAL::Line_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                       difference_type;   \
        typedef CGAL::Line_2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Line_2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                             \
CGAL_STL_END_NAMESPACE                                                                \
CGAL_STL_BEGIN_NAMESPACE                                                                 \
    template <>                                                                       \
    struct iterator_traits<const CGAL::Segment_2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                         iterator_category; \
        typedef CGAL::Segment_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                          difference_type;   \
        typedef const CGAL::Segment_2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Segment_2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                \
    template <>                                                                       \
    struct iterator_traits<CGAL::Segment_2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                         iterator_category; \
        typedef CGAL::Segment_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                          difference_type;   \
        typedef CGAL::Segment_2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Segment_2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                \
CGAL_STL_END_NAMESPACE                                                                   \
CGAL_STL_BEGIN_NAMESPACE                                                             \
    template <>                                                                   \
    struct iterator_traits<const CGAL::Ray_2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                     iterator_category; \
        typedef CGAL::Ray_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                      difference_type;   \
        typedef const CGAL::Ray_2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Ray_2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                            \
    template <>                                                                   \
    struct iterator_traits<CGAL::Ray_2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                     iterator_category; \
        typedef CGAL::Ray_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                      difference_type;   \
        typedef CGAL::Ray_2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Ray_2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                            \
CGAL_STL_END_NAMESPACE                                                               \
CGAL_STL_BEGIN_NAMESPACE                                                                       \
    template <>                                                                             \
    struct iterator_traits<const CGAL::Iso_rectangle_2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                               iterator_category; \
        typedef CGAL::Iso_rectangle_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                                difference_type;   \
        typedef const CGAL::Iso_rectangle_2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Iso_rectangle_2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                      \
    template <>                                                                             \
    struct iterator_traits<CGAL::Iso_rectangle_2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                               iterator_category; \
        typedef CGAL::Iso_rectangle_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                                difference_type;   \
        typedef CGAL::Iso_rectangle_2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Iso_rectangle_2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                      \
CGAL_STL_END_NAMESPACE                                                                         \
CGAL_STL_BEGIN_NAMESPACE                                                                  \
    template <>                                                                        \
    struct iterator_traits<const CGAL::Triangle_2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                          iterator_category; \
        typedef CGAL::Triangle_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                           difference_type;   \
        typedef const CGAL::Triangle_2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Triangle_2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                 \
    template <>                                                                        \
    struct iterator_traits<CGAL::Triangle_2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                          iterator_category; \
        typedef CGAL::Triangle_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                           difference_type;   \
        typedef CGAL::Triangle_2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Triangle_2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                 \
CGAL_STL_END_NAMESPACE                                                                    \
CGAL_STL_BEGIN_NAMESPACE                                                                \
    template <>                                                                      \
    struct iterator_traits<const CGAL::Circle_2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                        iterator_category; \
        typedef CGAL::Circle_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                         difference_type;   \
        typedef const CGAL::Circle_2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Circle_2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                               \
    template <>                                                                      \
    struct iterator_traits<CGAL::Circle_2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                        iterator_category; \
        typedef CGAL::Circle_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                         difference_type;   \
        typedef CGAL::Circle_2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Circle_2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                               \
CGAL_STL_END_NAMESPACE                                                                  \
CGAL_STL_BEGIN_NAMESPACE                                                                            \
    template <>                                                                                  \
    struct iterator_traits<const CGAL::Aff_transformation_2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                                    iterator_category; \
        typedef CGAL::Aff_transformation_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                                     difference_type;   \
        typedef const CGAL::Aff_transformation_2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Aff_transformation_2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                           \
    template <>                                                                                  \
    struct iterator_traits<CGAL::Aff_transformation_2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                                    iterator_category; \
        typedef CGAL::Aff_transformation_2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                                     difference_type;   \
        typedef CGAL::Aff_transformation_2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Aff_transformation_2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                           \
CGAL_STL_END_NAMESPACE                                                                              \

#define CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H(NT)                                                \
CGAL_STL_BEGIN_NAMESPACE                                                               \
    template <>                                                                     \
    struct iterator_traits<const CGAL::Point_3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                       iterator_category; \
        typedef CGAL::Point_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                        difference_type;   \
        typedef const CGAL::Point_3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Point_3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                              \
    template <>                                                                     \
    struct iterator_traits<CGAL::Point_3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                       iterator_category; \
        typedef CGAL::Point_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                        difference_type;   \
        typedef CGAL::Point_3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Point_3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                              \
CGAL_STL_END_NAMESPACE                                                                 \
CGAL_STL_BEGIN_NAMESPACE                                                                \
    template <>                                                                      \
    struct iterator_traits<const CGAL::Vector_3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                        iterator_category; \
        typedef CGAL::Vector_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                         difference_type;   \
        typedef const CGAL::Vector_3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Vector_3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                               \
    template <>                                                                      \
    struct iterator_traits<CGAL::Vector_3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                        iterator_category; \
        typedef CGAL::Vector_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                         difference_type;   \
        typedef CGAL::Vector_3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Vector_3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                               \
CGAL_STL_END_NAMESPACE                                                                  \
CGAL_STL_BEGIN_NAMESPACE                                                                   \
    template <>                                                                         \
    struct iterator_traits<const CGAL::Direction_3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                           iterator_category; \
        typedef CGAL::Direction_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                            difference_type;   \
        typedef const CGAL::Direction_3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Direction_3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                  \
    template <>                                                                         \
    struct iterator_traits<CGAL::Direction_3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                           iterator_category; \
        typedef CGAL::Direction_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                            difference_type;   \
        typedef CGAL::Direction_3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Direction_3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                  \
CGAL_STL_END_NAMESPACE                                                                     \
CGAL_STL_BEGIN_NAMESPACE                                                               \
    template <>                                                                     \
    struct iterator_traits<const CGAL::Plane_3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                       iterator_category; \
        typedef CGAL::Plane_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                        difference_type;   \
        typedef const CGAL::Plane_3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Plane_3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                              \
    template <>                                                                     \
    struct iterator_traits<CGAL::Plane_3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                       iterator_category; \
        typedef CGAL::Plane_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                        difference_type;   \
        typedef CGAL::Plane_3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Plane_3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                              \
CGAL_STL_END_NAMESPACE                                                                 \
CGAL_STL_BEGIN_NAMESPACE                                                              \
    template <>                                                                    \
    struct iterator_traits<const CGAL::Line_3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                      iterator_category; \
        typedef CGAL::Line_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                       difference_type;   \
        typedef const CGAL::Line_3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Line_3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                             \
    template <>                                                                    \
    struct iterator_traits<CGAL::Line_3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                      iterator_category; \
        typedef CGAL::Line_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                       difference_type;   \
        typedef CGAL::Line_3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Line_3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                             \
CGAL_STL_END_NAMESPACE                                                                \
CGAL_STL_BEGIN_NAMESPACE                                                                 \
    template <>                                                                       \
    struct iterator_traits<const CGAL::Segment_3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                         iterator_category; \
        typedef CGAL::Segment_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                          difference_type;   \
        typedef const CGAL::Segment_3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Segment_3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                \
    template <>                                                                       \
    struct iterator_traits<CGAL::Segment_3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                         iterator_category; \
        typedef CGAL::Segment_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                          difference_type;   \
        typedef CGAL::Segment_3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Segment_3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                \
CGAL_STL_END_NAMESPACE                                                                   \
CGAL_STL_BEGIN_NAMESPACE                                                             \
    template <>                                                                   \
    struct iterator_traits<const CGAL::Ray_3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                     iterator_category; \
        typedef CGAL::Ray_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                      difference_type;   \
        typedef const CGAL::Ray_3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Ray_3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                            \
    template <>                                                                   \
    struct iterator_traits<CGAL::Ray_3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                     iterator_category; \
        typedef CGAL::Ray_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                      difference_type;   \
        typedef CGAL::Ray_3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Ray_3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                            \
CGAL_STL_END_NAMESPACE                                                               \
CGAL_STL_BEGIN_NAMESPACE                                                                  \
    template <>                                                                        \
    struct iterator_traits<const CGAL::Triangle_3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                          iterator_category; \
        typedef CGAL::Triangle_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                           difference_type;   \
        typedef const CGAL::Triangle_3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Triangle_3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                 \
    template <>                                                                        \
    struct iterator_traits<CGAL::Triangle_3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                          iterator_category; \
        typedef CGAL::Triangle_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                           difference_type;   \
        typedef CGAL::Triangle_3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Triangle_3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                 \
CGAL_STL_END_NAMESPACE                                                                    \
CGAL_STL_BEGIN_NAMESPACE                                                                     \
    template <>                                                                           \
    struct iterator_traits<const CGAL::Tetrahedron_3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                             iterator_category; \
        typedef CGAL::Tetrahedron_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                              difference_type;   \
        typedef const CGAL::Tetrahedron_3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Tetrahedron_3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                    \
    template <>                                                                           \
    struct iterator_traits<CGAL::Tetrahedron_3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                             iterator_category; \
        typedef CGAL::Tetrahedron_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                              difference_type;   \
        typedef CGAL::Tetrahedron_3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Tetrahedron_3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                    \
CGAL_STL_END_NAMESPACE                                                                       \
CGAL_STL_BEGIN_NAMESPACE                                                                            \
    template <>                                                                                  \
    struct iterator_traits<const CGAL::Aff_transformation_3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                                    iterator_category; \
        typedef CGAL::Aff_transformation_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                                     difference_type;   \
        typedef const CGAL::Aff_transformation_3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Aff_transformation_3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                           \
    template <>                                                                                  \
    struct iterator_traits<CGAL::Aff_transformation_3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                                    iterator_category; \
        typedef CGAL::Aff_transformation_3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                                     difference_type;   \
        typedef CGAL::Aff_transformation_3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Aff_transformation_3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                           \
CGAL_STL_END_NAMESPACE                                                                              \

#define CGAL_ITERATOR_TRAITS_POINTER_SPECH2(NT)                                                       \
CGAL_STL_BEGIN_NAMESPACE                                                                \
    template <>                                                                      \
    struct iterator_traits<const CGAL::PointH2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                        iterator_category; \
        typedef CGAL::PointH2< CGAL::Homogeneous< NT > >        value_type;        \
        typedef ptrdiff_t                                         difference_type;   \
        typedef const CGAL::PointH2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::PointH2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                               \
    template <>                                                                      \
    struct iterator_traits<CGAL::PointH2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                        iterator_category; \
        typedef CGAL::PointH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                         difference_type;   \
        typedef CGAL::PointH2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::PointH2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                               \
CGAL_STL_END_NAMESPACE                                                                  \
CGAL_STL_BEGIN_NAMESPACE                                                                 \
    template <>                                                                       \
    struct iterator_traits<const CGAL::VectorH2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                         iterator_category; \
        typedef CGAL::VectorH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                          difference_type;   \
        typedef const CGAL::VectorH2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::VectorH2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                \
    template <>                                                                       \
    struct iterator_traits<CGAL::VectorH2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                         iterator_category; \
        typedef CGAL::VectorH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                          difference_type;   \
        typedef CGAL::VectorH2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::VectorH2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                \
CGAL_STL_END_NAMESPACE                                                                   \
CGAL_STL_BEGIN_NAMESPACE                                                                    \
    template <>                                                                          \
    struct iterator_traits<const CGAL::DirectionH2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                            iterator_category; \
        typedef CGAL::DirectionH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                             difference_type;   \
        typedef const CGAL::DirectionH2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::DirectionH2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                   \
    template <>                                                                          \
    struct iterator_traits<CGAL::DirectionH2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                            iterator_category; \
        typedef CGAL::DirectionH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                             difference_type;   \
        typedef CGAL::DirectionH2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::DirectionH2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                   \
CGAL_STL_END_NAMESPACE                                                                      \
CGAL_STL_BEGIN_NAMESPACE                                                               \
    template <>                                                                     \
    struct iterator_traits<const CGAL::LineH2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                       iterator_category; \
        typedef CGAL::LineH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                        difference_type;   \
        typedef const CGAL::LineH2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::LineH2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                              \
    template <>                                                                     \
    struct iterator_traits<CGAL::LineH2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                       iterator_category; \
        typedef CGAL::LineH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                        difference_type;   \
        typedef CGAL::LineH2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::LineH2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                              \
CGAL_STL_END_NAMESPACE                                                                 \
CGAL_STL_BEGIN_NAMESPACE                                                                  \
    template <>                                                                        \
    struct iterator_traits<const CGAL::SegmentH2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                          iterator_category; \
        typedef CGAL::SegmentH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                           difference_type;   \
        typedef const CGAL::SegmentH2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::SegmentH2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                 \
    template <>                                                                        \
    struct iterator_traits<CGAL::SegmentH2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                          iterator_category; \
        typedef CGAL::SegmentH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                           difference_type;   \
        typedef CGAL::SegmentH2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::SegmentH2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                 \
CGAL_STL_END_NAMESPACE                                                                    \
CGAL_STL_BEGIN_NAMESPACE                                                              \
    template <>                                                                    \
    struct iterator_traits<const CGAL::RayH2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                      iterator_category; \
        typedef CGAL::RayH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                       difference_type;   \
        typedef const CGAL::RayH2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::RayH2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                             \
    template <>                                                                    \
    struct iterator_traits<CGAL::RayH2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                      iterator_category; \
        typedef CGAL::RayH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                       difference_type;   \
        typedef CGAL::RayH2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::RayH2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                             \
CGAL_STL_END_NAMESPACE                                                                \
CGAL_STL_BEGIN_NAMESPACE                                                                        \
    template <>                                                                              \
    struct iterator_traits<const CGAL::Iso_rectangleH2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                                iterator_category; \
        typedef CGAL::Iso_rectangleH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                                 difference_type;   \
        typedef const CGAL::Iso_rectangleH2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Iso_rectangleH2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                       \
    template <>                                                                              \
    struct iterator_traits<CGAL::Iso_rectangleH2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                                iterator_category; \
        typedef CGAL::Iso_rectangleH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                                 difference_type;   \
        typedef CGAL::Iso_rectangleH2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Iso_rectangleH2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                       \
CGAL_STL_END_NAMESPACE                                                                          \
CGAL_STL_BEGIN_NAMESPACE                                                                   \
    template <>                                                                         \
    struct iterator_traits<const CGAL::TriangleH2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                           iterator_category; \
        typedef CGAL::TriangleH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                            difference_type;   \
        typedef const CGAL::TriangleH2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::TriangleH2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                  \
    template <>                                                                         \
    struct iterator_traits<CGAL::TriangleH2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                           iterator_category; \
        typedef CGAL::TriangleH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                            difference_type;   \
        typedef CGAL::TriangleH2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::TriangleH2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                  \
CGAL_STL_END_NAMESPACE                                                                     \
CGAL_STL_BEGIN_NAMESPACE                                                                 \
    template <>                                                                       \
    struct iterator_traits<const CGAL::CircleH2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                         iterator_category; \
        typedef CGAL::CircleH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                          difference_type;   \
        typedef const CGAL::CircleH2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::CircleH2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                \
    template <>                                                                       \
    struct iterator_traits<CGAL::CircleH2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                         iterator_category; \
        typedef CGAL::CircleH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                          difference_type;   \
        typedef CGAL::CircleH2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::CircleH2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                \
CGAL_STL_END_NAMESPACE                                                                   \
CGAL_STL_BEGIN_NAMESPACE                                                                             \
    template <>                                                                                   \
    struct iterator_traits<const CGAL::Aff_transformationH2< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                                     iterator_category; \
        typedef CGAL::Aff_transformationH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                                      difference_type;   \
        typedef const CGAL::Aff_transformationH2< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Aff_transformationH2< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                            \
    template <>                                                                                   \
    struct iterator_traits<CGAL::Aff_transformationH2< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                                     iterator_category; \
        typedef CGAL::Aff_transformationH2< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                                      difference_type;   \
        typedef CGAL::Aff_transformationH2< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Aff_transformationH2< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                            \
CGAL_STL_END_NAMESPACE                                                                               \

#define CGAL_ITERATOR_TRAITS_POINTER_SPECH3(NT)                                                       \
CGAL_STL_BEGIN_NAMESPACE                                                                \
    template <>                                                                      \
    struct iterator_traits<const CGAL::PointH3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                        iterator_category; \
        typedef CGAL::PointH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                         difference_type;   \
        typedef const CGAL::PointH3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::PointH3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                               \
    template <>                                                                      \
    struct iterator_traits<CGAL::PointH3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                        iterator_category; \
        typedef CGAL::PointH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                         difference_type;   \
        typedef CGAL::PointH3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::PointH3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                               \
CGAL_STL_END_NAMESPACE                                                                  \
CGAL_STL_BEGIN_NAMESPACE                                                                 \
    template <>                                                                       \
    struct iterator_traits<const CGAL::VectorH3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                         iterator_category; \
        typedef CGAL::VectorH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                          difference_type;   \
        typedef const CGAL::VectorH3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::VectorH3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                \
    template <>                                                                       \
    struct iterator_traits<CGAL::VectorH3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                         iterator_category; \
        typedef CGAL::VectorH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                          difference_type;   \
        typedef CGAL::VectorH3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::VectorH3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                \
CGAL_STL_END_NAMESPACE                                                                   \
CGAL_STL_BEGIN_NAMESPACE                                                                    \
    template <>                                                                          \
    struct iterator_traits<const CGAL::DirectionH3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                            iterator_category; \
        typedef CGAL::DirectionH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                             difference_type;   \
        typedef const CGAL::DirectionH3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::DirectionH3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                   \
    template <>                                                                          \
    struct iterator_traits<CGAL::DirectionH3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                            iterator_category; \
        typedef CGAL::DirectionH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                             difference_type;   \
        typedef CGAL::DirectionH3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::DirectionH3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                   \
CGAL_STL_END_NAMESPACE                                                                      \
CGAL_STL_BEGIN_NAMESPACE                                                                \
    template <>                                                                      \
    struct iterator_traits<const CGAL::PlaneH3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                        iterator_category; \
        typedef CGAL::PlaneH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                         difference_type;   \
        typedef const CGAL::PlaneH3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::PlaneH3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                               \
    template <>                                                                      \
    struct iterator_traits<CGAL::PlaneH3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                        iterator_category; \
        typedef CGAL::PlaneH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                         difference_type;   \
        typedef CGAL::PlaneH3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::PlaneH3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                               \
CGAL_STL_END_NAMESPACE                                                                  \
CGAL_STL_BEGIN_NAMESPACE                                                               \
    template <>                                                                     \
    struct iterator_traits<const CGAL::LineH3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                       iterator_category; \
        typedef CGAL::LineH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                        difference_type;   \
        typedef const CGAL::LineH3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::LineH3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                              \
    template <>                                                                     \
    struct iterator_traits<CGAL::LineH3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                       iterator_category; \
        typedef CGAL::LineH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                        difference_type;   \
        typedef CGAL::LineH3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::LineH3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                              \
CGAL_STL_END_NAMESPACE                                                                 \
CGAL_STL_BEGIN_NAMESPACE                                                                  \
    template <>                                                                        \
    struct iterator_traits<const CGAL::SegmentH3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                          iterator_category; \
        typedef CGAL::SegmentH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                           difference_type;   \
        typedef const CGAL::SegmentH3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::SegmentH3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                 \
    template <>                                                                        \
    struct iterator_traits<CGAL::SegmentH3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                          iterator_category; \
        typedef CGAL::SegmentH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                           difference_type;   \
        typedef CGAL::SegmentH3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::SegmentH3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                 \
CGAL_STL_END_NAMESPACE                                                                    \
CGAL_STL_BEGIN_NAMESPACE                                                              \
    template <>                                                                    \
    struct iterator_traits<const CGAL::RayH3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                      iterator_category; \
        typedef CGAL::RayH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                       difference_type;   \
        typedef const CGAL::RayH3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::RayH3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                             \
    template <>                                                                    \
    struct iterator_traits<CGAL::RayH3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                      iterator_category; \
        typedef CGAL::RayH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                       difference_type;   \
        typedef CGAL::RayH3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::RayH3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                             \
CGAL_STL_END_NAMESPACE                                                                \
CGAL_STL_BEGIN_NAMESPACE                                                                   \
    template <>                                                                         \
    struct iterator_traits<const CGAL::TriangleH3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                           iterator_category; \
        typedef CGAL::TriangleH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                            difference_type;   \
        typedef const CGAL::TriangleH3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::TriangleH3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                  \
    template <>                                                                         \
    struct iterator_traits<CGAL::TriangleH3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                           iterator_category; \
        typedef CGAL::TriangleH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                            difference_type;   \
        typedef CGAL::TriangleH3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::TriangleH3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                  \
CGAL_STL_END_NAMESPACE                                                                     \
CGAL_STL_BEGIN_NAMESPACE                                                                      \
    template <>                                                                            \
    struct iterator_traits<const CGAL::TetrahedronH3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                              iterator_category; \
        typedef CGAL::TetrahedronH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                               difference_type;   \
        typedef const CGAL::TetrahedronH3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::TetrahedronH3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                     \
    template <>                                                                            \
    struct iterator_traits<CGAL::TetrahedronH3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                              iterator_category; \
        typedef CGAL::TetrahedronH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                               difference_type;   \
        typedef CGAL::TetrahedronH3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::TetrahedronH3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                     \
CGAL_STL_END_NAMESPACE                                                                        \
CGAL_STL_BEGIN_NAMESPACE                                                                             \
    template <>                                                                                   \
    struct iterator_traits<const CGAL::Aff_transformationH3< CGAL::Homogeneous< NT > >*> {       \
        typedef random_access_iterator_tag                                     iterator_category; \
        typedef CGAL::Aff_transformationH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                                      difference_type;   \
        typedef const CGAL::Aff_transformationH3< CGAL::Homogeneous< NT > >*  pointer;           \
        typedef const CGAL::Aff_transformationH3< CGAL::Homogeneous< NT > >&  reference;         \
    };                                                                                            \
    template <>                                                                                   \
    struct iterator_traits<CGAL::Aff_transformationH3< CGAL::Homogeneous< NT > >*> {             \
        typedef random_access_iterator_tag                                     iterator_category; \
        typedef CGAL::Aff_transformationH3< CGAL::Homogeneous< NT > >         value_type;        \
        typedef ptrdiff_t                                                      difference_type;   \
        typedef CGAL::Aff_transformationH3< CGAL::Homogeneous< NT > >*        pointer;           \
        typedef CGAL::Aff_transformationH3< CGAL::Homogeneous< NT > >&        reference;         \
    };                                                                                            \
CGAL_STL_END_NAMESPACE                                                                               \



CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( int )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( int )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( long )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( long )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( float )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( float )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( double )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( double )

CGAL_ITERATOR_TRAITS_POINTER_SPECH2( int )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( int )
CGAL_ITERATOR_TRAITS_POINTER_SPECH2( long )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( long )
CGAL_ITERATOR_TRAITS_POINTER_SPECH2( float )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( float )
CGAL_ITERATOR_TRAITS_POINTER_SPECH2( double )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( double )

#if defined(LEDA_NAMESPACE)
namespace leda {
class real;
class integer;
class rational;
class bigfloat;
}
#else
class leda_real;
class leda_integer;
class leda_rational;
class leda_bigfloat;
#endif

CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( leda_real )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( leda_real )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( leda_integer )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( leda_integer )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( leda_rational )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( leda_rational )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( leda_bigfloat )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( leda_bigfloat )

CGAL_ITERATOR_TRAITS_POINTER_SPECH2( leda_real )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( leda_real )
CGAL_ITERATOR_TRAITS_POINTER_SPECH2( leda_integer )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( leda_integer )
CGAL_ITERATOR_TRAITS_POINTER_SPECH2( leda_rational )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( leda_rational )
CGAL_ITERATOR_TRAITS_POINTER_SPECH2( leda_bigfloat )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( leda_bigfloat )


namespace CGAL { class Gmpz; }

CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( CGAL::Gmpz )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( CGAL::Gmpz )

CGAL_ITERATOR_TRAITS_POINTER_SPECH2( CGAL::Gmpz )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( CGAL::Gmpz )

// Quotient.h must be have been included
#ifndef CGAL_QUOTIENT_H
#error
#endif  // CGAL_QUOTIENT_H

CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( CGAL::Quotient<int> )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( CGAL::Quotient<int> )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( CGAL::Quotient<long> )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( CGAL::Quotient<long> )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( CGAL::Quotient<float> )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( CGAL::Quotient<float> )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( CGAL::Quotient<double> )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( CGAL::Quotient<double> )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( CGAL::Quotient<leda_real> )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( CGAL::Quotient<leda_real> )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( CGAL::Quotient<leda_integer> )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( CGAL::Quotient<leda_integer> )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_2H( CGAL::Quotient<CGAL::Gmpz> )
CGAL_ITERATOR_TRAITS_POINTER_SPEC_3H( CGAL::Quotient<CGAL::Gmpz> )

CGAL_ITERATOR_TRAITS_POINTER_SPECH2( CGAL::Quotient<int> )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( CGAL::Quotient<int> )
CGAL_ITERATOR_TRAITS_POINTER_SPECH2( CGAL::Quotient<long> )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( CGAL::Quotient<long> )
CGAL_ITERATOR_TRAITS_POINTER_SPECH2( CGAL::Quotient<float> )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( CGAL::Quotient<float> )
CGAL_ITERATOR_TRAITS_POINTER_SPECH2( CGAL::Quotient<double> )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( CGAL::Quotient<double> )
CGAL_ITERATOR_TRAITS_POINTER_SPECH2( CGAL::Quotient<leda_real> )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( CGAL::Quotient<leda_real> )
CGAL_ITERATOR_TRAITS_POINTER_SPECH2( CGAL::Quotient<leda_integer> )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( CGAL::Quotient<leda_integer> )
CGAL_ITERATOR_TRAITS_POINTER_SPECH2( CGAL::Quotient<CGAL::Gmpz> )
CGAL_ITERATOR_TRAITS_POINTER_SPECH3( CGAL::Quotient<CGAL::Gmpz> )

#endif // CGAL_LIMITED_ITERATOR_TRAITS_SUPPORT
#endif // CGAL_ITERATOR_TRAITS_POINTER_SPECS_FOR_HOMOGENEOUS_KERNEL_H