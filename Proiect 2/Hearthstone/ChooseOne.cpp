#include "ChooseOne.h"


ChooseOne::ChooseOne():Card(), Minion(), Spell(), choice(0){}

ChooseOne::ChooseOne(string name, string backgroundFile, string description, CardType cardType, int cost, int attack, int health, int damage, bool choice):
    Card(name, backgroundFile, description, cardType, cost), Minion(name, backgroundFile, description, cardType, cost, attack, health),
    Spell(name, backgroundFile, description, cardType, cost, damage), choice(choice){}

/*ChooseOne::ChooseOne(string name, string backgroundFile, string description, int cost, int attack, int health, int damage, bool choice):
    Card(name, backgroundFile, cardType, cost), Minion(name, backgroundFile, cardType, cost, attack, health),
    Spell(name, backgroundFile, cardType, cost, damage), choice(choice){}

ChooseOne::ChooseOne(string name, string backgroundFile, CardType cardType, int cost, int attack, int health, int damage, bool choice):
    Card(name, description, cardType, cost), Minion(name, description, cardType, cost, attack, health),
    Spell(name, description, cardType, cost, damage), choice(choice){}*/

ChooseOne::ChooseOne(const ChooseOne& chooseOne):Card(chooseOne), Minion(chooseOne), Spell(chooseOne){}


Card& ChooseOne::operator = (const Card& card){
    if(this != &card){
        if(dynamic_cast<ChooseOne*>(const_cast<Card*>(&card))){
            Minion::operator=(card);
            this->damage = dynamic_cast<ChooseOne*>(const_cast<Card*>(&card))->damage;
            this->choice = dynamic_cast<ChooseOne*>(const_cast<Card*>(&card))->choice;
        }else{
            if(dynamic_cast<Minion*>(const_cast<Card*>(&card)))
                Minion::operator=(card);
            else
                if(dynamic_cast<Spell*>(const_cast<Card*>(&card)))
                    Spell::operator=(card);
                else
                    Card::operator=(card);
        }
    }

    return *this;
}

ChooseOne& ChooseOne::operator = (const ChooseOne& chooseOne){
    if(this != &chooseOne){
        Minion::operator=(chooseOne);
        this->damage = chooseOne.damage;
        this->choice = chooseOne.choice;
    }

    return *this;
}

/*ChooseOne ChooseOne::operator + (const ChooseOne& chooseOne) const{
    ChooseOne newChooseOne(*this);

    newChooseOne.attack += chooseOne.attack;
    newChooseOne.health += chooseOne.health;
    newChooseOne.damage += chooseOne.damage;

    return newChooseOne;
};

ChooseOne ChooseOne::operator - (const ChooseOne& chooseOne) const{
    ChooseOne newChooseOne(*this);

    newChooseOne.attack -= chooseOne.attack;
    newChooseOne.health -= chooseOne.health;
    newChooseOne.damage -= chooseOne.damage;

    return newChooseOne;
}


ChooseOne& ChooseOne::operator ++(){
    this->attack++;
    this->health++;
    this->damage++;

    return *this;
};

ChooseOne& ChooseOne::operator ++(int x){
    this->attack += x;
    this->health += x;
    this->damage += x;

    return *this;
};

ChooseOne& ChooseOne::operator --(){
    this->attack--;
    this->health--;
    this->damage--;

    return *this;
};

ChooseOne& ChooseOne::operator --(int x){
    this->attack -= x;
    this->health -= x;
    this->damage -= x;

    return *this;
}*/

istream& ChooseOne::read(istream& in){
    cout << "Introduceti datele Choose one card-ului " << this->cardId << '\n';
    Card::read(in);

    cout << "Attack-ul: ";
    in >> this->attack;
    cout << "Health-ul: ";
    in >> this->health;
    cout << "Damage-ul: ";
    in >> this->damage;
    cout << "Choice-ul(0 -> Minion, 1 -> Spell): ";
    in >> this->choice;

    return in;
}

ostream& ChooseOne::write(ostream& out) const{
    out << "Choose one card-ul cu numarul " << this->cardId << " este urmatorul\n";
    Card::write(out);

    cout << "Attack-ul: " << this->attack << '\n';
    cout << "Health-ul: " << this->health << '\n';
    cout << "Damage-ul: " << this->damage << '\n';
    cout << "Choice-ul(0 -> Minion, 1 -> Spell): " << this->choice << '\n';

    return out;
}

istream& operator >> (istream& in, ChooseOne& chooseOne){
    cout << "Introduceti datele ChooseOne card-ului: " << chooseOne.cardId << '\n';
    return chooseOne.read(in);
}

ostream& operator << (ostream& out, const ChooseOne& chooseOne){
    cout << "ChooseOne card-ul cu numarul " << chooseOne.cardId << " este urmatorul\n";
    chooseOne.write(out);

    return out;
}
