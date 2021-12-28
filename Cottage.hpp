#ifndef COTTAGE_H
#define COTTAGE_H

#include "Housing.hpp"

class Cottage : public Housing {
    Building* buildings;
    unsigned int buildingCount;
public:
    Cottage(const Address &address, HousingState state,
            unsigned int cost, const Building *buildings,
            unsigned int buildingCount);
    ~Cottage();

    Address getAddress() const override;
    HousingType getHouseType() const override;
    HousingState getState() const override;
    unsigned int getCost() const override;
    unsigned int getTotalCost() const override;

    void setState(HousingState state) override;

    friend std::ostream &operator<<(std::ostream& os, const Cottage& cot);
};

#endif //COTTAGE_H
