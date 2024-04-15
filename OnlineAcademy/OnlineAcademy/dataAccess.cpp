#include "dataAccess.h"


bool findStudent(const std::string& name, Student& student)
{
    std::ifstream file("Scores.txt");
    std::string line;
    while (getline(file, line))
    {
        if (line.find(name) != std::string::npos)
        {
            student.name = name;
            student.score = stoi(line.substr(line.find_last_of(' ') + 1));
            return true;
        }
    }
    return false;
}

void updateStudent(const Student& student)
{
    std::ifstream file("Scores.txt");
    std::vector <std::string> lines;
    std::string line;
    while (getline(file, line))
    {
        if (line.find(student.name) == std::string::npos)
        {
            lines.push_back(line);
        }
        else
        {
            // Update the student's score in the line
            lines.push_back(student.name + " " + std::to_string(student.score));
        }
    }
    file.close();

    std::ofstream outFile("Scores.txt", std::ios::trunc); // Overwrite the file with updated contents
    for (const auto& l : lines)
    {
        outFile << l << std::endl;
    }
    outFile.close();
}