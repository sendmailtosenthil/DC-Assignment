
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100

typedef struct Node {
    char* word;
    char* meaning;
    struct Node *next;
} Node;

static Node* dictionary[TABLE_SIZE];

unsigned int generateHashKey(char* word){
    unsigned int hash = 0;
    for(; *word ; word++){
        hash = *word + hash * 31;
    }
    return hash % TABLE_SIZE;
}

Node* lookup(char* word){
    int hashKey = generateHashKey(word);
    Node* dict = dictionary[hashKey];
    for(; dict != NULL; dict = dict->next){
        if(strcmp(dict->word, word) == 0){
            return dict;
        }
    }
    return NULL;
}

char* duplicateString(char* input){
    int length = strlen(input) + 1;
    char* output = (char*) malloc(length);
    strcpy(output, input);
    return output;
}

char* addToNode(char* word, char* meaning){
    Node* dict;

    if((dict = lookup(word)) == NULL){
        int hashKey = generateHashKey(word);
        dict = (Node*) malloc(sizeof(Node));
        dict->word = duplicateString(word);
        dict->meaning = duplicateString(meaning);
        dict->next = dictionary[hashKey];
        dictionary[hashKey] = dict;
    } else {
        return NULL;
    }
    return dictionary[generateHashKey(word)]->word;
}

 Node* delete(char* word){
     int hashKey = generateHashKey(word);
     Node* curr = dictionary[hashKey];
     Node* prev = NULL;
     for(; curr != NULL; curr = curr->next){
         if(strcmp(curr->word, word) == 0){
             if(prev == NULL){
                dictionary[hashKey] = curr->next;
             } else {
                 prev->next = curr->next;
             }
             return curr; 
         }
         prev = curr;
     }
     return NULL;
 }
 

char ** newword_1_svc(WM *wwm, struct svc_req *rqstp)
{
	static char * result;
	
	char* addedWord = addToNode(wwm->word, wwm->meaning);
	if(addedWord != NULL) {
		result = addedWord;
	}else{
		result = "";
	}
	
	return &result;
}

char ** searchword_1_svc(char **word, struct svc_req *rqstp)
{
	static char * result;
	Node* dict = lookup(*word);
	if(dict != NULL){
		result = dict->meaning;
	} else {
		result = "";
	}
	return &result;
}

char ** deleteword_1_svc(char ** word, struct svc_req *rqstp)
{
	static char * result;
	Node* dict = delete(*word);
	if(dict != NULL){
		result = dict->meaning;
	}else{
		result = "";
	}	
	return &result;
}
