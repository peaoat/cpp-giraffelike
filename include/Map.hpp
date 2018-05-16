static const int ROOM_MAX_SIZE = 12;
static const int ROOM_MIN_SIZE = 6;

struct Tile
{
    bool canWalk; // is the tile walkable by an Entity?
    Tile(): canWalk(false)
    {

    }
};

class Map
{
public:
    int width, height;

    Map(int width, int height);
    ~Map();
    bool isWall(int x, int y) const;
    void render() const;
protected:
    Tile *tiles;
    friend class BspListener;

    void dig(int x1, int y1, int x2, int y2);
    void createRoom(bool first, int x1, int y1, int x2, int y2);
};

class BspListener:
public ITCODBspCallback
{
private:
    Map &map;
    int roomNum;
    int lastx, lasty;
public:
    BspListener(Map &map):
        map(map), roomNum(0)
    {

    }
    bool visitNode(TCODBsp *node, void *userData)
    {
        if (node->isLeaf())
        {
            int x, y, w, h;
            TCODRandom *rng = TCODRandom::getInstance();
            w = rng->getInt(ROOM_MIN_SIZE, node->w - 2);
            h = rng->getInt(ROOM_MIN_SIZE, node->h - 2);
            x = rng->getInt(node->x + 1, node->x + node->w - w - 1);
            y = rng->getInt(node->y + 1, node->y + node->h - h - 1);
            map.createRoom(roomNum == 0, x, y, x + w - 1, y + h - 1);

            if (roomNum != 0)
            {
                map.dig(lastx, lasty, x + w / 2, lasty);
                map.dig(x + w / 2, lasty, x + w / 2, y + h / 2);
            }
            lastx = x + w / 2;
            lasty = y + h / 2;
            roomNum ++;
        }
        return true;
    }
};