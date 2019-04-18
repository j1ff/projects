#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tagNames[100][16] = {"Elf", "Goblin", "Undead", "Giant"};


typedef struct mtgCardType
{
	char title[51]; 
	char spellType[15];	// creature, enchantment, etc
	int tags[5]; 	// this array could have { 3,2,0,?,? } for giant undead elf
	int tagCount;	// would be 3 for above example 
	
	char rules[200];
	
	char flavorText[200];
	
	int power;
	int toughness;
	int manaCost;	// pretending all cards are colorless
	
	 mtgCardType * nextCard;
	 
} mtgCardType;

// function to read data and build list of cards...
mtgCardType* loadCardList(???????) // for now no params, later a filename...
{	//think about edge cases.. what do we do with first/last items
	/* loop until EOF: read data for one card
	 *			allocate memory to store that data
	 *			copy data into a new struct
	 *			make sure the previous card in the list has "next" pointing to new card
	 */			
	 
	char line[100];
	mtgCardType * newCardPtr;
	mtgCardType * lastCardInList;
	
	while(! feof(stdin))		// user can simulate EOF with ctrl + d
	{
		// for now just handling the title.. 
		fgets(line, 100, stdin);
		newCardPtr = malloc(sizeof(mtgCardType));
		// NEW STUFF!!!!!
		
		strcopy( (*newCardPtr).title, line); // * in front of a pointer value means
														// the thing pointed to. In this case, a
														// mtgCardType struct
		// how do we get this new structure into the list we are building?
		// need to keep track of last card in the list so we can add a new card to end
		// for now, writing code assuming we have a variable pointing to last card in list
		(*lastCardInList).nextCard = newCardPtr;	// this will add new card to end of list
		
		// now lets come back to how we keep track of end of list?
		lastCardInList = newCardPtr;
		
		// new card is now last in list, so make sure its "next" pointer is NULL
		
		(*lastCardInList).nextCard = NULL;
		
	}


	
}

int main(int argc, char *argv[])
{
	mtgCardType * topOfCardList;

	topOfCardList = loadCardList(); // all the reading input and memory alloc to 
									// build list will be inside loadCardList func

	// after loading, main program has a pointer to list to do other things with it
	// such as sorting it, printing it, searching it for cards



	return 0;

}
