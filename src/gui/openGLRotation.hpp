
#ifndef OPENGL_ROTATION_HPP_GUI_OPENGL
#define OPENGL_ROTATION_HPP_GUI_OPENGL

#include <QtCore/QObject>
#include <QtOpenGL>

class OpenGLRotation : public QObject
{
   Q_OBJECT

   public:
      OpenGLRotation();

      void mettreAJour();

      double getAxeX() const;
      double getAxeY() const;
      double getAxeZ() const;

   public slots:
      void setAxeX( double inX );
      void setAxeY( double inY );
      void setAxeZ( double inZ );

   signals :
      void miseAJour();

      void miseAJourAxeX( double outX );
      void miseAJourAxeY( double outY );
      void miseAJourAxeZ( double outZ );

   private :
      double   axeX_;
      double   axeY_;
      double   axeZ_;
};

#endif // OPENGL_ROTATION_HPP_GUI_OPENGL
