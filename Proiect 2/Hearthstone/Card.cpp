#include "Card.h"

using namespace std;

int Card::nrCards = 1000;

Card::Card():
    cardId(nrCards++),name("Empty"), backgroundFile(""), description(""), cardType(Common), cost(0){}

Card::Card(string name, string backgroundFile, string description, CardType cardType, int cost):
    cardId(nrCards++),name(name), backgroundFile(backgroundFile), description(description), cardType(cardType), cost(cost){}

/*Card::Card(string name, string backgroundFile, CardType cardType, int cost):
    cardId(nrCards++),name(name), backgroundFile(backgroundFile), description(""), cardType(cardType), cost(cost){}

Card::Card(string name, string backgroundFile, string description, int cost):
    cardId(nrCards++),name(name), backgroundFile(backgroundFile), description(description), cardType(Common), cost(cost){}

Card::Card(string name, string backGroundFile, string description, CardType cardType):
    cardId(nrCards++),name(name), backgroundFile(backgroundFile), description(description), cardType(cardType), cost(0){}*/

Card::Card(const Card& card):
    cardId(card.cardId), name(card.name), backgroundFile(card.backgroundFile), description(card.description), cardType(card.cardType), cost(card.cost){}

istream& Card::read(istream& in){
    cout << "Numele: ";
    in >> this->name;
    cout << "Background file-ul: ";
    in >> this->backgroundFile;
    cout << "Descrierea: ";
    in >> this->description;
    cout << "Card type-ul (0 -> Common, 1 -> Rare, 2 -> Epic, 3 -> Legendary, 4 -> OnceInALifetime): ";

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

    return in;
}

ostream& Card::write(ostream& out) const {
    out << "Numele: " << this->name << '\n';
    out << "Background file-ul: " << this->backgroundFile << '\n';
    out << "Card type-ul: " << this->cardType << '\n';
    out << "Descrierea: " << this->description << '\n';
    out << "Cost: " << this->cost << '\n';

    return out;
}

istream& operator >> (istream& in, Card& card){
    return card.read(in);
}

ostream& operator << (ostream& out, const Card& card){
    return card.write(out);
}

Card& Card::operator = (const Card& card){
    if(this != &card){
        this->name = card.name;
        this->backgroundFile = card.backgroundFile;
        this->description = card.description;
        this->cardType = card.cardType;
        this->cost = card.cost;
    }

    return *this;
}
