#pragma once
#include "PackageSlot.h"

class SnackRow {
private:
    PackageSlot packageSlots[5];

public:
    PackageSlot& getPackageSlot(int index);
};