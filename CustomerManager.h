#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include <vector>
#include "Customer.h"

using namespace std;

class CustomerManager
{
private:
    vector<Customer> customers;

public:
    CustomerManager();

    void addCustomer();

    void showCustomers();

    void searchCustomer();
    void editCustomer();
    void deleteCustomer();
    void menu();
    void load();

    void save();
};

#endif
