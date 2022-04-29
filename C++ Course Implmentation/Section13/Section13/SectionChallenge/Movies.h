#ifndef _MOVIES_H_
#define _MOVIES_H_

#include "Movie.h"
#include <vector>
#include <string>

class Movies
{
private:
    std::vector<Movie> *movies;
    
public:
    
    // Constructor
    Movies();
    
    // Deep Copy Constructor
    Movies(const Movies &source);
    
    // Move Constructor
    Movies(Movies &&source);
    
    std::vector<Movie> get_movies () { return *movies; }
    
    
    void add_movie (std::string movie_name, std::string movie_rating, int number_watches);
    void increment_watches (std::string movie_name);
    void display_movies () const;
    
    
    // Destructor
    ~Movies();
};

#endif // _MOVIES_H_
