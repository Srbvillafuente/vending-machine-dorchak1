#include "RetrievalBin.h"
#include <iostream>

using namespace std;

RetrievalBin::RetrievalBin() {
    contents = "";
}

bool RetrievalBin::isEmpty() const {
    return contents.empty();
}

bool RetrievalBin::release(const string& snack) {
    if (!isEmpty()) {
        cout << "Retrieval bin is already occupied." << endl;
        return false;
    }

    if (snack.empty()) {
        return false;
    }

    contents = snack;
    return true;
}

string RetrievalBin::retrieveSnack() {
    if (isEmpty()) {
        cout << "Retrieval bin is empty." << endl;
        return "";
    }

    string snack = contents;
    contents = "";

    return snack;
}