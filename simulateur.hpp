#ifndef __SIMULATEUR_HPP__
#define __SIMULATEUR_HPP__

#include <iostream>
#include <random>
#include <string>

static int _num_sensor = 0;

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
    std::string nameSensor;
    int num_sensor;

public:
    Sensor(){_num_sensor++; this->num_sensor = _num_sensor;};
    Sensor(const Sensor &s){this->valSense=s.valRcv;this->nameSensor = s.nameSensor;_num_sensor++; this->num_sensor = _num_sensor;};
    ~Sensor(){_num_sensor--;};
    Sensor &operator=(const Sensor &);
    Sensor(T valRcv,std::string _namesensor){this->valSense=valRcv;this->nameSensor = _namesensor;_num_sensor++; this->num_sensor = _num_sensor; };

    virtual T aleaGen() = 0;
};

//IMPLEMENTATION OF NUM_SENSOR TO FINISH 
/**
 * @brief Child Class of Sensor 
 * Currently thinking of how improve this class(other params)
 */
class Temperature : protected Sensor<float>{

private:
    float _min = -60.0;
    float _max = 60.0;

public:
    Temperature(){this->nameSensor = "Temperature Sensor"; this->valSense = this->aleaGen();};
    Temperature(const Temperature &t) : Sensor<float>(t.valSense,t.nameSensor){};
    Temperature &operator=(const Temperature &);
    ~Temperature(){_num_sensor--;};

    float aleaGen()
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_real_distribution<float> dist(this->_min, this->_max);

        return dist(gen);
    };
    void consoleWrite(){
        std::cout<<this->nameSensor<<" "<<this->num_sensor<<": "<<this->valSense<<std::endl;
    }
};

#endif