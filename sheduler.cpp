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

/**
 * @brief
 *
 * @tparam T
 * @param sensor
 */
template <class T>
void Scheduler::displayData(Sensor<T> &sensor)
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

/**
 * @brief
 *
 */
void Scheduler::userInputSheduler()
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
/**
 * @brief
 *
 */
void Scheduler::run()
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