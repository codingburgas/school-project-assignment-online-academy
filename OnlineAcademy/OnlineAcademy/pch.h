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
	int point = 0;
	int myarr = 0;
	int rollno;
	char name[50];
	//void calculate();	//function to calculate grade
	int obt;
	double score;
	const char* comm;
	void calculate();	//function to calculate grade
	void Result();
	int alreadyTakenTest;
	char grade;
	double per;
	void getdata();		//function to accept data from user
	void showdata() const;	//function to show data on screen
	void show_tabular() const;
};
