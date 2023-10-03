#ifndef __SIMULATEUR_HPP__
#define __SIMULATEUR_HPP__

#include <iostream>
#include <random>
#include <string>

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
    Server &operator=(const Server &);

    friend std::iostream &operator<<(std::iostream &os, const Server &s)
    {
        return os;
    };
};

/**
 * @brief Parent Sensor class template<T>
 * 
 * @tparam T (bool;float;int). It depends of the sensor
 */
template <typename T>
class Sensor
{

protected:
    T valSense;

public:
    Sensor(){};
    Sensor(const Sensor &s) : valSense(s.valSense){};
    ~Sensor(){};
    Sensor &operator=(const Sensor &);
    Sensor(T valRcv) : valSense(valRcv){};

    virtual T aleaGen() = 0;
};

/**
 * @brief Child Class of Sensor 
 * Currently thinking of how improve this class(other params)
 */
class Temperature : protected Sensor<float>{

private:
    std::string nameSensor;
    float _min = -60.0;
    float _max = 60.0;

public:
    Temperature(){};
    Temperature(const Temperature &t) : Sensor<float>(t.valSense), nameSensor(t.nameSensor){};
    Temperature &operator=(const Temperature &);
    Temperature(std::string _namesensor)
    {
        this->nameSensor = _namesensor;
        this->valSense = this->aleaGen();
    }
    ~Temperature(){};

    float aleaGen()
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_real_distribution<float> dist(this->_min, this->_max);

        return dist(gen);
    };
};

#endif