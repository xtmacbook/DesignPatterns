#include "Maze.h"

class MazeFactory {
public:
    MazeFactory();

    virtual Maze* MakeMaze() const;
    virtual Wall* MakeWall() const;
    virtual Room* MakeRoom(int n) const;
    virtual Door* MakeDoor(Room* r1, Room* r2) const;
};

class EnchantedMazeFactory : public MazeFactory
{
public:
    EnchantedMazeFactory();

    virtual Room* MakeRoom(int n) const;

    virtual Door* MakeDoor(Room* r1, Room* r2) const;

protected:
    Spell* CastSpell() const;
};

class BombedMazeFactory : public MazeFactory
{
public:
    virtual Room* MakeRoom(int n) const;

    virtual Wall* MakeWall() const;
};