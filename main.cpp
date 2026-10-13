#include <iostream>
#include <string>

using namespace std;


// --------------------  COIL  --------------------

class Coil
{
private:
    int capacity;
    int coil;
    int ID;
    int counter;
    string contents;

public:

    Coil()
    {
        capacity = 5;
        coil = 0;
        ID = 0;
        counter = capacity;
        contents = "";
    }

    void setCoil(int slotID, int coilNumber, string snack)
    {
        ID = slotID;
        coil = coilNumber;
        contents = snack;
        counter = capacity;
    }

    bool isEmpty()
    {
        return counter == 0;
    }

    string dispense()
    {
        if (counter > 0)
        {
            counter--;
            return contents;
        }

        return "";
    }

    void refill()
    {
        counter = capacity;
    }

    int getCounter() const
    {
        return counter;
    }

    string getContents()
    {
        return contents;
    }

    int getID() const
    {
        return ID;
    }
};


// -------------------- SET OF COILS --------------------

class SetOfCoils
{
private:

    // 3 rows and 5 columns
    Coil slots[3][5];

public:

    Coil& getSlot(int row, int column)
    {
        return slots[row][column];
    }
};


// -------------------- SNACK STORAGE --------------------

class SnackStorage
{
private:

    SetOfCoils setOfSlots;

public:

    Coil& getCoil(int row, int column)
    {
        return setOfSlots.getSlot(row, column);
    }
};


// -------------------- RETRIEVAL BIN --------------------

class RetrievalBin
{
private:

    string contents;

public:

    RetrievalBin()
    {
        contents = "";
    }

    bool isEmpty()
    {
        return contents == "";
    }

    void receiveSnack(string snack)
    {
        contents = snack;
    }

    string retrieveSnack()
    {
        string snack = contents;
        contents = "";

        return snack;
    }
};


// -------------------- SNACK DISPENSER --------------------

class SnackDispenser
{
private:

    SnackStorage snackStorage;
    RetrievalBin retrievalBin;

public:

    void loadCoil(int row, int column, int ID,
        int coil, string snack)
    {
        snackStorage.getCoil(row, column)
            .setCoil(ID, coil, snack);
    }


    void dispenseSnack(int row, int column)
    {
        Coil& coil =
            snackStorage.getCoil(row, column);

        if (coil.isEmpty())
        {
            cout << "Out of stock." << endl;
        }
        else
        {
            string snack = coil.dispense();

            retrievalBin.receiveSnack(snack);

            cout << snack << " has been dispensed" << endl;
        }
    }


    void retrieveSnack()
    {
        if (retrievalBin.isEmpty())
        {
            cout << "Retrieval bin is empty." << endl;
        }
        else
        {
            cout << "Retrieved: "
                << retrievalBin.retrieveSnack()
                << endl;
        }
    }


    void refillSlot(int row, int column)
    {
        snackStorage.getCoil(row, column).refill();

        cout << "Slot refilled." << endl;
    }


    void checkCoil(int row, int column)
    {
        Coil& coil =
            snackStorage.getCoil(row, column);

        cout << "Coil ID: "
            << coil.getID() << endl;

        cout << "Contents: "
            << coil.getContents() << endl;

        cout << "Packages remaining: "
            << coil.getCounter() << endl;
    }
};


// -------------------- MAIN --------------------

int main()
{
    SnackDispenser machine;

    // Load a coil
    machine.loadCoil(0, 0, 1, 1, "Chips");

    // Check the coil
    machine.checkCoil(0, 0);

    cout << endl;

    // Dispense a snack
    machine.dispenseSnack(0, 0);

    // Customer retrieves the snack
    machine.retrieveSnack();

    cout << endl;

    // Check slot again
    machine.checkCoil(0, 0);

    return 0;
}
