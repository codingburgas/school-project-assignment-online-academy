#include "quiz.h"

	double duration;
	double maxtime = 60;
	
	int point = 0;
	int myarr = 0;
class student
{
	int rollno;
	char name[50];
	//void calculate();	//function to calculate grade
	int obt;
	double per;
	char grade;

	void calculate();	//function to calculate grade
	void Result();

public:
	void showdata() const;	//function to show data on screen
	void show_tabular() const;
}; //class ends here

void student::calculate()
{
	const char* comm;

	per = point / 5 * 10;

	if (per >= 80)
	{
		grade = 'A';
		comm = "Excellent";
	}
	else if (per >= 60)
	{
		grade = 'B';
		comm = "Good";
	}

	else if (per >= 40)
	{
		grade = 'C';
		comm = "Fair";
	}
	else
	{
		grade = 'F';
		comm = "Fail Do hard work..";
	}
}


void student::showdata() const
{
	std::cout << "\nRoll number of student : " << rollno;
	std::cout << "\nName of student : " << name;
}

void student::show_tabular() const
{
	std::cout << rollno << std::setw(15) << name << std::setw(10) << obt << std::setw(10) << per << std::setw(6) << grade << std::endl;
	myarr++;
}

void quiz()
{

	std::clock_t start;
	start = std::clock();

	char a, b, e;
	int t = 0;
	int i = 0;
	int right = 0;
	int wrong = 0;
	char answer;
	struct question abc[6];
	int srno = 0;


	abc[0] = { "Which of the following is not the characteristic of a class?","Generic","Friend","Inline","Inline",'c' };
	abc[1] = { "Which of the following statements is most suitable for the C++ language?","Statically typed language.","Dynamically typed language.","All","Type-less language.",'a' };
	abc[2] = { "Which of the following operators doesn’t allow overloading?","Comparison operator.","Assignment operator.","Scope resolution operator.","Dereference operator.",'c' };
	abc[3] = { "Which of the following isn’t supported in C++ language?","Namespaces.","Inheritance","Reflection.","Polymorphism.",'c' };
	abc[4] = { "Which of the following keywords can’t appear inside a class definition?","template","static","virtual","friend",'a' };

	do {
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		std::cout << maxtime - duration << std::endl;
		if (duration >= maxtime) {
			t = 0;
			break;
		}

		if (srno == i) {
			system("cls");

			srno++;
			b = ' ';
			e = ' ';
			answer = abc[i].ans;

			std::cout << "Question " << srno << ") " << std::endl;
			
			std::cout << abc[i].ques << std::endl;
		
		
			std::cout << " a - " << abc[i].ans1 << std::endl;
			
			std::cout << " b - " << abc[i].ans2 << std::endl;
			
			std::cout << " c - " << abc[i].ans3 << std::endl;
			
			std::cout << " d - " << abc[i].ans4 << std::endl;
			
			std::cout << " Press Enter to skip ";
		
			std::cout << " Select your Option ==> ";
			
			std::cout << " Your Remaning Time ==> ";

		}

		if (_kbhit()) 
		{
			
			a = _getch();
			//cin>>a;
			std::cout << a;

			if (int(a) == 13) {

				
				std::cout << "You skipped this Question";
			}
			else {
				if (a == answer) {
					
					point = point + 10;
					std::cout << "Congratulation You selected right option";
				}
				else {
					
					std::cout << "Correct Option is  ==> " << answer;
					
					std::cout << "You selected wrong option.";

				}
			}
			_getch();
			i++;
		}
	} while (i < 5);

	if (i < 4) {
		std::cout << "\nTime is up. You failed to attempt all questions" << std::endl;
	}

	_getch();
}


