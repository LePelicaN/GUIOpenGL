
#ifndef OPENGL_CAMERA_HPP_GUI_OPENGL
#define OPENGL_CAMERA_HPP_GUI_OPENGL

#include <QGLWidget>

#include <QtCore/QObject>
#include <QtOpenGL>

class OpenGLCamera : public QObject
{
   Q_OBJECT

   public :
      OpenGLCamera();

      void mettreAJour();

      double getPositionX() const;
      double getPositionY() const;
      double getPositionZ() const;

      double getZoom() const;

      double getPremierPlan() const;

   public slots:
      void setPositionX( double inX );
      void setPositionY( double inY );
      void setPositionZ( double inZ );

      void setZoom( double inZoom );

      void setPremierPlan( double inPremierPlan );

   signals :
      void miseAJour();

      void miseAJourPositionX( double outX );
      void miseAJourPositionY( double outY );
      void miseAJourPositionZ( double outZ );

      void miseAJourZoom( double outZoom );

      void miseAJourPremierPlan( double outPremierPlan );

   private :
      double positionX_;
      double positionY_;
      double positionZ_;

      double zoom_;

      double premierPlan_;
};

#endif // OPENGL_CAMERA_HPP_GUI_OPENGL
