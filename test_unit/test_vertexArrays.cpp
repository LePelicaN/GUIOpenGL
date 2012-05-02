
#include "test_vertexArrays.hpp"

#include "vertexArrays.hpp"

#include <QTest>

#include <sstream>

void TestVertexArrays::TestCase()
{
   VertexArrays   vertexArrays;

   Sommet            s1( 1, 1, 1 );
   CouleurBasique    c1( 1, 0, 0 );

   vertexArrays.ajoutSommet( s1, c1 );
   QVERIFY2( vertexArrays.getNbSommet() == 1, "Il y a un sommet." );

   Sommet            s2( s1 );
   CouleurBasique    c2( c1 );

   vertexArrays.ajoutSommet( s2, c2 );
   QVERIFY2( vertexArrays.getNbSommet() == 2, "Il y a deux sommets." );

   vertexArrays.ajoutSommet( Sommet( 1.5, -2.5, -3 ), CouleurBasique( 0.2, 0.4, 0.3 ) );
   vertexArrays.ajoutSommet( Sommet( 0.5, 1, -1.5 ), CouleurBasique( 0., 0., 0. ) );
   vertexArrays.ajoutSommet( Sommet( 1.2, 3.2, 2 ), CouleurBasique( 0.6, 0.954, 0.001 ) );
   vertexArrays.ajoutSommet( Sommet( -10.5, -5.5, 7.8 ), CouleurBasique( 0.482, 0.458, 0.256 ) );
   QVERIFY2( vertexArrays.getNbSommet() == 6, "Il y a six sommets." );

   QFile    fichierSortie( ":/input/sortieVertexArrays.txt" );
   if ( fichierSortie.open( QIODevice::ReadOnly | QIODevice::Text ) )
   {
      std::ostringstream   oss;
      vertexArrays.afficher( oss );
      std::string    resultatEspere    = QString( fichierSortie.readAll() ).toStdString();
      std::cout << "->" << oss.str() << "<-" << std::endl;
      std::cout << "->" << resultatEspere << "<-" << std::endl;
      QVERIFY2( oss.str() == resultatEspere, "L'affichage est correct." );
   }
   else
   {
      std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
   }
}
