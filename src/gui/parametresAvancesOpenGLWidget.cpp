
#include "parametresAvancesOpenGLWidget.hpp"

#include <QtCore/QString>

#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QCheckBox>

#include "doubleadaptedslider.hpp"

#include "vueOpenGLWidget.hpp"

ParametresAvancesOpenGLWidget::ParametresAvancesOpenGLWidget( VueOpenGLWidget * inVueOpenGLWidget )
{
   QVBoxLayout * mainLayout = new QVBoxLayout;

   mainLayout->addWidget( creationGroupeRotation( &( inVueOpenGLWidget->getOpenGLRotation() ) ) );
   mainLayout->addWidget( creationGroupeCamera( &( inVueOpenGLWidget->getOpenGLCamera() ) ) );
   mainLayout->addWidget( creationGroupeLumiere( &( inVueOpenGLWidget->getOpenGLLumiere() ) ) );
   setLayout( mainLayout );

   xSliderRotation_->setAdaptedValue( 0 );
   ySliderRotation_->setAdaptedValue( 306 );
   zSliderRotation_->setAdaptedValue( 0 );
   
   xSliderCamera_->setAdaptedValue( -8 );
   ySliderCamera_->setAdaptedValue( 7 );
   zSliderCamera_->setAdaptedValue( 12 );
   sliderZoomCamera_->setAdaptedValue( 23 );
   sliderPremierPlanCamera_->setAdaptedValue( 0.1 );

   checkboxLumiere_->setCheckState( Qt::Checked );
   xSliderLumiere_->setValue( 4 );
   ySliderLumiere_->setValue( 2 );
   zSliderLumiere_->setValue( 3 );
}

QGroupBox * ParametresAvancesOpenGLWidget::creationGroupeRotation( const QObject * const inOpenGLRotation )
{
   QGroupBox *    outGroupBox    = new QGroupBox( tr( "Rotations" ) );
   QVBoxLayout *  groupeLayout   = new QVBoxLayout();

   groupeLayout->addLayout( creationTripletRotation( ParametresAvancesOpenGLWidget::x, inOpenGLRotation ) );
   groupeLayout->addLayout( creationTripletRotation( ParametresAvancesOpenGLWidget::y, inOpenGLRotation ) );
   groupeLayout->addLayout( creationTripletRotation( ParametresAvancesOpenGLWidget::z, inOpenGLRotation ) );
   outGroupBox->setLayout( groupeLayout );

   return outGroupBox;
}

QHBoxLayout * ParametresAvancesOpenGLWidget::creationTripletRotation( Axe inAxe, const QObject * const inOpenGLRotation )
{
   static QString Label[] = { tr( "Axe X : " ), tr( "Axe Y : " ), tr( "Axe Z : " ) };
   static DoubleAdaptedSlider ** Slider[] = { &xSliderRotation_, &ySliderRotation_, &zSliderRotation_ };

   QHBoxLayout *  outAxeLayout   = new QHBoxLayout();

   QLabel *    labelAxe    = new QLabel( Label[ inAxe ] );
   *( Slider[ inAxe ] )    = creationDoubleSlider( 2, 0, 360, 0.1, 1 );
   QDoubleSpinBox *  spinBox     = creationDoubleSpinBox( *( Slider[ inAxe ] ) );

   outAxeLayout->addWidget( labelAxe );
   outAxeLayout->addWidget( *( Slider[ inAxe ] ) );
   outAxeLayout->addWidget( spinBox );

   switch( inAxe )
   {
      case x :
         connect( *( Slider[ inAxe ] ), SIGNAL( adaptedValueChanged( double ) ),
                  inOpenGLRotation,     SLOT(   setAxeX( double ) ) );
         connect( inOpenGLRotation,     SIGNAL( miseAJourAxeX( double ) ),
                  *( Slider[ inAxe ] ), SLOT(   setAdaptedValue( double ) ) );
         break;
      case y :
         connect( *( Slider[ inAxe ] ), SIGNAL( adaptedValueChanged( double ) ),
                  inOpenGLRotation,     SLOT(   setAxeY( double ) ) );
         connect( inOpenGLRotation,     SIGNAL( miseAJourAxeY( double ) ),
                  *( Slider[ inAxe ] ), SLOT(   setAdaptedValue( double ) ) );
         break;
      case z :
         connect( *( Slider[ inAxe ] ), SIGNAL( adaptedValueChanged( double ) ),
                  inOpenGLRotation,     SLOT(   setAxeZ( double ) ) );
         connect( inOpenGLRotation,     SIGNAL( miseAJourAxeZ( double ) ),
                  *( Slider[ inAxe ] ), SLOT(   setAdaptedValue( double ) ) );
         break;
      default :
      // TODO : lever une exception
         exit( 1 );
   }

   return outAxeLayout;
}


