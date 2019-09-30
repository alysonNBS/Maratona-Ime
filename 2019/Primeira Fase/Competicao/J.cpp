#include <iostream>
#include <algorithm>

using namespace std;

const char deck[] = {'A','1','2','3','4','5','6','7','8','9','D','Q','J','K'};
const int deck_size = 14;

class Player {
    bool withJoker;
    bool discardJoker;
    int card[130]; // array to use like a map <char, int> 

    char __discardJoker() {
        withJoker = discardJoker = false;
        return 'C';
    }

    void __setJoker() {
        withJoker = true;
        discardJoker = false;
    }

public:
    Player() {
        fill(card, card+130, 0);
        withJoker = discardJoker = false;
    }

    bool isWinner() {
        bool loser = false;

        // check if everyone card of deck appear in cards of player and,
        // if a card appear in cards of player, it appears exactly 4 times
        for(int i=0; i<deck_size; i++)
            if(card[deck[i]] && card[deck[i]] != 4)
                loser = true;

        return !loser && !withJoker;
    }

    char discardCard() {
        if(withJoker && discardJoker) {
            return __discardJoker();
        }
        if(withJoker)
            discardJoker = true;
        
        int lowest_occurrence = 10;
        int least_occurring;

        for(int i=0; i<deck_size; i++)
            if(lowest_occurrence > card[deck[i]] && card[deck[i]])
                lowest_occurrence = card[deck[i]];
        
        for (int i = 0; i < deck_size; i++)
            if(lowest_occurrence == card[deck[i]]) {
                least_occurring = deck[i];
                card[deck[i]]--;
                break;
            }

        return least_occurring;
    }

    void setCard(char c) {
        if(c == 'C') __setJoker();
        else card[c]++;
    }
};

int main() {
    int N, K;
    int winner = 0;
    cin >> N >> K;

    Player player[N+1];
    player[K].setCard('C');

    for(int i=1; i<=N; i++) {
        char cards[5];
        cin >> cards;

        for(int j=0; cards[j]; j++)
            player[i].setCard(cards[j]);
    }

    for(int i=1; i<=N; i++)
        if(player[i].isWinner()) {
            winner = i;
            break;
        }
    
    while(!winner) {
        if(player[K].isWinner())
            winner = K;
        
        char discarded = player[K].discardCard();

        if(player[K].isWinner())
            winner = K;
        
        K = ( (K+1) % (N+1) ? (K+1) : 1 );

        player[K].setCard(discarded);
    }

    cout << winner << endl;

    return 0;
}