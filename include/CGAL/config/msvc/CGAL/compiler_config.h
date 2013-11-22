// ======================================================================
//
// Copyright (c) 2000 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------
//
// release       : 
// release_date  : 2000, January 12
//
// file          : ?/include/CGAL/config/msvc/CGAL/compiler_config.h
// package       : wininst (1.4.2)
// author(s)     : ?
// coordinator   : ?
//
// ======================================================================
// Package: wininst
//
// Compiler specific configuration file
// System: i686_CYGWINNT-4.0-20.1_CL.EXE-12.00.8168
// generated by install_cgal 1.72
// with install testsuite 1.11
// 
// Used for Windows-specific installation
//

//+--------------------------------------------------------------------------
// The compiler has to provide a Standard Template Library
//+--------------------------------------------------------------------------
// STL test ok

//+--------------------------------------------------------------------------
//| The flag CGAL_CFG_CCTYPE_MACRO_BUG is set, if a compiler defines the
//| standard C library functions in cctype (isdigit etc.) as macros.
//| According to the standard they have to be functions.
//+--------------------------------------------------------------------------
#define CGAL_CFG_CCTYPE_MACRO_BUG 1

//+--------------------------------------------------------------------------
//| When a dynamic cast involves a pointer to a not yet instantiated 
//| template class, some compilers give an error.
//| This program is used to detect this problem.
//| "CGAL_CFG_DYNAMIC_CAST_BUG.C", line 45: error(3105): the type in a
//|           dynamic_cast must be a pointer or reference to a complete class
//|           type, or void *
//|     W< L<int> >* wl_ptr = dynamic_cast<W< L<int> >* >( &wp );
//|                                        ^
//+--------------------------------------------------------------------------
//#define CGAL_CFG_DYNAMIC_CAST_BUG 1

//+--------------------------------------------------------------------------
//| This flag is set, if the compiler does not match a function
//| argument of type typename T::A correctly.
//| (e.g. SGI 7.2)
//+--------------------------------------------------------------------------
//#define CGAL_CFG_MATCHING_BUG_1 1

//+--------------------------------------------------------------------------
//| This flag is set, if the compiler does not match the most
//| specialized instance of a function template correctly,
//| but complains about multiple matches.
//| (e.g. SGI 7.2)
//+--------------------------------------------------------------------------
#define CGAL_CFG_MATCHING_BUG_2 1

//+--------------------------------------------------------------------------
//| When template implementation files are not included in the source files,
//| a compiler may attempt to find the unincluded template bodies
//| automatically. For example, suppose that the following conditions are
//| all true.
//|
//| - template entity ABC::f is declared in file xyz.h
//| - an instantiation of ABC::f is required in a compilation
//| - no definition of ABC::f appears in the source code processed by the
//|   compilation
//| 
//| In this case, the compiler may look to see if the source file xyz.n exists,
//| where n is .c, .C, .cpp, .CPP, .cxx, .CXX, or .cc. If this feature is
//| missing, the flag CGAL_CFG_NO_AUTOMATIC_TEMPLATE_INCLUSION is set.
//+--------------------------------------------------------------------------
#define CGAL_CFG_NO_AUTOMATIC_TEMPLATE_INCLUSION 1

//+--------------------------------------------------------------------------
//| The byte order of a machine architecture distinguishes into
//| big-endian and little-endian machines.
//| The following definition is set if it is a little-endian machine.
//+--------------------------------------------------------------------------
#define CGAL_CFG_NO_BIG_ENDIAN 1

//+--------------------------------------------------------------------------
//| This flag is set if the compiler doesn't support the operator dynamic_cast.
//+--------------------------------------------------------------------------
//#define CGAL_CFG_NO_DYNAMIC_CAST 1

//+--------------------------------------------------------------------------
//| If a compiler doesn't like explicit specification of 
//| template arguments in template function calls, the flag
//| CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION is set.
//+--------------------------------------------------------------------------
//#define CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION 1

//+--------------------------------------------------------------------------
//| Iterator traits are documented in the Dec. 1996 C++ Standard draft.
//| The following definition is set if iterator are not fully supported 
//| including their use in a template class, as a default template
//| argument and as a return type of global function.
//+--------------------------------------------------------------------------
//#define CGAL_CFG_NO_ITERATOR_TRAITS 1

//+--------------------------------------------------------------------------
//| This flag is set if the compiler doesn't support the operator Koenig
//| lookup. That is, it does not search in the namespace of the arguments for
//| the function.
//+--------------------------------------------------------------------------
#define CGAL_CFG_NO_KOENIG_LOOKUP 1

