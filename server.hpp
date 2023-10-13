#ifndef __SERVER_HPP__
#define __SERVER_HPP__
#include <sheduler.hpp>

class Server
{
private:
    int nbOfSensor;
    bool consolActivation;
    bool logActivation;
  
public:
    Server(){};
    Server(const Server &s) : nbOfSensor(s.nbOfSensor), consolActivation(s.consolActivation), logActivation(s.logActivation){};
    Server(int nbOfSensor, bool consolActivation, bool logActivation) : nbOfSensor(nbOfSensor), consolActivation(consolActivation), logActivation(logActivation){};
    ~Server(){};
    Server &operator=(const Server & s){
        this->nbOfSensor = s.nbOfSensor;
        this->consolActivation = s.consolActivation;
        this->logActivation = s.logActivation;

        return (*this);
    };

   
};

#endif
