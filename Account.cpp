#include "Account.h"
#include "Utils.h"

#include <iostream>
#include <sstream>

using namespace std;
Account::Account()
{
    accountNumber = 0;
    customerId = 0;

    accountType = "";

    currency = "USD";

    balance = 0.0;

    active = true;

    createdAt = Utils::currentDate();
}

Account::Account(
    int accountNumber,
    int customerId,
    string accountType,
    string currency,
    double balance)
{
    this->accountNumber = accountNumber;

    this->customerId = customerId;

    this->accountType = accountType;

    this->currency = currency;

    this->balance = balance;

    active = true;

    createdAt = Utils::currentDate();
}
void Account::show() const
{
    Utils::line();

    cout << "Account Number : "
         << accountNumber << endl;

    cout << "Customer ID    : "
         << customerId << endl;

    cout << "Account Type   : "
         << accountType << endl;

    cout << "Currency       : "
         << currency << endl;

    cout << "Balance        : "
         << balance << " "
         << currency << endl;

    cout << "Created At     : "
         << createdAt << endl;

    cout << "Status         : "
         << (active ? "Active" : "Inactive")
         << endl;

    Utils::line();
}
string Account::serialize() const
{
    return
        to_string(accountNumber) + "|" +
        to_string(customerId) + "|" +
        accountType + "|" +
        currency + "|" +
        to_string(balance) + "|" +
        createdAt + "|" +
        to_string(active);
}
void Account::deserialize(string line)
{
    string value;

    stringstream ss(line);

    getline(ss, value, '|');
    accountNumber = stoi(value);

    getline(ss, value, '|');
    customerId = stoi(value);

    getline(ss, accountType, '|');

    getline(ss, currency, '|');

    getline(ss, value, '|');
    balance = stod(value);

    getline(ss, createdAt, '|');

    getline(ss, value);

    active = stoi(value);
}

int Account::getAccountNumber() const
{
    return accountNumber;
}

int Account::getCustomerId() const
{
    return customerId;
}

string Account::getAccountType() const
{
    return accountType;
}

string Account::getCurrency() const
{
    return currency;
}

double Account::getBalance() const
{
    return balance;
}

bool Account::isActive() const
{
    return active;
}

void Account::setAccountNumber(int value)
{
    accountNumber = value;
}

void Account::setCustomerId(int value)
{
    customerId = value;
}

void Account::setAccountType(string value)
{
    accountType = value;
}

void Account::setCurrency(string value)
{
    currency = value;
}

void Account::setBalance(double value)
{
    balance = value;
}

void Account::setActive(bool value)
{
    active = value;
}

