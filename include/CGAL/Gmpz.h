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


// Source: Gmpz.h
// Author: Andreas Fabri

#ifndef CGAL_GMPZ_H
#define CGAL_GMPZ_H



#include<CGAL/basic.h>
#include<gmp.h> // line changed by Wieger


class CGAL_Gmpz_rep : public CGAL_Rep
{
public:
  mpz_t  mpZ;

  CGAL_Gmpz_rep()
  {
    mpz_init_set_si(mpZ, 0);
  }

  CGAL_Gmpz_rep(mpz_t  z)
  {
    mpz_init_set(mpZ, z);
  }

  CGAL_Gmpz_rep(int si)
  {
    mpz_init_set_si(mpZ, si);
  }

  CGAL_Gmpz_rep(double d)
  {
    mpz_init_set_d(mpZ, d);
  }

  CGAL_Gmpz_rep(char* str)
  {
    mpz_init_set_str(mpZ, str, 10);
  }

  CGAL_Gmpz_rep(char* str, int base)
  {
    mpz_init_set_str(mpZ, str, base);
  }

  ~CGAL_Gmpz_rep()
  {
    mpz_clear(mpZ);
  }
};


class CGAL_Gmpz;

class CGAL_Gmpz : public CGAL_Handle
{
public:
  CGAL_Gmpz();


  CGAL_Gmpz(const CGAL_Gmpz &z);


  CGAL_Gmpz(mpz_t z);


  CGAL_Gmpz(int i);

  CGAL_Gmpz(double d);

  CGAL_Gmpz(char* str);
  CGAL_Gmpz(char* str, int base);

  ~CGAL_Gmpz();

  CGAL_Gmpz &operator=(const CGAL_Gmpz &z);

  bool operator==(const CGAL_Gmpz &z) const;
  bool operator==(int i) const;

  bool operator!=(const CGAL_Gmpz &z) const;
  bool operator!=(int i) const;

  bool operator<(const CGAL_Gmpz &z) const;
  bool operator<(int i) const;

  bool operator<=(const CGAL_Gmpz &z) const;
  bool operator<=(int i) const;

  bool operator>(const CGAL_Gmpz &z) const;
  bool operator>(int i) const;

  bool operator>=(const CGAL_Gmpz &z) const;
  bool operator>=(int i) const;

  CGAL_Gmpz operator-() const;

  CGAL_Gmpz operator+(const CGAL_Gmpz &z) const;
  CGAL_Gmpz operator+(int i) const;

  CGAL_Gmpz operator-(const CGAL_Gmpz &z) const;
  CGAL_Gmpz operator-(int i) const;

  CGAL_Gmpz operator*(const CGAL_Gmpz &z) const;
  CGAL_Gmpz operator*(int i) const;

  CGAL_Gmpz& operator*=(const CGAL_Gmpz &z);
  CGAL_Gmpz operator*=(int i);

  CGAL_Gmpz operator/(const CGAL_Gmpz &z) const;
  CGAL_Gmpz operator/(int i) const;

  CGAL_Gmpz_rep* ptr() const;
  double to_double() const;
  int sign() const;

};


inline  CGAL_Gmpz_rep* CGAL_Gmpz::ptr() const
  {
    return (CGAL_Gmpz_rep*) PTR;
  }


inline CGAL_Gmpz::CGAL_Gmpz()
  {
    PTR = new CGAL_Gmpz_rep();
  }

inline CGAL_Gmpz::CGAL_Gmpz(const CGAL_Gmpz &z)
  : CGAL_Handle((CGAL_Handle&)z)
  {}

inline CGAL_Gmpz::CGAL_Gmpz(mpz_t z)
  {
    PTR = new CGAL_Gmpz_rep(z);
  }

inline CGAL_Gmpz::CGAL_Gmpz(int i)
  {
    PTR = new CGAL_Gmpz_rep(i);
  }

inline CGAL_Gmpz::CGAL_Gmpz(double d)
  {
    PTR = new CGAL_Gmpz_rep(d);
  }

inline CGAL_Gmpz::CGAL_Gmpz(char* str)
  {
    PTR = new CGAL_Gmpz_rep(str);
  }

inline CGAL_Gmpz::CGAL_Gmpz(char* str, int base)
  {
    PTR = new CGAL_Gmpz_rep(str, base);
  }

inline CGAL_Gmpz::~CGAL_Gmpz()
  {}

inline CGAL_Gmpz &CGAL_Gmpz::operator=(const CGAL_Gmpz &z)
  {
    CGAL_Handle::operator=(z);
    return *this;
  }

