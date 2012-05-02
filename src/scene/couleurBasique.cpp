
#include "couleurBasique.hpp"

#include <iostream>

CouleurBasique::CouleurBasique()
{}

CouleurBasique::CouleurBasique( float inR, float inG, float inB )
{
   rgb_[ 0 ] = inR;
   rgb_[ 1 ] = inG;
   rgb_[ 2 ] = inB;
}

CouleurBasique::CouleurBasique( const CouleurBasique & inCouleur )
{
   rgb_[ 0 ] = inCouleur.rgb_[ 0 ];
   rgb_[ 1 ] = inCouleur.rgb_[ 1 ];
   rgb_[ 2 ] = inCouleur.rgb_[ 2 ];
}

void CouleurBasique::afficherOpenGL() const
{
   // glMaterialfv( GL_FRONT, GL_SPECULAR, specular_ );
   // glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse_ );
   // glMaterialfv( GL_FRONT, GL_AMBIENT, ambient_ );
   // glMaterialfv( GL_FRONT, GL_SHININESS, shininess_ );
}

void CouleurBasique::afficher( std::ostream & inO ) const
{
   inO << "[ " << rgb_[ 0 ] << "; " << rgb_[ 1 ] << "; " << rgb_[ 2 ] << " ]";
}
