

drawText(char * word,int r,int g,int b,double xStart,double yStart, height)
{
	for(int i = 0;word[i] != '\0';i++)
	{	
		double spacing;
		double width = .750 * height;
		double xUL = xStart + (width * i) + (spacing * i); 
		double yUL = yStart;

		char letter = word[i];

		switch(letter){
			case '2':
				drawChar2(xUL,yUL,height);
				break;
			case '3':
				drawChar3(xUL,yUL,height);
				break;
			case '4':
				drawChar4(xUL,yUL,height);
				break;
			case '7':
				drawChar7(xUL,yUL,height);
				break;
			case '8':
				drawChar8(xUL,yUL,height);
				break;
			case '$':
				drawCharMoney(xUL,yUL,height);
				break;
			case '?':
				drawCharQuestion(xUL,yUL,height);
				break;
			case 'D':
			case 'd':
				drawCharD(xUL,yUL,height);
				break;
			case 'M':
			case 'm':
				drawCharM(xUL,yUL,height);
				break;
			case 'E':
			case 'e':
				drawCharE(xUL,yUL,height);
				break;
			case 'J':
			case 'j':
				drawCharJ(xUL,yUL,height);
				break;
			case 'L':
			case 'l':
				drawCharL(xUL,yUL,height);
				break;
			case 'N':
			case 'n':
				drawCharN(xUL,yUL,height);
				break;
			case 'Y':
			case 'y':
				drawCharY(xUL,yUL,height);
				break;
			case 'Q':
			case 'q':
				drawCharQ(xUL,yUL,height);
				break;
			case 'T':
			case 't':
				drawCharT(xUL,yUL,height);
				break;
			case 'Z':
			case 'z':
				drawCharZ(xUL,yUL,height);
				break;
			case 'U':
			case 'u':
				drawCharU(xUL,yUL,height);
				break;
			case 'C':
			case 'c':
				drawCharC(xUL,yUL,height);
				break;
			case 'R':
			case 'r':
				drawCharR(xUL,yUL,height);
				break;
			case 'I':
			case 'i':
				drawCharI(xUL,yUL,height);
				break;
			case 'V':
			case 'v':
				drawCharV(xUL,yUL,height);
				break;
			case 'H':
			case 'h':
				drawCharH(xUL,yUL,height);
				break;
			case 'S':
			case 's':
				drawCharS(xUL,yUL,height);
				break;
			case 'O':
			case 'o':
				drawLetterO(xUL,yUL,height);
				break;
			
			case '\n': 
		    case '\t':
		    case '\0':
		    case ' ':
				break;
			default:
				drawMissingLetter(xUL,yUL,height);	
			}
	}		
}