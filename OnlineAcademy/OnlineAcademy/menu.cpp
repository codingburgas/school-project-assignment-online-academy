#include "menu.h"
#include "dataAccess.h"
#include "quiz.h"
#include "quiz_10grade.h"

bool updateScore(bool sequence) 
{
	return sequence;
}

void displayMenu(student currentStudent) 
{
	system("CLS");

	std::vector<std::string> menuOptions = { "Revision", "Start test", "Instructions", "Exit" };

	menu(menuOptions, currentStudent);
}

void startingScreen() {
	student* currentStudent = new student();
	std::cout << "\t\t\t\t __    __    ___  _         __   ___   ___ ___    ___ \n";
	std::cout << "\t\t\t\t|  |__|  |  /  _|| |       /  | /   \\ |   Y   T  /  _|\n";
	std::cout << "\t\t\t\t|  |  |  | /  |_ | |      /  / /     \\| _   _ | /  |_ \n";
	std::cout << "\t\t\t\t|  |  |  |/    _|| l___  /  /  |  O  ||  \\_/  |/    _|\n";
	std::cout << "\t\t\t\tY  `  '  l|   |_ |     |/   \\_ |     ||   |   ||   |_ \n";
	std::cout << "\t\t\t\t \\      / |     ||     |\\     |\\     /|   |   ||     |\n";
	std::cout << "\t\t\t\t  \\_/\\_/  l_____jl_____j \\____j \\___/ l___j___jl_____j\n";

	std::cout << "\n\n\n\t\t\t\t Enter your name before starting the quiz: ";
	std::cin >> currentStudent->name;

	if (findStudent(currentStudent->name, *currentStudent)) 
	{
		char choice;
		std::cout << "\n\n\n\t\t\t\t This name is already used. Is that you? (y/n): ";
		std::cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			currentStudent->score = 0;  // Resetting score if it's an existing user
		}
		else 
		{
			std::cout << "\n\n\n\t\t\t\t\t Please choose a different name: ";
			std::cin >> currentStudent->name;
		}
	}
	else 
	{
		// New student, adding to the file with a placeholder score
		std::ofstream myfile("Scores.txt", std::ios::app);
		currentStudent->score = 0;
		myfile << std::left << std::setw(20) << currentStudent->name // Set a fixed width for the name
			<< std::setw(10) << currentStudent->score // Fixed width for percentage
			<< std::setw(2) << currentStudent->grade << std::endl; // Fixed width for grade

		myfile.close(); // Close the file after writing
	}

	displayMenu(*currentStudent);
}

// Function to set the cursor position on the console window
void outputPosition(int x, int y)
{
	COORD position;
	position.X = x;
	position.Y = y;
	if (SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position))
	{
		return;
	}

}

// Function to change text color in the console window
void color(int color)
{
	if (SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color))
	{
		return;
	}
}

// Function to print the main menu options
void printMenuOptions(std::vector<std::string> menuOptions, int selectedOption)
{

	for (size_t i = 0; i < menuOptions.size(); i++)
	{
		// Print arrow before selected option
		if (i == selectedOption)
		{
			outputPosition(1, i + 1);
			std::cout << "-> " << menuOptions[i];
		}

		// Print space before not selected option
		else
		{
			outputPosition(1, i + 1);
			std::cout << "   " << menuOptions[i];
		}
	}
}

// Function to print the submenu options
void printSubMenuOptions(std::vector<std::string> subMenuOptions, int selectedOption)
{

	for (size_t i = 0; i < subMenuOptions.size(); ++i)
	{
		// Print arrow before selected option
		if (i == selectedOption)
		{
			outputPosition(1, i + 1);
			std::cout << "-> " << subMenuOptions[i];
		}

		// Print space before not selected option
		else
		{
			outputPosition(1, i + 1);
			std::cout << "   " << subMenuOptions[i];
		}
	}
}

