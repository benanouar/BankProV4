#include "Card.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
Card::Card()
{
    id = 0;
    accountNumber = 0;

    cardNumber = "";
    cardType = "";

    expiryDate = "";
    cvv = "";

    active = true;
}
Card::Card(
    int id,
    int accountNumber,
    string cardNumber,
    string cardType,
    string expiryDate,
    string cvv,
    bool active
)
{
    this->id = id;
    this->accountNumber = accountNumber;

    this->cardNumber = cardNumber;
    this->cardType = cardType;

    this->expiryDate = expiryDate;
    this->cvv = cvv;

    this->active = active;
}
string Card::serialize() const
{
    stringstream ss;

    ss << id << "|"
       << accountNumber << "|"
       << cardNumber << "|"
       << cardType << "|"
       << expiryDate << "|"
       << cvv << "|"
       << active;

    return ss.str();
}
void Card::deserialize(string line)
{
    stringstream ss(line);

    string temp;

    getline(ss, temp, '|');
    id = stoi(temp);

    getline(ss, temp, '|');
    accountNumber = stoi(temp);

    getline(ss, cardNumber, '|');

    getline(ss, cardType, '|');

    getline(ss, expiryDate, '|');

    getline(ss, cvv, '|');

    getline(ss, temp);
    active = stoi(temp);
}

void Card::show() const
{
    cout << left;

    cout << setw(6)  << id;
    cout << setw(12) << accountNumber;
    cout << setw(22) << cardNumber;
    cout << setw(15) << cardType;
    cout << setw(12) << expiryDate;
    cout << setw(10) << (active ? "Active" : "Blocked");

    cout << endl;
}
int Card::getId() const
{
    return id;
}

int Card::getAccountNumber() const
{
    return accountNumber;
}

string Card::getCardNumber() const
{
    return cardNumber;
}

string Card::getCardType() const
{
    return cardType;
}

string Card::getExpiryDate() const
{
    return expiryDate;
}

string Card::getCvv() const
{
    return cvv;
}

bool Card::isActive() const
{
    return active;
}

void Card::setId(int value)
{
    id = value;
}

void Card::setAccountNumber(int value)
{
    accountNumber = value;
}

void Card::setCardNumber(string value)
{
    cardNumber = value;
}

void Card::setCardType(string value)
{
    cardType = value;
}

void Card::setExpiryDate(string value)
{
    expiryDate = value;
}

void Card::setCvv(string value)
{
    cvv = value;
}

void Card::setActive(bool value)
{
    active = value;
}
