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

template<typename T>
Sensor<T>& Sensor<T>::operator=(const Sensor<T> &s){
    
    this->valSense = s.valSense;

    return (*this);
}
