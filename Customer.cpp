#include "Customer.h"
#include "Utils.h"
#include <sstream>
#include <iostream>

using namespace std;

Customer::Customer()
{
    id = 0;

    firstName = "";
    lastName = "";

    gender = "";

    birthDate = "";

    phone = "";

    email = "";

    address = "";

    nationalId = "";

    createdAt = Utils::currentDate();

    active = true;
}

Customer::Customer(
    int id,
    string firstName,
    string lastName,
    string gender,
    string birthDate,
    string phone,
    string email,
    string address,
    string nationalId)

{
    this->id = id;

    this->firstName = firstName;
    this->lastName = lastName;

    this->gender = gender;

    this->birthDate = birthDate;

    this->phone = phone;

    this->email = email;

    this->address = address;

    this->nationalId = nationalId;

    this->createdAt = Utils::currentDate();

    active = true;
}

void Customer::show() const
{
    Utils::line();

    cout << "Customer ID   : " << id << endl;

    cout << "Name          : "
         << firstName
         << " "
         << lastName
         << endl;

    cout << "Gender        : " << gender << endl;

    cout << "Birth Date    : " << birthDate << endl;

    cout << "Phone         : " << phone << endl;

    cout << "Email         : " << email << endl;

    cout << "Address       : " << address << endl;

    cout << "National ID   : " << nationalId << endl;

    cout << "Created At    : " << createdAt << endl;

    cout << "Status        : "
         << (active ? "Active" : "Inactive")
         << endl;

    Utils::line();
}

int Customer::getId() const
{
    return id;
}

string Customer::getFullName() const
{
    return firstName + " " + lastName;
}

bool Customer::isActive() const
{
    return active;
}

void Customer::setActive(bool value)
{
    active = value;
}
string Customer::serialize() const
{
    return
        to_string(id) + "|" +
        firstName + "|" +
        lastName + "|" +
        gender + "|" +
        birthDate + "|" +
        phone + "|" +
        email + "|" +
        address + "|" +
        nationalId + "|" +
        createdAt + "|" +
        to_string(active);
}
void Customer::deserialize(string line)
{
    string value;

    stringstream ss(line);

    getline(ss, value, '|');
    id = stoi(value);

    getline(ss, firstName, '|');

    getline(ss, lastName, '|');

    getline(ss, gender, '|');

    getline(ss, birthDate, '|');

    getline(ss, phone, '|');

    getline(ss, email, '|');

    getline(ss, address, '|');

    getline(ss, nationalId, '|');

    getline(ss, createdAt, '|');

    getline(ss, value);

    active = stoi(value);
}

void Customer::setId(int id)
{
    this->id = id;
}

void Customer::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Customer::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Customer::setGender(string gender)
{
    this->gender = gender;
}

void Customer::setBirthDate(string birthDate)
{
    this->birthDate = birthDate;
}

void Customer::setPhone(string phone)
{
    this->phone = phone;
}

void Customer::setEmail(string email)
{
    this->email = email;
}

void Customer::setAddress(string address)
{
    this->address = address;
}

void Customer::setNationalId(string nationalId)
{
    this->nationalId = nationalId;
}
string Customer::getPhone() const
{
    return phone;
}
string Customer::getFirstName() const
{
    return firstName;
}
string Customer::getLastName() const
{
    return lastName;
}

string Customer::getGender() const
{
    return gender;
}

string Customer::getBirthDate() const
{
    return birthDate;
}

string Customer::getEmail() const
{
    return email;
}

string Customer::getAddress() const
{
    return address;
}

string Customer::getNationalId() const
{
    return nationalId;
}
