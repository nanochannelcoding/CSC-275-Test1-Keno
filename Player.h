#ifndef CSC_275_TEST1_KENO_PLAYER_H
#define CSC_275_TEST1_KENO_PLAYER_H
#include <vector>

class Player {
private:
    std::vector<int> m_playerNumbers;
public:
    void inputplayernumbers();
    std::vector<int>getPlayernumbers();
    void printPlayernumbers();
    void clearPlayernumbers();
};


#endif //CSC_275_TEST1_KENO_PLAYER_H