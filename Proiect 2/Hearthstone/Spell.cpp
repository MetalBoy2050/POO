#include "Minion.h"
#include "Spell.h"

Spell::Spell():Card(), damage(1){}

Spell::Spell(string name, string backgroundFile, string description, CardType cardType, int cost, int damage):
    Card(name, backgroundFile, description, cardType, cost), damage(damage){}

/*Spell::Spell(string name, string backgroundFile, string description, int cost, int damage):
    Card(name, backgroundFile, description, cost), damage(damage){}

Spell::Spell(string name, string backgroundFile, CardType cardType, int cost, int damage):
    Card(name, backgroundFile, cardType, cost), damage(damage){}*/

Spell::Spell(const Spell& spell):Card(spell), damage(spell.damage){}

istream& Spell::read(istream& in){
    cout << "Introduceti datele Spell-ului " << this->cardId << '\n';
    Card::read(in);
    cout << "Damage-ul: ";
    in >> this->damage;

    return in;
}

ostream& Spell::write(ostream& out) const {
    out << "Spell-ul cu numarul " << this->cardId << " este urmatorul\n";
    Card::write(out);
    out << "Damage: " << this->damage << '\n';

    return out;
}

Card& Spell::operator = (const Card& card){
    if(this != &card){
        Card::operator=(card);

        if(dynamic_cast<Spell*>(const_cast<Card*>(&card)))
            this->damage = dynamic_cast<Spell*>(const_cast<Card*>(&card))->damage;
    }

    return *this;
}

Spell& Spell::operator = (const Spell& spell){
    if(this != &spell){
        Card::operator=(spell);
        this->damage = spell.damage;
    }

    return *this;
};

/*Spell Spell::operator + (const Spell& card) const{
    Spell newSpell(*this);

    newSpell.damage += card.damage;

    return newSpell;
}

Spell Spell::operator - (const Spell& card) const{
    Spell newSpell(*this);

    newSpell.damage -= card.damage;

    return newSpell;
};

Spell& Spell::operator ++(){
    this->damage++;

    return *this;
};

Spell& Spell::operator ++(int x){
    this->damage += x;

    return *this;
};

Spell& Spell::operator --(){
    this->damage--;

    return *this;
};

Spell& Spell::operator --(int x){
    this->damage -= x;

    return *this;
};*/
