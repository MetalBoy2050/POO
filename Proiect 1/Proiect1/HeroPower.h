#include <iostream>
#include <cstring>

#ifndef HERO_POWER_H
#define HERO_POWER_H

using namespace std;

class HeroPower{
private:
    char* name, *description, *backgroundImageFile, *backgroundAnimationFile;
    int attackAdded, healthHealed, armorGiven;

public:
    HeroPower();
    HeroPower(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile,
              int attackAdded, int healthHealed, int armorGiven);
    HeroPower(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile,
              int attackAdded, int healthHealed);
    HeroPower(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile,
              int attackAdded);
    HeroPower(const HeroPower& newHeroPower);

    char* getName();
    char* getDescription();
    char* getBackgroundImageFile();
    char* getBackgroundAnimationFile();
    int getAttackAdded();
    int getHealthHealed();
    int getArmorGiven();

    void setName(char* name);
    void setDescription(char* description);
    void setBackgroundImageFile(char* backgroundImageFile);
    void setBackgroundAnimationFile(char* backgroundAnimationFile);
    void setAttackAdded(int attackAdded);
    void setHealthHealed(int healthHealed);
    void setArmorGiven(int armorGiven);

    void receiveHealth(int health);
    void receiveAttackAndArmor(int value);

    HeroPower operator= (const HeroPower& newCard);
    int operator[](int i);
    HeroPower operator++();
    HeroPower operator++(int i);
    HeroPower operator--();
    HeroPower operator+(const HeroPower& card);
    HeroPower operator-(const HeroPower& card);
    operator int() const;
    bool operator<(const HeroPower& card);
    bool operator==(const HeroPower& card);

    friend istream& operator>>(istream& in, HeroPower& inputHeroPower);
    friend ostream& operator<<(ostream& out, const HeroPower& outputHeroPower);

    ~HeroPower();
};

#endif // HEROPOWER_H
