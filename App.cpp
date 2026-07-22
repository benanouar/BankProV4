#include "App.h"
#include "Dashboard.h"

#include <iostream>

using namespace std;

void App::run()
{
    Dashboard::show();

    int choice;

    cout << "Choice: ";
    cin >> choice;
}
