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
#include <scheduler.hpp>

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
 * @brief Will be implement in a thread to display data in the consol or in a file or both
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
 * @brief Check input during the run of sheduler
 *
 */
void Scheduler::userInputScheduler()
{
    std::string input;
    cout << "Press 'q' to stop the scheduler. 'l/o' to log/off log writing. 'c/s' to console/stop console writing\n\n\n Be aware that if you press a world like 'oers' it will stop console writing and log writing because of the 's' and 'o'\n"
         << endl;
    while (true)
    {

        if ((this->_server.getConsol() == false) && (this->_server.getLog() == false))
        {
            cout << "Warning you have disable the consol writing and file writing \n\nDo you want to continue 'c' to activate console, 'l' to activate log or quit 'q' ?" << endl;
        }
        std::getline(std::cin, input);
        for (char c : input)
        {
            if (c == 'q')
            {
                this->stop();
                return;
            }
            else if (c == 'o')
            {
                this->_server.stopLog();
            }
            else if (c == 's')
            {
                this->_server.stopConsole();
            }
            else if (c == 'c')
            {
                this->_server.onConsole();
            }
            else if (c == 'l')
            {
                this->_server.onLog();
            }
        }
    }
}
/**
 * @brief Begin all the thread usefull for the writing
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