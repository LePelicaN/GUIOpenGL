
#include "openGLRotation.hpp"

OpenGLRotation::OpenGLRotation()
   : axeX_( 0 ),
     axeY_( 300 ),
     axeZ_( 0 )
{
}

void OpenGLRotation::mettreAJour()
{
	glMatrixMode(GL_MODELVIEW);
   glRotatef( axeX_, 1.0, 0.0, 0.0 );
   glRotatef( axeY_, 0.0, 1.0, 0.0 );
   glRotatef( axeZ_, 0.0, 0.0, 1.0 );
}

double OpenGLRotation::getAxeX() const
{
   return axeX_;
}

double OpenGLRotation::getAxeY() const
{
   return axeY_;
}

double OpenGLRotation::getAxeZ() const
{
   return axeZ_;
}

void OpenGLRotation::setAxeX( double inX )
{
   if ( axeX_ != inX )
   {
      axeX_ = inX;
      emit miseAJour();
      emit miseAJourAxeX( inX );
   }
}

void OpenGLRotation::setAxeY( double inY )
{
   if ( axeY_ != inY )
   {
      axeY_ = inY;
      emit miseAJour();
      emit miseAJourAxeY( inY );
   }
}

void OpenGLRotation::setAxeZ( double inZ )
{
   if ( axeZ_ != inZ )
   {
      axeZ_ = inZ;
      emit miseAJour();
      emit miseAJourAxeZ( inZ );
   }
}
