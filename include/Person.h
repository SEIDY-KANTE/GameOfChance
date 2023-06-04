/**
*
* @author SEIDY KANTE seidy.kante@ogr.sakarya.edu.tr
* <p>
*		Header file of the structure of people to play the game
* </p>
*/
#ifndef PERSON_H
#define PERSON_H

#include "Game.h"
#include <string.h>

struct PERSON{
	char* name;
	double money;
	float depositInEachRound;
	int luckyNumber;
	
	void(*play)(struct PERSON*,struct GAME*, int);
	
	void(*delete_Person)(struct PERSON*);
	
};

typedef struct PERSON* Person;

Person new_Person(char*,double,float,int);

void play(const Person, const Game,int);

void delete_Person(const Person);


#endif