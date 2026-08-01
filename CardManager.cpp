#include "CardManager.h"
#include "UI.h"
#include "Utils.h"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
CardManager::CardManager(AccountManager* accountManager)
{
    this->accountManager = accountManager;

    fileName = "Data/cards.txt";

    load();
}
void CardManager::load()
{
    cards.clear();

    ifstream file(fileName);

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        Card card;

        card.deserialize(line);

        cards.push_back(card);
    }

    file.close();
}
void CardManager::save()
{
    ofstream file(fileName);

    for (const Card &card : cards)
    {
        file << card.serialize() << endl;
    }

    file.close();
}
int CardManager::getNextId()
{
    if (cards.empty())
        return 1;

    return cards.back().getId() + 1;
}

string generateCardNumber()
{
    string number = "";

    for (int i = 0; i < 16; i++)
    {
        number += char('0' + rand() % 10);
    }

    return number;
}

string generateCVV()
{
    string cvv = "";

    for (int i = 0; i < 3; i++)
    {
        cvv += char('0' + rand() % 10);
    }

    return cvv;
}

string generateExpiryDate()
{
    return "07/2031";
}
void CardManager::addCard()
{
    Card card;

    int accountNumber;

    string cardType;

    UI::drawHeader("ADD CARD");

    cout << "Account Number : ";
    cin >> accountNumber;

    Account* account = accountManager->findAccount(accountNumber);

    if (account == nullptr)
    {
        Utils::error("Account not found.");
        return;
    }

    cout << "Card Type (Visa/MasterCard): ";
    cin >> cardType;

    card.setId(getNextId());

    card.setAccountNumber(accountNumber);

    card.setCardType(cardType);

    card.setCardNumber(generateCardNumber());

    card.setCvv(generateCVV());

    card.setExpiryDate(generateExpiryDate());

    card.setActive(true);

    cards.push_back(card);

    save();

    Utils::success("Card created successfully.");

    cout << endl;

    cout << "Card Number : " << card.getCardNumber() << endl;
    cout << "CVV         : " << card.getCvv() << endl;
    cout << "Expiry Date : " << card.getExpiryDate() << endl;
}
void CardManager::showCards()
{
    if (cards.empty())
    {
        Utils::warning("No cards found.");
        return;
    }

    UI::drawHeader("CARDS");

    cout << left;

    cout << setw(6)  << "ID"
         << setw(12) << "Account"
         << setw(22) << "Card Number"
         << setw(15) << "Type"
         << setw(12) << "Expiry"
         << setw(10) << "Status"
         << endl;

    cout << string(77, '=') << endl;

    for (const Card &card : cards)
    {
        card.show();
    }
}
void CardManager::searchCard()
{
    string cardNumber;

    UI::drawHeader("SEARCH CARD");

    cout << "Card Number : ";
    cin >> cardNumber;

    for (const Card &card : cards)
    {
        if (card.getCardNumber() == cardNumber)
        {
            cout << endl;

            cout << left;

            cout << setw(6)  << "ID"
                 << setw(12) << "Account"
                 << setw(22) << "Card Number"
                 << setw(15) << "Type"
                 << setw(12) << "Expiry"
                 << setw(10) << "Status"
                 << endl;

            cout << string(77, '=') << endl;

            card.show();

            return;
        }
    }

    Utils::error("Card not found.");
}
void CardManager::blockCard()
{
    string cardNumber;

    UI::drawHeader("BLOCK CARD");

    cout << "Card Number : ";
    cin >> cardNumber;

    for (Card &card : cards)
    {
        if (card.getCardNumber() == cardNumber)
        {
            if (!card.isActive())
            {
                Utils::warning("Card is already blocked.");
                return;
            }

            card.setActive(false);

            save();

            Utils::success("Card blocked successfully.");

            return;
        }
    }

    Utils::error("Card not found.");
}
void CardManager::unblockCard()
{
    string cardNumber;

    UI::drawHeader("UNBLOCK CARD");

    cout << "Card Number : ";
    cin >> cardNumber;

    for (Card &card : cards)
    {
        if (card.getCardNumber() == cardNumber)
        {
            if (card.isActive())
            {
                Utils::warning("Card is already active.");
                return;
            }

            card.setActive(true);

            save();

            Utils::success("Card activated successfully.");

            return;
        }
    }

    Utils::error("Card not found.");
}
void CardManager::deleteCard()
{
    string cardNumber;

    UI::drawHeader("DELETE CARD");

    cout << "Card Number : ";
    cin >> cardNumber;

    for (auto it = cards.begin(); it != cards.end(); ++it)
    {
        if (it->getCardNumber() == cardNumber)
        {
            cards.erase(it);

            save();

            Utils::success("Card deleted successfully.");

            return;
        }
    }

    Utils::error("Card not found.");
}
void CardManager::menu()
{
    int choice;

    do
    {
        UI::drawHeader("CARD MANAGEMENT");

        cout << "1. Add Card\n";
        cout << "2. Show Cards\n";
        cout << "3. Search Card\n";
        cout << "4. Block Card\n";
        cout << "5. Unblock Card\n";
        cout << "6. Delete Card\n";
        cout << "7. Back\n\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addCard();
                Utils::pause();
                break;

            case 2:
                showCards();
                Utils::pause();
                break;
            case 3:
                searchCard();
                Utils::pause();
                break;
case 4:
    blockCard();
    Utils::pause();
    break;

case 5:
    unblockCard();
    Utils::pause();
    break;

case 6:
    deleteCard();
    Utils::pause();
    break;
            case 7:
                break;

            default:
                Utils::warning("Coming soon...");
                Utils::pause();
        }

    } while (choice != 7);
}
