// ======================================================================
//
// Copyright (c) 1998,1999 The CGAL Consortium

// This software and related documentation is part of the Computational
// Geometry Algorithms Library (CGAL).
// This software and documentation is provided "as-is" and without warranty
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
//   markets LEDA (http://www.algorithmic-solutions.de). 
// - Commercial users may apply for an evaluation license by writing to
//   Algorithmic Solutions (contact@algorithmic-solutions.com). 
//
// The CGAL Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Free University of Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbrucken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).
//
// ----------------------------------------------------------------------
//
// release       : CGAL-2.1
// release_date  : 2000, January 11
//
// file          : include/CGAL/Interval_arithmetic/IA_leda_real.h
// package       : Interval_arithmetic (4.39)
// revision      : $Revision: 2.22 $
// revision_date : $Date: 1999/11/07 17:53:35 $
// author(s)     : Sylvain Pion
//
// coordinator   : INRIA Sophia-Antipolis (<Mariette.Yvinec>)
//
// email         : cgal@cs.uu.nl
//
// ======================================================================

#ifndef CGAL_IA_LEDA_REAL_H
#define CGAL_IA_LEDA_REAL_H

CGAL_BEGIN_NAMESPACE

inline
Interval_nt_advanced
convert_from_to (const Interval_nt_advanced&, const leda_real & z)
{
    CGAL_expensive_assertion(FPU_empiric_test() == CGAL_FE_UPWARD);
    FPU_set_cw(CGAL_FE_TONEAREST);
    double approx = CGAL::to_double(z);
    double rel_error = z.get_double_error();
    FPU_set_cw(CGAL_FE_UPWARD);
    Interval_nt_advanced result = approx
	* ( Interval_nt_advanced(-rel_error,rel_error) + 1 );
    CGAL_expensive_assertion_code(FPU_set_cw(CGAL_FE_TONEAREST);)
    CGAL_expensive_assertion( leda_real(result.inf()) <= z &&
		              leda_real(result.sup()) >= z );
    CGAL_expensive_assertion_code(FPU_set_cw(CGAL_FE_UPWARD);)
    return result;
}

#ifndef CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION
template <>
struct converter<Interval_nt_advanced,leda_real>
{
    static inline Interval_nt_advanced do_it (const leda_real & z)
    {
	return convert_from_to(Interval_nt_advanced(), z);
    }
};
#endif // CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION

CGAL_END_NAMESPACE

#endif	 // CGAL_IA_LEDA_REAL_H