QGroupBox * ParametresAvancesOpenGLWidget::creationGroupeCamera( const QObject * const inOpenGLCamera )
{
   QGroupBox *    outGroupBox    = new QGroupBox( tr( "Camera" ) );
   QVBoxLayout *  groupeLayout   = new QVBoxLayout();

   groupeLayout->addLayout( creationTripletCoordCamera( ParametresAvancesOpenGLWidget::x, inOpenGLCamera ) );
   groupeLayout->addLayout( creationTripletCoordCamera( ParametresAvancesOpenGLWidget::y, inOpenGLCamera ) );
   groupeLayout->addLayout( creationTripletCoordCamera( ParametresAvancesOpenGLWidget::z, inOpenGLCamera ) );
   groupeLayout->addLayout( creationTripletZoomCamera( inOpenGLCamera ) );
   groupeLayout->addLayout( creationTripletPremierPlanCamera( inOpenGLCamera ) );
   outGroupBox->setLayout( groupeLayout );

   return outGroupBox;
}

QHBoxLayout * ParametresAvancesOpenGLWidget::creationTripletCoordCamera( Axe inAxe, const QObject * const inOpenGLCamera )
{
   static QString Label[] = { tr( "Axe X : " ), tr( "Axe Y : " ), tr( "Axe Z : " ) };
   static DoubleAdaptedSlider ** Slider[] = { &xSliderCamera_, &ySliderCamera_, &zSliderCamera_ };

   QHBoxLayout *  outAxeLayout   = new QHBoxLayout();

   QLabel *    labelAxe    = new QLabel( Label[ inAxe ] );
   *( Slider[ inAxe ] )    = creationDoubleSlider( 1, -50, 50, 1, 5 );
   QDoubleSpinBox *  spinBox     = creationDoubleSpinBox( *( Slider[ inAxe ] ) );

   outAxeLayout->addWidget( labelAxe );
   outAxeLayout->addWidget( *( Slider[ inAxe ] ) );
   outAxeLayout->addWidget( spinBox );

   switch( inAxe )
   {
      case x :
         connect( *( Slider[ inAxe ] ), SIGNAL( adaptedValueChanged( double ) ),
                  inOpenGLCamera,       SLOT(   setPositionX( double ) ) );
         connect( inOpenGLCamera,       SIGNAL( miseAJourPositionX( double ) ),
                  *( Slider[ inAxe ] ), SLOT(   setAdaptedValue( double ) ) );
         break;
      case y :
         connect( *( Slider[ inAxe ] ), SIGNAL( adaptedValueChanged( double ) ),
                  inOpenGLCamera,       SLOT(   setPositionY( double ) ) );
         connect( inOpenGLCamera,       SIGNAL( miseAJourPositionY( double ) ),
                  *( Slider[ inAxe ] ), SLOT(   setAdaptedValue( double ) ) );
         break;
      case z :
         connect( *( Slider[ inAxe ] ), SIGNAL( adaptedValueChanged( double ) ),
                  inOpenGLCamera,       SLOT(   setPositionZ( double ) ) );
         connect( inOpenGLCamera,       SIGNAL( miseAJourPositionZ( double ) ),
                  *( Slider[ inAxe ] ), SLOT(   setAdaptedValue( double ) ) );
         break;
      default :
      // TODO : lever une exception
         exit( 1 );
   }

   return outAxeLayout;
}

