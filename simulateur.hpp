#ifndef __SIMULATEUR_HPP__
#define __SIMULATEUR_HPP__

#include <iostream>

class Server {
    private:
        int nbOfSensor;
        bool consolActivation;
        bool logActivation;
    
    public:
        Server(){};
        Server(const Server& s):nbOfSensor(s.nbOfSensor),consolActivation(s.consolActivation),logActivation(s.logActivation){};
        Server(int nbOfSensor,bool consolActivation,bool logActivation):nbOfSensor(nbOfSensor), consolActivation(consolActivation), logActivation(logActivation){};
        ~Server(){};
        Server& operator=(const Server&);
};


template <typename T> class Sensor {
    
    private:
        T valSense;

    public:
        Sensor(){};
        Sensor(const Sensor& s): valSense(s.valSense){};
        ~Sensor(){};
        Sensor(T valRcv): valSense(valRcv){};



};

#endif