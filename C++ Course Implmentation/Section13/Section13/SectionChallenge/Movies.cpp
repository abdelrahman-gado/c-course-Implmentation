#include <iostream>
#include "Movies.h"

// Constructor
Movies::Movies()
{
    movies = new std::vector<Movie>;
}

// Deep Copy Constructor
Movies::Movies(const Movies &source)
    : Movies {}
{
    *movies = *source.movies; 
}

// Move Constructor
Movies::Movies (Movies &&source)
    : movies {source.movies}
{
    source.movies = nullptr;
}


void Movies::add_movie(std::string movie_name, std::string movie_rating, int number_watches)
{
    Movie new_movie {movie_name, movie_rating, number_watches};
    movies->push_back(new_movie);
}


void Movies::increment_watches(std::string movie_name)
{
    for (Movie &m : *movies)
    {
        if (m.get_movie_name() == movie_name)
        {
            m.increment_watches();
        }
    }
}

void Movies::display_movies() const
{
    if (movies->size() == 0)
    {
        std::cout << "Sorry, no movies to display\n" << std::endl ;
    }
    else
    {
        for (const Movie &m : *movies)
        {
            std::cout << m.get_movie_name() << " - " << m.get_movie_rating() << " - " << m.get_number_watches() << std::endl;
        }
    }
}

// Destructor
Movies::~Movies()
{
    
}