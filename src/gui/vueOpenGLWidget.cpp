
#include "vueOpenGLWidget.hpp"

#include <QtGui>
#include <QtOpenGL>

#include <math.h>


QColor qtPurple = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);
QColor qtBeige = QColor::fromRgb( 224, 189, 152, 0 );

//! [6]
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
//! [6]


#include <iostream>
void VueOpenGLWidget::paintGL()
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity( );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   openGLCamera_.mettreAJour();

   openGLRotation_.mettreAJour();

   // glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
   // glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
   // glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);

   OpenGLLumiere::MettreAJourGeneral();
   openGLLumiere_.mettreAJour();

   
   
   
   // -------------- Debut ------------------ //
    /* nombre de sommets */
    #define N_VERTS 4
    
    /* nombre de variables dans un sommet de type position */
    #define P_SIZE 2
    
    /* nombre de variables dans un sommet de type couleur */
    #define C_SIZE 3
    
    /* tableau des donnees */
    float pos[N_VERTS*P_SIZE] =
    {
        -0.8, -0.8,     /* position 0 */
        0.8, -0.8,      /* position 1 */
        0.8, 0.8,       /* position 2 */
        -0.8, 0.8       /* position 3 */
    };
    
    float colors[N_VERTS*C_SIZE] =
    {
        1.0, 0.0, 0.0,  /* couleur 0 */
        0.0, 1.0, 0.0,  /* couleur 1 */
        0.0, 0.0, 1.0,  /* couleur 2 */
        1.0, 1.0, 1.0   /* couleur 3 */
    };
    
    unsigned int index[N_VERTS] =
    {
        1, 0, 3, 2
    };
        glClear(GL_COLOR_BUFFER_BIT);
       
        /* activation des tableaux de sommets */
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        
        /* envoi des donnees */
        glVertexPointer(P_SIZE, GL_FLOAT, 0, pos);
        glColorPointer(C_SIZE, GL_FLOAT, 0, colors);
        
        /* rendu indice */
        glDrawElements(GL_LINE_STRIP, N_VERTS, GL_UNSIGNED_INT, index);
        
        /* desactivation des tableaux de sommet */
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
        
        /* on échange les tampons */
        glFlush();
        //SDL_GL_SwapBuffers();
    


   // -------------- Fin ------------------ //
   
   
   
   
//   sceneAffichee_.afficherOpenGL();
}
//! [7]




//! [8]
void VueOpenGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#else
    glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void VueOpenGLWidget::mousePressEvent(QMouseEvent *event)
{
   lastPos = event->pos();
}

void VueOpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
   int dx = event->x() - lastPos.x();
   int dy = event->y() - lastPos.y();

   if (event->buttons() & Qt::LeftButton)
   {
      openGLRotation_.setAxeX( openGLRotation_.getAxeX() + 0.5 * dy);
      openGLRotation_.setAxeY( openGLRotation_.getAxeY() + 0.5 * dx);
   }
   else if (event->buttons() & Qt::RightButton)
   {
      openGLRotation_.setAxeX( openGLRotation_.getAxeX() + 0.5 * dy );
      openGLRotation_.setAxeZ( openGLRotation_.getAxeZ() + 0.5 * dx );
   }
   lastPos = event->pos();
}

QSize VueOpenGLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}
//! [2]

//! [3]
QSize VueOpenGLWidget::sizeHint() const
//! [3] //! [4]
{
    return QSize(400, 400);
}
//! [4]

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

//! [5]
void VueOpenGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}
//! [5]

void VueOpenGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void VueOpenGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

//! [0]
VueOpenGLWidget::VueOpenGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
   connect( &openGLCamera_, SIGNAL( miseAJour() ),
            this,           SLOT(   update() ) );
   connect( &openGLRotation_, SIGNAL( miseAJour() ),
            this,             SLOT(   update() ) );
   connect( &openGLLumiere_, SIGNAL( miseAJour() ),
            this,            SLOT(   update() ) );

   // premierPlan_ = 1;
    xRot = 0;
    yRot = 0;
    zRot = 0;

    qtGreen = QColor::fromCmykF(0.40, 0.0, 1.0, 0.0);
    qtPurple = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);
    
    coordFaceRouge[ 0 ][ 0 ] = 1;
    coordFaceRouge[ 0 ][ 1 ] = 1;
    coordFaceRouge[ 0 ][ 2 ] = 1;
    coordFaceRouge[ 1 ][ 0 ] = 1;
    coordFaceRouge[ 1 ][ 1 ] = 1;
    coordFaceRouge[ 1 ][ 2 ] = -1;
    coordFaceRouge[ 2 ][ 0 ] = -1;
    coordFaceRouge[ 2 ][ 1 ] = 1;
    coordFaceRouge[ 2 ][ 2 ] = -1;
    coordFaceRouge[ 3 ][ 0 ] = -1;
    coordFaceRouge[ 3 ][ 1 ] = 1;
    coordFaceRouge[ 3 ][ 2 ] = 1;
    
    coordFaceVerte[ 0 ][ 0 ] = 1;
    coordFaceVerte[ 0 ][ 1 ] = -1;
    coordFaceVerte[ 0 ][ 2 ] = 1;
    coordFaceVerte[ 1 ][ 0 ] = 1;
    coordFaceVerte[ 1 ][ 1 ] = -1;
    coordFaceVerte[ 1 ][ 2 ] = -1;
    coordFaceVerte[ 2 ][ 0 ] = 1;
    coordFaceVerte[ 2 ][ 1 ] = 1;
    coordFaceVerte[ 2 ][ 2 ] = -1;
    coordFaceVerte[ 3 ][ 0 ] = 1;
    coordFaceVerte[ 3 ][ 1 ] = 1;
    coordFaceVerte[ 3 ][ 2 ] = 1;
    
    coordFaceBleu[ 0 ][ 0 ] = -1;
    coordFaceBleu[ 0 ][ 1 ] = -1;
    coordFaceBleu[ 0 ][ 2 ] = 1;
    coordFaceBleu[ 1 ][ 0 ] = -1;
    coordFaceBleu[ 1 ][ 1 ] = -1;
    coordFaceBleu[ 1 ][ 2 ] = -1;
    coordFaceBleu[ 2 ][ 0 ] = 1;
    coordFaceBleu[ 2 ][ 1 ] = -1;
    coordFaceBleu[ 2 ][ 2 ] = -1;
    coordFaceBleu[ 3 ][ 0 ] = 1;
    coordFaceBleu[ 3 ][ 1 ] = -1;
    coordFaceBleu[ 3 ][ 2 ] = 1;

}
