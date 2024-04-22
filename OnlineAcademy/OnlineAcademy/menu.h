#pragma once
#include"pch.h"
#include "quiz.h"
#include "quiz_10grade.h"

// Function to display the starting screen and handle user input for name entry and checking for existing students
void startingScreen();

//Displays the menu options for the student
void displayMenu(student currentStudent);

// Function to set the cursor position on the console window
void outputPosition(int x, int y);

// Function to change text color in the console window
void color(int color);

// Function to print the main menu options
void printMenuOptions(std::vector<std::string> menuOptions, int selectedOption);

// Function to print the submenu options
void printSubMenuOptions(std::vector<std::string> subMenuOptions, int selectedOption);

// Function to display the main menu and handle user input
void menu(std::vector<std::string> menuOptions, student currentStudent);
