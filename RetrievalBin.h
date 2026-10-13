#pragma once
#include <string>

class RetrievalBin
{
private:
    std::string contents;

public:
    RetrievalBin();

    bool isEmpty() const;
    void receiveSnack(const std::string& snack);
    std::string retrieveSnack();
};
