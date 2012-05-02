
#ifndef SCENE_HPP_GUI_OPENGL
#define SCENE_HPP_GUI_OPENGL

#include "sommet.hpp"
#include "cube.hpp"
#include "couleurMaterial.hpp"

#include "etat.hpp"

#include <QtOpenGL>

#include <string>

#include <iostream>

class Scene
{
   public :
      typedef std::vector< std::pair< Cube, Etat > > ConteneurCubeEtat;
      typedef std::map< std::string, CouleurMaterial > ConteneurCouleur;
      typedef std::map< Etat, CouleurMaterial > ConteneurEtatCouleur;

      void ajouterCube( Cube inCube, Etat inEtat );
      void ajouterCouleur( const std::string & inNomCouleur, const CouleurMaterial & inCouleur );
      void ajouterCorrespondance( Etat inEtat, const std::string & inNomCouleur );

      void afficherOpenGL() const;
      void afficher( std::ostream & inO ) const;

   private :
      double minX_;
      double maxX_;
      double minY_;
      double maxY_;
      double minZ_;
      double maxZ_;
      ConteneurCubeEtat    cubes_;
      ConteneurCouleur     couleurs_;
      ConteneurEtatCouleur correspondancesEtatCouleur_;
      
};

Scene chargerCubesFichier( const std::string & inChemin );
void chargerCouleursFichier( const std::string & inChemin, Scene & inoutScene );
void chargerCorrespondanceEtatCouleursFichier( const std::string & inChemin, Scene & inoutScene );

#endif // SCENE_HPP_GUI_OPENGL
