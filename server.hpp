#ifndef __SERVER_HPP__
#define __SERVER_HPP__

#include <sensor.hpp>

class Server
{
private:
    bool _consol_activation;
    bool _log_activation;

public:
    Server();
    Server(const Server &s) : _consol_activation(s._consol_activation), _log_activation(s._log_activation){};
    virtual ~Server(){};
    Server &operator=(const Server &s);
    Server(bool consolActivation, bool logActivation);
    string getTime();
    string getDayAndYear();

    template <class T>
    void consoleWrite(T val, string nameSensor, string unity)
    {
        cout << this->getTime() << " : " << nameSensor << " " << val << " " << unity << "\n";
    }

    template <class T>
    void fileWrite(string nameSensor, string folderName, T val, bool uniqueFile)
    {

        if (this->_log_activation)
        {

            std::filesystem::create_directories(folderName); // Doesn't create if folder is here
            std::ofstream file;
            if (uniqueFile == false)
            { // Each sensor has a file
                string filePath = folderName + '/' + nameSensor + ".txt";
                file.open(filePath, std::ios::app);

                if (file) ///< test if the file is correctly open
                {
                    file << this->getTime() << " , " << val << endl;
                }
                else
                {
                    cerr << "file errror, couldn't open the right file" << endl;
                }

                file.close();
            }
            else
            {

                string filePath = folderName + '/' + "log" + this->getDayAndYear() + ".txt";
                file.open(filePath, std::ios::app);

                if (file) ///< test if the file is correctly open
                {
                    file << this->getTime() << " , " << nameSensor << " : " << val << endl;
                }
                else
                {
                    cerr << "file errror, couldn't open the right file" << endl;
                }

                file.close();
            }
        }
    }
};

#endif
