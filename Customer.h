#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer
{
private:
    int id;

    string firstName;
    string lastName;

    string gender;

    string birthDate;

    string phone;

    string email;

    string address;

    string nationalId;

    string createdAt;
        
    bool active;

public:

    Customer();

    Customer(
        int id,
        string firstName,
        string lastName,
        string gender,
        string birthDate,
        string phone,
        string email,
        string address,
        string nationalId
            
        );
    string serialize() const;
    string getPhone() const;
    string getFirstName() const;
    string getLastName() const;
    string getGender() const;
    string getBirthDate() const;
    string getEmail() const;
    string getAddress() const;
    string getNationalId() const;
    void deserialize(string line);
    void show() const;

    int getId() const;

    string getFullName() const;

    bool isActive() const;

    void setActive(bool value);

void setId(int id);

void setFirstName(string firstName);

void setLastName(string lastName);

void setGender(string gender);

void setBirthDate(string birthDate);

void setPhone(string phone);

void setEmail(string email);

void setAddress(string address);

void setNationalId(string nationalId);
};
#endif
