#include <sheduler.hpp>

int main(int argc, char* argv[]){
    /**TEST SYSTEM RUNNING*/
    Server s(true,true);
    Temperature temperature(-60.0,60.0,2000,"temperature");
    Humidity humidity;
    Sound sound;
    Light light(1000,"light");


    Scheduler scheduler(s,temperature,humidity,sound,light);
    
    scheduler.run();

    return 0;
}