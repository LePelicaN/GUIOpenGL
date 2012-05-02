
#include "visualisationOpenGL.hpp"

#include "vueOpenGLWidget.hpp"
#include "parametresAvancesOpenGLWidget.hpp"

#include <QtGui/QHBoxLayout>

VisualisationOpenGL::VisualisationOpenGL()
{
   vueOpenGLWidget_                 = new VueOpenGLWidget();
   parametresAvancesOpenGLWidget_   = new ParametresAvancesOpenGLWidget( vueOpenGLWidget_ );

   QHBoxLayout *  mainLayout  = new QHBoxLayout;
   mainLayout->addWidget( vueOpenGLWidget_ );
   mainLayout->addWidget( parametresAvancesOpenGLWidget_ );

   setLayout( mainLayout );
}
