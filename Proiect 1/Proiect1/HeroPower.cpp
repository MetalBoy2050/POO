#include <iostream>
#include <cstring>
#include "HeroPower.h"

using namespace std;

HeroPower::HeroPower(){
    this->name = NULL;
    this->description = NULL;
    this->backgroundImageFile = NULL;
    this->backgroundAnimationFile = NULL;
    this->attackAdded = 0;
    this->healthHealed = 0;
    this->armorGiven = 0;
}

HeroPower::HeroPower(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile,
          int attackAdded, int healthHealed, int armorGiven){
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->description = new char[strlen(description)];
    strcpy(this->description, description);
    this->backgroundImageFile = new char[strlen(backgroundImageFile)];
    strcpy(this->backgroundImageFile, backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile)];
    strcpy(this->backgroundAnimationFile, backgroundAnimationFile);
    this->attackAdded = attackAdded;
    this->healthHealed = healthHealed;
    this->armorGiven = armorGiven;
}

HeroPower::HeroPower(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile,
          int attackAdded, int healthHealed){
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->description = new char[strlen(description)];
    strcpy(this->description, description);
    this->backgroundImageFile = new char[strlen(backgroundImageFile)];
    strcpy(this->backgroundImageFile, backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile)];
    strcpy(this->backgroundAnimationFile, backgroundAnimationFile);
    this->attackAdded = attackAdded;
    this->healthHealed = healthHealed;
    this->armorGiven = 0;
}

HeroPower::HeroPower(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile,
              int attackAdded){
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->description = new char[strlen(description)];
    strcpy(this->description, description);
    this->backgroundImageFile = new char[strlen(backgroundImageFile)];
    strcpy(this->backgroundImageFile, backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile)];
    strcpy(this->backgroundAnimationFile, backgroundAnimationFile);
    this->attackAdded = attackAdded;
    this->healthHealed = 0;
    this->armorGiven = 0;
}

HeroPower::HeroPower(const HeroPower& newHeroPower){
    this->name = new char[strlen(newHeroPower.name)];
    strcpy(this->name, newHeroPower.name);
    this->description = new char[strlen(newHeroPower.description)];
    strcpy(this->description, newHeroPower.description);
    this->backgroundImageFile = new char[strlen(newHeroPower.backgroundImageFile)];
    strcpy(this->backgroundImageFile, newHeroPower.backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(newHeroPower.backgroundAnimationFile)];
    strcpy(this->backgroundAnimationFile, newHeroPower.backgroundAnimationFile);
    this->attackAdded = newHeroPower.attackAdded;
    this->healthHealed = newHeroPower.healthHealed;
    this->armorGiven = newHeroPower.armorGiven;
}

char* HeroPower::getName(){return this->name;}
char* HeroPower::getDescription(){return this->description;}
char* HeroPower::getBackgroundImageFile(){return this->backgroundImageFile;}
char* HeroPower::getBackgroundAnimationFile(){return this->backgroundAnimationFile;}
int HeroPower::getAttackAdded(){return this->armorGiven;}
int HeroPower::getHealthHealed(){return this->healthHealed;}
int HeroPower::getArmorGiven(){return this->armorGiven;}

void HeroPower::setName(char* name){
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
}

void HeroPower::setDescription(char* description){
    this->description = new char[strlen(description)];
    strcpy(this->description, description);
}

void HeroPower::setBackgroundImageFile(char* backgroundImageFile){
    this->backgroundImageFile = new char[strlen(backgroundImageFile)];
    strcpy(this->backgroundImageFile, backgroundImageFile);
}

void HeroPower::setBackgroundAnimationFile(char* backgroundAnimationFile){
    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile)];
    strcpy(this->backgroundAnimationFile, backgroundAnimationFile);
}

void HeroPower::setAttackAdded(int attackAdded){this->attackAdded = attackAdded;}
void HeroPower::setHealthHealed(int healthHealed){this->healthHealed = healthHealed;}
void HeroPower::setArmorGiven(int armorGiven){this->armorGiven = armorGiven;}

void HeroPower::receiveHealth(int health){
    this->healthHealed += health;
}

void HeroPower::receiveAttackAndArmor(int value){
    this->attackAdded += value;
    this->armorGiven += value;
}

HeroPower HeroPower::operator=(const HeroPower& newHeroPower){
    if(this != &newHeroPower){
        if(this->name != NULL)
            delete[] this->name;
        if(this->description != NULL)
            delete[] this->description;
        if(this->backgroundImageFile != NULL)
            delete[] this->backgroundImageFile;
        if(this->backgroundAnimationFile != NULL)
            delete[] this->backgroundAnimationFile;

        this->name = new char[strlen(newHeroPower.name)];
        strcpy(this->name, newHeroPower.name);
        this->description = new char[strlen(newHeroPower.description)];
        strcpy(this->description, newHeroPower.description);
        this->backgroundImageFile = new char[strlen(newHeroPower.backgroundImageFile)];
        strcpy(this->backgroundImageFile, newHeroPower.backgroundImageFile);
        this->backgroundAnimationFile = new char[strlen(newHeroPower.backgroundAnimationFile)];
        strcpy(this->backgroundAnimationFile, newHeroPower.backgroundAnimationFile);
        this->attackAdded = newHeroPower.attackAdded;
        this->healthHealed = newHeroPower.healthHealed;
        this->armorGiven = newHeroPower.armorGiven;
    }

    return *this;
}

