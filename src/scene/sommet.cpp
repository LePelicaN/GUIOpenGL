
#include "sommet.hpp"

#include <QtOpenGL>

#include <iostream>

Sommet::Sommet()
{
}

Sommet::Sommet( double inCoordonneeX, double inCoordonneeY, double inCoordonneeZ )
   : coordonneeX_( inCoordonneeX ),
     coordonneeY_( inCoordonneeY ),
     coordonneeZ_( inCoordonneeZ )
{
}

void Sommet::afficherOpenGL() const
{
   glVertex3d( coordonneeX_, coordonneeY_, coordonneeZ_ );
}

void Sommet::afficher() const
{
   std::cout << "[ "
             << coordonneeX_ << "; "
             << coordonneeY_ << "; "
             << coordonneeZ_ << " ]"
             << std::endl;
}

Sommet operator+( const Sommet & inSommetGauche, const Sommet & inSommetDroit )
{
   Sommet  outResultat  = inSommetGauche;

   outResultat.coordonneeX_ += inSommetDroit.coordonneeX_;
   outResultat.coordonneeY_ += inSommetDroit.coordonneeY_;
   outResultat.coordonneeZ_ += inSommetDroit.coordonneeZ_;

   return outResultat;
}
