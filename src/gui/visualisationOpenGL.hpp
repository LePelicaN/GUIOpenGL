
#ifndef VISUALISATION_OPENGL_HPP_GUI_OPENGL
#define VISUALISATION_OPENGL_HPP_GUI_OPENGL

#include "vueOpenGLWidget.hpp"

#include <QtGui/QWidget>

class ParametresAvancesOpenGLWidget;

class VisualisationOpenGL : public QWidget
{
   Q_OBJECT

   public:
      typedef VueOpenGLWidget::ConteneurObjetGraphique ConteneurObjetGraphique;
      VisualisationOpenGL( ConteneurObjetGraphique * inObjetsGraphiques );

   private:
      VueOpenGLWidget *                vueOpenGLWidget_;
      ParametresAvancesOpenGLWidget *  parametresAvancesOpenGLWidget_;
};

#endif // VISUALISATION_OPENGL_HPP_GUI_OPENGL
