// ======================================================================
//
// Copyright (c) 1997 The CGAL Consortium

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
//
// release       : CGAL-2.4
// release_date  : 2002, May 16
//
// file          : include/CGAL/Pm_segment_traits_2.h
// package       : Planar_map (5.113)
// source        : 
// revision      : 
// revision_date : 
// author(s)     : Iddo Hanniel
//                 Eyal Flato
//                 Oren Nechushtan
//                 Shai Hirsch
//                 Efi Fogel
//
// coordinator   : Tel-Aviv University (Dan Halperin)
//
// Chapter       : 
// email         : contact@cgal.org
// www           : http://www.cgal.org
//
// ======================================================================
#ifndef CGAL_PM_SEGMENT_TRAITS_2_H
#define CGAL_PM_SEGMENT_TRAITS_2_H

#ifndef CGAL_POINT_2_H
#include <CGAL/Point_2.h>
#endif
#ifndef CGAL_SEGMENT_2_H
#include <CGAL/Segment_2.h>
#endif

CGAL_BEGIN_NAMESPACE

template <class R>
class Pm_segment_traits_2
{
public:

  typedef typename R::Segment_2 X_curve_2;
  typedef typename R::Point_2   Point_2;
  typedef typename R::Vector_2  Vector_2;

  // Obsolete, for backward compatibility
  typedef X_curve_2             X_curve;
  typedef Point_2               Point;
  typedef Vector_2              Vector;
  
  typedef enum
  {
    UNDER_CURVE = -1,
    ABOVE_CURVE = 1,
    ON_CURVE = 2,
    CURVE_NOT_IN_RANGE = 0
  } Curve_point_status;	

protected:

  // This is an implementation type
  typedef enum 
  {
    CURVE_VERTICAL_UP = 0,
    CURVE_VERTICAL_DOWN = 2,
    CURVE_LEFT = 3,
    CURVE_RIGHT = 1
  } Curve_status;

public:
  Pm_segment_traits_2() {}
  
  Point_2 curve_source(const X_curve_2 & cv) const 
  { 
    return cv.source(); 
  }
  
  Point_2 curve_target(const X_curve_2 & cv) const 
  {
    return cv.target(); 
  }
  
  bool curve_is_vertical(const X_curve_2 & cv) const 
  {
    return is_same_x(cv.source(), cv.target()); 
  }
  
  bool curve_is_in_x_range(const X_curve_2 & cv, const Point_2 & q) const
  { 
    return !( is_right(q, rightmost(cv.source(), cv.target())) ||
              is_left(q, leftmost(cv.source(), cv.target()))	 );
  }
  
  bool curve_is_in_y_range(const X_curve_2 &cv, const Point_2 & q) const
  { 
    bool r = !( is_lower(q, lowest(cv.source(), cv.target())) ||
                is_higher(q, highest(cv.source(), cv.target())) );
    return r;
  }

  
  Curve_point_status 
  curve_get_point_status(const X_curve_2 &cv, const Point_2 & p) const
  {
    if (!curve_is_in_x_range(cv, p))
      return CURVE_NOT_IN_RANGE;
	if (!curve_is_vertical(cv))
	{
		int res = compare_y(p, curve_calc_point(cv, p));
		if (res == SMALLER) return UNDER_CURVE;
		if (res == LARGER)	return ABOVE_CURVE;
		//if (res == EQUAL) 
		return ON_CURVE;
	}
	else
	{
		if (is_lower(p,lowest(curve_source(cv),curve_target(cv))))
			return UNDER_CURVE;
		if (is_higher(p,highest(curve_source(cv),curve_target(cv))))
			return ABOVE_CURVE;
		// if (curve_is_in_y_range(cv,p))
		return ON_CURVE;
	}
  }
  
