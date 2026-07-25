#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include "CustomerManager.h"
#include <vector>
#include "Account.h"
#include "TransactionManager.h"
using namespace std;

class AccountManager
{
private:
    vector<Account> accounts;
    CustomerManager* customerManager;
    TransactionManager* transactionManager;
public:
    AccountManager(
        CustomerManager* customerManager,
        TransactionManager* transactionManager
    );
    Account* findAccount(int accountNumber);
    void menu();

    void addAccount();

    void showAccounts();

    void searchAccount();

    void editAccount();

    void deleteAccount();
    void deposit();
    void depositMenu();
    void withdraw();
bool accountExists(int accountNumber) const;
bool deposit(int accountNumber, double amount);
    void transfer();
    void load();

    void save();
};

#endif

