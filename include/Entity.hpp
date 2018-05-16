class Entity
{
public:
    int x, y; // Entity's map coordinates
    int ch; // ascii representation
    TCODColor col; // color

    Entity(int x, int y, int ch, const TCODColor &col);
    void render() const;
};