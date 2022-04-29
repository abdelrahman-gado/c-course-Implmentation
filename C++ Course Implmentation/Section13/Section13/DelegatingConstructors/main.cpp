#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    std::string name;
    int health;
    int xp;

public:
    
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

// Delegating Constructor
Player::Player () 
    : Player {"None", 0, 0} // Delegation
{
    cout << "No-args constructor" << endl;
}

// Delegating Constructor
Player::Player (std::string name_val)
    : Player {name_val, 0, 0} // Delegation
{
    cout << "One arg constructor" << endl;
}

// Delegated Constructor
Player::Player (std::string name_val, int health_val, int xp_val) 
    : name {name_val}, health {health_val}, xp {xp_val}
{
    cout << "three args Constrcutor" << endl;
}


int main() 
{
    Player empty;
    Player frank {"Frank"};
    Player villain {"villain", 100, 55};
    return 0;
}