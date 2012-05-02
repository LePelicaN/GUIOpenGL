
#ifndef OPENGL_LUMIERE_HPP_GUI_OPENGL
#define OPENGL_LUMIERE_HPP_GUI_OPENGL

#include <QtCore/QObject>
#include <QtOpenGL>

class OpenGLLumiere : public QObject
{
   Q_OBJECT

   public:
      OpenGLLumiere( unsigned int inIndice = GL_LIGHT0 );

      static void InitialiserGeneral();
      void initialiser();
      static void MettreAJourGeneral();
      void mettreAJour();

   public slots:
      static void SetActivationGeneral( bool inActive );

      void setActivation( bool inActive );

      void setPositionX( double inX );
      void setPositionY( double inY );
      void setPositionZ( double inZ );

   signals :
      void miseAJour();

      void miseAJourPositionX( double outX );
      void miseAJourPositionY( double outY );
      void miseAJourPositionZ( double outZ );

   private:
      static bool ActiveGeneral_;

      unsigned int   indice_;
      bool  active_;
      GLfloat  position_[ 4 ];
      GLfloat  ambient_[ 4 ];
      GLfloat  diffuse_[ 4 ];
      GLfloat  specular_[ 4 ];
};

#endif // OPENGL_LUMIERE_HPP_GUI_OPENGL
