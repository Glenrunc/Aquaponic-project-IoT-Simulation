/**
 * @file Scheduler.hpp
 * @author Mattéo Pourcine
 * @brief Description of the Scheduler class
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __SCHEDULER_HPP__
#define __SCHEDULER_HPP__

#include <server.hpp>

/**
 * @brief Scheduler Class
 *
 */
class Scheduler
{

private:
    Server _server;
    Temperature _temperature;
    Humidity _humidity;
    Sound _sound;
    Light _light;
    bool _running;

public:
    Scheduler(Server server, Temperature temperature, Humidity humidity, Sound sound, Light light) : _server(server),
                                                                                                     _temperature(temperature),
                                                                                                     _humidity(humidity),
                                                                                                     _sound(sound),
                                                                                                     _light(light),
                                                                                                     _running(true){};

    Scheduler(const Scheduler &scheduler);
    Scheduler &operator=(const Scheduler &scheduler);
    virtual ~Scheduler(){};

    template <class T>
    void displayData(Sensor<T> &sensor)
    {
        if (!(sensor.getNameSensor() == "UNKNOWN"))
        {
            if (this->_server.getLog())
            {
                this->_server.fileWrite(sensor.getNameSensor(), "logs", sensor.sendData(), sensor.getUnit());
                std::this_thread::sleep_for(std::chrono::milliseconds(sensor.getSensorFrequency()));
            }
            if (this->_server.getConsol())
            {

                this->_server.consoleWrite(sensor.sendData(), sensor.getNameSensor(), sensor.getUnit());
                std::this_thread::sleep_for(std::chrono::milliseconds(sensor.getSensorFrequency()));
            }
        }
    }
    void run()
    {
        if (this->_server.getLog() && this->_server.getConsol())
        {
            std::thread threadDispTemp([&]()
                                       {
                    while(this->_running){
                        displayData<float>(_temperature);
                    } });

            std::thread threadDispHumi([&]()
                                       {
                    while(this->_running){
                        displayData<float>(_humidity);
                    } });

            std::thread threadDispSound([&]()
                                        {
                    while(this->_running){
                        displayData<int>(_sound);
                    } });

            std::thread threadDispLight([&]()
                                        {
                    while(this->_running){
                        displayData<bool>(_light);
                    } });

            threadDispTemp.join();
            threadDispHumi.join(); // Wait for ending thread
            threadDispSound.join();
            threadDispLight.join();
        }
        else
        {
            cout << "No log writing ! \nNo console writing ! \nSYSTEM DISABLE" << endl;
        }
    }
};

#endif