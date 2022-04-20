#include <bits/stdc++.h>

#ifndef CARD_H
#define CARD_H

using namespace std;

enum CardType{
    Common,
    Rare,
    Epic,
    Legendary,
    OnceInALifetime
};

class Card{
protected:
    string name;
    string backgroundFile;
    string description;
    CardType cardType;
    int cost;
    static int nrCards;
    const int cardId;

public:
    Card();
    Card(string name, string backgroundFile, string description, CardType cardType, int cost);
    Card(string name, string backgroundFile, CardType cardType, int cost);
    Card(string name, string backgroundFile, string description, int cost);
    Card(string name, string backGroundFile, string description, CardType cardType);
    Card(const Card& card);

    static int getNrCards(){return nrCards;}
    int getCardId() const {return this->cardId;}
    string getName() const {return this->name;}
    string getBackgroundFile() const {return this->backgroundFile;}
    string getDescription() const {return this->description;}
    CardType getCardType() const {return this->cardType;}
    int getCost() const {return this->cost;}

    void setName(string name){this->name = name;}
    void setBackgroundFile(string backgroundFile){this->backgroundFile = backgroundFile;}
    void setDescription(string description){this->description = description;}
    void setCardType(CardType cardType){this->cardType = cardType;}
    void setCost(int cost){this->cost = cost;}

    virtual Card& operator = (const Card& card);
    bool operator < (const Card& card) const {return this->cost < card.cost;}
    bool operator <= (const Card& card) const {return this->cost <= card.cost;}
    bool operator > (const Card& card) const {return this->cost > card.cost;}
    bool operator >= (const Card& card) const {return this->cost >= card.cost;}
    bool operator == (const Card& card) const {return this->cost == card.cost;}
    operator int() const {return this->cost;}

    virtual istream& read(istream& in) = 0;
    virtual ostream& write(ostream& out) const = 0;
};

#endif // CARD_H
