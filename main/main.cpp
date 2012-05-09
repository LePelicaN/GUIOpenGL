
#include "fenetrePrincipale.hpp"

#include "../scene/vertexArrays.hpp"

#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>

int main(int argc, char *argv[])
{
   QApplication            app(argc, argv);

   FenetrePrincipale::ConteneurObjetGraphique objetsGraphiques;

   VertexArrays   vertexArrays;
   vertexArrays.ajoutSommet( Sommet( 0.8, -0.8, 0 ), CouleurBasique( 0.0, 1.0, 0.0 ) );
   vertexArrays.ajoutSommet( Sommet( -0.8, -0.8, 0 ), CouleurBasique( 1.0, 0.0, 0.0 ) );
   vertexArrays.ajoutSommet( Sommet( -0.8, 0.8, 0 ), CouleurBasique( 1.0, 1.0, 1.0 ) );
   vertexArrays.ajoutSommet( Sommet( 0.8, 0.8, 0 ), CouleurBasique( 0.0, 0.0, 1.0 ) );
   vertexArrays.ajoutSommet( Sommet( 2, 0.8, 0 ), CouleurBasique( 0.0, 0.0, 1.0 ) );
   vertexArrays.afficherOpenGL();
   objetsGraphiques.push_back( &vertexArrays );

   FenetrePrincipale       fenetrePrincipale( &objetsGraphiques );

   fenetrePrincipale.affichageTailleCorrect();

   return app.exec();
}
