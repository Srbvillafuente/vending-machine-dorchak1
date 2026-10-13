//
// Created by Sebastian Baltazar on 10/13/26.
//

#ifndef UNTITLED_PACKAGESLOT_H
#define UNTITLED_PACKAGESLOT_H

class PackageSlot {
private:
    Snack snack;
    const int capacity;
    int countDispensed;

public:
    PackageSlot(Snack newSnack, int slotCapacity);

    bool dispense();
    void refill(Snack newSnack);
    const Snack& getSnack() const;
    int getDispensedCount() const;
    bool isEmpty() const;
};


#endif //UNTITLED_PACKAGESLOT_H
