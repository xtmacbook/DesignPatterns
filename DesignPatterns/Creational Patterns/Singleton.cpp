#include "Singleton.h"

MazeSingletonFactory* MazeSingletonFactory::_instance = nullptr;

MazeSingletonFactory* MazeSingletonFactory::Instance() {
    if (!_instance) {
        _instance = new MazeSingletonFactory;
    }
    return _instance;
}

MazeSingletonFactory::MazeSingletonFactory()
{

}

//如果有继承的话

//MazeFactory* MazeFactory::Instance() {
//    if (_instance == 0) {
//        const char* mazeStyle = getenv("MAZESTYLE");
//
//        if (strcmp(mazeStyle, "bombed") == 0) {
//            _instance = new BombedMazeFactory;
//
//        }
//        else if (strcmp(mazeStyle, "enchanted") == 0) {
//            _instance = new EnchantedMazeFactory;
//
//            // ... other possible subclasses
//
//        }
//        else { // default
//            _instance = new MazeFactory;
//        }
//    }
//    return _instance;
//}