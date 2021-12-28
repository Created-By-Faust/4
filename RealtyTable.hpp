#ifndef MIPHI_REALTYTABLE_H
#define MIPHI_REALTYTABLE_H

#include <vector>
#include "Housing.hpp"
#include "Cottage.hpp"
#include "StudioApartment.hpp"
#include "StandartApartment.hpp"
#include "Vector.hpp"

class RealtyTable {
    Vector<Housing*> housings;
    //unsigned int housingArraySize;
public:
    RealtyTable();
    ~RealtyTable();

    int printFreeHousings();
    int printHousings();
    void addNew(Housing *housing);
    int setHousingState(const Address &address, HousingState state);
    const Housing *getHousingByAddress(const Address &address);

    friend std::ostream& operator<<(std::ostream& os, RealtyTable& table);
};


#endif //MIPHI_REALTYTABLE_H
