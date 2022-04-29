#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

const int total_line_length {70};

struct City
{
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country
{
    std::string name;
    std::vector<City> cities;
};

struct Tours
{
    std::string title;
    std::vector<Country> countries;
};

void ruler()
{
    std::cout << "\n1234567890123456789012345678901234567890123456789012345678901234567890\n" << std::endl;
}

void display_header(std::string tour_title)
{
    int title_length = tour_title.length();
    std::cout << std::setw((total_line_length - title_length)/2) << std::right << "";
    std::cout << tour_title << std::endl;
    
    
    std::cout << std::endl << std::endl;
    
    std::cout << std::setw(20) << std::left << "Country";
    std::cout << std::setw(20) << std::left << "City";
    std::cout << std::setw(15) << std::right << "Population";
    std::cout << std::setw(15) << std::right << "Price" << std::endl;
    
    std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
}

int main() 
{
    
    Tours tours 
    { "Tour Ticket Prices from Miami",
        {
            {
                "Colombia", {
                    {"Bogota", 87780000, 400.98},
                    {"Cali", 2401000, 424.12},
                    {"Medellin", 2464000, 350.98},
                    {"Cartagena", 972000, 345.34}
                },
            },
            {
                "Brazil", {
                    {"Rio De Janiero", 13500000, 567.45},
                    {"Sao Paulo", 11310000, 975.45},
                    {"Salvador", 18234000, 855.99}
                },
            },
            {
                "Chile", {
                    {"Valdivia", 260000, 569.12},
                    {"Santiago", 7040000, 520.00}
                },
                
            },
            {
                "Argentina", {
                 {"Buenous Aires", 3010000, 728.77}
                }
            },
        }
    };
    
    // Unformatted diplay so you can see how to access the vector elements
    ruler();
    display_header(tours.title);
    
    for (auto country : tours.countries)
    {
        std::cout << std::setw(20) << std::left << country.name;
        for (size_t i {0}; i < country.cities.size(); i++)
        {
            City city = country.cities[i];
            if (i != 0)
            {
                std::cout << std::setw(20) << std::left << "";
            }
            
            std::cout << std::setw(20) << std::left << city.name;
            std::cout << std::setw(15) << std::right << city.population;
            std::cout << std::setw(15) << std::right << std::setprecision(2) << std::fixed << city.cost << std::endl;
            
        }
        std::cout << std::endl;
    }
    
    
    
    
    std::cout << std::endl << std::endl;
    
    return 0;
}