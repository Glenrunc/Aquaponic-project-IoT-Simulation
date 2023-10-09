#ifndef __SENSOR_HPP__
#define __SENSOR_HPP__

#include <iostream>
#include <random>
#include <string>

static std::random_device rd;
static std::mt19937 gen(rd());

/**
 * @brief Parent Sensor class template<T>
 *
 * @tparam T (bool;float;int). It depends of the sensor
 */
template <typename T>
class Sensor{
protected:
    T valSense;
    std::string nameSensor;
    T min,max;

public:
    Sensor(std::string name_sensor,T _min,T _max):nameSensor(name_sensor),min(_min),max(_max){
        this->valSense = this->aleaGen();
    };
    Sensor(const Sensor<T>& s){
        this->valSense = s.valSense;
        this->nameSensor = s.nameSensor;
        this->min = s.min;
        this->max = s.max;
    };

    Sensor<T>& operator=(const Sensor<T>& s){
        this->valSense = s.valSense;
        this->nameSensor = s.nameSensor;
        this->min = s.min;
        this->max = s.max;
        
        return(*this);
    };
    ~Sensor(){};

    T aleaGen(){
        std::uniform_real_distribution<float> dist(this->min, this->max);
        return (T)(dist(gen));
    };
};
#endif