#include "TransactionManager.h"
#include "UI.h"
#include "Utils.h"
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

TransactionManager::TransactionManager()
{
    fileName = "Data/transactions.txt";

    load();
}
int TransactionManager::getCount() const
{
    return transactions.size();
}
void TransactionManager::load()
{
    transactions.clear();

    ifstream file(fileName);

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        Transaction transaction;

        transaction.deserialize(line);

        transactions.push_back(transaction);
    }

    file.close();
}

void TransactionManager::save()
{
    ofstream file(fileName);

    for (const Transaction &transaction : transactions)
    {
        file << transaction.serialize() << endl;
    }

    file.close();
}
int TransactionManager::getNextId()
{
    if (transactions.empty())
    {
        return 1;
    }

    return transactions.back().getId() + 1;
}
void TransactionManager::addTransaction(const Transaction &transaction)
{
    transactions.push_back(transaction);

    save();
}
void TransactionManager::showTransactions()
{
    if (transactions.empty())
    {
        Utils::warning("No transactions found.");
        return;
    }

    UI::drawHeader("TRANSACTIONS");

    cout << left;

    cout << setw(6)  << "ID"
         << setw(12) << "Account"
         << setw(18) << "Type"
         << setw(15) << "Amount"
         << setw(18) << "Balance"
         << setw(15) << "Date"
         << endl;

    cout << string(84, '=') << endl;

    for (const Transaction &transaction : transactions)
    {
        transaction.show();
    }
}
void TransactionManager::showAccountStatement(int accountNumber)
{
    UI::drawHeader("ACCOUNT STATEMENT");

    bool found = false;

    for (const Transaction &transaction : transactions)
    {
        if (transaction.getAccountNumber() == accountNumber)
        {
            transaction.show();
            found = true;
        }
    }

    if (!found)
    {
        Utils::warning("No transactions found for this account.");
    }
}
void TransactionManager::menu()
{
    int choice;

    do
    {
        UI::drawHeader("TRANSACTION MANAGEMENT");

cout << "1. Show Transactions\n";
cout << "2. Account Statement\n";
cout << "3. Search Transaction\n";
cout << "4. Back\n\n";

cout << "Choice: ";
cin >> choice;

switch (choice)
{
    case 1:
        showTransactions();
        Utils::pause();
        break;

    case 2:
    {
        int accountNumber;

        cout << "Account Number : ";
        cin >> accountNumber;

        showAccountStatement(accountNumber);

        break;
    }

    case 3:
        Utils::warning("Coming soon...");
        Utils::pause();
        break;

    case 4:
        break;

    default:
        Utils::error("Invalid choice.");
        Utils::pause();
      }    
}   while (choice != 4);

}
