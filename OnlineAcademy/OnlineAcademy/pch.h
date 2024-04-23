#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdio>
#include <ctime>

struct question
{
	std::string questions;
	std::string answer1;
	std::string answer2;
	std::string answer3;
	std::string answer4;
	char yourAnswer;
};

class student
{
public:
	int pointTenth = 0;
	int pointNinth = 0;
	std::string name;
	//void calculate();	//function to calculate grade
	double score;
	int alreadyTakenTest;
	char grade;
};
