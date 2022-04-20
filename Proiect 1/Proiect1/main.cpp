#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

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

Card::~Card(){
    if(this->name != NULL)
        delete[] this->name;
    if(this->description != NULL)
        delete[] this->description;
    if(this->imageFile != NULL)
        delete[] this->imageFile;
}

Card::!Card(){
    if(!)
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

class Deck{
private:
    char* name, *description;
    int classType; //0 -> None, 1 -> Hunter, 2 -> Warrior, 3 -> Priest, 4 -> Mage, 5 -> Warlock, 6 -> Rogue
    int nrCards; //a deck has 30 cards;
    Card* listOfCards;

    const int idDeck;
    static int contorId;
public:
    Deck();
    Deck(char* name, int classType, int nrCards, Card* listOfCards);
    Deck(Card* listOfCards);
    Deck(int nrCards, Card* listOfCards);
    Deck(const Deck& newDeck);

    char* getName();
    char* getDescription();
    int getClassType();
    int getNrCards();
    Card* getListOfCards();

    void setName(char* name);
    void setDescription(char* description);

    Card* getCardsWithGivenAttack(int attack);

    Deck operator=(const Deck& newDeck);
    Card operator[](int i);
    Deck operator++();
    Deck operator--();
    Deck operator+(const Deck& deck);
    Deck operator-(const Deck& deck);
    operator int() const;
    bool operator<(const Deck& deck);
    bool operator==(const Deck& deck);

    friend Deck operator+(const Card& card, const Deck& deck);
    friend Deck operator+(const Deck& deck, const Card& card);
    friend istream& operator>>(istream& in, Deck& newDeck);
    friend ostream& operator<<(ostream& out, const Deck& newDeck);

    ~Deck();
};

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

    this->listOfCards = new Card[this->nrCards];

    for(int i = 0; i < nrCards; i++)
        this->listOfCards[i] = listOfCards[i];
}

Deck::Deck(Card* listOfCards):idDeck(contorId++){
    this->name = new char[strlen("Empty") + 1];
    strcpy(this->name, "Empty");
    this->classType = 0;
    this->nrCards = 30;
    this->listOfCards = new Card[this->nrCards];

    for(int i = 0; i < nrCards; i++)
        this->listOfCards[i] = listOfCards[i];
}

Deck::Deck(int nrCards, Card* listOfCards):idDeck(contorId++){
    this->name = new char[strlen("Empty") + 1];
    strcpy(this->name, "Empty");
    this->classType = 0;
    this->nrCards = nrCards;
    this->listOfCards = new Card[this->nrCards];

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
    this->listOfCards = new Card[newDeck.nrCards];

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
   // Card* cardList;

    int cnt = 0;

    for(int i = 0; i < this->nrCards; i++)
        if(this->listOfCards[i].getAttackValue() == attack)
            cnt++;

    Card* cardList = new Card[cnt];
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

HeroPower::HeroPower(){
    this->name = new char[strlen("Empty") + 1];
    strcpy(this->name, "Empty");
    this->description = new char[1];
    strcpy(this->description, "");
    this->backgroundImageFile = new char[1];
    strcpy(this->backgroundImageFile, "");
    this->backgroundAnimationFile = new char[1];
    strcpy(this->backgroundAnimationFile, "");
    this->attackAdded = 0;
    this->healthHealed = 0;
    this->armorGiven = 0;
}

HeroPower::HeroPower(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile,
          int attackAdded, int healthHealed, int armorGiven){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
    this->backgroundImageFile = new char[strlen(backgroundImageFile) + 1];
    strcpy(this->backgroundImageFile, backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile) + 1];
    strcpy(this->backgroundAnimationFile, backgroundAnimationFile);
    this->attackAdded = attackAdded;
    this->healthHealed = healthHealed;
    this->armorGiven = armorGiven;
}

HeroPower::HeroPower(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile,
          int attackAdded, int healthHealed){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
    this->backgroundImageFile = new char[strlen(backgroundImageFile) + 1];
    strcpy(this->backgroundImageFile, backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile) + 1];
    strcpy(this->backgroundAnimationFile, backgroundAnimationFile);
    this->attackAdded = attackAdded;
    this->healthHealed = healthHealed;
    this->armorGiven = 0;
}

