#include "SnackDispenser.h"
#include <iostream>

using namespace std;

void SnackDispenser::setState(bool newState) {
    state = newState;
}

bool SnackDispenser::getState() const {
    return state;
}

void SnackDispenser::selectSnack() {
    int selection;

    cout << "\n===== AVAILABLE SNACK SLOTS =====" << endl;
    cout << "Row 1: 11  12  13  14  15" << endl;
    cout << "Row 2: 21  22  23  24  25" << endl;
    cout << "\nAll slots contain Chips." << endl;
    cout << "Enter snack selection (11-15 or 21-25): ";

    if (!(cin >> selection)) {
        cout << "Invalid input. Please enter a number." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    int row = selection / 10;
    int slot = selection % 10;

    if (row < 1 || row > 2 || slot < 1 || slot > 5) {
        cout << "Invalid selection. Choose 11-15 or 21-25." << endl;
        return;
    }

    dispenseSnack(row - 1, slot - 1);
}

bool SnackDispenser::dispenseSnack(int row, int slot) {
    if (row < 0 || row >= 2 || slot < 0 || slot >= 5) {
        cout << "Invalid row or slot." << endl;
        return false;
    }

    if (!state) {
        cout << "Machine is in refill mode." << endl;
        return false;
    }

    if (!retrievalBin.isEmpty()) {
        cout << "Please retrieve the previous snack first." << endl;
        return false;
    }

    PackageSlot& selected = storage.getPackageSlot(row, slot);

    if (selected.isEmpty()) {
        cout << "Out of stock!" << endl;
        return false;
    }

    string snack = selected.drop();

    if (snack.empty()) {
        return false;
    }

    if (!retrievalBin.release(snack)) {
        cout << "Unable to release snack." << endl;
        return false;
    }

    cout << "Snack dropped into retrieval bin." << endl;

    // retrieve the snack
    retrieveSnack();

    return true;
}

bool SnackDispenser::refillSlot(
    int row, int slot, const string& snack) {

    if (row < 0 || row >= 2 || slot < 0 || slot >= 5) {
        cout << "Invalid row or slot." << endl;
        return false;
    }

    if (state) {
        cout << "Switch to refill mode first." << endl;
        return false;
    }

    bool success = storage.getPackageSlot(row, slot).refill(snack);

    if (!success) {
        cout << "Unable to refill slot." << endl;
    }

    return success;
}

void SnackDispenser::retrieveSnack() {
    if (retrievalBin.isEmpty()) {
        cout << "No snack to retrieve." << endl;
        return;
    }

    string snack = retrievalBin.retrieveSnack();

    cout << "Customer retrieved: " << snack << endl;
}