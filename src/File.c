/**
*
* @author SEIDY KANTE
* <p>
*		Implementation of file reading structure
* </p>
*/
#include "File.h"

int fileSize(const char*);

File new_File(char* personFile, char* numbersFile){
	File this;
	this=(File)malloc(sizeof(struct FILE));
	
	this->numberOfPerson=fileSize(personFile);
	this->roundNumber=fileSize(numbersFile);
	
	this->person=(Person*)malloc(sizeof(struct PERSON)*this->numberOfPerson);
	this->numbers=(int*)malloc(sizeof(int)*this->roundNumber);
	
	this->readPersonFile=&readPersonFile;
	this->readNumbersFile=&readNumbersFile;
	
	this->delete_File=&delete_File;
	
	return this;
	
}