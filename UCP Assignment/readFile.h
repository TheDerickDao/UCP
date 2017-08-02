/*	Settings struct contains the name of the dictionary,	*
*	the number of max numbers of characters to identify		*
*	to spell check, autocorrect specifies whether to auto-	*
*	correct or not											*
*	If SETTINGS isn't defined, then define it				*/

#ifndef SETTINGS
#define SETTINGS
typedef struct{
	char dictionary[51];
	int maxCorrection;
	char autocorrect[4];
} Settings;
#endif

/*	Structs defined to create a linked list 		*
*	The list contains a head (first element)		*
*	and the number of nodes in the list (count).	*
*	Each node contains a word and a pointer to the	*
*	next node (next)								*/

typedef struct LinkedListNode{
	char word[51];
	struct LinkedListNode* next;
} LinkedListNode;

typedef struct{
	struct LinkedListNode* head;
	int count;
} LinkedList;

LinkedList* makeDictionary(Settings* settings);
void listToArray(char** array, LinkedList* list, int arrayLength);
LinkedList* readUserFile(Settings* settings, char* filename);
void freeList(LinkedList* list);
void writeFile(char** array, char* filename, int arrayLength);
