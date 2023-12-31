/**
 * @file server.hpp
 * @author Mattéo Pourcine
 * @brief Server Class definition
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __SERVER_HPP__
#define __SERVER_HPP__

#include <sensor.hpp>
/**
 * @brief Server class in which you could find some functions to write into a standard output and a file
 *
 */
class Server
{
private:
    bool _consol_activation;
    bool _log_activation;
    bool _unique_file;
    std::mutex consoleMutex; // Add a mutex for console access

public:
    Server();
    Server(const Server &s) : _consol_activation(s._consol_activation), _log_activation(s._log_activation), _unique_file(s._unique_file){};
    Server &operator=(const Server &s);
    Server(bool consolActivation, bool logActivation,bool uniqueFile);
    virtual ~Server(){};

    string getTime();
    string getDayAndYear();

    bool getLog() { return _log_activation; };
    bool getConsol() { return _consol_activation; };
    bool getUnique() { return _unique_file;}
    template <class T>
    void consoleWrite(T val, string nameSensor, string unit) // Usefull to write in the consol
    {
        std::lock_guard<std::mutex> lock(this->consoleMutex);
        cout << this->getTime() << " : " << nameSensor << " " << val << " " << unit << "\n";
    }

    template <class T>
    void fileWrite(string nameSensor, string folderName, T val, string unit,bool uniqueFile) // UseFull to write in a file of your choice
    {
        if (this->_log_activation)
        {
            std::filesystem::create_directories(folderName); // Doesn't create if folder is here
            std::ofstream file;
            if(uniqueFile == false){
                // Each sensor has a file
                string filePath = folderName + '/' + nameSensor + this->getDayAndYear() + ".txt";
                file.open(filePath, std::ios::app);
                if (file)
                {
                    file << this->getTime() << " , " << val << " , " << unit << endl;
                }
                else
                {
                    cerr << "file errror, couldn't open the right file" << endl;
                }
            }

             if(uniqueFile == true){ // unique file
                string filePath = folderName + '/' + "sensors_values" + this->getDayAndYear() + ".txt";
                file.open(filePath, std::ios::app);
                if (file)
                {
                    file << this->getTime() << " , "<<nameSensor<<" , "<< val << " , " << unit << endl;
                }
                else
                {
                    cerr << "file errror, couldn't open the right file" << endl;
                }
             }
            file.close();
        }
    }

    void stopLog();
    void stopConsole();
    void onLog();
    void onConsole();
};

#endif
