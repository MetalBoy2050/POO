#include <iostream>
#include <cstring>
#include "Deck.h"

using namespace std;

int Deck::contorId = 1000;

Deck::Deck():idDeck(contorId++){
    this->name = new char[strlen("Empty") + 1];
    strcpy(this->name, "Empty");
    this->description = new char[1];
    strcpy(this->description, "");
    this->classType = 0;
    this->nrCards = 0;
    this->listOfCards = NULL;
}

Deck::Deck(char* name, int classType, int nrCards, Card* listOfCards):idDeck(contorId++){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->classType = classType;
    this->nrCards = nrCards;

    for(int i = 0; i < nrCards; i++)
        this->listOfCards[i] = listOfCards[i];
}

Deck::Deck(Card* listOfCards):idDeck(contorId++){
    this->name = new char[strlen("Empty") + 1];
    strcpy(this->name, "Empty");
    this->classType = 0;
    this->nrCards = 30;

    for(int i = 0; i < nrCards; i++)
        this->listOfCards[i] = listOfCards[i];
}

Deck::Deck::Deck(int nrCards, Card* listOfCards):idDeck(contorId++){
    this->name = new char[strlen("Empty") + 1];
    strcpy(this->name, "Empty");
    this->classType = 0;
    this->nrCards = nrCards;

    for(int i = 0; i < nrCards; i++)
        this->listOfCards[i] = listOfCards[i];
}

Deck::Deck(const Deck& newDeck):idDeck(newDeck.idDeck){
    this->name = new char[strlen(newDeck.name)];
    strcpy(this->name, newDeck.name);
    this->description = new char[strlen(newDeck.description)];
    strcpy(this->description, newDeck.description);
    this->classType = newDeck.classType;
    this->nrCards = newDeck.nrCards;

    for(int i = 0; i < this->nrCards; i++)
        this->listOfCards[i] = newDeck.listOfCards[i];
}

char* Deck::getName(){return this->name;}
char* Deck::getDescription(){return this->description;}
int Deck::getClassType(){return this->classType;}
int Deck::getNrCards(){return this->nrCards;}
Card* Deck::getListOfCards(){return this->listOfCards;}

