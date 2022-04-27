#ifndef MINION_H
#define MINION_H

#include "Card.h"

class Minion: virtual public Card{
protected:
    int attack;
    int health;

public:
    Minion();
    Minion(string name, string backgroundFile, string description, CardType cardType, int cost, int attack, int health);
  //  Minion(string name, string backgroundFile, string description, int cost, int attack, int health);
  //  Minion(string name, string backgroundFile, CardType cardType, int cost, int attack, int health);
    Minion(const Minion& minion);

    int getAttack() const {return this->attack;}
    int getHealth() const {return this->health;}
    int getValue() const {return this->attack + this->health - this->cost;}

    void setAttack(int attack){this->attack = attack;}
    void setHealth(int health){this->health = health;}

    Card& operator = (const Card& card);
    Minion& operator = (const Minion& minion);
    /*bool operator < (const Minion& minion) const {return this->cost < minion.cost;}
    bool operator <= (const Minion& minion) const {return this->cost <= minion.cost;}
    bool operator > (const Minion& minion) const {return this->cost <= minion.cost;}
    bool operator >= (const Minion& minion) const {return this->cost >= minion.cost;}
    bool operator == (const Minion& minion) const {return this->cost == minion.cost;}
    Minion operator + (const Minion& minion) const;
    Minion operator - (const Minion& minion) const;
    Minion& operator ++();
    Minion& operator ++(int x);
    Minion& operator --();
    Minion& operator --(int x);
    operator int() const {return this->cost;}*/

    istream& read(istream& in);
    ostream& write(ostream& out) const;

    ~Minion() { cout << "Destructing minion " << this->cardId; }
};

#endif // MINION_H
