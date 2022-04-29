#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <iterator>
#include <fstream>

class Song
{
    friend std::ostream &operator<< (std::ostream &os, const Song &s);
private:
    std::string name;
    std::string artist;
    int rating;

public:
    Song () = default;
    Song (std::string name, std::string artist, int rating)
        : name {name}, artist {artist}, rating {rating} {}
    std::string get_name() const
    {
        return name;
    }
    
    std::string get_artist() const
    {
        return artist;
    }
    
    int get_rating() const
    {
        return rating;
    }
    
    bool operator< (const Song &rhs) const
    {
        return (this->name < rhs.name);
    }
    
    bool operator== (const Song &rhs) const
    {
        return (this->name == rhs.name);
    }
};

std::ostream &operator<< (std::ostream &os, const Song &s)
{
    os << std::setw(20) << std::left << s.name
        << std::setw(30) << std::left << s.artist
        << std::setw(2) << std::left << s.rating;
        return os;
}

void display_menu()
{
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "E - play Last Song" << std::endl;
    std::cout << "A - Add and Play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===========================================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";    
}

void play_current_song (const Song &song)
{
    std::cout << "Playing:" <<std::endl;
    std::cout << song << std::endl;
}

void display_playlist (const std::list<Song> &playlist, const Song &current_song)
{
    std::for_each(playlist.begin(), playlist.end(), [](Song song) { std::cout << song << std::endl;});
    std::cout << "Current song:" << std::endl;
    std::cout << current_song << std::endl;
}

void play_first_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song_it)
{
    current_song_it = playlist.begin();
    std::cout << "Playing first song" << std::endl;
    play_current_song(*current_song_it);
}

void play_next_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song_it)
{
    std::cout << "Playing next song" << std::endl;
    current_song_it++;
    if (current_song_it == playlist.end())
    {
        current_song_it = playlist.begin();
        std::cout << "Wrapping to start of playlist" << std::endl;
    }
    play_current_song(*current_song_it);
    
}

void play_previous_song (std::list<Song> &playlist, std::list<Song>::iterator &current_song_it)
{
    std::cout << "Playing previous song" << std::endl;
    if (current_song_it == playlist.begin())
    {
        current_song_it = playlist.end();
        std::cout << "Wrapping to end of playlist" << std::endl;
    }
    current_song_it--;
    play_current_song(*current_song_it);
}

void save_changes(std::list<Song> &playlist)
{
    std::ofstream playlist_file;
    playlist_file.open("Playlist.txt", std::ios::out);
    if (!playlist_file.is_open())
    {
        throw std::string {"Sorry, the file is not opened for writing"};
    }
    std::for_each(playlist.begin(), playlist.end(), 
    [&playlist_file](Song song) 
    {  
        playlist_file << song.get_name() << "-" << song.get_artist() << "-" << song.get_rating() << std::endl;
    });
    playlist_file.close();
}


void add_song (std::list<Song> &playlist, std::list<Song>::iterator &current_song_it)
{
    std::cout << "Adding and playing new song" << std::endl;
    std::string name {};
    std::string artist {};
    int rating {};
    std::cout << "Enter song name: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, name);
    std::cout << "Enter song artist: ";
    getline(std::cin, artist);
    std::cout << "Enter your rating (1-5): ";
    std::cin >> rating;
            
    playlist.emplace(current_song_it, name, artist, rating);
    current_song_it--;
    try
    {
        save_changes(playlist);
    }
    catch (std::string &ex)
    {
        std::cout << ex << std::endl;
    }
    play_current_song(*current_song_it);
}

void play_last_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song_it)
{
    current_song_it = playlist.end();
    current_song_it--;
    std::cout << "Playing last song" << std::endl;
    play_current_song(*current_song_it);
}


std::list<Song> load_playlist (std::string file_name)
{   
    std::list<Song> playlist;
    std::ifstream playlist_file;
    playlist_file.open(file_name, std::ios::in);
    if (!playlist_file.is_open())
    {
        throw std::string {"Sorry, the file is not opened for reading"};
    }
    
    std::string line {};
    
    while (getline(playlist_file, line))
    {
        std::string song_name {};
        std::string song_artist {};
        int rating {};
        
        int name_limit = line.find("-");
        song_name = line.substr(0, name_limit);
        int artist_limit = line.find("-", name_limit+1);
        int length = artist_limit - name_limit - 1;
        song_artist = line.substr(name_limit+1,  length);
        rating = std::stoi(line.substr(artist_limit+1));
        
        
        playlist.emplace_back(song_name, song_artist, rating);
    }
    
    playlist_file.close();
    
    return playlist;
}


int main() 
{
    std::list<Song> playlist;
    try
    {
        playlist = load_playlist("Playlist.txt");
    }
    catch (std::string &ex)
    {
        std::cout << ex << std::endl;
    }
    
    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);
    
    char selection {};
    
    do
    {
        display_menu();
        std::cin >> selection;
        selection = std::toupper(selection);
        
        switch(selection)
        {
            case 'F':
                play_first_song(playlist, current_song);
                break;
            case 'N':
                play_next_song(playlist, current_song);
                break;
            case 'P':
                play_previous_song (playlist, current_song);
                break;
            case 'A':
                add_song(playlist, current_song);
                break;
            case 'L':
            case 'l':
                display_playlist(playlist, *current_song);
                break;
            case 'E':
                play_last_song(playlist, current_song);
            default:
                continue;
        }
    }
    while(selection != 'Q');
    
    
    return 0;
}