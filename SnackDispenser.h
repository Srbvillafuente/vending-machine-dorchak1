#pragma once
#include <string>
#include "SnackStorage.h"
#include "RetrievalBin.h"

class SnackDispenser {
private:
    SnackStorage storage;
    RetrievalBin retrievalBin;
    bool state = false;

public:
    void setState(bool newState);
    bool getState() const;

    void selectSnack();
    bool dispenseSnack(int row, int slot);
    bool refillSlot(int row, int slot, const std::string& snack);
    void retrieveSnack();
};
