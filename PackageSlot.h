#pragma once
#include <string>

class PackageSlot {
private:
    std::string snack;
    const int capacity = 5;
    int quantity = 0;
    int countDispensed = 0;

public:
    PackageSlot();

    std::string drop();
    bool refill(const std::string& newSnack);
    bool isEmpty() const;
    int getDispensedCount() const;
};