HeroPower::HeroPower(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile,
              int attackAdded){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
    this->backgroundImageFile = new char[strlen(backgroundImageFile) + 1];
    strcpy(this->backgroundImageFile, backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile) + 1];
    strcpy(this->backgroundAnimationFile, backgroundAnimationFile);
    this->attackAdded = attackAdded;
    this->healthHealed = 0;
    this->armorGiven = 0;
}

HeroPower::HeroPower(const HeroPower& newHeroPower){
    this->name = new char[strlen(newHeroPower.name) + 1];
    strcpy(this->name, newHeroPower.name);
    this->description = new char[strlen(newHeroPower.description) + 1];
    strcpy(this->description, newHeroPower.description);
    this->backgroundImageFile = new char[strlen(newHeroPower.backgroundImageFile) + 1];
    strcpy(this->backgroundImageFile, newHeroPower.backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(newHeroPower.backgroundAnimationFile) + 1];
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
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void HeroPower::setDescription(char* description){
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

void HeroPower::setBackgroundImageFile(char* backgroundImageFile){
    this->backgroundImageFile = new char[strlen(backgroundImageFile) + 1];
    strcpy(this->backgroundImageFile, backgroundImageFile);
}

void HeroPower::setBackgroundAnimationFile(char* backgroundAnimationFile){
    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile) + 1];
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

        this->name = new char[strlen(newHeroPower.name) + 1];
        strcpy(this->name, newHeroPower.name);
        this->description = new char[strlen(newHeroPower.description) + 1];
        strcpy(this->description, newHeroPower.description);
        this->backgroundImageFile = new char[strlen(newHeroPower.backgroundImageFile) + 1];
        strcpy(this->backgroundImageFile, newHeroPower.backgroundImageFile);
        this->backgroundAnimationFile = new char[strlen(newHeroPower.backgroundAnimationFile) + 1];
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

class Hero{
    char* name, *description, *backgroundImageFile, *backgroundAnimationFile;
    int health, attack, armor;
    HeroPower heroPower;

public:
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

Hero::Hero(){
    this->name = new char[strlen("Empty") + 1];
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
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
    this->backgroundImageFile = new char[strlen(backgroundImageFile) + 1];
    strcpy(this->backgroundImageFile, backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile) + 1];
    strcpy(this->backgroundImageFile, backgroundAnimationFile);
    this->health = health;
    this->attack = attack;
    this->armor = armor;
    this->heroPower = heroPower;
}

Hero::Hero(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile, int health, HeroPower heroPower){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
    this->backgroundImageFile = new char[strlen(backgroundImageFile) + 1];
    strcpy(this->backgroundImageFile, backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile) + 1];
    strcpy(this->backgroundImageFile, backgroundAnimationFile);
    this->health = health;
    this->attack = 0;
    this->armor = 0;
    this->heroPower = heroPower;
}

Hero::Hero(char* name, char* description, char* backgroundImageFile, char* backgroundAnimationFile, int health, int armor, HeroPower heroPower){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
    this->backgroundImageFile = new char[strlen(backgroundImageFile) + 1];
    strcpy(this->backgroundImageFile, backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(backgroundAnimationFile) + 1];
    strcpy(this->backgroundImageFile, backgroundAnimationFile);
    this->health = health;
    this->attack = 0;
    this->armor = armor;
    this->heroPower = heroPower;
}

