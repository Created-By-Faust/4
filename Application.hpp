#ifndef APPLICATION_H
#define APPLICATION_H

#include "RealtyTable.hpp"

class Application {
    RealtyTable table;

    void helloDialog();

    void checkInDialog();
    void evictionDialog();
    void displayFreeHousingsDialog();
    void displayHousingsDialog();
    void cottageCreateDialog(const Address& address);
    void studioApartmentDialog(const Address& address);
    void standardApartmentDialog(const Address& address);

public:
    Application();

    void startDialog();
};


#endif //APPLICATION_H
