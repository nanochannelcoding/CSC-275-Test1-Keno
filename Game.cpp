#include "Game.h"
#include <iostream>
#include <algorithm>

Game::Game() {
}

void Game::printMatches(std::vector<int> playerPicks, std::vector<int> kenoNumbers) {
    // Find matches
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 20; j++) {
            if(playerPicks.at(i) == kenoNumbers.at(j)) {
                m_matches.push_back(playerPicks.at(i));
            }
        }
    }
}

void Game::displayResults() {
    // Display results
    std::cout <<"\n----------------------------------Results----------------------------------\n";
    m_keno.printKenoNumbers();
    m_player.printPlayerNumbers();

    std::cout << "You matched: ";

    std::sort(m_matches.begin(), m_matches.end());
    for (auto i : m_matches) {
        std::cout << i << " ";
    }

    if (m_matches.size() > 0) {
        std::cout<<"\nMatching " << m_matches.size() << " of 20 numbers wins ";
        switch (m_matches.size()){
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
}
void Game::playGame() {
    char again = 'y';
    do {
        std::cout << "\nTo play Keno, select 10 unique (no repeats) numbers in the range of 1-80.\n\n";
        std::cout << "Let's Play Keno!\n\n";

        m_player.inputPlayerNumbers();
        m_keno.generateNumbers();

        printMatches(
        m_player.getPlayerNumbers(), m_keno.getKenoNumbers()
        );
        displayResults();


        std::cout << "\n\nPlay again? (y/n): ";
        std::cin >> again;

        m_player.clearPlayerNumbers();
        m_keno.clearKenoNumbers();
        m_matches.clear();
        }
    while (tolower(again) == 'y');
        std::cout << "\nTHANKS FOR PLAYING!!\n";
    }