int HeroPower::operator[](int i){
    if(i == 0)
        return this->attackAdded;
    if(i == 1)
        return this->healthHealed;
    if(i == 2)
        return this->armorGiven;
    else
        return -1;
}

HeroPower HeroPower::operator++(){
    this->attackAdded++;
    this->healthHealed++;
    this->armorGiven++;

    return *this;
}

HeroPower HeroPower::operator++(int i){
    HeroPower aux = *this;

    aux.attackAdded++;
    aux.healthHealed++;
    aux.armorGiven++;

    return *this;
}

HeroPower HeroPower::operator--(){
    this->attackAdded = max(0, this->attackAdded - 1);
    this->healthHealed = max(0, this->healthHealed - 1);
    this->armorGiven = max(0, this->armorGiven - 1);

    return *this;
};

HeroPower HeroPower::operator+(const HeroPower& card){
    HeroPower aux = *this;

    aux.attackAdded += card.attackAdded;
    aux.healthHealed += card.healthHealed;
    aux.armorGiven += card.armorGiven;

    return aux;
}

HeroPower HeroPower::operator-(const HeroPower& card){
    HeroPower aux = *this;

    aux.attackAdded = max(0, aux.attackAdded - card.attackAdded);
    aux.healthHealed += max(0, aux.healthHealed - card.healthHealed);
    aux.armorGiven += max(0, aux.armorGiven - card.armorGiven);

    return aux;
}

HeroPower::operator int() const{
    return this->attackAdded + this->healthHealed + this->armorGiven;
};

bool HeroPower::operator<(const HeroPower& card){
    return int(this) < int(card);
}

bool HeroPower::operator==(const HeroPower& card){
    return int(this) == int(card);
}


istream& operator>>(istream& in, HeroPower& inputHeroPower){
    cout << "Name: ";

    if(inputHeroPower.name != NULL)
        delete[] inputHeroPower.name;

    char name[200];

    in >> name;

    inputHeroPower.name = new char[strlen(name) + 1];
    strcpy(inputHeroPower.name, name);

    cout << "Description: ";

    if(inputHeroPower.description != NULL)
        delete[] inputHeroPower.description;

    char description[200];

    in.ignore();
    in.getline(description, 201);

    inputHeroPower.description = new char[strlen(description) + 1];
    strcpy(inputHeroPower.description, description);

    cout << "Background image file location: ";

    if(inputHeroPower.backgroundImageFile != NULL)
        delete[] inputHeroPower.backgroundImageFile;

    char backgroundImageFile[200];

    in >> backgroundImageFile;

    inputHeroPower.backgroundImageFile = new char[strlen(backgroundImageFile) + 1];
    strcpy(inputHeroPower.backgroundImageFile, backgroundImageFile);

    cout << "Background Animation file location: ";

    if(inputHeroPower.backgroundAnimationFile != NULL)
        delete[] inputHeroPower.backgroundAnimationFile;

    char backgroundAnimationFile[200];

    in >> backgroundAnimationFile;

    inputHeroPower.backgroundAnimationFile = new char[strlen(backgroundAnimationFile) + 1];
    strcpy(inputHeroPower.backgroundAnimationFile, backgroundAnimationFile);

    cout << "Attack added: ";
    in >> inputHeroPower.attackAdded;
    cout << "Health healed: ";
    in >> inputHeroPower.healthHealed;
    cout << "Armor given: ";
    in >> inputHeroPower.armorGiven;

    return in;
}

ostream& operator<<(ostream& out, const HeroPower& outputHeroPower){
    out << "Name: " << outputHeroPower.name << '\n';
    out << "Description: " << outputHeroPower.description << '\n';
    out << "Background image file location: " << outputHeroPower.backgroundImageFile << '\n';
    out << "Background animation file location: " << outputHeroPower.backgroundAnimationFile << '\n';
    out << "Attack added: " << outputHeroPower.attackAdded << '\n';
    out << "Health healed: " << outputHeroPower.healthHealed << '\n';
    out << "Armor given: " << outputHeroPower.armorGiven << '\n';

    return out;
}

HeroPower::~HeroPower(){
    if(this->name != NULL)
        delete[] this->name;
    if(this->description != NULL)
        delete[] this->description;
    if(this->backgroundImageFile != NULL)
        delete[] this->backgroundImageFile;
    if(this->backgroundAnimationFile != NULL)
        delete[] this->backgroundAnimationFile;
}
