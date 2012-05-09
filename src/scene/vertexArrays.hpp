
#ifndef VERTEXARRAYS_HPP_GUI_OPENGL
#define VERTEXARRAYS_HPP_GUI_OPENGL

#include "objetGraphique.hpp"
#include "sommet.hpp"
#include "couleurBasique.hpp"

#include <iostream>

class VertexArrays : public ObjetGraphique
{
   public :
      void ajoutSommet( const Sommet & inSommet, const CouleurBasique & inCouleur );

      int getNbSommet() const;

      void afficherOpenGL() const;
      void afficher( std::ostream & inO ) const;

   private :
      std::vector< Sommet >         sommets_;
      std::vector< CouleurBasique > couleurs_;
      std::vector< unsigned int >   indices_;
};

#endif // VERTEXARRAYS_HPP_GUI_OPENGL
