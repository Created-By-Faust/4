#ifndef HOUSINGPRIMITIVES_H
#define HOUSINGPRIMITIVES_H

#include <string>

struct Room {
    std::string     name;
    std::string     comment;
    unsigned int    area;

    friend std::ostream& operator<<(std::ostream& os, const Room& r);
};

struct Address {
    std::string     street;
    unsigned int    apartmentNumber;
    unsigned int    houseNumber;

    friend std::ostream& operator<<(std::ostream& os, const Address& address);
};

struct Building {
    Room*           rooms;
    unsigned int    roomsCount;
    unsigned int    buildingNumber;

    ~Building();
    friend std::ostream& operator<<(std::ostream& os, const Building& building);
};


#endif //HOUSINGPRIMITIVES_H
