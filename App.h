#ifndef APP_H
#define APP_H
#include "CardManager.h"
#include "CustomerManager.h"
#include "TransactionManager.h"
#include "AccountManager.h"

class App
{
private:

    CustomerManager customerManager;

    TransactionManager transactionManager;

    AccountManager accountManager;
    CardManager cardManager;
public:

    App();

    void run();
};

#endif
