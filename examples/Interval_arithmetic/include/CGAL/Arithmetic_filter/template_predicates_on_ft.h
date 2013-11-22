// This is an extract from include/CGAL/predicates_on_ftC2.h
// It's a template predicate.

#ifndef CGAL_ARITHMETIC_FILTER_TEMPLATE_PREDICATES_ON_FT_H
#define CGAL_ARITHMETIC_FILTER_TEMPLATE_PREDICATES_ON_FT_H

// This file is automatically generated by the script for filtering
// predicates, using Interval arithmetic.

CGAL_BEGIN_NAMESPACE

#ifndef CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION
template < class CGAL_IA_CT, class CGAL_IA_ET, class CGAL_IA_CACHE >
#endif
// CGAL_KERNEL_LARGE_INLINE
Comparison_result
compare_xC2(
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &px,  
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &py,
            
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &l1a, 
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &l1b, 
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &l1c,
            
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &l2a, 
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &l2b, 
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &l2c)
{
  FPU_CW_t backup = FPU_get_cw();
  FPU_set_cw(FPU_cw_up);
  try
  {
    Comparison_result result = compare_xC2(
		px.interval(),
		py.interval(),
		l1a.interval(),
		l1b.interval(),
		l1c.interval(),
		l2a.interval(),
		l2b.interval(),
		l2c.interval());
    FPU_set_cw(backup);
    return result;
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    FPU_set_cw(backup);
    return compare_xC2(
		px.exact(),
		py.exact(),
		l1a.exact(),
		l1b.exact(),
		l1c.exact(),
		l2a.exact(),
		l2b.exact(),
		l2c.exact());
  }
}

CGAL_END_NAMESPACE

#ifdef CGAL_ARITHMETIC_FILTER_H
#include <CGAL/Arithmetic_filter/template_predicates_on_ft.h>
#endif

#endif // CGAL_ARITHMETIC_FILTER_TEMPLATE_PREDICATES_ON_FT_H