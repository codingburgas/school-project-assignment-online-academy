#include "quiz_10grade.h"

int pointTenth = 0;

//Conducts a quiz for 10th-grade students
void quiz_10grade()

{

	pointTenth = 0;
	char userAnswerTenth;
	int questionIndexTenth = 0;
	char correctAnswersTenth;

	struct question tenthGradeQuestions[30];

	int currentQuestionIndexTenth = 0;

	//add the questions for 10 grade
	tenthGradeQuestions[0] = { "Which of the political models is NOT characteristic of the New Age","socialism ","conservatism","authoritarianism","liberalism",'d' };

	tenthGradeQuestions[1] = { "During the period 1839 - 1876 in the Ottoman Empire was?","The Young Turk revolution","The Kemalist movement","the Tanzima era","the Eastern Question",'c' };

	tenthGradeQuestions[2] = { "The American Constitution of 1789 provides?","weak king and strong Parliament","weak government","monarchical rule","federalism and separation of powers",'d' };

	tenthGradeQuestions[3] = { "The Bulgarian revival begins?","at the beginning of the 18th century","at the beginning of the 19th century","with the writing of Slavic Bulgarian History","in the end of the 18th century",'c' };

	tenthGradeQuestions[4] = { "Power under absolutism is exercised by?","the parliament","the monarch","the aristocrats","the government",'b' };

	tenthGradeQuestions[5] = { "Which organic compound is a carbohydrate with reserve functions in the human body","starch","glucagon","glycogen","insulin",'b' };

	tenthGradeQuestions[6] = { "Oxygen in the blood is carried by the protein?","chitin","cholesterol","actin","hemoglobin",'d' };

	tenthGradeQuestions[7] = { "In a eukaryotic cell, DNA is located in?","the membrane","lysosomes","the cytoplasm","the nucleus",'d' };

	tenthGradeQuestions[8] = { "Erythrocytes, unlike leukocytes, have?","variable shape","smaller sizes","iron ions","cell nucleus",'b' };

	tenthGradeQuestions[9] = { "Endocrine control in the human body is carried out by?","enzymes","hormones","vitamins ","minerals",'c' };

	tenthGradeQuestions[10] = { "Compound X has a sweet taste and is used to make antifreeze. Substance X is:e","propane-1,2,3-triol ","ethane-1,2-diol","nitroglycerin","acetone",'b' };

	tenthGradeQuestions[11] = { "In which order are aldehyde, alcohol, ketone labeled consecutively?","CH3COCH3, C3H7OH, CH3CHO","CH3OH, CH3COCH3, CH3CHO","HCHO, C2H5OH, CH3COCH3","C2H5OH, HCHO, CH3COCH",'d' };

	tenthGradeQuestions[12] = { "In which order is a compound that reacts with Cu(OH)2 indicated","C3H5(OH)3, C3H7OH","CH3OH, CH3COCH3","C2H5OH, CH3OH","C3H7OH, CH3COCH3",'a' };

	tenthGradeQuestions[13] = { "Which combination NONE of the compounds add a hydrogen?","CH3COCH3, C3H5(OH)3, CH3CHO","C6H5OH, CH3COCH3, CH3CHO","CH3COOH, C3H5(OH)3, C2H5OH","CH3OH, CH3CHO, C2H5COCH3",'a' };

	tenthGradeQuestions[14] = { "What is the formula of lactic acid?","CH3CH(OH)COOH","C6H4(OH)COOH","C6H5COOH","CH3COOH",'a' };

	tenthGradeQuestions[15] = { "Which statement is NOT true about the Enlightenment?","Knowledge is largely subordinated by religion","The Enlightenment is the first era in which the idea of progress is inherent","Knowledge is thought of as attainable, systematic, and comprehensive","Reason dictates morality",'a' };

	tenthGradeQuestions[16] = { "Where does Grandpa Gorio take place?","in Petersburg","in Paris","in London","in Rouen",'b' };

	tenthGradeQuestions[17] = { "In which of the lines work and author are NOT correctly connected?","Madame Bovary - Gustave Flaubert","Gulliver's Travels - Jonathan Swift","Autumn Song - Charles Baudelaire","Don Juan - George Byron",'c' };

	tenthGradeQuestions[18] = { "In which of the lines are genre and work related correctly?","epic poem - Spleen","ballad - Stranger","a novel in verse - Grandfather Gorio","elegy - Your mother",'d' };

	tenthGradeQuestions[19] = { "In which of the lines are character and work related correctly??","Vautrin - Grandfather Goriot","Tatyana - The Spring of the White Leg","Emma - Gulliver's Travels","Rastinyak - Autumn Song",'a' };

	tenthGradeQuestions[20] = { "Before doing the first commit,which of the following Git commands must be run?","git add","git init","git reset","git ad",'a' };

	tenthGradeQuestions[21] = { "What is the command to get the installed version of Git?","getGitVersion","git -version","git --version","git help version",'c' };

	tenthGradeQuestions[22] = { "Omitting semicolon at the end of a statement is called","Logical error","Execution time error","Syntax error","Run time error",'c' };

	tenthGradeQuestions[23] = { "del command is used to?","Delete directory","Delete labels","None of above","Delete files",'d' };

	tenthGradeQuestions[24] = { "What is the purpose of using breakpoints during execution of a program?","Memory management","Syntax checking","Intentionally crashing the program","Debugging",'d' };

	tenthGradeQuestions[25] = { "What is the command to set the user email for the current repository?","git email.user","git config user.email","git config email","git config",'b' };

	tenthGradeQuestions[26] = { "Which of the following command is used to view the content of any file?","TYPE","VIEW","REN","LS",'a' };

	tenthGradeQuestions[27] = { "I would use what command to get a list of files and folders?","cd","dir","mkdir","ls",'b' };

	tenthGradeQuestions[28] = { "Writing a code that prevents a program from a runtime crash is called?","Syntax checking","Breakpointing","Exception handling","Error correcting code",'c' };

	tenthGradeQuestions[29] = { "Which keyword is used to handle the expection?","handler","catch","throw","try",'b' };

	do

	{

		if (currentQuestionIndexTenth == questionIndexTenth)
		{
            system("cls");
			currentQuestionIndexTenth++;
			correctAnswersTenth = tenthGradeQuestions[questionIndexTenth].yourAnswer;

			std::cout << "Question " << currentQuestionIndexTenth << ") " << std::endl;

			std::cout << tenthGradeQuestions[questionIndexTenth].questions << std::endl;


			std::cout << " a - " << tenthGradeQuestions[questionIndexTenth].answer1 << std::endl;
			std::cout << " b - " << tenthGradeQuestions[questionIndexTenth].answer2 << std::endl;
			std::cout << " c - " << tenthGradeQuestions[questionIndexTenth].answer3 << std::endl;
			std::cout << " d - " << tenthGradeQuestions[questionIndexTenth].answer4 << std::endl;
			std::cout << " Press Enter to skip " << std::endl;
			std::cout << "\t Select your Option ==> ";

		}

		if (_kbhit())
        {

			userAnswerTenth = _getch();
			std::cout << userAnswerTenth;
			if (int(userAnswerTenth) == 13)
			{
				std::cout << "\tYou skipped this Question";
			}

			else
            {
				//check the answers
				if (userAnswerTenth == correctAnswersTenth)
				{

					pointTenth += 10;
					std::cout << "\tCongratulation You selected right option";
				}

				else
				{
					std::cout << "\tCorrect Option is  ==> " << correctAnswersTenth;
					std::cout << "\tYou selected wrong option.";

				}

			}

			_getch();

			questionIndexTenth++;

		}

	} while (questionIndexTenth < 30);
	//add grading system
	pointTenth = pointTenth * 100 / 300;
	std::cout << "\n\nYou have: " << pointTenth << " percents" << std::endl;
	//student percents
	
	if (pointTenth >= 80)
	{
		std::cout << "Your grade is: A";

	}
	else if (pointTenth >= 60)
	{
		std:: cout << "Your grade is: B";
		
	}
	else if (pointTenth >= 40)
	{
		std::cout << "Your grade is: C";
		
	}
	else
	{
		std:: cout << "Your grade is: F";
		
	}

	_getch();
    system("CLS");
}

