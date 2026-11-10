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

    cout << "Choose a slot (A1-A5 or B1-B5): ";
    cin >> code;

    return code;
}