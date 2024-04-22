#include "quiz.h"

int pointNinth = 0;

//Conducts a quiz for 9th-grade students
void quiz()
{
	pointNinth = 0;
	char a, b, e;
	int i = 0;
	int right = 0;
	int wrong = 0;
	char answers;
	struct question abc[30];
    int number = 0;

	//Add questions for 9 grade
	abc[0] = { "Which of the political models is NOT characteristic of the New Age","socialism ","conservatism","authoritarianism","liberalism",'d' };

	abc[1] = { "During the period 1839 - 1876 in the Ottoman Empire was?","The Young Turk revolution","The Kemalist movement","the Tanzima era","the Eastern Question",'c' };

	abc[2] = { "The American Constitution of 1789 provides?","weak king and strong Parliament","weak government","monarchical rule","federalism and separation of powers",'d' };

	abc[3] = { "The Bulgarian revival begins?","at the beginning of the 18th century","at the beginning of the 19th century","with the writing of Slavic Bulgarian History","in the end of the 18th century",'c' };

	abc[4] = { "Power under absolutism is exercised by?","the parliament","the monarch","the aristocrats","the government",'b' };

	abc[5] = { "Which organic compound is a carbohydrate with reserve functions in the human body","starch","glucagon","glycogen","insulin",'b' };

	abc[6] = { "Oxygen in the blood is carried by the protein?","chitin","cholesterol","actin","hemoglobin",'d' };

	abc[7] = { "In a eukaryotic cell, DNA is located in?","the membrane","lysosomes","the cytoplasm","the nucleus",'d' };

	abc[8] = { "Erythrocytes, unlike leukocytes, have?","variable shape","smaller sizes","iron ions","cell nucleus",'b' };

	abc[9] = { "Endocrine control in the human body is carried out by?","enzymes","hormones","vitamins ","minerals",'c' };

	abc[10] = { "Compound X has a sweet taste and is used to make antifreeze. Substance X is:e","propane-1,2,3-triol ","ethane-1,2-diol","nitroglycerin","acetone",'b' };

	abc[11] = { "In which order are aldehyde, alcohol, ketone labeled consecutively?","CH3COCH3, C3H7OH, CH3CHO","CH3OH, CH3COCH3, CH3CHO","HCHO, C2H5OH, CH3COCH3","C2H5OH, HCHO, CH3COCH",'d' };

	abc[12] = { "In which order is a compound that reacts with Cu(OH)2 indicated","C3H5(OH)3, C3H7OH","CH3OH, CH3COCH3","C2H5OH, CH3OH","C3H7OH, CH3COCH3",'a' };

	abc[13] = { "Which combination NONE of the compounds add a hydrogen?","CH3COCH3, C3H5(OH)3, CH3CHO","C6H5OH, CH3COCH3, CH3CHO","CH3COOH, C3H5(OH)3, C2H5OH","CH3OH, CH3CHO, C2H5COCH3",'a' };

	abc[14] = { "What is the formula of lactic acid?","CH3CH(OH)COOH","C6H4(OH)COOH","C6H5COOH","CH3COOH",'a' };

	abc[15] = { "Which statement is NOT true about the Enlightenment?","Knowledge is largely subordinated by religion","The Enlightenment is the first era in which the idea of progress is inherent","Knowledge is thought of as attainable, systematic, and comprehensive","Reason dictates morality",'a' };

	abc[16] = { "Where does Grandpa Gorio take place?","in Petersburg","in Paris","in London","in Rouen",'b' };

	abc[17] = { "In which of the lines work and author are NOT correctly connected?","Madame Bovary - Gustave Flaubert","Gulliver's Travels - Jonathan Swift","Autumn Song - Charles Baudelaire","Don Juan - George Byron",'c' };

	abc[18] = { "In which of the lines are genre and work related correctly?","epic poem - Spleen","ballad - Stranger","a novel in verse - Grandfather Gorio","elegy - Your mother",'d' };

	abc[19] = { "In which of the lines are character and work related correctly??","Vautrin - Grandfather Goriot","Tatyana - The Spring of the White Leg","Emma - Gulliver's Travels","Rastinyak - Autumn Song",'a' };

	abc[20] = { "Before doing the first commit,which of the following Git commands must be run?","git add","git init","git reset","git ad",'a' };

	abc[21] = { "What is the command to get the installed version of Git?","getGitVersion","git -version","git --version","git help version",'c' };

	abc[22] = { "Omitting semicolon at the end of a statement is called","Logical error","Execution time error","Syntax error","Run time error",'c' };

	abc[23] = { "del command is used to?","Delete directory","Delete labels","None of above","Delete files",'d' };

	abc[24] = { "What is the purpose of using breakpoints during execution of a program?","Memory management","Syntax checking","Intentionally crashing the program","Debugging",'d' };

	abc[25] = { "What is the command to set the user email for the current repository?","git email.user","git config user.email","git config email","git config",'b' };

	abc[26] = { "Which of the following command is used to view the content of any file?","TYPE","VIEW","REN","LS",'a' };

	abc[27] = { "I would use what command to get a list of files and folders?","cd","dir","mkdir","ls",'b' };

	abc[28] = { "Writing a code that prevents a program from a runtime crash is called?","Syntax checking","Breakpointing","Exception handling","Error correcting code",'c' };

	abc[29] = { "Which keyword is used to handle the expection?","handler","catch","throw","try",'b' };

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
			std::cout << a;

			if (int(a) == 13)
			{
				std::cout << "\tYou skipped this Question";
			}

			else
			{
				//check the answers
                if (a == answers)
				{
					pointNinth += 10;
					std::cout << "\tCongratulation You selected right option";
				}

				else
				{

					std::cout << "\tCorrect Option is  ==> " << answers;
					std::cout << "\tYou selected wrong option.";

				}

			}
			_getch();
			i++;

		}

	} while (i < 30);


	//add grading system
	pointNinth = pointNinth * 100 / 300;
	std::cout << "\nYou have: " << pointNinth << " percents" << std::endl;
	//students result
	if (pointNinth >= 80)
	{
		std::cout << "Your grade is: A";

	}
	else if (pointNinth >= 60)
	{
		std::cout << "Your grade is: B";

	}
	else if (pointNinth >= 40)
	{
		std::cout << "Your grade is: C";

	}
	else
	{
		std::cout << "Your grade is: F";

	}
	_getch();

	system("CLS");


}

