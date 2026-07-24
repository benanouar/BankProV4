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
    bool exists(int id);
    void showSimpleList() const;
    Customer* findById(int id);
    void searchCustomer();
    void editCustomer();
    void deleteCustomer();
    void menu();
    void load();
    string getCustomerName(int id);
    void save();
};

#endif
