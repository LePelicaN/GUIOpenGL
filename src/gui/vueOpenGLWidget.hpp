
#ifndef OPENGL_WIDGET_HPP_GUI_OPENGL
#define OPENGL_WIDGET_HPP_GUI_OPENGL

#include <QGLWidget>

#include "openGLCamera.hpp"
#include "openGLRotation.hpp"
#include "openGLLumiere.hpp"

class VueOpenGLWidget : public QGLWidget
{
    Q_OBJECT

public:
    VueOpenGLWidget(QWidget *parent = 0);
    // ~VueOpenGLWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

   const QObject & getOpenGLCamera() const
   { return openGLCamera_; }

   const QObject & getOpenGLRotation() const
   { return openGLRotation_; }

   const QObject & getOpenGLLumiere() const
   { return openGLLumiere_; }

public slots:
   void setXRotation(int angle);
   void setYRotation(int angle);
   void setZRotation(int angle);

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
   OpenGLCamera   openGLCamera_;
   OpenGLRotation openGLRotation_;
   OpenGLLumiere  openGLLumiere_;

   void createConnexionLumiere();

    int xRot;
    int yRot;
    int zRot;
    QPoint lastPos;
    QColor qtGreen;
    QColor qtPurple;
    
    
    double coordFaceRouge[ 4 ][ 3 ];
    double coordFaceVerte[ 4 ][ 3 ];
    double coordFaceBleu[ 4 ][ 3 ];
};

#endif // OPENGL_WIDGET_HPP_GUI_OPENGL
