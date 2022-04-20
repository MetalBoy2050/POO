#include <iostream>

using namespace std;

#ifndef CARD_H
#define CARD_H

class Deck;

class Card{
private:
    char* name, *imageFile, *description;
    char archetype; //0 -> default, 1 -> common, 2 -> rare, 3 -> epic, 4 -> legendary
    int classType; //0 -> None, 1 -> Hunter, 2 -> Warrior, 3 -> Priest, 4 -> Mage, 5 -> Warlock, 6 -> Rogue
    int attackValue, healthValue, nrKeyWords;
    int* keyWords; /*
    0 -> stealth, 1 -> battlecry, 2 - >deathrattle,
    3 -> taunt, 4 -> rush, 5 -> charge, 6 -> silence
    */
    static int contorId;
    const int idCard;

public:
    Card();
    Card(char* name, char* description, char* imageFile, char archetype, int classType,
         int attackValue, int healthValue, int nrKeyWords, int* keyWords);
    Card(char* name, char* description, char* imageFile, char archetype,
         int attackValue, int healthValue, int nrKeyWords, int* keyWords);
    Card(char* name, char* description, char* imageFile, char archetype, int classType,
          int nrKeyWords, int* keyWords);
    Card(const Card& newCard);

    char* getName();
    char* getImageFile();
    char* getDescription();
    int getArchetype();
    int getClassType();
    int getAttackValue();
    int getHealthValue();
    int* getKeyWords();

    void setName(char *name);
    void setImageFile(char *imageFile);
    void setDescription(char *description);
    void setArchetype(char archetype);
    void setClassType(int classType);
    void setAttackValue(int attackValue);
    void setHealthValue(int healthValue);
    void setKeyWords(int nrKeyWords, int* keyWords);

    void attackAnotherCard(Card card);

    Card operator= (const Card& newCard);
    int operator[](int i);
    Card operator++();
    Card operator++(int i);
    Card operator--();
    Card operator+(const Card& card);
    Card operator-(const Card& card);
    operator int() const;
    bool operator<(const Card& card);
    bool operator==(const Card& card);

    //friend Deck operator+(const Card& card, const Deck& deck);
    //friend Deck operator+(const Deck& deck, const Card& card);
    friend istream& operator>>(istream& in, Card& inputCard);
    friend ostream& operator<<(ostream& out, const Card& outputCard);

    ~Card();
};

#endif
