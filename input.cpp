/**
 * @file input.cpp
 * @author Pourcine Mattéo
 * @brief Implementation of input.hpp's functions
 * @version 0.1
 * @date 2023-10-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <input.hpp>
/**
 * @brief Flush buffer
 *
 */
void flushInput()
{
    cin.clear();                                                   // Clear any error flags that may be set
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard any characters in the buffer
}
/**
 * @brief Int iput check
 *
 * @return int
 */
int userInput()
{
    int num;
    while (!(cin >> num) || num <= 1000)
    {
        cout << "Invalid input (Must be >1000). Please enter a valid number." << endl;
        flushInput(); // Discard input buffer
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush the newline character

    return num;
}
/**
 * @brief Verification of a selection of char
 *
 * @param verifications
 * @return char
 */
char charInput(vector<char> &verifications)
{
    char input;
    while (true)
    {
        cin >> input;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush the input buffer
        for (char verification : verifications)
        {
            if (input == verification)
            {
                return input;
            }
        }

        cout << "Invalid input. Please enter one of the specified characters: ";
        for (char verification : verifications)
        {
            cout << "'" << verification << "'  ";
        }
        cout << endl;
    }
}
/**
 * @brief Get the String object
 *
 * @return string
 */
string getString()
{

    string userInput;

    cout << "Please enter a string: ";
    std::getline(cin, userInput);

    cout << "You entered: " << userInput << endl;

    return userInput;
}
/**
 * @brief Usefull for fill frequency and name of sensor
 *
 * @param originSensor
 * @param verif
 * @return std::pair<int, string>
 */
std::pair<int, string> buildSensor(string originSensor, vector<char> &verif)
{
    char inputCheck = ' ';
    int frequency = 0;
    string nameSensor = "UNKNOWN";

    cout << "Do you want a " << originSensor << " sensor?(y/n) \n"
         << endl;
    inputCheck = charInput(verif);

    if (inputCheck == 'Y' || inputCheck == 'y')
    {
        cout << "Choose a frequency in millisecond > 1000\n " << endl;
        frequency = userInput();
        cout << "Choose a nameSensor\n " << endl;
        nameSensor = getString();
    }

    return std::make_pair(frequency, nameSensor);
}
