#include "RetrievalBin.h"
using namespace std;

bool RetrievalBin::isEmpty() const {
    return contents.empty();
}

bool RetrievalBin::isReadyForPickup() const {
    return retrievalMode && !isEmpty();
}

bool RetrievalBin::release(const string& snack) {
    if (!isEmpty() || snack.empty())
        return false;

    contents = snack;
    retrievalMode = true;
    return true;
}

string RetrievalBin::retrieveSnack() {
    if (!isReadyForPickup())
        return "";

    string snack = contents;
    contents.clear();
    retrievalMode = false;

    return snack;
}