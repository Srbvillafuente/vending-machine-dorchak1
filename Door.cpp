#include "Door.h"
#include <iostream>
using namespace std;

bool Door::isOpen() const {
    return open;
}

void Door::openForRefill() {
    open = true;
    cout << "Service door opened; sales stopped.\n";
}

void Door::closeAndLock() {
    open = false;
    cout << "Service door closed and locked.\n";
}

string Door::requestSlot() const {
    string code;

    while (true) {
        cout << "Choose a slot (A1-A5 or B1-B5): ";

        if (!(cin >> code))
            return "";   // input closed (EOF); avoid an infinite loop

        // Accept lowercase too, to match parseSlot() in main.cpp
        code[0] = static_cast<char>(
            toupper(static_cast<unsigned char>(code[0])));

        if (code.length() == 2 &&
            (code[0] == 'A' || code[0] == 'B') &&
            (code[1] >= '1' && code[1] <= '5')) {
            cout << "Slot " << code << " accepted.\n";
            return code;
            }

        cout << "Invalid code. Please try again.\n";
    }
}