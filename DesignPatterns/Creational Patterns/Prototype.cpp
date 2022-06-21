#include "Prototype.h"

MazePrototypeFactory::MazePrototypeFactory(Maze*pMaze, Wall*pWall, Room*pRoom, Door*pDoor):
    prototypeMaze_(pMaze),
    prototypeWall_(pWall),
    prototypeRoom_(pRoom),
    prototypeDoor_(pDoor)
{

}

Maze* MazePrototypeFactory::MakeMaze() const
{
    return prototypeMaze_->Clone();
}

Room* MazePrototypeFactory::MakeRoom(int n) const
{
    return prototypeRoom_->Clone();
}

Wall* MazePrototypeFactory::MakeWall() const
{
    return prototypeWall_->Clone();
}

Door* MazePrototypeFactory::MakeDoor(Room* r1, Room*r2) const
{
    auto pDoor = prototypeDoor_->Clone();
    pDoor->Initialize(r1, r2);

    return pDoor;
}

MazePrototypeFactory simpleMazeFactory(
    new Maze, new Wall, new Room, new Door
);

MazePrototypeFactory bombedMazeFactory(
    new Maze, new BombedWall,
    new Room, new Door
);

Maze* CreateMaze_PrototypeFactor(MazePrototypeFactory * factory)
{
    return nullptr;
}
