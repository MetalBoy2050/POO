#include "Card.h"

#ifndef SPELL_H
#define SPELL_H

class Spell: virtual public Card{
protected:
    int damage;

public:
    Spell();
    Spell(string name, string backgroundFile, string description, CardType cardType, int cost, int damage);
    Spell(string name, string backgroundFile, string description, int cost, int damage);
    Spell(string name, string backgroundFile, CardType cardType, int cost, int damage);
    Spell(const Spell& spell);

    bool getDamage() const {return this->damage;}

    void setDamage(int damage){this->damage = damage;}

    Card& operator = (const Card& card);
    Spell& operator = (const Spell& spell);
    bool operator < (const Spell& minion) const {return this->cost < minion.cost;}
    bool operator <= (const Spell& minion) const {return this->cost <= minion.cost;}
    bool operator > (const Spell& minion) const {return this->cost <= minion.cost;}
    bool operator >= (const Spell& minion) const {return this->cost >= minion.cost;}
    bool operator == (const Spell& minion) const {return this->cost == minion.cost;}
    Spell operator + (const Spell& minion) const;
    Spell operator - (const Spell& minion) const;
    Spell operator ++() const;
    Spell operator ++(int x) const;
    Spell operator --() const;
    Spell operator --(int x) const;
    operator int() const {return this->cost;}

    istream& read(istream& in);
    ostream& write(ostream& out) const;

    friend istream& operator >> (istream& in, Spell& minion);
    friend ostream& operator << (ostream& out, const Spell& minion);
};

#endif // MINION_H