//+--------------------------------------------------------------------------
//| If a compiler doesn't know the locale classic
//| CGAL_CFG_NO_LOCALE is set. 
//+--------------------------------------------------------------------------
//#define CGAL_CFG_NO_LOCALE 1

//+--------------------------------------------------------------------------
//| If a compiler (or assembler or linker) has problems with long names
//| CGAL_CFG_NO_LONGNAME_PROBLEM is set.
//+--------------------------------------------------------------------------
//#define CGAL_CFG_NO_LONGNAME_PROBLEM 1

//+--------------------------------------------------------------------------
//| If a compiler doesn't know namespaces, the flag
//| CGAL_CFG_NO_NAMESPACE is set.
//+--------------------------------------------------------------------------
//#define CGAL_CFG_NO_NAMESPACE 1

//+--------------------------------------------------------------------------
//| If a compiler doesn't support partial specialisation of class templates,
//| the flag CGAL_CFG_NO_PARTIAL_CLASS_TEMPLATE_SPECIALISATION is set.
//+--------------------------------------------------------------------------
#define CGAL_CFG_NO_PARTIAL_CLASS_TEMPLATE_SPECIALISATION 1

//+--------------------------------------------------------------------------
//| If a compiler doesn't like explicit partial specification of 
//| template arguments in template function calls, the flag
//| CGAL_CFG_NO_PARTIAL_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION is set.
//+--------------------------------------------------------------------------
//#define CGAL_CFG_NO_PARTIAL_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION 1

//+--------------------------------------------------------------------------
//| The parameter types of member functions might contain a scope
//| operator. This works as long as the member function is implemented
//| inline in the class. If the member function is implemented external
//| not all compilers are able to parse the scope operators correctly.
//| The following definition is set if the compiler fails parsing.
//+--------------------------------------------------------------------------
#define CGAL_CFG_NO_SCOPE_MEMBER_FUNCTION_PARAMETERS 1

//+--------------------------------------------------------------------------
//| The flag CGAL_CFG_NO_STANDARD_HEADERS is set, if a compiler does not 
//| support the new standard headers (i.e. without the .h suffix).
//+--------------------------------------------------------------------------
//#define CGAL_CFG_NO_STANDARD_HEADERS 1

//+--------------------------------------------------------------------------
//| The flag CGAL_CFG_NO_STDC_NAMESPACE is set, if a compiler does not
//| put the parts of the standard library inherited from the standard
//| C library in namespace std. (only tests for the symbols used in CGAL)
//+--------------------------------------------------------------------------
#define CGAL_CFG_NO_STDC_NAMESPACE 1

//+--------------------------------------------------------------------------
//| The flag CGAL_CFG_NO_STDIO_NAMESPACE is set, if a compiler does not
//| put the IO standard library in namespace std.
//+--------------------------------------------------------------------------
//#define CGAL_CFG_NO_STDIO_NAMESPACE 1

//+--------------------------------------------------------------------------
//| If a compiler doesn't know the namespace std, the flag
//| CGAL_CFG_NO_STD_NAMESPACE is set. Some compilers know namespace std
//| but don't implement namespaces in general.
//+--------------------------------------------------------------------------
//#define CGAL_CFG_NO_STD_NAMESPACE 1

//+--------------------------------------------------------------------------
//| Checks whether the compiler wants to have a <> in friend declarations
//| of template functions.
//+--------------------------------------------------------------------------
#define CGAL_CFG_NO_TEMPLATE_FRIEND_DISTINCTION 1

//+--------------------------------------------------------------------------
//| Nested templates in template parameter, such as 'template <
//| template <class T> class A>' are not supported by any compiler. 
//| The following definition is set if they are not supported.
//+--------------------------------------------------------------------------
#define CGAL_CFG_NO_TMPL_IN_TMPL_PARAM 1

//+--------------------------------------------------------------------------
//| If a compiler complains about typename, when passing a dependent
//| type as template parameter, the flag CGAL_CFG_TYPENAME_BUG is set.
//+--------------------------------------------------------------------------
#define CGAL_CFG_TYPENAME_BUG 1

//+--------------------------------------------------------------------------
//| If a compiler does not accept a using declaration referring to a 
//| symbol that is again declared by a using declaration, the flag
//| CGAL_CFG_USING_USING_BUG is set.
//+--------------------------------------------------------------------------
#define CGAL_CFG_USING_USING_BUG 1

