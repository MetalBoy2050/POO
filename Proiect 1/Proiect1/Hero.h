#include <iostream>
#include <cstring>
#include "HeroPower.h"

using namespace std;

#ifndef HERO_H
#define HERO_H

class Hero{
    char* name, *description, *backgroundImageFile, *backgroundAnimationFile;
    int health, attack, armor;
    HeroPower heroPower;

    Hero();
    Hero(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile, int health, int attack, int armor, HeroPower heroPower);
    Hero(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile, int health, HeroPower heroPower);
    Hero(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile, int health, int armor, HeroPower heroPower);
    Hero(const Hero& newHero);

    char* getName();
    char* getDescription();
    char* getBackgroundImageFile();
    char* getBackgroundAnimationFile();
    int getAttack();
    int getHealth();
    int getArmor();
    HeroPower getHeroPower();

    void setName(char* name);
    void setDescription(char* description);
    void setBackgroundImageFile(char* backgroundImageFile);
    void setBackgroundAnimationFile(char* backgroundAnimationFile);
    void setAttack(int attack);
    void setHealth(int health);
    void setArmor(int armor);
    void setHeroPower(HeroPower heroPower);

    void takeDamage(int damage);

    Hero operator=(const Hero& newHero);
    int operator[](int i);
    Hero operator++();
    Hero operator++(int i);
    Hero operator--();
    Hero operator+(const Hero& card);
    Hero operator-(const Hero& card);
    operator int() const;
    bool operator<(const Hero& card);
    bool operator==(const Hero& card);

    friend istream& operator>>(istream& in, Hero& inputHero);
    friend ostream& operator<<(ostream& out, const Hero& newHero);

    ~Hero();
};

#endif // HERO_H
