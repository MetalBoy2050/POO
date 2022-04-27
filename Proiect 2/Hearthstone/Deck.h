#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "Minion.h"

enum HeroType{
    Mage, Warrior, Warlock, Priest, Shaman, Paladin, Hunter, DemonHunter, Rogue, Druid
};

class Deck{
private:
    string name;
    string description;
    HeroType heroType;
    vector<Card*> cards;

    static int deckCounter;
    const int deckId;

public:
    Deck();
    Deck(string name, string description, HeroType heroType, vector<Card*> cards);
    Deck(const Deck& deck);

    Deck& operator =(const Deck& deck);

    int getDeckId() const {return this->deckId;}
    vector<Card*>& getCards() {return this->cards;}
    void pushCard(const Card* card);
    int getDeckValue() const;

    friend istream& operator >> (istream& in, Deck& deck);
    friend ostream& operator << (ostream& out, const Deck& deck);
    ~Deck(){ cout << "Destructing the deck: " << this->deckId;}
};

#endif
