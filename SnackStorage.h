#pragma once
#include "SnackRow.h"

class SnackStorage {
private:
    SnackRow snackRows[2];

public:
    SnackRow& getSnackRow(int index);
    PackageSlot& getPackageSlot(int row, int slot);
};