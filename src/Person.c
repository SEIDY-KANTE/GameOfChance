/**
*
* @author SEIDY KANTE seidy.kante@ogr.sakarya.edu.tr
* <p>
*		Implementation of the game players structure
* </p>
*/

#include "Person.h"

Person new_Person(char* name,double money,float depositInEachRound,int luckyNumber){
	Person this;
	
	this=(Person)malloc(sizeof(struct PERSON));
	this->name=malloc(sizeof(char)*(strlen(name) + 1));
	memcpy(this->name, name,strlen(name) + 1);
	this->money=money;
	this->depositInEachRound=depositInEachRound;
	this->luckyNumber=luckyNumber;
	
	this->play=&play;
	this->delete_Person=&delete_Person;
	
	return this;

}

void play(const Person this, const Game that, int luckyNumber){

	double balance=this->money;
	double deposit = balance*this->depositInEachRound;
	this->money-=deposit;  
	that->tableBalance+=deposit;

	if(this->luckyNumber==luckyNumber){
		that->tableBalance-=deposit*10;
		this->money+=deposit*10;
	}	

}

void delete_Person(const Person this){
	if(this==NULL) return;
	free(this);
}