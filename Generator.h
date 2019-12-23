#pragma once
#include <utility>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define RoomPlaceTries 50
#define minRoomSize 3
#define maxRoomSize 7
#define WALL_SYMBOL '#'
#define SPACE_SYMBOL ' '

class Room
{
public:
    int x1, y1,
        x2, y2,
        height,
        width;
    std::pair<int, int> center;

    Room(int _x1, int _y1, int _h, int _w) : x1(_x1), y1(_y1), height(_h), width(_w), x2(_x1 + _w), y2(_y1 + _h)
    {
        center = std::make_pair(x1 + (width + 1) / 2, y1 + (height + 1) / 2);
        center.first--; center.second--;
    }

    // return true if two rooms intersects
    bool intersects(Room room)
    {
        return (x1 <= room.x2 && x2 >= room.x1 &&
            y1 <= room.y2 && room.y2 >= room.y1);
    }
};

class Generator
{
public:
    static std::vector< std::vector< char >> map;
    
    static void init(int MAP_HEIGHT, int MAP_WIDTH);

    static void Corridor(std::pair<int, int> center1, std::pair<int, int> center2);

    static void createRoom(Room newRoom);

    static void placeRooms();

    static void Print();
};

