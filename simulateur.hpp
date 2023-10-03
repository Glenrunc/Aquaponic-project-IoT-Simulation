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

private:

    const std::string nameSensor;
    T valSense;
    T min,max;
    
public:

    Sensor(){};
    Sensor(const Sensor &s) : valSense(s.valSense),nameSensor(s.nameSensor),min(s.min),max(s.max){};
    ~Sensor(){};
    Sensor(const std::string _nameSensor,T _min,T _max): nameSensor(_nameSensor),min(_min),max(_max){};
    Sensor &operator=(const Sensor &);
    Sensor(T valRcv) : valSense(valRcv){};

    void aleaGen(); //implement here

    void consoleWrite(){
        std::cout<<this->nameSensor<<": "<<this->valSense<<std::endl;
    }
};

// class Temperature : protected Sensor<float>{

// private:
//     std::string nameSensor;
    

// public:
//     Temperature(){};
//     Temperature(const Temperature &t) : Sensor<float>(t), nameSensor(t.nameSensor){};
//     Temperature(const std::string _namesensor): Sensor<float>(valSense),nameSensor(_namesensor){};//replace valSense apar alea gen
//     float aleaGen(); 
// };

#endif