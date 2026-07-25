#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include <vector>
#include <string>

#include "Card.h"
#include "AccountManager.h"

using namespace std;

class CardManager
{
private:

    vector<Card> cards;

    string fileName;

    AccountManager* accountManager;

public:

    CardManager(AccountManager* accountManager);

    void menu();

    void load();

    void save();

    int getNextId();

    void addCard();

    void showCards();

    void searchCard();

    void blockCard();

    void unblockCard();

    void deleteCard();
};

#endif
