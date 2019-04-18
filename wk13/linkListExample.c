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

/*

// function to read data and build list of cards...
mtgCardType* loadCardList(   ) // for now no params, later a filename...
{	//think about edge cases.. what do we do with first/last items
	/* loop until EOF: read data for one card
	 *			allocate memory to store that data
	 *			copy data into a new struct
	 *			make sure the previous card in the list has "next" pointing to new card
	 */			
/*	 
	char line[100];
	// in declaration, * means "pointer to"
	mtgCardType * newCardPtr = NULL;
	mtgCardType * lastCardInList = NULL;
	mtgCardType * firstCardInList = NULL;
	
	while(! feof(stdin))		// user can simulate EOF with ctrl + d
	{	
		// for now just handling the title.. 
		fgets(line, 100, stdin);
		// allocating mem for new card struct
		newCardPtr = (mtgCardType *) malloc(sizeof(mtgCardType)); 
		// malloc returns a generic "void" pointer
		// so typecast to correct pointer
		
		// NEW STUFF!!!
		strcopy( (*newCardPtr).title, line); // * in front of a pointer value means
														// the thing pointed to. In this case, a
														// mtgCardType struct
		
		if(firstCardInList != NULL)	// 
		{
			// how do we get this new structure into the list we are building?
			// need to keep track of last card in the list so we can add a new card to end
			// for now, writing code assuming we have a variable pointing to last card in list
			(*lastCardInList).nextCard = newCardPtr;	// this will add new card to end of list
			// cannot do this step when list is empty because last card in list
			// will not be pointing to anything
		} else {
			// what to do if list is empty and we are adding first item
			firstCardInList = newCardPtr;
			lastCardInList = newCardPtr;
		}
		
		(*newCardPtr).nextCard = NULL;
		// now lets come back to how we keep track of end of list?
		lastCardInList = newCardPtr;
		// new card is now last in list, so make sure its "next" pointer is NULL
		//(*lastCardInList).nextCard = NULL;
		//(*newCardPtr).nextCard = NULL; // alternate for above line
		
	}
	
	return firstCardInList;
}

*/

// function to read data and build list of cards...
mtgCardType* loadCardList(){ // for now no params, later a filename...
	
	char line[100];
	mtgCardType * newCardPtr = NULL;
	mtgCardType * lastCardInList = NULL;
	mtgCardType * firstCardInList = NULL;
	
	while (! feof(stdin)){	
		// read data for next card
		fgets(line, 100, stdin);
		// create new card
		newCardPtr = (mtgCardType *) malloc(sizeof(mtgCardType)); 
		strcopy( (*newCardPtr).title, line); 
		(*newCardPtr).nextCard = NULL;
		
		// inserting new card into list, making sure to catch edge case of first card
		if (firstCardInList != NULL){
			(*lastCardInList).nextCard = newCardPtr;	
		} else {
			firstCardInList = newCardPtr;
		}
		// update lastCardInList to point to new last card
		lastCardInList = newCardPtr;
	}
	
	// return pointer to beginning of list to calling func so it can access list
	return firstCardInList;
}


int main(int argc, char *argv[]) {

	mtgCardType * topOfCardList1;
	mtgCardType * topOfCardList2;
	
	printf("Please enter list of card titles... \n");

	topOfCardList1 = loadCardList(); // all the reading input and memory alloc to 
									// build list will be inside loadCardList func

	printf("----------------------------------------\n");
	printf("Please enter another list of card titles...\n);
	topOfCardList2 = loadCardList();

	// after loading, main program has a pointer to list to do other things with it
	// such as sorting it, printing it, searching it for cards

	return 0;
}
