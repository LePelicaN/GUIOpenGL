
#ifndef VERTEXARRAYS_HPP_GUI_OPENGL
#define VERTEXARRAYS_HPP_GUI_OPENGL

#include "sommet.hpp"
#include "couleurBasique.hpp"

#include <iostream>

class VertexArrays
{
   public :
      void ajoutSommet( const Sommet & inSommet, const CouleurBasique & inCouleur );

      int getNbSommet() const;

      void afficherOpenGL() const;
      void afficher( std::ostream & inO ) const;

   private :
      std::vector< Sommet >         sommets_;
      std::vector< CouleurBasique > couleurs_;
};

#endif // VERTEXARRAYS_HPP_GUI_OPENGL
