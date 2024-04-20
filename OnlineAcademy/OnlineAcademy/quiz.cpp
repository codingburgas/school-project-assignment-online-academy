#include "quiz.h"

	int point = 0;
	int myarr = 0;
class student
{
	int rollno;
	char name[50];
	//void calculate();	//function to calculate grade
	int obt;
	double persent;
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

	persent = point / 5 * 10;

	if (persent >= 80)
	{
		grade = 'A';
		comm = "Excellent";
	}
	else if (persent >= 60)
	{
		grade = 'B';
		comm = "Good";
	}

	else if (persent >= 40)
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
	std::cout << rollno << std::setw(15) << name << std::setw(10) << obt << std::setw(10) << persent << std::setw(6) << grade << std::endl;
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
	char answers;
	struct question abc[6];
	int number = 0;


	abc[0] = { "Which of the following is not the characteristic of a class?","Generic","Friend","Inline","Inline",'c' };
	abc[1] = { "Which of the following statements is most suitable for the C++ language?","Statically typed language.","Dynamically typed language.","All","Type-less language.",'a' };
	abc[2] = { "Which of the following operators doesn’t allow overloading?","Comparison operator.","Assignment operator.","Scope resolution operator.","Dereference operator.",'c' };
	abc[3] = { "Which of the following isn’t supported in C++ language?","Namespaces.","Inheritance","Reflection.","Polymorphism.",'c' };
	abc[4] = { "Which of the following keywords can’t appear inside a class definition?","template","static","virtual","friend",'a' };

	do 
	{

		if (number == i)
		{
			system("cls");

			number++;
			b = ' ';
			e = ' ';
			answers = abc[i].yourAnswer;

			std::cout << "Question " << number << ") " << std::endl;
			
			std::cout << abc[i].questions << std::endl;
		
		
			std::cout << " a - " << abc[i].answer1 << std::endl;
			
			std::cout << " b - " << abc[i].answer2 << std::endl;
			
			std::cout << " c - " << abc[i].answer3 << std::endl;
			
			std::cout << " d - " << abc[i].answer4 << std::endl;
			
			std::cout << " Press Enter to skip " << std::endl;
		
			std::cout << "\t Select your Option ==> ";

		}

		if (_kbhit()) 
		{
			
			a = _getch();
			//cin>>a;
			std::cout << a;

			if (int(a) == 13) 
			{

				
				std::cout << "You skipped this Question";
			}
			else 
			{
				if (a == answers) 
				{
					
					point = point + 10;
					std::cout << "Congratulation You selected right option";
				}
				else 
				{
					
					std::cout << "Correct Option is  ==> " << answers;
					
					std::cout << "You selected wrong option.";

				}
			}
			_getch();
			i++;
		}
	} 
	while (i < 5);

	if (i < 4) 
	{
		std::cout << "\nTime is up. You failed to attempt all questions" << std::endl;
	}

	_getch();
}


