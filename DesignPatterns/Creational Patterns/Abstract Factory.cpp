#include "Abstract Factory.h"

MazeFactory::MazeFactory()
{

}

Maze* MazeFactory::MakeMaze() const
{
    return new Maze;
}

Wall* MazeFactory::MakeWall() const
{
    return new Wall;
}

Room* MazeFactory::MakeRoom(int n) const
{
    return new Room(n);
}

Door* MazeFactory::MakeDoor(Room* r1, Room* r2) const
{
    return new Door(r1, r2);
}


Maze* CreateMaze_AbstractFactory(MazeFactory& factory)
{
    Maze* aMaze = factory.MakeMaze();
    Room* r1 = factory.MakeRoom(1);
    Room* r2 = factory.MakeRoom(2);
    Door* aDoor = factory.MakeDoor(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(Direction::North, factory.MakeWall());
    r1->SetSide(Direction::East, aDoor);
    r1->SetSide(Direction::South, factory.MakeWall());
    r1->SetSide(Direction::West, factory.MakeWall());
    
    r2->SetSide(Direction::North, factory.MakeWall());
    r2->SetSide(Direction::East, factory.MakeWall());
    r2->SetSide(Direction::South, factory.MakeWall());
    r2->SetSide(Direction::West, aDoor);

    return aMaze;
}

Room* BombedMazeFactory::MakeRoom(int n) const
{
    return nullptr;
}

Wall* BombedMazeFactory::MakeWall() const
{
    return nullptr;
}
