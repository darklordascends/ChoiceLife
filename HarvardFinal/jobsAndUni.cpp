#include "Player.h"
#include "Relationships.h"

void partTime()
{
	int userInput, workTime, amtMade;
	bool hasJob = true;

	//jobs and the hourly pay in parallel arrays
	vector<string> partJobs = { "Tutor","Handyman","Cashier","Lawn Mower","Dog Walker" };
	vector<int> pay = { 15,13,10,9,7 };
	//job requirements for each
	//in order health-happiness-smart
	vector<vector<int>> jobRequirements{
		{0,0,80},
		{80,0,20},
		{30,0,30},
		{60,0,0},
		{40,40,0}
	};

	system("CLS");
	cout << "Available Part Times\n";
	cout << "_________________________\n";

	//displays job
	for (int i = 0; i < partJobs.size(); i++)
	{
		cout << left << i + 1 << ". " << setw(11) << partJobs[i] << " $";
		cout << right << setw(2) << pay[i] << "/hr.\n";
	}
	cout << "6. Return.\n";

	do
	{
		hasJob = true;
		cout << "\nEnter your choice: ";
		cin >> userInput;

		if (userInput == 6)
		{
			return;
		}

		if (userInput >= 1 || userInput <= 5)
		{
			userInput--;

			//checks if they meet job requirements
			//if they dont, display message for each category
			if (jobRequirements[userInput][0] > startValue.m_health)
			{
				hasJob = false;
				cout << "Your health is too low to take this job!\n";
			}
			if (jobRequirements[userInput][1] > startValue.m_happy)
			{
				hasJob = false;
				cout << "You are too sad to have this job!\n";
			}
			if (jobRequirements[userInput][2] > startValue.m_smarts)
			{
				hasJob = false;
				cout << "You are too dumb to have this job!\n";
			}
			if (!hasJob)
			{
				cout << "Try again\n";
			}
		}
		else
		{
			cout << "Enter valid value\n";
			hasJob = false;
		}

		//repeats until user has a job or they return
	} while (!hasJob);

	//assigns random amt of time to work
	workTime = rand() % 16 + 5;

	//multiply by hourly pay
	amtMade = workTime * pay[userInput];

	//display to user
	cout << "\nYOU GOT THE JOB!!!\n";
	cout << "You worked for " << workTime << " hours as a " << partJobs[userInput];
	cout << " making $" << amtMade << "!\n";

	//update class info
	startValue.addPlayerInfo(0, 0, 0, amtMade);

}

void fullTime()
{
	//let user choose a full time job
	system("CLS");
	int i = 0, userInput, limit = 5;
	bool hasJob;

	//vectors containing jobs, their pay, and smartness requirements
	//amt of jobs accessible depending on lvl of education
	//harder college-more job oppurtunities
	vector <string> jobs = {
	"cashier","janitor","hairdresser","postman", "construction worker",//lvl 0 jobs- no college
	"teacher","artist"," graphic designer",//lvl 1 jobs- community college
	"dental assistant", "office clerk", "jr. engineer",//lvl 2 jobs- bitlife uni
	"dentist","pediatrician","pilot",//lvl 3 jobs- uc berkeley
	"brain surgeon","chief executive officer","CEO"//lvl 4 jobs- harvard yale
	};
	vector <int> pay = {
		16000, 18000, 20000, 25000, 28000,
		36000, 38000, 46000,
		50000, 55000, 62000,
		130000, 150000, 220000,
		377000, 400000, 820000
	};
	vector <int> smartMin = {
		10, 12, 15, 20, 25,
		30, 35, 40,
		50, 55, 60,
		70, 75, 80,
		90, 95, 99
	};

	//determins limit based on education level
	limit = limit + (3 * startStats.m_uniChallengeLvl);

	//displays options for user
	for (i; i < limit; i++)
	{
		cout << left << i + 1 << ". " << setw(25) << jobs[i] << " $";
		cout << right << setw(6) << pay[i] << "/yr.\n";
	}
	cout << limit + 1 << ". Return";

	do
	{
		hasJob = true;
		cout << "\nEnter your choice: ";
		cin >> userInput;

		//check if user wants to return
		if (userInput == limit + 1)
		{
			return;
		}

		if (userInput >= 1 || userInput <= limit)
		{
			userInput--;

			//checks if requirements are met
			//if not display message
			if (smartMin[userInput] > startValue.m_smarts)
			{
				hasJob = false;
				cout << "You are too dumb to have this job!\n";
			}
			if (!hasJob)
			{
				cout << "\nTry a different job\n";
			}
		}
		else
		{
			cout << "Enter valid value\n";
			hasJob = false;
		}

		//repeats until user has a job
	} while (!hasJob);

	cout << "\nYOU GOT THE JOB!!!\n";
	//assigns job and pay into classes
	startStats.m_job = jobs[userInput];
	startStats.m_jobPay = pay[userInput];

}

