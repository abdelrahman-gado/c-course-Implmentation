#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>


class Movie
{
private:
    std::string movie_name;
    std::string movie_rating;
    int number_watches;
    
public:
    
    void set_movie_name (std::string name) { movie_name = name; }
    std::string get_movie_name () const { return movie_name; }
    
    void set_movie_rating (std::string rating) { movie_rating = rating; }
    std::string get_movie_rating () const { return movie_rating; }
    
    void set_number_watches (int number) { number_watches = number; }
    int get_number_watches () const { return number_watches; }
    
    // Constructor
    Movie(std::string name_val, std::string rating_val, int number_val);
    
    // Deep Copy-Constructor
    Movie(const Movie &source);
    
    void increment_watches();
    
    // Destructor
    ~Movie();
};

#endif // _MOVIE_H_
