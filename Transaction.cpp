#include "Transaction.h"
#include "Utils.h"

#include <iostream>
#include <sstream>

using namespace std;
Transaction::Transaction()
{
    id = 0;
    accountNumber = 0;
    type = "";
    amount = 0;
    balanceAfter = 0;
    date = Utils::currentDate();
}

Transaction::Transaction(
    int id,
    int accountNumber,
    string type,
    double amount,
    double balanceAfter,
    string date)
{
    this->id = id;
    this->accountNumber = accountNumber;
    this->type = type;
    this->amount = amount;
    this->balanceAfter = balanceAfter;
    this->date = date;
}
string Transaction::serialize() const
{
    return
        to_string(id) + "|" +
        to_string(accountNumber) + "|" +
        type + "|" +
        to_string(amount) + "|" +
        to_string(balanceAfter) + "|" +
        date;
}
void Transaction::deserialize(string line)
{
    string value;

    stringstream ss(line);

    getline(ss, value, '|');
    id = stoi(value);

    getline(ss, value, '|');
    accountNumber = stoi(value);

    getline(ss, type, '|');

    getline(ss, value, '|');
    amount = stod(value);

    getline(ss, value, '|');
    balanceAfter = stod(value);

    getline(ss, date);
}
void Transaction::show() const
{
    Utils::line();

    cout << "Transaction ID : " << id << endl;
    cout << "Account Number : " << accountNumber << endl;
    cout << "Type           : " << type << endl;
    cout << "Amount         : " << amount << endl;
    cout << "Balance After  : " << balanceAfter << endl;
    cout << "Date           : " << date << endl;

    Utils::line();
}
int Transaction::getId() const
{
    return id;
}

int Transaction::getAccountNumber() const
{
    return accountNumber;
}

string Transaction::getType() const
{
    return type;
}

double Transaction::getAmount() const
{
    return amount;
}

double Transaction::getBalanceAfter() const
{
    return balanceAfter;
}

string Transaction::getDate() const
{
    return date;
}
void Transaction::setId(int value)
{
    id = value;
}

void Transaction::setAccountNumber(int value)
{
    accountNumber = value;
}

void Transaction::setType(string value)
{
    type = value;
}

void Transaction::setAmount(double value)
{
    amount = value;
}

void Transaction::setBalanceAfter(double value)
{
    balanceAfter = value;
}

void Transaction::setDate(string value)
{
    date = value;
}

