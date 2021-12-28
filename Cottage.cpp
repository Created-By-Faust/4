#include <ostream>
#include "Cottage.hpp"

Cottage::Cottage(const Address &address, HousingState state,
                unsigned int cost, const Building *buildings,
                unsigned int buildingCount)
                    : Housing(address, HousingType::cottage, state, cost)
{
    this->buildingCount = buildingCount;
    this->buildings = new Building[buildingCount];

    for (int i = 0; i < buildingCount; i++)
        this->buildings[i] = buildings[i];
}

Cottage::~Cottage()
{
    delete [] buildings;
}

Address Cottage::getAddress() const
{
    return address;
}

HousingType Cottage::getHouseType() const
{
    return type;
}

HousingState Cottage::getState() const
{
    return state;
}

unsigned int Cottage::getCost() const
{
    return cost;
}

unsigned int Cottage::getTotalCost() const
{
    unsigned int totalCost = 0;

    for (int i = 0; i < buildingCount; i++)
        for (int j = 0; j < buildings[i].roomsCount; i++)
            totalCost += buildings[i].rooms->area * cost;

    return totalCost;
}

void Cottage::setState(HousingState state)
{
    this->state = state;
}

std::ostream &operator<<(std::ostream &os, const Cottage &cot)
{
    os << "-------------------------------------------------\n";
    os << "Cottage:\n";
    os << cot.address << std::endl
       << "Cost per sq meter: " << cot.cost << std::endl;

    os << "State: ";
    switch (cot.state) {
        case populated:
            os << "populated";
            break;
        case notPopulated:
            os << "not populated";
            break;
    }
    os << std::endl;

    for (int i = 0; i < cot.buildingCount; i++)
        os << cot.buildings[i] << std::endl;

    os << "------------------------------------------------\n";

    return os;
}