// Function to handle the "Start Test" submenu
bool subMenuStartTest(std::vector<std::string> subMenuStartTestOptions, std::vector<std::string> menuOptions, student currentStudent)
{
	int selectedOption = 0;
	char pressedKey = ' ';

	while (true)
	{
		system("CLS");
		printSubMenuOptions(subMenuStartTestOptions, selectedOption);

		pressedKey = _getch();

		if (pressedKey == (char)72 && selectedOption > 0)
		{
			selectedOption--;
		}
		else if (pressedKey == (char)80 && selectedOption < subMenuStartTestOptions.size() - 1)
		{
			selectedOption++;
		}

		// Handle user selection
		if (pressedKey == '\r')
		{
			switch (selectedOption)
			{
			case 0:
				system("CLS");
				quiz();
				break;
			case 1:
				system("CLS");
				quiz_10grade();
				break;

			case 2:
				system("CLS");
				return true;
			default:
				break;
			}
		}
	}
	return false;
}


// Function to display the main menu and handle user input
void menu(std::vector<std::string> menuOptions, student currentStudent)
{

	int selectedOption = 0; // By default when you open the app you are hovering at the first menu option
	char pressedKey = ' ';
	bool exitStatement = true;
	bool displayMenu = true; // Flag to control whether to display the main menu

	while (exitStatement)
	{
		if (displayMenu)
		{
			system("CLS"); // Clear the screen
			printMenuOptions(menuOptions, selectedOption);
		}

		pressedKey = _getch();

		// Moving up through the menu
		if (selectedOption != 0 && pressedKey == (char)72)
		{
			selectedOption--;
		}

		// Moving down through the menu
		if (selectedOption != menuOptions.size() - 1 && pressedKey == (char)80)
		{
			selectedOption++;
		}

		if (displayMenu)
		{
			printMenuOptions(menuOptions, selectedOption);
		}

		// Choosing menu option
		if (pressedKey == '\r')
		{
			switch (selectedOption)
			{
				// Learn
			case 0:
				system("CLS");
				std::cout << "\t\t\t\t\t _        ___   ____  ____   ____ " << std::endl;
				std::cout << "\t\t\t\t\t| T      /  _] /    T|    \\ |    \\ " << std::endl;
				std::cout << "\t\t\t\t\t| |     /  [_ /  o  ||  D  )|  _  \\" << std::endl;
				std::cout << "\t\t\t\t\t| |___ /    _]|     ||    / |  |  |" << std::endl;
				std::cout << "\t\t\t\t\t|     ||   [_ |  _  ||    \\ |  |  |" << std::endl;
				std::cout << "\t\t\t\t\t|     ||     T|  |  ||  .  Y|  |  |" << std::endl;
				std::cout << "\t\t\t\t\tl_____jl_____jl__j__jl__j\__jl__j__j" << std::endl;

				std::cout << "\n\n\t\t\t\t\t\t  Choose Grade:" << std::endl;
				std::cout << "\t\t\t\t\t\t  1.9th Grade" << std::endl;
				std::cout << "\t\t\t\t\t\t  2.10th Grade" << std::endl;
				std::cout << "\t\t\t\t\t\t  ";
				int yourGradeOption;
				std::cin >> yourGradeOption;

				if (yourGradeOption == 1)
				{
					system("CLS");
					std::cout << "\t\t\t\t\t _        ___   ____  ____   ____ " << std::endl;
					std::cout << "\t\t\t\t\t| T      /  _] /    T|    \\ |    \\ " << std::endl;
					std::cout << "\t\t\t\t\t| |     /  [_ /  o  ||  D  )|  _  \\" << std::endl;
					std::cout << "\t\t\t\t\t| |___ /    _]|     ||    / |  |  |" << std::endl;
					std::cout << "\t\t\t\t\t|     ||   [_ |  _  ||    \\ |  |  |" << std::endl;
					std::cout << "\t\t\t\t\t|     ||     T|  |  ||  .  Y|  |  |" << std::endl;
					std::cout << "\t\t\t\t\tl_____jl_____jl__j__jl__j\__jl__j__j" << std::endl;
					std::vector<std::string> subjects = { "Bulgarian", "Biology", "Chemistry", "History", "Physics    " };
					std::cout << "\n\n\t\t\t\t\tChoose a Subject: " << std::endl;

					for (size_t i = 0; i < subjects.size(); i++)
					{
						std::cout << "\t\t\t\t\t" << i + 1 << "." << subjects[i] << std::endl;
					}
					std::cout << "\n\t\t\t\t\tSelect an option:";

					int subjectChoice;
					std::cin >> subjectChoice;
					if (subjectChoice >= 1 && subjectChoice <= static_cast<int>(subjects.size()))
					{
						system("CLS");
						if (subjectChoice == 1)
						{
							std::cout << "\t\t\t   ___________________________________________________________" << std::endl;
							std::cout << "\t\t\t / \\                             	                      \\." << std::endl;
							std::cout << "\t\t\t|   |                                                         |." << std::endl;
							std::cout << "\t\t\t \\_ |                                                         |." << std::endl;
							std::cout << "\t\t\t    |                 Revision about " << subjects[subjectChoice - 1] << "                |." << std::endl;
							std::cout << "\t\t\t    |                                                         |." << std::endl;
							std::cout << "\t\t\t    | In 1726, Jonathan Swift published his book Travels      |." << std::endl;
							std::cout << "\t\t\t    | in Various Countries of the World, in four parts.       |." << std::endl;
							std::cout << "\t\t\t    | By Lemuel Gulliver,first a physician, and afterwards    |." << std::endl;
							std::cout << "\t\t\t    | captain of several ships.In 1735, the edition took its  |." << std::endl;
							std::cout << "\t\t\t    | final form and consisted of Captain Gulliver's Letter   |." << std::endl;
							std::cout << "\t\t\t    | to his Cousin Simpson, a Publisher's Preface,           |." << std::endl;
							std::cout << "\t\t\t    | and four chapters.The author began writing the Voyages  |." << std::endl;
							std::cout << "\t\t\t    |  in 1721, influenced by the great success of            |." << std::endl;
							std::cout << "\t\t\t    | Daniel Defoe's novel Robinson Crusoe. In many ways,     |." << std::endl;
							std::cout << "\t\t\t    | Gulliver can be considered a parody of Robinson Crusoe. |." << std::endl;
							std::cout << "\t\t\t    | The book ridicules the diaristic adventure literature   |." << std::endl;
							std::cout << "\t\t\t    | the Renaissance, of which Robinson Crusoe               |." << std::endl;
							std::cout << "\t\t\t    | Robinson Crusoe was the pinnacle.                       |." << std::endl;
							std::cout << "\t\t\t    |   ______________________________________________________|" << std::endl;
							std::cout << "\t\t\t    |  /                                                      /." << std::endl;
							std::cout << "\t\t\t    \\_/______________________________________________________/." << std::endl;
						}
						if (subjectChoice == 2)
						{
							std::cout << "\t\t\t   ____________________________________________________" << std::endl;
							std::cout << "\t\t\t / \\                             	               \\." << std::endl;
							std::cout << "\t\t\t|   |                                                   |." << std::endl;
							std::cout << "\t\t\t \\_ |                                                   |." << std::endl;
							std::cout << "\t\t\t    |                Revision about Biology             |." << std::endl;
							std::cout << "\t\t\t    |                                                   |." << std::endl;
							std::cout << "\t\t\t    | Mitosis consists of four main phases: prophase,   |." << std::endl;
							std::cout << "\t\t\t    | metaphase, anaphase and telophase.                |." << std::endl;
							std::cout << "\t\t\t    | Some textbooks describe five, dividing prophase   |." << std::endl;
							std::cout << "\t\t\t    | into an early phase (called prophase) and a late  |." << std::endl;
							std::cout << "\t\t\t    | phase (called prometaphase). These phases occur   |." << std::endl;
							std::cout << "\t\t\t    | strictly sequential order, and cytokinesis-the    |." << std::endl;
							std::cout << "\t\t\t    | process of dividing the contents  of cells        |." << std::endl;
							std::cout << "\t\t\t    |  to build two new cells-begins                    |." << std::endl;
							std::cout << "\t\t\t    | during anaphase or telophase.                     |." << std::endl;
							std::cout << "\t\t\t    |   ________________________________________________|." << std::endl;
							std::cout << "\t\t\t    |  /                                                 /." << std::endl;
							std::cout << "\t\t\t    \\_/_________________________________________________/." << std::endl;
						}
						if (subjectChoice == 3)
						{
							std::cout << "\t\t\t   _______________________________________________________________" << std::endl;
							std::cout << "\t\t\t / \\                             	                          \\." << std::endl;
							std::cout << "\t\t\t|   |                                                              |." << std::endl;
							std::cout << "\t\t\t \\_ |                                                              |." << std::endl;
							std::cout << "\t\t\t    |                 Revision about Chemistry                     |." << std::endl;
							std::cout << "\t\t\t    |                                                              |." << std::endl;
							std::cout << "\t\t\t    | Atoms are the smallest units of matter that retain the basic |." << std::endl;
							std::cout << "\t\t\t    | chemical properties of the elements.. Much of what we study  |." << std::endl;
							std::cout << "\t\t\t    | in chemistry involves what happens when atoms                |." << std::endl;
							std::cout << "\t\t\t    | bond with other atoms to form compounds. A compound is       |." << std::endl;
							std::cout << "\t\t\t    | a distinct group of atoms that are joined by chemical bonds. |." << std::endl;
							std::cout << "\t\t\t    | Just as the structure of an atom is maintained by the        |." << std::endl;
							std::cout << "\t\t\t    | electrostatic attraction between the positively charged      |." << std::endl;
							std::cout << "\t\t\t    | nucleus and the negatively charged electrons around it,      |." << std::endl;
							std::cout << "\t\t\t    | stability in chemical bonds is also due to electrostatic     |." << std::endl;
							std::cout << "\t\t\t    | attractions. To show this, we will consider the two main     |." << std::endl;
							std::cout << "\t\t\t    | types of chemical bonds : covalent and ionic bonds.          |." << std::endl;
							std::cout << "\t\t\t    | In covalent bonds, two atoms share pairs of electrons        |." << std::endl;
							std::cout << "\t\t\t    | completely transferred from one atom to the other            |." << std::endl;
							std::cout << "\t\t\t    | forming ions.                                                |." << std::endl;
							std::cout << "\t\t\t    |   ___________________________________________________________|" << std::endl;
							std::cout << "\t\t\t    |  /                                                           /." << std::endl;
							std::cout << "\t\t\t    \\_/___________________________________________________________/." << std::endl;

						}
						if (subjectChoice == 4)
						{
							std::cout << "\t\t\t   ___________________________________________________________" << std::endl;
							std::cout << "\t\t\t / \\                             	                      \\." << std::endl;
							std::cout << "\t\t\t|   |                                                          |." << std::endl;
							std::cout << "\t\t\t \\_ |                                                          |." << std::endl;
							std::cout << "\t\t\t    |                Revision about History                    |." << std::endl;
							std::cout << "\t\t\t    |                                                          |." << std::endl;
							std::cout << "\t\t\t    | 1939 The beginning of World War II The beginning of the  |." << std::endl;
							std::cout << "\t\t\t    | war finds Bulgaria in a relatively stable authoritarian  |." << std::endl;
							std::cout << "\t\t\t    | regime, which tries to maintain neutrality               |." << std::endl;
							std::cout << "\t\t\t    | by maneuvering between Nazi Germany ,the Western         |." << std::endl;
							std::cout << "\t\t\t    | powers and the USSR. February 1940 Tsar Boris III        |." << std::endl;
							std::cout << "\t\t\t    | appoints a new government Tsar Boris III appoints a new  |." << std::endl;
							std::cout << "\t\t\t    | government headed by Prof. Bogdan Filov. The composition |." << std::endl;
							std::cout << "\t\t\t    | of this cabinet is a benevolent gesture towards          |." << std::endl;
							std::cout << "\t\t\t    | the Reich (Nazi Germany). 7 September 1940 | Signing     |." << std::endl;
							std::cout << "\t\t\t    | of the Craiova Agreement Bulgaria and Romania sign the   |." << std::endl;
							std::cout << "\t\t\t    | Treaty of Craiova, by which Southern Dobrudzha is        |." << std::endl;
							std::cout << "\t\t\t    | returned to Bulgaria.                                    |." << std::endl;
							std::cout << "\t\t\t    |   _______________________________________________________|." << std::endl;
							std::cout << "\t\t\t    |  /                                                       /." << std::endl;
							std::cout << "\t\t\t    \\_/_______________________________________________________/." << std::endl;

						}
						if (subjectChoice == 5)
						{
							std::cout << "\t\t\t   _______________________________________________________________" << std::endl;
							std::cout << "\t\t\t / \\                             	                          \\." << std::endl;
							std::cout << "\t\t\t|   |                                                             |." << std::endl;
							std::cout << "\t\t\t \\_ |                                                             |." << std::endl;
							std::cout << "\t\t\t    |                Revision about Physics                       |." << std::endl;
							std::cout << "\t\t\t    |                                                             |." << std::endl;
							std::cout << "\t\t\t    | The notion of electricity stems from observation of nature. |." << std::endl;
							std::cout << "\t\t\t    | We observe the action of a force between bodies which,      |." << std::endl;
							std::cout << "\t\t\t    | like gravity, acts from a distance.The source of this force |." << std::endl;
							std::cout << "\t\t\t    | is given the name charge. A very remarkable feature of      |." << std::endl;
							std::cout << "\t\t\t    | the electric force force is that it is large, much more     |." << std::endl;
							std::cout << "\t\t\t    | appoints a new government Tsar Boris III appoints a new     |." << std::endl;
							std::cout << "\t\t\t    | powerful than the force of gravity. Unlike gravity,         |." << std::endl;
							std::cout << "\t\t\t    | however, there are two kinds of electric charge.Different   |." << std::endl;
							std::cout << "\t\t\t    | charges attract each other and the same charges repel       |." << std::endl;
							std::cout << "\t\t\t    | each other. Gravity always attracts and never repels.       |." << std::endl;
							std::cout << "\t\t\t    |   __________________________________________________________|." << std::endl;
							std::cout << "\t\t\t    |  /                                                          /." << std::endl;
							std::cout << "\t\t\t    \\_/__________________________________________________________/." << std::endl;
						}


						std::cout << "\nPress any key to return to Study Set...";
						_getch();
						system("CLS");
						displayMenu = true;
					}
					else
					{
						std::cout << "Invalid choice. Returning to main menu.\n";
						system("CLS");
						displayMenu = true;
					}
				}
				else if (yourGradeOption == 2)
				{
					std::cout << "10th grade options\n";
					system("CLS");
					std::cout << "\t\t\t\t\t _        ___   ____  ____   ____ " << std::endl;
					std::cout << "\t\t\t\t\t| T      /  _] /    T|    \\ |    \\ " << std::endl;
					std::cout << "\t\t\t\t\t| |     /  [_ /  o  ||  D  )|  _  \\" << std::endl;
					std::cout << "\t\t\t\t\t| |___ /    _]|     ||    / |  |  |" << std::endl;
					std::cout << "\t\t\t\t\t|     ||   [_ |  _  ||    \\ |  |  |" << std::endl;
					std::cout << "\t\t\t\t\t|     ||     T|  |  ||  .  Y|  |  |" << std::endl;
					std::cout << "\t\t\t\t\tl_____jl_____jl__j__jl__j\__jl__j__j" << std::endl;
					std::vector<std::string> subjectsTenGrade = { "Bulgarian", "Biology", "Chemistry", "History", "Physics" };
					std::cout << "\n\n\t\t\t\t\tChoose a Subject: " << std::endl;

					for (size_t i = 0; i < subjectsTenGrade.size(); i++)
					{
						std::cout << "\t\t\t\t\t" << i + 1 << "." << subjectsTenGrade[i] << std::endl;
					}


					std::cout << "\n\t\t\t\t\tSelect an option:";

					int subjectChoice2;
					std::cin >> subjectChoice2;

					if (subjectChoice2 >= 1 && subjectChoice2 <= static_cast<int>(subjectsTenGrade.size()))
					{
						system("CLS");
						if (subjectChoice2 == 1)
						{
							std::cout << "\t\t\t   ______________________________________________________________" << std::endl;
							std::cout << "\t\t\t / \\                             	                         \\." << std::endl;
							std::cout << "\t\t\t|   |                                                            |." << std::endl;
							std::cout << "\t\t\t \\_ |                                                            |." << std::endl;
							std::cout << "\t\t\t    |                Revision about Bulgarian                    |." << std::endl;
							std::cout << "\t\t\t    |                                                            |." << std::endl;
							std::cout << "\t\t\t    | The event on which the plot of the story Albena.           |." << std::endl;
							std::cout << "\t\t\t    | is built is drawn from the author's direct observations. A |." << std::endl;
							std::cout << "\t\t\t    | young and beautiful woman is married to an unsuitable man. |." << std::endl;
							std::cout << "\t\t\t    | Dissatisfied with her situation, looking for true love,    |." << std::endl;
							std::cout << "\t\t\t    | she begins a relationship with the master of the village   |." << std::endl;
							std::cout << "\t\t\t    | mill. Soon the two lovers come to the idea of killing the  |." << std::endl;
							std::cout << "\t\t\t    | husband. The crime is solved by the testimony of the       |." << std::endl;
							std::cout << "\t\t\t    | woman's younger son, she is arrested and about to be       |." << std::endl;
							std::cout << "\t\t\t    | brought to town for trials                                 |." << std::endl;
							std::cout << "\t\t\t    |   _________________________________________________________|." << std::endl;
							std::cout << "\t\t\t    |  /                                                         /." << std::endl;
							std::cout << "\t\t\t    \\_/_________________________________________________________/." << std::endl;
						}

						if (subjectChoice2 == 2)
						{
							std::cout << "\t\t\t   _______________________________________________________________" << std::endl;
							std::cout << "\t\t\t / \\                             	                          \\." << std::endl;
							std::cout << "\t\t\t|   |                                                             |." << std::endl;
							std::cout << "\t\t\t \\_ |                                                             |." << std::endl;
							std::cout << "\t\t\t    |                Revision about Biology                       |." << std::endl;
							std::cout << "\t\t\t    |                                                             |." << std::endl;
							std::cout << "\t\t\t    | An allelic interaction in which in heterozygous individuals |." << std::endl;
							std::cout << "\t\t\t    | two dominant alleles of a gene occur independently, without |." << std::endl;
							std::cout << "\t\t\t    | affecting each other, and form a new phenotypic trait.      |." << std::endl;
							std::cout << "\t\t\t    | It is characteristic of genes that have more than two       |." << std::endl;
							std::cout << "\t\t\t    | alleles, but only two of them occur in a 2n organism.       |." << std::endl;
							std::cout << "\t\t\t    | In most sexually reproducing species, the ratio of          |." << std::endl;
							std::cout << "\t\t\t    | individuals of both sexes is 1 : 1. Mendel was the first    |." << std::endl;
							std::cout << "\t\t\t    | to make the suggestion, ingenious for his time, that the    |." << std::endl;
							std::cout << "\t\t\t    | sex trait is inherited by the laws of analysing             |." << std::endl;
							std::cout << "\t\t\t    | interbreeding.                                              |." << std::endl;
							std::cout << "\t\t\t    |   __________________________________________________________|." << std::endl;
							std::cout << "\t\t\t    |  /                                                          /." << std::endl;
							std::cout << "\t\t\t    \\_/__________________________________________________________/." << std::endl;
						}
						if (subjectChoice2 == 3)
						{
							std::cout << "\t\t\t   ________________________________________________________________" << std::endl;
							std::cout << "\t\t\t / \\                             	                           \\." << std::endl;
							std::cout << "\t\t\t|   |                                                              |." << std::endl;
							std::cout << "\t\t\t \\_ |                                                              |." << std::endl;
							std::cout << "\t\t\t    |                Revision about Chemistry                      |." << std::endl;
							std::cout << "\t\t\t    |                                                              |." << std::endl;
							std::cout << "\t\t\t    | Electrolysis: all chemical processes that take place at      |." << std::endl;
							std::cout << "\t\t\t    | electrodesunder the action of an electric current in         |." << std::endl;
							std::cout << "\t\t\t    | solution or melt. When electrolysis takes place, an          |." << std::endl;
							std::cout << "\t\t\t    | an oxidation - reduction process actually takes place,       |." << std::endl;
							std::cout << "\t\t\t    | in which the electron transition takes place due to the      |." << std::endl;
							std::cout << "\t\t\t    | electric current passed through the solution or melt.        |." << std::endl;
							std::cout << "\t\t\t    | At the cathode, the negatively charged electrode, a cathodic |." << std::endl;
							std::cout << "\t\t\t    | ions accept electrons and pass into a neutral particle.      |." << std::endl;
							std::cout << "\t\t\t    | At the anode - positively charged electrode, a process       |." << std::endl;
							std::cout << "\t\t\t    | of anodic oxidation takes place i.e.the negatively charged   |." << std::endl;
							std::cout << "\t\t\t    | give up electrons and turn into electroneutral particles.    |." << std::endl;
							std::cout << "\t\t\t    |   ___________________________________________________________|." << std::endl;
							std::cout << "\t\t\t    |  /                                                           /." << std::endl;
							std::cout << "\t\t\t    \\_/___________________________________________________________/." << std::endl;





						}
						if (subjectChoice2 == 4)
						{
							std::cout << "\t\t\t   _________________________________________________________________" << std::endl;
							std::cout << "\t\t\t / \\                             	                            \\." << std::endl;
							std::cout << "\t\t\t|   |                                                               |." << std::endl;
							std::cout << "\t\t\t \\_ |                                                               |." << std::endl;
							std::cout << "\t\t\t    |                Revision about History                         |." << std::endl;
							std::cout << "\t\t\t    |                                                               |." << std::endl;
							std::cout << "\t\t\t    | After the end of the Russo - Turkish War, the Treaty of San   |." << std::endl;
							std::cout << "\t\t\t    | Stefano was signed, which provided for the creation of large  |." << std::endl;
							std::cout << "\t\t\t    | Slavic state in the Balkans.It satisfied the demands of       |." << std::endl;
							std::cout << "\t\t\t    | Russia alone, and the Great Powers did not want it to have    |." << std::endl;
							std::cout << "\t\t\t    | such influence in the Balkans.Therefore the Congress of       |." << std::endl;
							std::cout << "\t\t\t    | Berlin was reached, at which the Bulgarian territories were   |." << std::endl;
							std::cout << "\t\t\t    | fragmented.This caused mass discontent among the Bulgarians   |." << std::endl;
							std::cout << "\t\t\t    | and led to the emergence of the national question:            |." << std::endl;
							std::cout << "\t\t\t    | Although it did not cover all the territories inhabited       |." << std::endl;
							std::cout << "\t\t\t    | by Bulgarians, the borders of the Treaty of San               |." << std::endl;
							std::cout << "\t\t\t    | Stefano became an ideal.                                      |." << std::endl;
							std::cout << "\t\t\t    |   ____________________________________________________________|." << std::endl;
							std::cout << "\t\t\t    |  /                                                            /." << std::endl;
							std::cout << "\t\t\t    \\_/____________________________________________________________/." << std::endl;


						}
						if (subjectChoice2 == 5)
						{
							std::cout << "\t\t\t   __________________________________________________________________" << std::endl;
							std::cout << "\t\t\t / \\                             	                             \\." << std::endl;
							std::cout << "\t\t\t|   |                                                                |." << std::endl;
							std::cout << "\t\t\t \\_ |                                                                |." << std::endl;
							std::cout << "\t\t\t    |                    Revision about Physics                      |." << std::endl;
							std::cout << "\t\t\t    |                                                                |." << std::endl;
							std::cout << "\t\t\t    | X - rays(Rö - rays) are short - wavelength electromagnetic     |." << std::endl;
							std::cout << "\t\t\t    | radiation with a wavelength of about 10nm to about 10 - 3nm.   |." << std::endl;
							std::cout << "\t\t\t    | In the electromagnetic spectrum, Rö rays lie between           |." << std::endl;
							std::cout << "\t\t\t    | ultraviolet rays and γ - rays, partially overlapping           |." << std::endl;
							std::cout << "\t\t\t    | them.Rö raysare produced in a so - called X - ray tube,        |." << std::endl;
							std::cout << "\t\t\t    | in which high - energy electrons bombard a metal target(anode) |." << std::endl;
							std::cout << "\t\t\t    | The X - ray tubeis a vacuum tube placed in a special lead cage |." << std::endl;
							std::cout << "\t\t\t    | to shield against the harmful effects of                       |." << std::endl;
							std::cout << "\t\t\t    | X - ray radiation.                                             |." << std::endl;
							std::cout << "\t\t\t    |   _____________________________________________________________|." << std::endl;
							std::cout << "\t\t\t    |  /                                                             /." << std::endl;
							std::cout << "\t\t\t    \\_/_____________________________________________________________/." << std::endl;

						}



						std::cout << "\nPress any key to return to Main Menu...";
						_getch();
						system("CLS");
						displayMenu = true;
					}
				}
				else
				{
					std::cout << "Invalid choice. Returning to main menu.\n";
					system("CLS");
					displayMenu = true;
				}

				// Implement learning mode functionality
				break;

				// Start test

			case 1:
			{
				system("CLS");
				std::vector<std::string> startTestOptions = { "9 Grade", "10 Grade", "Back" };
				system("CLS");
				if (subMenuStartTest(startTestOptions, menuOptions, currentStudent)) {
					displayMenu = true; // Display main menu after returning from submenu
				}
			}
			break;

			// Information
			case 2:
				system("CLS");
				std::cout << "\t\t\t ____  ____    _____ ______  ____   __ __    __ ______  ____  ___   ____    _____" << std::endl;
				std::cout << "\t\t\t|    ||    \\  / ___/|      ||    \\ |  T  T  /  |      ||    |/   \\ |    \\  / ___/" << std::endl;
				std::cout << "\t\t\t |  | |  _  \\(   \\_ |      ||  D  )|  |  | /  /|      | |  |Y     Y|  _  \\(   \\_ " << std::endl;
				std::cout << "\t\t\t |  | |  |  | \\__  ||_|  |_||    / |  |  |/  / |_|  |_| |  ||  O  ||  |  | \\__  |" << std::endl;
				std::cout << "\t\t\t |  | |  |  | /  \\ |  |  |  |    \\ |  |  /   \\_  |  |   |  ||     ||  |  | /  \\ |" << std::endl;
				std::cout << "\t\t\t |  | |  |  | \\    |  |  |  |  .  Y|     \\     | |  |   |  ||     !|  |  | \\    |" << std::endl;
				std::cout << "\t\t\t|____|l__j__j  \\___j  l__j  l__j\\_j \\____j\\____j l__j  |____j\\___/ l__j__j  \\___j" << std::endl;
				std::cout << std::endl;
				std::cout << "\t\t\t   __________________________________________________________________" << std::endl;
				std::cout << "\t\t\t / \\                             	                             \\." << std::endl;
				std::cout << "\t\t\t|   |                                                                |." << std::endl;
				std::cout << "\t\t\t \\_ |                                                                |." << std::endl;
				std::cout << "\t\t\t    |                                                                |." << std::endl;
				std::cout << "\t\t\t    | Hello, we are Online Academy and we made an app for you to     |." << std::endl;
				std::cout << "\t\t\t    | study for the final exams in 9-th and 10-th grade.             |." << std::endl;
				std::cout << "\t\t\t    | We know that they are so important and we wanted to help you.  |." << std::endl;
				std::cout << "\t\t\t    | If you want to use our app here are the instructions.          |." << std::endl;
				std::cout << "\t\t\t    | Firtsly go to Revision to revise for the forthcoming exams     |." << std::endl;
				std::cout << "\t\t\t    | Then go to Test to take some tests, where you can choose       |." << std::endl;
				std::cout << "\t\t\t    | if you want to take 9-th grade tests or 10-th grade tests      |." << std::endl;
				std::cout << "\t\t\t    | After that you can go to Grades to see what is your grade      |." << std::endl;
				std::cout << "\t\t\t    |                                                                |." << std::endl;
				std::cout << "\t\t\t    |                                                                |." << std::endl;
				std::cout << "\t\t\t    |                                                                |." << std::endl;
				std::cout << "\t\t\t    |   _____________________________________________________________|." << std::endl;
				std::cout << "\t\t\t    |  /                                                             /." << std::endl;
				std::cout << "\t\t\t    \\_/_____________________________________________________________/." << std::endl;
				// Implement the information display functionality
				displayMenu = false;
				pressedKey = _getch();
				if (pressedKey == 27)
				{
					displayMenu = true;
				}
				else
				{
					std::cout << "Invalid choice. Returning to main menu.\n";
					system("CLS");
					displayMenu = true;
				}
				break;

			// Exit
			case 3:

				exitStatement = false;
				system("CLS");
				std::cout << "Press any key to exit";
				break;

			default:
				break;
			}
		}
	}
}