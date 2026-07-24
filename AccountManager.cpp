#include "AccountManager.h"
#include "UI.h"
#include "Utils.h"

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

const string ACCOUNT_FILE = "Data/accounts.txt";

AccountManager::AccountManager()
{
    load();
}
void AccountManager::menu()
{
    int choice;

    do
    {
        UI::drawHeader("ACCOUNT MANAGEMENT");

        cout << "1. Add Account\n";
        cout << "2. Show Accounts\n";
        cout << "3. Search Account\n";
        cout << "4. Edit Account\n";
        cout << "5. Delete Account\n";
        cout << "6. Deposit\n"; 
        cout << "7. Withdraw\n";
        cout << "8. Transfert\n";
        cout << "9. Back\n\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addAccount();
                Utils::pause();
                break;

            case 2:
                showAccounts();
                Utils::pause();
                break;

            case 3:
                searchAccount();
                Utils::pause();
                break;

            case 4:
                editAccount();
                Utils::pause();
                break;

            case 5:
                deleteAccount();
                Utils::pause();
                break;
            case 6:
                deposit();
                Utils::pause();
                break;

            case 7:
                withdraw();
                Utils::pause();
                break;

            case 8:
                transfer();
                Utils::pause();
                break;

            case 9:
            break;
            default:
                Utils::error("Invalid choice.");
                Utils::pause();
        }

    } while (choice != 9);
}
void AccountManager::addAccount()
{
    Account account;

    int accountNumber;
    int customerId;

    string accountType;
    string currency;

    double balance;

    UI::drawHeader("ADD ACCOUNT");

    cout << "Account Number : ";
    cin >> accountNumber;

    cout << "Customer ID    : ";
    cin >> customerId;

    cin.ignore();

    cout << "Account Type (Current/Savings/Business): ";
    getline(cin, accountType);

    cout << "Currency (USD/EUR/DZD): ";
    getline(cin, currency);

    cout << "Initial Balance: ";
    cin >> balance;

    account.setAccountNumber(accountNumber);
    account.setCustomerId(customerId);
    account.setAccountType(accountType);
    account.setCurrency(currency);
    account.setBalance(balance);

    accounts.push_back(account);

    save();

    Utils::success("Account created successfully.");
}
void AccountManager::showAccounts()
{
    UI::drawHeader("ACCOUNTS");

    if (accounts.empty())
    {
        Utils::warning("No accounts found.");
        return;
    }

    cout << left;

    cout << setw(12) << "Account"
         << setw(12) << "Customer"
         << setw(15) << "Type"
         << setw(10) << "Currency"
         << setw(15) << "Balance"
         << setw(10) << "Status"
         << endl;

    Utils::line();

    for (const Account &account : accounts)
    {
        cout << setw(12) << account.getAccountNumber()
             << setw(12) << account.getCustomerId()
             << setw(15) << account.getAccountType()
             << setw(10) << account.getCurrency()
             << setw(15) << fixed << setprecision(2) << account.getBalance()
             << setw(10)
             << (account.isActive() ? "Active" : "Inactive")
             << endl;
    }

    Utils::line();
}
void AccountManager::searchAccount()
{

}

void AccountManager::editAccount()
{

}

void AccountManager::deleteAccount()
{

}

void AccountManager::load()
{
    accounts.clear();

    ifstream file(ACCOUNT_FILE);

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        Account account;

        account.deserialize(line);

        accounts.push_back(account);
    }

    file.close();
}

void AccountManager::save()
{
    ofstream file(ACCOUNT_FILE);

    if (!file)
    {
        Utils::error("Cannot save accounts.");
        return;
    }

    for (const Account &account : accounts)
    {
        file << account.serialize() << endl;
    }

    file.close();
}