  Comparison_result 
  curve_compare_at_x(const X_curve_2 & cv1, 
                     const X_curve_2 & cv2, 
                     const Point_2   & q)    const 
  {
    //CGAL_assertion (curve_is_in_x_range(cv1, q));
    //CGAL_assertion (curve_is_in_x_range(cv2, q));
    if ((!curve_is_in_x_range(cv1, q)) || (!curve_is_in_x_range(cv2, q)))
      return EQUAL;
    
    X_curve_2 cv1_ = cv1;
    X_curve_2 cv2_ = cv2;
    if (compare_lexicographically_xy(cv1.source(), cv1.target()) == LARGER)
      cv1_ = curve_flip(cv1);
    if (compare_lexicographically_xy(cv2.source(), cv2.target()) == LARGER)
      cv2_ = curve_flip(cv2);
    
    Point_2 p1 = curve_calc_point(cv1_, q);
    Point_2 p2 = curve_calc_point(cv2_, q);
    
    if (curve_is_vertical(cv1_))
      {
        if (curve_is_vertical(cv2_))
          {
            // both cv1 and cv2 are vertical
            if ( is_lower(cv1_.target(), cv2_.source()) )
              return SMALLER;
            if ( is_higher(cv1_.source(), cv2_.target()) )
              return LARGER;
            return SMALLER;
          }
        // cv1 is vertical and cv2 not
        if ( is_lower(cv1_.target(), p2) )
          return SMALLER;
        if ( is_higher(cv1_.source(), p2) )
          return LARGER;
        return EQUAL;
      }
    
    if (curve_is_vertical(cv2_))
      {
        // cv2 is vertical and cv1- not
         /*        bug fix (Oren)
        if (is_lower(cv2.target(), p1) )
          return LARGER;
        if ( is_higher(cv2.source(), p1) )
          return SMALLER;
 
        if ( is_higher(cv2.source(), p1) ) // bug fix (Oren)
        The answer should be independent of the curve's orientation !!

     p1 x--x               p1 x--x
        |                     /\
        |           versus    |
        \/cv2                 |cv2
        x                     x

        p                     p

        */
        if (is_lower(cv2_.target(), p1) )
          return LARGER;
        if (is_higher(cv2_.source(), p1) )
          return SMALLER;
        return EQUAL;
      }
    
    // both are not vertical
    if (is_higher(p1, p2)) return LARGER;
    if (is_lower(p1, p2)) return SMALLER;
    return EQUAL;
  }
  
  
  Comparison_result 
  curve_compare_at_x_left(const X_curve_2 &cv1, const X_curve_2 &cv2, 
                          const Point_2 &q) const 
  {
    // cases  in which the function isn't defined
    //CGAL_assertion(!curve_is_vertical(cv1));
    //CGAL_assertion(!curve_is_vertical(cv2));
    //CGAL_assertion(is_left(leftmost(cv1.source(), cv1.target()), q));
    //CGAL_assertion(is_left(leftmost(cv2.source(), cv2.target()), q));
    
    if (curve_is_vertical(cv1) || (curve_is_vertical(cv2))) return EQUAL;
    if (!is_left(leftmost(cv1.source(), cv1.target()), q)) return EQUAL;
    if (!is_left(leftmost(cv2.source(), cv2.target()), q)) return EQUAL;
    
    Comparison_result r = curve_compare_at_x(cv1, cv2, q);
        
    if ( r != EQUAL)
      return r;     // since the curve is continous 
    
    // <cv2> and <cv1> meet at a point with the same x-coordinate as q
    // compare their derivatives
    return compare_value(curve_derivative(cv2), curve_derivative(cv1));
    }
  
  Comparison_result 
  curve_compare_at_x_right(const X_curve_2 &cv1, const X_curve_2 &cv2, 
			   const Point_2 & q) const 
  {
    // cases  in which the function isn't defined
    //CGAL_assertion(!curve_is_vertical(cv1));
    //CGAL_assertion(!curve_is_vertical(cv2));
    //CGAL_assertion(is_right(rightmost(cv1.source(), cv1.target()), q));
    //CGAL_assertion(is_right(rightmost(cv2.source(), cv2.target()), q));
    
    if (curve_is_vertical(cv1) || (curve_is_vertical(cv2))) return EQUAL;
    if (!is_right(rightmost(cv1.source(), cv1.target()), q)) return EQUAL;
    if (!is_right(rightmost(cv2.source(), cv2.target()), q)) return EQUAL;
    
    Comparison_result r = curve_compare_at_x(cv1, cv2, q);
    
    if ( r != EQUAL)
      return r;     // since the curve is continous (?)
    
    // <cv1> and <cv2> meet at a point with the same x-coordinate as q
    // compare their derivatives
    return compare_value(curve_derivative(cv1), curve_derivative(cv2));
  }

  
  X_curve_2 curve_flip(const X_curve_2 &cv) const
  {
    return X_curve_2(cv.target(), cv.source());
  }
  
