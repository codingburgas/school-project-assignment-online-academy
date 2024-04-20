#include "results.h"

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

void write_student()
{
	student st;
	std::ofstream outFile;
	outFile.open("Results.txt", std::ios::binary | std::ios::app);
	
	outFile.write(reinterpret_cast<char*> (&st), sizeof(student));
	outFile.close();
	//	cout<<"\n\nStudent record Has Been Created ";
	//cin.ignore();
	std::cin.get();
}

//***************************************************************
//    	function to read all records from file
//****************************************************************

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


//***************************************************************
//    	function to display all students grade report
//****************************************************************

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