#pragma once
#include <string>

class RetrievalBin {
private:
    std::string contents;

public:
    RetrievalBin();

    bool isEmpty() const;
    bool release(const std::string& snack);
    std::string retrieveSnack();
};