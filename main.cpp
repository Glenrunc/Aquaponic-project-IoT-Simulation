#include <simulateur.hpp>

int main(int argc, char* argv[]){
    
    Sensor<int> s1("TEMPERATURE",0,90);
    s1.aleaGen();
    s1.consoleWrite();
   
    return 0; 
}