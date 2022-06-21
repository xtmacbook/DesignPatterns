#include "Maze.h"

Room::Room(int rootNo) :roomNumber_(rootNo)
{

}

Room::Room(const Room&other)
{
   std::copy(other.sides_->cbegin(), other.sides_->cend(), sides_->begin());
    roomNumber_ = other.roomNumber_;
}

Room::Room()
{

}

Room* Room::Clone() const
{
    return new Room(*this);
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

Wall::Wall(const Wall&)
{

}

Wall* Wall::Clone() const
{
    return new Wall(*this);
}

void Wall::Enter()
{

}


Door::Door(const Door&other)
{
    room1_ = other.room1_;
    room2_ = other.room2_;
}

void Door::Initialize(Room*r1, Room*r2)
{
    room1_ = r1;
    room2_ = r2;
}

Door* Door::Clone() const
{
    return new Door(*this);
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

Maze::Maze(const Maze&)
{

}

Maze* Maze::Clone() const
{
    return new Maze(*this);
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

    auto* theDoor = new Door;
    theDoor->Initialize(r1, r2);

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

BombedWall::BombedWall():bomb_(true)
{

}

BombedWall::BombedWall(const BombedWall&other)
{
    bomb_ = other.bomb_;
}

Wall* BombedWall::Clone() const
{
    return new BombedWall(*this);
}

bool BombedWall::HasBomb()
{
    return bomb_;
}
