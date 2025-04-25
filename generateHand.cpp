#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
//generate 5 cards and determine best hand

//enum and switch?

class deck {
    public:
    deck();
    void shuffle();
    void deal(int n);
    void valToCard(vector<int> cards);
    vector<int> getDealt();
    void getRanking(vector<int> cards);

    private:
    vector<int> suits = {100, 200, 300, 400};
    vector<int> value = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    vector<int> newDeck;
    vector<int> dealt;

};
deck::deck() {
    for(int s : suits) {
        for(int v : value) {
            newDeck.push_back(s + v);
        }
    }
}

void deck::shuffle() {
    srand(time(0));
    for(int i = 0; i < 52; i++) {
        int j = rand() % 52;
        swap(newDeck[i], newDeck[j]);
    }
}

void deck::deal(int n) {
    dealt.clear();
    for(int i = 0; i < n; i++) {
        dealt.push_back(newDeck[i]);
        cout << newDeck[i] << " "; //delete later
    }
    shuffle();
    cout << endl;
}

void deck::valToCard(vector<int> cards) {
    enum Suits {
        Clubs = 1,
        Diamonds, 
        Hearts,
        Spades 
    };

    enum Val {Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

    for(int card : cards) {
        int nsuit = card / 100;
        int nrank = card % 100;

        string suit;
        string rank;
        switch(nsuit) {
            case Clubs: suit = "Clubs"; break;
            case Diamonds: suit = "Diamonds"; break;
            case Hearts: suit = "Hearts"; break;
            case Spades: suit = "Spades"; break;
        }
        switch(nrank) {
            case Ace: rank = "Ace"; break;
            case King: rank = "King"; break;
            case Queen: rank = "Queen"; break;
            case Jack: rank = "Jack"; break;
            default: rank = to_string(nrank);
        }
        cout << rank << " of " << suit << endl; // delete later
    }
}

vector<int> deck::getDealt() {
    return dealt;
}

void deck::getRanking(vector<int> cards) {
    enum handRankings{
        HighCard = 1,
        Pair,
        TwoPair,
        Set,
        Straight,
        Flush,
        FullHouse,
        Quads,
        StraightFlush,
        RoyalFlush
    };
    //determine if there are duplicates and number
    //determine flush
    sort(cards.begin(), cards.end());
    int handRank;
    vector<int> suits;
    vector<int> rank;
    int size = cards.size();
    for(int i = 0; i < size; i++) {
        suits.push_back(cards[i] / 100);
    }
    for(int j = 0; j < size; j++) {
        rank.push_back(cards[j] % 100);
    }

    

    
}






int main() {
    deck deck1;
    deck1.shuffle();
    deck1.deal(2);
    deck1.valToCard(deck1.getDealt());
    deck1.getRanking(deck1.getDealt());
    return 0;
}