#include "Movie.h"

// Constructor
Movie::Movie (std::string name_val, std::string rating_val, int number_val)
    : movie_name {name_val}, movie_rating {rating_val}, number_watches {number_val}
{
    
}

// Copy-Constructor
Movie::Movie (const Movie &source)
    : Movie {source.movie_name, source.movie_rating, source.number_watches}
{
    
}

Movie::~Movie()
{

}

void Movie::increment_watches()
{
    number_watches++;
}
