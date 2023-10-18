/**
 * @file sheduler.cpp
 * @author Pourcine Mattéo
 * @brief Scheduler.cpp implementation of .hpp file
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <sheduler.hpp>

/**
 * @brief Construct a new Scheduler:: Scheduler object
 *
 * @param scheduler
 */
Scheduler::Scheduler(const Scheduler &scheduler)
{

    this->_server = scheduler._server;
    this->_temperature = scheduler._temperature;
    this->_humidity = scheduler._humidity;
    this->_sound = scheduler._sound;
    this->_light = scheduler._light;
    this->_running = scheduler._running;
}

/**
 * @brief Overload of "=" operator
 *
 * @param scheduler
 * @return Scheduler&
 */
Scheduler &Scheduler::operator=(const Scheduler &scheduler)
{
    if (this != &scheduler)
    {

        this->_server = scheduler._server;
        this->_temperature = scheduler._temperature;
        this->_humidity = scheduler._humidity;
        this->_sound = scheduler._sound;
        this->_light = scheduler._light;
        this->_running = scheduler._running;
    }
    return (*this);
}
