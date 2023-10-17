#ifndef __SHEDULER_HPP__
#define __SHEDULER_HPP__

#include <server.hpp>

class Sheduler{
    private:
        Server _server;
        Temperature _temperature;
        Humidity _humidity;
        Sound _sound;
        Light _light;

    public:
        Sheduler(Server server, Temperature temperature, Humidity humidity, Sound sound, Light light):
        _server(server),
        _temperature(temperature),
        _humidity(humidity),
        _sound(sound),
        _light(light) {};

        Sheduler(const Sheduler& sheduler){
            this->_server = sheduler._server;
            this->_temperature = sheduler._temperature;
            this->_humidity = sheduler._humidity;
            this->_sound = sheduler._sound;
            this->_light = sheduler._light;

        }

        Sheduler& operator=(const Sheduler& sheduler){
            if(this != &sheduler){
                this->_server = sheduler._server;
                this->_temperature = sheduler._temperature;
                this->_humidity = sheduler._humidity;
                this->_sound = sheduler._sound;
                this->_light = sheduler._light;
            }

            return (*this);
        }
        virtual ~Sheduler(){};

        template <class T>
        void displayData(Sensor<T> & sensor){
                if(this->_server.getLog()){
                    this->_server.fileWrite(sensor.getNameSensor(),"logs",sensor.sendData(),sensor.getUnit());
                    std::this_thread::sleep_for(std::chrono::milliseconds(sensor.getSensorFrequency()));

                if(this->_server.getConsol()){
        
                    this->_server.consoleWrite(sensor.sendData(),sensor.getNameSensor(),sensor.getUnit());
                    std::this_thread::sleep_for(std::chrono::milliseconds(sensor.getSensorFrequency()));
                }
        
            }
        }
        void run(){
            if(this->_server.getLog() && this->_server.getConsol()){
                std::thread threadDispTemp([&]() {
                    while(true) {
                        displayData<float>(_temperature);
                    }
                });

                std::thread threadDispHumi([&]() {
                    while(true) {
                        displayData<float>(_humidity);
                    }
                });

                std::thread threadDispSound([&]() {
                    while(true) {
                        displayData<int>(_sound);
                    }
                });

                std::thread threadDispLight([&]() {
                    while(true) {
                        displayData<bool>(_light);
                    }
                });
                threadDispTemp.join();
                threadDispHumi.join(); // Wait for ending thread
                threadDispSound.join();
                threadDispLight.join();
            }
            else{
                cout << "No log writing ! \nNo console writing ! \nSYSTEM DISABLE" << endl;
            }
        }
       
};


#endif