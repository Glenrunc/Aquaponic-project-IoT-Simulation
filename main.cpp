#include <sheduler.hpp>

int main(int argc, char* argv[]){
    Temperature t(-60.0,60.0,"Temp");
    for(int i= 0; i<10;i++){
        t.consoleWrite();
    }
    return 0; 
}