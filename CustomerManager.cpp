#include "CustomerManager.h"
#include "UI.h"
#include "Utils.h"
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

CustomerManager::CustomerManager()
{
    load();
}
const string CUSTOMER_FILE = "Data/customers.txt";
void CustomerManager::addCustomer()
{
    Customer customer;

    int id;

    string text;

    UI::drawHeader("ADD CUSTOMER");

    cout << "Customer ID : ";
    cin >> id;
    cin.ignore();

    customer.setId(id);

    cout << "First Name : ";
    getline(cin, text);
    customer.setFirstName(text);

    cout << "Last Name : ";
    getline(cin, text);
    customer.setLastName(text);

    cout << "Gender : ";
    getline(cin, text);
    customer.setGender(text);

    cout << "Birth Date : ";
    getline(cin, text);
    customer.setBirthDate(text);

    cout << "Phone : ";
    getline(cin, text);
    customer.setPhone(text);

    cout << "Email : ";
    getline(cin, text);
    customer.setEmail(text);

    cout << "Address : ";
    getline(cin, text);
    customer.setAddress(text);

    cout << "National ID : ";
    getline(cin, text);
    customer.setNationalId(text);

    customers.push_back(customer);

    save();

    Utils::success("Customer added successfully.");
}
void CustomerManager::showCustomers()
{
    UI::drawHeader("CUSTOMERS");

    if (customers.empty())
    {
        Utils::warning("No customers found.");
        return;
    }

    cout << left;

    cout << setw(6)  << "ID"
         << setw(25) << "Name"
         << setw(18) << "Phone"
         << setw(12) << "Status"
         << endl;

    Utils::line();

    for (const Customer &customer : customers)
    {
        cout << setw(6)  << customer.getId()
             << setw(25) << customer.getFullName()
             << setw(18) << customer.getPhone()
             << setw(12)
             << (customer.isActive() ? "Active" : "Inactive")
             << endl;
    }

    Utils::line();
}
void CustomerManager::editCustomer()
{
    UI::drawHeader("EDIT CUSTOMER");

    int id;

    cout << "Customer ID: ";
    cin >> id;
    cin.ignore();

    for (Customer &customer : customers)
    {
        if (customer.getId() == id)
        {
            string text;

            cout << "First Name (" << customer.getFirstName() << "): ";
            getline(cin, text);
            if (!text.empty())
                customer.setFirstName(text);

            cout << "Last Name (" << customer.getLastName() << "): ";
            getline(cin, text);
            if (!text.empty())
                customer.setLastName(text);

            cout << "Phone (" << customer.getPhone() << "): ";
            getline(cin, text);
            if (!text.empty())
                customer.setPhone(text);

            cout << "Email (" << customer.getEmail() << "): ";
            getline(cin, text);
            if (!text.empty())
                customer.setEmail(text);

            cout << "Address (" << customer.getAddress() << "): ";
            getline(cin, text);
            if (!text.empty())
                customer.setAddress(text);

            save();

            Utils::success("Customer updated successfully.");

            return;
        }
    }

    Utils::warning("Customer not found.");
}
void CustomerManager::searchCustomer()
{
    UI::drawHeader("SEARCH CUSTOMER");

    string keyword;

    cout << "Enter ID or First Name: ";
    cin >> keyword;

    bool found = false;

    for (const Customer &customer : customers)
    {
        if (keyword == to_string(customer.getId()) ||
            keyword == customer.getFirstName())
        {
            customer.show();

            found = true;
        }
    }

    if (!found)
    {
        Utils::warning("Customer not found.");
    }
}
void CustomerManager::deleteCustomer()
{
    UI::drawHeader("DELETE CUSTOMER");

    int id;

    cout << "Customer ID: ";
    cin >> id;

    for (auto it = customers.begin(); it != customers.end(); ++it)
    {
        if (it->getId() == id)
        {
            char answer;

            cout << "\nDelete "
                 << it->getFullName()
                 << " ? (Y/N): ";

            cin >> answer;

            if (answer == 'Y' || answer == 'y')
            {
                customers.erase(it);

                save();

                Utils::success("Customer deleted successfully.");
            }
            else
            {
                Utils::warning("Operation cancelled.");
            }

            return;
        }
    }

    Utils::warning("Customer not found.");
}
void CustomerManager::load()
{
    customers.clear();

    ifstream file(CUSTOMER_FILE);

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        Customer customer;

        customer.deserialize(line);

        customers.push_back(customer);
    }

    file.close();
}

void CustomerManager::save()
{
    ofstream file(CUSTOMER_FILE);

    if (!file)
    {
        Utils::error("Cannot save customers.");
        return;
    }

    for (const Customer &customer : customers)
    {
        file << customer.serialize() << endl;
             
    }

    file.close();
}
void CustomerManager::menu()
{
    int choice;

    do
    {
        UI::drawHeader("CUSTOMER MANAGEMENT");

        cout << "1. Add Customer\n";
        cout << "2. Show Customers\n";
        cout << "3. Search Customer\n";
        cout << "4. Edit Customer\n";
        cout << "5. Delete Customer\n";
        cout << "6. Back\n\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addCustomer();
                Utils::pause();
                break;

            case 2:
                showCustomers();
                Utils::pause();
                break;

            case 3:
                searchCustomer();
                Utils::pause();
                break;

            case 4:
                editCustomer();
                Utils::pause();
                break;
            case 5:
                deleteCustomer();
                Utils::pause();
                break;

            case 6:
                break;

            default:
                Utils::error("Invalid choice!");
                Utils::pause();
        }

    } while (choice != 6);
}
