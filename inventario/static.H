#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*void pro(int progress, int x, int y) {
    int barLength = 50, i;
    int numChars = (int)(((float)progress / 100) * barLength);
    gotoxy(x, y);
    printf("");
    for (i = 0; i < barLength; i++) {
        if (i < numChars) {
            printf("%c",223);
        } else {
            printf(" ");
        }
    }
    printf(" %d%%", progress);
}

int main() {
	    int progress = 0;
    int centerX = 40; 
    int centerY = 12; 
    int x = centerX - 26; 
    int y = centerY;
    clrscr();
    
    while (progress <= 100) {
        progressBar(progress, x, y);
        delay(100);
        progress++;
    }

    return 0;
}*/


void adios()
{
 	int x, y;
  	clrscr();
  
  for (y= 2; y <= 2; y++)
    {
        textcolor(GREEN + BLINK);
        gotoxy(38, y);
        cprintf("%c%c%c%c", 219,219,219,219); 
    }

  for (y= 4; y <= 5; y++)
  {
      textcolor(GREEN + BLINK);
      gotoxy(38, y);
      cprintf("%c%c%c%c", 219,219,219,219); 
  }

  for ( x= 34; x <= 46; x++) 
    {
        gotoxy(x , 5);
        cprintf("%c", 219);
        
    }

  for (y= 7; y <= 7; y++)
  {
      textcolor(GREEN + BLINK);
      gotoxy(25, y);
      cprintf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219,219,219,219, 219,219,219,219, 219,219,219,219, 219,219,219,219, 219,219,219,219, 219,219,219,219, 219, 219, 219, 219, 219, 219, 219, 219, 219); 
  }

  for (y= 8; y <= 8; y++)
  {
      textcolor(GREEN + BLINK);
      gotoxy(31, y);
      cprintf("%c%c%c%c%c", 219,219,219,219, 219); 
  }

  for (y= 8; y <= 8; y++)
  {
      textcolor(GREEN + BLINK);
      gotoxy(46, y);
      cprintf("%c%c%c%c%c", 219,219,219,219, 219); 
  }
  
  for (y= 10; y <= 10; y++)
  {
      textcolor(GREEN + BLINK);
      gotoxy(31, y);
      cprintf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219, 219,219,219,219, 219,219,219,219, 219,219,219,219, 219, 219, 219, 219, 219, 219, 219, 219, 219); 
  }

  for (y= 11; y <= 11; y++)
  {
      textcolor(GREEN + BLINK);
      gotoxy(13, y);
      cprintf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219,219,219,219,219, 219, 219, 219, 219, 219, 219, 219, 219, 219,219, 219,219,219,219, 219,219,219,219, 219,219,219,219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,219, 219, 219, 219,219,219,219, 219,219,219,219, 219,219,219,219, 219, 219, 219, 219, 219, 219, 219, 219, 219); 
  }
