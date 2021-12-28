#include "Housing.hpp"

Housing::Housing(const Address &address, HousingType type, HousingState state, unsigned int cost) {
    this->address = address;
    this->type = type;
    this->state = state;
    this->cost = cost;
}
