#include "SnackStorage.h"

SnackRow& SnackStorage::getSnackRow(int index) {
    return snackRows[index];
}

PackageSlot& SnackStorage::getPackageSlot(int row, int slot) {
    return getSnackRow(row).getPackageSlot(slot);
}