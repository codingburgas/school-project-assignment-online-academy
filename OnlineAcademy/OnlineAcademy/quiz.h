#pragma once
#include"pch.h"

class student {
public:
	int rollno;
	std::string name;
	int obt;
	double percent = 0;
	char grade = 'F';
	int score = 0;
	bool alreadyTakenTest = false;

	// Member function to calculate grade
	void calculate() {
		const char* comm;

		percent = score / 5.0 * 10;

		if (percent >= 80) {
			grade = 'A';
			comm = "Excellent";
		}
		else if (percent >= 60) {
			grade = 'B';
			comm = "Good";
		}
		else if (percent >= 40) {
			grade = 'C';
			comm = "Fair";
		}
		else {
			grade = 'F';
			comm = "Fail Do hard work..";
		}

		std::cout << "Grade: " << grade << " - " << comm << std::endl;
	}


	// Function to show data in a simple format
	void showdata() const;

	// Function to show data in tabular form
	void show_tabular() const;
};

void quiz();
