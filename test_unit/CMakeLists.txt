
INCLUDE_DIRECTORIES(
                     ../src
                     ../src/scene
                     ../src/gui
                   )

SET( QT_USE_QTTEST TRUE )
SET( QT_USE_QTOPENGL TRUE )

INCLUDE( ${QT_USE_FILE} )
ADD_DEFINITIONS( ${QT_DEFINITIONS} )

#FILE( GLOB TEST_STUBS "stub_*.*" )
FILE( GLOB TEST_SOURCES "test_*.cpp" )
FILE( GLOB TEST_HEADERS "test_*.hpp" )

FILE( GLOB TEST_INPUT_RC "input/*.*" )

SET( SOURCES_RC ressources_test.qrc )

#SOURCE_GROUP( Stubs FILES ${TEST_STUBS} )
SOURCE_GROUP( Test_Unit FILES ${TEST_SOURCES} ${TEST_HEADERS} )
SOURCE_GROUP( Input FILES ${TEST_INPUT_RC} )


QT4_ADD_RESOURCES( SOURCES_RC_SRC ${SOURCES_RC} )
QT4_WRAP_CPP( TEST_HEADERS_MOC ${TEST_HEADERS} )

ADD_EXECUTABLE( test_guiopengl
                main.cpp
                ${TEST_HEADERS}
                ${TEST_SOURCES}
#                ${STUBS}
                ${TEST_HEADERS_MOC}
                ${SOURCES_RC_SRC} )

TARGET_LINK_LIBRARIES( test_guiopengl ${QT_LIBRARIES} ${OPENGL_LIBRARIES} source_general )
