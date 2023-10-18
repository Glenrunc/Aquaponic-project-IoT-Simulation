/**
 * @file input.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <input.hpp>

void flushInput()
{
    cin.clear();                                                   // Clear any error flags that may be set
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard any characters in the buffer
}