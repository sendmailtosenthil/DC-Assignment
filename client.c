/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "dictionary.h"
#include <stdio.h>
#include <string.h>

CLIENT* createClient(char* host){
	CLIENT *clnt;
	clnt = clnt_create (host, DICTIONARY, DICTIONARY_VER, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		printf("Invalid host name [%s]", host);
		exit (1);
	}
	return clnt;
}

void dict_1(CLIENT* clnt, char op)
{
	char word[250];	
	char operation[15];
	switch(op){
		case 'I' : 
			strcpy(operation, "Insert");
			break;
		case 'S':
			strcpy(operation, "Search");
			break;
		case 'D':
			strcpy(operation, "Delete");
			break;
		default:
			printf("Unknown Operation, supported (Insert, Search & Delete) Known operations I | S | D\n");
			return;		
	}
	printf("Enter word for %s :", operation);
	scanf("%s", word);

	switch(op){
		case 'I' : {
				char meaning[1000];

				printf("Enter Meaning :");
				scanf(" %[^\n]", meaning);				

				WordWithMeaning* wwm;
				wwm = (WordWithMeaning*) malloc(sizeof(WordWithMeaning));
				wwm->word = (char*) malloc(sizeof(char) * strlen(word));
				strcpy(wwm->word, word);
				wwm->meaning = (char*) malloc(sizeof(char) * strlen(meaning));
				strcpy(wwm->meaning, meaning);

				char** output = newword_1(wwm, clnt);
				if (output == (char **) NULL) {
					clnt_perror (clnt, "call failed");
				}

				printf("Added [%s] to dictionary", *output);
				break;
			}
		case 'S' : {
				char** output = searchword_1((char* []){word}, clnt);
				if (output == (char **) NULL) {
					clnt_perror (clnt, "call failed");
				}
				printf("For [%s], meaning is [%s]", word, *output);
				break;
			}
		case 'D': {
				char** output = deleteword_1( (char*[]) {word}, clnt);
				if (output == (char **) NULL) {
					clnt_perror (clnt, "call failed");
				}
				if(strcmp(*output,"") == 0){
					printf("Not found [%s] to delete", word);	
				}else{
					printf("Deleted [%s] from dictionary", word);
				}
				break;
			}
		default: {
			printf("Unknown Operation, supported (Insert, Search & Delete) Known operations I | S | D\n");
			break;
		}
	};
	
}


int main (int argc, char *argv[])
{
	
	char host[100];
	char inputOption;
	char inputWord[250];
	char inputMeaning[1000];

	printf("To quit the app, press Ctrl+C\n");
	printf("Enter the server hostname :");
	scanf("%100[^\n]", host);
	
	CLIENT* clnt = createClient(host);

	printf("Provide Your options to work on Dictionary App");
	while(1) {
		printf("\nI for Insert, S for Search, D for Delete :");
		scanf(" %c", &inputOption);
		dict_1 (clnt, inputOption);		
	}
	
	clnt_destroy (clnt);

	exit (0);
}
