#include <iostream>
#include "Generator.h"

using namespace std;

int main()
{
    Generator::Generate(60,30);

    Generator::Print();


    Generator::placeRooms();

    Generator::Print();

    system("pause");
}