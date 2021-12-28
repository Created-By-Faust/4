#include <ostream>
#include "StandartApartment.hpp"

StandartApartment::StandartApartment(const Address &address, HousingState state,
                                     unsigned int cost, const Room *rooms,
                                     unsigned int roomCount)
                                        : Housing(address, HousingType::standartApartment, state, cost)
{
    this->roomCount = roomCount;
    this->rooms = new Room[roomCount];

    for (int i = 0; i < roomCount; i++)
        this->rooms[i] = rooms[i];
}

StandartApartment::~StandartApartment()
{
    delete [] rooms;
}

Address StandartApartment::getAddress() const
{
    return address;
}

HousingType StandartApartment::getHouseType() const
{
    return type;
}

HousingState StandartApartment::getState() const
{
    return state;
}

unsigned int StandartApartment::getCost() const
{
    return cost;
}

unsigned int StandartApartment::getTotalCost() const
{
    unsigned int totalCost = 0;

    for (int i = 0; i < roomCount; i++)
        totalCost += rooms[i].area * cost;

    return totalCost;
}

void StandartApartment::setState(HousingState state)
{
    this->state = state;
}

std::ostream &operator<<(std::ostream &os, const StandartApartment &apartment)
{
    os << "-------------------------------------------------\n";
    os << "Standard apartment:\n";
    os << apartment.address << std::endl
       << "Cost per sq meter: " << apartment.cost << std::endl;

    os << "State: ";
    switch (apartment.state) {
        case populated:
            os << "populated";
            break;
        case notPopulated:
            os << "not populated";
            break;
    }
    os << std::endl;

    for (int i = 0; i < apartment.roomCount; i++)
        os << apartment.rooms[i] << std::endl;

    os << "-------------------------------------------------\n";
    return os;
}

