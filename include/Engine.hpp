class Engine
{
public:
    TCODList<Entity *> entities;
    Entity *player;
    Map *map;

    Engine();
    ~Engine();
    void update();
    void render();
};

extern Engine engine;