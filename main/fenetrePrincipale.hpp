
#ifndef FENETREPRINCIPALE_HPP_GUI_OPENGL
#define FENETREPRINCIPALE_HPP_GUI_OPENGL

#include "visualisationOpenGL.hpp"

#include <QtGui/QMainWindow>

class FenetrePrincipale : public QMainWindow
{
   Q_OBJECT

   public:
      typedef VisualisationOpenGL::ConteneurObjetGraphique ConteneurObjetGraphique;
      FenetrePrincipale( ConteneurObjetGraphique * inObjetsGraphiques );

      void affichageTailleCorrect();

   private:
      VisualisationOpenGL *  visualisationOpenGL_;
};

#endif // FENETREPRINCIPALE_HPP_GUI_OPENGL