  bool curve_is_between_cw(const X_curve_2 &cv, 
                           const X_curve_2 &first, 
                           const X_curve_2 &second, 
                           const Point_2 &point)	const
    // TRUE if cv is between first and second in cw direction
    // precondition: this, first and second have a common endpoint
    // precondition: first, second, this are pairwise interior disjoint
  {
    // CGAL_assertion(is_intersection_simple(first, second);
    // CGAL_assertion(is_intersection_simple(first, *this);
    // CGAL_assertion(is_intersection_simple(*this, second);
    
    Curve_status cv0_status, cv1_status, cvx_status;
    int cv0_cv1, cv0_cvx, cv1_cvx;
    cv0_cv1 = cv0_cvx = cv1_cvx = -1;

    Point_2 cp = point;
    
    X_curve_2 cv0 = first;
    X_curve_2 cv1 = second;
    X_curve_2 cvx = cv;
    
    if ( !is_same(cv0.source(),cp) ) cv0 = curve_flip(cv0);
    if ( !is_same(cv1.source(),cp) ) cv1 = curve_flip(cv1);
    if ( !is_same(cvx.source(),cp) ) cvx = curve_flip(cvx);

    cv0_status = curve_get_status(cv0);
    cv1_status = curve_get_status(cv1);
    cvx_status = curve_get_status(cvx);
		
    //	the circle:				    0
    //						 ** | **
    //						*	*
    //					     3 *	 * 1
    //						*	*
    //						 ** | **
    //						    2
    
    if (cv0_status == cv1_status)
      {
        if (cv0_status == CURVE_RIGHT)
          cv0_cv1 = curve_compare_at_x_right(cv0, cv1, cp);
        if (cv0_status == CURVE_LEFT)
          cv0_cv1 = curve_compare_at_x_left(cv0, cv1, cp);
      }
    if (cv0_status == cvx_status)
      {
        if (cv0_status == CURVE_RIGHT)
          cv0_cvx = curve_compare_at_x_right(cv0, cvx, cp);
        if (cv0_status == CURVE_LEFT)
          cv0_cvx = curve_compare_at_x_left(cv0, cvx, cp);
      }
    if (cv1_status == cvx_status)
      {
        if (cv1_status == CURVE_RIGHT)
          cv1_cvx = curve_compare_at_x_right(cv1, cvx, cp);
        if (cv1_status == CURVE_LEFT)
          cv1_cvx = curve_compare_at_x_left(cv1, cvx, cp);
      }
    
    if (cv0_status == cv1_status)
      {
        if (cv0_status == CURVE_LEFT)
          {
            if ( ((cv0_cv1==1) && (cvx_status==cv0_status) && 
                  ((cv0_cvx==-1) || (cv1_cvx==1))) ||
                 ((cv0_cv1==1) && (cvx_status!=cv0_status)) ||
                 ((cv0_cv1==-1) && (cvx_status==cv0_status) && 
                  ((cv0_cvx==-1) && (cv1_cvx==1))) )
              return true;
          }
        if (cv0_status == CURVE_RIGHT)
          {
            if ( ((cv0_cv1==1) && (cvx_status==cv0_status) && 
                  ((cv0_cvx==1) && (cv1_cvx==-1))) ||
                 ((cv0_cv1==-1) && (cvx_status!=cv0_status)) ||
                 ((cv0_cv1==-1) && (cvx_status==cv0_status) && 
                  ((cv0_cvx==1) || (cv1_cvx==-1))) )
              return true;
          }
        return false;
      }
    // else do the following
    
    if (cv0_status == cvx_status)
      {
        if ( ((cv0_status == CURVE_LEFT) && (cv0_cvx==-1)) ||
             ((cv0_status == CURVE_RIGHT) && (cv0_cvx==1)) )
          return true;

        //Addition by iddo for enabeling addition of null segments - testing
        if ( (cv0_status==CURVE_VERTICAL_DOWN)&&
             ((cv0.source()==cv0.target())||(cvx.source()==cvx.target())) )
          return true; //a null segment (=point) 

        return false;
      }
    
    if (cv1_status == cvx_status)
      {
        if ( ((cv1_status == CURVE_LEFT) && (cv1_cvx==1)) ||
             ((cv1_status == CURVE_RIGHT) && (cv1_cvx==-1)) )
          return true;

        //Addition by iddo for enabeling addition of null segments - testing
        if ( (cv1_status==CURVE_VERTICAL_DOWN)&&
             ((cv1.source()==cv1.target())||(cvx.source()==cvx.target())) )
          return true; //a null segment (=point)  

        return false;
      }
    
    // cv1 and cv0 are on diffrent part of the circle - it is easy
    if ( ((cv1_status - cv0_status + 4)%4) < 
         ((cvx_status - cv0_status + 4)%4) )
      return false;
    else
      // if there is an equality or inequality to the other side
      // everything is ok
      return true;
  }
  
