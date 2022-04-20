#include "Card.h"

#ifndef MINION_H
#define MINION_H

class Minion: virtual public Card{
protected:
    int attack;
    int health;

public:
    Minion();
    Minion(string name, string backgroundFile, string description, CardType cardType, int cost, int attack, int health);
    Minion(string name, string backgroundFile, string description, int cost, int attack, int health);
    Minion(string name, string backgroundFile, CardType cardType, int cost, int attack, int health);
    Minion(const Minion& minion);

    int getAttack() const {return this->attack;}
    int getHealth() const {return this->health;}

    void setAttack(int attack){this->attack = attack;}
    void setHealth(int health){this->health = health;}

    Card& operator = (const Card& card);
    Minion& operator = (const Minion& minion);
    bool operator < (const Minion& minion) const {return this->cost < minion.cost;}
    bool operator <= (const Minion& minion) const {return this->cost <= minion.cost;}
    bool operator > (const Minion& minion) const {return this->cost <= minion.cost;}
    bool operator >= (const Minion& minion) const {return this->cost >= minion.cost;}
    bool operator == (const Minion& minion) const {return this->cost == minion.cost;}
    Minion operator + (const Minion& minion) const;
    Minion operator - (const Minion& minion) const;
    Minion operator ++() const;
    Minion operator ++(int x) const;
    Minion operator --() const;
    Minion operator --(int x) const;
    operator int() const {return this->cost;}

    istream& read(istream& in);
    ostream& write(ostream& out) const;

    friend istream& operator >> (istream& in, Minion& minion);
    friend ostream& operator << (ostream& out, const Minion& minion);
};

#endif // MINION_H
