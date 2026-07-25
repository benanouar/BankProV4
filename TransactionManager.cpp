#include "TransactionManager.h"
#include "UI.h"
#include "Utils.h"

#include <iostream>
#include <fstream>

using namespace std;

TransactionManager::TransactionManager()
{
    fileName = "Data/transactions.txt";

    load();
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

    for (const Transaction &transaction : transactions)
    {
        transaction.show();
    }
}
void TransactionManager::menu()
{
    int choice;

    do
    {
        UI::drawHeader("TRANSACTION MANAGEMENT");

        cout << "1. Show Transactions\n";
        cout << "2. Search Transaction\n";
        cout << "3. Filter By Account\n";
        cout << "4. Back\n\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                showTransactions();
                Utils::pause();
                break;

            case 4:
                break;

            default:
                Utils::warning("Coming soon...");
                Utils::pause();
        }

    } while (choice != 4);
}
