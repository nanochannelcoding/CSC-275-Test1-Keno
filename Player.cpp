#include "Player.h"
#include <iostream>
#include <algorithm>

void Player::inputplayernumbers() {
    char again = 'y';
    bool error;
    int temp=0;
    std::vector <int> playerNumbers, kenoNumbers, matches;;

    // Get player picks
    for (int i=0;i<10;i++){
        error = false;
        std::cout << "Enter your pick #" << i+1 <<": ";
        std::cin >> temp;
        if (std::cin.fail())
        {
            error = true;
            std::cin.clear();
            std::cin.ignore(100,'\n');
            std::cout << "Invalid data input! Try again. ";
        }
        else if (temp > 80)
        {
            error = true;
            std::cout << temp << " is out of range! Try again. ";
        }
        else if (std::find(playerNumbers.begin(), playerNumbers.end(), temp) != playerNumbers.end()) {
            error = true;
            std::cout << temp << " was already picked! Try again. ";
        }
        if (error)
            i--;
        else
            playerNumbers.push_back(temp);
    }
}

std::vector<int> Player::getPlayernumbers() {

}

void Player::printPlayernumbers() {

}

void Player::clearPlayernumbers() {

}
