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



#ifndef CGAL_RAYH2_H
#define CGAL_RAYH2_H




template < class FT, class RT >
class CGAL__Ray_repH2 : public CGAL_Rep
{
public:
                        CGAL__Ray_repH2();
                        CGAL__Ray_repH2(const CGAL_PointH2<FT,RT>& fp,
                                        const CGAL_PointH2<FT,RT>& sp);
                        ~CGAL__Ray_repH2(){}

    CGAL_PointH2<FT,RT>  start;
    CGAL_PointH2<FT,RT>  second;
};




template < class FT, class RT >
class CGAL_RayH2 : public CGAL_Handle
{
public:
            CGAL_RayH2();
            CGAL_RayH2( const CGAL_RayH2& r);
            CGAL_RayH2( const CGAL_PointH2<FT,RT>& sp,
                        const CGAL_PointH2<FT,RT>& secondp);
            CGAL_RayH2( const CGAL_PointH2<FT,RT>& sp,
                        const CGAL_DirectionH2<FT,RT>& d);
            ~CGAL_RayH2();

    CGAL_RayH2<FT,RT>&
            operator=(const CGAL_RayH2<FT,RT>& r);

    bool    operator==(const CGAL_RayH2& r) const;
    bool    operator!=(const CGAL_RayH2& r) const;
    bool    identical( const CGAL_RayH2& r) const;
    int     id() const;

    CGAL_PointH2<FT,RT>     start() const;
    CGAL_PointH2<FT,RT>     source() const;
    CGAL_PointH2<FT,RT>     second_point() const;
    CGAL_PointH2<FT,RT>     point(int i) const;
    CGAL_DirectionH2<FT,RT> direction() const;
    CGAL_LineH2<FT,RT>      supporting_line() const;
    CGAL_RayH2              opposite() const;

    bool    is_horizontal() const;
    bool    is_vertical() const;
    bool    has_on(const CGAL_PointH2<FT,RT> p) const;
    bool    collinear_has_on(const CGAL_PointH2<FT,RT> p) const;
    bool    is_degenerate() const;

    CGAL_RayH2<FT,RT>
            transform( const CGAL_Aff_transformationH2<FT,RT> & t) const;
protected:

    CGAL__Ray_repH2<FT,RT>*
            ptr() const;
};



template < class FT, class RT >
CGAL__Ray_repH2<FT,RT>::CGAL__Ray_repH2()
{
}


template < class FT, class RT >
CGAL__Ray_repH2<FT,RT>::CGAL__Ray_repH2(const CGAL_PointH2<FT,RT>& fp,
                                        const CGAL_PointH2<FT,RT>& sp) :
  start(fp), second(sp)
{
}




template < class FT, class RT >
CGAL_RayH2<FT,RT>::CGAL_RayH2()
{
#ifdef CGAL_CHECK_PRECONDITIONS
  PTR = NULL;
#else
 PTR = new CGAL__Ray_repH2<FT,RT>;
#endif // CGAL_CHECK_PRECONDITIONS
}

template < class FT, class RT >
CGAL_RayH2<FT,RT>::CGAL_RayH2(const CGAL_RayH2<FT,RT>& r) :
  CGAL_Handle(r)
{
}

template < class FT, class RT >
CGAL_RayH2<FT,RT>::CGAL_RayH2( const CGAL_PointH2<FT,RT>& sp,
                               const CGAL_PointH2<FT,RT>& secondp)
{
 PTR = new CGAL__Ray_repH2<FT,RT>(sp,secondp);
 CGAL_nondegeneracy_assertion;
}

template < class FT, class RT >
CGAL_RayH2<FT,RT>::CGAL_RayH2( const CGAL_PointH2<FT,RT>& sp,
                               const CGAL_DirectionH2<FT,RT>& d)
{
 PTR = new CGAL__Ray_repH2<FT,RT>(sp, sp + d.vector());
 CGAL_nondegeneracy_assertion;
}

template < class FT, class RT >
CGAL_RayH2<FT,RT>::~CGAL_RayH2()
{
}

