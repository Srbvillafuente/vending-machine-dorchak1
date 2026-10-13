//
// Created by Sebastian Baltazar on 10/13/26.
//

#ifndef UNTITLED_DOOR_H
#define UNTITLED_DOOR_H
#include <string>

class Door {
    private:
    std::string name;

    public:
    std::string getName() const;
    void setName(std::string name);
};

#endif //UNTITLED_DOOR_H
