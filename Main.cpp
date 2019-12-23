#include <iostream>
#include "Generator.h"

using namespace std;

int main()
{
    Generator::init(50,50);

    Generator::Print();

    cout << endl;

    Generator::placeRooms();

    Generator::Print();

    system("pause");
}