The following is a summary of the bugs introduced during the refactoring of dominion.c 
Play Adventurer
	while (Z-1 >=0) 
	is now
	while(Z+1 >=0) 
Play Smithy
	for (i = 0; i < 3; i++)
	is now 
	 for (i = 0; i < 6; i++)

Play Steward
	if (choice1 == 1)
	is now
	if (choice1 <= 1)
	
	else if (choice1 == 2)
	is now  
	else if (choice1 != 2)
Play Council Room
	for (i = 0; i < 4; i++)
 	is now 
	for (i = 1; i < 8; i++)



Play Village

	No change