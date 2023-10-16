/**
 * @file sensor.hpp
 * @author Mattéo Pourcine
 * @brief
 * @version 0.1
 * @date 2023-10-14
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __SENSOR_HPP__
#define __SENSOR_HPP__

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <filesystem>

using std::string, std::cout,std::cerr, std::endl, std::vector, std::ofstream;

/**
 * @brief Sensor class template<T>
 *
 * @tparam T (bool;float;int). It depends of the sensor
 */
template <class T>
class Sensor
{
protected:
    T _val_sense;
    string _name_sensor;
    float _sensor_frequency;
    
public:
    T sendData() { return this->_val_sense; };
    virtual T aleaGen() = 0;
};
/**
 * @brief Child of Sensor -> temperature
 *
 */
class Temperature : public Sensor<float>
{
private:
    float _min, _max;

public:
    Temperature() : _min(0), _max(0) 
    {
        this->_name_sensor = "UNKNOWN";
        this->_val_sense = 0;
        this->_sensor_frequency = 0;

    };
    Temperature(float min, float max,float sensorFrequency, std::string nameSensor) : _min(min), _max(max)
    {   
        this->_sensor_frequency = sensorFrequency;
        this->_name_sensor = nameSensor;
        this->_val_sense = this->aleaGen();
        
    };
    Temperature(const Temperature &t)
    {   
        this->_sensor_frequency = t._sensor_frequency;
        this->_name_sensor = t._name_sensor;
        this->_val_sense = t._val_sense;
        this->_min = t._min;
        this->_max = t._max;
    };
    Temperature &operator=(const Temperature &t)
    {
        if (this != &t)
        {
            this->_sensor_frequency = t._sensor_frequency;
            this->_val_sense = t._val_sense;
            this->_min = t._min;
            this->_max = t._max;
        }
        return (*this);
    };

    float aleaGen()
    {
        std::mt19937 gen(std::random_device{}());
        std::uniform_real_distribution dist(this->_min, this->_max);
        return dist(gen);
    }
    virtual ~Temperature(){};
};

/**
 * @brief Child class of temperature -> Humidity
 *
 */
// Obviously a temperature sensor is not a humidity sensor. But in my implementation it's more usefull
class Humidity : public Temperature
{
public:
    Humidity() {}
    Humidity(float min, float max,float sensorFrequency, std::string nameSensor) : Temperature(min, max,sensorFrequency, nameSensor) {}
    virtual ~Humidity(){};
};

/**
 * @brief Child class of sensor -> Sound
 *
 */
class Sound : public Sensor<int>
{
private:
    int _min, _max;

public:
    Sound() : _min(0), _max(0)
    {
        this->_name_sensor = "UNKNOWN";
        this->_val_sense = 0;
        this->_sensor_frequency = 0;
    };
    Sound(int min, int max,float sensorFrequency, std::string nameSensor) : _min(min), _max(max)
    {   
        this->_name_sensor = nameSensor;
        this->_val_sense = this->aleaGen();
        this->_sensor_frequency = sensorFrequency;

    };
    Sound(const Sound &s)
    {
        this->_sensor_frequency = s._sensor_frequency;
        this->_name_sensor = s._name_sensor;
        this->_val_sense = s._val_sense;
        this->_min = s._min;
        this->_max = s._max;
    };
    Sound &operator=(const Sound &s)
    {
        if (this != &s)
        {
            this->_sensor_frequency = s._sensor_frequency;
            this->_val_sense = s._val_sense;
            this->_min = s._min;
            this->_max = s._max;
        }
        return (*this);
    };

    int aleaGen()
    {
        std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution dist(this->_min, this->_max);
        return dist(gen);
    }
    virtual ~Sound(){};
};

class Light : public Sensor<bool>
{
public:
    Light()
    {
        this->_name_sensor = "UNKNOWN";
        this->_val_sense = false;
        this->_sensor_frequency = 0;
    };
    Light(float sensorFrequency, std::string nameSensor)
    {
        this->_name_sensor = nameSensor;
        this->_val_sense = this->aleaGen();
        this->_sensor_frequency = sensorFrequency;
    };
    Light(const Light &l)
    {   
        this->_sensor_frequency = l._sensor_frequency;
        this->_name_sensor = l._name_sensor;
        this->_val_sense = l._val_sense;
    };
    Light &operator=(const Light &l)
    {
        if (this != &l)
        {   
            this->_sensor_frequency = l._sensor_frequency;
            this->_name_sensor = l._name_sensor;
            this->_val_sense = l._val_sense;
        }
        return (*this);
    };

    bool aleaGen()
    {
        std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution dist(0,1);
        return dist(gen);
    }
    virtual ~Light(){};

};


#endif