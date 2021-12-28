//
//  Tests.hpp
//  4
//
//  Created by Дмитрий Емелин on 22.12.2021.
//

#ifndef Tests_hpp
#define Tests_hpp
#include"HousingPrimitives.hpp"
#include"Housing.hpp"
#include"RealtyTable.hpp"
#include"vector"
#include"gtest/gtest.h"


TEST(StudioApartment, Methods){
    Address address;
    address.street = "Lenina";
    address.houseNumber = 10;
    address.apartmentNumber = 1;
    
    Room rooms[4];
    rooms[0].area = 20;
    rooms[0].comment = "0";
    rooms[0].name = "living room";
    
    rooms[1].area = 30;
    rooms[1].comment = "1";
    rooms[1].name = "kitchen";

    rooms[2].area = 10;
    rooms[2].comment = "2";
    rooms[2].name = "bath room";

    rooms[3].area = 10;
    rooms[3].comment = "3";
    rooms[3].name = "vestibule";

    unsigned int cost = 100;

    Housing* studio = new StudioApartment(address, populated, cost, rooms);
    
    Address address2;
    address2 = studio->getAddress();
    ASSERT_EQ(address2.street, address.street);
    ASSERT_EQ(address2.houseNumber, address.houseNumber);
    ASSERT_EQ(address2.apartmentNumber, address.apartmentNumber);
    
    ASSERT_EQ(studio->getState(), populated);
    ASSERT_EQ(studio->getHouseType(), studioApartment);
    ASSERT_EQ(studio->getCost(), cost);
    ASSERT_EQ(studio->getTotalCost(), 7000);
    
    studio->setState(notPopulated);
    ASSERT_EQ(studio->getState(), notPopulated);
}

TEST(StandartApartment, Methods){
    Address address;
    address.street = "Emelina";
    address.houseNumber = 22;
    address.apartmentNumber = 21;
    
    unsigned int roomCount = 7;
    Room rooms[roomCount];

    for (int i = 0; i < roomCount; i++) {
        rooms[i].name = std::to_string(i);
        rooms[i].area = 10;
        rooms[i].comment = "0";
    }

    unsigned int cost = 100;

    Housing* apartment = new StandartApartment(address, populated, cost, rooms, roomCount);
    
    Address address2;
    address2 = apartment->getAddress();
    ASSERT_EQ(address2.street, address.street);
    ASSERT_EQ(address2.houseNumber, address.houseNumber);
    ASSERT_EQ(address2.apartmentNumber, address.apartmentNumber);
    
    ASSERT_EQ(apartment->getState(), populated);
    ASSERT_EQ(apartment->getHouseType(), standartApartment);
    ASSERT_EQ(apartment->getCost(), cost);
    ASSERT_EQ(apartment->getTotalCost(), 7000);
    
    apartment->setState(notPopulated);
    ASSERT_EQ(apartment->getState(), notPopulated);
}

TEST(Cottage, Methods){
    Address address;
    address.street = "Sovet";
    address.houseNumber = 22;
    address.apartmentNumber = 1;
    
    unsigned int buildingCount = 2;
    Building buildings[buildingCount];

    for (int i = 0; i < buildingCount; i++) {
        buildings[i].roomsCount = 2;
        buildings[i].buildingNumber = i;

        buildings[i].rooms = new Room[buildings[i].roomsCount];
    
        for (int j = 0; j < buildings[i].roomsCount; j++) {
            buildings[i].rooms[j].name = std::to_string(i);
            buildings[i].rooms[j].area = 10;
            buildings[i].rooms[j].comment = "0";
        }
    }

    unsigned int cost = 100;

    Housing* cttg = new Cottage(address, populated, cost, buildings, buildingCount);
    
    Address address2;
    address2 = cttg->getAddress();
    ASSERT_EQ(address2.street, address.street);
    ASSERT_EQ(address2.houseNumber, address.houseNumber);
    
    ASSERT_EQ(cttg->getState(), populated);
    ASSERT_EQ(cttg->getHouseType(), cottage);
    ASSERT_EQ(cttg->getCost(), cost);
    //ASSERT_EQ(cttg->getTotalCost(), 2000);
    
    cttg->setState(notPopulated);
    ASSERT_EQ(cttg->getState(), notPopulated);
    
}

TEST(RealtyTable, Methods){
    RealtyTable table;
    Address address;
    address.street = "Amelina";
    address.houseNumber = 11;
    address.apartmentNumber = 12;
    
    Room rooms[4];
    rooms[0].area = 20;
    rooms[0].comment = "0";
    rooms[0].name = "living room";
    
    rooms[1].area = 30;
    rooms[1].comment = "1";
    rooms[1].name = "kitchen";

    rooms[2].area = 10;
    rooms[2].comment = "2";
    rooms[2].name = "bath room";

    rooms[3].area = 10;
    rooms[3].comment = "3";
    rooms[3].name = "vestibule";

    unsigned int cost = 100;
    
    Housing* studio = new StudioApartment(address, populated, cost, rooms);
        
    //table.addNew(studio);
    //ASSERT_EQ(table.printHousings(), 2);
    //ASSERT_EQ(table.setHousingState(address, notPopulated), 1);

    //table.setHousingState(address, notPopulated);
    
    //ASSERT_EQ(table.printFreeHousings(), 2);
    
}

TEST(Vector, Methods){
    Address address1;
    address1.street = "Amelina";
    address1.houseNumber = 11;
    address1.apartmentNumber = 12;
    Address address2;
    address2.street = "elina";
    address2.houseNumber = 13;
    address2.apartmentNumber = 2;
    Address address3;
    address3.street = "Alina";
    address3.houseNumber = 21;
    address3.apartmentNumber = 2;
    Room rooms[4];
    Vector<Housing*> housings;
    
    Housing*  studio = new StudioApartment(address1, populated, 100, rooms);
    housings.push_back(studio);
    //Housing*  studio2 = new StudioApartment(address2, populated, 100, rooms);
    housings.push_back(new StudioApartment(address2, populated, 100, rooms));
    housings.push_back(new StudioApartment(address3, populated, 100, rooms));
    
    Vector<Housing*> u(housings);
    for (auto & i : u) {
        EXPECT_TRUE(i);
    }
   
    
    
    
}
#endif /* Tests_hpp */
