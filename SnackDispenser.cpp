#include "SnackDispenser.h"
#include <iostream>
using namespace std;

void SnackDispenser::setState(bool enabled) {
    selling = enabled;
}

bool SnackDispenser::dispenseSnack(int row, int slot) {
    if (row < 0 || row >= 2 ||
        slot < 0 || slot >= 5 || !selling) {

        cout << "Dispensing is unavailable.\n";
        return false;
    }

    if (!retrievalBin.isEmpty()) {
        cout << "Please retrieve the previous snack first.\n";
        return false;
    }

    PackageSlot& item = storage.getPackageSlot(row, slot);

    if (item.isEmpty()) {
        cout << "Out of stock! Choose another slot.\n";
        return false;
    }

    string snack = item.drop();

    cout << "Step 3: Dropping " << snack
        << " from the slot...\n";

    if (!retrievalBin.release(snack)) {
        cout << "Unable to transfer snack to retrieval bin.\n";
        return false;
    }

    cout << "Step 4: " << snack
        << " placed in the retrieval bin.\n";
    cout << "Retrieval bin unlocked for pickup.\n";

    return true;
}

bool SnackDispenser::refillSlot(
    int row, int slot, const string& snack, int amount) {

    if (row < 0 || row >= 2 ||
        slot < 0 || slot >= 5 || selling)
        return false;

    return storage.getPackageSlot(row, slot)
        .refill(snack, amount);
}

void SnackDispenser::retrieveSnack() {
    if (!retrievalBin.isReadyForPickup()) {
        cout << "No snack is ready for pickup.\n";
        return;
    }

    cout << "Step 5: Customer collected "
        << retrievalBin.retrieveSnack() << ".\n";

    cout << "Retrieval bin is now empty and locked.\n";
}

bool SnackDispenser::binIsEmpty() const {
    return retrievalBin.isEmpty();
}

int SnackDispenser::getQuantity(int row, int slot) {
    return storage.getPackageSlot(row, slot)
        .getQuantity();
}

int SnackDispenser::getSold(int row, int slot) {
    return storage.getPackageSlot(row, slot)
        .getDispensedCount();
}

string SnackDispenser::getSnackName(int row, int slot) {
    return storage.getPackageSlot(row, slot)
        .getSnackName();
}