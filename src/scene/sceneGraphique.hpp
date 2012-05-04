
#ifndef SCENEGRAPHIQUE_HPP_GUI_OPENGL
#define SCENEGRAPHIQUE_HPP_GUI_OPENGL

#include "objetGraphique.hpp"

#include <QtOpenGL>

#include <vector>

class SceneGraphique : public ObjetGraphique
{
   public :
      virtual ~SceneGraphique();

      void ajouterObjetGraphique( ObjetGraphique * inObjetGraphique );

      virtual void afficherOpenGL() const;
      virtual void afficher( std::ostream & inO ) const;

   private :
      typedef std::vector< ObjetGraphique * > ConteneurObjetGraphique;
      ConteneurObjetGraphique    objetsGraphiques_;
};

#endif // SCENEDECUBES_HPP_GUI_OPENGL
