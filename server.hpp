#ifndef __SERVER_HPP__
#define __SERVER_HPP__
#include <sensor.hpp>

class Server{
private:
    string filename;
    bool consolActivation;
    bool logActivation;

public:
    Server() : filename("\0")
    {
        this->consolActivation = true;
        this->logActivation = false;
    };
    Server(const Server &s) : filename(s.filename), consolActivation(s.consolActivation), logActivation(s.logActivation){};
    Server(string _filename, bool _consolActivation, bool _logActivation) : filename(_filename), consolActivation(_consolActivation), logActivation(_logActivation){};
    ~Server(){};
    Server &operator=(const Server &s)
    {
        this->filename = s.filename;
        this->consolActivation = s.consolActivation;
        this->logActivation = s.logActivation;

        return (*this);
    };
};

#endif
