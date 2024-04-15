#pragma once
#include"pch.h"

void startingScreen();

void outputPosition(int x, int y);

void color(int color);

void printMenuOptions(std::vector<std::string> menuOptions, int selectedOption);

void printSubMenuOptions(std::vector<std::string> subMenuOptions, int selectedOption);

bool subMenuStartTest(std::vector<std::string> subMenuStartTestOptions, std::vector<std::string> menuOptions);

bool subMenuGrades(std::vector<std::string> subMenuGradesOptions, std::vector<std::string> menuOptions);

void menu(std::vector<std::string> menuOptions);

