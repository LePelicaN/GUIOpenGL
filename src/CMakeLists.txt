
SET( QT_USE_QTOPENGL TRUE )

INCLUDE( ${QT_USE_FILE} )
ADD_DEFINITIONS( ${QT_DEFINITIONS} )

include_directories( gui )
include_directories( scene )


FILE( GLOB MOC_HEADERS "gui/*.hpp" )
     
QT4_WRAP_CPP( MOC_SOURCES ${MOC_HEADERS} )

FILE( GLOB GUI_SOURCES "gui/*.*" )
FILE( GLOB SCENE_SOURCES "scene/*.*" )

SOURCE_GROUP( Gui FILES ${GUI_SOURCES} )
SOURCE_GROUP( Scene FILES ${SCENE_SOURCES} )

ADD_LIBRARY( source_general
             ${GUI_SOURCES}
             ${SCENE_SOURCES}
             ${MOC_SOURCES} )

TARGET_LINK_LIBRARIES( source_general ${QT_LIBRARIES} ${OPENGL_LIBRARIES} )
