// prueba de examen mipyd


#include <stdio.h>
#include <stdlib.h>

s32 EventosUSB = 0;
u32 SystemTicks = 0;


void USBRead ( void ) {
	;	
}

void Timer ( void ) {   //timer cada 10ms.
	
	SystemTicks++;
}

void IniHardware ( void ) {
	;
}

void IniTimer ( void ) {
	;
}

void LedON ( int led ) {
	;	
}

void LedOFF ( int led ) {
	;	
}


int Lecturas ( void ) {
	
	static u32 st = 0;
	static u32 nled=0;
	
	switch ( EventoUSB ) {
		case 0:  //none	
		
		break;
		
		case 1:	//Ini
			nled = 0;
			st = 1;
		break;
		
		case 2:  //stop
			st = 3;
		break;		
	}
	
	switch ( st ) {
		
		case 0:	//none
			
		break;
		
		case 1:  //Ini
			if ( nled < 6 ) {
				LedON( nled );
				ticks = SystemTicks + 8;
				st = 2; 
			}
			else {
				nled = 0;
				st = 0;
			}
		break;
		
		case 2:	//wait
			if ( SystemTicks >= ticks ) {
				MeasureADC();
				LedOFF(nled);
				nled++;
				st = 1;
			}
		break;
		
		case 3:  // stop
			LedOFF(nled);
			nled = 0;
			st = 0;
		break;
	}	
}


void main ( void ) {
	
	IniHardware ();
	IniTimer ( );
	
	while ( 1 ) {

		USBRead();
		
		Lecturas ( );
			
	}
	
}