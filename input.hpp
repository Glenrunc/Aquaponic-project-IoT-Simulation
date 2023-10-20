/**
 * @file input.hpp
 * @author Pourcine Mattéo
 * @brief definition of some check input functions
 * @version 0.1
 * @date 2023-10-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include <iostream>
#include <limits>
#include <vector>
#include <utility>

using namespace std;
/**
 * @brief Flush buffer
 *
 */
void flushInput();
/**
 * @brief Int iput check
 *
 * @return int
 */
int userInput();
/**
 * @brief Verification of a selection of char
 *
 * @param verifications
 * @return char
 */
char charInput(vector<char> &verifications);
/**
 * @brief Get the String object
 *
 * @return string
 */
string getString();
/**
 * @brief Usefull for fill frequency and name of sensor
 *
 * @param originSensor
 * @param verif
 * @return std::pair<int, string>
 */
std::pair<int, string> buildSensor(string originSensor, vector<char> &verif);
#endif