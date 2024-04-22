#include "results.h"
#include "quiz.h"


void student::calculate()
{
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

void student::getdata()
{
	point = 0;
	std::cout << "\nEnter The roll number of student ";
	std::cin >> rollno;
	std::cout << "\n\nEnter The Name of student ";
	std::cin.ignore();
	std::cin.getline(name, 50);
	system("cls");
	quiz();
	obt = point;

	calculate();
	system("cls");
	Result();
}

void write_student()
{
	student st;
	std::ofstream outFile;
	outFile.open("Results.txt", std::ios::binary | std::ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char*> (&st), sizeof(student));
	outFile.close();
	//	cout<<"\n\nStudent record Has Been Created ";
	//cin.ignore();
	std::cin.get();
}


//function to read all records from file


void display_all()
{
	student st;
	std::ifstream inFile;
	inFile.open("Results.txt", std::ios::binary);
	if (!inFile)
	{
		std::cout << "File could not be open !! Press any Key...";
		std::cin.ignore();
		std::cin.get();
		return;
	}
	std::cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
	{
		st.showdata();
		std::cout << "\n\n====================================\n";
	}
	inFile.close();
	std::cin.ignore();
	std::cin.get();
}



//function to display all students grade report


void class_result()
{
	student st;
	std::ifstream inFile;

	inFile.open("Results.txt", std::ios::binary);
	if (!inFile)
	{
		std::cout << "File could not be open !! Press any Key...";
		std::cin.ignore();

		std::cin.get();
		return;
	}

	std::cout << "\n\n\t\tALL STUDENTS RESULT \n";
	std::cout << "\n\t\tPress Enter to Go Back Home Screen\n";
	std::cout << "==========================================================\n";
	std::cout << "R.No          Name      Points     %      Grade" << std::endl;
	std::cout << "==========================================================\n";
	while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
	{
		st.show_tabular();
	}
	std::cin.ignore();
	std::cin.get();
	inFile.close();
}