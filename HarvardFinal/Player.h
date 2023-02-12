#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <queue>
using namespace std;

//#include "general.h"
#include "Relationships.h"

class playerInfo {
public:
	int m_age;
	string m_name;
	int m_health;
	int m_happy;
	int m_smarts;
	int m_money;

	playerInfo();
	void addPlayerInfo(int, int, int, int);

};


class playerStats {
public:
	string m_school;
	string m_job;
	bool m_uni;
	int m_uniChallengeLvl;
	int m_jobPay;

	playerStats();
	//void addPlayerStats(int);
	friend void operator == (playerStats& grade, string input);
};

extern playerInfo startValue;
extern playerStats startStats;

//finalMain.cpp
char intro();
void userChoice(int ageAmt);
void life(randomEvents* lifeStage, int age, int sceneAmt, int events, int ageAmt, bool choices);
void readResults(randomEvents* lifeStage, int randEvent);
void dead();

//infant.cpp
void randStartStats();
void display(playerInfo info, playerStats stats);
void age1To3();
void beginLife();

//age4-10.cpp
void age4Above(string fileName, int maxAge, int eventAmt);

//Relationships.cpp
void school();
void relationShipChoices();
void minusRelationship();

//jobs.cpp
void jobs();