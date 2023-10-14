#ifndef __SERVER_HPP__
#define __SERVER_HPP__
#include <sensor.hpp>


class Server{
private:
    
    vector<string> filename;
    bool consolActivation;
    bool logActivation;

public:
    Server(){
        this->consolActivation = false;
        this->logActivation = false;
    };
    Server(const Server &s) : filename(s.filename), consolActivation(s.consolActivation), logActivation(s.logActivation){};
    ~Server(){};
    Server &operator=(const Server &s){
        if (this != &s){
            this->filename = s.filename;
            this->consolActivation = s.consolActivation;
            this->logActivation = s.logActivation;
        }
        return (*this);
    };
};

#endif
