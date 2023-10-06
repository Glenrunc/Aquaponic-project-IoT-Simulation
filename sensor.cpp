#include <sensor.hpp> 

/**
 * Method uses by the Sensor
*/
template<typename T>
Sensor<T>& Sensor<T>::operator=(const Sensor<T> &s){
    this->valSense = s.valSense;
    
    return (*this);
}

Temperature& Temperature::operator=(const Temperature&  t){
    
    this->valSense = t.valSense;
    this->_max = t._max;
    this->_min = t._min;
    this->nameSensor = t.nameSensor;

    return (*this);
}