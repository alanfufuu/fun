#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/* 
deals you two cards out of a 52 card deck
lets you know one dealer card
valid actions: hit, stand
*/

void createDeck(vector<int> &deck) {
    vector<int> intsuits = {0, 100, 200, 300};
    vector<int> intnum = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for(int i = 0; i < intsuits.size(); i++) {
        for(int j = 0; j < intnum.size(); j++) {
            int temp = intnum[j] + intsuits[i];
            deck.push_back(temp);
        }
    } // want to create a deck vector like <101> <102> ... <201> ...
}

string valToString(int value) {
    vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
    vector<string> num = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    string suit = suits[value / 100];
    string card = num[value % 100];
    string temp = card + " of " + suit;
    return temp;
}

int valOfCard(int x) {
    int value = x % 100 + 1;
    if (value > 10) {
        value = 10;
    }
    if (value == 1) {
        value = 11;
    }
    return value;
}

void shuffle(vector<int> &deck) {
    srand(time(0));
    for(int i = 0; i < deck.size(); i++) {
        int j = rand() % deck.size();
        int temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

int deal(vector<int> &deck) {
    int temp = deck[deck.size() - 1];
    deck.pop_back();
    shuffle(deck);
    return temp;
}

void playerAction(vector<int> &deck, int card1, int card2, int &totalValue);

int hit(vector<int> &deck, int card1, int card2, int &totalValue) {
    int newCard = deal(deck);
    totalValue += valOfCard(newCard);
    if (totalValue > 21) {
        cout << "You were dealt the " <<  valToString(newCard);
        cout << ". Your total is now " << totalValue << ". You have busted." << endl;
        return 1;
    } else {
        cout << "You were dealt the " <<  valToString(newCard);
        cout << ". Your total is now " << totalValue << ". Would you like to hit or stand?" << endl;
        playerAction(deck, card1, card2, totalValue);
    }
    return 0;
}

void playerAction(vector<int> &deck, int card1, int card2, int &totalValue) {
    string action;
    cin >> action;
    while (action != "hit" && action != "stand") {
        cout << "Invalid input. Input must be 'hit' or 'stand'. Please state your action again." << endl;
        cin >> action;
    }
    if (action == "double") {
        hit(deck, card1, card2, totalValue);
    } else if (action == "hit") {
        hit(deck, card1, card2, totalValue);
    } else if (action == "stand") {
        return;
    }
}

int dealerAction(int dealercard, vector<int> &deck) {
    vector<int> dealerCards;
    int dealerValue = valOfCard(dealercard);
    while(dealerValue < 17) {
        int newDealerCard = deal(deck);
        dealerCards.push_back(newDealerCard);
        dealerValue += valOfCard(newDealerCard);
    }
    if(dealerValue <= 21 && dealerValue >= 17) {
        cout << "The dealer was dealt the ";
        if(dealerCards.size() >= 2) {
            for(int i = 0; i < dealerCards.size() - 1; i++){
                cout << "the " << valToString(dealerCards[i]) << ",";
            }
            cout << " and the " << valToString(dealerCards[dealerCards.size() -1]) << ".";
            cout << " Their total is " << dealerValue << "." << endl;
            return 1;
        } else {
            cout << valToString(dealerCards[0]) << ".";
            cout << " Their total is " << dealerValue << "." << endl;
        }
    }
    if(dealerValue > 21) {
        cout << "The dealer was dealt ";
        for(int i = 0; i < dealerCards.size() - 1; i++){
            cout << "the " << valToString(dealerCards[i]) << ",";
        }
        cout << " and the " << valToString(dealerCards[dealerCards.size() -1]) << ".";
        cout << " Their total is " << dealerValue << ". Since they busted, you win!";
        return 1;
    }
    return dealerValue;
}

int main() {
    vector<int> deck;
    createDeck(deck);
    shuffle(deck);
    int card1 = deal(deck);
    int card2 = deal(deck);
    int dealercard = deal(deck);
    int totalValue = valOfCard(card1) + valOfCard(card2);

    cout << "Your cards are the " << valToString(card1) << " and the " << valToString(card2) << ". Your total value is " << totalValue << "." << endl;
    cout << "The dealer is showing the " << valToString(dealercard) << ". Would you like to hit or stand?" << endl;

    playerAction(deck, card1, card2, totalValue);

    int dvalue = dealerAction(dealercard, deck);
    cout << dvalue << endl;
    return 0;
}

//g++ -std=c++11 blackjack.cpp