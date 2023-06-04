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


void readPersonFile(const File this,const char* path){
	
	char* name;
	double balance;
	double depositInEachRound;
	int luckyNumber;

	FILE *file;

	file=fopen(path,"r");

        char* money;
        char* ratio;
        char* number;

		char* line=NULL;
		size_t len;
		int index=0;
	if(file!=NULL){
 
        while(getline(&line,&len,file) != -1){
           
            char * token = strtok(line, "#");       
            int n=0;
            while( token != NULL ) {
                            
                if(n==0)
                    name=token;
                else if(n==1)
                    money=token;
                else if(n==2)
                    ratio=token;
                else number=token;
                token = strtok(NULL, "#");
                n++;
                
            }
			balance=atof(money);
			depositInEachRound=atof(ratio);
			luckyNumber=atoi(number);

			this->person[index++]=new_Kisi(name, balance,depositInEachRound, luckyNumber);

        }
      
	}else{
        
		printf("File Not Found!");
	}
	fclose(file);
	
}
void readNumbersFile(const File this, const char* path){
	FILE *file;

	file=fopen(path,"r");
	int luckyNumber;
	int index=0;
	if(file!=NULL){

        while(!feof(file)){
            fscanf(file,"%d",&luckyNumber);
			this->numbers[index++]=luckyNumber;
        }

	}else{
        
		printf("File Not Found!");
	}
	fclose(file);
}
	 
void delete_File(const File this){
	if(this==NULL) return;
	int i=0;
	for ( i = 0; i < this->numberOfPerson; i++)
	{
		this->person[i]->delete_Person(this->person[i]);
	}
	free(this->numbers);
	free(this);
}
int dosyaBoyutu(const char* file){
	FILE *file;

	file=fopen(file,"r");
	int numberOfLine=0;
    char *line = NULL;
    size_t len = 0;

	if(file!=NULL){

        while(getline(&line,&len,file) != -1){
            numberOfLine++;
        }

	}else{
        
		printf("File Not Found!");
	}
	fclose(file);

	return numberOfLine;
}