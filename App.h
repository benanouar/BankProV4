#ifndef APP_H
#define APP_H

#include "CustomerManager.h"
#include "TransactionManager.h"
#include "AccountManager.h"

class App
{
private:

    CustomerManager customerManager;

    TransactionManager transactionManager;

    AccountManager accountManager;

public:

    App();

    void run();
};

#endif
