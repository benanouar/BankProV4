#include "Utils.h"

#include <ctime>
#include <iomanip>
#include <limits>

using namespace std;

const string RESET  = "\033[0m";
const string RED    = "\033[31m";
const string GREEN  = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE   = "\033[34m";
const string CYAN   = "\033[36m";
void Utils::clearScreen()
{
    system("clear");
}
void Utils::line()
{
    cout << "============================================================\n";
}void Utils::title(string text)
{
    cout << BLUE;

    line();

    cout << "                 " << text << endl;

    line();

    cout << RESET;
}
void Utils::success(string text)
{
    cout << GREEN
         << "[SUCCESS] "
         << text
         << RESET
         << endl;
}
void Utils::error(string text)
{
    cout << RED
         << "[ERROR] "
         << text
         << RESET
         << endl;
}
void Utils::warning(string text)
{
    cout << YELLOW
         << "[WARNING] "
         << text
         << RESET
         << endl;
}
void Utils::pause()
{
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
string Utils::currentDate()
{
    time_t now = time(nullptr);

    tm *t = localtime(&now);

    char buffer[20];

    strftime(buffer,
             sizeof(buffer),
             "%d/%m/%Y",
             t);

    return buffer;
}
string Utils::currentTime()
{
    time_t now = time(nullptr);

    tm *t = localtime(&now);

    char buffer[20];

    strftime(buffer,
             sizeof(buffer),
             "%H:%M:%S",
             t);

    return buffer;
}

