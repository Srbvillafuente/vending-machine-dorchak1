#pragma once
#include <string>
#include "SnackStorage.h"
#include "RetrievalBin.h"

class SnackDispenser {
    SnackStorage storage;
    RetrievalBin retrievalBin;
    bool selling = false;

public:
    void setState(bool enabled);
    bool dispenseSnack(int row, int slot);
    bool refillSlot(int row, int slot,
        const std::string& snack, int amount);
    void retrieveSnack();
    bool binIsEmpty() const;
    int getQuantity(int row, int slot);
    int getSold(int row, int slot);
    std::string getSnackName(int row, int slot);
};