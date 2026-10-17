#include "Game.h"
#include <iostream>
#include <algorithm>
#include <cctype>

Game::Game() {

}

void Game::printMatches(std::vector<int> playerPicks, std::vector<int> kenoNumbers) {

}

void Game::displayResults() {
    std::cout <<"\n----------------------------------Results----------------------------------\n";
    std::cout << "Keno Numbers: ";
    std::sort(kenoNumbers.begin(), kenoNumbers.end());
    for (auto i:kenoNumbers) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Players: ";
    std::sort(playerNumbers.begin(), playerNumbers.end());
    for (auto i:playerNumbers) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "You matched: ";
    std::sort(matches.begin(), matches.end());
    for (auto i:matches) {
        std::cout << i << " ";
    }

    if (matches.size() > 0) {
        std::cout<<"\nMatching " << matches.size() << " of 20 numbers wins ";
        switch (matches.size()){
            case 10:
                std::cout<<"the GRAND PRIZE of $25,000";
                break;
            case 9:
                std::cout << "$2,500";
                break;
            case 8:
                std::cout<<"$250";
                break;
            case 7:
                std::cout<<"$50";
                break;
            case 6:
                std::cout<<"$10";
                break;
            case 5:
                std::cout<<"$5";
                break;
            default:
                std::cout<<"$0. Sorry, better luck next time.";
        }
    }
    else {
        std::cout << "\nSorry, you didn't have any matches.";
    }
}

void Game::playGame() {

    std::cout << "\nTo play Keno, select 10 unique (no repeats) numbers in the range of 1-80.\n\n";
    std::cout << "Let's Play Keno!\n\n";

    player.getPlayerPicks();
    keno.generateKenoNumbers();

    // Find matches
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 20; j++) {
            if(playerNumbers.at(i) == kenoNumbers.at(j)) {
                matches.push_back(playerNumbers.at(i));
            }
        }
    };
}



