#ifndef STUDIOAPARTMENT_H
#define STUDIOAPARTMENT_H

#include "Housing.hpp"
#include "HousingPrimitives.hpp"


class StudioApartment : public Housing {
    Room* rooms;
    unsigned int roomCount;
public:
    StudioApartment(const Address &address, HousingState state,
                    unsigned int cost, const Room *rooms);
    ~StudioApartment();

    Address getAddress() const override;
    HousingType getHouseType() const override;
    HousingState getState() const override;
    unsigned int getCost() const override;
    unsigned int getTotalCost() const override;

    void setState(HousingState state) override;

    friend std::ostream& operator<<(std::ostream& os, const StudioApartment& apartment);
};


#endif //STUDIOAPARTMENT_H
