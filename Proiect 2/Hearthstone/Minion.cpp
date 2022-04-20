#include "Minion.h"

Minion::Minion():Card(), attack(0), health(0){}

Minion::Minion(string name, string backgroundFile, string description, CardType cardType, int cost, int attack, int health):
    Card(name, backgroundFile, description, cardType, cost), attack(attack), health(health){}

Minion::Minion(string name, string backgroundFile, string description, int cost, int attack, int health):
    Card(name, backgroundFile, description, cost), attack(attack), health(health){}

Minion::Minion(string name, string backgroundFile, CardType cardType, int cost, int attack, int health):
    Card(name, backgroundFile, cardType, cost), attack(attack), health(health){}

Minion::Minion(const Minion& minion):Card(minion), attack(minion.attack), health(minion.health){}

istream& Minion::read(istream& in){
    cout << "Introduceti datele Spell-ului " << Minion::nrCards << '\n';
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
    cout << "Attack-ul: ";
    in >> this->attack;
    cout << "Health-ul: ";
    in >> this->health;

    return in;
}

ostream& Minion::write(ostream& out) const {
    out << "Minionul cu numarul " << this->cardId << " este urmatorul\n";
    out << "Numele: " << this->name << '\n';
    out << "Background file-ul: " << this->backgroundFile << '\n';
    out << "Card type-ul: " << this->cardType << '\n';
    out << "Descrierea: " << this->description << '\n';
    out << "Cost: " << this->cost << '\n';
    out << "Attack: " << this->attack << '\n';
    out << "Health: " << this->health << '\n';

    return out;
}

istream& operator >> (istream& in, Minion& minion){
    return minion.read(in);
}
ostream& operator << (ostream& out, const Minion& minion){
    return minion.write(out);
}

Card& Minion::operator = (const Card& card){
    if(this != &card){
        Card::operator=(card);

        this->attack = dynamic_cast<Minion*>(const_cast<Card*>(&card))->attack;
        this->health = dynamic_cast<Minion*>(const_cast<Card*>(&card))->health;
    }

    return *this;
}

Minion& Minion::operator = (const Minion& minion){
    if(this != &minion){
        Card::operator=(const_cast<Minion&>(minion));

        this->attack = minion.attack;
        this->health = minion.health;
    }

    return *this;
};

Minion Minion::operator + (const Minion& card) const{
    Minion newMinion(*this);

    newMinion.attack += card.attack;
    newMinion.health += card.health;

    return newMinion;
}
Minion Minion::operator - (const Minion& card) const{
    Minion newMinion(*this);

    newMinion.attack -= card.attack;
    newMinion.health -= card.health;

    return newMinion;
};

Minion Minion::operator ++() const {
    Minion newMinion(*this);

    newMinion.attack++;
    newMinion.health++;

    return newMinion;
};

Minion Minion::operator ++(int x) const {
    Minion newMinion(*this);

    newMinion.attack += x;
    newMinion.health += x;

    return newMinion;
};

Minion Minion::operator --() const {
    Minion newMinion(*this);

    newMinion.attack--;
    newMinion.health--;

    return newMinion;
};

Minion Minion::operator --(int x) const {
    Minion newMinion(*this);

    newMinion.attack -= x;
    newMinion.health -= x;

    return newMinion;
};
