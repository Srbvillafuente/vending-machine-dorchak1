#include "PackageSlot.h"
#include <iostream>

using namespace std;

PackageSlot::PackageSlot() {
    snack = "";
}

string PackageSlot::drop() {
    if (isEmpty()) {
        cout << "Out of stock!" << endl;
        return "";
    }

    quantity--;
    countDispensed++;

    return snack;
}

bool PackageSlot::refill(const string& newSnack) {
    if (newSnack.empty()) {
        cout << "Snack name cannot be empty." << endl;
        return false;
    }

    if (!snack.empty() && snack != newSnack) {
        cout << "Wrong snack type for this slot." << endl;
        return false;
    }

    snack = newSnack;
    quantity = capacity;
    countDispensed = 0;

    return true;
}

bool PackageSlot::isEmpty() const {
    return quantity == 0;
}

int PackageSlot::getDispensedCount() const {
    return countDispensed;
}