QHBoxLayout * ParametresAvancesOpenGLWidget::creationTripletZoomCamera( const QObject * const inOpenGLCamera )
{
   QHBoxLayout *  outAxeLayout   = new QHBoxLayout();

   QLabel *    labelAxe    = new QLabel( tr( "Zoom : " ) );
   sliderZoomCamera_       = creationDoubleSlider( 1, 0, 200, 0.1, 20 );
   QDoubleSpinBox *  spinBox     = creationDoubleSpinBox( sliderZoomCamera_ );

   outAxeLayout->addWidget( labelAxe );
   outAxeLayout->addWidget( sliderZoomCamera_ );
   outAxeLayout->addWidget( spinBox );

   connect( sliderZoomCamera_, SIGNAL( adaptedValueChanged( double ) ),
            inOpenGLCamera,    SLOT(   setZoom( double ) ) );
   connect( inOpenGLCamera,    SIGNAL( miseAJourZoom( double ) ),
            sliderZoomCamera_, SLOT(   setAdaptedValue( double ) ) );

   return outAxeLayout;
}

QHBoxLayout * ParametresAvancesOpenGLWidget::creationTripletPremierPlanCamera( const QObject * const inOpenGLCamera )
{
   QHBoxLayout *  outAxeLayout   = new QHBoxLayout();

   QLabel *    labelAxe       = new QLabel( tr( "Premier plan : " ) );
   sliderPremierPlanCamera_   = creationDoubleSlider( 2, 0, 100, 0.1, 10 );
   QDoubleSpinBox *  spinBox  = creationDoubleSpinBox( sliderPremierPlanCamera_ );

   outAxeLayout->addWidget( labelAxe );
   outAxeLayout->addWidget( sliderPremierPlanCamera_ );
   outAxeLayout->addWidget( spinBox );

   connect( sliderPremierPlanCamera_, SIGNAL( adaptedValueChanged( double ) ),
            inOpenGLCamera,           SLOT(   setPremierPlan( double ) ) );
   connect( inOpenGLCamera,           SIGNAL( miseAJourPremierPlan( double ) ),
            sliderPremierPlanCamera_, SLOT(   setAdaptedValue( double ) ) );

   return outAxeLayout;
}

QGroupBox * ParametresAvancesOpenGLWidget::creationGroupeLumiere( const QObject * const inOpenGLLumiere )
{
   QGroupBox *    outGroupBox    = new QGroupBox( tr( "Lumiere" ) );
   QVBoxLayout *  groupeLayout   = new QVBoxLayout();

   groupeLayout->addWidget( creationCheckBoxLumiere( inOpenGLLumiere ) );
   groupeLayout->addLayout( creationTripletLumiere( ParametresAvancesOpenGLWidget::x, inOpenGLLumiere ) );
   groupeLayout->addLayout( creationTripletLumiere( ParametresAvancesOpenGLWidget::y, inOpenGLLumiere ) );
   groupeLayout->addLayout( creationTripletLumiere( ParametresAvancesOpenGLWidget::z, inOpenGLLumiere ) );
   outGroupBox->setLayout( groupeLayout );

   return outGroupBox;
}

QCheckBox * ParametresAvancesOpenGLWidget::creationCheckBoxLumiere( const QObject * const inOpenGLLumiere )
{
   checkboxLumiere_  = new QCheckBox( tr( "Activer les lumieres" ) );

   connect( checkboxLumiere_, SIGNAL( stateChanged( int ) ),
            this,             SLOT(  changementEtatLumiere( int ) ) );
   connect( this,            SIGNAL( changementEtatLumiere( bool ) ),
            inOpenGLLumiere, SLOT(   SetActivationGeneral( bool ) ) );
   connect( this,            SIGNAL( changementEtatLumiere( bool ) ),
            inOpenGLLumiere, SIGNAL( miseAJour() ) );

   return checkboxLumiere_;
}

