
#include "openGLCamera.hpp"

OpenGLCamera::OpenGLCamera()
   : positionX_( -8 ),
     positionY_( 7 ),
     positionZ_( 12 ),
     zoom_( 23 ),
     premierPlan_( 0.1 )
{
}

void OpenGLCamera::mettreAJour()
{
   glMatrixMode( GL_PROJECTION );
   gluPerspective( zoom_, 1.0, premierPlan_, 1000 );

	glMatrixMode( GL_MODELVIEW );
	gluLookAt( positionX_, positionY_, positionZ_, 0, 0, 0, 0, 1, 0 );
}

double OpenGLCamera::getPositionX() const
{
   return positionX_;
}

double OpenGLCamera::getPositionY() const
{
   return positionY_;
}

double OpenGLCamera::getPositionZ() const
{
   return positionZ_;
}

double OpenGLCamera::getZoom() const
{
   return zoom_;
}

double OpenGLCamera::getPremierPlan() const
{
   return premierPlan_;
}

void OpenGLCamera::setPositionX( double inX )
{
   if ( positionX_ != inX )
   {
      positionX_ = inX;
      emit miseAJour();
      emit miseAJourPositionX( positionX_ );
   }
}

void OpenGLCamera::setPositionY( double inY )
{
   if ( positionY_ != inY )
   {
      positionY_ = inY;
      emit miseAJour();
      emit miseAJourPositionY( positionY_ );
   }
}

void OpenGLCamera::setPositionZ( double inZ )
{
   if ( positionZ_ != inZ )
   {
      positionZ_ = inZ;
      emit miseAJour();
      emit miseAJourPositionZ( positionZ_ );
   }
}

void OpenGLCamera::setZoom( double inZoom )
{
   if ( zoom_ != inZoom )
   {
      zoom_ = inZoom;
      emit miseAJour();
      emit miseAJourZoom( zoom_ );
   }
}

void OpenGLCamera::setPremierPlan( double inPremierPlan )
{
   if ( premierPlan_ != inPremierPlan )
   {
      premierPlan_ = inPremierPlan;
      emit miseAJour();
      emit miseAJourPremierPlan( premierPlan_ );
   }
}
