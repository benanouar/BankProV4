#include "UI.h"
#include "Utils.h"

#include <iostream>

using namespace std;

void UI::drawHeader(string title)
{
    Utils::clearScreen();

    cout << "\033[36m";

    cout << "============================================================\n";
    cout << "                     BANK PRO v4\n";
    cout << "============================================================\n";

    cout << "\033[0m";

    cout << title << endl;

    Utils::line();
}

void UI::drawFooter()
{
    Utils::line();
}

void UI::drawBox(string text)
{
    cout << "+----------------------------------------------------------+\n";
    cout << "| " << text << endl;
    cout << "+----------------------------------------------------------+\n";
}

void UI::drawMenu()
{
    cout << "[1] Customers\n";
    cout << "[2] Accounts\n";
    cout << "[3] Transactions\n";
    cout << "[4] Cards\n";
    cout << "[5] Loans\n";
    cout << "[6] Reports\n";
    cout << "[7] Statistics\n";
    cout << "[8] Settings\n";
    cout << "[9] Exit\n";
}
