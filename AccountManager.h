#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <vector>
#include "Account.h"

using namespace std;

class AccountManager
{
private:
    vector<Account> accounts;

public:
    AccountManager();

    void menu();

    void addAccount();

    void showAccounts();

    void searchAccount();

    void editAccount();

    void deleteAccount();
    void deposit();

    void withdraw();

    void transfer();
    void load();

    void save();
};

#endif

