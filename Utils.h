#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>

using namespace std;

class Utils
{
public:

    static void clearScreen();

    static void pause();

    static string currentDate();

    static string currentTime();

    static void title(string text);

    static void success(string text);

    static void error(string text);

    static void warning(string text);

    static void line();
};

#endif
