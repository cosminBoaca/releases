// Copyright (c) 2005  Tel-Aviv University (Israel).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.3-branch/Arrangement_2/include/CGAL/IO/Arr_with_history_iostream.h $
// $Id: Arr_with_history_iostream.h 28567 2006-02-16 14:30:13Z lsaboret $
// 
//
// Author(s)     : Ron Wein           <wein@post.tau.ac.il>

#ifndef CGAL_ARR_WITH_HISTORY_IOSTREAM_H
#define CGAL_ARR_WITH_HISTORY_IOSTREAM_H

/*! \file
 * Definition of the I/O operators for the
 * Arrangement_with_history_2<Traits,Dcel> class.
 */

#include <CGAL/Arrangement_with_history_2.h>
#include <CGAL/IO/Arr_with_history_text_formatter.h>
#include <CGAL/IO/Arr_text_formatter.h>
#include <CGAL/IO/Arr_with_history_2_writer.h>
#include <CGAL/IO/Arr_with_history_2_reader.h>
#include <iostream>

CGAL_BEGIN_NAMESPACE

/*!
 * Write an arrangement with history to an output stream using a given
 * formatter.
 * \param arr The arrangement-with-history instance.
 * \param os The output stream.
 * \param format The formatter.
 */
template <class Traits, class Dcel, class Formatter>
std::ostream& write (const Arrangement_with_history_2<Traits,Dcel>& arr,
                     std::ostream& os, 
                     Formatter& format)
{
  typedef Arrangement_with_history_2<Traits,Dcel>        Arr_with_history_2;
  typedef Arr_with_history_2_writer<Arr_with_history_2>  Arr_writer;

  Arr_writer      writer (arr);

  format.set_out (os);
  writer (format);
  return (os);
}

/*!
 * Output operator (importer).
 * \param os The output stream.
 * \param arr The arrangement-with-history instance.
 */
template <class Traits, class Dcel>
std::ostream& operator<< (std::ostream& os, 
                          const Arrangement_with_history_2<Traits,Dcel>& arr)
{
  typedef Arrangement_with_history_2<Traits,Dcel>        Arr_with_history_2;
  typedef Arr_with_history_2_writer<Arr_with_history_2>  Arr_writer;
  typedef Arr_with_history_text_formatter
    <Arr_text_formatter<Arr_with_history_2> >            Text_formatter;

  Text_formatter  text_format (os);
  Arr_writer      writer (arr);

  writer (text_format);
  return (os);
}

/*!
 * Read an arrangement with history from an input stream using a given
 * formatter.
 * \param arr The arrangement-with-history instance.
 * \param os The output stream.
 * \param format The formatter.
 */
template <class Traits, class Dcel, class Formatter>
std::istream& read (Arrangement_with_history_2<Traits,Dcel>& arr,
                    std::istream& is, 
                    Formatter& format)
{
  typedef Arrangement_with_history_2<Traits,Dcel>        Arr_with_history_2;
  typedef Arr_with_history_2_reader<Arr_with_history_2>  Arr_reader;

  Arr_reader      reader (arr);

  format.set_in (is);
  reader (format);
  return (is);
}

/*!
 * Output operator (exporter).
 * \param is The input stream.
 * \param arr The arrangement-with-history instance.
 */
template <class Traits, class Dcel>
std::istream& operator>> (std::istream& is, 
                          Arrangement_with_history_2<Traits,Dcel>& arr)
{
  typedef Arrangement_with_history_2<Traits,Dcel>        Arr_with_history_2;
  typedef Arr_with_history_2_reader<Arr_with_history_2>  Arr_reader;
  typedef Arr_with_history_text_formatter
    <Arr_text_formatter<Arr_with_history_2> >            Text_formatter;

  Text_formatter  text_format (is);
  Arr_reader      reader (arr);
  
  reader (text_format);
  return (is);
}

CGAL_END_NAMESPACE

#endif
