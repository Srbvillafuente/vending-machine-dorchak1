#pragma once
#include <string>

class RetrievalBin {
private:
    std::string contents;
    bool retrievalMode = false;

public:
    bool isEmpty() const;
    bool isReadyForPickup() const;
    bool release(const std::string& snack);
    std::string retrieveSnack();
};