#ifndef PLAYER_H
#define PLAYER_H

#include <sstream>

using namespace std;

class Player {
    public:
    Player(int health, int hunger, int thirst, int gold,
            int x, int y);
    unsigned int getX() const;
    unsigned int getY() const;
    void setX(unsigned int newX);
    void setY(unsigned int newY);
    int getHunger() const;
    int getThirst() const;
    int getHealth() const;
    int getGold() const;
    void setThirst(int t);
    void setHunger(int h);
    void setHealth(int h);
    void setGold(int g);
    void newTurn();
    string printStats();
    bool isAlive() const;
    
    static const int DEFAULT_HEALTH = 5;
    static const int DEFAULT_HUNGER = 10;
    static const int DEFAULT_THIRST = 5;
    static const int DEFAULT_GOLD = 0;
    
    private:
    int health;
    int hunger;
    int thirst;
    int gold;
    int x;
    int y;
};

#endif