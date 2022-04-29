#include <iostream>
#include <fstream>
#include <iomanip>

void print_header ()
{
    std::cout << std::setw(15) << std::left << "Student"
              << std::setw(15) << std::right << "Score" << std::endl;
    
    std::cout << std::setw(30) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
}

void print_footer (double average)
{
    std::cout << std::setw(15) << std::left << "Average score";
    std::cout << std::setw(13) << std::setprecision(1) << std::fixed << std::right << average << std::endl;
    
}

void print_student (const std::string &name, int score)
{
    std::cout << std::setw(15) << std::left << name;
        std::cout << std::setw(12) << std::right << score << std::endl;
}

int calculate_score (std::string student_answer, std::string answer_key)
{
    int score {answer_key.length()};
    for (int i {0}; i < answer_key.length(); i++)
    {
        if (student_answer[i] != answer_key[i])
            score--;
    }
    
    return score;
}


int main() 
{
    
    std::ifstream in_file;
    in_file.open("responses.txt");
    
    if (!in_file)
    {
        std::cerr << "Problem Opening File" << std::endl;
        return 1;
    }
    
    std::string answer_key {};
    in_file >> answer_key;
    
    std::string student_name {};
    std::string student_answer {};
    
    int total_score {0};
    int count_students {0};
    
    print_header();
    
    while (!in_file.eof())
    {
        in_file >> student_name >> student_answer;
        int score = calculate_score(student_answer, answer_key);
        
        total_score += score;
        count_students++;
        
        print_student(student_name, score);
    }
    
    std::cout << std::setw(30) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
    
    double average_score {};
    if (count_students != 0)
    {
        average_score = static_cast<double>(total_score) / count_students;
    }
    
    print_footer(average_score);
    
    in_file.close();
    
    std::cout << std::endl << std::endl;
    
    return 0;
}