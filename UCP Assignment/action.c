#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "settings.h"
#define FALSE 0
#define TRUE !FALSE
/*	actionFunc is the function used for the pointer to a function in main				*
*	and passing it through to the check() function provided for the assignment			*
*																						*
*	Parameters: Takes a word that is from the user file and a suggested word to be		*
*	auto-corrected.																		*
*																						*
*	Returns a value: TRUE or FALSE depending on the decision made by the user,			*
*	or if the the auto-correct value from the settings file is "no".					*/

int actionFunc(char* word, char* suggestion)
{  
	/* Makes the initial decision to be FALSE (do not auto-correct) */
    int decision = FALSE; 
	/* User enters a char value that indicates whether the user wants to autocorrect or not */	
	char change;
	/* Makes a struct for the settings information */
	Settings* settings = (Settings*)malloc(sizeof(Settings)); 
	/* Reads the settings file and allocated the required fields to the struct */
	readSettings(settings);	

	/* If the word to be auto-corrected to is not NULL then... */
	if(suggestion != NULL) 
	{	
		/* From the settings file, if the auto-correct value is yes, then allow to auto-correct */
		if(strcmp(settings->autocorrect, "yes") == 0) 
		{
			decision = TRUE;
		}
		else
		{
			/* Prompt the user to answer if they want the original word changed into the suggested word given */
			printf("Original Word: %s, Suggested Correction: %s\n", word, suggestion);
			printf("Do you want to correct the original word?\n");
			printf("Y - Yes, N - No\n");
			/* Prompts the user for input on whether to auto correct a word */			
			scanf(" %c", &change);
			
			/* If the user inputs 'y' for yes, then allow for the word to change */
			if((change == 'y' || change == 'Y')) 
			{
				decision = TRUE;
			}
			/* If the user inputs 'n' for no, do not change the word into the suggested word */
			else if(change == 'n' || change == 'N') 
			{
				decision = FALSE;
			}
			/* if the input is anything but 'y' or 'n', print an error to the user and don't change. */
			else 
			{
				printf("Word not changed. Input is not 'Y' or 'N' to change the original word\n");
			}
		}
	}
	/* free the memory allocated for settings */
	free(settings); 
	return decision;
}