#include "Maze.h"

Room::Room(int rootNo) :roomNumber_(rootNo)
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

Door::Door(Room* r1, Room* r2) :
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

Maze* MazeGame::CreateMaze()
{
    auto* aMaze = new Maze;

    auto* r1 = new Room(1);
    auto* r2 = new Room(2);

    auto* theDoor = new Door(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(Direction::North, new Wall);
    r1->SetSide(Direction::East, theDoor);
    r1->SetSide(Direction::South, new Wall);
    r1->SetSide(Direction::West, new Wall);

    r2->SetSide(Direction::North, new Wall);
    r2->SetSide(Direction::East, new Wall);
    r2->SetSide(Direction::South, new Wall);
    r2->SetSide(Direction::West, theDoor);

    return aMaze;
}
