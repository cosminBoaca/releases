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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.4-branch/Boolean_set_operations_2/demo/Boolean_set_operations_2/Qt_widget_locate_layer.h $
// $Id: Qt_widget_locate_layer.h 44050 2008-07-09 13:04:14Z guyzucke $
//
//
// Author(s)     : Baruch Zukerman <baruchzu@post.tau.ac.il>

#ifndef CGAL_QT_WIDGET_LOCATE_LAYER_H
#define CGAL_QT_WIDGET_LOCATE_LAYER_H

#include <CGAL/IO/Qt_widget_layer.h>
#include <qcursor.h>

#include "typedefs.h"
#include "Qt_widget_circ_polygon.h"

class MyWindow;

class  Qt_widget_locate_layer : public CGAL::Qt_widget_layer
{
    //Data members
    Polygon_with_holes     m_pgn;

    QWidget::FocusPolicy  m_oldpolicy;
    QCursor               m_oldcursor;
    QCursor               m_cursor;
	  	
    bool m_found_pgn;
	 MyWindow*				 m_window;

  public:
		/*needed to add window param, so set's are recognized
		replaced QObject* parent parameter type
		should be possible to use the inherited Qt_widget* widget
		member field and not a seperate one  */
    Qt_widget_locate_layer(MyWindow* parent = 0, const QCursor c=QCursor(Qt::crossCursor),
                           const char* name = 0 )
      : CGAL::Qt_widget_layer((QObject*)parent, name),
        m_cursor(c),
        m_found_pgn(false),
        m_window(parent)
    {}

    void draw();

  protected:

  void mousePressEvent(QMouseEvent *e);
  void activating();
  void deactivating();

  public:
  void reset();
};

#endif
