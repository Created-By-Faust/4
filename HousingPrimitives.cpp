#include <ostream>
#include "HousingPrimitives.hpp"

std::ostream& operator<<(std::ostream &os, const Room &r)
{
    os  << "Room: \n"
        << "\tName: "     << r.name       << std::endl
        << "\tArea: "     << r.area       << std::endl
        << "\tComment: "    << r.comment;

    return os;
}

std::ostream& operator<<(std::ostream &os, const Address &address)
{
    os  << "Address: \n"
        << "\tStreet: "           << address.street            << std::endl
        << "\tHouse number: "     << address.houseNumber       << std::endl
        << "\tApartment number: " << address.apartmentNumber;

    return os;
}

std::ostream& operator<<(std::ostream &os, const Building &building)
{

    os << "Building: \n";
    for (int i = 0; i < building.roomsCount; i++)
        os  << building.rooms[i];

    return os;
}

Building::~Building()
{
    delete [] rooms;
}
