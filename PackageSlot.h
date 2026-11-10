#pragma once
#include <string>

class PackageSlot {
    std::string snack;
    static const int capacity = 5;
    int quantity = 0;
    int countDispensed = 0;

public:
    std::string drop();
    bool refill(const std::string& newSnack, int amount);
    bool isEmpty() const;
    int getQuantity() const;
    int getDispensedCount() const;
    std::string getSnackName() const;
};