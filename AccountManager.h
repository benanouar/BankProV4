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
    void showSimpleAccounts() const;
    void deleteAccount();
    void deposit();
    void depositMenu();
    void withdraw();
bool accountExists(int accountNumber) const;
bool deposit(int accountNumber, double amount);
bool withdraw(int accountNumber, double amount);
bool transfer(int fromAccount, int toAccount, double amount);

    void transferMenu();
    void withdrawMenu();
    void transfer();
    void load();
int getCount() const;
    void save();
};

#endif

