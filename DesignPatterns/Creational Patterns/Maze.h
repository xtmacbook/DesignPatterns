#pragma once

#include <array>

enum class  Direction : unsigned char
{
    North,South,East,West
};

class MapSite
{
public:
    virtual void Enter() = 0;
};

class Room : public MapSite
{
public:
    Room();
    Room(int rootNo);
    Room(const Room&);

    virtual Room* Clone()const;

    MapSite* GetSide(Direction)const;

    void SetSide(Direction, MapSite*);

    virtual void Enter();

private:
    std::array<MapSite*,4> sides_[4];
    int roomNumber_;
};

class Wall : public MapSite
{
public:
    Wall();
    Wall(const Wall&);

    virtual Wall* Clone()const;

    virtual void Enter();
};

class Door : public MapSite
{
public:
    Door() = default;

    Door(const Door&);

    virtual void Initialize(Room*, Room*);
    virtual Door* Clone()const;

    virtual void Enter();
    Room* OtherSideFrom(Room*);
    bool IsOpen()const;

private:
    Room* room1_;
    Room* room2_;
    bool isOpen_;
};

class BombedWall : public Wall {
public:
    BombedWall();
    BombedWall(const BombedWall&);

    virtual Wall* Clone() const;
    bool HasBomb();
private:
    bool bomb_;
};

class Maze
{
public:
    Maze();
    Maze(const Maze&);
    virtual Maze* Clone()const;
    void AddRoom(Room*);
    Room* RoomNo(int)const;

private:

};

class MazeGame
{
public:
    Maze* CreateMaze();
};

class Spell;