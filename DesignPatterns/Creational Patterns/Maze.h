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
    Room(int rootNo);

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

    virtual void Enter();
};

class Door : public MapSite
{
public:
    Door(Room* = nullptr,Room* = nullptr);

    virtual void Enter();
    Room* OtherSideFrom(Room*);
    bool IsOpen()const;

private:
    Room* room1_;
    Room* room2_;
    bool isOpen_;
};

class Maze
{
public:
    Maze();
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