Hero::Hero(const Hero& newHero){
    this->name = new char[strlen(newHero.name) + 1];
    strcpy(this->name, newHero.name);
    this->description = new char[strlen(newHero.description) + 1];
    strcpy(this->description, newHero.description);
    this->backgroundImageFile = new char[strlen(newHero.backgroundImageFile) + 1];
    strcpy(this->backgroundImageFile, newHero.backgroundImageFile);
    this->backgroundAnimationFile = new char[strlen(newHero.backgroundAnimationFile) + 1];
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
    cout << "Hero Power: \n";
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
    out << "Hero power: \n" << outputHero.heroPower << '\n';

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
    void setListOfFriends(int nrFriends, char** listOfFriend);

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
    this->listOfDecks = NULL;
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
    this->listOfDecks = new Deck[this->nrDecks];

    for(int i = 0; i < this->nrDecks; i++)
        this->listOfDecks[i] = listOfDecks[i];
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
    this->listOfDecks = new Deck[this->nrDecks];

    for(int i = 0; i < this->nrDecks; i++)
        this->listOfDecks[i] = listOfDecks[i];}

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
    if(newPlayer.profileImageFile == NULL)
        this->profileImageFile = NULL;
    else{
        this->profileImageFile = new char[strlen(newPlayer.profileImageFile) + 1];
        strcpy(this->profileImageFile, newPlayer.profileImageFile);
    }
    this->age = newPlayer.age;
    this->gender = newPlayer.gender;
    this->height = newPlayer.height;
    this->nrDecks = newPlayer.nrDecks;
    this->listOfDecks = new Deck[newPlayer.nrDecks];

    for(int i = 0; i < this->nrDecks; i++)
        this->listOfDecks[i] = newPlayer.listOfDecks[i];
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

