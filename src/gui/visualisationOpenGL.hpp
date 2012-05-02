
#ifndef VISUALISATION_OPENGL_HPP_GUI_OPENGL
#define VISUALISATION_OPENGL_HPP_GUI_OPENGL

#include <QtGui/QWidget>

class ParametresAvancesOpenGLWidget;
class VueOpenGLWidget;

class VisualisationOpenGL : public QWidget
{
   Q_OBJECT

   public:
      VisualisationOpenGL();

   private:
      VueOpenGLWidget *                vueOpenGLWidget_;
      ParametresAvancesOpenGLWidget *  parametresAvancesOpenGLWidget_;
};

#endif // VISUALISATION_OPENGL_HPP_GUI_OPENGL
