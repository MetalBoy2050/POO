#ifndef SPELL_H
#define SPELL_H

#include "Card.h"

class Spell: virtual public Card{
protected:
    int damage;

public:
    Spell();
    Spell(string name, string backgroundFile, string description, CardType cardType, int cost, int damage);
   // Spell(string name, string backgroundFile, string description, int cost, int damage);
   // Spell(string name, string backgroundFile, CardType cardType, int cost, int damage);
    Spell(const Spell& spell);

    bool getDamage() const {return this->damage;}

    void setDamage(int damage){this->damage = damage;}
    void getSpellDamage(int spellDamage) {this->damage += spellDamage;}

    Card& operator = (const Card& card);
    Spell& operator = (const Spell& spell);
    /*bool operator < (const Spell& minion) const {return this->cost < minion.cost;}
    bool operator <= (const Spell& minion) const {return this->cost <= minion.cost;}
    bool operator > (const Spell& minion) const {return this->cost <= minion.cost;}
    bool operator >= (const Spell& minion) const {return this->cost >= minion.cost;}
    bool operator == (const Spell& minion) const {return this->cost == minion.cost;}
    Spell operator + (const Spell& minion) const;
    Spell operator - (const Spell& minion) const;
    Spell& operator ++();
    Spell& operator ++(int x);
    Spell& operator --();
    Spell& operator --(int x);
    operator int() const {return this->cost;}*/

    istream& read(istream& in);
    ostream& write(ostream& out) const;

    ~Spell() { cout << "Destructing spell " << this->cardId; }
};

#endif // MINION_H
