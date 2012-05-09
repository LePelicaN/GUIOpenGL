
#include "vueOpenGLWidget.hpp"

#include <QtGui>
#include <QtOpenGL>

// #include "vertexArrays.hpp"

VueOpenGLWidget::VueOpenGLWidget( ConteneurObjetGraphique * inObjetsGraphiques, QWidget * inParent )
   : QGLWidget( QGLFormat( QGL::SampleBuffers ), inParent ),
     objetsGraphiques_( inObjetsGraphiques )
{
   connect( &openGLCamera_, SIGNAL( miseAJour() ),
            this,           SLOT(   update() ) );
   connect( &openGLRotation_, SIGNAL( miseAJour() ),
            this,             SLOT(   update() ) );
   connect( &openGLLumiere_, SIGNAL( miseAJour() ),
            this,            SLOT(   update() ) );
}

const QObject & VueOpenGLWidget::getOpenGLCamera() const
{
   return openGLCamera_;
}

const QObject & VueOpenGLWidget::getOpenGLRotation() const
{
   return openGLRotation_;
}

const QObject & VueOpenGLWidget::getOpenGLLumiere() const
{
   return openGLLumiere_;
}

QSize VueOpenGLWidget::minimumSizeHint() const
{
    return QSize( 50, 50 );
}

QSize VueOpenGLWidget::sizeHint() const
{
    return QSize( 400, 400 );
}

void VueOpenGLWidget::initializeGL()
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   qglClearColor(Qt::black);

   glEnable( GL_DEPTH_TEST );

   OpenGLLumiere::InitialiserGeneral();
   openGLLumiere_.initialiser();
}

void VueOpenGLWidget::paintGL()
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity( );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   openGLCamera_.mettreAJour();
   openGLRotation_.mettreAJour();
   OpenGLLumiere::MettreAJourGeneral();
   openGLLumiere_.mettreAJour();

   for ( ConteneurObjetGraphique::const_iterator objetGraphiqueCourant = objetsGraphiques_->begin();
         objetGraphiqueCourant != objetsGraphiques_->end();
         ++objetGraphiqueCourant )
   {
      (*objetGraphiqueCourant)->afficherOpenGL();
   }
   
   // VertexArrays   vertexArrays;
   // vertexArrays.ajoutSommet( Sommet( 0.8, -0.8, 0 ), CouleurBasique( 0.0, 1.0, 0.0 ) );
   // vertexArrays.ajoutSommet( Sommet( -0.8, -0.8, 0 ), CouleurBasique( 1.0, 0.0, 0.0 ) );
   // vertexArrays.ajoutSommet( Sommet( -0.8, 0.8, 0 ), CouleurBasique( 1.0, 1.0, 1.0 ) );
   // vertexArrays.ajoutSommet( Sommet( 0.8, 0.8, 0 ), CouleurBasique( 0.0, 0.0, 1.0 ) );
   // vertexArrays.ajoutSommet( Sommet( 2, 0.8, 0 ), CouleurBasique( 0.0, 0.0, 1.0 ) );
   // vertexArrays.afficherOpenGL();

//   sceneAffichee_.afficherOpenGL();
}

void VueOpenGLWidget::resizeGL( int inWidth, int inHeight )
{
   int side = qMin( inWidth, inHeight );
   glViewport( ( inWidth - side ) / 2, ( inHeight - side ) / 2, side, side );

   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
#ifdef QT_OPENGL_ES_1
   glOrthof(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#else
   glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#endif
   glMatrixMode( GL_MODELVIEW );
}

void VueOpenGLWidget::mousePressEvent( QMouseEvent * inMouseEvent )
{
   lastPos = inMouseEvent->pos();
}

void VueOpenGLWidget::mouseMoveEvent( QMouseEvent * inMouseEvent )
{
   int dx = inMouseEvent->x() - lastPos.x();
   int dy = inMouseEvent->y() - lastPos.y();

   if ( inMouseEvent->buttons() & Qt::LeftButton )
   {
      openGLRotation_.setAxeX( openGLRotation_.getAxeX() + 0.5 * dy );
      openGLRotation_.setAxeY( openGLRotation_.getAxeY() + 0.5 * dx );
   }
   else if ( inMouseEvent->buttons() & Qt::RightButton )
   {
      openGLRotation_.setAxeX( openGLRotation_.getAxeX() + 0.5 * dy );
      openGLRotation_.setAxeZ( openGLRotation_.getAxeZ() + 0.5 * dx );
   }
   lastPos = inMouseEvent->pos();
}
