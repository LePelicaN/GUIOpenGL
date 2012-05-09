
#ifndef OPENGL_WIDGET_HPP_GUI_OPENGL
#define OPENGL_WIDGET_HPP_GUI_OPENGL

#include "openGLCamera.hpp"
#include "openGLRotation.hpp"
#include "openGLLumiere.hpp"
#include "../scene/objetGraphique.hpp"

#include <QGLWidget>

#include <vector>

class VueOpenGLWidget : public QGLWidget
{
   Q_OBJECT

   public :
      typedef std::vector< ObjetGraphique * > ConteneurObjetGraphique;

      VueOpenGLWidget( ConteneurObjetGraphique * inObjetsGraphiques, QWidget * inParent = 0 );

      const QObject & getOpenGLCamera() const;
      const QObject & getOpenGLRotation() const;
      const QObject & getOpenGLLumiere() const;

      QSize minimumSizeHint() const;
      QSize sizeHint() const;

   protected :
      void initializeGL();
      void paintGL();
      void resizeGL( int inWidth, int inHeight );

      void mousePressEvent( QMouseEvent * inMouseEvent );
      void mouseMoveEvent( QMouseEvent * inMouseEvent );

   private :
      OpenGLCamera   openGLCamera_;
      OpenGLRotation openGLRotation_;
      OpenGLLumiere  openGLLumiere_;

      QPoint lastPos;

      ConteneurObjetGraphique *   objetsGraphiques_;
};

#endif // OPENGL_WIDGET_HPP_GUI_OPENGL
