#include <iostream>
#include <fstream>
#include <cstring>
#include "Card.h"

using namespace std;

int Card::contorId = 1000;

Card::Card():idCard(contorId++){
    this->name = new char[strlen("Empty") + 1];
    strcpy(this->name, "Empty");
    this->description = NULL;
    this->imageFile = NULL;
    this->archetype = 0;
    this->classType = 1;
    this->attackValue = 1;
    this->healthValue = 1;
    this->nrKeyWords = 0;
    this->keyWords = NULL;
}

Card::Card(char* name, char* description, char* imageFile, char archetype, int classType,
         int attackValue, int healthValue, int nrKeyWords, int* keyWords):idCard(contorId++){
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->description = new char[strlen(description)];
    strcpy(this->description, description);
    this->imageFile = new char[strlen(imageFile)];
    strcpy(this->imageFile, imageFile);
    this->archetype = archetype;
    this->classType = classType;
    this->attackValue = attackValue;
    this->healthValue = healthValue;
    this->nrKeyWords = nrKeyWords;
    this->keyWords = new int[this->nrKeyWords];

    for(int i = 0; i < nrKeyWords; i++)
        this->keyWords[i] = keyWords[i];
}

Card::Card(char* name, char* description, char* imageFile, char archetype,
         int attackValue, int healthValue, int nrKeyWords, int* keyWords):idCard(contorId++){
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->description = new char[strlen(description)];
    strcpy(this->description, description);
    this->imageFile = new char[strlen(imageFile)];
    strcpy(this->imageFile, imageFile);
    this->archetype = archetype;
    this->classType = 1;
    this->attackValue = attackValue;
    this->healthValue = healthValue;
    this->nrKeyWords = nrKeyWords;
    this->keyWords = new int[this->nrKeyWords];

    for(int i = 0; i < nrKeyWords; i++)
        this->keyWords[i] = keyWords[i];
}

Card::Card(char* name, char* description, char* imageFile, char archetype, int classType,
         int nrKeyWords, int* keyWords):idCard(contorId++){
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->description = description;
    this->imageFile = imageFile;
    this->archetype = archetype;
    this->classType = classType;
    this->attackValue = 1;
    this->healthValue = 1;
    this->nrKeyWords = nrKeyWords;
    this->keyWords = new int[this->nrKeyWords];

    for(int i = 0; i < nrKeyWords; i++)
        this->keyWords[i] = keyWords[i];
}

char* Card::getName(){return this->name;}
char* Card::getImageFile(){return this->imageFile;}
char* Card::getDescription(){return this->description;}
int Card::getArchetype(){return this->archetype;}
int Card::getClassType(){return this->classType;}
int Card::getAttackValue(){return this->attackValue;}
int Card::getHealthValue(){return this->healthValue;}
int* Card::getKeyWords(){return this->keyWords;}

void Card::setName(char *name){
    if(name != NULL)
        delete[] name;

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
};
void Card::setImageFile(char *imageFile){
    if(imageFile != NULL)
        delete[] imageFile;

    this->imageFile = new char[strlen(imageFile) + 1];
    strcpy(this->imageFile, imageFile);
}
void Card::setDescription(char *description){
    if(description != NULL)
            delete[] description;

    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}
void Card::setArchetype(char archetype){this->archetype = archetype;}
void Card::setClassType(int classType){this->classType = classType;}
void Card::setAttackValue(int attackValue){this->attackValue = attackValue;}
void Card::setHealthValue(int healthValue){this->healthValue = healthValue;}
void Card::setKeyWords(int nrKeyWords, int* keyWords){
    if(this->keyWords != NULL)
        delete[] this->keyWords;

    this->nrKeyWords = nrKeyWords;
    this->keyWords = new int[nrKeyWords];

    for(int i = 0; i < nrKeyWords; i++)
        this->keyWords[i] = keyWords[i];
}

void Card::attackAnotherCard(Card card){
    this->healthValue = max(0, this->healthValue - card.attackValue);
    card.healthValue = max(0, card.healthValue - this->attackValue);
}

