#include "Dashboard.h"
#include "Utils.h"

#include <iostream>

using namespace std;

void Dashboard::show(
    int customers,
    int accounts,
    int transactions,
    int cards,
    int loans
)
{
    Utils::clearScreen();

    cout << "\033[36m";

    cout << "==============================================================\n";
    cout << "                    BANK PRO v4\n";
    cout << "          Professional Banking System\n";
    cout << "==============================================================\n";

    cout << "\033[0m";

    cout << "\n";

    cout << "Date : "
         << Utils::currentDate()
         << endl;

    cout << "Time : "
         << Utils::currentTime()
         << endl;

    Utils::line();

    cout << "Customers     : " << customers << endl;
    cout << "Accounts      : " << accounts << endl;
    cout << "Transactions  : " << transactions << endl;
    cout << "Loans         : " << loans << endl;
    cout << "Cards         : " << cards << endl;
    Utils::line();

    cout << "1. Customers\n";
    cout << "2. Accounts\n";
    cout << "3. Transactions\n";
    cout << "4. Cards\n";
    cout << "5. Loans\n";
    cout << "6. Reports\n";
    cout << "7. Statistics\n";
    cout << "8. Settings\n";
    cout << "9. Exit\n";

    Utils::line();
    
}
