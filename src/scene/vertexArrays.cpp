
#include "vertexArrays.hpp"

#include <QtOpenGL>

void VertexArrays::ajoutSommet( const Sommet & inSommet, const CouleurBasique & inCouleur )
{
   sommets_.push_back( inSommet );
   couleurs_.push_back( inCouleur );
}

int VertexArrays::getNbSommet() const
{
   return sommets_.size();
}

void VertexArrays::afficherOpenGL() const
{
//   glVertex3d( coordonneeX_, coordonneeY_, coordonneeZ_ );
}

void VertexArrays::afficher( std::ostream & inO ) const
{
   std::vector< Sommet >::const_iterator   sommetCourant    = sommets_.begin();
   std::vector< CouleurBasique >::const_iterator   couleurCourante  = couleurs_.begin();

   assert( sommets_.size() == couleurs_.size() );
   while ( sommetCourant != sommets_.end() )
   {
      sommetCourant->afficher( inO );
      couleurCourante->afficher( inO );
      inO << std::endl;

      ++sommetCourant;
      ++couleurCourante;
   }
}
