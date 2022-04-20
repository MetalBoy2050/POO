#include <iostream>
#include <cstring>
#include "Card.h"

using namespace std;

#ifndef DECK_H
#define DECK_H

class Deck{
private:
    char* name, *description;
    int classType; //0 -> None, 1 -> Hunter, 2 -> Warrior, 3 -> Priest, 4 -> Mage, 5 -> Warlock, 6 -> Rogue
    int nrCards; //a deck has 30 cards;
    Card* listOfCards;

    const int idDeck;
    static int contorId;
public:
    Deck();
    Deck(char* name, int classType, int nrCards, Card* listOfCards);
    Deck(Card* listOfCards);
    Deck(int nrCards, Card* listOfCards);
    Deck(const Deck& newDeck);

    char* getName();
    char* getDescription();
    int getClassType();
    int getNrCards();
    Card* getListOfCards();

    void setName(char* name);
    void setDescription(char* description);

    Card* getCardsWithGivenAttack(int attack);

    Deck operator=(const Deck& newDeck);
    Card operator[](int i);
    Deck operator++();
    Deck operator--();
    Deck operator+(const Deck& deck);
    Deck operator-(const Deck& deck);
    operator int() const;
    bool operator<(const Deck& deck);
    bool operator==(const Deck& deck);
    friend Deck operator+(const Card& card, const Deck& deck);
    friend Deck operator+(const Deck& deck, const Card& card);
    friend istream& operator>>(istream& in, Deck& newDeck);
    friend ostream& operator<<(ostream& out, const Deck& newDeck);

    ~Deck();
};

#endif // DECK_H
