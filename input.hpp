/**
 * @file input.hpp
 * @author your name (you@domain.com)
 * @brief
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

using std::string, std::cout, std::cerr, std::endl, std::ofstream, std::cin;

char inputCheck(char input, char verification);
void flushInput();

#endif