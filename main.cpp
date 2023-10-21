/**
 * @file main.cpp
 * @author Pourcine Mattéo
 * @brief Main part of the project -> SYSTEM RUNNING 
 * @version 0.1
 * @date 2023-10-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <scheduler.hpp>

int main(int argc, char *argv[])
{
    char charInputUser = ' ';
    bool consolActivation = false;
    bool fileActivation = false;
    vector<char> verif = {'Y', 'y', 'N', 'n'};
    std::pair<int, string> build;
    // Clean the command prompt before begining
    system(CLEAN);


    // System's presentation
    cout << "\t\t\t\t~WELCOME TO THE IoT SIMULATION~\n\nHere we are -> So you have 4 sensors (temperature, humidity, sound and light).\n\nYou can choose there names and there frequencies at which they will be displaying in the command prompt or file.\n\nYou can also choose to display there values or not as you want during the execution, just follow these instructions\n\n\n"
         << endl;


    //User choose to activate the log or not
    cout << "Do you want to activate log (y/n) ?\n"
         << endl;
    charInputUser = charInput(verif);
    if (charInputUser == 'Y' || charInputUser == 'y')
    {
        fileActivation = true;
    }
    cout << "Do you want to activate console (y/n) ?\n"
         << endl;
    charInputUser = charInput(verif);
    if (charInputUser == 'Y' || charInputUser == 'y')
    {
        consolActivation = true;
    }

    if ((fileActivation == false) && (consolActivation == false))
    {
        cout << "Sheduler is not displaying any information, SYSTEM DISABLE\n"
             << endl;
        return 0;
    }

    Server server(consolActivation, fileActivation);



    //Here we build the sensor 
    build = buildSensor("temperature", verif);
    Temperature temperature(-60.0, 60.0, build.first, build.second);

    build = buildSensor("humidity", verif);
    Humidity humidity(0, 100, build.first, build.second);

    build = buildSensor("sound", verif);
    Sound sound(0, 200, build.first, build.second);

    build = buildSensor("light", verif);
    Light light(false, true, build.first, build.second);
    
    system(CLEAN);



    /**TEST SYSTEM RUNNING*/
    if (temperature.getNameSensor() == "UNKNOWN" && humidity.getNameSensor() == "UNKNOWN" && sound.getNameSensor() == "UNKNOWN" && light.getNameSensor() == "UNKNOWN")
    {
        cout << "No sensor enable, SYSTEM DISABLE\n"
             << endl;
        return 0;
    }
    

    Scheduler scheduler(server, temperature, humidity, sound, light);

    // BEGINNING OF THE IoT System
    std::thread inputThread(&Scheduler::userInputScheduler, &scheduler);
    std::thread runScheduler(&Scheduler::run, &scheduler);

    inputThread.join();
    runScheduler.join();

    return 0;
}