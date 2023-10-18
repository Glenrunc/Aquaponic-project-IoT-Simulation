#include <sheduler.hpp>
#include <input.hpp>
int main(int argc, char *argv[])
{
    // bool consolActivation;
    // bool fileActivation;

    // //Clean the command prompt before begining
    // system(CLEAN);
    // //System's presentation
    // cout << "\t\t\t\t~WELCOME TO THE IoT SIMULATION~\n\nHere we are -> So you have 4 sensors (temperature, humidity, sound and light).\n\nYou can choose there names, there ranges of detection and there frequencies at which they will be displaying in the command prompt or file.\n\nYou can also choose to display there values or not as you want, just follow these instructions\n\n\n"<<endl;

    /**TEST SYSTEM RUNNING*/
    Server s(true, true);
    Temperature temperature(-60.0, 60.0, 1000, "temperature");
    Humidity humidity(0, 100, 1000, "humidity");
    Sound sound(0, 250, 1000, "sound");
    Light light(false, true, 1000, "light");

    Scheduler scheduler(s, temperature, humidity, sound, light);

    // BEGINNING OF THE IoT System
    std::thread inputThread(&Scheduler::userInputSheduler, &scheduler);
    std::thread runScheduler(&Scheduler::run, &scheduler);

    inputThread.join();
    runScheduler.join();

    return 0;
}