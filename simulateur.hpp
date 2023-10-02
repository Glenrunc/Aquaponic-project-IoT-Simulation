#ifndef __SIMULATEUR_HPP__
#define __SIMULATEUR_HPP__

#include <iostream>
#include <random>
#include <string>

class Server{
private:
    int nbOfSensor;
    bool consolActivation;
    bool logActivation;

public:
    Server(){};
    Server(const Server &s) : nbOfSensor(s.nbOfSensor), consolActivation(s.consolActivation), logActivation(s.logActivation){};
    Server(int nbOfSensor, bool consolActivation, bool logActivation) : nbOfSensor(nbOfSensor), consolActivation(consolActivation), logActivation(logActivation){};
    ~Server(){};
    Server &operator=(const Server &);

    friend std::iostream &operator<<(std::iostream &os, const Server &s)
    {
        return os;
    };
};

template <typename T>
class Sensor{

protected:
    T valSense;

public:
    Sensor(){};
    Sensor(const Sensor &s) : valSense(s.valSense){};
    ~Sensor(){};
    Sensor &operator=(const Sensor &);

    Sensor(T valRcv) : valSense(valRcv){};

    // virtual T aleaGen();
};

class Temperature : protected Sensor<float>{

private:
    std::string nameSensor;
    // float aleaGen() { return 0.6; };

public:
    Temperature(){};
    Temperature(const Temperature &t) : Sensor<float>(t), nameSensor(t.nameSensor){};
    Temperature(float valSense, const std::string _namesensor): Sensor<float>(valSense),nameSensor(_namesensor){};
  
};

#endif