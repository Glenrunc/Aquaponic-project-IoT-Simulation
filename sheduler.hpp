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
    void displayData(Sensor<T> &sensor)
    {

        if (!(sensor.getNameSensor() == "UNKNOWN"))
        {
            bool log = this->_server.getLog();
            bool consol = this->_server.getConsol();

            if (log && consol)
            {
                this->_server.fileWrite(sensor.getNameSensor(), "logs", sensor.sendData(), sensor.getUnit());
                this->_server.consoleWrite(sensor.sendData(), sensor.getNameSensor(), sensor.getUnit());
            }
            else if (consol)
            {
                this->_server.consoleWrite(sensor.sendData(), sensor.getNameSensor(), sensor.getUnit());
            }
            else if (log)
            {
                this->_server.fileWrite(sensor.getNameSensor(), "logs", sensor.sendData(), sensor.getUnit());
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(sensor.getSensorFrequency()));
        }
    }

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

    void userInputSheduler()
    {
        char input;
        cout << "Press 'q' to stop the scheduler. 'l/o' to log/off log writing. 'c/s' to console/stop console writing\n"
             << endl;

        while (true)
        {
            flushInput();

            if ((this->_server.getConsol() == false) && (this->_server.getLog() == false))
            {
                cout << "Warning you have disable the consol writing and file writing \n\nDo you want to continue 'c' to activate console, 'l' to activate log and 'q' ?" << endl;
            }

            cin >> input;
            if (input == 'q')
            {
                this->stop();
                break;
            }
            if (input == 'o')
            {
                this->_server.stopLog();
            }
            if (input == 's')
            {
                this->_server.stopConsole();
            }
            if (input == 'c')
            {
                this->_server.onConsole();
            }
            if (input == 'l')
            {
                this->_server.onLog();
            }
        }
    }
    void run()
    {
        while (this->_running == true)
        {
            std::thread threadDispTemp([&]()
                                       {
                    while(this-> _running == true){
                        displayData<float>(_temperature);
                    } });

            std::thread threadDispHumi([&]()
                                       {
                    while(this-> _running == true){
                        displayData<float>(_humidity);
                    } });

            std::thread threadDispSound([&]()
                                        {
                    while(this-> _running == true){
                        displayData<int>(_sound);
                    } });

            std::thread threadDispLight([&]()
                                        {
                    while(this-> _running == true){
                        displayData<bool>(_light);
                    } });

            threadDispTemp.join();
            threadDispHumi.join(); // Wait for ending thread
            threadDispSound.join();
            threadDispLight.join();
        }
        if (this->_running == false)
        {

            cout << "SCHEDULER DISABLE" << endl;
        }
    }
};

#endif