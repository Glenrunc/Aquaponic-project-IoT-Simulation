#ifndef __SENSOR_HPP__
#define __SENSOR_HPP__

#include <iostream>
#include <random>
#include <string>

using namespace std;
static std::random_device rd;
static std::mt19937 gen(rd());

/**
 * @brief Sensor class template<T>
 *
 * @tparam T (bool;float;int). It depends of the sensor
 */
template <typename T>
class Sensor
{
protected:
    T valSense;
    std::string nameSensor;

public:
    T sendData(){ return this->valSense;};//TODO
    virtual T aleaGen() = 0;
};

class Temperature : public Sensor<float>{
private:
    float min, max;

public:
    Temperature() : min(0), max(0){
        this->nameSensor = "UNKNOWN";
        this->valSense = 0;
    };
    Temperature(float _min, float _max, std::string _nameSensor) : min(_min), max(_max){
        this->nameSensor = _nameSensor;
        this->valSense = this->aleaGen();
    };
    Temperature(const Temperature &t){
        this->nameSensor = t.nameSensor;
        this->valSense = t.valSense;
        this->min = t.min;
        this->max = t.max;
    };
    Temperature &operator=(const Temperature &t){
        this->valSense = t.valSense;
        this->min = t.min;
        this->max = t.max;
        return (*this);
    };

    float aleaGen(){
        std::uniform_real_distribution dist(this->min, this->max);
        return dist(gen);
    }
    virtual ~Temperature(){};
};

// Obviously a temperature sensor is not a humidity sensor. But in my implementation it's more usefull
class Humidity : public Temperature{
public:
    Humidity() {}
    Humidity(float _min, float _max, std::string _nameSensor) : Temperature(_min, _max, _nameSensor) {}
    virtual ~Humidity(){};
};

class Sound : public Sensor<int>{
private:
    int min, max;

public:
    Sound() : min(0), max(0){
        this->nameSensor = "UNKNOWN";
        this->valSense = 0;
    };
    Sound(int _min, int _max, std::string _nameSensor) : min(_min), max(_max){
        this->nameSensor = _nameSensor;
        this->valSense = this->aleaGen();
    };
    Sound(const Sound &s){
        this->nameSensor = s.nameSensor;
        this->valSense = s.valSense;
        this->min = s.min;
        this->max = s.max;
    };
    Sound &operator=(const Sound &s){
        this->valSense = s.valSense;
        this->min = s.min;
        this->max = s.max;
        return (*this);
    };

    int aleaGen(){
        std::uniform_int_distribution dist(this->min, this->max);
        return dist(gen);
    }
    virtual ~Sound(){};
};

class Light : public Sound{
public:
    Light() {}
    Light(int _min, int _max, std::string _nameSensor) : Sound(_min, _max, _nameSensor) {}
    virtual ~Light(){};
};

#endif