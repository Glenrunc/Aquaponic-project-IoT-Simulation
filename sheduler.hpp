#ifndef __SHEDULER_HPP__
#define __SHEDULER_HPP__

#include <server.hpp>

class Sheduler{
    private:
        Server _server;
        vector<Temperature> _temperature;
        vector<Humidity> _humidity;
        vector<Sound> _sound;
        vector<Light> _light;
    
    public:

        void run();

       
};

#endif