Card::Card(const Card& newCard):idCard(newCard.idCard){
    this->name = new char[strlen(newCard.name)];
    strcpy(this->name, newCard.name);
    this->description = newCard.description;
    this->imageFile = newCard.imageFile;
    this->archetype = newCard.archetype;
    this->classType = newCard.classType;
    this->attackValue = newCard.attackValue;
    this->healthValue = newCard.healthValue;
    this->nrKeyWords = newCard.nrKeyWords;
    this->keyWords = new int[this->nrKeyWords];

    for(int i = 0; i < newCard.nrKeyWords; i++)
        this->keyWords[i] = newCard.keyWords[i];
};
Card Card::operator= (const Card& newCard){
    if(this != &newCard){
        if(this->name != NULL)
            delete[] name;
        if(this->description != NULL)
                delete[] description;
        if(this->imageFile != NULL)
            delete[] imageFile;

        this->name = new char[strlen(newCard.name)];
        strcpy(this->name, newCard.name);
        this->description = new char[strlen(newCard.description)];
        strcpy(this->description, newCard.description);
        this->imageFile = new char[strlen(newCard.imageFile)];
        strcpy(this->imageFile, newCard.imageFile);
        this->archetype = newCard.archetype;
        this->classType = newCard.classType;
        this->attackValue = newCard.attackValue;
        this->healthValue = newCard.healthValue;
        this->nrKeyWords = newCard.nrKeyWords;
        this->keyWords = new int[this->nrKeyWords];

        for(int i = 0; i < newCard.nrKeyWords; i++)
            this->keyWords[i] = newCard.keyWords[i];
    }

    return *this;
}

int Card::operator[](int i){
    if(i > this->nrKeyWords)
        return 0;

    return this->keyWords[i];
}

Card Card::operator++(){
    this->attackValue++;
    this->healthValue++;

    return *this;
}

Card Card::operator++(int i){
    Card aux = *this;

    aux.attackValue += i;
    aux.healthValue += i;

    return *this;
}

Card Card::operator--(){
    this->healthValue = max(this->healthValue - 1, 0);
    this->attackValue = max(this->attackValue - 1, 0);

    return *this;
}

Card Card::operator+(const Card& card){
    Card aux = *this;

    aux.attackValue += card.attackValue;
    aux.healthValue += card.healthValue;

    return aux;
}

Card Card::operator-(const Card& card){
    Card aux = *this;

    aux.attackValue = max(0, aux.attackValue - card.attackValue);
    aux.healthValue = max(0, aux.healthValue - card.healthValue);

    return aux;
}

Card::operator int() const{
    return this->attackValue + this->healthValue;
}

bool Card::operator<(const Card& card){
    return int(this) < int(card);
}

bool Card::operator==(const Card& card){
    return int(this) == int(card);
}

istream& operator>>(istream& in, Card& inputCard){
    cout << "Nume: ";

    char name[200];
    in >> name;

    if(inputCard.name != NULL)
        delete[] inputCard.name;

    inputCard.name = new char[strlen(name)];
    strcpy(inputCard.name, name);

    cout << "Description: ";

    char description[200];
    in >> description;

    if(inputCard.description != NULL)
        delete[] inputCard.description;

    inputCard.description = new char[strlen(description)];
    strcpy(inputCard.description, description);

    cout << "Image file: ";

    char imageFile[200];
    in >> imageFile;

    if(inputCard.imageFile != NULL)
        delete[] inputCard.imageFile;

    inputCard.imageFile = new char[strlen(imageFile)];
    strcpy(inputCard.imageFile, imageFile);

    cout << "Archetype: ";
    in >> inputCard.archetype;
    cout << "ClassType: ";
    in >> inputCard.classType;
    cout << "Attack: ";
    in >> inputCard.attackValue;
    cout << "Health: ";
    in >> inputCard.healthValue;
    cout << "Nr. Key Words: ";
    in >> inputCard.nrKeyWords;

    if(inputCard.keyWords != NULL)
        delete[] inputCard.keyWords;

    inputCard.keyWords = new int[inputCard.nrKeyWords];

    cout << "Key Words: ";

    for(int i = 0; i < inputCard.nrKeyWords; i++)
        in >> inputCard.keyWords[i];

    return in;
}

ostream& operator<<(ostream& out, const Card& outputCard){
    out << "Name: " << outputCard.name << '\n';
    out << "Description: " << outputCard.description << '\n';
    out << "Image file: " << outputCard.imageFile << '\n';
    out << "Archetype: " << outputCard.archetype << '\n';
    out << "Classtype: " << outputCard.classType << '\n';
    out << "Attack: " << outputCard.attackValue << '\n';
    out << "Health: " << outputCard.healthValue << '\n';
    out << "Nr. Key Words: " << outputCard.nrKeyWords << '\n';

    for(int i = 0; i < outputCard.nrKeyWords; i++)
        out << outputCard.keyWords[i] << " ";

    out << '\n';

    return out;
}

Card::~Card(){
    if(this->name != NULL)
        delete[] this->name;
    if(this->description != NULL)
        delete[] this->description;
    if(this->imageFile != NULL)
        delete[] this->imageFile;
}
