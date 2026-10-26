#include <stdio.h>
#include <conio.h>
#include <dos.h>

int main()
{
	int x, y;
	clrscr();
	textcolor(BLUE+BLINK);
	gotoxy(22, 20);
	cprintf("UNIVERSIDAD NACIONAL DE INGENERIA"); 
	/*letra u */
	/*linea vertical*/ 
    for ( y= 5; y <= 15; y++)
    {
        gotoxy(15 , y);
        textcolor(BLUE);
        cprintf("%c%c%c%c%c%c%c", 219,219,219,219,219,219,219);
		delay(100);
    }

	/*linea horizontal de la letra u*/
	for ( x= 15; x <= 35; x++) 
    {										
        gotoxy(x , 15);                            
		cprintf("%c", 219);
		gotoxy(x , 16);
		cprintf("%c", 219);
		gotoxy(x , 17);
		cprintf("%c", 219);
		delay(100);
        textcolor(BLUE);   
    }

	/*linea vertical de la letra u*/
	for ( y= 17; y >= 10; y--)
    {							  			
        gotoxy(36, y);                            
		cprintf("%c%c%c%c%c%c%c", 219,219,219,219,219,219,219); 
		delay(100);
        textcolor(BLUE);   
    }

	/*letra N*/
	/*linea vertical*/
	for ( y= 5; y <= 13; y++)
    {							  			
        gotoxy(26, y);                            
		cprintf("%c%c%c%c%c%c%c", 219,219,219,219,219,219,219); 
		delay(100);
        textcolor(BLUE);   
    }

	/*linea horizontal de la letra N*/
	/*linea horizontal*/
	for ( x= 26; x <= 47; x++)
    {							  			
        gotoxy(x , 5);                            
		cprintf("%c", 219); 
		gotoxy(x , 6);                            
		cprintf("%c", 219);
		gotoxy(x , 7);
		cprintf("%c", 219);
		delay(100);
        textcolor(BLUE);   
		/*delay(100);
        textcolor(BLUE); */  
    }

	/*linea vertical de la N*/
	for ( y= 5; y <= 17; y++)
    {							  			
        gotoxy(47, y);                          
		cprintf("%c%c%c%c%c%c%c", 219,219,219,219,219,219,219); 
		delay(100);
        textcolor(BLUE);   
    }

	/*letyra i*/
	/*linea horizontal de la i */ 
	for ( x= 47; x <=57; x++) 
    {							  			
        gotoxy(x , 17);                          
		cprintf("%c", 219); 
		gotoxy(x , 16);                            
		cprintf("%c", 219);
		gotoxy(x , 15);
		cprintf("%c", 219);
		delay(100);
        textcolor(BLUE);   
    }


	/*linea vertical de la i*/
	for ( y= 17; y >= 9; y--)
    {							  			
        gotoxy(57, y);                          
		cprintf("%c%c%c%c%c%c%c", 219,219,219,219,219,219,219); 
		delay(100);
        textcolor(BLUE);   
    }

	/*cuadrito de la i*/
	for ( x= 57; x <=63; x++) 
    {							  			
        gotoxy(x, 5);                          
		cprintf("%c", 219); 
		gotoxy(x , 6);                            
		cprintf("%c", 219);
		gotoxy(x , 7);
		cprintf("%c", 219);
		delay(100);
        textcolor(BLUE);   
    }

	/*---------------------------------------------------------------------------------------------*/


	getch();
  return 0;
}
