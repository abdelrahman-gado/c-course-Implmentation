#include <iostream>
#include "Movies.h"
#include "Movie.h"
#include <string>

using namespace std;

bool is_movie_exists(Movies &movies, std::string movie_name);
void add_movie(Movies &m, string name, string rating, int watches);
void incr_movie(Movies &m, string name);


int main()
{
    Movies my_movies;
    
    my_movies.display_movies();
    
    add_movie (my_movies, "Big", "PG-13", 2);
    add_movie (my_movies, "Star Wars", "PG", 5);
    add_movie (my_movies, "Cinderella", "PG", 7);
    
    my_movies.display_movies();
    
    cout << "==================================" << endl;
    
    add_movie (my_movies, "Cinderella", "PG", 7);
    add_movie (my_movies, "Ice Age", "PG", 12);
    
    cout << "==================================" << endl;
    
    my_movies.display_movies();
    
    cout << "==================================" << endl;
    
    incr_movie(my_movies, "Big");
    incr_movie(my_movies, "Ice Age");
    
    cout << "==================================" << endl;
    
    my_movies.display_movies();
    
    cout << "==================================" << endl;
    
    incr_movie(my_movies, "XXXX");
    
    return 0;
}

void add_movie(Movies &m, string name, string rating, int watches)
{
    if (!is_movie_exists(m, name))
    {
        m.add_movie(name, rating, watches);
        cout << name << " is added to the movies collection" << endl;
    }
    else
    {
        cout << "Sorry, " << name << " is already exists in movies collection." << endl;
    }
}

void incr_movie(Movies &m, string name)
{
    if (is_movie_exists(m, name))
    {
        m.increment_watches(name);
        cout << name << " number of watches incremented" << endl;
    }
    else
    {
        cout << "Sorry, the movie " << name << " is not exist in the movies collection." << endl;
    }
    
}

bool is_movie_exists(Movies &movies, std::string movie_name)
{
    for (Movie m : movies.get_movies())
    {
        if (m.get_movie_name() == movie_name)
        {
            return true; // The moive exists in movies collection.
        }
    }
    
    return false;  // The movie is not in the movies collection.
}