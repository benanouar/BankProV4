#include "ReportManager.h"
#include "UI.h"
#include "Utils.h"

#include <iostream>

using namespace std;

ReportManager::ReportManager(
    CustomerManager* customerManager,
    AccountManager* accountManager,
    TransactionManager* transactionManager,
    CardManager* cardManager
)
{
    this->customerManager = customerManager;
    this->accountManager = accountManager;
    this->transactionManager = transactionManager;
    this->cardManager = cardManager;
}
void ReportManager::bankSummary()
{
    UI::drawHeader("BANK SUMMARY");

    cout << "Customers     : " << customerManager->getCount() << endl;
    cout << "Accounts      : " << accountManager->getCount() << endl;
    cout << "Transactions  : " << transactionManager->getCount() << endl;
    cout << "Cards         : " << cardManager->getCount() << endl;
}
void ReportManager::customerReport()
{
    Utils::warning("Coming soon...");
}

void ReportManager::accountReport()
{
    Utils::warning("Coming soon...");
}

void ReportManager::transactionReport()
{
    Utils::warning("Coming soon...");
}
void ReportManager::menu()
{
    int choice;

    do
    {
        UI::drawHeader("REPORTS");

        cout << "1. Bank Summary\n";
        cout << "2. Customer Report\n";
        cout << "3. Account Report\n";
        cout << "4. Transaction Report\n";
        cout << "5. Back\n\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                bankSummary();
                Utils::pause();
                break;

            case 2:
                customerReport();
                Utils::pause();
                break;

            case 3:
                accountReport();
                Utils::pause();
                break;

            case 4:
                transactionReport();
                Utils::pause();
                break;

            case 5:
                break;

            default:
                Utils::error("Invalid choice.");
                Utils::pause();
        }

    } while (choice != 5);
}

