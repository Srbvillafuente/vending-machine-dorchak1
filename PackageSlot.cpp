#include "PackageSlot.h"
#include <iostream>
using namespace std;

string PackageSlot::drop() {
    if (isEmpty())
        return "";

    --quantity;
    ++countDispensed;
    return snack;
}

bool PackageSlot::refill(const string& newSnack, int amount) {
    if (newSnack.empty() || amount < 0 ||
        amount > capacity - quantity)
        return false;

    if (quantity > 0 && snack != newSnack)
        return false;

    if (amount > 0)
        snack = newSnack;

    quantity += amount;
    return true;
}

bool PackageSlot::isEmpty() const {
    return quantity == 0;
}

int PackageSlot::getQuantity() const {
    return quantity;
}

int PackageSlot::getDispensedCount() const {
    return countDispensed;
}

string PackageSlot::getSnackName() const {
    return snack;
}