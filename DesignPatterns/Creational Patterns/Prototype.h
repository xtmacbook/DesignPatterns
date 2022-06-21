#include "Abstract Factory.h"


/*

 If CreateMaze is parameterized by various prototypical room,door, and wall
objects, which it then copies and adds to the maze,then you can change the
maze's composition by replacing these prototypical objects with different
ones. This is an example of the Prototype (133) pattern.

*/

class MazePrototypeFactory : public MazeFactory
{
public:
    MazePrototypeFactory(Maze*, Wall*, Room*, Door*);

    virtual Maze* MakeMaze() const;
    virtual Room* MakeRoom(int) const;
    virtual Wall* MakeWall() const;
    virtual Door* MakeDoor(Room*, Room*) const;

private:
    Maze* prototypeMaze_;
    Room* prototypeRoom_;
    Wall* prototypeWall_;
    Door* prototypeDoor_;
};

