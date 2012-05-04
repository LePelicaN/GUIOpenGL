
#include "sceneGraphique.hpp"

SceneGraphique::~SceneGraphique()
{
   for ( ConteneurObjetGraphique::const_iterator objetGraphiqueCourant = objetsGraphiques_.begin();
         objetGraphiqueCourant != objetsGraphiques_.end();
         ++objetGraphiqueCourant )
   {
      delete (*objetGraphiqueCourant);
   }
}

/**
  * /!\ Cette fonction prend la possession de l'objet graphique, il sera detruit
  *     a la destruction de la scene graphique.
  **/
void SceneGraphique::ajouterObjetGraphique( ObjetGraphique * inObjetGraphique )
{
   objetsGraphiques_.push_back( inObjetGraphique );
}

void SceneGraphique::afficherOpenGL() const
{
   for ( ConteneurObjetGraphique::const_iterator objetGraphiqueCourant = objetsGraphiques_.begin();
         objetGraphiqueCourant != objetsGraphiques_.end();
         ++objetGraphiqueCourant )
   {
      (*objetGraphiqueCourant)->afficherOpenGL();
   }
}

void SceneGraphique::afficher( std::ostream & inO ) const
{
   for ( ConteneurObjetGraphique::const_iterator objetGraphiqueCourant = objetsGraphiques_.begin();
         objetGraphiqueCourant != objetsGraphiques_.end();
         ++objetGraphiqueCourant )
   {
      (*objetGraphiqueCourant)->afficher( inO );
   }
}
