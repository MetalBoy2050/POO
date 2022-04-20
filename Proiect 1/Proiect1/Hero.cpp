#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;
Hero::Hero(){
    this->name = new char[strlen("Empty")];
    strcpy(this->name, "Empty");
    this->description = new char[1];
    strcpy(this->description, "");
    this->backgroundImageFile = NULL;
    this->backgroundAnimationFile = NULL;
    this->health = 30;
    this->attack = 0;
    this->armor = 0;
    this->heroPower = HeroPower();
}

Hero::Hero(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile, int health, int attack, int armor, HeroPower heroPower){
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->description = new char[strlen(description)];
    strcpy(this->description, description);
    this->backgroundImageFile = new char[strlen(backgroundImageFile)];
    strcpy(this->backgroundImageFile, backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile)];
    strcpy(this->backgroundImageFile, backgroundAnimationFile);
    this->health = health;
    this->attack = attack;
    this->armor = armor;
    this->heroPower = heroPower;
}

Hero::Hero(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile, int health, HeroPower heroPower){
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->description = new char[strlen(description)];
    strcpy(this->description, description);
    this->backgroundImageFile = new char[strlen(backgroundImageFile)];
    strcpy(this->backgroundImageFile, backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile)];
    strcpy(this->backgroundImageFile, backgroundAnimationFile);
    this->health = health;
    this->attack = 0;
    this->armor = 0;
    this->heroPower = heroPower;
}

Hero::Hero(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile, int health, int armor, HeroPower heroPower){
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->description = new char[strlen(description)];
    strcpy(this->description, description);
    this->backgroundImageFile = new char[strlen(backgroundImageFile)];
    strcpy(this->backgroundImageFile, backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile)];
    strcpy(this->backgroundImageFile, backgroundAnimationFile);
    this->health = health;
    this->attack = 0;
    this->armor = armor;
    this->heroPower = heroPower;
}

Hero::Hero(const Hero& newHero){
    this->name = new char[strlen(newHero.name)];
    strcpy(this->name, newHero.name);
    this->description = new char[strlen(newHero.description)];
    strcpy(this->description, newHero.description);
    this->backgroundImageFile = new char[strlen(newHero.backgroundImageFile)];
    strcpy(this->backgroundImageFile, newHero.backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(newHero.backgroundAnimationFile)];
    strcpy(this->backgroundImageFile, newHero.backgroundAnimationFile);
    this->health = newHero.health;
    this->attack = newHero.attack;
    this->armor = newHero.armor;
    this->heroPower = newHero.heroPower;
}

char* Hero::getName(){return this->name;}
char* Hero::getDescription(){return this->description;}
char* Hero::getBackgroundImageFile(){return this->backgroundImageFile;}
char* Hero::getBackgroundAnimationFile(){return this->backgroundAnimationFile;}
int Hero::getAttack(){return this->attack;}
int Hero::getHealth(){return this->health;}
int Hero::getArmor(){return this->armor;}
HeroPower Hero::getHeroPower(){return this->heroPower;}

void Hero::setName(char* name){
    if(this->name != NULL)
        delete[] this->name;

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Hero::setDescription(char* description){
    if(this->description != NULL)
        delete[] this->description;

    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

void Hero::setBackgroundImageFile(char* backgroundImageFile){
    if(this->backgroundImageFile != NULL)
        delete[] this->backgroundImageFile;

    this->backgroundImageFile = new char[strlen(backgroundImageFile) + 1];
    strcpy(this->backgroundImageFile, backgroundImageFile);
}

void Hero::setBackgroundAnimationFile(char* backgroundAnimationFile){
    if(this->backgroundAnimationFile != NULL)
        delete[] this->backgroundAnimationFile;

    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile) + 1];
    strcpy(this->backgroundAnimationFile, backgroundAnimationFile);
}

void Hero::setAttack(int attack){this->attack = attack;}

void Hero::setHealth(int health){this->health = health;}

void Hero::setArmor(int armor){this->armor = armor;}

void Hero::setHeroPower(HeroPower HeroPower){this->heroPower = HeroPower;}

void Hero::takeDamage(int damage){
    if(damage > this->armor){
        this->armor = 0;
        damage -= this->armor;
        this->health = max(0, this->health - damage);
    }
}

