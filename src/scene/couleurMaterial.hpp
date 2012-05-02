
#ifndef COULEURMATERIAL_HPP_GUI_OPENGL
#define COULEURMATERIAL_HPP_GUI_OPENGL

#include <QtOpenGL>

class CouleurMaterial
{
   public :
      CouleurMaterial();
      CouleurMaterial( GLfloat inSpecular[ 4 ],
                       GLfloat inDiffuse[ 4 ],
                       GLfloat inAmbient[ 4 ],
                       GLfloat inShininess[ 1 ] );
      CouleurMaterial( const CouleurMaterial & inCouleur );

      void afficherOpenGL() const;
      void afficher() const;

      virtual bool estValid() const;

   private :
      GLfloat specular_[ 4 ];
      GLfloat diffuse_[ 4 ];
      GLfloat ambient_[ 4 ];
      GLfloat shininess_[ 1 ];

      static CouleurMaterial  Invisible_;
};


class InvalidCouleurMaterial : public CouleurMaterial
{
   public :
      virtual bool estValid() const;
};

#endif // COULEURMATERIAL_HPP_GUI_OPENGL
