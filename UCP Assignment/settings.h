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

void readSettings(Settings* settings);
