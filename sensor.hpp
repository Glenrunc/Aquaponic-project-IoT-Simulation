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


// // IMPLEMENTATION OF NUM_SENSOR TO FINISH
// /**
//  * @brief Child Class of Sensor
//  * Currently thinking of how improve this class(other params)
//  */
// class Temperature : public Sensor<float>
// {

// private:
//     float _min = -60.0;
//     float _max = 60.0;

// public:
//     Temperature(){
//         this->nameSensor = "Temperature Sensor";
//         this->valSense = this->aleaGen();
//         _num_sensor++;
//         this->num_sensor = _num_sensor;
//     };
//     Temperature(const Temperature &t){
//         this->nameSensor = t.nameSensor;
//         this->valSense = t.valSense;
//         _num_sensor++;
//         this->num_sensor = _num_sensor;
//     };
//     Temperature &operator=(const Temperature &);
//     ~Temperature(){};

//     float aleaGen(){
//         std::uniform_real_distribution<float> dist(this->_min, this->_max);
//         return dist(gen);
//     };
// };

// class Humidity : public Sensor<float>{

// private:
//     float _min = 0.0;
//     float _max = 100.0;

// public:
//     Humidity(){
//         this->nameSensor = "Humidity Sensor";
//         this->valSense = this->aleaGen();
//         _num_sensor++;
//         this->num_sensor = _num_sensor;
//     };
//     Humidity(const Humidity &h){
//         this->nameSensor = h.nameSensor;
//         this->valSense = h.valSense;
//         _num_sensor++;
//         this->num_sensor = _num_sensor;
//     };
//     Humidity &operator=(const Humidity &);
//     ~Humidity(){};

//     float aleaGen(){
//         std::uniform_real_distribution<float> dist(this->_min, this->_max);
//         return dist(gen);
//     };
// };

// class Light : public Sensor<int>{

// private:
//     int _min = 0;
//     int _max = 1;

// public:
//     Light(){
//         this->nameSensor = "Light Sensor";
//         this->valSense = this->aleaGen();
//         _num_sensor++;
//         this->num_sensor = _num_sensor;
//     };
//     Light(const Light &l){
//         this->nameSensor = l.nameSensor;
//         this->valSense = l.valSense;
//         _num_sensor++;
//         this->num_sensor = _num_sensor;
//     };
//     Light &operator=(const Light &);
//     ~Light(){};

//     int aleaGen(){
//         std::uniform_int_distribution<int> dist(this->_min, this->_max);
//         return dist(gen);
//     };
// };

// class Sound : public Sensor<int>{

// private:
//     int _min = 0;
//     int _max = 180;

// public:
//     Sound(){
//         this->nameSensor = "Sound Sensor";
//         this->valSense = this->aleaGen();
//         _num_sensor++;
//         this->num_sensor = _num_sensor;
//     };
//     Sound(const Sound &l){
//         this->nameSensor = l.nameSensor;
//         this->valSense = l.valSense;
//         _num_sensor++;
//         this->num_sensor = _num_sensor;
//     };
//     Sound &operator=(const Sound &);
//     ~Sound(){};

//     int aleaGen(){
//         std::uniform_int_distribution<int> dist(this->_min, this->_max);
//         return dist(gen);
//     };
//     void consoleWrite(){
//         std::cout<<this->valSense<<std::endl;
//     }
// };


#endif