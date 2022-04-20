#include "Minion.h"
#include "Spell.h"

Spell::Spell():Card(), damage(1){}

Spell::Spell(string name, string backgroundFile, string description, CardType cardType, int cost, int damage):
    Card(name, backgroundFile, description, cardType, cost), damage(damage){}

Spell::Spell(string name, string backgroundFile, string description, int cost, int damage):
    Card(name, backgroundFile, description, cost), damage(damage){}

Spell::Spell(string name, string backgroundFile, CardType cardType, int cost, int damage):
    Card(name, backgroundFile, cardType, cost), damage(damage){}

Spell::Spell(const Spell& spell):Card(spell), damage(spell.damage){}

istream& Spell::read(istream& in){
    cout << "Introduceti datele Spell-ului " << Spell::nrCards << '\n';
    cout << "Numele: ";
    in >> this->name;
    cout << "Background file-ul: ";
    in >> this->backgroundFile;
    cout << "Descrierea: ";
    in >> this->description;
    cout << "Card type-ul: ";

    int auxCardType;
    in >> auxCardType;
    switch(auxCardType){
    case 0:
        this->cardType = Common;
        break;
    case 1:
        this->cardType = Rare;
        break;
    case 2:
        this->cardType = Epic;
        break;
    case 3:
        this->cardType = Legendary;
        break;
    case 4:
        this->cardType = OnceInALifetime;
        break;
    default:
        this->cardType = Common;
        break;
    }

    cout << "Cost-ul: ";
    in >> this->cost;
    cout << "Damage-ul: ";
    in >> this->damage;

    return in;
}

ostream& Spell::write(ostream& out) const {
    out << "Spellul cu numarul " << this->cardId << " este urmatorul\n";
    out << "Numele: " << this->name << '\n';
    out << "Background file-ul: " << this->backgroundFile << '\n';
    out << "Card type-ul: " << this->cardType << '\n';
    out << "Descrierea: " << this->description << '\n';
    out << "Cost: " << this->cost << '\n';
    out << "Damage: " << this->damage << '\n';

    return out;
}

istream& operator >> (istream& in, Spell& minion){
    return minion.read(in);
}
ostream& operator << (ostream& out, const Spell& minion){
    return minion.write(out);
}

Card& Spell::operator = (const Card& card){
    if(this != &card){
        Card::operator=(card);
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

Spell Spell::operator + (const Spell& card) const{
    Spell newSpell(*this);

    newSpell.damage += card.damage;

    return newSpell;
}

Spell Spell::operator - (const Spell& card) const{
    Spell newSpell(*this);

    newSpell.damage -= card.damage;

    return newSpell;
};

Spell Spell::operator ++() const {
    Spell newSpell(*this);

    newSpell.damage++;

    return newSpell;
};

Spell Spell::operator ++(int x) const {
    Spell newSpell(*this);

    newSpell.damage += x;

    return newSpell;
};

Spell Spell::operator --() const {
    Spell newSpell(*this);

    newSpell.damage--;

    return newSpell;
};

Spell Spell::operator --(int x) const {
    Spell newSpell(*this);

    newSpell.damage -= x;

    return newSpell;
};