Hero Hero::operator=(const Hero& newHero){
    if(this != &newHero){
        if(this->name != NULL)
            delete[] this->name;
        if(this->description != NULL)
            delete[] this->description;
        if(this->backgroundImageFile != NULL)
            delete[] this->backgroundImageFile;
        if(this->backgroundAnimationFile != NULL)
        delete[] this->backgroundAnimationFile;
        this->name = new char[strlen(newHero.name)];
        strcpy(this->name, newHero.name);
        this->description = new char[strlen(newHero.description)];
        strcpy(this->description, newHero.description);
        this->backgroundImageFile = new char[strlen(newHero.backgroundImageFile)];
        strcpy(this->backgroundImageFile, newHero.backgroundImageFile);
        this->backgroundAnimationFile = new char[strlen(newHero.backgroundAnimationFile)];
        strcpy(this->backgroundImageFile, newHero.backgroundAnimationFile);
        this->health = newHero.health;
        this->attack = newHero.attack;
        this->armor = newHero.armor;
        this->heroPower = newHero.heroPower;
    }

    return *this;
}

int Hero::operator[](int i){
    if(i == 0)
        return this->attack;
    if(i == 1)
        return this->health;
    if(i == 2)
        return this->armor;
    else
        return -1;
}

Hero Hero::operator++(){
    this->attack++;
    this->health++;
    this->armor++;

    return *this;
}

Hero Hero::operator++(int i){
    Hero aux = *this;

    aux.attack++;
    aux.health++;
    aux.armor++;

    return *this;
}

Hero Hero::operator--(){
    this->attack = max(0, this->attack - 1);
    this->health = max(0, this->health - 1);
    this->armor = max(0, this->armor - 1);

    return *this;
}

Hero Hero::operator+(const Hero& card){
    Hero aux = *this;

    aux.attack += card.attack;
    aux.health += card.health;
    aux.armor += card.armor;

    return aux;
}

Hero Hero::operator-(const Hero& card){
    Hero aux = *this;

    aux.attack = max(0, aux.attack - card.attack);
    aux.health += max(0, aux.health - card.health);
    aux.armor += max(0, aux.armor - card.armor);

    return aux;
}

Hero::operator int() const{
    return this->attack + this->health + this->armor;
}

bool Hero::operator<(const Hero& card){
    return int(this) < int(card);
}

bool Hero::operator==(const Hero& card){
    return int(this) == int(card);
}


istream& operator>>(istream& in, Hero& inputHero){
    cout << "Name: ";

    if(inputHero.name != NULL)
        delete[] inputHero.name;

    char name[200];

    in >> name;

    inputHero.name = new char[strlen(name) + 1];
    strcpy(inputHero.name, name);

    cout << "Description: ";

    if(inputHero.description != NULL)
        delete[] inputHero.description;

    char description[200];

    in.ignore();
    in.getline(description, 201);

    inputHero.description = new char[strlen(description) + 1];
    strcpy(inputHero.description, description);

    cout << "Background image file location: ";

    if(inputHero.backgroundImageFile != NULL)
        delete[] inputHero.backgroundImageFile;

    char backgroundImageFile[200];

    in >> backgroundImageFile;

    inputHero.backgroundImageFile = new char[strlen(backgroundImageFile) + 1];
    strcpy(inputHero.backgroundImageFile, backgroundImageFile);

    cout << "Background Animation file location: ";

    if(inputHero.backgroundAnimationFile != NULL)
        delete[] inputHero.backgroundAnimationFile;

    char backgroundAnimationFile[200];

    in >> backgroundAnimationFile;

    inputHero.backgroundAnimationFile = new char[strlen(backgroundAnimationFile) + 1];
    strcpy(inputHero.backgroundAnimationFile, backgroundAnimationFile);

    cout << "Attack: ";
    in >> inputHero.attack;
    cout << "Health: ";
    in >> inputHero.health;
    cout << "Armor: ";
    in >> inputHero.armor;
    cout << "Hero Power: ";
    in >> inputHero.heroPower;

    return in;
}

ostream& operator<<(ostream& out, const Hero& outputHero){
    out << "Name: " << outputHero.name << '\n';
    out << "Description: " << outputHero.description << '\n';
    out << "Background image file location: " << outputHero.backgroundImageFile << '\n';
    out << "Background animation file location: " << outputHero.backgroundAnimationFile << '\n';
    out << "Health: " << outputHero.health << '\n';
    out << "Attack: " << outputHero.attack << '\n';
    out << "Armor: " << outputHero.armor << '\n';
    out << "Hero power: " << outputHero.heroPower << '\n';

    return out;
}

Hero::~Hero(){
    if(this->name != NULL)
        delete[] this->name;
    if(this->description != NULL)
        delete[] this->description;
    if(this->backgroundImageFile != NULL)
        delete[] this->backgroundImageFile;
    if(this->backgroundAnimationFile != NULL)
        delete[] this->backgroundAnimationFile;
}
