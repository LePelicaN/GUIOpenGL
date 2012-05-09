
#include "visualisationOpenGL.hpp"

#include "vueOpenGLWidget.hpp"
#include "parametresAvancesOpenGLWidget.hpp"

#include <QtGui/QHBoxLayout>

VisualisationOpenGL::VisualisationOpenGL( ConteneurObjetGraphique * inObjetsGraphiques )
{
   vueOpenGLWidget_                 = new VueOpenGLWidget( inObjetsGraphiques );
   parametresAvancesOpenGLWidget_   = new ParametresAvancesOpenGLWidget( vueOpenGLWidget_ );

   QHBoxLayout *  mainLayout  = new QHBoxLayout;
   mainLayout->addWidget( vueOpenGLWidget_ );
   mainLayout->addWidget( parametresAvancesOpenGLWidget_ );

   setLayout( mainLayout );
}
