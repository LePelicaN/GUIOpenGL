
#ifndef FENETREPRINCIPALE_HPP_GUI_OPENGL
#define FENETREPRINCIPALE_HPP_GUI_OPENGL

#include <QtGui/QMainWindow>

class VisualisationOpenGL;

class FenetrePrincipale : public QMainWindow
{
   Q_OBJECT

   public:
      FenetrePrincipale();

      void affichageTailleCorrect();

   private:
      VisualisationOpenGL *  visualisationOpenGL_;
};

#endif // FENETREPRINCIPALE_HPP_GUI_OPENGL