void ParametresAvancesOpenGLWidget::changementEtatLumiere( int inNouvelEtat )
{
   emit changementEtatLumiere( inNouvelEtat == Qt::Checked );
}

QHBoxLayout * ParametresAvancesOpenGLWidget::creationTripletLumiere( Axe inAxe, const QObject * const inOpenGLLumiere )
{
   static QString Label[] = { tr( "Axe X : " ), tr( "Axe Y : " ), tr( "Axe Z : " ) };
   static DoubleAdaptedSlider ** Slider[] = { &xSliderLumiere_, &ySliderLumiere_, &zSliderLumiere_ };

   QHBoxLayout *  outAxeLayout   = new QHBoxLayout();

   QLabel *    labelAxe    = new QLabel( Label[ inAxe ] );
   *( Slider[ inAxe ] )    = creationDoubleSlider( 1, -100, 100, 1, 20 );
   QDoubleSpinBox *  spinBox     = creationDoubleSpinBox( *( Slider[ inAxe ] ) );

   outAxeLayout->addWidget( labelAxe );
   outAxeLayout->addWidget( *( Slider[ inAxe ] ) );
   outAxeLayout->addWidget( spinBox );

   switch( inAxe )
   {
      case x :
         connect( *( Slider[ inAxe ] ), SIGNAL( adaptedValueChanged( double ) ),
                  inOpenGLLumiere,      SLOT(   setPositionX( double ) ) );
         connect( inOpenGLLumiere,      SIGNAL( miseAJourPositionX( double ) ),
                  *( Slider[ inAxe ] ), SLOT(   setAdaptedValue( double ) ) );
         break;
      case y :
         connect( *( Slider[ inAxe ] ), SIGNAL( adaptedValueChanged( double ) ),
                  inOpenGLLumiere,      SLOT(   setPositionY( double ) ) );
         connect( inOpenGLLumiere,      SIGNAL( miseAJourPositionY( double ) ),
                  *( Slider[ inAxe ] ), SLOT(   setAdaptedValue( double ) ) );
         break;
      case z :
         connect( *( Slider[ inAxe ] ), SIGNAL( adaptedValueChanged( double ) ),
                  inOpenGLLumiere,      SLOT(   setPositionZ( double ) ) );
         connect( inOpenGLLumiere,      SIGNAL( miseAJourPositionZ( double ) ),
                  *( Slider[ inAxe ] ), SLOT(   setAdaptedValue( double ) ) );
         break;
      default :
      // TODO : lever une exception
         exit( 1 );
   }

   return outAxeLayout;
}

DoubleAdaptedSlider * ParametresAvancesOpenGLWidget::creationDoubleSlider( int inNbDecimal, double inMinimum, double inMaximum, double inPasSimple, double inPasPage )
{
   DoubleAdaptedSlider *   outSlider   = new DoubleAdaptedSlider( Qt::Horizontal, inNbDecimal );

   outSlider->setAdaptedRange( inMinimum, inMaximum );
   outSlider->setAdaptedSingleStep( inPasSimple );
   outSlider->setAdaptedPageStep( inPasPage );

   return outSlider;
}

QDoubleSpinBox * ParametresAvancesOpenGLWidget::creationDoubleSpinBox( DoubleAdaptedSlider * inSliderCorrespondant )
{
   QDoubleSpinBox * outSpinBox = new QDoubleSpinBox();

   outSpinBox->setRange( inSliderCorrespondant->adaptedMinimum(), inSliderCorrespondant->adaptedMaximum() );
   outSpinBox->setSingleStep( inSliderCorrespondant->adaptedSingleStep() );

   connect( outSpinBox,            SIGNAL( valueChanged( double ) ),
            inSliderCorrespondant, SLOT(   setAdaptedValue( double ) ) );
   connect( inSliderCorrespondant, SIGNAL( adaptedValueChanged( double ) ),
            outSpinBox,            SLOT(   setValue( double ) ) );

   return outSpinBox;
}
