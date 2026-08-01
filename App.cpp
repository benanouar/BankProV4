#include "App.h"
#include "Dashboard.h"
#include "Utils.h"
#include <iostream>

using namespace std;
App::App()
    : accountManager(&customerManager, &transactionManager),
      cardManager(&accountManager),
      reportManager(
          &customerManager,
          &accountManager,
          &transactionManager,
          &cardManager)
{
}
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
 
        case 2: 
            accountManager.menu();
            Utils::pause();
            break;
        case 3:
            transactionManager.menu();
            Utils::pause();                        
            break;
        case 4:
            cardManager.menu();
            Utils::pause();
            break;
        case 5:
            Utils::warning("Loans module coming soon...");
            Utils::pause();
            break;

        case 6:
            reportManager.menu();
            Utils::pause();
            break;
        case 7:
            Utils::warning("Statistics module coming soon...");
            Utils::pause();
            break;

        case 8:
            Utils::warning("Settings module coming soon...");
            Utils::pause();
            break;

        case 9:
            Utils::warning("Goodbye!");
            break;

            default:
            Utils::error("Invalid choice.");
            Utils::pause();   
}    

} while (choice != 9);
}