void Deck::setName(char* name){
    if(this->name != NULL)
        delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Deck::setDescription(char* description){
    if(this->description != NULL)
        delete[] this->description;
    this->name = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

Card* Deck::getCardsWithGivenAttack(int attack){
    Card* cardList;

    int cnt = 0;

    for(int i = 0; i < this->nrCards; i++)
        if(this->listOfCards[i].getAttackValue() == attack)
            cnt++;

    cardList = new Card[cnt];
    cnt = 0;

    for(int i = 0; i < this->nrCards; i++)
        if(this->listOfCards[i].getAttackValue() == attack){
            cardList[cnt] = this->listOfCards[i];
            cnt++;
        }

    return cardList;
}

Deck Deck::operator=(const Deck& newDeck){
    if(this != &newDeck){
        if(this->name != NULL)
            delete[] this->name;
        if(this->description != NULL)
            delete[] this->description;
        if(this->nrCards)
            delete[] this->listOfCards;

        this->name = new char[strlen(newDeck.name)];
        strcpy(this->name, newDeck.name);
        this->description = new char[strlen(newDeck.description)];
        strcpy(this->description, newDeck.description);
        this->classType = newDeck.classType;
        this->nrCards = newDeck.nrCards;
        this->listOfCards = new Card[this->nrCards];

        for(int i = 0; i < this->nrCards; i++)
            this->listOfCards[i] = newDeck.listOfCards[i];
    }

    return *this;
}

Card Deck::operator[](int i){
    if(i < 1 || i > this->nrCards){
        cout << "The card doesn't exist!\n";
        return Card();
    }

    return this->listOfCards[i - 1];
}

Deck Deck::operator++(){
    Card* newListOfCards = new Card[this->nrCards + 1];

    for(int i = 0; i < this->nrCards; i++)
        newListOfCards[i] = this->listOfCards[i];

    if(this->nrCards)
        newListOfCards[this->nrCards] = newListOfCards[this->nrCards - 1];
    else
        newListOfCards[0] = Card();

    if(this->listOfCards)
        delete[] this->listOfCards;

    this->listOfCards = newListOfCards;
    this->nrCards++;

    return *this;
}

Deck Deck::operator--(){
    if(this->nrCards){
        Card* newListOfCards = new Card[this->nrCards - 1];

        for(int i = 0; i < this->nrCards - 1; i++)
            newListOfCards[i] = this->listOfCards[i];

        if(this->listOfCards)
            delete[] this->listOfCards;

        this->listOfCards = newListOfCards;
        this->nrCards--;
    }

    return *this;
}

Deck Deck::operator+(const Deck& deck){
    Deck newDeck = *this;
    Card* newListOfCards = new Card[this->nrCards + deck.nrCards];

    for(int i = 0; i < this->nrCards; i++)
        newListOfCards[i] = this->listOfCards[i];
    for(int i = 0; i < deck.nrCards; i++)
        newListOfCards[this->nrCards + i] = deck.listOfCards[i];

    if(deck.listOfCards)
        delete[] deck.listOfCards;

    newDeck.listOfCards = newListOfCards;
    newDeck.nrCards += deck.nrCards;

    return newDeck;
}

Deck Deck::operator-(const Deck& deck){
    Deck newDeck = *this;
    if(deck.nrCards > this->nrCards){
        cout << "The deck substracted is invalid!\n";
        return *this;
    }

    bool verified[this->nrCards];

    for(int i = 0; i < this->nrCards; i++)
        verified[i] = 0;

    for(int i = 0; i < deck.nrCards; i++){
        bool flag = 0;

        for(int j = 0; !flag && j < this->nrCards; j++)
            if(!verified[j] && deck.listOfCards[i] == this->listOfCards[j])
                verified[j] = flag = 1;

        if(!flag){
            cout << "The deck substracted is invalid!\n";
            return *this;
        }
    }

    Card* newListOfCards = new Card[this->nrCards - deck.nrCards];

    for(int i = 0; i < deck.nrCards; i++)
        verified[i] = 0;

    int k = 0;
    for(int i = 0; i < this->nrCards; i++){
        bool flag = 0;

        for(int j = 0; !flag && j < deck.nrCards; j++)
            if(!verified[j] && this->listOfCards[i] == deck.listOfCards[j])
                verified[j] = flag = 1;

        if(!flag){
            newListOfCards[k] = listOfCards[i];
        }
    }

    if(newDeck.listOfCards)
        delete[] deck.listOfCards;

    newDeck.listOfCards = newListOfCards;
    newDeck.nrCards -= deck.nrCards;

    return deck;
}

inline Deck::operator int() const{return this->nrCards;}
inline bool Deck::operator<(const Deck& deck){return this->nrCards < deck.nrCards;}
bool Deck::operator==(const Deck& deck){
    if(this->nrCards != deck.nrCards)
        return false;

    bool verified[this->nrCards];

    for(int i = 0; i < deck.nrCards; i++)
        verified[i] = 0;

    for(int i = 0; i < this->nrCards; i++){
        bool flag = 0;

        for(int j = 0; !flag && j < deck.nrCards; j++)
            if(!verified[j] && this->listOfCards[i] == deck.listOfCards[j])
                flag = verified[j] = 1;

        if(!flag)
            return false;
    }

    return true;
}

Deck operator+(const Card& card, const Deck& deck){
    Deck newDeck = deck;
    if(deck.nrCards < 30){
        if(newDeck.nrCards > 0)
            delete[] newDeck.listOfCards;

        newDeck.nrCards++;
        newDeck.listOfCards = new Card[newDeck.nrCards];

        for(int i = 0; i < deck.nrCards - 1; i++)
            newDeck.listOfCards[i] = deck.listOfCards[i];

        newDeck.listOfCards[newDeck.nrCards - 1] = card;
    }

    return newDeck;
}

Deck operator+(const Deck& deck, const Card& card){
    Deck newDeck = deck;
    if(deck.nrCards < 30){
        if(newDeck.nrCards > 0)
            delete[] newDeck.listOfCards;

        newDeck.nrCards++;
        newDeck.listOfCards = new Card[newDeck.nrCards];

        for(int i = 0; i < deck.nrCards - 1; i++)
            newDeck.listOfCards[i] = deck.listOfCards[i];

        newDeck.listOfCards[newDeck.nrCards - 1] = card;
    }

    return newDeck;
}

istream& operator>>(istream& in, Deck& newDeck){
    cout << "Name: ";

    if(newDeck.name != NULL)
        delete[] newDeck.name;

    char name[200];

    in >> name;

    newDeck.name = new char[strlen(name) + 1];
    strcpy(newDeck.name, name);

    cout << "Description: ";

    if(newDeck.description != NULL)
        delete[] newDeck.description;

    char description[200];

    in.ignore();
    in.getline(description, 201);

    newDeck.description = new char[strlen(description) + 1];
    strcpy(newDeck.description, description);

    cout << "Number of cards: ";
    in >> newDeck.nrCards;

    if(newDeck.listOfCards != NULL)
        delete[] newDeck.listOfCards;

    newDeck.listOfCards = new Card[newDeck.nrCards];
    cout << "Cards: \n";

    for(int i = 0; i < newDeck.nrCards; i++)
        in >> newDeck.listOfCards[i];

    return in;
}

ostream& operator<<(ostream& out, const Deck& newDeck){
    out << "Name: " << newDeck.name << '\n';
    out << "Description: " << newDeck.description << '\n';
    out << "Cards: \n";

    for(int i = 0; i < newDeck.nrCards; i++)
        out << newDeck.listOfCards[i] << "\n";

    return out;
}


Deck::~Deck(){
    if(this->name != NULL)
        delete[] this->name;
    if(this->description != NULL)
        delete[] this->description;
}
