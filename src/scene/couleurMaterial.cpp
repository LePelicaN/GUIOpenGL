
#include "couleurMaterial.hpp"

#include <iostream>

CouleurMaterial::CouleurMaterial()
{}

CouleurMaterial::CouleurMaterial( GLfloat inSpecular[ 4 ],
                                  GLfloat inDiffuse[ 4 ],
                                  GLfloat inAmbient[ 4 ],
                                  GLfloat inShininess[ 1 ] )
{
   memcpy( specular_, inSpecular, sizeof( GLfloat ) * 4 );
   memcpy( diffuse_, inDiffuse, sizeof( GLfloat ) * 4 );
   memcpy( ambient_, inAmbient, sizeof( GLfloat ) * 4 );
   memcpy( shininess_, inShininess, sizeof( GLfloat ) );
}

CouleurMaterial::CouleurMaterial( const CouleurMaterial & inCouleur )
{
   memcpy( specular_, inCouleur.specular_, sizeof( GLfloat ) * 4 );
   memcpy( diffuse_, inCouleur.diffuse_, sizeof( GLfloat ) * 4 );
   memcpy( ambient_, inCouleur.ambient_, sizeof( GLfloat ) * 4 );
   memcpy( shininess_, inCouleur.shininess_, sizeof( GLfloat ) );
}

void CouleurMaterial::afficherOpenGL() const
{
   glMaterialfv( GL_FRONT, GL_SPECULAR, specular_ );
   glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse_ );
   glMaterialfv( GL_FRONT, GL_AMBIENT, ambient_ );
   glMaterialfv( GL_FRONT, GL_SHININESS, shininess_ );
}

void CouleurMaterial::afficher() const
{
   std::cout << specular_[ 0 ] << " " << specular_[ 1 ] << " " << specular_[ 2 ] << " " << specular_[ 3 ] << std::endl;
   std::cout << diffuse_[ 0 ] << " " << diffuse_[ 1 ] << " " << diffuse_[ 2 ] << " " << diffuse_[ 3 ] << std::endl;
   std::cout << ambient_[ 0 ] << " " << ambient_[ 1 ] << " " << ambient_[ 2 ] << " " << ambient_[ 3 ] << std::endl;
   std::cout << shininess_[ 0 ] << std::endl;
}

bool CouleurMaterial::estValid() const
{
   return true;
}

bool InvalidCouleurMaterial::estValid() const
{
   return false;
}
