
#ifndef CUBE_HPP_GUI_OPENGL
#define CUBE_HPP_GUI_OPENGL

#include "objetGraphique.hpp"
#include "sommet.hpp"

#include <iostream>

class Cube : public ObjetGraphique
{
   public :
      Cube( Sommet inCoinSupDroitDevant, double inTailleCote );
      void afficherOpenGL() const;
      void afficher( std::ostream & inO ) const;

   private :
      Sommet   sommets_[ 8 ];
      // +x -y +z - droite haut devant : 0
      // -x +y +z - gauche haut devant : 1
      // +x -y +z - droite bas  devant : 2
      // -x -y +z - gauche bas  devant : 3
      // +x +y -z - droite haut derriere : 4
      // -x +y -z - gauche haut derriere : 5
      // +x -y -z - droite bas  derriere : 6
      // -x -y -z - gauche bas  derriere : 7

      void afficherFaceOpenGL( int inIndiceSommet1,
                               int inIndiceSommet2,
                               int inIndiceSommet3,
                               int inIndiceSommet4 ) const;
};

#endif // CUBE_HPP_GUI_OPENGL
