#ifndef __SHEDULER_HPP__
#define __SHEDULER_HPP__

#include <sensor.hpp>

// class Sheduler{
//     private:
//         Sensor<float> temperature;
//         Sensor<float> humidity;
//         Sensor<int> sound;
//         Sensor<int> light;
//         float time;

//     public:
//         Sheduler():
//             temperature("Temperature Sensor",-60.0,60.0),
//             humidity("Humidity Sensor",0,100),
//             sound("Sound Sensor",0,200),
//             light("Light Sensor",0,1),
//             time(5000)
//         {};

//         ~Sheduler(){};

//         Sheduler(const Sheduler& s):
//             temperature(s.temperature),
//             humidity(s.humidity),
//             sound(s.sound),
//             light(s.light),
//             time(s.time)
//         {};

//         Sheduler& operator=(const Sheduler& s){
//             this->temperature = s.temperature;
//             this->humidity = s.humidity;
//             this->sound = s.sound;
//             this->light = s.light;
//             this ->time = s.time;
//             return (*this);
//         };

// };

#endif