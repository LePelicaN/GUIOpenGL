
#ifndef SOMMET_HPP_GUI_OPENGL
#define SOMMET_HPP_GUI_OPENGL

class Sommet
{
   public :
      Sommet();
      Sommet( double inCoordonneeX, double inCoordonneeY, double inCoordonneeZ );
      void afficherOpenGL() const;
      void afficher() const;

   private :
      double   coordonneeX_;
      double   coordonneeY_;
      double   coordonneeZ_;

   friend Sommet operator+( const Sommet & inSommetGauche, const Sommet & inSommetDroit );
};

Sommet operator+( const Sommet & inSommetGauche, const Sommet & inSommetDroit );

#endif // SOMMET_HPP_GUI_OPENGL
