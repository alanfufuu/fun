#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

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

int deal(vector<int> &deck) {
    int temp = deck[deck.size() - 1];
    deck.pop_back();
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

enum handRankings {
    highcard,
    pair,
    tpair,
    set,
    straight,
    flush,
    fhouse,
    quads,
    sflush,
    rflush
};

//use switch statement for output

string publicCards(vector<int> &deck){
    vector<int> pubCards;
    
}

int main() {
    vector<int> deck;
    createDeck(deck);
    shuffle(deck);

    vector<vector<int>> newDeck;

}

