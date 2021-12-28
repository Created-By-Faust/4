#ifndef HOUSING_H
#define HOUSING_H

#include "HousingPrimitives.hpp"

enum HousingState {
    populated,
    notPopulated
};

enum HousingType {
    cottage,
    studioApartment,
    standartApartment
};

class Housing {
protected:
    Address         address;
    HousingType     type;
    HousingState    state;
    unsigned int    cost; // the cost of one square meter
public:
    Housing(const Address &address, HousingType type, HousingState state, unsigned int cost);
    //virtual ~Housing() = 0;

    virtual Address         getAddress()    const    = 0;
    virtual HousingType     getHouseType()  const    = 0;
    virtual HousingState    getState()      const    = 0;
    virtual unsigned int    getCost()       const    = 0;
    virtual unsigned int    getTotalCost()  const    = 0;

    virtual void setState(HousingState state) = 0;
};

#endif //HOUSING_H
