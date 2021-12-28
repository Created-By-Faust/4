//
//  library.hpp
//
//

#ifndef library_hpp
#define library_hpp
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
template <class T>
int getNum(T &a)
{
    std::cin >> a;
    if (!std::cin.good())
        return -1;
    return 1;
}
namespace Prog {

struct room{ // описатель помещений
    string name;
    int square;
    string comment;
};

struct buldings{
    int number;
    int amountRooms;
    room* Arr;
};
struct address{
    string street;
    int homeNumber;
    int flatNumber;
};
class lodging // жильё
{
private:
    std::string type;// one bedroom, apartments, cottage
public:
    
};

    
}
#endif /* library_hpp */
