#ifndef CHOOSE_ONE_H
#define CHOOSE_ONE_H

#include "Minion.h"
#include "Spell.h"

class ChooseOne: public Minion, public Spell{
    bool choice;

public:
    ChooseOne();
    ChooseOne(string name, string backgroundFile, string description, CardType cardType, int cost, int attack, int health, int damage, bool choice);
   // ChooseOne(string name, string backgroundFile, string description, int cost, int attack, int health, int damage, bool choice);
    //ChooseOne(string name, string backgroundFile, CardType cardType, int cost, int attack, int health, int damage, bool choice);
    ChooseOne(const ChooseOne& chooseOne);

    bool getChoice(){ return this->choice; }

    void inversareChoice(){ this->choice = !this->choice; }

    Card& operator = (const Card& card);
    ChooseOne& operator = (const ChooseOne& minion);
    /*bool operator < (const ChooseOne& minion) const {return this->cost < minion.cost;}
    bool operator <= (const ChooseOne& minion) const {return this->cost <= minion.cost;}
    bool operator > (const ChooseOne& minion) const {return this->cost <= minion.cost;}
    bool operator >= (const ChooseOne& minion) const {return this->cost >= minion.cost;}
    bool operator == (const ChooseOne& minion) const {return this->cost == minion.cost;}
    ChooseOne operator + (const ChooseOne& minion) const;
    ChooseOne operator - (const ChooseOne& minion) const;
    ChooseOne& operator ++();
    ChooseOne& operator ++(int x);
    ChooseOne& operator --();
    ChooseOne& operator --(int x);
    operator int() const {return this->cost;}*/

    istream& read(istream& in);
    ostream& write(ostream& out) const;

    friend istream& operator >> (istream& in, ChooseOne& minion);
    friend ostream& operator << (ostream& out, const ChooseOne& minion);

    ~ChooseOne() { cout << "Destructing the Choose one card " << this->cardId; }
};

#endif // MINION_H
