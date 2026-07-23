#include "App.h"
#include "Dashboard.h"
#include "Utils.h"
#include <iostream>

using namespace std;

void App::run()
{
int choice;

do
{
    Dashboard::show();

    cout << "Choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            customerManager.menu();
            Utils::pause();
            break;

        case 9:
            Utils::warning("Goodbye!");
            break;

        default:
            Utils::warning("Coming soon...");
            Utils::pause();
    }

} while (choice != 9);
}
