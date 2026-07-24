#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include "CustomerManager.h"
#include <vector>
#include "Account.h"

using namespace std;

class AccountManager
{
private:
    vector<Account> accounts;
    CustomerManager* customerManager;
public:
    AccountManager(CustomerManager* customerManager);

    void menu();

    void addAccount();

    void showAccounts();

    void searchAccount();

    void editAccount();

    void deleteAccount();
    void deposit();

    void withdraw();
bool accountExists(int accountNumber) const;
    void transfer();
    void load();

    void save();
};

#endif

