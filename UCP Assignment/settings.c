#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "settings.h"

/*	readSettings read the settings file 'spellrc' with the variables dictionary, maxcorrection	*
*	and autocorrect. dictionary being the dictionary file the program will use as its			*
*	dictionary, maxcorrection being the number of different letters for the word being mispelt	*
*	to be changed into a word from the dictionary, and autocorrect having the value to tell		*
*	the program whether to automatically correct the spelling of the mispelt word.				*/

void readSettings(Settings* settings)
{		
		/* Open the spellrc file for reading */
		FILE* f = fopen("spellrc", "r"); 
		/* Makes the number of items read as 1 so that it isn't the end-of-file */
		int readN = 1; 
		/* done is the flag to show when the do-while loop stops. */
		/* maxcorVal is the number of letters for the mispelt word to be different for spellchecking */
		int done = 0, maxcorVal;  
		/* Dynamically allocating a 50 character array including null terminator '\0' */
		char* varName = (char*)malloc(51 * sizeof(char));
		/* Name of the dictionary has a maximum of 50 characters plus the '\0' (null terminator) */ 
		char dictionaryName[51]; 
		/* Value of the auto-correction option: yes or no, plus the '\0' (null terminator) */
		char autocorVal[4]; 
		
		
		/* If the file isn't opened correctly, throw an error message */
		if(f == NULL) 
		{
			perror("Error in opening file for readSettings");
		}
		/* Otherwise, start reading the settings file */
		else 
		{
				do
				{
						/* read the variable in the file */
						readN = fscanf(f, "%s = ", varName); 
						/* If it reads the end of file, stop the loop */
						if(readN == EOF) 
						{
							done = 1;
						}
						/* Otherwise, continue */
						else 
						{
							/* If the variable is "dictionary", then read the dictionary filename and store it into the settings struct. */
							if(strcmp(varName, "dictionary") == 0) 
							{
								/* read dictionary filename */
								fscanf(f, "%s", dictionaryName); 
								
								/* If the dictionary name is NULL, then no dictionary is found */
								if(dictionaryName == NULL) 
								{
									printf("Dictionary not found");
								}
								else
								{
									/* makes the name of the dictionary file in the struct as the name read from the file */
									strcpy(settings->dictionary, dictionaryName); 
								}
							}
							/* If the variable is maxcorrection */
							else if(strcmp(varName, "maxcorrection") == 0) 
							{
								/* read the maxcorrection integer */
								fscanf(f, "%d", &maxcorVal); 
								
								/* If the maxcorrection value is less than 0, throw an error message */
								if(maxcorVal < 0) 
								{
									printf("Max Correction Value cannot be negative");
								}
								else
								{
									/* make the value of the maxcorrection value in the struct with the value read from the file */
									settings->maxCorrection = maxcorVal; 
								}
							}
							/* if the variable is autocorrect */
							else if(strcmp(varName, "autocorrect") == 0) 
							{
								/* read the value for autocorrect */
								fscanf(f, "%s", autocorVal); 
								
								/* if the value of autocorrect is either yes or no, then assign it to the field in the struct */
								if(strcmp(autocorVal, "yes") == 0 || strcmp(autocorVal, "no") == 0) 
								{
									/* allocate the setting's autocorrect field as the value read from the file */
									strcpy(settings->autocorrect, autocorVal); 
								}
								else
								{
									/* otherwise, if it is not 'yes' or 'no', throw an error message */
									printf("Autocorrect value is not Yes or No."); 
								}
							}
						}
				}while(!done);
		}
		
		/* close the file being read */
		fclose(f); 
		/* free the variable name that was used to read in from the file */
		free(varName); 
}

