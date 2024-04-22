#include "quiz_10grade.h"

int pointTenth = 0;

int myarrTenth = 0;

void student::show_tabular() const

{

	std::cout << rollno << std::setw(15) << name << std::setw(10) << obt << std::setw(10) << score << std::setw(6) << grade << std::endl;

}

void student::showdata() const {

	std::cout << "\nRoll number of student: " << rollno;

	std::cout << "\nName of student: " << name << std::endl;

}

void quiz()

{

	pointTenth = 0;


	char aTenth, bTenth, eTenth;

	int iTenth = 0;

	int rightTenth = 0;

	int wrongTenth = 0;

	char answersTenth;

	struct question abcTenth[30];

	int numberTenth = 0;


	abcTenth[0] = { "Which of the political models is NOT characteristic of the New Age","socialism ","conservatism","authoritarianism","liberalism",'d' };

	abcTenth[1] = { "During the period 1839 - 1876 in the Ottoman Empire was?","The Young Turk revolution","The Kemalist movement","the Tanzima era","the Eastern Question",'c' };

	abcTenth[2] = { "The American Constitution of 1789 provides?","weak king and strong Parliament","weak government","monarchical rule","federalism and separation of powers",'d' };

	abcTenth[3] = { "The Bulgarian revival begins?","at the beginning of the 18th century","at the beginning of the 19th century","with the writing of Slavic Bulgarian History","in the end of the 18th century",'c' };

	abcTenth[4] = { "Power under absolutism is exercised by?","the parliament","the monarch","the aristocrats","the government",'b' };

	abcTenth[5] = { "Which organic compound is a carbohydrate with reserve functions in the human body","starch","glucagon","glycogen","insulin",'b' };

	abcTenth[6] = { "Oxygen in the blood is carried by the protein?","chitin","cholesterol","actin","hemoglobin",'d' };

	abcTenth[7] = { "In a eukaryotic cell, DNA is located in?","the membrane","lysosomes","the cytoplasm","the nucleus",'d' };

	abcTenth[8] = { "Erythrocytes, unlike leukocytes, have?","variable shape","smaller sizes","iron ions","cell nucleus",'b' };

	abcTenth[9] = { "Endocrine control in the human body is carried out by?","enzymes","hormones","vitamins ","minerals",'c' };

	abcTenth[10] = { "Compound X has a sweet taste and is used to make antifreeze. Substance X is:e","propane-1,2,3-triol ","ethane-1,2-diol","nitroglycerin","acetone",'b' };

	abcTenth[11] = { "In which order are aldehyde, alcohol, ketone labeled consecutively?","CH3COCH3, C3H7OH, CH3CHO","CH3OH, CH3COCH3, CH3CHO","HCHO, C2H5OH, CH3COCH3","C2H5OH, HCHO, CH3COCH",'d' };

	abcTenth[12] = { "In which order is a compound that reacts with Cu(OH)2 indicated","C3H5(OH)3, C3H7OH","CH3OH, CH3COCH3","C2H5OH, CH3OH","C3H7OH, CH3COCH3",'a' };

	abcTenth[13] = { "Which combination NONE of the compounds add a hydrogen?","CH3COCH3, C3H5(OH)3, CH3CHO","C6H5OH, CH3COCH3, CH3CHO","CH3COOH, C3H5(OH)3, C2H5OH","CH3OH, CH3CHO, C2H5COCH3",'a' };

	abcTenth[14] = { "What is the formula of lactic acid?","CH3CH(OH)COOH","C6H4(OH)COOH","C6H5COOH","CH3COOH",'a' };

	abcTenth[15] = { "Which statement is NOT true about the Enlightenment?","Knowledge is largely subordinated by religion","The Enlightenment is the first era in which the idea of progress is inherent","Knowledge is thought of as attainable, systematic, and comprehensive","Reason dictates morality",'a' };

	abcTenth[16] = { "Where does Grandpa Gorio take place?","in Petersburg","in Paris","in London","in Rouen",'b' };

	abcTenth[17] = { "In which of the lines work and author are NOT correctly connected?","Madame Bovary - Gustave Flaubert","Gulliver's Travels - Jonathan Swift","Autumn Song - Charles Baudelaire","Don Juan - George Byron",'c' };

	abcTenth[18] = { "In which of the lines are genre and work related correctly?","epic poem - Spleen","ballad - Stranger","a novel in verse - Grandfather Gorio","elegy - Your mother",'d' };

	abcTenth[19] = { "In which of the lines are character and work related correctly??","Vautrin - Grandfather Goriot","Tatyana - The Spring of the White Leg","Emma - Gulliver's Travels","Rastinyak - Autumn Song",'a' };

	abcTenth[20] = { "Before doing the first commit,which of the following Git commands must be run?","git add","git init","git reset","git ad",'a' };

	abcTenth[21] = { "What is the command to get the installed version of Git?","getGitVersion","git -version","git --version","git help version",'c' };

	abcTenth[22] = { "Omitting semicolon at the end of a statement is called","Logical error","Execution time error","Syntax error","Run time error",'c' };

	abcTenth[23] = { "del command is used to?","Delete directory","Delete labels","None of above","Delete files",'d' };

	abcTenth[24] = { "What is the purpose of using breakpoints during execution of a program?","Memory management","Syntax checking","Intentionally crashing the program","Debugging",'d' };

	abcTenth[25] = { "What is the command to set the user email for the current repository?","git email.user","git config user.email","git config email","git config",'b' };

	abcTenth[26] = { "Which of the following command is used to view the content of any file?","TYPE","VIEW","REN","LS",'a' };

	abcTenth[27] = { "I would use what command to get a list of files and folders?","cd","dir","mkdir","ls",'b' };

	abcTenth[28] = { "Writing a code that prevents a program from a runtime crash is called?","Syntax checking","Breakpointing","Exception handling","Error correcting code",'c' };

	abcTenth[29] = { "Which keyword is used to handle the expection?","handler","catch","throw","try",'b' };

	do

	{

		if (numberTenth == iTenth)

		{

			system("cls");

			numberTenth++;

			bTenth = ' ';

			eTenth = ' ';

			answersTenth = abcTenth[iTenth].yourAnswer;

			std::cout << "Question " << numberTenth << ") " << std::endl;

			std::cout << abcTenth[iTenth].questions << std::endl;


			std::cout << " a - " << abcTenth[iTenth].answer1 << std::endl;

			std::cout << " b - " << abcTenth[iTenth].answer2 << std::endl;

			std::cout << " c - " << abcTenth[iTenth].answer3 << std::endl;

			std::cout << " d - " << abcTenth[iTenth].answer4 << std::endl;

			std::cout << " Press Enter to skip " << std::endl;

			std::cout << "\t Select your Option ==> ";

		}

		if (_kbhit())

		{

			aTenth = _getch();

			//cin>>a;

			std::cout << aTenth;

			if (int(aTenth) == 13)

			{

				std::cout << "\tYou skipped this Question";

			}

			else

			{

				if (aTenth == answersTenth)

				{

					pointTenth += 10;

					std::cout << "\tCongratulation You selected right option";

				}

				else

				{

					std::cout << "\tCorrect Option is  ==> " << answersTenth;

					std::cout << "\tYou selected wrong option.";

				}

			}

			_getch();

			iTenth++;

		}

	} while (iTenth < 30);

	std::cout << "\nYou have " << pointTenth << " points" << std::endl;

	_getch();

	system("CLS");


}

