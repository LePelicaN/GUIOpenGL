
#ifndef SOMMET_HPP_GUI_OPENGL
#define SOMMET_HPP_GUI_OPENGL

#include <iostream>

class Sommet
{
   public :
      Sommet();
      Sommet( float inCoordonneeX, float inCoordonneeY, float inCoordonneeZ );
      void afficherOpenGL() const;
      void afficher( std::ostream & inO ) const;

      static const int NbCoordonnees_ = 3;

   private :
      float coordonneeX_;
      float coordonneeY_;
      float coordonneeZ_;

   friend Sommet operator+( const Sommet & inSommetGauche, const Sommet & inSommetDroit );
};

Sommet operator+( const Sommet & inSommetGauche, const Sommet & inSommetDroit );

#endif // SOMMET_HPP_GUI_OPENGL
