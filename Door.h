#pragma once
#include <string>

class Door {
    bool open = false;

public:
    bool isOpen() const;
    void openForRefill();
    void closeAndLock();
    std::string requestSlot() const;
};