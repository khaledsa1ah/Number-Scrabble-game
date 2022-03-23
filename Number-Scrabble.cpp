/*
Name: Khaled Salah
ID: 20211033
Game: (3) Number scrabble
Assignment-1
 */

#include<bits/stdc++.h>

using namespace std;

bool correct_choice(vector<int> v, int value) {

    if (find(v.begin(), v.end(), value) != v.end())
        return true;
    else
        return false;
}

//Defining a function to check winner by checking if there's a combination of 3 numbers that equals 15
bool check_winner(vector<int> player) {
    if (player.size() > 2) {
        for (int i = 0; i < player.size() - 2; ++i) {
            for (int j = i + 1; j < player.size() - 1; ++j) {
                for (int k = j + 1; k < player.size(); ++k) {
                    if ((player[i] + player[j] + player[k]) == 15)
                        return true;
                }
            }
        }
    } else
        return false;
}

int main() {
    //# I made 2 lists for the 2 players to store their choices
    vector<int> player1;
    vector<int> player2;
    //a list of the numbers
    vector<int> nums_list = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //I made a loop to take the inputs from the players
    while (true) {
        while (true) {
            //Taking the input from the first player
            cout << "First player, Please Choose a number: ";
            vector<int> nums_list_display(nums_list.begin(), nums_list.end());
            for (int x: nums_list_display)
                cout << x << " ";
            cout << ": ";
            int First_player;
            cin >> First_player;
            //Defensive programming
            while (cin.fail()) {
                cout << "please enter valid input: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> First_player;
            }
            if (correct_choice(nums_list, First_player)) {
                player1.push_back(First_player);
                //# removing the input from the numbers list
                nums_list.erase(find(nums_list.begin(), nums_list.end(), First_player));
                break;
            }
        }
        //Checking if the first player won
        if (check_winner(player1)) {
            cout << "\nFirst Player is the winner\n";
            return 0;
        }
            //Checking draw
        else if (nums_list.empty()) {
            cout << "\nThe game is draw\n";
            return 0;
        }
        //Taking the input from the second player
        while (true) {
            cout << "Second player, Please Choose a number: ";
            vector<int> nums_list_display(nums_list.begin(), nums_list.end());
            for (int x: nums_list_display)
                cout << x << " ";
            cout << ':';
            int Second_player;
            cin >> Second_player;
            //Defensive programming
            while (cin.fail()) {
                cout << "please enter valid input: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> Second_player;
            }

            if (correct_choice(nums_list, Second_player)) {
                player2.push_back(Second_player);
                //removing the input from the numbers list
                nums_list.erase(find(nums_list.begin(), nums_list.end(), Second_player));
                break;
            }

        }
        //Checking if the second player won
        if (check_winner(player2)) {
            cout << "\nSecond Player is the winner\n";
            return 0;
        }

    }
}