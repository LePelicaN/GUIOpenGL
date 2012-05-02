
#include "cube.hpp"

#include <QtOpenGL>

#include <iostream>
#include <cassert>

Cube::Cube( Sommet inCoinSupDroitDevant, double inTailleCote )
{
   assert( inTailleCote > 0 );
   int indiceSommet = 0;
   for( int decalageDevant = 0; decalageDevant > -2; --decalageDevant )
   {
      for( int decalageHaut = 0; decalageHaut > -2; --decalageHaut )
      {
         for( int decalageDroit = 0; decalageDroit > -2; --decalageDroit )
         {
            sommets_[ indiceSommet++ ] = inCoinSupDroitDevant + Sommet( inTailleCote * decalageDroit,
                                                                        inTailleCote * decalageHaut,
                                                                        inTailleCote * decalageDevant );
         }
      }
   }
}
void Cube::afficherOpenGL() const
{
   afficherFaceOpenGL( 0, 2, 6, 4 ); // Face droite
   afficherFaceOpenGL( 0, 4, 5, 1 ); // Face haut
   afficherFaceOpenGL( 1, 5, 7, 3 ); // Face gauche
   afficherFaceOpenGL( 2, 3, 7, 6 ); // Face bas
   afficherFaceOpenGL( 0, 1, 3, 2 ); // Face devant
   afficherFaceOpenGL( 4, 6, 7, 5 ); // Face derriere
}
void Cube::afficher( std::ostream & inO ) const
{
   for ( int indiceSommet = 0; indiceSommet < 8; ++indiceSommet )
   {
      sommets_[ indiceSommet ].afficher( inO );
   }
}

void Cube::afficherFaceOpenGL( int inIndiceSommet1,
                               int inIndiceSommet2,
                               int inIndiceSommet3,
                               int inIndiceSommet4 ) const
{
   sommets_[ inIndiceSommet1 ].afficherOpenGL();
   sommets_[ inIndiceSommet2 ].afficherOpenGL();
   sommets_[ inIndiceSommet3 ].afficherOpenGL();
   sommets_[ inIndiceSommet4 ].afficherOpenGL();
}
