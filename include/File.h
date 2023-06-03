/**
*
* @author SEIDY KANTE
* <p>
*		Header file of file reading structure
* </p>
*/
#ifndef FILE_H
#define FILE_H

#include "Person.h"

struct FILE{
	
	int numberOfPerson;
	int roundNumber;

	Person* person;
    int* numbers;

	void(*readPersonFile)(struct FILE*,const char*);
	void(*readNumbersFile)(struct FILE*,const char*);
	
	void(*delete_File)(struct FILE*);
	
};

typedef struct FILE* File;

File new_File(char*, char*);

void readPersonFile(const File,const char*);
void readNumbersFile(const File, const char*);

void delete_File(const File);


#endif