#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card
{
private:

    int id;
    int accountNumber;

    string cardNumber;
    string cardType;
    string expiryDate;
    string cvv;

    bool active;

public:

    Card();

    Card(
        int id,
        int accountNumber,
        string cardNumber,
        string cardType,
        string expiryDate,
        string cvv,
        bool active
    );

    string serialize() const;
    void deserialize(string line);
    void show() const;

    int getId() const;
    int getAccountNumber() const;
    string getCardNumber() const;
    string getCardType() const;
    string getExpiryDate() const;
    string getCvv() const;
    bool isActive() const;

    void setId(int value);
    void setAccountNumber(int value);
    void setCardNumber(string value);
    void setCardType(string value);
    void setExpiryDate(string value);
    void setCvv(string value);
    void setActive(bool value);
};

#endif
