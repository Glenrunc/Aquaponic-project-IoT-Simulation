#include <sheduler.hpp>

int main(int argc, char* argv[]){
    /**TEST SYSTEM RUNNING*/
    Server s(false,false);
    Temperature temperature(-60.0,60.0,2000,"temperature");
    Humidity humidity(0,100,3000,"humidity");
    Sound sound(0,250,10000,"sound");
    Light light(1000,"light");


    Sheduler sheduler(s,temperature,humidity,sound,light);
    
    sheduler.run();

    return 0;
}