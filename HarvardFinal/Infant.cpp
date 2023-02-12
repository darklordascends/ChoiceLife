#include "Player.h"
#include "Relationships.h"

//ages 1-3

extern vector <string> relationships = {};
extern vector<int> relationStats = {};

playerInfo startValue;
playerStats startStats;

void randStartStats()
{
	//initializes stats of the user
	int playerName, momName, dadName, lastNames;

	//assigns random health, happy, smarts
	startValue.m_happy = rand() % 10 + 91;//min is 91
	startValue.m_health = rand() % 60 + 41;//min is 41
	startValue.m_smarts = rand() % 60 + 41;//min is 41

	//randomly assigns name to user and parents
	playerName = rand() % 11;
	momName = rand() % 11;
	dadName = rand() % 11;
	lastNames = playerName % 6;

	string firstMName[] = { "John","Bob","Jimmy","Kobe","Jack","Zack",
		"Morb","Bob","Isaiah","Noah","Kevin" };

	string firstFName[] = { "Brooke","Zoe","Slay","Lisa","Eve","Karen","Martha",
		"Selena","Havanna","Hailey","Bianca" };

	string lastName[] = { "Harrington","Smith","Nguyen","Huang","Marks", "DiOrio" };

	//randomly chooses "male" or "girl" name
	if ((rand() % 2 + 1) == 1)
	{
		startValue.m_name = firstMName[playerName] + ' ';
	}
	else
	{
		startValue.m_name = firstFName[playerName] + ' ';
	}
	startValue.m_name += lastName[lastNames];

	//push dads name into index 0 of vector
	relationships.push_back(firstMName[dadName] + ' ' + lastName[lastNames] + "(Dad)");
	//push relationship of 100 into vector
	relationStats.push_back(100);

	//push moms name into vector
	relationships.push_back(firstFName[momName] + ' ' + lastName[lastNames] + "(Mom)");
	relationStats.push_back(100);
}


void age1To3()
{
	//assigns scenes and results
	//1-3 don't have user prompts
	string sceneLine, word;
	int health, happy, smart;

	//opens file 
	ifstream infantScenes("1-3 infancy.txt");

	if (infantScenes.fail())
	{
		//checks if could be opened
		cout << "unable to open file.";
		infantScenes.close();
		exit(-1);
	}

	//dynamically allocated class array
	randomEvents* infantEvent = new randomEvents[9];

	for (int i = 0; i < 9; i++)
	{
		infantScenes >> word;
		//gets scene line
		getline(infantScenes, sceneLine, '\n');

		//gets the 3 numbers;
		infantScenes >> health >> happy >> smart;

		//assigns stats
		infantEvent[i].events = "   " + sceneLine;
		infantEvent[i].statChange[0] = health;
		infantEvent[i].statChange[1] = happy;
		infantEvent[i].statChange[2] = smart;
	}

	//calls life event with following info
	//the class events, max age, amt of events, how many events per year
	//how much to add up per year(age from 1 to 2), if scenes have choices
	life(infantEvent, 3, 9, 2, 1, false);

	//close array/file
	delete[] infantEvent;
	infantScenes.close();
}

void beginLife()
{
	//introduction at the beginning
	display(startValue, startStats);
	cout << "\nYou, " << startValue.m_name << " are born to two loving parents named\n";
	cout << relationships[0] << " and " << relationships[1] << ".\n";
}