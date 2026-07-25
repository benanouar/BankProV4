#include "AccountManager.h"
#include "UI.h"
#include "Transaction.h"
#include "Utils.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

const string ACCOUNT_FILE = "Data/accounts.txt";

AccountManager::AccountManager(
    CustomerManager* customerManager,
    TransactionManager* transactionManager
)
{
    this->customerManager = customerManager;
    this->transactionManager = transactionManager;

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
        cout << "7. Back\n\n";

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
                depositMenu();
                Utils::pause();
                break;
            case 7:
            break;
            default:
                Utils::error("Invalid choice.");
                Utils::pause();
        }

    } while (choice != 7);
}
bool AccountManager::accountExists(int accountNumber) const
{
    for (const Account &account : accounts)
    {
        if (account.getAccountNumber() == accountNumber)
        {
            return true;
        }
    }

    return false;
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
    if (accountExists(accountNumber))
    {
        Utils::error("Account number already exists.");
        return;
    }
    UI::drawHeader("AVAILABLE CUSTOMERS");

    customerManager->showSimpleList();

    cout << endl;
    cout << "Customer ID    : ";
    cin >> customerId;
    if (!customerManager->exists(customerId))
    {
        Utils::error("Customer not found.");
        return;
    }
    cin.ignore();

  
    cout << "Initial Balance: ";
    cin >> balance;

    account.setAccountNumber(accountNumber);
    account.setCustomerId(customerId);
    accountType = Utils::chooseAccountType();
    currency = Utils::chooseCurrency();
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
             << setw(12) << customerManager->getCustomerName(account.getCustomerId())
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
    UI::drawHeader("SEARCH ACCOUNT");

    int accountNumber;

    cout << "Account Number: ";
    cin >> accountNumber;

    for (const Account &account : accounts)
    {
        if (account.getAccountNumber() == accountNumber)
        {
            account.show();
            return;
        }
    }

    Utils::warning("Account not found.");
}
void AccountManager::editAccount()
{
    UI::drawHeader("EDIT ACCOUNT");

    int number;

    cout << "Account Number: ";
    cin >> number;

    cin.ignore();

    for (Account &account : accounts)
    {
        if (account.getAccountNumber() == number)
        {
            string text;
            double balance;

            cout << "Account Type (" << account.getAccountType() << "): ";
            getline(cin, text);
            if (!text.empty())
                account.setAccountType(text);

            cout << "Currency (" << account.getCurrency() << "): ";
            getline(cin, text);
            if (!text.empty())
                account.setCurrency(text);

            cout << "Balance (" << account.getBalance() << "): ";
            cin >> balance;

            account.setBalance(balance);

            save();

            Utils::success("Account updated successfully.");

            return;
        }
    }

    Utils::warning("Account not found.");
}
void AccountManager::deleteAccount()
{
    UI::drawHeader("DELETE ACCOUNT");

    int accountNumber;

    cout << "Account Number: ";
    cin >> accountNumber;

    for (auto it = accounts.begin(); it != accounts.end(); ++it)
    {
        if (it->getAccountNumber() == accountNumber)
        {
            char answer;

            cout << "\nDelete Account "
                 << accountNumber
                 << " ? (Y/N): ";

            cin >> answer;

            if (answer == 'Y' || answer == 'y')
            {
                accounts.erase(it);

                save();

                Utils::success("Account deleted successfully.");
            }
            else
            {
                Utils::warning("Operation cancelled.");
            }

            return;
        }
    }

    Utils::warning("Account not found.");
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
Account* AccountManager::findAccount(int accountNumber)
{
    for (Account &account : accounts)
    {
        if (account.getAccountNumber() == accountNumber)
        {
            return &account;
        }
    }

    return nullptr;
}
bool AccountManager::deposit(int accountNumber, double amount)
{
    Account* account = findAccount(accountNumber);

    if (account == nullptr)
    {
        return false;
    }

    account->setBalance(account->getBalance() + amount);

    save();
Transaction transaction;

transaction.setId(transactionManager->getNextId());

transaction.setAccountNumber(accountNumber);

transaction.setType("Deposit");

transaction.setAmount(amount);

transaction.setBalanceAfter(account->getBalance());

transaction.setDate(Utils::currentDate());
transactionManager->addTransaction(transaction);
    return true;
}



void AccountManager::depositMenu()
{
    int accountNumber;
    double amount;

    UI::drawHeader("DEPOSIT");

    cout << "Account Number : ";
    cin >> accountNumber;

    cout << "Amount : ";
    cin >> amount;

    if (amount <= 0)
    {
        Utils::error("Invalid amount.");
        return;
    }

    if (deposit(accountNumber, amount))
    {
        Utils::success("Deposit completed successfully.");
    }
    else
    {
        Utils::error("Account not found.");
    }
}

