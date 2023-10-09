#include <server.hpp>

int main(int argc, char* argv[]){

    Sensor<float> s("Temperature",-60.0,60.0);
    Sensor<float> s1(s);
    Sensor<int> s2("Sound",0,200);

    // s.consolWrite();
    s1.consolWrite();
    s2.consolWrite();
    
    return 0; 
}