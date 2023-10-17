/**
 * @file server.cpp
 * @author Mattéo Pourcine 
 * @brief Implentation of the Server.hpp 's functions :|
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <server.hpp>

/**
 * @brief Construct a new Server:: Server object
 * 
 */
Server::Server(){
    this->_consol_activation = false;
    this->_log_activation = false;
}

/**
 * @brief Overloading "=" operator 
 * 
 * @param s Server& 
 * @return Server::Server& 
 */
Server& Server::operator=(const Server &s){
      if (this != &s){
          this->_consol_activation = s._consol_activation;
          this->_log_activation = s._log_activation;
      }
      return (*this);
}

/**
 * @brief Construct a new Server object
 * 
 * @param consolActivation 
 * @param logActivation 
 */
Server::Server(bool consolActivation, bool logActivation)
{
    this->_consol_activation = consolActivation;
    this->_log_activation = logActivation;
}

/**
 * @brief Get the Time object
 * 
 * @return string 
 */
string Server::getTime(){
    time_t now = time(0);           // current date/time based on current system
    std::string date = ctime(&now); // convert now to string form
    date.pop_back();                // delete the "\n" at the end of the string
    return date;
}

/**
 * @brief Get the Day And Year object
 * 
 * @return string 
 */
string Server::getDayAndYear(){
    time_t now = time(0);
    struct tm *timeinfo = localtime(&now);
    int day = timeinfo->tm_mday;         // Day of the month (1-31)
    int month = timeinfo->tm_mon + 1;
    int year = 1900 + timeinfo->tm_year; // Year since 1900
    return "_" + std::to_string(day) + "_" + std::to_string(month)+ "_" + std::to_string(year);
}

