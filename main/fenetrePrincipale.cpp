
#include "fenetrePrincipale.hpp"

#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>
#include <QtGui/QHBoxLayout>

#include "visualisationOpenGL.hpp"

FenetrePrincipale::FenetrePrincipale( ConteneurObjetGraphique * inObjetsGraphiques )
{
   visualisationOpenGL_ = new VisualisationOpenGL( inObjetsGraphiques );

   QHBoxLayout *mainLayout = new QHBoxLayout;
   mainLayout->addWidget( visualisationOpenGL_ );

   QWidget *  widgetCentrale    = new QWidget();
   widgetCentrale->setLayout( mainLayout );
   setCentralWidget( widgetCentrale );

   setWindowTitle( tr( "Interface Graphique OpenGL de test" ) );
}

void FenetrePrincipale::affichageTailleCorrect()
{
   resize( sizeHint() );

   float aireEcran      = QApplication::desktop()->width() * QApplication::desktop()->height();
   float aireFenetre    = width() * height();
   if ( ( aireFenetre / aireEcran ) < 0.75f )
   {
      show();
   }
   else
   {
      showMaximized();
   }
}
