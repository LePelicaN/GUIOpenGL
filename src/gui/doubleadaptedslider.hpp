#ifndef DOUBLEADAPTEDSLIDER_H
#define DOUBLEADAPTEDSLIDER_H

#include <QSlider>

class DoubleAdaptedSlider : public QSlider
{
    Q_OBJECT

  public: // member functions

    explicit DoubleAdaptedSlider(int nbDecimal_ = 0, QWidget * parent = 0);
    DoubleAdaptedSlider( Qt::Orientation orientation, int nbDecimals = 0, QWidget * parent = 0);

    void setNbDecimals( int nbDecimals );

    void setAdaptedMinimum( double min );
    void setAdaptedMaximum( double max );
    void setAdaptedRange( double min, double max );
    void setAdaptedSingleStep( double step );
    void setAdaptedPageStep( double step );

    double adaptedMinimum( ) const;
    double adaptedMaximum( ) const;
    double adaptedSingleStep( ) const;
    double adaptedPageStep( ) const;
    double adaptedValue( ) const;

  signals:

    void adaptedValueChanged( double value );


  public slots:

    void setAdaptedValue( double value );


  private: // member functions

    void createConnections( );


  private slots:

    void adaptValueChangedSignal( int value );


  private: // static member functions

    static double NbDecimalsToFactor( int nbDecimals );


  private: // member variables

    double factor_;
};


#endif // DOUBLESLIDER_H
