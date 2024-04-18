#include "menu.h"
#include "dataAccess.h"

// Function to display the starting screen and handle user input for name entry and checking for existing students
void startingScreen()
{
    Student student;
    std::cout << "\t\t\t\t __    __    ___  _         __   ___   ___ ___    ___ " << std::endl;
    std::cout << "\t\t\t\t|  |__|  |  /  _|| |       /  | /   \\ |   Y   T  /  _|" << std::endl;
    std::cout << "\t\t\t\t|  |  |  | /  |_ | |      /  / /     \\| _   _ | /  |_ " << std::endl;
    std::cout << "\t\t\t\t|  |  |  |/    _|| l___  /  /  |  O  ||  \\_/  |/    _|" << std::endl;
    std::cout << "\t\t\t\tY  `  '  l|   |_ |     |/   \\_ |     ||   |   ||   |_ " << std::endl;
    std::cout << "\t\t\t\t \\      / |     ||     |\\     |\\     /|   |   ||     |" << std::endl;
    std::cout << "\t\t\t\t  \\_/\\_/  l_____jl_____j \\____j \\___/ l___j___jl_____j" << std::endl;
    
    std::cout << "\n\n\n\t\t\t\t    Enter your name before starting the quiz:"  ;
    std::cin >> student.name;
  
    Student existingStudent;
    if (findStudent(student.name, existingStudent))
    {
        char choice;
        std::cout << "\n\n\t\t\t\t    This name is already used. Is that you? (y/n): ";
        std::cin >> choice;
        if (choice == 'n' || choice == 'N')
        {
            std::cout << "\n\n\t\t\t\t    Please choose a different name:";
            std::cin >> student.name;

            std::ofstream myfile("Scores.txt", std::ios::app);
            student.score = 0;
            myfile << student.name << " " << student.score << std::endl;
            myfile.close();
        }
    }
    else
    {
        // New student, proceed to add them to the file
        std::ofstream myfile("Scores.txt", std::ios::app);
        // Assume a default score or some logic to determine the score
        student.score = 0; // Placeholder
        myfile << student.name << " " << student.score << std::endl;
        myfile.close();
    }

    system("CLS");
    

    std::vector<std::string> menuOptions = { "Revision", "Start test", "Information", "Grades", "Exit" };
    menu(menuOptions);

    std::cout << " ___ ___   ____  ____  ____       ___ ___    ___  ____   __ __ " << std::endl;
    std::cout << "|   T   | /    Tl    j|    \\     |   T   |  /  _]|    \\ |  T  |" << std::endl;
    std::cout << "| _   _ |/  o  | |  | |  _  \\    | _   _ | /  [_ |  _  \\|  |  |" << std::endl;
    std::cout << "|  \\_/  ||     | |  | |  |  |    |  \\_/  |/    _]|  |  ||  |  |" << std::endl;
    std::cout << "|   |   ||  _  | |  | |  |  |    |   |   ||   [_ |  |  ||  |  |" << std::endl;
    std::cout << "|   |   ||  |  | j  l |  |  |    |   |   ||     ||  |  |l     |" << std::endl;
    std::cout << "l___j___jl__j__j|____jl__|__j    l___j___jl_____jl__j__j \\__,_j" << std::endl;
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
bool subMenuStartTest(std::vector<std::string> subMenuStartTestOptions, std::vector<std::string> menuOptions)
{
    int selectedOption = 0;
    char pressedKey = ' ';

    system("CLS"); // Clear the screen

    printSubMenuOptions(subMenuStartTestOptions, selectedOption);
    
    {
        pressedKey = _getch();

        // Moving up through the submenu
        if (selectedOption != 0 && pressedKey == (char)72)
        {
            selectedOption--;
        }

        // Moving down through the submenu
        if (selectedOption != subMenuStartTestOptions.size() - 1 && pressedKey == (char)80)
        {
            selectedOption++;
        }

        system("CLS"); // Clear the screen
        
        printSubMenuOptions(subMenuStartTestOptions, selectedOption);

        // Choosing submenu option
        if (pressedKey == '\r')
        {
            switch (selectedOption)
            {
                // Option 1
            case 0:
                system("CLS");
                std::cout << "Option 1 selected." << std::endl;
                break;

                // Option 2
            case 1:
                system("CLS");
                std::cout << "Option 2 selected." << std::endl;
                break;

                // Back
            case 2:
                system("CLS");
                return true; // Return to main menu

            default:
                break;
            }
        }
    }
}

// Function to handle the "Grades" submenu


bool subMenuGrades(std::vector<std::string> subMenuGradesOptions, std::vector<std::string> menuOptions)
{
        

    int selectedOption = 0;
    char pressedKey = ' ';

    system("CLS"); // Clear the screen
        


    printSubMenuOptions(subMenuGradesOptions, selectedOption);

    while (true)
    {
        pressedKey = _getch();

        // Moving up through the submenu
        if (selectedOption != 0 && pressedKey == (char)72)
        {
            selectedOption--;
        }

        // Moving down through the submenu
        if (selectedOption != subMenuGradesOptions.size() - 1 && pressedKey == (char)80)
        {
            selectedOption++;
        }

        system("CLS"); // Clear the screen
        
        printSubMenuOptions(subMenuGradesOptions, selectedOption);

        // Choosing submenu option
        if (pressedKey == '\r')
        {
            switch (selectedOption)
            {
                // Option 1
            case 0:
                system("CLS");
                std::cout << "Displaying highest grade." << std::endl;
                // Implement displaying highest grade functionality
                break;

                // Option 2
            case 1:
                system("CLS");
                std::cout << "Displaying students who passed the test." << std::endl;
                // Implement displaying students who passed the test functionality
                break;

                // Option 3
            case 2:
                system("CLS");
                std::cout << "Displaying students who don't pass the test." << std::endl;
                // Implement displaying students who don't pass the test functionality
                break;

                // Back
            case 3:
                system("CLS");
                return true; // Return to main menu

            default:
                break;
            }
        }
    }
}

// Function to display the main menu and handle user input
void menu(std::vector<std::string> menuOptions)
{
    
    int selectedOption = 0; // By default when you open the app you are hovering at the first menu option
    char pressedKey = ' ';
    bool exitStatement = true;
    bool displayMenu = true; // Flag to control whether to display the main menu

    while (exitStatement)
    {
        if (displayMenu) {
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

        if (displayMenu) {
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
                std::cout << "\t\t\t\t\t _        ___   ____  ____   ____ " <<    std::endl;
                std::cout << "\t\t\t\t\t| T      /  _] /    T|    \\ |    \\ " << std::endl;
                std::cout << "\t\t\t\t\t| |     /  [_ /  o  ||  D  )|  _  \\" <<  std::endl;
                std::cout << "\t\t\t\t\t| |___ /    _]|     ||    / |  |  |" <<   std::endl;
                std::cout << "\t\t\t\t\t|     ||   [_ |  _  ||    \\ |  |  |" <<  std::endl;
                std::cout << "\t\t\t\t\t|     ||     T|  |  ||  .  Y|  |  |" <<   std::endl;
                std::cout << "\t\t\t\t\tl_____jl_____jl__j__jl__j\__jl__j__j" <<  std::endl;
               
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
                    std::cout << "\t\t\t\t\t";

                    int subjectChoice;
                    std::cin >> subjectChoice;
                    if (subjectChoice >= 1 && subjectChoice <= static_cast<int>(subjects.size()))
                    {
                        system("CLS");
                        if (subjectChoice == 1)
                        {
                            std::cout << "Revision about " << subjects[subjectChoice - 1] << std::endl;
                            std::cout << "In 1726, Jonathan Swift published his book Travels in Various Countries of the World, in four parts. By Lemuel Gulliver,first a physician," << std::endl;
                            std::cout << "and afterwards captain of several ships.In 1735, the edition took its final form and consisted of Captain Gulliver's Letter to his Cousin Simpson, a Publisher's Preface, " << std::endl;
                            std::cout << "and four chapters.The author began writing the Voyages in 1721, influenced by the great success of Daniel Defoe's novel Robinson Crusoe. In many ways, Gulliver can" << std::endl;
                            std::cout << "be considered a parody of Robinson Crusoe.The book ridicules the diaristic adventure literature developed during the Renaissance, of which Robinson Crusoe was the pinnacle."   << std::endl;
                        }
                        if (subjectChoice == 2)
                        {
                            std::cout << "Revision about Biology" << std::endl;
                            std::cout << "Mitosis consists of four main phases: prophase, metaphase, anaphase and telophase. Some textbooks describe" << std::endl;
                            std::cout << "five, dividing prophase into an early phase (called prophase) and a late phase (called prometaphase). " << std::endl;
                            std::cout << "These phases occur in a strictly sequential order, and cytokinesis-the process of dividing the contents " << std::endl;
                            std::cout << "of cells to build two new cells-begins during anaphase or telophase." << std::endl;

                        }
                        if (subjectChoice == 3)
                        {
                            std::cout << "Revision about Chemistry " << std::endl;
                            std::cout << "Atoms are the smallest units of matter that retain the basic chemical properties of the elements.. Much of what we study " << std::endl;
                            std::cout << "in chemistry involves what happens when atoms bond with other atoms to form compounds. A compound is a distinct group " << std::endl;
                            std::cout << "of atoms that are joined by chemical bonds. Just as the structure of an atom is maintained by the electrostatic " << std::endl;
                            std::cout << "attraction between the positively charged nucleus and the negatively charged electrons around it, stability in chemical " << std::endl;
                            std::cout << "bonds is also due to electrostatic attractions. To show this, we will consider the two main types of chemical bonds : covalent and ionic bonds. " << std::endl;
                            std::cout << "In covalent bonds, two atoms share pairs of electrons, while in ionic bonds the shared electron pair is completely transferred from one atom to the other, forming ions. " << std::endl;


                        }
                        if (subjectChoice == 4)
                        {
                            std::cout << "Revision about History " << std::endl;
                            std::cout << "1939 The beginning of World War II The beginning of the war finds Bulgaria in a relatively stable authoritarian regime, which tries to maintain neutrality " << std::endl;
                            std::cout << "by maneuvering between Nazi Germany ,the Western powers and the USSR. February 1940 Tsar Boris III appoints a new government" << std::endl;
                            std::cout << "Tsar Boris III appoints a new government headed by Prof. Bogdan Filov. The composition of this cabinet is a benevolent gesture towards the Reich (Nazi Germany)." << std::endl;
                            std::cout << "7 September 1940 | Signing of the Craiova Agreement Bulgaria and Romania sign the Treaty of Craiova, by which Southern Dobrudzha is returned to Bulgaria " << std::endl;
                        }
                        if (subjectChoice == 5)
                        {

                            std::cout << "Revision about Physics " << std::endl;
                            std::cout << "The notion of electricity stems from observation of nature. We observe the action of a force between bodies which, , like gravity, acts from a distance." << std::endl;
                            std::cout << "The source of this force is given the name charge. A very remarkable feature of the electric force force is that it is large, much more powerful than " << std::endl;
                            std::cout << "the force of gravity. Unlike gravity, however, there are two kinds of electric charge. Different charges attract each other and the same charges repel " << std::endl;
                            std::cout << "each other. Gravity always attracts and never repels." << std::endl;
                        }


                        std::cout << "\nPress any key to return to Study Set...";
                        _getch();
                        system("CLS");
                        menu(menuOptions);
                    }
                    else
                    {
                        std::cout << "Invalid choice. Returning to main menu.\n";
                        system("CLS");
                        menu(menuOptions);
                    }
                }
                else if (yourGradeOption == 2)
                {
                    std::cout << "Revision" << std::endl;
                    std::cout << "\nPress any key to return to Main Menu...";
                    _getch();
                    system("CLS");
                    menu(menuOptions);
                }
                else
                {
                    std::cout << "Invalid choice. Returning to main menu.\n";
                    system("CLS");
                    menu(menuOptions);
                }

                // Implement learning mode functionality
                break;

                // Start test
            case 1:
            {
                system("CLS");
                std::vector<std::string> startTestOptions = { "9 Grade", "10 Grade", "Back" };
                system("CLS");
                if (subMenuStartTest(startTestOptions, menuOptions)) {
                    displayMenu = true; // Display main menu after returning from submenu
                }
            }
            break;

            // Information
            case 2:
                system("CLS");
                std::cout << "\t\t\t ____  ____    _____ ______  ____   __ __    __ ______  ____  ___   ____    _____" <<     std::endl;
                std::cout << "\t\t\t|    ||    \\  / ___/|      ||    \\ |  T  T  /  |      ||    |/   \\ |    \\  / ___/" << std::endl;
                std::cout << "\t\t\t |  | |  _  \\(   \\_ |      ||  D  )|  |  | /  /|      | |  |Y     Y|  _  \\(   \\_ " << std::endl;
                std::cout << "\t\t\t |  | |  |  | \\__  ||_|  |_||    / |  |  |/  / |_|  |_| |  ||  O  ||  |  | \\__  |" <<   std::endl;
                std::cout << "\t\t\t |  | |  |  | /  \\ |  |  |  |    \\ |  |  /   \\_  |  |   |  ||     ||  |  | /  \\ |" << std::endl;
                std::cout << "\t\t\t |  | |  |  | \\    |  |  |  |  .  Y|     \\     | |  |   |  ||     !|  |  | \\    |" <<  std::endl;
                std::cout << "\t\t\t|____|l__j__j  \\___j  l__j  l__j\\_j \\____j\\____j l__j  |____j\\___/ l__j__j  \\___j" << std::endl;
                std::cout << "Displaying information..." << std::endl;
                // Implement the information display functionality
                displayMenu = false;
                pressedKey = _getch();
                if (pressedKey == 27)
                {
                    displayMenu = true;
                }
                break;

                // Grades
            case 3:
            {
                system("CLS");
                

                std::vector<std::string> gradesOptions = { "Highest grade", "Students who passed the test", "Students who don't pass the test", "Back" };
                system("CLS");
                std::cout << "\t\t\t\t\t  ____  ____    ____  ___      ___  _____" << std::endl;
                std::cout << "\t\t\t\t\t /    ||    \\  /    ||   \\    /  _]/ ___/" << std::endl;
                std::cout << "\t\t\t\t\t|   __j|  D  )/  o  ||    \\  /  [_(   \\_ " << std::endl;
                std::cout << "\t\t\t\t\t|  |  ||    / |     ||  D  \\/    _]\\__  |" << std::endl;
                std::cout << "\t\t\t\t\t|  |_ ||    \\ |  _  ||     ||   [_ /  \\ |" << std::endl;
                std::cout << "\t\t\t\t\t|     ||  .  Y|  |  ||     ||     |\\    |" << std::endl;
                std::cout << "\t\t\t\t\tl_____jl__j\\_jl__|__|l_____jl_____| \\___j" << std::endl;

                if (subMenuGrades(gradesOptions, menuOptions)) 
                {
                    displayMenu = true; // Display main menu after returning from submenu
                }
            }
            break;

            // Exit
            case 4:
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