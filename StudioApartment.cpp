#include <ostream>
#include "StudioApartment.hpp"


StudioApartment::StudioApartment(const Address &address, HousingState state,
                                 unsigned int cost, const Room *rooms)
                                    : Housing(address, HousingType::studioApartment, state, cost)
{
    roomCount = 4;
    this->rooms = new Room[roomCount];

    for (int i = 0; i < roomCount; i++)
        this->rooms[i] = rooms[i];
}

StudioApartment::~StudioApartment()
{
    delete [] rooms;
}

Address StudioApartment::getAddress() const
{
    return address;
}

HousingType StudioApartment::getHouseType() const
{
    return type;
}

HousingState StudioApartment::getState() const
{
    return state;
}

unsigned int StudioApartment::getCost() const
{
    return cost;
}

unsigned int StudioApartment::getTotalCost() const
{
    unsigned int totalCost = 0;

    for (int i = 0; i < roomCount; i++)
        totalCost += rooms[i].area * cost;

    return totalCost;
}

void StudioApartment::setState(HousingState state)
{
    this->state = state;
}

std::ostream &operator<<(std::ostream &os, const StudioApartment &apartment) {
    os << "-------------------------------------------------\n";
    os << "Studio apartment:\n";
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
