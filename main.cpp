#include <simulateur.hpp>

int main(int argc, char* argv[]){
    // const std::string temperature = "TEMPERATURE";
    Temperature t1("TEMPERATURE");
    Temperature t2(t1);

    t1.consoleWrite();
    t2.consoleWrite();
    return 0; 
}