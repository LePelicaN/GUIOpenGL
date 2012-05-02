#include "doubleadaptedslider.hpp"

#include <cmath>

//---------------------------------------------------------
// Public member functions
//---------------------------------------------------------

DoubleAdaptedSlider::DoubleAdaptedSlider( int nbDecimals, QWidget * parent )
  : QSlider( parent ),
    factor_( NbDecimalsToFactor( nbDecimals ) )
{
    createConnections();
}


DoubleAdaptedSlider::DoubleAdaptedSlider( Qt::Orientation orientation, int nbDecimals, QWidget * parent )
  : QSlider( orientation, parent ),
    factor_( NbDecimalsToFactor( nbDecimals ) )
{
    createConnections();
}


void DoubleAdaptedSlider::setNbDecimals( int nbDecimals )
{
    double min        = adaptedMinimum();
    double max        = adaptedMaximum();
    double singleStep = adaptedSingleStep();
    double pageStep   = adaptedPageStep();
    double value      = adaptedValue();

    double oldFactor = factor_;
    factor_ = NbDecimalsToFactor( nbDecimals );

    // Mettre a jour les attributs dans le bon ordre pour eviter que la valeur ne soit hors de l'intervalle
    if ( oldFactor < factor_ )
    {
        setAdaptedRange( min, max );
        setAdaptedValue( value );
    }
    else
    {
        setAdaptedValue( value );
        setAdaptedRange( min, max );
    }

    setAdaptedSingleStep( singleStep );
    setAdaptedPageStep( pageStep );
}


void DoubleAdaptedSlider::setAdaptedValue( double value )
{
    double newValue = value * factor_;

    if ( newValue - std::floor( newValue ) >= 0.5 )
    {
        newValue += 0.5;
    }

    setValue( static_cast< int >( newValue ) );
}


void DoubleAdaptedSlider::setAdaptedMinimum( double min )
{
    setMinimum( static_cast< int >( min * factor_ ) );
}


void DoubleAdaptedSlider::setAdaptedMaximum( double max )
{
    setMaximum( static_cast< int >( max * factor_ ) );
}


void DoubleAdaptedSlider::setAdaptedRange( double min, double max )
{
    setRange( static_cast< int >( min * factor_ ), static_cast< int >( max * factor_ ) );
}


void DoubleAdaptedSlider::setAdaptedSingleStep( double step )
{
    setSingleStep( static_cast< int >( step * factor_ ) );
}


void DoubleAdaptedSlider::setAdaptedPageStep( double step )
{
    setPageStep( static_cast< int >( step * factor_ ) );
}


double DoubleAdaptedSlider::adaptedMinimum( ) const
{
    return minimum() / factor_;
}


double DoubleAdaptedSlider::adaptedMaximum( ) const
{
    return maximum() / factor_;
}


double DoubleAdaptedSlider::adaptedSingleStep( ) const
{
    return singleStep() / factor_;
}


double DoubleAdaptedSlider::adaptedPageStep( ) const
{
    return pageStep() / factor_;
}


double DoubleAdaptedSlider::adaptedValue( ) const
{
    return value() / factor_;
}


//---------------------------------------------------------
// Private member functions
//---------------------------------------------------------

void DoubleAdaptedSlider::createConnections( )
{
    connect( this, SIGNAL( valueChanged( int ) ),
             this, SLOT( adaptValueChangedSignal( int ) ) );
}


void DoubleAdaptedSlider::adaptValueChangedSignal( int value )
{
    emit adaptedValueChanged( value / factor_ );
}


//---------------------------------------------------------
// Private static member functions
//---------------------------------------------------------

double DoubleAdaptedSlider::NbDecimalsToFactor( int nbDecimals )
{
    double power = pow( 10.0, nbDecimals );

    return power;
}


