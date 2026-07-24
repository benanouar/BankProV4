#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction
{
private:

    int id;

    int accountNumber;

    string type;

    double amount;

    double balanceAfter;

    string date;

public:

    Transaction();

    Transaction(
        int id,
        int accountNumber,
        string type,
        double amount,
        double balanceAfter,
        string date
    );

    string serialize() const;

    void deserialize(string line);

    void show() const;

    int getId() const;

    int getAccountNumber() const;

    string getType() const;

    double getAmount() const;

    double getBalanceAfter() const;

    string getDate() const;

    void setId(int value);

    void setAccountNumber(int value);

    void setType(string value);

    void setAmount(double value);
    
    void setBalanceAfter(double value);

    void setDate(string value);
};

#endif