inline  bool CGAL_Gmpz::operator==(const CGAL_Gmpz &z) const
  {
    return ( mpz_cmp(ptr()->mpZ, z.ptr()->mpZ) == 0 );
  }


inline  bool CGAL_Gmpz::operator<(const CGAL_Gmpz &z) const
  {
    return ( mpz_cmp(ptr()->mpZ, z.ptr()->mpZ) < 0 );
  }


inline  bool CGAL_Gmpz::operator<(int i) const
  {
    return ( mpz_cmp_si(ptr()->mpZ, i) < 0 );
  }


inline  bool CGAL_Gmpz::operator<=(const CGAL_Gmpz &z) const
  {
    return ( mpz_cmp(ptr()->mpZ, z.ptr()->mpZ) <= 0 );
  }


inline  bool CGAL_Gmpz::operator<=(int i) const
  {
    return ( mpz_cmp_si(ptr()->mpZ, i) <= 0 );
  }

inline  bool CGAL_Gmpz::operator>(const CGAL_Gmpz &z) const
  {
    return ( mpz_cmp(ptr()->mpZ, z.ptr()->mpZ) > 0 );
  }

inline  bool CGAL_Gmpz::operator>(int i) const
  {
    return ( mpz_cmp_si(ptr()->mpZ, i) > 0 );
  }


inline  bool CGAL_Gmpz::operator>=(const CGAL_Gmpz &z) const
  {
    return ( mpz_cmp(ptr()->mpZ, z.ptr()->mpZ) >= 0 );
  }


inline  bool CGAL_Gmpz::operator>=(int i) const
  {
    return ( mpz_cmp_si(ptr()->mpZ, i) >= 0 );
  }

inline  bool CGAL_Gmpz::operator!=(const CGAL_Gmpz &z) const
  {
    return ! (*this == z);
  }

inline  bool CGAL_Gmpz::operator==(int i) const
  {
    return ( mpz_cmp_si(ptr()->mpZ, i) == 0 );
  }

inline  bool CGAL_Gmpz::operator!=(int i) const
  {
    return ! (*this == i);
  }


inline  CGAL_Gmpz CGAL_Gmpz::operator-() const
  {
    mpz_t res;
    mpz_init(res);
    mpz_neg(res, ptr()->mpZ);
    return CGAL_Gmpz(res);
  }

inline  CGAL_Gmpz CGAL_Gmpz::operator+(const CGAL_Gmpz &z) const
  {
    mpz_t res;
    mpz_init(res);
    mpz_add(res, ptr()->mpZ, z.ptr()->mpZ);
    return CGAL_Gmpz(res);
  }

inline  CGAL_Gmpz CGAL_Gmpz::operator+(int i) const
  {
    if (i>0) {
      mpz_t res;
      mpz_init(res);
      mpz_add_ui(res, ptr()->mpZ, i);
      return CGAL_Gmpz(res);
    }
    return *this + CGAL_Gmpz(i);
  }


inline  CGAL_Gmpz CGAL_Gmpz::operator-(const CGAL_Gmpz &z) const
  {
    mpz_t res;
    mpz_init(res);
    mpz_sub(res, ptr()->mpZ, z.ptr()->mpZ);
    return CGAL_Gmpz(res);
  }

inline  CGAL_Gmpz CGAL_Gmpz::operator-(int i) const
  {
    if (i>0) {
      mpz_t res;
      mpz_init(res);
      mpz_sub_ui(res, ptr()->mpZ, i);
      return CGAL_Gmpz(res);
    }
    return *this - CGAL_Gmpz(i);
  }


inline  CGAL_Gmpz CGAL_Gmpz::operator*(const CGAL_Gmpz &z) const
  {
    mpz_t res;
    mpz_init(res);
    mpz_mul(res, ptr()->mpZ, z.ptr()->mpZ);
    return CGAL_Gmpz(res);
  }


inline  CGAL_Gmpz CGAL_Gmpz::operator*(int i) const
  {
    if (i>0) {
      mpz_t res;
      mpz_init(res);
      mpz_mul_ui(res, ptr()->mpZ, i);
      return CGAL_Gmpz(res);
    }
    return *this * CGAL_Gmpz(i);
  }


inline  CGAL_Gmpz& CGAL_Gmpz::operator*=(const CGAL_Gmpz &z)
  {
      *this = *this * z;
      return *this;
  }


inline  CGAL_Gmpz CGAL_Gmpz::operator*=(int i)
  {
      *this =  *this * CGAL_Gmpz(i); // line changed by Wieger
      return *this;
  }

