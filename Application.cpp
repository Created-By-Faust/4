#include <iostream>
#include "Application.hpp"

Application::Application()
{

}

void Application::startDialog()
{
    int command;

    helloDialog();

    std::cin >> command;
    while( true) {
        switch(command) {
            case 1:
                checkInDialog();
                break;
            case 2:
                evictionDialog();
                break;
            case 3:
                displayFreeHousingsDialog();
                break;
            case 4:
                displayHousingsDialog();
                break;
            case 5:
                std::cout << "Exit!\n";
                std::exit(0);
            default:
                std::cout << " Unknown command!\n";
        }

        helloDialog();

        std::cin >> command;
    }
    return ;
}

void Application::helloDialog()
{
    std::cout << "Hello! What do you wanna do?\n";
    std::cout << "1: check in new guy\n";
    std::cout << "2: evict some guy\n";
    std::cout << "3: display info about free housings\n";
    std::cout << "4: display info about  housings\n";
    std::cout << "5: exit from program\n";
}

void Application::checkInDialog()
{
    Address address;

    std::cout << "Ok, let`s check in yet another !\n";
    std::cout << "Enter street: \n";
    std::cin >> address.street;
    std::cout << "Enter house number: \n";
    std::cin >> address.houseNumber;
    std::cout << "Enter apartment number: \n";
    std::cin >> address.apartmentNumber;

    const Housing* housing = table.getHousingByAddress(address);
    if (!housing) {
        int type;

        std::cout << "This address does not exist, so create new one!\n";
        std::cout << "First of all, enter the type of housing:\n";
        std::cout << HousingType::cottage << ": cottage\n";
        std::cout << HousingType::studioApartment << ": studio apartment\n";
        std::cout << HousingType::standartApartment << ": standard apartment\n";
        std::cin >>  type;

        switch (static_cast<HousingType>(type)) {
            case cottage:
                cottageCreateDialog(address);
                break;
            case studioApartment:
                studioApartmentDialog(address);
                break;
            case standartApartment:
                standardApartmentDialog(address);
                break;
        }
    } else {
        if (housing->getState()) {
            std::cout << "Sorry guy, this housing is occupied by someone, I cannot to check in new one!\n";
        } else {
            table.setHousingState(address, HousingState::populated);
            std::cout << "Ok, This housing is empty, check in new \n";
        }
    }
}

void Application::evictionDialog()
{
    Address address;
    std::cout << "Enter the address, where need to evict some guy!\n";

    std::cout << "Enter street:\n";
    std::cin >> address.street;

    std::cout << "Enter house number:\n";
    std::cin >> address.houseNumber;

    std::cout << "Enter apartment number:\n";
    std::cin >> address.apartmentNumber;

    table.setHousingState(address, HousingState::notPopulated);

    std::cout << "People from this housing was evicted! AHAHAHAHAHA!\n";
}
 
void Application::displayFreeHousingsDialog()
{
    table.printFreeHousings();
}

void Application::displayHousingsDialog()
{
    table.printHousings();
}

void Application::cottageCreateDialog(const Address& address)
{
    int buildingCount;

    std::cout << "Enter count of buildings: \n";
    std::cin >> buildingCount;

    while (buildingCount <= 0) {
        std::cout << "Incorrect type! Enter again!\n";
        std::cin >> buildingCount;
    }

    Building buildings[buildingCount];

    std::cout << "So, let`s grab all info about buildings!\n";
    for (int i = 0; i < buildingCount; i++) {
        std::cout << "Enter count of rooms in the " << i << " building:\n";
        std::cin >> buildings[i].roomsCount;

        std::cout << "Enter building number:\n";
        std::cin >> buildings[i].buildingNumber;


        buildings[i].rooms = new Room[buildings[i].roomsCount];
        std::cout << "Fill info about all rooms\n";
        for (int j = 0; j < buildings[i].roomsCount; j++) {
            std::cout << "Fill info about new room\n";
            std::cout << "Enter name of the room:\n";
            std::cin >> buildings[i].rooms[j].name;
            std::cout << "Enter the area of the room:\n";
            std::cin >> buildings[i].rooms[j].area;
            std::cout << "Enter comment\n";
            std::cin >> buildings[i].rooms[j].comment;

            std::cout << "Ok, all info have been gotten. Create new one\n";
        }
        std::cout << "Ok, all info about building have been gotten. Create new one\n";
    }

    unsigned int cost;
    std::cout << "Enter cost of each sq meter:\n";
    std::cin >> cost;

    Housing* cottage = new Cottage(address, populated, cost, buildings, buildingCount);
    table.addNew(cottage);

    std::cout << "New housing was created and added to the table\n";
}

void Application::studioApartmentDialog(const Address& address)
{
    std::cout << "Ok, I will create new studio apartment\n";

    Room rooms[4];

    std::cout << "Filling info about living room: \n";
    std::cout << "Area(in sq m) \n";
    std::cin >> rooms[0].area;
    std::cout << "Enter some comment\n";
    std::cin >> rooms[0].comment;
    rooms[0].name = "living room";

    std::cout << "Filling info about kitchen:\n";
    std::cout << "Area(in sq m)\n";
    std::cin >> rooms[1].area;
    std::cout << "Enter some comment\n";
    std::cin >> rooms[1].comment;
    rooms[1].name = "kitchen";

    std::cout << "Filling info about bath room:\n";
    std::cout << "Area(in sq m)\n";
    std::cin >> rooms[2].area;
    std::cout << "Enter some comment\n";
    std::cin >> rooms[2].comment;
    rooms[2].name = "bath room";

    std::cout << "Filling info about vestibule:\n";
    std::cout << "Area(in sq m)\n";
    std::cin >> rooms[3].area;
    std::cout << "Enter some comment\n";
    std::cin >> rooms[3].comment;
    rooms[3].name = "vestibule";

    unsigned int cost;
    std::cout << "Enter cost of each sq meter:\n";
    std::cin >> cost;

    Housing* studio = new StudioApartment(address, populated, cost, rooms);
    table.addNew(studio);

    std::cout << "New housing was created and added to the table\n";
}

void Application::standardApartmentDialog(const Address& address)
{
    int roomCount;

    std::cout << "Enter count of rooms: \n";
    std::cin >> roomCount;

    while (roomCount <= 0) {
        std::cout << "Incorrect type! Enter again!\n";
        std::cin >> roomCount;
    }

    Room rooms[roomCount];

    std::cout << "So, let`s grab all info about rooms!\n";
    for (int i = 0; i < roomCount; i++) {
        std::cout << "Fill info about new room\n";
        std::cout << "Enter name of the room:\n";
        std::cin >> rooms[i].name;
        std::cout << "Enter the area of the room:\n";
        std::cin >> rooms[i].area;
        std::cout << "Enter comment\n";
        std::cin >> rooms[i].comment;

        std::cout << "Ok, all info have been gotten. Create new one\n";
    }

    unsigned int cost;
    std::cout << "Enter cost of each sq meter:\n";
    std::cin >> cost;

    Housing* aprt = new StandartApartment(address, populated, cost, rooms, roomCount);
    table.addNew(aprt);

    std::cout << "New housing was created and added to the table\n";
}
