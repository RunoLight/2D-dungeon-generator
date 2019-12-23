#include "Generator.h"

std::vector< std::vector< char >> Generator::map = std::vector< std::vector <char>>(0, std::vector<char>(0));

void Generator::init(int MAP_HEIGHT, int MAP_WIDTH)
{
    map = std::vector< std::vector <char>>(MAP_WIDTH, std::vector<char>(MAP_HEIGHT, WALL_SYMBOL));
}

void Generator::createRoom(Room newRoom)
{
    for (int i = newRoom.y1; i < newRoom.y1 + newRoom.height - 1; i++)
        for (int j = newRoom.x1; j < newRoom.x1 + newRoom.width - 1; j++)
            map[j][i] = SPACE_SYMBOL;

    map[newRoom.center.first][newRoom.center.second] = 'X'; //rooms center show
}

void Generator::Corridor(std::pair<int, int> center1, std::pair<int, int> center2)
{
    //vertical corridor
    int index1;
    if (center1.second < center2.second)
        index1 = std::max(center2.first, center1.first);
    else
        index1 = std::min(center2.first, center1.first);

    for (int i = std::min(center1.second, center2.second); i <= std::max(center1.second, center2.second); i++)
        map[index1][i] = SPACE_SYMBOL;
    
    //horizontal corridor
    int index;
    if (center1.first > center2.first)
        index = std::max(center2.second, center1.second);
    else
        index = std::min(center2.second, center1.second);

    for (int j = std::min(center1.first, center2.first); j <= std::max(center1.first, center2.first); j++)
        map[j][index] = SPACE_SYMBOL;
}

void Generator::Print()
{
    for (int i = 0; i < Generator::map.size(); i++)
    {
        for (int j = 0; j < Generator::map[i].size(); j++)
        {
            std::cout << Generator::map[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Generator::placeRooms()
{
    std::vector<Room> rooms;
    std::pair<int, int> prevCenter;

    // randomize values for each room
    for (int i = 0; i < RoomPlaceTries; i++)
    {
        int w = minRoomSize + rand() % (maxRoomSize - minRoomSize + 1);
        int h = minRoomSize + rand() % (maxRoomSize - minRoomSize + 1);
        int x = rand() % (map.size() - h - 1) + 1;
        int y = rand() % (map[0].size() - w - 1) + 1;

        // create room with randomized values
        Room newRoom(x, y, w, h);

        //check if new room does not intersects any of already existing rooms
        bool failed = false;
        //for (int k = 0; k < rooms.size(); k++)
        //{
        //    if (newRoom.intersects(rooms[k])) {
        //        failed = true;
        //        break;
        //    }
        //}
        if (!failed) {
            // carves out room in map
            Generator::createRoom(newRoom);

            Generator::Print();

            if (i) //skips first iteration
                Generator::Corridor(prevCenter, newRoom.center);

            prevCenter = newRoom.center;

            Generator::Print();

            // push new room into rooms array
            rooms.push_back(newRoom);
        }
    }
}