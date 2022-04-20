#include <bits/stdc++.h>
#include "Card.h"

using namespace std;

int Card::nrCards = 1000;

Card::Card():
    cardId(nrCards++),name("Empty"), backgroundFile(""), description(""), cardType(Common), cost(0){}

Card::Card(string name, string backgroundFile, string description, CardType cardType, int cost):
    cardId(nrCards++),name(name), backgroundFile(backgroundFile), description(description), cardType(cardType), cost(cost){}

Card::Card(string name, string backgroundFile, CardType cardType, int cost):
    cardId(nrCards++),name(name), backgroundFile(backgroundFile), description(""), cardType(cardType), cost(cost){}

Card::Card(string name, string backgroundFile, string description, int cost):
    cardId(nrCards++),name(name), backgroundFile(backgroundFile), description(description), cardType(Common), cost(cost){}

Card::Card(string name, string backGroundFile, string description, CardType cardType):
    cardId(nrCards++),name(name), backgroundFile(backgroundFile), description(description), cardType(cardType), cost(0){}

Card::Card(const Card& card):
    cardId(card.cardId), name(card.name), backgroundFile(card.backgroundFile), description(card.description), cardType(card.cardType), cost(card.cost){}

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
