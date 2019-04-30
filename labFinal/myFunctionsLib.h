/*	myFunctionsLib.h
 *		header file for myFunctionsLib.c
 *
 *
 */
 
 //===== defining structure mtgCardType =====//
typedef struct mtgCardType
{
	char title[51]; 
	int manaCost;	// pretending all cards are colorless
	char spellType[15];	// creature, enchantment, etc
	int power;
	int toughness;
	
	struct mtgCardType * nextCard;	// pointer to next structure in linked list
	 
} mtgCardType;



//========== function headers ==========// 
 
 void swapNumbers(double a, double b);
 
 void sortNumbers(double list[], int size);
 
 void sortVisualize(double list[],int size);
 
 mtgCardType * sortCardsByTitle(mtgCardType * topOfList);
