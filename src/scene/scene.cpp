
#include "scene.hpp"

#include <fstream>
#include <iostream>

void Scene::ajouterCube( Cube inCube, Etat inEtat )
{
   cubes_.push_back( std::make_pair( inCube, inEtat ) );
}

void Scene::ajouterCouleur( const std::string & inNomCouleur, const CouleurMaterial & inCouleur )
{
   couleurs_[ inNomCouleur ] = inCouleur;
}

void Scene::ajouterCorrespondance( Etat inEtat, const std::string & inNomCouleur )
{
   ConteneurCouleur::const_iterator  couleurTrouve  = couleurs_.find( inNomCouleur );
   if ( couleurTrouve != couleurs_.end() )
   {
      correspondancesEtatCouleur_[ inEtat ] = couleurTrouve->second;
   }
   else
   {
      correspondancesEtatCouleur_[ inEtat ] = InvalidCouleurMaterial();
      // TODO: logger l'erreur
   }
}

void Scene::afficherOpenGL() const
{
   glBegin(GL_QUADS);
      for ( ConteneurCubeEtat::const_iterator cubeCourant = cubes_.begin();
            cubeCourant != cubes_.end();
            ++cubeCourant )
      {
         ConteneurEtatCouleur::const_iterator   couleurTrouve =
                        correspondancesEtatCouleur_.find( cubeCourant->second );
         if ( couleurTrouve != correspondancesEtatCouleur_.end() && (*couleurTrouve).second.estValid() )
         {
            couleurTrouve->second.afficherOpenGL();
            cubeCourant->first.afficherOpenGL();
         }
      }
   glEnd();
}

void Scene::afficher( std::ostream & inO ) const
{
   for ( ConteneurCouleur::const_iterator couleurCourante = couleurs_.begin();
         couleurCourante != couleurs_.end();
         ++couleurCourante )
   {
      inO << couleurCourante->first << "\n";
      couleurCourante->second.afficher( inO );
   }
   for ( ConteneurCubeEtat::const_iterator cubeCourant = cubes_.begin();
         cubeCourant != cubes_.end();
         ++cubeCourant )
   {
      ConteneurEtatCouleur::const_iterator   couleurTrouve = correspondancesEtatCouleur_.find( cubeCourant->second );
      if ( couleurTrouve != correspondancesEtatCouleur_.end() )
      {
         couleurTrouve->second.afficher( inO );
      }
      cubeCourant->first.afficher( inO );
   }
}

Scene chargerCubesFichier( const std::string & inChemin )
{
   Scene outScene;

   std::ifstream  fichierLu( inChemin.c_str() );

   int   dimX;
   int   dimY;
   int   dimZ;
   fichierLu >> dimX >> dimY >> dimZ;

   double   largeurCube;
   double   ecartCube;
   fichierLu >> largeurCube >> ecartCube;

   double   largeurPlusEcart  = largeurCube + ecartCube;

   double   largeurXtotal  = dimX * largeurCube + ( dimX - 1 ) * ecartCube;
   double   largeurYtotal  = dimY * largeurCube + ( dimY - 1 ) * ecartCube;
   double   largeurZtotal  = dimZ * largeurCube + ( dimZ - 1 ) * ecartCube;

   double   origineX    = -largeurXtotal / 2;
   double   origineY    = +largeurYtotal / 2;
   double   origineZ    = +largeurZtotal / 2;

   for ( int indiceX = 0; indiceX < dimX; ++ indiceX )
   {
      for ( int indiceY = 0; indiceY < dimY; ++ indiceY )
      {
         for ( int indiceZ = 0; indiceZ < dimZ; ++ indiceZ )
         {
            int   coordonneeX;
            int   coordonneeY;
            int   coordonneeZ;
            int   etat;

            fichierLu >> coordonneeX;
            fichierLu >> coordonneeY;
            fichierLu >> coordonneeZ;
            fichierLu >> etat;

            outScene.ajouterCube( Cube(
                                        Sommet( origineX + largeurCube + coordonneeX * largeurPlusEcart,
                                                origineY - coordonneeY * largeurPlusEcart,
                                                origineZ - coordonneeZ * largeurPlusEcart ),
                                        largeurCube
                                      ),
                                  etat );
         }
      }
   }

   return outScene;
}

void chargerCouleursFichier( const std::string & inChemin, Scene & inoutScene )
{
   std::ifstream  fichierLu( inChemin.c_str() );

   int   nbCouleur;
   fichierLu >> nbCouleur;

   for ( int indiceCouleur = 0; indiceCouleur < nbCouleur; ++indiceCouleur )
   {
      std::string nom;
      GLfloat mat_specular[ 4 ]; 
      GLfloat mat_diffuse[ 4 ];
      GLfloat mat_ambient[ 4 ];
      GLfloat mat_shininess[ 1 ];

      fichierLu >> nom;
      for ( int indiceComposante = 0; indiceComposante < 4; ++indiceComposante )
      {
         fichierLu >> mat_specular[ indiceComposante ];
      }
      for ( int indiceComposante = 0; indiceComposante < 4; ++indiceComposante )
      {
         fichierLu >> mat_diffuse[ indiceComposante ];
      }
      for ( int indiceComposante = 0; indiceComposante < 4; ++indiceComposante )
      {
         fichierLu >> mat_ambient[ indiceComposante ];
      }
      for ( int indiceComposante = 0; indiceComposante < 1; ++indiceComposante )
      {
         fichierLu >> mat_shininess[ indiceComposante ];
      }

      inoutScene.ajouterCouleur( nom, CouleurMaterial( mat_specular,
                                                       mat_diffuse,
                                                       mat_ambient,
                                                       mat_shininess ) );
   }
}

void chargerCorrespondanceEtatCouleursFichier( const std::string & inChemin, Scene & inoutScene )
{
   std::ifstream  fichierLu( inChemin.c_str() );

   int   nbCorrespondance;
   fichierLu >> nbCorrespondance;

   for ( int indiceCorrespondance = 0; indiceCorrespondance < nbCorrespondance; ++indiceCorrespondance )
   {
      Etat etat;
      std::string nom;

      fichierLu >> etat >> nom;

      inoutScene.ajouterCorrespondance( etat, nom );
   }
}

