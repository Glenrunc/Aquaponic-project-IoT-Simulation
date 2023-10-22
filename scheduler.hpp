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

    template <class T>
    void displayData(Sensor<T> &sensor);

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

    void stop()
    {
        this->_running = false;
    }
    bool getRunning(){return this->_running;};
    void userInputScheduler();
    void run();
};

#endif