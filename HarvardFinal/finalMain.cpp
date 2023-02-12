#include "Player.h"
#include "Relationships.h"


char intro()
{
	//introduce user to game and check if they want to play
	char answer;
	cout << "Welcome to bitLife2.0! In this game you make different";
	cout << " choices that affect you future and relationships!\n";
	cout << "This game goes from 1 - 30 years old.\n";
	cout << "Are you ready to play ? (Y / N)\n";
	cin >> answer;
	return answer;
}

void outro()
{
	cout << "Thank you for playing bitLife2.0 and I hope you had fun!\n";
	cout << "-Program ends at 30-\n";
}

void dead()
{
	cout << "\n YOU DIED YOU DIED YOU DIED\n";
	cout << "-GAME OVER-\n";
	exit(-1);
}

void userChoice(int ageAmt)
{
	//function called by life func
	//occurs at end of end of current age
	//asks user to make choices that lead to diff things
	int userChoice;
	bool choice = false;
	do
	{
		cout << "\nChoose option:\n";
		cout << "1. Age Up\n";
		cout << "2. Invest time in relationships\n";
		cout << "3. Work a job\n";
		cout << "4. Exit Game\n";

		cin >> userChoice;

		choice = false;
		if (userChoice == 1)
		{
			system("CLS");
			//clears screen then adds to user age
			startValue.m_age += ageAmt;

			//display user info
			display(startValue, startStats);
			choice = true;
		}
		else if (userChoice == 2)
		{
			if (startValue.m_age >= 5)
			{
				//checks to make sure user is of age
				//calls function that leads to relationship options
				relationShipChoices();
			}
			else
			{
				//displays message otherwise
				cout << "!!Wait till you are 5 years old!!\n\n";
			}
		}
		else if (userChoice == 3)
		{
			if (startValue.m_age >= 13)
			{
				//lets user choose jobs if they are of age
				jobs();
			}
			else
			{
				cout << "!!Wait till you are 13 years old!!\n\n";
			}
		}
		else if (userChoice == 4)
		{
			//exits user from program
			cout << "\nThanks for playing!!\n";
			exit(-1);
		}
		else
		{
			cout << "!!Choose a valid number!!\n\n";
		}
		//repeats until input is valid
	} while (!choice);
}

void readResults(randomEvents* lifeStage, int randEvent)
{
	//function displays prompts from dynamically allocated class array
	//asks user to choose choice and results + stats changes occur
	int inputChoice;

	for (int i = 0; i < 2; i++)
	{
		//prints the 2 prompts
		cout << i + 1 << "." << lifeStage[randEvent].prompts[i] << endl;
	}

	do
	{
		cout << "Enter Choice: ";
		cin >> inputChoice;
	} while (inputChoice > 2 || inputChoice < 1);

	if (lifeStage[randEvent].statChange[4 + ((inputChoice == 1) ? 0 : 5)] != 0)
	{
		//checks to see if prompt leads to a result being printed as txt file
		// contains 0 if it leads nowhere
		//prints results
		cout << endl << "   " << lifeStage[randEvent].results[inputChoice - 1];
	}

	if (inputChoice == 1)
	{
		//checks if inputs are one or two and displays appropriate stat changes.
		startValue.addPlayerInfo(lifeStage[randEvent].statChange[0],
			lifeStage[randEvent].statChange[1], lifeStage[randEvent].statChange[2],
			lifeStage[randEvent].statChange[3]);
	}
	else
	{
		startValue.addPlayerInfo(lifeStage[randEvent].statChange[5],
			lifeStage[randEvent].statChange[6], lifeStage[randEvent].statChange[7],
			lifeStage[randEvent].statChange[8]);
	}

}

void display(playerInfo info, playerStats stats)
{
	//displays player info
	cout << "__________________________________________\n";
	cout << info.m_name << "'s stats\n";
	cout << "STATS RANGE |0 - 100|\n";
	cout << "__________________________________________\n";
	cout << "Health - " << info.m_health << " Happiness - " << info.m_happy;
	cout << " Smarts - " << info.m_smarts << " Money - $" << info.m_money << endl;
	cout << "School - " << stats.m_school << " |Full Time Job - " << stats.m_job << endl;
	cout << "\nAGE: " << startValue.m_age << "\n______\n";

}

void life(randomEvents* lifeStage, int age, int sceneAmt, int events, int ageAmt, bool choices)
{
	int eventAmt, randEvent, inputChoice;

	do
	{

		//subtracts a random amount of a relationship every year
		//deletes person if relationship status lower than 30
		minusRelationship();

		//how many events will occur per age
		eventAmt = rand() % events + 1;
		for (int i = 0; i < eventAmt; i++)
		{

			//gets random number to get random scene from dyn alloc array
			randEvent = rand() % sceneAmt;

			cout << "______________\n";
			cout << "Random Event\n";

			cout << lifeStage[randEvent].events << endl;

			if (choices)
			{
				//checks if the events asks user for choices
				// if they do call the function
				readResults(lifeStage, randEvent);
			}
			else
			{
				//displays stat changes if doesn't ask for choices
				startValue.addPlayerInfo(lifeStage[randEvent].statChange[0],
					lifeStage[randEvent].statChange[1], lifeStage[randEvent].statChange[2],
					lifeStage[randEvent].statChange[3]);
			}
		}
		//checks age and assigns user a school
		school();

		//if in university, add to user smartness depedning on uni level
		if (startStats.m_school != "None" && startValue.m_age >= 18)
		{
			cout << "\nIn College! Add to Intelligence\n";
			startValue.addPlayerInfo(0, 0, 3 * startStats.m_uniChallengeLvl, 0);
		}

		//if user has a full time job, add to total money based on amt they make
		if (startStats.m_job != "None")
		{
			cout << "\nJob Payout\n";
			startValue.addPlayerInfo(0, 0, 0, startStats.m_jobPay);
		}
		//function call to start next age
		userChoice(ageAmt);

		//repeats until age is met(4, 14, 25, 30)
	} while (startValue.m_age <= age);
}


//compiled in Visual Studio
//Justin Chen- Final Project
int main()
{
	char answer;
	srand(time(0));
	answer = intro();

	if (toupper(answer) == 'Y')
	{
		system("CLS");
		//initializes player info and parents name
		randStartStats();
		beginLife();
		age1To3();
		age4Above("4-14 life events.txt", 14, 9);
		age4Above("15-25 life events.txt", 25, 8);
		age4Above("26-30 life events.txt", 30, 6);
		outro();
	}
	else
	{
		cout << "ok bye!\n";
	}
	return 0;
}