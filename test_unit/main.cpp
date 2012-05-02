#include <QtTest>
#include <QApplication>

#include "test_vertexArrays.hpp"

int main( int argc, char *argv[] )
{
   QApplication   app( argc, argv );

   return QTest::qExec( new TestVertexArrays );
}
