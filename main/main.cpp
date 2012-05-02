
#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>

#include "fenetrePrincipale.hpp"

int main(int argc, char *argv[])
{
   QApplication            app(argc, argv);
   FenetrePrincipale       fenetrePrincipale;

   fenetrePrincipale.affichageTailleCorrect();

   return app.exec();
}
