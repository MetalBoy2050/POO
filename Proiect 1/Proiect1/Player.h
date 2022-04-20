#include <iostream>
#include <cstring>
#include "Deck.h"

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player{
private:
    char* name, *description;
    int age;
    bool gender; //0-boy, 1-girl
    float height;
    int nrFriends;
    char** listOfFriends, *profileImageFile;
    int nrDecks;
    Deck* listOfDecks;

    const int idPlayer;
    static int contorId;

public:
    Player();  // Default Constructor
    Player(char* name, char* description, int nrFriends, char** listOfFriends, char* profileImageFile,
           int age, bool gender, float height, int nrDecks, Deck* listOfDecks);  // Full Constrcutor
    Player(char* name, char* description, int nrFriends, char** listOfFriends, char* profileImageFile,
           int age, float height, int nrDecks, Deck* listOfDecks);  // Constructor 1
    Player(char* name, int nrFriends, char** listOfFriends, char* profileImageFile,
           int age, float height, int nrDecks, Deck* listOfDecks); // Constructor 2
    Player(const Player& newPlayer); // Copy Constructor

    char* getPlayerName();
    char* getPlayerDescription();
    char** getListOfFriends();
    Deck* getListOfDecks();

    void setPlayerName(char* name);
    void setPlayerDescription(char* description);
    void addFriend(char* newFriend);
    void removeFriend(char* oldFriend);

    void showCompleteDecks();

    Deck operator[](int i);
    Player operator++();
    Player operator++(int i);
    Player operator--();
    Player operator+(const Player& player);
    Player operator-(const Player& player);
    operator int() const;
    bool operator<(const Player& player);
    bool operator==(const Player& player);
    Player operator=(const Player& newPlayer); // operatorul egal

    friend istream& operator>>(istream& in, Player& inputPlayer);   // functia de citire
    friend ostream& operator<<(ostream& out, const Player& outputPlayer);   // functia de afisare

    ~Player();
};

#endif // PLAYER_H
