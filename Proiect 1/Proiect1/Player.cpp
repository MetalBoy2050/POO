#include <iostream>
#include <cstring>
#include "Player.h"

using namespace std;

int Player::contorId = 1000;

Player::Player():idPlayer(contorId++){  // Default Constructor
    this->name = new char[strlen("Empty") + 1];
    strcpy(this->name, "Empty");
    this->description = new char[1];
    strcpy(this->description, "");
    this->nrFriends = 0;
    this->listOfFriends = NULL;
    this->profileImageFile = NULL;
    this->age = 0;
    this->gender = 0;
    this->height = 0;
    this->nrDecks = 0;
    listOfDecks = NULL;
}

Player::Player(char* name, char* description, int nrFriends, char** listOfFriends, char* profileImageFile,
    int age, bool gender, float height, int nrDecks, Deck* listOfDecks):idPlayer(contorId++){  // Full Constrcutor
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
    this->nrFriends = nrFriends;
    this->listOfFriends = new char*[nrFriends];
    for(int i = 0; i < nrFriends; i++){
        this->listOfFriends[i] = new char[strlen(listOfFriends[i]) + 1];
        strcpy(this->listOfFriends[i], listOfFriends[i]);
    }
    this->profileImageFile = new char[strlen(profileImageFile) + 1];
    strcpy(this->profileImageFile, profileImageFile);
    this->age = age;
    this->gender = gender;
    this->height = height;
    this->nrDecks = nrDecks;
    this->listOfDecks = listOfDecks;
}

Player::Player(char* name, char* description, int nrFriends, char** listOfFriends, char* profileImageFile,
    int age, float height, int nrDecks, Deck* listOfDecks):idPlayer(contorId++){  // Constructor 1
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
    this->nrFriends = nrFriends;
    this->listOfFriends = new char*[nrFriends];
    for(int i = 0; i < nrFriends; i++){
        this->listOfFriends[i] = new char[strlen(listOfFriends[i]) + 1];
        strcpy(this->listOfFriends[i], listOfFriends[i]);
    }
    this->profileImageFile = new char[strlen(profileImageFile) + 1];
    strcpy(this->profileImageFile, profileImageFile);
    this->age = age;
    this->gender = 0;
    this->height = height;
    this->nrDecks = nrDecks;
    this->listOfDecks = listOfDecks;
}

Player::Player(char* name, int nrFriends, char** listOfFriends, char* profileImageFile,
    int age, float height, int nrDecks, Deck* listOfDecks):idPlayer(contorId++){ // Constructor 2
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->description = new char[1];
    strcpy(this->description, "");
    this->nrFriends = nrFriends;
    this->listOfFriends = new char*[nrFriends];
    for(int i = 0; i < nrFriends; i++){
        this->listOfFriends[i] = new char[strlen(listOfFriends[i]) + 1];
        strcpy(this->listOfFriends[i], listOfFriends[i]);
    }
    this->profileImageFile = new char[strlen(profileImageFile) + 1];
    strcpy(this->profileImageFile, profileImageFile);
    this->age = age;
    this->gender = 0;
    this->height = height;
    this->nrDecks = nrDecks;
    this->listOfDecks = listOfDecks;
}

Player::Player(const Player& newPlayer):idPlayer(newPlayer.idPlayer){  // Copy Constructor
    this->name = new char[strlen(newPlayer.name) + 1];
    strcpy(this->name, newPlayer.name);
    this->description = new char[strlen(newPlayer.description) + 1];
    strcpy(this->description, newPlayer.description);
    this->nrFriends = newPlayer.nrFriends;
    this->listOfFriends = new char*[newPlayer.nrFriends];
    for(int i = 0; i < newPlayer.nrFriends; i++){
        this->listOfFriends[i] = new char[strlen(newPlayer.listOfFriends[i]) + 1];
        strcpy(this->listOfFriends[i], newPlayer.listOfFriends[i]);
    }
    this->profileImageFile = new char[strlen(newPlayer.profileImageFile) + 1];
    strcpy(this->profileImageFile, newPlayer.profileImageFile);
    this->age = newPlayer.age;
    this->gender = newPlayer.gender;
    this->height = newPlayer.height;
    this->nrDecks = newPlayer.nrDecks;
    this->listOfDecks = newPlayer.listOfDecks;
}

char* Player::getPlayerName(){return this->name;}
char* Player::getPlayerDescription(){return this->description;}
char** Player::getListOfFriends(){return this->listOfFriends;}
Deck* Player::getListOfDecks(){return this->listOfDecks;}

void Player::setPlayerName(char* name){
    if(this->name != NULL)
        delete[] this->name;
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
}

void Player::setPlayerDescription(char* description){
    if(this->description != NULL)
        delete[] this->description;
    this->description = new char[strlen(description)];
    strcpy(this->description, description);
}

void Player::addFriend(char* newFriend){
    this->listOfFriends[nrFriends] = new char[strlen(newFriend)];
    strcpy(this->listOfFriends[nrFriends], newFriend);
    this->nrFriends++;
}

void Player::removeFriend(char* oldFriend){
    for(int i = 0; i < this->nrFriends; i++){
        if(strcmp(this->listOfFriends[i], oldFriend) == 0){
            for(int j = i + 1; j < this->nrFriends; j++){
                strcpy(this->listOfFriends[j - 1], this->listOfFriends[j]);
            }
        }
    }

    this->nrFriends--;
}

void Player::showCompleteDecks(){
    for(int i = 0; i < this->nrDecks; i++)
        if(this->listOfDecks[i].getNrCards() == 30)
            cout << this->listOfDecks[i] << '\n';
}

