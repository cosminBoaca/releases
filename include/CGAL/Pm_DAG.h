// ======================================================================
//
// Copyright (c) 1999 The GALIA Consortium
//
// This software and related documentation is part of the
// Computational Geometry Algorithms Library (CGAL).
//
// Every use of CGAL requires a license. Licenses come in three kinds:
//
// - For academic research and teaching purposes, permission to use and
//   copy the software and its documentation is hereby granted free of  
//   charge, provided that
//   (1) it is not a component of a commercial product, and
//   (2) this notice appears in all copies of the software and
//       related documentation.
// - Development licenses grant access to the source code of the library 
//   to develop programs. These programs may be sold to other parties as 
//   executable code. To obtain a development license, please contact
//   the GALIA Consortium (at cgal@cs.uu.nl).
// - Commercialization licenses grant access to the source code and the
//   right to sell development licenses. To obtain a commercialization 
//   license, please contact the GALIA Consortium (at cgal@cs.uu.nl).
//
// This software and documentation is provided "as-is" and without
// warranty of any kind. In no event shall the CGAL Consortium be
// liable for any damage of any kind.
//
// The GALIA Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Free University of Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbrucken (Germany),
// and Tel-Aviv University (Israel).
//
// ----------------------------------------------------------------------
//
// release       : CGAL-2.0
// release_date  : 1999, June 03
//
// file          : include/CGAL/Pm_DAG.h
// package       : pm (3.07)
// source        : 
// revision      : 
// revision_date : 
// author(s)     : Iddo Hanniel
//                 Oren Nechushtan
//
//
// coordinator   : Tel-Aviv University (Dan Halperin)
//
// Chapter       : 
// email         : cgal@cs.uu.nl
//
// ======================================================================
/*
Directed acyclic binary graph template class
*/
#ifndef CGAL_PM_DAG_H
#define CGAL_PM_DAG_H

#ifndef CGAL_PM_CONFIG_H
#include <CGAL/Pm_config.h>
#endif

#include <cstdlib>
#include <iostream>
#include <list>
#include <functional>
#ifndef CGAL_NUMBER_UTILS_H
#include <CGAL/number_utils.h>
#endif
#ifndef CGAL_KERNEL_ASSERTIONS_H
#include <CGAL/kernel_assertions.h>
#endif
#ifndef CGAL_HANDLE_H
#include <CGAL/Handle.h>
#endif

CGAL_BEGIN_NAMESPACE

template<class T,class Pred>
class DAG;

template<class T>
class DAG_handle : public Handle
{
public: //iddo (for CC-7.2) maybe protected?
	typedef T* pointer;
	typedef T& reference;
	typedef const T& const_reference;
protected:
	void init() {PTR=0;}
public:
	DAG_handle() {init();}
	DAG_handle(const DAG_handle<T>& x) : Handle(x) {}
	DAG_handle& operator=(const DAG_handle<T>& x) {Handle::operator=(x);return *this;}
	bool operator!() const {return PTR==0;}
};

template<class T,class Pred>
class DAG : public DAG_handle<T>
{
public:
	typedef DAG<T,Pred> Self;
	typedef DAG_handle<T> DAG_handle;
	typedef Pred Predicate;
	typedef std::list<pointer> list_pointer;
protected:	
	static const Self dummy_DAG;
	class node : public Rep
	{
		friend class DAG<T,Pred>;
	public:
		node(const T& e) : data(e),leftPtr(),rightPtr(){}
		node(const T& e, const DAG_handle& left, const DAG_handle& right)
			: data(e),leftPtr(left),rightPtr(right) {}
		~node(){}
		bool is_inner_node() const {return !!leftPtr && !!rightPtr;}
		bool visited() const {return visited_;}
	protected:
		T data;			// information stored in node
		DAG_handle leftPtr,rightPtr;
		mutable bool visited_;
	};
	
	public:
		
		/* -------constructors destructors -----*/
		DAG(){}
		DAG(const DAG_handle& dag):DAG_handle(dag){}
		DAG(const Self& dag):DAG_handle(dag){}
		DAG(const T& rootValue){PTR = new node(rootValue);}
		DAG(const T& rootValue, const Self& left, const Self& right)
		{PTR= new node(rootValue, left, right);}
		~DAG(){}
		/* --------information retrieval -------*/
		const Self& left() const
		{
			CGAL_precondition(!operator!());
                        //const DAG_handle& x=ptr()->leftPtr;
/*			if (!!x) return *(const Self*)&x;
			return dummy_DAG;*/
			return *(const Self*)&ptr()->leftPtr;

		}
		const Self& right() const
		{
			CGAL_precondition(!operator!());
/*			const DAG_handle& x=ptr()->rightPtr;	
			if (!!x) return *(const Self*)&x;
			return dummy_DAG;*/
			return *(const Self*)&ptr()->rightPtr;
		}
		reference operator*() const
		{
			CGAL_precondition(!operator!());
			return ptr()->data;
		}
		pointer operator->() const
		{
			CGAL_precondition(!operator!());
			return &operator*();
		}
		bool is_inner_node() const {return !operator!() && ptr()->is_inner_node();}
		unsigned long size() const
		{
			visit_none();
			return recursive_size();
		}
		unsigned long depth() const
		{
			visit_none();
			return recursive_depth();
		}
		bool operator==(const Self& b) const
		{
			return PTR==b.PTR;
		}
		bool operator!=(const Self& b) const
		{
			return !operator==(b);
		}
		/* dynamic management ---------*/
		
