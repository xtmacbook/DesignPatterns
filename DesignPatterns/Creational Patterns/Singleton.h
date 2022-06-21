
class MazeSingletonFactory {
public:
    static MazeSingletonFactory* Instance();

    // existing interface goes here
protected:
    MazeSingletonFactory();
private:
    static MazeSingletonFactory* _instance;
};