void Player::setListOfFriends(int nrFriends, char** listOfFriend){
    if(this->listOfFriends != NULL)
        for(int i = 0; i < this->nrFriends; i++)
            if(this->listOfFriends[i] != NULL)
                delete[] this->listOfFriends[i];

    if(nrFriends != 0){
        this->listOfFriends = new char*[nrFriends];
        this->nrFriends = nrFriends;

        for(int i = 0; i < nrFriends; i++){
            if(this->listOfFriends[i] != NULL)
                delete[] listOfFriends[i];

            this->listOfFriends[i] = new char[strlen(listOfFriends[i]) + 1];
            strcpy(this->listOfFriends[i], listOfFriends[i]);
        }
    }
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

    in.ignore();
    in.getline(description, 201);

    inputPlayer.description = new char[strlen(description) + 1];
    strcpy(inputPlayer.description, description);

    char profileImageFile[200];

    cout << "Profile image file: ";

    if(inputPlayer.profileImageFile != NULL)
        delete[] inputPlayer.profileImageFile;

    in >> profileImageFile;

    inputPlayer.profileImageFile = new char[strlen(profileImageFile) + 1];
    strcpy(inputPlayer.profileImageFile, profileImageFile);

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


int main()
{
    //0 -> default, 1 -> common, 2 -> rare, 3 -> epic, 4 -> legendary
    //0 -> None, 1 -> Hunter, 2 -> Warrior, 3 -> Priest, 4 -> Mage, 5 -> Warlock, 6 -> Rogue
    /*
    0 -> stealth, 1 -> battlecry, 2 - >deathrattle,
    3 -> taunt, 4 -> rush, 5 -> charge, 6 -> silence
    */

    vector<Card> cards;
    vector<Deck> decks;
    vector<Player> players;
    vector<HeroPower> heroPowers;
    vector<Hero> heroes;

    int k = 1, startProgram = true;
    while(k){
        if(!startProgram)
            cout << "\n\n";
        else
            startProgram = false;

        cout << "0-stop program\n";
        cout << "1-add card\n";
        cout << "2-update card\n";
        cout << "3-delete card\n";
        cout << "4-display cards\n";
        cout << "5-add deck\n";
        cout << "6-update a card in deck\n";
        cout << "7-delete deck\n";
        cout << "8-display decks\n";
        cout << "9-add player\n";
        cout << "10-update player\n";
        cout << "11-delete player\n";
        cout << "12-display player\n";
        cout << "13-add hero power\n";
        cout << "14-update hero power\n";
        cout << "15-delete hero power\n";
        cout << "16-display hero powers\n";
        cout << "17-add hero\n";
        cout << "18-update hero\n";
        cout << "19-delete hero\n";
        cout << "20-display heroes\n\n";

        int c;

        cin >> c;

        switch(c){
        case 0:{
            k = 0;
            break;
        }
        case 1:{
            Card card;
            cin >> card;
            cards.push_back(card);

            break;
        }
        case 2:{
            int idCard;
            cout << "The position of the card from the vector of cards: ";
            cin >> idCard;
            cout << "Please insert the information for the new card!\n";
            Card newCard;

            cin >> newCard;

            cards[idCard] = newCard;

            break;
        }
        case 3:{
            cout << "The id of the card you want to delete: ";
            int idCard;
            cin >> idCard;

            cards.erase(cards.begin() + idCard);

            break;
        }
        case 4:{
            cout << "The cards are: \n";

            for(int i = 0; i < int(cards.size()); i++){
                cout << "Card " << i << ":\n";
                cout << cards[i] << '\n';
            }

            break;
        }
        case 5:{
            Deck deck;

            cin >> deck;
            decks.push_back(deck);

            break;
        }
        case 6:{
            int idDeck, idOldCard, idNewCard;

            cout << "The position of the deck: ";
            cin >> idDeck;
            cout << "The position of the card in the deck that you want to replace: ";
            cin >> idOldCard;
            cout << "The position of the card that you want to put: ";
            cin >> idNewCard;

            decks[idDeck].getListOfCards()[idOldCard] = cards[idNewCard];
            break;
        }
        case 7:{
            int idDeck;

            cout << "The position of the deck you want to remove: ";
            cin >> idDeck;

            decks.erase(decks.begin() + idDeck);

            break;
        }
        case 8:{
            cout << "The decks are: \n";

            for(int i = 0; i < int(decks.size()); i++){
                cout << "Deck " << i << ":\n";
                cout << decks[i] << '\n';
            }

            break;
        }
        case 9:{
            Player newPlayer;

            cin >> newPlayer;
            players.push_back(newPlayer);

            break;
        }
        case 10:{
            int idPlayer;

            cout << "Position of the player: ";
            cin >> idPlayer;
            cout << "Introduce the new player: \n";
            Player newPlayer;

            cin >> newPlayer;
            players[idPlayer] = newPlayer;

            break;
        }
        case 11:{
            int idPlayer;

            cout << "The position of the player you want to remove: ";
            cin >> idPlayer;

            players.erase(players.begin() + idPlayer);

            break;
        }
        case 12:{
            cout << "The players are: \n";

            for(int i = 0; i < int(players.size()); i++){
                cout << "Player " << i << ":\n";
                cout << players[i] << '\n';
            }

            break;
        }
        case 13:{
            HeroPower newHeroPower;

            cin >> newHeroPower;
            heroPowers.push_back(newHeroPower);

            break;
        }
        case 14:{
            int idHeroPower;

            cout << "Position of the hero power you want to replace: ";
            cin >> idHeroPower;
            cout << "Introduce the new hero player: \n";
            HeroPower newHeroPower;

            cin >> newHeroPower;
            heroPowers[idHeroPower] = newHeroPower;

            break;
        }
        case 15:{
            int idHeroPower;

            cout << "The position of the hero power you want to remove: ";
            cin >> idHeroPower;

            heroPowers.erase(heroPowers.begin() + idHeroPower);

            break;
        }
        case 16:{
            cout << "The hero powers are: \n";

            for(int i = 0; i < int(heroPowers.size()); i++){
                cout << "Hero Power " << i << ":\n";
                cout << heroPowers[i] << '\n';
            }

            break;
        }
        case 17:{
            Hero newHero;

           // cout << "Ceva\n";
            cin >> newHero;
            //cout << "Altceva\n";
            heroes.push_back(newHero);

            break;
        }
        case 18:{
            int idHero;

            cout << "Position of the Hero you want to replace: ";
            cin >> idHero;
            cout << "Introduce the new Hero: \n";
            Hero newHero;

            cin >> newHero;
            heroes[idHero] = newHero;

            break;
        }
        case 19:{
            int idHero;

            cout << "The position of the hero you want to remove: ";
            cin >> idHero;

            heroes.erase(heroes.begin() + idHero);

            break;
        }
        case 20:{
            cout << "The heroes are: \n";

            for(int i = 0; i < int(heroes.size()); i++){
                cout << "Hero " << i << ":\n";
                cout << heroes[i] << '\n';
            }

            break;
        }
        default:{
            cout << "Ati introdus un numar gresit!\n";
            break;
        }
        }
    }

    return 0;
}
