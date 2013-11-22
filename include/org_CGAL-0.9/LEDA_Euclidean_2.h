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



#ifndef LEDA_EUCLIDEAN_2_H
#define LEDA_EUCLIDEAN_2_H

#include <CGAL/Triangulation_vertex.h>
#include <CGAL/Triangulation_face.h>
#include <CGAL/Triangulation_face_circulator.h>
#include <CGAL/Triangulation_vertex_circulator.h>

template < class R >
class LEDA_Euclidean_2 {
public:
    typedef R Rep;
    typedef leda_point  Point;
    typedef leda_segment Segment;
    typedef leda_triangle Triangle;

    typedef CGAL_Triangulation_vertex<Point> Vertex;
    typedef CGAL_Triangulation_face<Vertex> Face;

    CGAL_Comparison_result compare_x(const Point &p, const Point &q) const
    {
         return CGAL_compare(p.xcoord(), q.xcoord());
    }


    CGAL_Comparison_result compare_y(const Point &p, const Point &q) const
    {
        return CGAL_compare(p.ycoord(), q.ycoord());
    }


    CGAL_Orientation orientation(const Point &p,
                                 const Point &q,
                                 const Point &r) const
    { 
        int o = orientation(p, q, r);
        return (o>0)?CGAL_LEFTTURN : (o<0)?CGAL_RIGHTTURN : CGAL_COLLINEAR;
    }


    CGAL_Orientation extremal(const Point &p,
                              const Point &q,
                              const Point &r) const
    {
        if (p==q) return CGAL_COLLINEAR;
        if (p==r) return CGAL_COLLINEAR;
        if (r==q) return CGAL_COLLINEAR;
        int o = orientation(p, q, r);
        return (o>0)?CGAL_LEFTTURN : (o<0)?CGAL_RIGHTTURN : CGAL_COLLINEAR;
    }

    CGAL_Oriented_side side_of_oriented_circle(const Point &p,
                                               const Point &q,
                                               const Point &r,
                                               const Point &s) const
    {
        if (p==s) return CGAL_ON_ORIENTED_BOUNDARY;
        if (q==s) return CGAL_ON_ORIENTED_BOUNDARY;
        if (r==s) return CGAL_ON_ORIENTED_BOUNDARY;

        int o = side_of_circle(p, q, r, s);
        return (o>0)? CGAL_ON_POSITIVE_SIDE  
                    : (o<0)?CGAL_ON_NEGATIVE_SIDE : CGAL_ON_ORIENTED_BOUNDARY;
    }

    

    
    class Distance{
    public:
        Distance(const Point& p0,
                 const LEDA_Euclidean* impl = NULL)
            : _p0(p0)
        {
            CGAL_kernel_assertion( impl == impl ); // avoids warning
        }
    
    
        Distance(const Point& p0,
                 const Point& p1,
                 const LEDA_Euclidean* impl = NULL)
            : _p0(p0), _p1(p1)
        {
            CGAL_kernel_assertion( impl == impl ); // avoids warning
        }
    
    
        Distance(const Point& p0,
                 const Point& p1,
                 const Point& p2,
                 const LEDA_Euclidean* impl = NULL)
            : _p0(p0), _p1(p1), _p2(p2)
        {
            CGAL_kernel_assertion( impl == impl ); // avoids warning
        }
    
        void
        set_point(int i, const Point& p)
        {
            CGAL_kernel_precondition(i == 0 || i == 1 || i == 2);
            switch(i){
            case 0:
                _p0 = p;
                break;
            case 1:
                _p1 = p;
                break;
            default:
                _p2 = p;
            }
        }
    
        Point
        get_point(int i) const
        {
          CGAL_kernel_precondition(i == 0 || i == 1 || i == 2);
          switch(i){
          case 0:
            return _p0;
          case 1:
            return _p1;
          }
          return _p2;
        }
    
        CGAL_Comparison_result
        compare() const
        {
            return CGAL_compare(_p0.sqr_dist(_p1),
                                _p0.sqr_dist(_p2));
        }
    
    private:
        Point _p0, _p1, _p2;
    };
    

    
};



#endif // LEDA_EUCLIDEAN_2_H