for (y= 13; y <= 14; y++)
  {
      textcolor(GREEN + BLINK);
      gotoxy(23, y);
      cprintf("%c%c%c", 219,219,219); 
  }

  for ( x= 17; x <= 23; x++) 
    {
        gotoxy(x , 14);
        cprintf("%c", 219);
        
    }
  for (y= 13; y <= 14; y++)
  {
      textcolor(GREEN + BLINK);
      gotoxy(17, y);
      cprintf("%c%c%c", 219,219,219); 
  }

  for (y= 13; y <= 13; y++)
  {
      textcolor(GREEN + BLINK);
      gotoxy(31, y);
      cprintf("%c%c%c%c%c%c%c%c", 219,219,219,219, 219, 219, 219, 219); 
  }

  for (y= 13; y <= 13; y++)
  {
      textcolor(GREEN + BLINK);
      gotoxy(43, y);
      cprintf("%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219); 
  }

  for ( x= 34; x <= 47; x++) 
    {
        gotoxy(x , 14);
        cprintf("%c", 219);
        
    }
    

  for (y= 13; y <= 14; y++)
  {
      textcolor(GREEN + BLINK);
      gotoxy(56, y);
      cprintf("%c%c%c", 219,219,219); 
  }

  for ( x= 56; x <= 62; x++) 
    {
        gotoxy(x , 14);
        cprintf("%c", 219);
        
    }
  for (y= 13; y <= 14; y++)
  {
      textcolor(GREEN + BLINK);
      gotoxy(62, y);
      cprintf("%c%c%c", 219,219,219); 
  }

	gotoxy(31,21);
  	textcolor(LIGHTGREEN);cprintf("H");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("A");
  	delay(100);
	textcolor(LIGHTGREEN);cprintf("V");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("E");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf(" - ");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("A");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf(" - ");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("G");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("O");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("O");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("D");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf(" - ");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("T");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("R");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("I");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("P");
  	delay(100);



  getch();
}
void dujujodelogo()
{
    int x, y;

    for (y = 5; y <= 10; y++)
    {
        gotoxy(18, y);
        textcolor(BLUE);
        cprintf("%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219);
        delay(100);
    }

    for (x = 18; x <= 35; x++)
    {
        gotoxy(x, 11);
        cprintf("%c", 219);
        gotoxy(x, 12);
        cprintf("%c", 219);
        gotoxy(x, 13);
        cprintf("%c", 219);
        delay(100);
        textcolor(BLUE);
    }

    for (y = 13; y >= 8; y--)
    {
        gotoxy(35, y);
        cprintf("%c%c%c%c%c", 219, 219, 219, 219, 219, 219);
        delay(100);
        textcolor(BLUE);
    }

    for (y = 7; y <= 9; y++)
    {
        gotoxy(27, y);
        cprintf("%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219);
        delay(100);
        textcolor(BLUE);
    }

    for (x = 27; x <= 47; x++)
    {
        gotoxy(x, 5);
        cprintf("%c", 219);
        gotoxy(x, 6);
        cprintf("%c", 219);
        delay(100);
        textcolor(BLUE);
    }

    for (y = 5; y <= 13; y++)
    {
        gotoxy(42, y);
        cprintf("%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219);
        delay(100);
        textcolor(BLUE);
    }

    for (x = 42; x <= 52; x++)
    {
        gotoxy(x, 11);
        cprintf("%c", 219);
        gotoxy(x, 12);
        cprintf("%c", 219);
        gotoxy(x, 13);
        cprintf("%c", 219);
        delay(100);
        textcolor(BLUE);
    }

    for (y = 13; y >= 8; y--)
    {
        gotoxy(50, y);
        cprintf("%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219);
        delay(100);
        textcolor(BLUE);
    }

    for (x = 50; x <= 55; x++)
    {
        gotoxy(x, 5);
        cprintf("%c", 219);
        gotoxy(x, 6);
        cprintf("%c", 219);
        gotoxy(x, 6);
        cprintf("%c", 219);
        delay(100);
        textcolor(BLUE);
    }
    system("cls");
}


void hola()
{
 	int x, y;
  	clrscr();
  
  for (y= 2; y <= 2; y++)
    {
        textcolor(WHITE);
        gotoxy(38, y);
        cprintf("%c%c%c%c", 219,219,219,219); 
    }

  for (y= 4; y <= 5; y++)
  {
      textcolor(RED);
      gotoxy(38, y);
      cprintf("%c%c%c%c", 219,219,219,219); 
  }

  for ( x= 34; x <= 46; x++) 
    {
        gotoxy(x , 5);
        cprintf("%c", 219);
        
    }

  for (y= 7; y <= 7; y++)
  {
      textcolor(WHITE);
      gotoxy(25, y);
      cprintf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219,219,219,219, 219,219,219,219, 219,219,219,219, 219,219,219,219, 219,219,219,219, 219,219,219,219, 219, 219, 219, 219, 219, 219, 219, 219, 219); 
  }

  for (y= 8; y <= 8; y++)
  {
      textcolor(WHITE);
      gotoxy(31, y);
      cprintf("%c%c%c%c%c", 219,219,219,219, 219); 
  }

  for (y= 8; y <= 8; y++)
  {
      textcolor(WHITE);
      gotoxy(46, y);
      cprintf("%c%c%c%c%c", 219,219,219,219, 219); 
  }
  
  for (y= 10; y <= 10; y++)
  {
      textcolor(WHITE);
      gotoxy(31, y);
      cprintf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219, 219,219,219,219, 219,219,219,219, 219,219,219,219, 219, 219, 219, 219, 219, 219, 219, 219, 219); 
  }

  for (y= 11; y <= 11; y++)
  {
      textcolor(WHITE);
      gotoxy(13, y);
      cprintf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219,219,219,219,219, 219, 219, 219, 219, 219, 219, 219, 219, 219,219, 219,219,219,219, 219,219,219,219, 219,219,219,219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,219, 219, 219, 219,219,219,219, 219,219,219,219, 219,219,219,219, 219, 219, 219, 219, 219, 219, 219, 219, 219); 
  }
for (y= 13; y <= 14; y++)
  {
      textcolor(WHITE);
      gotoxy(23, y);
      cprintf("%c%c%c", 219,219,219); 
  }

  for ( x= 17; x <= 23; x++) 
    {
        gotoxy(x , 14);
        cprintf("%c", 219);
        
    }
  for (y= 13; y <= 14; y++)
  {
      textcolor(WHITE);
      gotoxy(17, y);
      cprintf("%c%c%c", 219,219,219); 
  }

  for (y= 13; y <= 13; y++)
  {
      textcolor(RED);
      gotoxy(31, y);
      cprintf("%c%c%c%c%c%c%c%c", 219,219,219,219, 219, 219, 219, 219); 
  }

  for (y= 13; y <= 13; y++)
  {
      textcolor(RED);
      gotoxy(43, y);
      cprintf("%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219); 
  }

  for ( x= 34; x <= 47; x++) 
    {
        gotoxy(x , 14);
        cprintf("%c", 219);
        
    }
    

  for (y= 13; y <= 14; y++)
  {
      textcolor(WHITE);
      gotoxy(56, y);
      cprintf("%c%c%c", 219,219,219); 
  }

  for ( x= 56; x <= 62; x++) 
    {
        gotoxy(x , 14);
        cprintf("%c", 219);
        
    }
  for (y= 13; y <= 14; y++)
  {
      textcolor(WHITE);
      gotoxy(62, y);
      cprintf("%c%c%c", 219,219,219); 
  }
  	gotoxy(31,19);
  	textcolor(WHITE);cprintf("AEREOLINEA - IES");
	gotoxy(34,21);
  	textcolor(LIGHTGREEN);cprintf("B");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("I");
  	delay(100);
	textcolor(LIGHTGREEN);cprintf("E");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("N");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("V");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("E");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("N");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("I");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("D");
  	delay(100);
  	textcolor(LIGHTGREEN);cprintf("O");
  	delay(100);
	
	
  getch();
}


void dibujarUNI() {
    int x, y;
    clrscr();
    textcolor(BLUE + BLINK);
    gotoxy(22, 20);
    cprintf("UNIVERSIDAD NACIONAL DE INGENIERIA");

    /* letra U */
    /* línea vertical */
    for (y = 5; y <= 15; y++) {
        gotoxy(15, y);
        textcolor(BLUE);
        cprintf("%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219);
        delay(100);
    }

    /* línea horizontal de la letra U */
    for (x = 15; x <= 35; x++) {
        gotoxy(x, 15);
        cprintf("%c", 219);
        gotoxy(x, 16);
        cprintf("%c", 219);
        gotoxy(x, 17);
        cprintf("%c", 219);
        delay(100);
        textcolor(BLUE);
    }

    /* línea vertical de la letra U */
    for (y = 17; y >= 10; y--) {
        gotoxy(36, y);
        cprintf("%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219);
        delay(100);
        textcolor(BLUE);
    }

    /* letra N */
    /* línea vertical */
    for (y = 5; y <= 13; y++) {
        gotoxy(26, y);
        cprintf("%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219);
        delay(100);
        textcolor(BLUE);
    }

    /* línea horizontal de la letra N */
    /* línea horizontal */
    for (x = 26; x <= 47; x++) {
        gotoxy(x, 5);
        cprintf("%c", 219);
        gotoxy(x, 6);
        cprintf("%c", 219);
        gotoxy(x, 7);
        cprintf("%c", 219);
        delay(100);
        textcolor(BLUE);
    }

    /* línea vertical de la N */
    for (y = 5; y <= 17; y++) {
        gotoxy(47, y);
        cprintf("%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219);
        delay(100);
        textcolor(BLUE);
    }

    /* letra I */
    /* línea horizontal de la I */
    for (x = 47; x <= 57; x++) {
        gotoxy(x, 17);
        cprintf("%c", 219);
        gotoxy(x, 16);
        cprintf("%c", 219);
        gotoxy(x, 15);
        cprintf("%c", 219);
        delay(100);
        textcolor(BLUE);
    }

    /* línea vertical de la I */
    for (y = 17; y >= 9; y--) {
        gotoxy(57, y);
        cprintf("%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219);
        delay(100);
        textcolor(BLUE);
    }

    /* cuadrito de la I */
    for (x = 57; x <= 63; x++) {
        gotoxy(x, 5);
        cprintf("%c", 219);
        gotoxy(x, 6);
        cprintf("%c", 219);
        gotoxy(x, 7);
        cprintf("%c", 219);
        delay(100);
        textcolor(BLUE);
    }
}


void logo1()
{
  int i;
  clrscr();
  for (i= 0;i<= 10; i++)
  {
	 gotoxy(20, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
   for (i=0;i<=10;i++)
   {
	  gotoxy(21, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i= 0;i<= 16;i++)
  {
	 gotoxy(20+i, 16);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i= 0;i<= 10; i++)
  {
	 gotoxy(22, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i= 0;i<= 10; i++)
  {
	  gotoxy(23, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i= 0;i<= 10; i++)
  {
	 gotoxy(24, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i= 0;i<=16; i++)
  {
	 gotoxy(20+i, 17);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i= 0;i<=7; i++)
  {
	 gotoxy(27, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i= 0;i<=7; i++)
  {
	 gotoxy(28, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=7; i++)
  {
	 gotoxy(29, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=7; i++)
  {
	 gotoxy(30, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=7; i++)
  {
	 gotoxy(31, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i= 0;i<= 6; i++)
  {
	 gotoxy(34, 11+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=6; i++)
  {
	 gotoxy(35, 11+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=6; i++)
  {
	 gotoxy(36, 11+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=6; i++)
  {
	 gotoxy(37, 11+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=10; i++)
  {
	 gotoxy(30+i, 7);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=10; i++)
  {
	 gotoxy(30+i, 8);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=10; i++)
  {
	 gotoxy(30+i, 9);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=11; i++)
  {
	 gotoxy(40, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=11; i++)
  {
	 gotoxy(41, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=17; i++)
  {
	 gotoxy(20+i, 18);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=11; i++)
  {
	 gotoxy(42, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=11; i++)
  {
	 gotoxy(43, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=11; i++)
  {
	 gotoxy(44, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=2; i++)
  {
	 gotoxy(47, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=2; i++)
  {
	 gotoxy(48, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=2; i++)
  {
	 gotoxy(49, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=2; i++)
  {
	 gotoxy(50, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=2; i++)
  {
	 gotoxy(51, 7+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=7; i++)
  {
	 gotoxy(47, 11+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=7; i++)
  {
	 gotoxy(48, 11+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=7; i++)
  {
	 gotoxy(49, 11+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=7; i++)
  {
	 gotoxy(50, 11+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=7; i++)
  {
	 gotoxy(51, 11+i);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=5; i++)
  {
	 gotoxy(42+i, 16);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=5; i++)
  {
	 gotoxy(42+i, 17);textcolor(BLUE);cprintf("%c", 219);
   }
  for (i=0;i<=5; i++)
  {
	 gotoxy(42+i, 18);textcolor(BLUE);cprintf("%c", 219);
   }
  gotoxy(20,4);
  textcolor(YELLOW);cprintf("UNIVERSIDAD NACIONAL DE INGENIERIA");
  gotoxy(20,5);
  textcolor(WHITE);cprintf("INSTITUTO DE ESTUDIOS SUPERIORES");
  gotoxy(25,21);
  textcolor(WHITE);cprintf("CAJERO AUTOMATICO IES");

  for (i=0;i<=34; i++)
  {
	 gotoxy(18+i, 6);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=35; i++)
  {
	 gotoxy(18+i,19);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=8; i++)
  {
	 gotoxy(25, 7+i);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=8; i++)
  {
	 gotoxy(26, 7+i);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=11; i++)
  {
	 gotoxy(18, 7+i);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=11; i++)
  {
	 gotoxy(19, 7+i);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=5; i++)
  {
	 gotoxy(32, 10+i);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=5; i++)
  {
	 gotoxy(33, 10+i);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=9; i++)
  {
	 gotoxy(38, 10+i);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=9; i++)
  {
	 gotoxy(39, 10+i);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=8; i++)
  {
	 gotoxy(45, 7+i);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=8; i++)
  {
	 gotoxy(46, 7+i);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=11; i++)
  {
	 gotoxy(52, 7+i);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=13; i++)
  {
	 gotoxy(53, 6+i);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=7; i++)
  {
	 gotoxy(25+i, 15);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=5; i++)
  {
	 gotoxy(33+i, 10);textcolor(WHITE);cprintf("%c", 219);
   }
  for (i=0;i<=5; i++)
  {
	 gotoxy(47+i, 10);textcolor(WHITE);cprintf("%c", 219);
   }
	 delay(3500);
   getch();
}



void barra()
{
 int pasos = 20;
 int bar = 50;
 int e;
 int j;

 clrscr();
 printf("CARGANDO...\n");

 e = 1;
 while(e<= pasos)
{
 int fract = e * bar;
 int progreso = fract / pasos;

 printf("[");
 j = 0;
 while (j < bar)
{
 if(j < progreso)
 {
  textcolor(10);
  cprintf("%c", 254);
 }
 else
{
 textcolor(7);
 cprintf(" ");
 }
 j++;
}
printf("] %d%%\r", (fract * 5) / bar);
textcolor(7);

delay(350);
e++;

}
 printf("\nCarga Completa.\n");
 getch();
}





