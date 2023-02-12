#include "Player.h"
#include "Relationships.h"
//#include "general.h"

void age4Above(string fileName, int maxAge, int eventAmt)
{
	//takes file name, age they want to go up to, and amount of events
	//in txt file
	string sceneLine, promptLine, resultLine, wordBuffer;
	int eventLead, health, happy, smart, money, numberBuffer;

	//opens the file for reading
	ifstream Scenes4Above(fileName);

	if (Scenes4Above.fail())
	{
		//checks if accessible
		cout << "unable to open file.";
		Scenes4Above.close();
		exit(-1);
	}

	//dynamically allocated class array
	randomEvents* YouthEvent = new randomEvents[eventAmt];

	for (int i = 0; i < eventAmt; i++)
	{
		Scenes4Above >> wordBuffer;

		//gets lines of @s
		getline(Scenes4Above, sceneLine, '\n');
		YouthEvent[i].events = "   " + sceneLine;

		for (int j = 0; j < 2; j++)
		{
			//repeats twice for both prompts
			Scenes4Above >> wordBuffer;

			//gets @p
			getline(Scenes4Above, promptLine, '\n');

			//stores in class
			YouthEvent[i].prompts[j] = promptLine;

			//reads in the 5 numbers
			Scenes4Above >> eventLead >> health >> happy >> smart >> money;

			if (j == 0)
			{
				//assigns location of 0-4 or 4-9 depending if 1st or 2nd prompt
				YouthEvent[i].statChange[0] = health;
				YouthEvent[i].statChange[1] = happy;
				YouthEvent[i].statChange[2] = smart;
				YouthEvent[i].statChange[3] = money;
				YouthEvent[i].statChange[4] = eventLead;
			}
			else
			{
				YouthEvent[i].statChange[5] = health;
				YouthEvent[i].statChange[6] = happy;
				YouthEvent[i].statChange[7] = smart;
				YouthEvent[i].statChange[8] = money;
				YouthEvent[i].statChange[9] = eventLead;
			}
		}
		if (YouthEvent[i].statChange[4] == 0)
		{
			//checks if the 1st prompt leads to a result

			Scenes4Above >> wordBuffer >> numberBuffer;

			//reads in @r
			getline(Scenes4Above, resultLine, '\n');
			YouthEvent[i].results[1] = resultLine;
		}
		else
		{
			//if both prompts leads to a result statement

			for (int j = 0; j < 2; j++)
			{

				//assign 2 @r statements to the class
				Scenes4Above >> wordBuffer >> numberBuffer;
				getline(Scenes4Above, resultLine, '\n');
				YouthEvent[i].results[j] = resultLine;
			}
		}

	}

	//calls life event with following info
	//the class events, max age, amt of events, how many events per year
	//how much to add up per year(ex 4 to 6), if scenes have choices
	life(YouthEvent, maxAge, eventAmt, 1, 2, true);

	//delete
	delete[] YouthEvent;
	Scenes4Above.close();
}