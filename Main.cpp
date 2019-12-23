#include <iostream>
#include "Generator.h"

using namespace std;

int main()
{
    Generator::init(60,30);

    Generator::Print();


    Generator::placeRooms();

    Generator::Print();

    system("pause");
}