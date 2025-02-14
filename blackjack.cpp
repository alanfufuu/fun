#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/* 
deals you two cards out of a 52 card deck
lets you know one dealer card
valid actions: double, hit, stand
*/


void createDeck(vector<string> &deck) {
    vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
    vector<string> num = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    for(int i = 0; i < suits.size(); i++) {
        for(int j = 0; j < num.size(); j++) {
            string temp = num[j] + " of " + suits[i];
            deck.push_back(temp);
        }
    } // want to create a deck vector like <Ace of Spades> <2 of Spades> ...
}

void shuffle(vector<string> &deck) {
    srand(time(0));
    for(int i = 0; i < deck.size(); i++) {
        int j = rand() % deck.size();
        string temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

string deal(vector<string> &deck) {
    string temp = deck[deck.size() - 1];
    deck.pop_back();
    shuffle(deck);
    return temp;
}

int main() {
    vector<string> deck;
    createDeck(deck);
    shuffle(deck);
    cout << "Your cards are the " << deal(deck) << " and the " << deal(deck) << "." << endl;
    cout << "The dealer is showing the " << deal(deck) << ". Would you like to double, hit, or stand?" << endl;
    string action;
    cin >> action;
    while (action != "double" && action != "hit" && action != "stand") {
        cout << "Invalid input. Input must be 'double', 'hit', or 'stand'. Please state your action again." << endl;
        cin >> action;
    }
    // if (action == "double") {
    //     dble();
    // } else if (action == "hit") {
    //     hit();
    // } else if (action == "stand") {
    //     stand();

    return 0;
}