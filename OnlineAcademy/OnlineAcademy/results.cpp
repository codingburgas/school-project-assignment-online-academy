#include "results.h"
#include "quiz.h"

//Writes student data to a binary file
void write_student()
{
	student st;
	std::ofstream outFile;
	outFile.open("Results.txt", std::ios::binary | std::ios::app);
	//st.getdata();
	outFile.write(reinterpret_cast<char*> (&st), sizeof(student));
	outFile.close();
	//	cout<<"\n\nStudent record Has Been Created ";
	//cin.ignore();
	std::cin.get();
}

//Function to read all records from file
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
		std::cout << "\n\n====================================\n";
	}
	inFile.close();
	std::cin.ignore();
	std::cin.get();
}



//Function to display all students grade report
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
	
	std::cin.ignore();
	std::cin.get();
	inFile.close();
}