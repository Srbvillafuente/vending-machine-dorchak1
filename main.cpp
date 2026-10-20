#include <iostream>
#include "SnackDispenser.h"

using namespace std;

// =====================================
// VendingMachine Class
// =====================================

class VendingMachine {
private:
    SnackDispenser snackDispenser;
    int price;

public:
    VendingMachine() {
        price = 0;
    }

    void run() {
        cout << "Welcome to the Vending Machine!" << endl;
        cout << "Price: " << price << "Cents" << endl;

        // Start in refill mode.
        snackDispenser.setState(false);

        // Fill all slots with Chips.
        for (int row = 0; row < 2; row++) {
            for (int slot = 0; slot < 5; slot++) {
                snackDispenser.refillSlot(row, slot, "Chips");
            }
        }

        // Switch to selling mode
        snackDispenser.setState(true);

        int choice = 0;

        while (choice != 2) {
            cout << "\n===== VENDING MACHINE =====" << endl;
            cout << "1. Select Snack" << endl;
            cout << "2. Exit" << endl;
            cout << "Enter choice (1-2): ";

            if (!(cin >> choice)) {
                cout << "Invalid input. Please enter 1 or 2." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (choice == 1) {
                snackDispenser.selectSnack();
            }
            else if (choice == 2) {
                cout << "Thank you!" << endl;
            }
            else {
                cout << "Invalid choice. Please enter 1 or 2." << endl;
            }
        }
    }
};

// =====================================
// Main Function
// =====================================

int main() {
    VendingMachine machine;
    machine.run();

    return 0;
}