#include "quiz_10grade.h"

int point_10grade = 0;

class student
{

	char name[50];
	//void calculate();	//function to calculate grade
	int obt;
	double persent;
	char grade;
	void calculate_10grade();	//function to calculate grade

public:
	void showdata() const;	//function to show data on screen
	void show_tabular() const;
}; //class ends here

void student::calculate_10grade()
{
	const char* comm;

	persent = point_10grade / 5 * 10;

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


void quiz_10grade()
{
	char a, b, e;
	int i = 0;
	int right = 0;
	int wrong = 0;
	char answers;
	struct question abc[30];
	int number = 0;


	abc[0] = { "Which of the names listed is spelled correctly?","Union of Teachers in Bulgaria","Bulgarian State Railways","National Revenue Agency","United States of America",'c' };
	abc[1] = { "Indicate the true statement. Endothermic processes:","occur with the absorption of heat and the final products are richer in energy than the starting substances","proceed with the absorption of heat and the final products are poorer in energy than the starting substances","proceed with the release of heat and the final products are richer in energy than the starting substances","proceed with the release of heat and the final products are poorer in energy than the starting substances",'b' };
	abc[2] = { "Indicate the true statement. According to Hess's law, the thermal effect of a reaction depends on?","the initial state of the system","he final state of the system","the initial and final state of the system, as well as the intermediate stages of the reaction","the initial and final state of the system and does not depend on its intermediate stages",'c' };
	abc[3] = { "Which sentence has a grammatical mistake?","So far only a few projects meet the requirements","And today, to my regret, after the end of the seminar in the club, I did not find anyone","Any of my friends will be able to give me the address of the foundation","The authors whose materials I reviewed today have really big ambitions.",'b' };
	abc[4] = { "In which order are all the words spelled correctly? ","distracted, restless, sleepless","polite, no-nonsense, distance","major, nein, zoning","honesty, danger, selflessness",'b' };
	abc[5] = { "Which sentence is NOT misspelled?","I'lluminated by the moon, the mountain shone like silver, the bare frozen forests darkened, its valleys and ravines gaped like pits, sunken in snow and breathing cold","In the evening, when the fog over the field cleared and the snow turned red from the sunset, the five wolves that lay in the sparse forest by the road set off for the mountain","She came from the end well, gilded the rings of the iron chain, bent over the bucket, wet her clear forehead and shook it violently in the air.","The plums turn red above the braids, and the yellow bells hang from the broad-leaved pumpkins,which ring, swayed by the meek song of the bees",'b' };
	abc[6] = { "Which sentence has a punctuation error?","Thin, hot, they looked like twins - both were the same height, light brown, and their manes and tails were even lighter, almost white","Water could be heard rushing from the other side, torrents were flowing down through the bars, and in the village valley a whole river was now roaring - dim, wide, scary","Sometimes it rained, at first with thunder and wind, then settled, overthe field was covered with mist and the rain was falling softly and softly","The horizon was not visible, the massive and heavy outlines of mountains were not obstructed anywhere, there were no forests, no trees",'c' };
	abc[7] = { "In which sentence is NOT a punctuation error?","On one side of the square was a dark building with a huge tree in the courtyard, probably a church, judging by its scabbard on the roof","The fifth turned into a long main street lined with houses, which led them to a poorly lit square","He saw a brown street jammed with cars and passers-by wearing dark coats","He got up, went to the door, found it unlocked and locked it",'d' };
	abc[8] = { "In which of the sentences is the punctuation norm violated?","Both permanent and temporary exhibitions display the collected treasures","The museum, located on the territory of the monastery, has 35,000 exhibits","There are many collections, including icons and wood carvings and collections of manuscripts","However, it is not possible for visitors to the complex to see all the valuables",'c' };
	abc[9] = { "In which of the sentences is a punctuation error made?","The frescoes and wood carvings in the monastery were painted and made by generations of painters and craftsmen","They have worked hard to give their best and have achieved a lot","From the 10th century, when it was founded, the temple was unwittingly destroyed and burned, after which it was rebuilt","The holy cloister acquired this appearance only when it was completely restored, which happened in the middle of the 20th century",'c' };
	abc[10] = { "In which of the sentences is NOT a lexical error?","Kliment Ohridski founded a book school that trained clerics and grammarians","During the Revival, many were initiated into the cell school of Neophyte Rilski students","Many Bulgarians and revolutionaries, including Botev, lived in Bucharest at that time","The Rila Monastery is not only a religious and cultural monument, but also a historical shrine",'d' };
	abc[11] = { "Which of the following qualities does not have quixote? ","courage","magnanimity","determination","kindness",'d' };
	abc[12] = { "What a change in Sancho Pansa ? ","gets rich","is no longer a materialist","becomes more honest","forgets where he started from",'c' };
	abc[13] = { "What is not the conflict in Hamlet?","conceptual","slaughtered","elevated","personal",'c' };
	abc[14] = { "What is leading during Classicism?","the circus","to affect life such that,as it is","reason","striving for rapprochement with God",'c' };
	abc[15] = { "Which of the following qualities does Orgone not possess?","trustworthiness","hypocrisy","naivety","blindness",'b' };
	abc[16] = { "In which of the lines are the character and the work correctly related?","Kutsar - Indje","Gatyu - The Heroes","Bezportev - Under the yoke","Bojan - Tobacco",'d' };
	abc[18] = { "In which of the lines are the work and its genre correctly related?","Story - a story","September - a lyrical cycle","Levski - ode","Cis moll - elegy",'b' };
	abc[19] = { "Which work is characterized by the motif of the fog that has turned intoa metaphor for human life ?","Tobacco","Letter","Armenians","Winter evenings",'d' };
	abc[20] = { "In which of the lines is indicated a phenomenon characteristic only of the post-war periodmodernism? ","expressionism","aesthetic individualism","symbolism","realism",'a' };
	abc[21] = { "How many traits are tracked in a dihybrid cross?","one","three","two","more than three",'c' };
	abc[22] = { "A person's gender is determined by?","the segmentation","fertilization","gastrulation","gametogenesis",'b' };
	abc[23] = { "Anthropogenesis is a process of?","embryonic development of man","extinction of organisms due to human activity","origin and historical development of man","climate change due to human activity",'c' };
	abc[24] = { "The rate of a chemical reaction in an irreversible process does NOT change when?","increasing the concentration of the reactant","decrease in product concentration","change in temperature of the system","adding a catalyst to the system",'b' };
	abc[25] = { "Which of the following statements about enzymes is NOT true?","their activity is preserved at a very high temperature","are very sensitive","their action is influenced by the pH of the environment","can speed up only one process",'a' };
	abc[26] = { "The dissolution of substances is?","a chemical process with a certain heat effect","always an endothermic process","a physicochemical process with a certain thermal effect","physical exothermic process",'c' };
	abc[27] = { "Which of the given examples is a solution?","mineral water","distilled water","customs water","milk",'a' };
	abc[28] = { "When organic substances are burned, CO2 is released. Which of the biological processes is important for the reduction of CO2 in nature?","sweet fruit fermentation","photosynthesis","putrefaction","breathing",'b' };
	abc[29] = { "Name the faithful creation. Exothermic processes?","proceed with the absorption of heat and the final products are richer in energy than the starting substances","proceed with the absorption of heat and the final products are poorer in energy than the starting substances","proceed with the release of heat and the final products are richer in energy than the starting substances","proceed with the release of heat and the final products are poorer",'c' };



	do {

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

			std::cout << "\n Press Enter to skip " << std::endl;

			std::cout << " Select your Option ==> ";


		}

		if (_kbhit())
		{

			a = _getch();
			//cin>>a;
			std::cout << a;

			if (int(a) == 13) 
			{
				std::cout << "\tYou skipped this Question";
			}
			else 
			{
				if (a == answers) 
				{

					point_10grade = point_10grade + 10;
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
	} 
	while (i < 30);

}


