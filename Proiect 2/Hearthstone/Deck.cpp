#include "Deck.h"

int Deck::deckCounter = 1000;

Deck::Deck():deckId(deckCounter++), name("Empty"), description(""), heroType(Mage), cards(){}
Deck::Deck(string name, string description, HeroType heroType, vector<Card*> cards):
    deckId(deckCounter++), name(name), description(description), heroType(heroType), cards(cards){}
Deck::Deck(const Deck& deck):deckId(deck.deckId), name(deck.name), description(deck.description), heroType(deck.heroType),
cards(deck.cards){}

Deck& Deck::operator =(const Deck& deck){
    if(this != &deck){
        this->name = deck.name;
        this->description = deck.description;
        this->heroType = deck.heroType;
        this->cards = deck.cards;
    }

    return *this;
}


istream& operator >> (istream& in, Deck& deck){
    cout << "Introduceti deck-ul cu numarul " << deck.deckId << '\n';
    cout << "Nume: ";
    cin >> deck.name;
    cout << "Descriere: ";
    cin >> deck.description;
    cout << "HeroType (0: Mage, 1: Warrior, 2: Warlock, 3: Priest, 4: Shaman, 5: Paladin, 6: Hunter, 7: DemonHunter, 8: Rogue, 9: Druid: ";

    int heroTypeId;
    cin >> heroTypeId;

    switch(heroTypeId){
    case 0:
        deck.heroType = Mage;
        break;
    case 1:
        deck.heroType = Warrior;
        break;
    case 2:
        deck.heroType = Warlock;
        break;
    case 3:
        deck.heroType = Priest;
        break;
    case 4:
        deck.heroType = Shaman;
        break;
    case 5:
        deck.heroType = Paladin;
        break;
    case 6:
        deck.heroType = Hunter;
        break;
    case 7:
        deck.heroType = DemonHunter;
        break;
    case 8:
        deck.heroType = Rogue;
        break;
    case 9:
        deck.heroType = Druid;
        break;
    default:
        deck.heroType = Mage;
        break;
    }

    return in;
}

ostream& operator << (ostream& out, const Deck& deck){
    out << "Deck-ul cu numarul " << deck.deckId << " este urmatorul\n";
    out << "Nume: " << deck.name << '\n';
    out << "Descriere: " << deck.description << '\n';
    out << "HeroType: " << deck.heroType << '\n';
    out << "Cards: " << '\n';

    for(card : deck.cards)
        out << card << '\n';

    return out;
}

void Deck::pushCard(const Card* card){
    this->cards.push_back(const_cast<Card*>(card));
}

int Deck::getDeckValue() const{
    int sum = 0;
    for(const Card* x : this->cards)
        if(dynamic_cast<Minion*>(const_cast<Card*>(x)))
            sum += dynamic_cast<Minion*>(const_cast<Card*>(x))->getValue();

    return sum;
}
