
#include "vertexArrays.hpp"

#include <QtOpenGL>

void VertexArrays::ajoutSommet( const Sommet & inSommet, const CouleurBasique & inCouleur )
{
   sommets_.push_back( inSommet );
   couleurs_.push_back( inCouleur );
   indices_.push_back( indices_.size() );
}

int VertexArrays::getNbSommet() const
{
   return sommets_.size();
}

void VertexArrays::afficherOpenGL() const
{
   glClear( GL_COLOR_BUFFER_BIT );

   /* activation des tableaux de sommets */
   glEnableClientState( GL_VERTEX_ARRAY );
   glEnableClientState( GL_COLOR_ARRAY );

   /* envoi des donnees */
   glVertexPointer( Sommet::NbCoordonnees_,        GL_FLOAT, 0, &( sommets_[ 0 ] ) );
   glColorPointer( CouleurBasique::NbComposantes_, GL_FLOAT, 0, &( couleurs_[ 0 ] ) );

   /* rendu indice */
   glDrawElements( GL_LINE_STRIP, sommets_.size(), GL_UNSIGNED_INT, &( indices_[ 0 ] ) );

   /* desactivation des tableaux de sommet */
   glDisableClientState( GL_COLOR_ARRAY );
   glDisableClientState( GL_VERTEX_ARRAY );

   /* on échange les tampons */
   glFlush();
   //SDL_GL_SwapBuffers();
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
