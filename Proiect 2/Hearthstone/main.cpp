#include "ChooseOne.h"
#include "Deck.h"

using namespace std;

int main()
{
    vector<Card*> cards, minions, spells, chooseOnes;
    vector<Deck*> decks;

    while(1){
        cout << "=======================================================================================================================\n";
        cout << "Alegeti una dintre optiunile de mai jos!\n";
        cout << "=======================================================================================================================\n";
        cout << "1. Creeaza o carte(Minion/Spell/ChooseOneCard)!\n";
        cout << "2. Elimina o carte dupa id!\n";
        cout << "3. Afiseaza toate cartile!\n";
        cout << "4. Afiseaza totii minionii!\n";
        cout << "5. Afiseaza toate spellurile!\n";
        cout << "6. Afiseaza toate choose one card-urile!\n";
        cout << "7. Creeaza un deck\n";
        cout << "8. Adauga o carte dupa id la un deck dupa deckId\n";
        cout << "9. Elimina o carte dupa id dintr-un deck dupa deckId\n";
        cout << "10. Afiseaza cartile dintr-un deck dupa id\n";
        cout << "11. Calculeaza valoarea unui deck dupa id\n";
        cout << "12. Adauga spell damage la un spell dupa id\n";
        cout << "13. Schimba alegerea unui choose one card dupa id\n";

        int optiune;

        cout << "Optiunea aleasa este: ";
        cin >> optiune;

        switch(optiune){
        case 1:{
            Card* card;

            cout << "Tipul cartii pe care vreti s-o adaugati(Minion = 1, Spell = 2, ChooseOneCard = 3): ";
            int tip;

            cin >> tip;

            switch(tip){
            case 1:
                card = new Minion;

                cin >> *card;
                cards.push_back(card);
                minions.push_back(card);
                break;
            case 2:
                card = new Spell;

                cin >> *card;
                cards.push_back(card);
                spells.push_back(card);
                break;
            case 3:
                card = new ChooseOne;

                cin >> *card;
                cards.push_back(card);
                chooseOnes.push_back(card);
                break;
            default:
                cout << "Optiunea primita nu se numara printre cele valabile! Va rog sa alegeti o alta optiune!\n";
                break;
            }

            break;
        }
        case 2:{
            cout << "Id-ul cartii pe care doresti s-o elimini: ";
            int id;

            cin >> id;

            int gasit = -1;
            for(unsigned int i = 0; gasit == -1 && i < cards.size(); i++)
                if(cards[i]->getCardId() == id)
                    gasit = i;

            if(gasit == -1)
                 cout << "Cartea n-a fost gasita! Va rog alegeti inca o data optiunea dorita sau alta optiune!\n";
            else{
                cout << "Cartea a fost gasita. Stergere in progres...\n";
                cards.erase(cards.begin() + gasit);
            }
            break;
        }
        case 3:
            for(const Card* x : cards)
                cout << *x << '\n';

            break;
        case 4:
            for(const Card* x : minions)
                cout << *x << '\n';

            break;
        case 5:
            for(const Card* x : spells)
                cout << *x << '\n';

            break;
        case 6:
            for(const Card* x : chooseOnes)
                cout << *x << '\n';

            break;
        case 7:{
            Deck* deck = new Deck;

            cin >> *deck;
            decks.push_back(deck);

            break;
        }
        case 8:{
            cout << "Id-ul deck-ului la care doresti sa adaugi o carte: ";
            int deckId;

            cin >> deckId;

            int gasitDeck = -1;
            for(unsigned int i = 0; gasitDeck == -1 && i < decks.size(); i++)
                if(decks[i]->getDeckId() == deckId)
                    gasitDeck = i;

            if(gasitDeck == -1)
                 cout << "Deck-ul n-a fost gasit! Va rog alegeti inca o data optiunea dorita sau o alta optiune!\n";
            else{
                cout << "Deck-ul a fos gasit\n";
                cout << "Id-ul cartii pe care doresti s-o adaugi: ";

                int cardId;

                cin >> cardId;

                int gasitCard = -1;
                for(unsigned int i = 0; gasitCard == -1 && i < cards.size(); i++)
                    if(cards[i]->getCardId() == cardId)
                        gasitCard = i;

                if(gasitCard == -1)
                     cout << "Cartea n-a fost gasita! Va rog alegeti inca o data optiunea dorita sau o alta optiune!\n";
                else{
                    cout << "Cartea a fost gasita. Adaugare in progres...\n";
                    decks[gasitDeck]->pushCard(cards[gasitCard]);
                }
            }
            break;
        }
        case 9:{
            cout << "Id-ul deck-ului din care doresti sa scoti o carte: ";
            int deckId;

            cin >> deckId;

            int gasitDeck = -1;
            for(unsigned int i = 0; gasitDeck == -1 && i < decks.size(); i++)
                if(decks[i]->getDeckId() == deckId)
                    gasitDeck = i;

            if(gasitDeck == -1)
                 cout << "Deck-ul n-a fost gasit! Va rog alegeti inca o data optiunea dorita sau o alta optiune!\n";
            else{
                cout << "Deck-ul a fos gasit\n";
                cout << "Id-ul cartii pe care doresti s-o scoti: ";

                int cardId;

                cin >> cardId;

                int gasitCard = -1;
                for(unsigned int i = 0; gasitCard == -1 && i < decks[gasitDeck]->getCards().size(); i++)
                    if(decks[gasitDeck]->getCards()[i]->getCardId() == cardId)
                        gasitCard = i;

                if(gasitCard == -1)
                     cout << "Cartea n-a fost gasita! Va rog alegeti inca o data optiunea dorita sau o alta optiune!\n";
                else{
                    cout << "Cartea a fost gasita. Stergere in progres...\n";
                    decks[gasitDeck]->getCards().erase(decks[gasitDeck]->getCards().begin() + gasitCard);
                }
            }
            break;
        }
        case 10:{
            cout << "Id-ul deck-ului pe care vrei sa-l afisezi: ";
            int deckId;

            cin >> deckId;

            int gasitDeck = -1;
            for(unsigned int i = 0; gasitDeck == -1 && i < decks.size(); i++)
                if(decks[i]->getDeckId() == deckId)
                    gasitDeck = i;

            if(gasitDeck == -1)
                 cout << "Deck-ul n-a fosst gasit! Va rog alegeti inca o data optiunea dorita sau o alta optiune!\n";
            else{
                for(auto x : decks[gasitDeck]->getCards())
                    cout << *x << '\n';
            }

            break;
        }
        case 11:{
            cout << "Id-ul deck-ului a carui valoarea vrei s-o calculezi: ";
            int deckId;

            cin >> deckId;

            int gasitDeck = -1;
            for(unsigned int i = 0; gasitDeck == -1 && i < decks.size(); i++)
                if(decks[i]->getDeckId() == deckId)
                    gasitDeck = i;

            if(gasitDeck == -1)
                 cout << "Deck-ul n-a fost gasit! Va rog alegeti inca o data optiunea dorita sau o alta optiune!\n";
            else{
                cout << "Valoarea deck-ului este: " << decks[gasitDeck]->getDeckValue() << '\n';
            }

            break;
        }
        case 12:{
            cout << "Id-ul spell-ului la care vrei sa adaugi spell damage: ";
            int spellId;

            cin >> spellId;

            int gasitSpell = -1;
            for(unsigned int i = 0; gasitSpell == -1 && i < spells.size(); i++)
                if(spells[i]->getCardId() == spellId)
                    gasitSpell = i;

            if(gasitSpell == -1)
                 cout << "Spell-ul n-a fost gasit! Va rog alegeti inca o data optiunea dorita sau o alta optiune!\n";
            else{
                cout << "Spell-ul a fost gasit! Spell damage-ul pe care vreti sa-l adaugati: ";
                int spellDamage;

                cin >> spellDamage;
                dynamic_cast<Spell*>(spells[gasitSpell])->getSpellDamage(spellDamage);
                cout << "Spell damage adaugat cu succes!\n";
            }
        }
        case 13:{
            cout << "Id-ul choose one card-ului la care vrei sa schimbi choice-ul: ";
            int chooseOneId;

            cin >> chooseOneId;

            int gasithooseOne = -1;
            for(unsigned int i = 0; gasithooseOne == -1 && i < chooseOnes.size(); i++)
                if(chooseOnes[i]->getCardId() == chooseOneId)
                    gasithooseOne = i;

            if(gasithooseOne == -1)
                 cout << "Choose one card-ul n-a fost gasit! Va rog alegeti inca o data optiunea dorita sau alta optiune!\n";
            else{
                cout << "Choose one card-ul a fost gasit! Inversare choice in curs...\n";
                dynamic_cast<ChooseOne*>(chooseOnes[gasithooseOne])->inversareChoice();
            }

            break;
        }
        default:
            cout << "Optiunea aleasa nu se afla printre cele enumerate pana acum! Va rog alegeti o alta optiune!\n";
            break;
        }
    }

    return 0;
}
