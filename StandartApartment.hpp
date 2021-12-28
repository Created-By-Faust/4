#ifndef STANDARTAPARTMENT_HPP
#define STANDARTAPARTMENT_HPP

#include "Housing.hpp"
#include "HousingPrimitives.hpp"


class StandartApartment : public Housing {
    Room* rooms;
    unsigned int roomCount;
public:
     StandartApartment(const Address &address, HousingState state,
                       unsigned int cost, const Room *rooms,
                       unsigned int roomCount);

    ~StandartApartment();

    Address getAddress() const override;
    HousingType getHouseType() const override;
    HousingState getState() const override;
    unsigned int getCost() const override;
    unsigned int getTotalCost() const override;

    void setState(HousingState state) override;

    friend std::ostream& operator<< (std::ostream& os, const StandartApartment& apartment);
};

#endif //STANDARTAPARTMENT_HPP
