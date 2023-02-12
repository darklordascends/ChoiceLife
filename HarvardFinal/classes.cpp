#include "Player.h"
#include "Relationships.h"

//default constructor
playerStats::playerStats() :m_school("Not in School"), m_job("None"), m_uni(false), m_uniChallengeLvl(0), m_jobPay(0)
{}

//default constructor
playerInfo::playerInfo() :m_age(0), m_name(""), m_health(0), m_happy(0), m_smarts(0), m_money(0)
{}

//default constructor
randomEvents::randomEvents() :
	events("None"), prompts{ "None","None" }, results{ "None","None" }, statChange{ 0 }
{}

void playerInfo::addPlayerInfo(int health, int happy, int smarts, int money)
{
	//prints the update
	cout << "\nSTATS UPDATE\n<HEALTH,HAPPINESS,SMARTNESS,MONEY>\n";
	cout << "< " << health << ", " << happy << ", ";
	cout << smarts << ", $" << money << " >\n";

	//adds to data members
	m_health += health;
	m_happy += happy;
	m_smarts += smarts;
	m_money += money;

	//makes sure health, happy, and smart do not go over 100 or under 0
	//if under or over, set to 0/100
	if (m_health > 100 || m_health < 0)
	{
		(m_health > 100) ? m_health = 100 : m_health = 0;
	}
	if (m_happy > 100 || m_happy < 0)
	{
		(m_happy > 100) ? m_happy = 100 : m_happy = 0;
	}
	if (m_smarts > 100 || m_smarts < 0)
	{
		(m_smarts > 100) ? m_smarts = 100 : m_smarts = 0;
	}
}

void operator == (playerStats& grade, string input)
{
	//simplifies coding
	//sets school to string
	grade.m_school = input;
}