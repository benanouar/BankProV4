#ifndef REPORTMANAGER_H
#define REPORTMANAGER_H

#include "CustomerManager.h"
#include "AccountManager.h"
#include "TransactionManager.h"
#include "CardManager.h"

class ReportManager
{
private:
    CustomerManager* customerManager;
    AccountManager* accountManager;
    TransactionManager* transactionManager;
    CardManager* cardManager;

public:
    ReportManager(
        CustomerManager* customerManager,
        AccountManager* accountManager,
        TransactionManager* transactionManager,
        CardManager* cardManager
    );

    void menu();

    void bankSummary();
    

    void customerReport();

    void accountReport();

    void transactionReport();
};

#endif