inline CGAL_Gmpz CGAL_Gmpz::operator/(const CGAL_Gmpz &z) const
  {
    mpz_t res;
    mpz_init(res);
    mpz_tdiv_q(res, ptr()->mpZ, z.ptr()->mpZ);
    return CGAL_Gmpz(res);
  }

inline CGAL_Gmpz CGAL_Gmpz::operator/(int i) const
  {
    if (i>0) {
      mpz_t res;
      mpz_init(res);
      mpz_tdiv_q_ui(res, ptr()->mpZ, i);
      return CGAL_Gmpz(res);
    }
    return *this / CGAL_Gmpz(i);
  }


inline  double CGAL_Gmpz::to_double() const
  {
    return mpz_get_d(ptr()->mpZ);
  }


inline
CGAL_io_Operator
CGAL_io_tag(const CGAL_Gmpz&)
{
    return CGAL_io_Operator();
}


inline  int CGAL_Gmpz::sign() const
  {
    return mpz_sgn(ptr()->mpZ);
  }



inline CGAL_Gmpz operator+(int i, const CGAL_Gmpz &z)
  {
    return z + i;
  }

inline CGAL_Gmpz operator-(int i, const CGAL_Gmpz &z)
  {
    return CGAL_Gmpz(i) - z;
  }

inline CGAL_Gmpz operator*(int i, const CGAL_Gmpz &z)
  {
    return z * i;
  }

inline double CGAL_to_double(const CGAL_Gmpz &z)
{
  return z.to_double();
}


inline
CGAL_Number_tag
CGAL_number_type_tag(const CGAL_Gmpz& )
{
 return CGAL_Number_tag();
}

inline int CGAL_sign(const CGAL_Gmpz &z)
{
  return z.sign();
}

inline bool CGAL_is_valid(const CGAL_Gmpz &)
{
  return true;
}

inline bool CGAL_is_finite(const CGAL_Gmpz &)
{
  return true;
}

inline CGAL_Gmpz CGAL_sqrt(const CGAL_Gmpz &z)
{
  mpz_t res;
  mpz_init(res);
  mpz_sqrt(res, z.ptr()->mpZ);
  return CGAL_Gmpz(res);
}

inline CGAL_Gmpz CGAL_gcd(const CGAL_Gmpz &z1, const CGAL_Gmpz &z2)
{
  mpz_t res;
  mpz_init(res);
  mpz_gcd(res, z1.ptr()->mpZ, z2.ptr()->mpZ);
  return CGAL_Gmpz(res);
}

inline CGAL_Gmpz CGAL_gcd(const CGAL_Gmpz &z, int i)
{
  if (i > 0) {
    mpz_t res;
    mpz_init(res);
    mpz_gcd_ui(res, z.ptr()->mpZ, i);
    return CGAL_Gmpz(res);
  }
  return CGAL_gcd(z, CGAL_Gmpz(i));
}

inline CGAL_Gmpz CGAL_exact_division(const CGAL_Gmpz &z1,
                                       const CGAL_Gmpz &z2)
{
  mpz_t res;
  mpz_init(res);
  mpz_divexact(res, z1.ptr()->mpZ, z2.ptr()->mpZ);
#ifdef CGAL_CHECK_POSTCONDITIONS
  mpz_t prod;
  mpz_init(prod);
  mpz_mul(prod, res, z2.ptr()->mpZ);
  CGAL_kernel_postcondition_msg(mpz_cmp(prod, z1.ptr()->mpZ) == 0,
                                "CGAL_exact_division failed\n");
#endif // CGAL_CHECK_POSTCONDITIONS
  return CGAL_Gmpz(res);
}


inline ostream& operator<<(ostream& os, const CGAL_Gmpz &z)
{
  char *str = new char [mpz_sizeinbase(z.ptr()->mpZ,10) + 2];
  str = mpz_get_str(str, 10, z.ptr()->mpZ);
  os << str ;
  delete str;
  return os;
}

inline istream& operator>>(istream& is, CGAL_Gmpz &z)
{
    int negative = 0;
    const int null = '0';
    char c;

    while (is.get(c) && isspace(c)){
    }

    if (c == '-') {
        negative = 1;
        while (is.get(c) && isspace(c)){
        }
    }

    if (isdigit(c)) {
        z = c - '0';
        while (is.get(c) && isdigit(c)) {
            z = 10*z + (c-null);
        }
    }

    if(is){
        is.putback(c);
    }

    if (CGAL_sign(z) != 0 && negative){
        z = -z;
    }

    return is;
}
#endif // CGAL_GMPZ_H