template < class FT, class RT >
CGAL_RayH2<FT,RT>&
CGAL_RayH2<FT,RT>::operator=(const CGAL_RayH2<FT,RT>& r)
{
 CGAL_Handle::operator=(r);
 return *this;
}
template < class FT, class RT >
CGAL_PointH2<FT,RT>
CGAL_RayH2<FT,RT>::source() const
{
 return ptr()->start;
}

template < class FT, class RT >
CGAL_PointH2<FT,RT>
CGAL_RayH2<FT,RT>::start() const
{
 return ptr()->start;
}


template < class FT, class RT >
CGAL_DirectionH2<FT,RT>
CGAL_RayH2<FT,RT>::direction() const
{
 CGAL_nondegeneracy_precondition( !is_degenerate() );
 return CGAL_DirectionH2<FT,RT>( ptr()->second - ptr()->start );
}
template < class FT, class RT >
CGAL_PointH2<FT,RT>
CGAL_RayH2<FT,RT>::second_point() const
{
 CGAL_nondegeneracy_precondition( !is_degenerate() );
 return ptr()->second;
}

template < class FT, class RT >
CGAL_PointH2<FT,RT>
CGAL_RayH2<FT,RT>::point(int i) const
{
 CGAL_nondegeneracy_precondition( !is_degenerate() );
 CGAL_kernel_precondition( i>= 0 );
 CGAL_VectorH2<FT,RT> v = direction().vector();
 return start() + RT(i) * v;
}

template < class FT, class RT >
CGAL_LineH2<FT,RT>
CGAL_RayH2<FT,RT>::supporting_line() const
{
 CGAL_nondegeneracy_precondition( !is_degenerate() );
 return CGAL_LineH2<FT,RT>(*this);
}

template < class FT, class RT >
CGAL_RayH2<FT,RT>
CGAL_RayH2<FT,RT>::opposite() const
{
 return CGAL_RayH2<FT,RT>( ptr()->start, - direction() );
}

template < class FT, class RT >
CGAL_RayH2<FT,RT>
CGAL_RayH2<FT,RT>::transform(
                       const CGAL_Aff_transformationH2<FT,RT> & t) const
{
 return CGAL_RayH2<FT,RT>(t.transform(ptr()->start),
                          t.transform(ptr()->second) );
}


template < class FT, class RT >
bool
CGAL_RayH2<FT,RT>::is_horizontal() const
{
 return start().hy()*second_point().hw() == second_point().hy()*start().hw();
}

template < class FT, class RT >
bool
CGAL_RayH2<FT,RT>::is_vertical() const
{
 return start().hx()*second_point().hw() == second_point().hx()*start().hw();
}

template < class FT, class RT >
bool
CGAL_RayH2<FT,RT>::has_on(const CGAL_PointH2<FT,RT> p) const
{
 return ( (  p == start() )
        ||(CGAL_DirectionH2<FT,RT>(p - ptr()->start) == direction() ) );
}

template < class FT, class RT >
bool
CGAL_RayH2<FT,RT>::is_degenerate() const
{
 return ( (ptr()->start == ptr()->second) );
}

template < class FT, class RT >
bool
CGAL_RayH2<FT,RT>::collinear_has_on(const CGAL_PointH2<FT,RT> p) const
{
 return has_on(p);
}

template < class FT, class RT >
bool
CGAL_RayH2<FT,RT>::operator==(const CGAL_RayH2<FT,RT>& r) const
{
 return ( (start() == r.start() )&&( direction() == r.direction() ) );
}

template < class FT, class RT >
bool
CGAL_RayH2<FT,RT>::operator!=( const CGAL_RayH2<FT,RT>& r) const
{
 return !(*this == r);
}


template < class FT, class RT >
bool
CGAL_RayH2<FT,RT>::identical( const CGAL_RayH2<FT,RT>& r) const
{
 return ( PTR == r.PTR );
}

template < class FT, class RT >
int
CGAL_RayH2<FT,RT>::id() const
{
 return (int)PTR;
}


template < class FT, class RT >
inline
CGAL__Ray_repH2<FT,RT>*
CGAL_RayH2<FT,RT>::ptr() const
{
 return (CGAL__Ray_repH2<FT,RT>*)PTR;
}


#endif // CGAL_RAYH2_H
