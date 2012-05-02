
#ifndef COULEURBASIQUE_HPP_GUI_OPENGL
#define COULEURBASIQUE_HPP_GUI_OPENGL

#include <QtOpenGL>

#include <iostream>

class CouleurBasique
{
   public :
      CouleurBasique();
      CouleurBasique( float inR, float inG, float inB );
      CouleurBasique( const CouleurBasique & inCouleur );

      void afficherOpenGL() const;
      void afficher( std::ostream & inO ) const;

   private :
      GLfloat rgb_[ 3 ];
};

#endif // COULEURBASIQUE_HPP_GUI_OPENGL
