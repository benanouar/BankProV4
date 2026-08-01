#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H

#include <vector>

#include "Transaction.h"

using namespace std;

class TransactionManager
{
private:

    vector<Transaction> transactions;


    string fileName;
public:

    TransactionManager();

    void load();

    void save();

    void addTransaction(const Transaction& transaction);
    void menu();
    void showTransactions();
    void showAccountStatement(int accountNumber);
int getCount() const;
    int getNextId();
};

#endif
