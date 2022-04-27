#include "Minion.h"

Minion::Minion():Card(), attack(0), health(0){}

Minion::Minion(string name, string backgroundFile, string description, CardType cardType, int cost, int attack, int health):
    Card(name, backgroundFile, description, cardType, cost), attack(attack), health(health){}

/*Minion::Minion(string name, string backgroundFile, string description, int cost, int attack, int health):
    Card(name, backgroundFile, description, cost), attack(attack), health(health){}

Minion::Minion(string name, string backgroundFile, CardType cardType, int cost, int attack, int health):
    Card(name, backgroundFile, cardType, cost), attack(attack), health(health){}*/

Minion::Minion(const Minion& minion):Card(minion), attack(minion.attack), health(minion.health){}

istream& Minion::read(istream& in){
    cout << "Introduceti datele Minion-ului " << this->cardId << '\n';
    Card::read(in);
    cout << "Attack-ul: ";
    in >> this->attack;
    cout << "Health-ul: ";
    in >> this->health;

    return in;
}

ostream& Minion::write(ostream& out) const {
    out << "Minion-ul cu numarul " << this->cardId << " este urmatorul\n";
    Card::write(out);
    cout << "Attack-ul: " << this->attack << '\n';
    cout << "Health-ul: " << this->health << '\n';

    return out;
}

Card& Minion::operator = (const Card& card){
    if(this != &card){
        Card::operator=(card);

        if(dynamic_cast<Minion*>(const_cast<Card*>(&card))){
            this->attack = dynamic_cast<Minion*>(const_cast<Card*>(&card))->attack;
            this->health = dynamic_cast<Minion*>(const_cast<Card*>(&card))->health;
        }
    }

    return *this;
}

Minion& Minion::operator = (const Minion& minion){
    if(this != &minion){
        Card::operator=(minion);

        this->attack = minion.attack;
        this->health = minion.health;
    }

    return *this;
};

/*Minion Minion::operator + (const Minion& card) const{
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

Minion& Minion::operator ++(){
    this->attack++;
    this->health++;

    return *this;
};

Minion& Minion::operator ++(int x){
    this->attack += x;
    this->health += x;

    return *this;
};

Minion& Minion::operator --(){
    this->attack--;
    this->health--;

    return *this;
};

Minion& Minion::operator --(int x){
    this->attack -= x;
    this->health -= x;

    return *this;
};*/
