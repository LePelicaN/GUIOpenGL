
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
   glColor3f( rgb_[ 0 ], rgb_[ 1 ], rgb_[ 2 ] );
}

void CouleurBasique::afficher( std::ostream & inO ) const
{
   inO << "[ " << rgb_[ 0 ] << "; " << rgb_[ 1 ] << "; " << rgb_[ 2 ] << " ]";
}
