/*	Template for using gfx2 library
 *		Opens window using xy params, sets color,
 *		waits for user to press q to quit
 */



int main(int argc,char* argv[])
{
	
	double xSize = 600;
	double ySize = 600;
	char c;
	
	gfx_open(xSize,ySize,"Graphics Program");

	//R,G,B
	gfx_color(0,200,100);



	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

	return 0;
	
}	
