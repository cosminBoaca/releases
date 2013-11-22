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


#ifndef CGAL_TRIANGULATION_2_VERTEX_ITERATOR_H
#define CGAL_TRIANGULATION_2_VERTEX_ITERATOR_H

template<class I>
class CGAL_Triangulation_2;


template<class I>
class CGAL_Triangulation_2_vertex_iterator
    : public bidirectional_iterator<I::Vertex*,ptrdiff_t>
{
public:
    typedef I::Vertex Vertex;
    typedef I::Face Face;
    typedef CGAL_Triangulation_2_vertex_iterator<I> Vertex_iterator;

    CGAL_Triangulation_2_vertex_iterator()
        : pos(NULL), triangulation(NULL)
    {}
    
    CGAL_Triangulation_2_vertex_iterator(CGAL_Triangulation_2<I> *T)
        : pos(NULL), triangulation(T)
    {
        switch( T->number_of_vertices() ){
        case 0: // past-the-end
            pos = NULL;
            return;
        case 1:
            pos = (Face*)1; // different from any pointer;
            return;         // "points" to the only vertex of the triangulation
        default:
            {
                pos = T->infinite_face();
                while (associated_vertex()==NULL){
                    increment();
                }
                return;
            }
        }
    }
    
    CGAL_Triangulation_2_vertex_iterator(CGAL_Triangulation_2<I> *T,int)
        : pos(NULL), triangulation(T)
    {}
    Vertex_iterator&
    operator++()
    {
        if (pos==NULL){
            return *this;            // cannot advance past-the-end iterator
        }
        if (triangulation->number_of_vertices()==1){
            pos = NULL; // past-the-end
            return *this;
        }
        do{
            increment();
            if ( pos == triangulation->infinite_face()){
                pos = NULL;   // complete tour
                return *this;
            }
        }while (associated_vertex()==NULL);
        return *this;
    }
    
    
    Vertex_iterator&
    operator--()
    {
        switch(triangulation->number_of_vertices()) {
        case 0:
            return *this;
        case 1:
            if(pos == NULL){
                *this = Vertex_iterator(triangulation);
            } else {
                pos = NULL;
            }
            return *this;            // can decrease past-the-end iterator
        default:
            if (pos==NULL){
                *this = Vertex_iterator(triangulation);
                --*this;
                return *this;            // can decrease past-the-end iterator
            }
            do{
                decrement();
                if ( pos == triangulation->infinite_face()){
                    pos = NULL;   // complete tour
                    return *this;
                }
            }while (associated_vertex()==NULL);
            return *this;
        }
    }
    
    
    Vertex_iterator operator++(int)
    {
        Vertex_iterator tmp(*this);
        ++(*this);
        return tmp;
    }
    
    
    Vertex_iterator operator--(int)
    {
        Vertex_iterator tmp(*this);
        --(*this);
        return tmp;
    }
    Vertex*
    operator*() const
    {
        return associated_vertex();
    }
    
    
    //
    bool
    operator==(const Vertex_iterator& fi) const
    {
        return ( (pos == fi.pos ) && (triangulation==fi.triangulation) );
    }
    
    
    bool
    operator!=(const Vertex_iterator& fi) const
    {
        return !(*this == fi);
    }
    
private:
    Face *pos;
    CGAL_Triangulation_2<I> *triangulation;
    
    Vertex*
    associated_vertex() const
    {
        if(pos == NULL) {
            return NULL;
        }
        switch(triangulation->number_of_vertices() ){
        case 0:
            return NULL;
        case 1:
            return triangulation->finite_vertex();
        case 2:
            return pos->vertex(cw(maximum(pos)));
        default:
            {
                int i = cw(maximum(pos));            // candidate associate vertex
                if(triangulation->traits().compare_y(pos->vertex(i)->point(),
                                                   pos->vertex(cw(i))->point())
                   ==CGAL_LARGER){
                    //   vcw(i) < vi
                    return pos->vertex(i);
                }
                if ( triangulation->is_infinite(pos)){
                    Face* f=pos->neighbor(cw(i)); // next edge on the CH in cw order
                    int   j=f->index(triangulation->infinite_vertex() );
                    CGAL_Comparison_result comp =
                        triangulation->traits().compare_y(pos->vertex(i)->point(),
                                                        f->vertex(cw(j))->point());
                    if (comp == CGAL_SMALLER){         //  vi smaller vertex
                        return pos->vertex(i);
                    }
                    if(comp ==CGAL_EQUAL){            // horizontal part of CH
                        comp = triangulation->traits().compare_x(
                                                        pos->vertex(i)->point(),
                                                        f->vertex(cw(j))->point());
                        if(comp == CGAL_LARGER){        // lower hull
                            return pos->vertex(i);
                        }
                        if(pos->vertex(cw(i)) == f->vertex(cw(j))){ // 1 dim. horiz.
                            return pos->vertex(i);
                        }
                    }
                }
            }
        }
        return NULL;
    }
    
    
    
    static
    int
    ccw(int i)
    {
        return (i+1) % 3;
    }
    
    
    static
    int
    cw(int i)
    {
        return (i+2) % 3;
    }
    
    void
    increment()
    {
        int max = maximum(pos);
        Face *next=pos->neighbor(max);         // tentatative first child
        Face *parent;
        int max2 = maximum(next);
        if ( next->neighbor(cw(max2))== pos){
          // next is the first child of pos
          pos = next;
          return;
        }
        // look for the second child of an ancestor of pos
        next=pos->neighbor(ccw(max));          // tentatative second child
        while (1){
            max2 = maximum(next);
            if ( next->neighbor(cw(max2))== pos) // next is the second child of pos
                { pos = next; return;}
            while (1){
                parent = pos->neighbor(cw(max));        // go to parent
                max = maximum(parent);
                next=parent->neighbor(ccw(max));       // tentatative second child
                if (next==pos)              // already coming back from this child
                    { pos = parent; continue; }
                else
                    { pos = parent; break; }
            }
        }
    }
    
    
    void
    decrement()
    {
        int max = maximum(pos);
        Face *next=pos->neighbor(cw(max));     // parent of pos
        int max2 = maximum(next);
        if ( next->neighbor(max2) == pos)      // pos is the first child of next
            { pos = next; return;}
        pos = next->neighbor(max2);         // tentative first child
        max = maximum(pos);
        if ( pos->neighbor(cw(max))!=next)   // pos is not the first child of next
            { pos = next; return;}
        // look for "last" node in first subtree of next
        while (1){
            next = pos->neighbor(ccw(max));       // tentatative second child
            max2 = maximum(next);
            if (next->neighbor(cw(max2))!= pos){
                //next is not the second child of pos
                next=pos->neighbor(max);         // tentative first child
                max2 = maximum(next);
                if ( next->neighbor(cw(max2))!= pos){
                    //next is not first child of pos
                    return;
                }
            }
            pos=next;
            max=max2;
        }
    }
    
    
    int maximum(Face *f) const
    {
        if ( triangulation->is_infinite(f) ){
            return f->index( triangulation->infinite_vertex() );
        }
        if(triangulation->traits().compare_y(f->vertex(0)->point(),
                                           f->vertex(1)->point()) == CGAL_SMALLER)
            //  v0 < v1
            if(triangulation->traits().compare_y(f->vertex(2)->point(),
                                               f->vertex(1)->point())==CGAL_SMALLER)
                //  v0,v2 < v1
                { return 1; }
            else
                //  v0 < v1 <= v2
                { return 2; }
        else
            //  v1 <= v0
    
            if(triangulation->traits().compare_y(f->vertex(1)->point(),
                                               f->vertex(2)->point())!=CGAL_SMALLER)
                //  v2 <= v1 <= v0
                if(triangulation->traits().compare_y(
                                               f->vertex(0)->point(),
                                               f->vertex(1)->point()) == CGAL_EQUAL)
                    //  v2 <= v1 == v0
                    { return 1; }
                else
                    //  v2 <= v1 < v0
                    { return 0; }
            else
                //  v1<=v0, v1<v2
                if(triangulation->traits().compare_y(f->vertex(0)->point(),
                                                   f->vertex(2)->point())
                   ==CGAL_SMALLER)
                    //  v1 <= v0 < v2
                    { return 2; }
                else
                    //  v1 < v2 <= v0
                    { return 0; }
    
    }
    
    
    
    
};

#endif // CGAL_TRIANGULATION_2_VERTEX_ITERATOR_H
