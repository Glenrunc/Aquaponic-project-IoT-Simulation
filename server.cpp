#include <server.hpp>

/**
 * Method uses by Server
 */
Server &Server::operator=(const Server &s){
    
    this->nbOfSensor = s.nbOfSensor;
    this->consolActivation = s.consolActivation;
    this->logActivation = s.logActivation;

    return (*this);
}
