#include <iostream>
#include "RealtyTable.hpp"
RealtyTable::RealtyTable()
{
}

RealtyTable::~RealtyTable()
{
    for (auto & housing : housings)
        delete housing;
}

std::ostream &operator<<(std::ostream &os, RealtyTable &table)
{
    int i = 1;
    for (auto housing : table.housings) {
        os << "Housing № " << i << ":\n" << housing << std::endl;
        i++;
    }
    return os;
}


void RealtyTable::addNew(Housing *housing)
{
    housings.push_back(housing);
}

int RealtyTable::printFreeHousings()
{
    for (auto & housing : housings) {
        if (housing->getState() == HousingState::notPopulated) {
            switch (housing->getHouseType()) {
                case HousingType::cottage:
                    std::cout << *dynamic_cast<Cottage *>(housing);
                    break;
                case HousingType::studioApartment:
                    std::cout << *dynamic_cast<StudioApartment *>(housing);
                    break;
                case HousingType::standartApartment:
                    std::cout << *dynamic_cast<StandartApartment *>(housing);
                    break;
            }
        }
    }
    return 0;
}

int RealtyTable::printHousings()
{
    for (auto & housing : housings) {
         
            switch (housing->getHouseType()) {
                case HousingType::cottage:
                    std::cout << *dynamic_cast<Cottage *>(housing);
                    break;
                case HousingType::studioApartment:
                    std::cout << *dynamic_cast<StudioApartment *>(housing);
                    break;
                case HousingType::standartApartment:
                    std::cout << *dynamic_cast<StandartApartment *>(housing);
                    
                    break;
            
        }
        
    }
    return 0;
}

const Housing* RealtyTable::getHousingByAddress(const Address &address)
{
    for (auto & housing : housings) {
        if (housing->getAddress().street == address.street) {
            if (housing->getAddress().houseNumber == address.houseNumber) {
                if (housing->getAddress().apartmentNumber == address.apartmentNumber) {
                    return housing;
                } else {
                    return nullptr;
                }
            } else {
                return nullptr;
            }
        } else {
            return nullptr;
        }
    }

    return nullptr;
}

int RealtyTable::setHousingState(const Address &address, HousingState state)
{
    for (auto & housing : housings) {
        if (housing->getAddress().street == address.street
            and housing->getAddress().houseNumber == address.houseNumber
            and housing->getAddress().apartmentNumber == address.apartmentNumber){
                    housing->setState(state);
            return 1;
        }
                    
    }
    return 0;
}
