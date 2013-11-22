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
// source        : Bbox_3.fw
// file          : include/CGAL/Bbox_3.h
// package       : _3 (2.1.2)
// revision      : 2.1.2
// revision_date : 21 May 1999 
// author(s)     : Andreas Fabri
//
// coordinator   : MPI, Saarbruecken  (<Stefan.Schirra>)
// email         : cgal@cs.uu.nl
//
// ======================================================================
 

#ifndef CGAL_BBOX_3_H
#define CGAL_BBOX_3_H

#ifndef CGAL_BASIC_H
#include <CGAL/basic.h>
#endif // CGAL_BASIC_H
#ifndef CGAL_CARTESIAN_CLASSES_H
#include <CGAL/cartesian_classes.h>
#endif // CGAL_CARTESIAN_CLASSES_H
#ifndef SIXTUPLE_H
#include <CGAL/Sixtuple.h>
#endif // SIXTUPLE_H

CGAL_BEGIN_NAMESPACE

class Bbox_3 : public Handle
{
public:
                         Bbox_3();
                         Bbox_3(const Bbox_3& );
                         Bbox_3(double x_min, double y_min, double zmin,
                                    double x_max, double y_max, double z_max);
                         ~Bbox_3();
  Bbox_3& operator=(const Bbox_3& b);

  double                 xmin() const;
  double                 ymin() const;
  double                 zmin() const;
  double                 xmax() const;
  double                 ymax() const;
  double                 zmax() const;

  Bbox_3             operator+(const Bbox_3& b) const;

private:
  inline _Sixtuple<double>* ptr() const;
};

inline Bbox_3::Bbox_3()
{
  PTR = new _Sixtuple<double>;
}

inline Bbox_3::Bbox_3(const Bbox_3& b) :
  Handle(b)
{}

inline Bbox_3::Bbox_3(double x_min, double y_min, double z_min,
                              double x_max, double y_max, double z_max)
{
  PTR = new _Sixtuple<double>(x_min, y_min, z_min, x_max, y_max, z_max);
}

inline Bbox_3::~Bbox_3()
{}

inline Bbox_3& Bbox_3::operator=(const Bbox_3& b)
{
  Handle::operator=(b);
  return *this;
}
inline double Bbox_3::xmin() const
{
  return ptr()->e0;
}

inline double Bbox_3::ymin() const
{
  return ptr()->e1;
}

inline double Bbox_3::zmin() const
{
  return ptr()->e2;
}

inline double Bbox_3::xmax() const
{
  return ptr()->e3;
}

inline double Bbox_3::ymax() const
{
  return ptr()->e4;
}

inline double Bbox_3::zmax() const
{
  return ptr()->e5;
}
inline Bbox_3 Bbox_3::operator+(const Bbox_3& b) const
{
  return Bbox_3(std::min(xmin(), b.xmin()),
                std::min(ymin(), b.ymin()),
                std::min(zmin(), b.zmin()),
                std::max(xmax(), b.xmax()),
                std::max(ymax(), b.ymax()),
                std::max(zmax(), b.zmax()));
}
inline bool do_overlap(const Bbox_3& bb1, const Bbox_3& bb2)
{
    // check for emptiness ??
    if (bb1.xmax() < bb2.xmin() || bb2.xmax() < bb1.xmin())
        return false;
    if (bb1.ymax() < bb2.ymin() || bb2.ymax() < bb1.ymin())
        return false;
    if (bb1.zmax() < bb2.zmin() || bb2.zmax() < bb1.zmin())
        return false;
    return true;
}
inline _Sixtuple<double>* Bbox_3::ptr() const
{
  return (_Sixtuple<double>*)PTR;
}

#ifndef NO_OSTREAM_INSERT_BBOX_3
inline
std::ostream&
operator<<(std::ostream &os, const Bbox_3& b)
{
  switch(os.iword(IO::mode))
  {
    case IO::ASCII :
        return os << b.xmin() << ' ' << b.ymin() << ' ' << b.zmin();
    case IO::BINARY :
        write(os, b.xmin());
        write(os, b.ymin());
        write(os, b.zmin());
        write(os, b.xmax());
        write(os, b.ymax());
        write(os, b.zmax());
        return os;
    default:
        os << "Bbox_3((" << b.xmin()
           << ", "       << b.ymin()
           << ", "       << b.zmin() << "), (";
        os <<               b.xmax()
           << ", "       << b.ymax()
           << ", "       << b.zmax() << "))";
        return os;
  }
}
#endif // NO_OSTREAM_INSERT_BBOX_3



#ifndef NO_ISTREAM_EXTRACT_BBOX_3
inline
std::istream&
operator>>(std::istream &is, Bbox_3& b)
{
  double xmin, ymin, zmin, xmax, ymax, zmax;

  switch(is.iword(IO::mode))
  {
    case IO::ASCII :
        is >> xmin >> ymin >> xmax >> ymax;
        break;
    case IO::BINARY :
        read(is, xmin);
        read(is, ymin);
        read(is, zmin);
        read(is, xmax);
        read(is, ymax);
        read(is, zmax);
        break;
  }
  b = Bbox_3(xmin, ymin, zmin, xmax, ymax, zmax);
  return is;
}

#endif // NO_ISTREAM_EXTRACT_BBOX_3


CGAL_END_NAMESPACE


#endif // CGAL_BBOX_3_H
