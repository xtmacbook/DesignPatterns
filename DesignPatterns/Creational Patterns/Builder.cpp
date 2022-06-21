#include "Builder.h"

void MazeBuilder::BuildMaze()
{

}

void MazeBuilder::BuildRoom(int room)
{

}

void MazeBuilder::BuildDoor(int roomFrom, int roomTo)
{

}

Maze* MazeBuilder::GetMaze()
{
    return nullptr;
}

MazeBuilder::MazeBuilder()
{

}
/*
If CreateMaze is passed an object that can create a new maze in its entirety
using operations for adding rooms, doors, and walls to the maze it builds,
then you can use inheritance to change parts of the maze or the way the maze
is built. This is an example of the Builder (110) pattern.

*/
Maze* CreateMaze_Builder(MazeBuilder&builder)
{
    builder.BuildMaze();

    builder.BuildRoom(1);
    builder.BuildRoom(2);
    builder.BuildDoor(1, 2);

    return builder.GetMaze();
}

StandardMazeBuilder::StandardMazeBuilder():currentMaze_(nullptr)
{

}

void StandardMazeBuilder::BuildMaze()
{
    currentMaze_ = new Maze;
}

void StandardMazeBuilder::BuildRoom(int n)
{
    if (!currentMaze_->RoomNo(n)) {
        Room* room = new Room(n);
        currentMaze_->AddRoom(room);

        room->SetSide(Direction::North, new Wall);
        room->SetSide(Direction::South, new Wall);
        room->SetSide(Direction::East, new Wall);
        room->SetSide(Direction::West, new Wall);
    }
}

void StandardMazeBuilder::BuildDoor(int n1, int n2)
{
    Room* r1 = currentMaze_->RoomNo(n1);
    Room* r2 = currentMaze_->RoomNo(n2);
    Door* d = new Door;
    d->Initialize(r1, r2);

    r1->SetSide(CommonWall(r1, r2), d);
    r2->SetSide(CommonWall(r2, r1), d);
}

Maze* StandardMazeBuilder::GetMaze()
{
    return currentMaze_;
}

Direction StandardMazeBuilder::CommonWall(Room*, Room*)
{
    return Direction::East;
}