Player Player::operator=(const Player& newPlayer){ // operatorul egal
    if(this != &newPlayer){
        if(this->name != NULL)
            delete[] this->name;
        if(this->description != NULL)
            delete[] this->description;
        if(this->listOfFriends != NULL){
            for(int i = 0; i < this->nrFriends; i++)
                delete[] this->listOfFriends[i];

            delete[] this->listOfFriends;
        }
        if(this->profileImageFile != NULL)
            delete[] this->profileImageFile;
        if(this->listOfDecks != NULL)
            delete[] this->listOfDecks;

        this->name = new char[strlen(newPlayer.name) + 1];
        strcpy(this->name, newPlayer.name);
        this->description = new char[strlen(newPlayer.description) + 1];
        strcpy(this->description, newPlayer.description);
        this->nrFriends = newPlayer.nrFriends;
        this->listOfFriends = new char*[newPlayer.nrFriends];
        for(int i = 0; i < newPlayer.nrFriends; i++){
            this->listOfFriends[i] = new char[strlen(newPlayer.listOfFriends[i]) + 1];
            strcpy(this->listOfFriends[i], newPlayer.listOfFriends[i]);
        }
        this->profileImageFile = new char[strlen(newPlayer.profileImageFile) + 1];
        strcpy(this->profileImageFile, newPlayer.profileImageFile);
        this->age = newPlayer.age;
        this->gender = newPlayer.gender;
        this->height = newPlayer.height;
        this->nrDecks = newPlayer.nrDecks;
        this->listOfDecks = newPlayer.listOfDecks;
    }

    return *this;
}

Deck Player::operator[](int i){return this->listOfDecks[i];}
Player Player::operator++(){
    this->nrDecks++;
    this->listOfDecks[nrDecks - 1] = Deck();

    return *this;
}

Player Player::operator++(int i){
    this->nrDecks += i;

    for(int j = this->nrDecks - i; j < this->nrDecks; j++)
        this->listOfDecks[j] = Deck();

    return *this;
}

Player Player::operator--(){
    if(this->nrDecks){
        this->nrDecks--;
        delete (this->listOfDecks + this->nrDecks);
    }

    return *this;
}

Player Player::operator+(const Player& player){
    Player aux = Player();

    aux.nrFriends = this->nrFriends + player.nrFriends;
    aux.nrDecks = this->nrDecks + player.nrDecks;

    aux.listOfFriends = new char*[aux.nrFriends];
    for(int i = 0; i < this->nrFriends; i++){
        aux.listOfFriends[i] = new char[strlen(this->listOfFriends[i])];
        strcpy(aux.listOfFriends[i], this->listOfFriends[i]);
    }

    aux.listOfDecks = new Deck[aux.nrDecks];
    for(int i = 0; i < this->nrDecks; i++)
        aux.listOfDecks[i] = this->listOfDecks[i];

    for(int i = this->nrDecks; i < aux.nrDecks; i++)
        aux.listOfDecks[i] = player.listOfDecks[i];

    return aux;
}

Player Player::operator-(const Player& player){
    Player aux = Player();

    aux.nrFriends = max(0, this->nrFriends - player.nrFriends);
    aux.nrDecks = max(0, this->nrDecks - player.nrDecks);

    if(aux.nrFriends > 0){
        aux.listOfFriends = new char*[aux.nrFriends];
        for(int i = 0; i < aux.nrFriends; i++){
            aux.listOfFriends[i] = new char[strlen(this->listOfFriends[i])];
            strcpy(aux.listOfFriends[i], this->listOfFriends[i]);
        }
    }

    if(aux.nrDecks > 0){
        aux.listOfDecks = new Deck[aux.nrDecks];
        for(int i = 0; i < aux.nrDecks; i++)
            aux.listOfDecks[i] = this->listOfDecks[i];
    }

    return aux;
}

Player::operator int() const{
    return this->nrFriends;
}

bool Player::operator<(const Player& player){
    return this->nrDecks < player.nrFriends;
}

bool Player::operator==(const Player& player){
    return this->nrDecks == player.nrFriends;
}

istream& operator>>(istream& in, Player& inputPlayer){
    cout << "Name: ";

    if(inputPlayer.name != NULL)
        delete[] inputPlayer.name;

    char name[200];

    in >> name;

    inputPlayer.name = new char[strlen(name) + 1];
    strcpy(inputPlayer.name, name);

    cout << "Description: ";

    if(inputPlayer.description != NULL)
        delete[] inputPlayer.description;

    char description[200];

    in.getline(description, 201);

    inputPlayer.description = new char[strlen(description) + 1];
    strcpy(inputPlayer.description, description);

    cout << "Number of decks: ";
    in >> inputPlayer.nrDecks;

    if(inputPlayer.listOfDecks != NULL)
        delete[] inputPlayer.listOfDecks;

    inputPlayer.listOfDecks = new Deck[inputPlayer.nrDecks];
    cout << "Decks: \n";

    for(int i = 0; i < inputPlayer.nrDecks; i++)
        in >> inputPlayer.listOfDecks[i];

    return in;
}

ostream& operator<<(ostream& out, const Player& outputPlayer){
    out << "Name: " << outputPlayer.name << '\n';
    out << "Description: " << outputPlayer.description << '\n';
    out << "Cards: \n";

    for(int i = 0; i < outputPlayer.nrDecks; i++)
        out << outputPlayer.listOfDecks[i] << "\n";

    return out;
}

Player::~Player(){
    if(this->name != NULL)
        delete[] this->name;
    if(this->description != NULL)
        delete[] this->description;
    if(this->listOfFriends != NULL){
        for(int i = 0; i < this->nrFriends; i++)
            delete[] this->listOfFriends[i];

        delete[] this->listOfFriends;
    }
    if(this->profileImageFile != NULL)
        delete[] this->profileImageFile;
    if(this->listOfDecks != NULL)
        delete[] this->listOfDecks;
}
