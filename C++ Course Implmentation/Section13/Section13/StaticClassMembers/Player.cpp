#include "Player.h"


int Player::num_players {0};

int Player::get_num_players() 
{
    return num_players;
}


// Constructor
Player::Player (std::string name_val, int health_val, int xp_val)
    : name {name_val}, health {health_val}, xp {xp_val}
{
    ++num_players;
}

// Copy Constructor (Shallow copy)
Player::Player (const Player &source)
    : Player {source.name, source.health, source.xp}
{
    
}

Player::~Player ()
{
    --num_players;
}
