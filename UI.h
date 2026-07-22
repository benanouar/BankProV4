#ifndef UI_H
#define UI_H

#include <string>

using namespace std;

class UI
{
public:
    static void drawHeader(string title);
    static void drawFooter();
    static void drawMenu();
    static void drawBox(string text);
};

#endif
