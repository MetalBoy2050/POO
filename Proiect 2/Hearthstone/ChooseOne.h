#include "Card.h"

#ifndef CHOOSE_ONE_H
#define CHOOSE_ONE_H

class ChooseOne: public Minion, public Spell{
protected:
    bool choice;

public:
    ChooseOne();
    ChooseOne(string name, string backgroundFile, string description, CardType cardType, int cost, int attack, int health, int damage, bool choice);
    ChooseOne(string name, string backgroundFile, string description, int cost, int attack, int health, int damage, bool choice);
    ChooseOne(string name, string backgroundFile, CardType cardType, int cost, int attack, int health, int damage, bool choice);

    ChooseOne operator = (const ChooseOne& minion) const ;
    bool operator < (const ChooseOne& minion) const {return this->cost < minion.cost;}
    bool operator <= (const ChooseOne& minion) const {return this->cost <= minion.cost;}
    bool operator > (const ChooseOne& minion) const {return this->cost <= minion.cost;}
    bool operator >= (const ChooseOne& minion) const {return this->cost >= minion.cost;}
    bool operator == (const ChooseOne& minion) const {return this->cost == minion.cost;}
    ChooseOne operator + (const ChooseOne& minion) const;
    ChooseOne operator - (const ChooseOne& minion) const;
    ChooseOne operator ++() const;
    ChooseOne operator ++(int x) const;
    ChooseOne operator --() const;
    ChooseOne operator --(int x) const;
    operator int() const {return this->cost;}

    istream& read(istream& in);
    ostream& write(ostream& out) const;

    friend istream& operator >> (istream& in, ChooseOne& minion);
    friend ostream& operator << (ostream& out, const ChooseOne& minion);
};

#endif // MINION_H
