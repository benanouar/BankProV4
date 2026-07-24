#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account
{
private:

    int accountNumber;

    int customerId;

    string accountType;

    string currency;

    double balance;

    bool active;

    string createdAt;

public:

    Account();

    Account(
        int accountNumber,
        int customerId,
        string accountType,
        string currency,
        double balance
    );

    void show() const;

    string serialize() const;

    void deserialize(string line);

    int getAccountNumber() const;

    int getCustomerId() const;

    string getAccountType() const;

    string getCurrency() const;

    double getBalance() const;

    bool isActive() const;

    void setAccountNumber(int value);

    void setCustomerId(int value);

    void setAccountType(string value);

    void setCurrency(string value);

    void setBalance(double value);

    void setActive(bool value);
};

#endif
