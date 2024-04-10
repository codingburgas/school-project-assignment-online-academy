#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

struct Student
{
    std::string name;
    int score;
};

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
    std::vector<std::string> lines;
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

// Output coordinates manipulation function
void outputPosition(int x, int y)
{
    COORD position;
    position.X = x;
    position.Y = y;
    if (SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position))
    {
        return;
    }
}

// Output color manipulation function
void color(int color)
{
    if (SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color))
    {
        return;
    }
}

void printMenuOptions(std::vector<std::string> menuOptions, int selectedOption)
{
    for (int i = 0; i < 3; i++)
    {
        // Print arrow before selected option
        if (i == selectedOption)
        {
            outputPosition(1, i + 1);
            std::cout << "-> " << menuOptions[i];
        }

        // Print space before not selected option
        else
        {
            outputPosition(1, i + 1);
            std::cout << "   " << menuOptions[i];
        }
    }
}

void menu(std::vector<std::string> menuOptions)
{
    int selectedOption = 0; // By default when you open the app you are hovering at the first menu option
    char pressedKey = ' ';
    bool exitStatement = true;

    printMenuOptions(menuOptions, selectedOption);

    while (exitStatement)
    {
        pressedKey = _getch();

        // Moving up through the menu
        if (selectedOption != 0 && pressedKey == (char)72)
        {
            selectedOption--;
        }

        // Moving down through the menu
        if (selectedOption != 2 && pressedKey == (char)80)
        {
            selectedOption++;
        }

        printMenuOptions(menuOptions, selectedOption);

        // Choosing menu option
        if (pressedKey == '\r')
        {
            switch (selectedOption)
            {
                // Start game
            case 0:
                system("CLS");
                std::cout << "Start";
                break;

                // Rules
            case 1:
                system("CLS");
                std::cout << "Statistics";
                break;

                // Exit
            case 2:
                exitStatement = false;
                system("CLS");
                std::cout << "Press any key to exit";
                break;

            default:
                break;
            }
        }
    }
}
int main()
{
    Student student;
    std::cout << "Enter your name before starting the quiz: ";
    std::cin >> student.name;

    Student existingStudent;
    if (findStudent(student.name, existingStudent))
    {
        char choice;
        std::cout << "This name is already used. Is that you? (y/n): ";
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            std::cout << "Enter your new score: ";
            std::cin >> student.score;
            updateStudent(student);
        }
        else
        {
            std::cout << "Please choose a different name." << std::endl;
            std::cin >> student.name;

            std::ofstream myfile("Scores.txt", std::ios::app);
            student.score = 0;
            myfile << student.name << " " << student.score << std::endl;
            myfile.close();
        }
    }
    else
    {
        // New student, proceed to add them to the file
        std::ofstream myfile("Scores.txt", std::ios::app);
        // Assume a default score or some logic to determine the score
        student.score = 0; // Placeholder
        myfile << student.name << " " << student.score << std::endl;
        myfile.close();
    }

    system("CLS");

    std::vector<std::string> menuOptions = { "Start Quiz", "Quiz Statistics", "Quit" };
    menu(menuOptions);
}