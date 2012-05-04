
#ifndef OBJETGRAPHIQUE_HPP_GUI_OPENGL
#define OBJETGRAPHIQUE_HPP_GUI_OPENGL

#include <iostream>

class ObjetGraphique
{
   public :
      virtual ~ObjetGraphique(){}
      virtual void afficherOpenGL() const = 0;
      virtual void afficher( std::ostream & inO ) const = 0;
};

#endif // OBJETGRAPHIQUE_HPP_GUI_OPENGL