		/* description:
		Shallow copy	*/
		Self& operator=(const Self& b)
		{
			Handle::operator=(b);
			return *this;
		}
/*
		Self& deep_copy(const Self& b)
		{
			if (this != &b)
			{
				clear();
				operator=(b);
			}
			return *this;
		}
*/
/*
		void clear()
		{
			if (!operator!())
			{
				left().clear();
				right().clear();
				operator=(Self());
			}
		}
*/
/*
		void detach_left()
		{
			if (!operator!())
			{
				// create dummy DAG
				T tmp;
				Self dummy(tmp);
				// detach left son,redirect to dummy
				set_left(dummy);
				// set left son pointer to 0
				ptr()->leftPtr.PTR=0;
				// delete dummy DAG
				delete dummy.ptr();
			}
		}
		void detach_right()
		{
			if (!operator!())
			{
				// create dummy DAG
				T tmp;
				Self dummy(tmp);
				// detach right son,redirect to dummy
				set_right(dummy);
				// set right son pointer to 0
				ptr()->rightPtr.PTR=0;
				// delete dummy DAG
				delete dummy.ptr();
			}
		}
		void detach()
		{
			detach_left();
			detach_right();
		}
*/
		void set_data(const T& data)
		{
			if (!operator!()) ptr()->data=data;
			else operator=(Self(data));
		}
		void set_left(const Self& left)
		{
			CGAL_precondition(!operator!());
			ptr()->leftPtr=left;
		}
		void set_right(const Self& right)
		{
			CGAL_precondition(!operator!());
			ptr()->rightPtr=right;
		}
		void replace(const T& data,const Self& left,const Self& right)
		{
			set_data(data);
			set_left(left);
			set_right(right);
		}
		void visit_none() const
		{
			if (!operator!())
			{
				ptr()->visited_=false;
				left().visit_none();
				right().visit_none();
			}
		}
		void visit_one() const
		{
			if (!operator!())
				ptr()->visited_=true;
		}
		/* -----output ---------------*/
#ifdef CGAL_PRE_IN_POST_ORDER
		void preorder() const
		{
			if (!operator!())
			{
				std::cout << operator*() << '\t';
				left().preorder();
				right().preorder();
			}
		}
		void inorder() const
		{
			if (!operator!())
			{
				left().inorder();
				std::cout << operator*() << '\t';
				right().inorder();
			}
		}
		void postorder() const
		{
			if (!operator!())
			{
				left().postorder();
				right().postorder();
				std::cout << operator*() << '\t';
			}
		}
#endif

#if _MSC_VER>=1100
		friend std::ostream& operator<<(std::ostream&  out, const Self& t);
#endif

		list_pointer& filter(const Predicate& p,list_pointer& l) const
		{
			visit_none();
			return recursive_filter(p,l);
		}
protected:
		unsigned long recursive_size() const
		{
			if (!operator!() && !ptr()->visited())
				return 1+left().recursive_size()+right().recursive_size();
			else
				return 0;
		}
		unsigned long recursive_depth() const
		{
			if (!operator!() && !ptr()->visited())
				return 1+ std::max(left().recursive_depth(),right().recursive_depth());
			else
				return 0;
		}
		list_pointer& recursive_filter(const Predicate& p,list_pointer& l) const
		{
			if (!operator!() && !ptr()->visited())
			{
				if (p(operator*())) 
					l.insert(l.end(),operator->());
				visit_one();
				left().recursive_filter(p,l);
				right().recursive_filter(p,l);
			}
			return l;
		}
private:
	node* ptr() const {return (node*)PTR;}
};

template<class T,class Pred> std::ostream& operator<<(std::ostream&  out, const DAG<T,Pred>& t)
{
  //	typedef DAG<T,Pred> Self; 
	static int depth;
	int i;
	if (!!t)
	{
		out << "\n";
		for(i=0;i<depth;i++)out << ">";
		out << "Data=" << *t;
		{
			depth++;
			out << "\n";
			for(i=0;i<depth;i++)out << ">";
			out << "left=" << t.left();
			out << "\n";
			for(i=0;i<depth;i++)out << ">";
			out << "right=" <<t.right();
			depth--;
		}
	}
	else
	{
		out << "Empty";
	}
	return out ;
}

CGAL_END_NAMESPACE

#ifdef CGAL_CFG_NO_AUTOMATIC_TEMPLATE_INCLUSION
//#include <CGAL/Pm_DAG.C>
#endif




#endif
/* 
	tech notes:
		The code is Handle designed.
		left(),right() are designed to cope with Handle(Handle& x) precondition x.PTR!=0
		operator=() performs shallow copy
		operator*() returns data type
		output is done as a binary tree.
*/










