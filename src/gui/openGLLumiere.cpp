
#include "openGLLumiere.hpp"

bool OpenGLLumiere::ActiveGeneral_ = true;

OpenGLLumiere::OpenGLLumiere( unsigned int inIndice )
   : indice_( inIndice ),
     active_( true )
{
     position_[ 0 ] = 4.f;
     position_[ 1 ] = 2.f;
     position_[ 2 ] = 3.f;
     position_[ 3 ] = 0.f;

     ambient_[ 0 ] = 0.f;
     ambient_[ 1 ] = 0.f;
     ambient_[ 2 ] = 0.f;
     ambient_[ 3 ] = 0.f;

     diffuse_[ 0 ] = 1.f;
     diffuse_[ 1 ] = 1.f;
     diffuse_[ 2 ] = 1.f;
     diffuse_[ 3 ] = 1.f;

     specular_[ 0 ] = 1.f;
     specular_[ 1 ] = 1.f;
     specular_[ 2 ] = 1.f;
     specular_[ 3 ] = 1.f;
}

void OpenGLLumiere::InitialiserGeneral()
{
   MettreAJourGeneral();
}

void OpenGLLumiere::initialiser()
{
   mettreAJour();

	glLightfv( indice_, GL_AMBIENT, ambient_ );
	glLightfv( indice_, GL_DIFFUSE, diffuse_ );
}

void OpenGLLumiere::MettreAJourGeneral()
{
	glMatrixMode( GL_MODELVIEW );
   if ( ActiveGeneral_ )
   {
      glEnable( GL_LIGHTING );
   }
   else
   {
      glDisable( GL_LIGHTING );
   }
}

void OpenGLLumiere::mettreAJour()
{
	glMatrixMode( GL_MODELVIEW );
   if ( active_ )
   {
      glEnable( indice_ );
   }
   else
   {
      glDisable( indice_ );
   }
	glLightfv( indice_, GL_POSITION, position_ );
}

void OpenGLLumiere::SetActivationGeneral( bool inActive )
{
   ActiveGeneral_ = inActive;
}

void OpenGLLumiere::setActivation( bool inActive )
{
   active_  = inActive;
   emit miseAJour();
}

void OpenGLLumiere::setPositionX( double inX )
{
   if ( position_[ 0 ] != static_cast< GLfloat >( inX ) )
   {
      position_[ 0 ] = inX;
      emit miseAJour();
      emit miseAJourPositionX( position_[ 0 ] );
   }
}

void OpenGLLumiere::setPositionY( double inY )
{
   if ( position_[ 1 ] != static_cast< GLfloat >( inY ) )
   {
      position_[ 1 ] = inY;
      emit miseAJour();
      emit miseAJourPositionY( position_[ 1 ] );
   }
}

void OpenGLLumiere::setPositionZ( double inZ )
{
   if ( position_[ 2 ] != static_cast< GLfloat >( inZ ) )
   {
      position_[ 2 ] = inZ;
      emit miseAJour();
      emit miseAJourPositionZ( position_[ 2 ] );
   }
}
