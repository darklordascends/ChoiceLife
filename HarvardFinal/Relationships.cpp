#include "Player.h"
#include "Relationships.h"

void minusRelationship()
{
	//subtracts a random amount for relationships
	//every time user ages up
	int i = 0;
	if (startValue.m_age < 14)
	{
		//if age is less than 14 then dont subtract from the parents
		i = 2;
	}

	for (i; i < relationStats.size(); i++)
	{
		//subtracys for every person
		relationStats[i] -= rand() % 6;
	}

	for (int i = 0; i < relationStats.size(); i++)
	{
		//deletes relationship if status is under 25
		if (relationStats[i] <= 30)
		{
			cout << endl << relationships[i] << " no longer wants to interact with you.\n";
			cout << "Relationship broken off . . \n\n";

			//deletes from vector
			relationships.erase(relationships.begin() + i);
			relationStats.erase(relationStats.begin() + i);
		}
	}

}

void spendTime()
{
	//choose who to spend time with and activity to do
	int userInput, activity, relationshipPts;
	string activities[] = { "go to the park","play video games","watch a movie","have a conversation" };

	//asks for number next to name
	cout << "\nWho would you like to spend time with?\n";
	cout << "Enter the number next to the persons name: ";
	cin >> userInput;

	cout << "\nWhat activity would you like to do with ";
	cout << relationships[userInput - 1] << "?\n";

	//displays activities
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << ". " << activities[i] << endl;
	}
	cout << "Enter your choice: ";
	cin >> activity;

	cout << "\nYou " << activities[activity - 1] << " with " << relationships[userInput - 1] << ".\n";

	//randomly adds a number to relationship points
	relationshipPts = rand() % 15;
	relationStats[userInput - 1] += relationshipPts;

	//assigns relationship to 100 if it goes above
	(relationStats[userInput - 1] > 100) ? (relationStats[userInput - 1] = 100) : 0;

	//depending on pts earned, display a diff message
	if (relationshipPts >= 10)
	{
		cout << "You guys has great fun!\n";
	}
	else if (relationshipPts >= 4)
	{
		cout << "You guys had some fun.\n";
	}
	else
	{
		cout << "It wasn't super enjoyable.\n";
	}

	cout << "+" << relationshipPts << " added to your relationship!\n";

}

void makeFriends()
{
	//choose a new friend from list of ppl
	string name;
	int userInput;
	int i = 1;

	//open file
	ifstream classList("name list.txt");

	//output file
	ostringstream formatClass;
	system("ClS");

	if (classList.fail())
	{
		//check if file can open
		cout << "unable to open file.";
		classList.close();
		exit(-1);
	}

	classList >> name;
	while (!classList.eof())
	{
		//grabs a name and add to output file until end of file
		classList >> name;

		formatClass << i << ". " << name << endl;
		i++;
	}

	//display output stream
	cout << formatClass.str();

	cout << "Which classmates do you want to be friends with?(Enter number) ";
	cin >> userInput;

	//open file
	ifstream classLists("name list.txt");
	i = 0;

	while (!classLists.eof())
	{
		classLists >> name;
		//repeats until number matches a user
		if (i == userInput)
			break;
		i++;
	}

	cout << endl << name << " is now your friend!\n";

	//add friend to vector with random relationship status 50-59
	relationships.push_back(name + "(Friend)");
	relationStats.push_back(rand() % 10 + 50);

	classList.close();
	classLists.close();
}

void findDate()
{
	//uses a queue!
	string name;
	string checkName;
	char userInput;
	bool dating = false;

	//static prevents repeats
	static queue<string> dates;

	//opens list for reading
	ifstream classList("name list.txt");
	ostringstream formatClass;
	system("ClS");

	if (classList.fail())
	{
		cout << "unable to open file.";
		classList.close();
		exit(-1);
	}

	classList >> name;
	while (!classList.eof())
	{
		//repeats until end of file
		classList >> name;

		//push name in to queue
		dates.push(name);
	}

	do
	{
		cout << "Would you like to date " << dates.front() << "? (Y/N)\n";
		//asks user if they want to date the name at front of queue
		cin >> userInput;

		if (toupper(userInput) == 'Y')
		{
			//if yes display message
			cout << "You are now dating " << dates.front() << " <3 4lyfers\n";

			//push name and status into vectors
			relationships.push_back(dates.front() + "(Dating)");
			relationStats.push_back(rand() % 10 + 90);

			dating = true;
			//deletes name from queue
			dates.pop();
		}
		else
		{
			cout << "OK next!\n\n";
			//deletes name at front
			dates.pop();
		}

		//repeats until dating someone
	} while (dating == false);


	//loop checks if you are already dating someone
	//if you are, they break up with you
	for (int i = 2; i < relationships.size() - 1; i++)
	{
		checkName = relationships[i];

		//gets substring
		checkName = checkName.substr(checkName.length() - 8, checkName.length() - 1);

		if (checkName == "(Dating)")
		{
			cout << endl << relationships[i] << " broke up with you for cheating on them >:(\n";

			//delete name and status from vector
			relationships.erase(relationships.begin() + i);
			relationStats.erase(relationStats.begin() + i);
		}
	}
}

void unfriend()
{
	//lets user unfriend someone
	int userInput;
	cout << "\nWho would you like to unfriend?\n";
	cout << "Enter the number next to the persons name or 0 to return: ";
	cin >> userInput;

	if (userInput == 0)
	{
		return;
	}

	if (userInput <= 2)
	{
		//if inoputs 1-2 displays message
		cout << "You can not unfriend your parents!\n";
		return;
	}

	//deletes name and status from vector
	cout << "\nYou have unfriended " << relationships[userInput - 1] << " :( \n";
	relationships.erase(relationships.begin() + userInput - 1);
	relationStats.erase(relationStats.begin() + userInput - 1);

}

void relationShipChoices()
{
	//function that calls the other functions
	int userInput;
	system("CLS");

	cout << "Relationships - Status(0-100):\n";

	//displays person and their relationship status
	for (int i = 0; i < relationships.size(); i++)
	{
		cout << i + 1 << ". " << relationships[i] << ' ' << relationStats[i] << endl;
	}

	do
	{
		cout << "\nWhat would you like to do?\n";
		cout << "1. Spend time with someone.\n";
		cout << "2. Make new friends.\n";
		cout << "3. Find someone to date.\n";
		cout << "4. Unfriend someone.\n";
		cout << "5. Return.\n";
		cout << "Enter your choice: ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
			spendTime();
			break;
		case 2:
			makeFriends();
			break;
		case 3:
			//makes sure user us of age
			if (startValue.m_age >= 12)
			{
				findDate();
			}
			else
			{
				cout << "!! Wait till you are 12!!\n";
				userInput = 6;
			}

			break;
		case 4:
			unfriend();
			break;
		case 5:
			return;
			break;
		default:
			cout << "Invalid input\n";
		}
		//repeats until valid input
	} while (userInput > 5 || userInput < 1);
}