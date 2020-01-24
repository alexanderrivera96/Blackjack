/**
* This program simulates a Blackjack game
* @author arivera
* @version 1.0
* @since 01/21/2020
*/
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>


using namespace std;


void Play();
void Deal();
void rules();
void singleDeal(int, int&);
void scoring(int&, int);
void checkScore(int&, int&);
void finalScore(int);


int main()
{
    cout << "***************************************************" << endl;
    cout << "                 BLACK JACK TABLE                  " << endl;
    cout << "***************************************************" << endl;

    Play();

    return 0;
}


void Play(){
    char response;

    cout << "\n\t   Would you like to play?\n\t'y': Yes  'q': Quit  'r': Rules" << endl;
    cin >> response;

    if(response == 'y'){
       Deal();
    }
    else if(response == 'q'){
        cout << "\nCOME AGAIN" << endl;
    }
    else if(response == 'r'){
        rules();
        Play();
    }
} // end Play()


void rules(){
    cout << "\t\t\t------------------" << endl;
    cout << "\t\t\tOBJECT OF THE GAME\n\t\t\t------------------\n\tEach participant attempts to beat the dealer by getting a" << endl;
    cout << "\tcount as close to 21 as possible, without going over 21." << endl;
    cout << "\t\t\t--------------" << endl;
    cout << "\t\t\tSCORING SYSTEM\n\t\t\t--------------" << endl;
    cout << "\tPicture Cards(JACK, QUEEN & KING): 10 points" << endl;
    cout << "\tACE: 1 or 11 points, whichever is better." << endl;
    cout << "\tOther cards: Their numerical value." << endl;
}


void Deal(){

    int static userScore = 0;
    int static dealerScore = 0;
    string suit[4] = {"Hearts","Clubs","Spades","Diamonds"};
    string value[13] = {"Ace","Two","Three","Four","Five","Six","Seven",
                        "Eight","Nine","Ten","Jack","Queen","King"};

    int playerSuitValue, playerCValue;
    int dealerSuitValue, dealerCValue;
    char var;
    bool valid;

    srand((unsigned)time(0)); // Seed the random number generator

    valid = false;

    while(!valid){
        playerSuitValue = rand() % 4;
        playerCValue = rand() % 13;
        dealerSuitValue = rand() % 4;
        dealerCValue = rand() % 13;

        // Accumulating the scores based on the value of the card.
        scoring(userScore, playerCValue);
        scoring(dealerScore, dealerCValue);

        // Displaying the card dealt for both the user and deal along with their scores
        cout << "\nUser's hand: " << value[playerCValue] << " of " << suit[playerSuitValue] << endl;
        cout << "Dealer's hand: " << value[dealerCValue] << " of " << suit[dealerSuitValue] << endl;
        cout << "\nUser's current score: " << userScore << endl;
        cout << "Dealer's current score: " << dealerScore << endl;


        // check scores after each dealt hand
        checkScore(userScore, dealerScore);


        // Asking user if he/she wishes to draw of skip his/her turn
        var = ' ';

        while(var != 'h'){
            cout << "\nHit or Stay" << endl;
            cin >> var;
            if(var == 's')
                singleDeal(userScore, dealerScore);
        } // end inner while



    } // end while

} // end Deal()


void singleDeal(int userScore, int &dealerScore){
    string suit[4] = {"Hearts","Clubs","Spades","Diamonds"};
    string value[13] = {"Ace","Two","Three","Four","Five","Six","Seven",
                        "Eight","Nine","Ten","Jack","Queen","King"};

    int suitValue, cValue;

    srand((unsigned) time(0)); // Seed the random number generator

    suitValue = rand() % 4;
    cValue = rand() % 13;

    // Accumulating the scores based on the value of the card.
    scoring(dealerScore, cValue);

    // Displaying the card dealt for the dealer along with the score
    cout << "User skipped his turn." << endl;
    cout << "User's current score: " << userScore << endl;

    cout << "Dealer's hand: " << value[cValue] << " of " << suit[suitValue] << endl;
    cout << "Dealer's current score: " << dealerScore << endl;
} // end singleDeal


void scoring(int &score, int value){

    // if card value is Ace
    if(value == 0){
        // card value is 1 or 11, whichever is better.
        if(score < 10){
            score += 11;
        }
        else{
            score += 1;
        }
    }
    // if card value is a Picture card
    else if(value == 10 || value == 11 || value == 12){
        score += 10;
    }
    // if card is a basic numerical card
    else{
        value += 1;
        score += value;
    }
} // end scoring()


void checkScore(int &userScore, int &dealerScore){
    if(userScore >= 21){
        if(userScore == 21){
            cout << "\nBLACKJACK\nUser Wins." << endl;
            exit(0);
        }
        else if(userScore > dealerScore){
            cout << "\nBLACKJACK\nDealer Wins." << endl;
            exit(0);
        }
    }
    else if(dealerScore >= 21){
        if(dealerScore == 21){
            cout << "\nBLACKJACK\nDealer Wins." << endl;
            exit(0);
        }
        else if(dealerScore > userScore){
            cout << "\nBLACKJACK\nUser Wins." << endl;
            exit(0);
        }
    }
} // end checkScore

/*
* This program works as expected
*/
