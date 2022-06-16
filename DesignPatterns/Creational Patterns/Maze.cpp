#include "Maze.h"

Room::Room(int rootNo):roomNumber_(rootNo)
{

}

MapSite* Room::GetSide(Direction dir) const
{
    return nullptr;
}

void Room::SetSide(Direction, MapSite*)
{

}

void Room::Enter()
{

}

Wall::Wall()
{

}

void Wall::Enter()
{

}

Door::Door(Room* r1, Room* r2):
    room1_(r1),
    room2_(r2)
{

}

void Door::Enter()
{

}

Room* Door::OtherSideFrom(Room*)
{
    return nullptr;
}

bool Door::IsOpen() const
{
    return isOpen_;
}

Maze::Maze()
{

}

void Maze::AddRoom(Room*)
{

}

Room* Maze::RoomNo(int) const
{
    return nullptr;
}
