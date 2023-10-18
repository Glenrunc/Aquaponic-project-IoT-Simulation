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

#include <random>
#include <string>
#include <ctime>
#include <fstream>
#include <filesystem>
#include <thread>
#include <chrono>
#include <mutex>
#include <cstdlib>
#include <input.hpp>

#ifdef _WIN32
#define CLEAN "cls" // This will clear the console screen on Windows
#else
#define CLEAN "clear" // This will clear the console screen on Unix-based systems
#endif

/**
 * @brief Sensor class template<T>
 *
 * @tparam T (bool;float;int). It depends of the sensor
 */
template <class T>
class Sensor
{

protected:
    T _min;
    T _max;
    T _val_sense;
    string _name_sensor;
    string _unit;          // Usefull for console writing
    int _sensor_frequency; // in millisecond !

public:
    Sensor() { this->_name_sensor = "UNKNOWN"; };
    Sensor(float min, float max, float sensorFrequency, std::string nameSensor)
    {

        this->_min = min;
        this->_max = max;
        this->_sensor_frequency = sensorFrequency;
        this->_name_sensor = nameSensor;
    }
    T sendData()
    {
        this->_val_sense = this->aleaGen();
        return this->_val_sense;
    };
    string getNameSensor() { return this->_name_sensor; };
    string getUnit() { return this->_unit; };
    int getSensorFrequency() { return this->_sensor_frequency; };
    virtual T aleaGen() = 0;
};

/**
 * @brief Child of Sensor -> temperature
 *
 */
class Temperature : public Sensor<float>
{

public:
    Temperature() : Sensor(){};

    Temperature(float min, float max, float sensorFrequency, std::string nameSensor) : Sensor(min, max, sensorFrequency, nameSensor)
    {
        this->_val_sense = this->aleaGen();
        this->_unit = "°C";
    };

    float aleaGen()
    {

        std::mt19937 gen(std::random_device{}());
        std::uniform_real_distribution dist(this->_min, this->_max);
        return dist(gen);
    };

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
    Humidity() : Temperature(){};
    Humidity(float min, float max, float sensorFrequency, std::string nameSensor) : Temperature(min, max, sensorFrequency, nameSensor)
    {
        this->_unit = "%";
    };
    virtual ~Humidity(){};
};

/**
 * @brief Child class of sensor -> Sound
 *
 */
class Sound : public Sensor<int>
{

public:
    Sound() : Sensor() {}

    Sound(int min, int max, float sensorFrequency, std::string nameSensor) : Sensor(min, max, sensorFrequency, nameSensor)
    {

        this->_val_sense = this->aleaGen();
        this->_unit = "dB";
    };

    int aleaGen()
    {

        std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution dist(this->_min, this->_max);
        return dist(gen);
    };
    virtual ~Sound(){};
};
/**
 * @brief Child class of Sensor<bool>
 *
 */
class Light : public Sensor<bool>
{
public:
    Light() : Sensor() {}

    Light(bool min, bool max, float sensorFrequency, std::string nameSensor) : Sensor(min, max, sensorFrequency, nameSensor)
    {

        this->_val_sense = this->aleaGen();
        this->_unit = " ";
    };

    bool aleaGen()
    {
        std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution dist(0, 1);
        return dist(gen);
    };

    virtual ~Light(){};
};

#endif