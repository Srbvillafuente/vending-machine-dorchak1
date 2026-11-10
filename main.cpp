#include <iostream>
#include <string>
#include <cctype>
#include "Door.h"
#include "SnackDispenser.h"

using namespace std;

class VendingMachine {
private:
    Door door;
    SnackDispenser dispenser;
    int price = 0;

    bool parseSlot(const string& code, int& row, int& slot) {
        if (code.size() != 2)
            return false;

        char letter = static_cast<char>(
            toupper(static_cast<unsigned char>(code[0]))
            );

        if ((letter != 'A' && letter != 'B') ||
            code[1] < '1' || code[1] > '5')
            return false;

        row = letter - 'A';
        slot = code[1] - '1';

        return true;
    }

    void inventory() {
        cout << "\nSlot   Snack         Remaining   Sold\n";

        for (int row = 0; row < 2; ++row) {
            for (int slot = 0; slot < 5; ++slot) {
                string name = dispenser.getSnackName(row, slot);

                cout << char('A' + row) << slot + 1
                    << "     "
                    << (name.empty() ? "(empty)" : name)
                    << "       "
                    << dispenser.getQuantity(row, slot)
                    << "           "
                    << dispenser.getSold(row, slot)
                    << "\n";
            }
        }
    }

    void refillMode() {
        if (!dispenser.binIsEmpty()) {
            cout << "Retrieve the snack before entering refill mode.\n";
            return;
        }

        dispenser.setState(false);
        door.openForRefill();

        while (true) {
            cout << "\nREFILL MODE\n";
            cout << "1. Refill one slot\n";
            cout << "2. Show inventory\n";
            cout << "3. Finish and lock\n";
            cout << "Choice: ";

            int choice;

            if (!(cin >> choice)) {
                if (cin.eof())
                    break;

                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter a valid number.\n";
                continue;
            }

            if (choice == 3)
                break;

            if (choice == 2) {
                inventory();
                continue;
            }

            if (choice != 1) {
                cout << "Invalid option.\n";
                continue;
            }

            string code, name;
            int amount, row, slot;

            cout << "Slot (A1-A5 or B1-B5): ";

            if (!(cin >> code))
                break;

            if (!parseSlot(code, row, slot)) {
                cout << "Invalid slot.\n";
                continue;
            }

            cout << "Snack name (one word): ";

            if (!(cin >> name))
                break;

            cout << "How many to add (1-5): ";

            if (!(cin >> amount)) {
                if (cin.eof())
                    break;

                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid quantity.\n";
                continue;
            }

            if (amount < 1 || amount > 5) {
                cout << "Quantity must be 1 through 5.\n";
                continue;
            }

            if (dispenser.refillSlot(row, slot, name, amount))
                cout << "Refill successful.\n";
            else
                cout << "Refill failed: check space and existing snack type.\n";
        }

        door.closeAndLock();
        dispenser.setState(true);
    }

    void retrieveSnack() {
        if (dispenser.binIsEmpty()) {
            cout << "Retrieval bin is empty.\n";
            return;
        }

        dispenser.retrieveSnack();
        cout << "Returning to the customer menu...\n";
    }

    void buySnack() {
        if (door.isOpen()) {
            cout << "Machine unavailable during refill.\n";
            return;
        }

        if (!dispenser.binIsEmpty()) {
            cout << "A snack is waiting. "
                << "Press R on the main menu to retrieve it.\n";
            return;
        }

        cout << "\n--- SNACK PURCHASE ---\n";
        cout << "Step 1: Select a slot (A1-A5 or B1-B5).\n";

        string code = door.requestSlot();
        int row, slot;

        if (!parseSlot(code, row, slot)) {
            cout << "Invalid slot code.\n";
            return;
        }

        cout << "Step 2: Checking " << code
            << " for availability...\n";

        if (dispenser.getQuantity(row, slot) == 0) {
            cout << "Out of stock! Please select another snack.\n";
            return;
        }

        cout << dispenser.getSnackName(row, slot)
            << " is available.\n";

        cout << "Purchase accepted "
            << "\n";

        if (!dispenser.dispenseSnack(row, slot))
            return;

        cout << "Snack is ready for pickup.\n";
        cout << "Press R to retrieve now, "
            << "or M to return to the menu: ";

        string choice;

        if (!(cin >> choice))
            return;

        if (choice == "R" || choice == "r")
            retrieveSnack();
        else
            cout << "Snack remains in the bin. "
            << "Choose R on the main menu to collect it.\n";
    }

public:
    void run() {
        cout << "Welcome to the Vending Machine!\n";
        cout << "Price: " << price
            << " cents (snack prototype).\n";
        cout << "Machine starts empty. "
            << "Press K to enter refill mode.\n";

        while (true) {
            cout << "\n1. Buy snack\n";
            cout << "2. Show inventory\n";
            cout << "R. Retrieve snack\n";
            cout << "K. Refiller\n";
            cout << "3. Exit\n";
            cout << "Choice: ";

            string choice;

            if (!(cin >> choice))
                break;

            if (choice == "3")
                break;
            else if (choice == "K" || choice == "k")
                refillMode();
            else if (choice == "1")
                buySnack();
            else if (choice == "2")
                inventory();
            else if (choice == "R" || choice == "r")
                retrieveSnack();
            else
                cout << "Invalid option.\n";
        }

        cout << "Goodbye!\n";
    }
};

int main() {
    VendingMachine machine;
    machine.run();
    return 0;
}