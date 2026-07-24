#include "CustomerManager.h"
#ifndef APP_H
#define APP_H
#include "AccountManager.h"
class App
{
public:
    void run();
private:
    CustomerManager customerManager;

    AccountManager
    accountManager{&customerManager};
};

#endif