void commitCrime()
{
	int userInput, risk, money;

	//crime options available risk in increasing order, and amt earned for stealing
	vector<string> crimes = { "steal candy from a chld",
		"steal a car","rob a house","rob a bank" };
	vector<int> crimeRisk = { 1000,10,5,3 };
	system("ClS");
	vector<int> moneyEarned = { 1, 2000, 5000, 10000 };

	cout << "!!Committing a crime has a risk of death!!\n";

	//displays to user
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << ". " << crimes[i] << endl;
	}
	cout << "5. Return\n";

	do
	{
		cout << "Enter your choice: ";
		cin >> userInput;

		if (userInput == 5)
		{
			return;
		}

		cout << "\nYou decide to " << crimes[userInput - 1] << ". How will this go down?!\n";

		//depedning on choice, generate randoom number from range
		risk = rand() % crimeRisk[userInput - 1];

		if (risk == 1)
		{
			//if number generate is 1, user dies
			cout << "\nYou were unsuccessful in trying to " << crimes[userInput - 1] << ".\n";
			cout << "The police were alerted and they shot you :O yikes. . .\n";

			//display death message
			dead();
		}

		//displays user was succesvul
		cout << "\nYou were successful in trying to " << crimes[userInput - 1] << "!!\n";

		//adds random amt user can earn
		money = rand() % moneyEarned[userInput - 1] + 1;

		startValue.addPlayerInfo(0, 10, 0, money);

		//repeats until valid input
	} while (userInput > 5 || userInput < 1);


}

void jobs()
{
	//function that leads to the other functions
	int userInput;
	system("ClS");

	do
	{
		cout << "What job type would you like?\n";
		cout << "1. Part Time\n";
		cout << "2. Full Time\n";
		cout << "3. Commit a crime\n";
		cout << "4. Return\n";
		cout << "Enter your choice: ";
		cin >> userInput;

		//chooses option depending on input
		switch (userInput)
		{
		case 1:
			partTime();
			break;
		case 2:
			//only works if user is out of school and over 18
			if (startValue.m_age >= 18 && startStats.m_school == "None")
			{
				fullTime();
			}
			else
			{
				cout << "\n!! Wait till you are 18 and/ or out of school!!\n\n";
				userInput = 6;
			}
			break;
		case 3:
			commitCrime();
			break;
		case 4:
			return;
			break;
		default:
			cout << "Invalid input\n";
		}
		//repeats until input is valid
	} while (userInput > 4 || userInput < 1);


}

void uni(vector <string> Schools, vector <int> SchoolCost,
	vector <int> SmartRequirement, vector <int> collegeLevel)
{
	//display uni choies once

	char answer;
	int userInput;
	bool inCollege;


	cout << "\nWould you like to go to University?(Y/N)";
	cin >> answer;

	if (toupper(answer) == 'Y')
	{
		//displays school choices and cost per year
		for (int i = 0; i < Schools.size(); i++)
		{
			cout << left << i + 1 << ". " << setw(26) << Schools[i];
			cout << right << "$" << setw(5) << SchoolCost[i] << endl;
		}
		cout << "6. Return\n";

		do
		{
			inCollege = false;
			cout << "Which college/uni will you choose?(Enter number) ";
			cin >> userInput;

			if (userInput == 6)
			{
				return;
			}

			if (userInput > 6 || userInput < 1)
			{
				cout << "Enter a valid number\n";
			}
			else
			{

				if (startValue.m_smarts >= SmartRequirement[userInput - 1])
				{
					//checks if intelligence requirement is met
					cout << "YOU GOT ACCEPTED!!!\n";

					//add school to class
					startStats.m_school = Schools[userInput - 1];
					startValue.addPlayerInfo(0, 0, 0, -(SchoolCost[userInput - 1] * 4));

					//add college level
					startStats.m_uniChallengeLvl = collegeLevel[userInput - 1];
					inCollege = true;
				}
				else
				{
					cout << "Sorry you dont meet intelligence requirements\n\n";
				}
			}

			//repeats until in college/ returned
		} while (!inCollege);
	}
}

void school()
{
	//schools, their cost, and school lvl
	vector <string> Schools = { "Harvard","BitLife Community College","BitLife University",
	"UC Berkeley","Yale" };
	vector <int> SchoolCost = { 50000,1000,15000,25000,50000 };
	vector <int> SmartRequirement = { 90,30,50,60,90 };
	vector <int> collegeLevel = { 4,1,2,3,4 };
	bool changeGrade = false;

	if (startValue.m_age == 4)
	{
		//overloaded operators for assignment
		startStats == "BitLife Elementary School";
		changeGrade = true;
	}
	if (startValue.m_age == 10)
	{
		//overloaded operators for assignment
		startStats == "BitLife Middle School";
		changeGrade = true;
	}
	if (startValue.m_age == 14)
	{
		//overloaded operators for assignment
		startStats == "BitLife High School";
		changeGrade = true;
	}
	if (changeGrade)
	{
		//if new grade, display it
		cout << "\n__________________________________\n";
		cout << "\nYou are now attending " << startStats.m_school << "!\n\n";
	}
	if (startValue.m_age == 18)
	{
		startStats == "None";

		cout << "\n__________________________________\n";
		cout << "\nYou graduated BitLife High School!\n\n";

		//calls uni function that asks if they wanna go to college
		uni(Schools, SchoolCost, SmartRequirement, collegeLevel);
	}

	if (startValue.m_age == 22 && startStats.m_school != "None")
	{
		//displays college graduation if they went to college
		cout << "\n__________________________________\n";
		cout << "\nYou graduated from " << startStats.m_school << "!\n\n";
		startStats == "None";
	}

}
