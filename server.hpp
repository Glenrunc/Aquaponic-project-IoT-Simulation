#ifndef __SERVER_HPP__
#define __SERVER_HPP__

#include <sensor.hpp>


class Server{
private:

    bool _consol_activation;
    bool _log_activation;
    

public:
    Server(){
        this->_consol_activation = false;
        this->_log_activation = false;
    };
    Server(const Server &s) :_consol_activation(s._consol_activation), _log_activation(s._log_activation){};
    ~Server(){};
    Server &operator=(const Server &s){
        if (this != &s){
            this->_consol_activation = s._consol_activation;
            this->_log_activation = s._log_activation;
        }
        return (*this);
    };

    Server(bool consolActivation, bool logActivation){
            this->_consol_activation = consolActivation;
            this->_log_activation = logActivation;
    }

    string getTime(){

     	time_t now = time(0);//< current date/time based on current system
	    std::string date = ctime(&now);//< convert now to string form
	    date.pop_back();//<delete the "\n" at the end of the string

        return date;
    }

    template <class T>
    void consoleWrite(T val, string nameSensor,string unity){
        cout<< this->getTime()<<" : "<<nameSensor<<" "<<val<<" "<<unity<<"\n"; 
    }

    template <class T>
    void fileWrite(string nameSensor,string folderName, T val, bool uniqueFile){

        if(this->_log_activation){
            if(uniqueFile == false ){ // Each sensor has a file
                std::filesystem::create_directories(folderName);
                string filePath = folderName +'/'+ nameSensor + ".txt";
			    std::ofstream file;
			    file.open(filePath,std::ios::app);

			    if (file) ///< test if the file is correctly open
			    {
			    	file << this->getTime() << " , " <<val<<endl;
			    }
			    else
			    {
			    	cerr << "file errror, couldn't open the right file" << endl;
			    }

			    file.close();
            }

            //TODO UNIQUE FILE
        }
    }
};

#endif
