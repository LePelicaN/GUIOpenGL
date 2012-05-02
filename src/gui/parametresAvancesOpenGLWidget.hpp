
#ifndef PAREMETREAVANCESWIDGET_HPP_GUI_OPENGL
#define PAREMETREAVANCESWIDGET_HPP_GUI_OPENGL

#include <QtGui/QWidget>

class VueOpenGLWidget;

class DoubleAdaptedSlider;

class QString;

class QGroupBox;
class QHBoxLayout;
class QSlider;
class QSpinBox;
class QDoubleSpinBox;
class QCheckBox;

class ParametresAvancesOpenGLWidget : public QWidget
{
   Q_OBJECT

   public:
      ParametresAvancesOpenGLWidget( VueOpenGLWidget * inVueOpenGLWidget );

   private:
      enum Axe
      {
         x,
         y,
         z
      };

      QGroupBox * creationGroupeRotation( const QObject * const inOpenGLRotation );
      QHBoxLayout * creationTripletRotation( Axe inAxe, const QObject * const inOpenGLRotation );

      QGroupBox * creationGroupeCamera( const QObject * const inOpenGLCamera );
      QHBoxLayout * creationTripletCoordCamera( Axe inAxe, const QObject * const inOpenGLCamera );
      QHBoxLayout * creationTripletZoomCamera( const QObject * const inOpenGLCamera );
      QHBoxLayout * creationTripletPremierPlanCamera( const QObject * const inOpenGLCamera );

      QGroupBox * creationGroupeLumiere( const QObject * const inOpenGLLumiere );
      QCheckBox * creationCheckBoxLumiere( const QObject * const inOpenGLLumiere );
      QHBoxLayout * creationTripletLumiere( Axe inAxe, const QObject * const inOpenGLLumiere );

      DoubleAdaptedSlider * creationDoubleSlider( int inNbDecimal, double inMinimum, double inMaximum, double inPasSimple, double inPasPage );
      QDoubleSpinBox * creationDoubleSpinBox( DoubleAdaptedSlider * inSliderCorrespondant );


      DoubleAdaptedSlider *   xSliderRotation_;
      DoubleAdaptedSlider *   ySliderRotation_;
      DoubleAdaptedSlider *   zSliderRotation_;

      DoubleAdaptedSlider *   xSliderCamera_;
      DoubleAdaptedSlider *   ySliderCamera_;
      DoubleAdaptedSlider *   zSliderCamera_;
      DoubleAdaptedSlider *   sliderZoomCamera_;
      DoubleAdaptedSlider *   sliderPremierPlanCamera_;

      QCheckBox * checkboxLumiere_;
      DoubleAdaptedSlider *   xSliderLumiere_;
      DoubleAdaptedSlider *   ySliderLumiere_;
      DoubleAdaptedSlider *   zSliderLumiere_;

   signals :
      void changementEtatLumiere( bool outNouvelEtat );

   private slots :
      void changementEtatLumiere( int inNouvelEtat );
};

#endif // PAREMETREAVANCESWIDGET_HPP_GUI_OPENGL
