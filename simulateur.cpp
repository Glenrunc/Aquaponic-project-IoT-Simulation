#include <simulateur.hpp>

/**
 * Method uses by Server
 */
Server &Server::operator=(const Server &s){
    
    this->nbOfSensor = s.nbOfSensor;
    this->consolActivation = s.consolActivation;
    this->logActivation = s.logActivation;

    return (*this);
}
/**
 * Method uses by the Sensor
*/
template<typename T>
Sensor<T>& Sensor<T>::operator=(const Sensor<T> &s){
    
    this->valSense = s.valSense;
    this->nameSensor = s.nameSensor;
    this->min = s.min;
    this->max = s.max;

    return (*this);
}