  Comparison_result compare_x(const Point_2 &p1, const Point_2 &p2) const
  { return compare_value(p1.x(), p2.x()); }
  Comparison_result compare_y(const Point_2 &p1, const Point_2 &p2) const
  { return compare_value(p1.y(), p2.y()); }
public:
  Point_2 point_to_left(const Point_2& p) const {
    return p+Vector_2(-1,0);}
  Point_2 point_to_right(const Point_2& p) const {return p+Vector_2(1,0);}
  bool curve_is_same(const X_curve_2 &cv1, const X_curve_2 &cv2) const
  {
	return is_same(curve_source(cv1),curve_source(cv2))&&
		is_same(curve_target(cv1),curve_target(cv2));
  }
  bool is_point_on_curve(const X_curve_2 &cv, const Point_2& p) const //check
  {
    if (!curve_is_in_x_range(cv, p))
      return false;
    if (curve_is_vertical(cv))
      {
        if (curve_is_in_y_range(cv,p))
          return true;
        else
          return false;
      }
    int res = compare_y(p, curve_calc_point(cv, p));
    if (res == EQUAL)
      return true;
    return false;
  }
private:
  bool is_left(const Point_2 &p1, const Point_2 &p2) const 
  { return (compare_x(p1, p2) == SMALLER); }
  bool is_right(const Point_2 &p1, const Point_2 &p2) const 
  { return (compare_x(p1, p2) == LARGER); }
  bool is_same_x(const Point_2 &p1, const Point_2 &p2) const 
  { return (compare_x(p1, p2) == EQUAL); }
  bool is_lower(const Point_2 &p1, const Point_2 &p2) const 
  { return (compare_y(p1, p2) == SMALLER); }
  bool is_higher(const Point_2 &p1, const Point_2 &p2) const 
  { return (compare_y(p1, p2) == LARGER); }
  bool is_same_y(const Point_2 &p1, const Point_2 &p2) const 
  { return (compare_y(p1, p2) == EQUAL); }
  bool is_same(const Point_2 &p1, const Point_2 &p2) const
  {
    return (compare_x(p1, p2) == EQUAL) &&
      (compare_y(p1, p2) == EQUAL);
  }
  const Point_2& leftmost(const Point_2 &p1, const Point_2 &p2) const
  { return (is_left(p1, p2) ? p1 : p2); }

  const Point_2& rightmost(const Point_2 &p1, const Point_2 &p2) const
  { return (is_right(p1, p2) ? p1 : p2); }
  
  const Point_2& lowest(const Point_2 &p1, const Point_2 &p2) const
  { return (is_lower(p1, p2) ? p1 : p2); }
  
  const Point_2& highest(const Point_2 &p1, const Point_2 &p2) const
  { return (is_higher(p1, p2) ? p1 : p2); }
  
private:
  Point_2 curve_calc_point(const X_curve_2 &cv, const Point_2 & q) const
  {
    // CGAL_assertion (!curve_is_in_s_range(cv, q));
    if ( !curve_is_in_x_range(cv, q) )
      return cv.source();
    
    if (curve_is_vertical(cv))
      return cv.source();
    
    //return Point_2(q.x(), cv.source().y() + 
    //             (cv.target().y() - cv.source().y()) / 
    //             (cv.target().x() - cv.source().x()) * 
    //             (q.x() - cv.source().x()) );
    
    const Point_2 & a = cv.source();
    const Point_2 & b = cv.target();
    return Point_2((b.hx() * a.hw() - a.hx() * b.hw()) * q.hx() * a.hw(),
                   (b.hx() * a.hw() - a.hx() * b.hw()) * q.hw() * a.hy() + 
                   (b.hy() * a.hw() - a.hy() * b.hw()) * 
                   (q.hx() * a.hw() - a.hx() * q.hw()),  
                   (b.hx() * a.hw() - a.hx() * b.hw()) * q.hw() * a.hw());
  }
  
  typename R::FT curve_derivative(const X_curve_2 &cv) const
  {
    CGAL_assertion(!curve_is_vertical(cv));
    
    return ( (cv.target()).y() - cv.source().y()) / 
      (cv.target().x() - cv.source().x());
  }
  
  typename R::FT curve_b_const(const X_curve_2 &cv)const
  {
    CGAL_assertion (!curve_is_vertical(cv));
    return ((cv.target().x() * cv.source().y() - 
             cv.target().y()*cv.source().x())     / 
            (cv.target().x() - cv.source().x()));
  }
  
  Comparison_result compare_value(const typename R::FT &v1, 
                                       const typename R::FT &v2) const
  {
    typename R::FT d = v1 - v2;
    typename R::FT z(0);
    if (d == z)
      return EQUAL;
    if (z < d)
      return LARGER;
    else
      return SMALLER;
  }

  Curve_status curve_get_status(const X_curve_2 &cv) const
  {
    if (curve_is_vertical(cv)) 
      {
        if ( is_higher(cv.target(), cv.source()) )
          return CURVE_VERTICAL_UP;
        else
          return CURVE_VERTICAL_DOWN;
      }
    else
      {
        if ( is_right(cv.target(), cv.source()) )
          return CURVE_RIGHT;
        else
          return CURVE_LEFT;
      }
  }

};

CGAL_END_NAMESPACE

#endif // CGAL_PM_SEGMENT_TRAITS_2_H
// EOF