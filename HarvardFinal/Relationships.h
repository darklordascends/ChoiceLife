#pragma once
#include "Player.h"

//accessible across files
extern vector <string> relationships;
extern vector <int> relationStats;

class randomEvents {
public:
	string events;
	string prompts[2];
	string results[2];
	int statChange[10];
	randomEvents();
};