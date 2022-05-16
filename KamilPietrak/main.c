#include <avr/io.h>
#include <util/delay.h>

void z1();
void z2();
void z3();
void z4();
void z5();


int main(void)
{
    
	DDRA = 0xFF;
	PORTA = 0x00;
	
    while (1) 
    {
		// z1();
		// z2();
		// z3();
		// z4();
		z5();
		
    }
}

void z1() {
	// Zapalanie i gaszenie od 7 do 0 co pol sekundy
	for(uint8_t i = 7; i>0; i--){
		PORTA |= (1<<i)|(1<<(i-1)); // Zapalanie diod 
		_delay_ms(500); // Odczekiwanie 0.5s na kolejna instrukcja
		PORTA &= ~((1<<i)|(1<<(i-1))); // Gaszenie diod
	}
	
	// Zapalanie i gaszenie od 0 do 7 co sekunde
	
	for(uint8_t i = 0; i<7; i++){
		PORTA |= (1<<i)|(1<<(i+1)); // Zapalanie diod
		_delay_ms(1000); // Odczekiwanie 0.5s na kolejna instrukcja
		PORTA &= ~((1<<i)|(1<<(i+1))); // Gaszenie diod
	}

}

void z2() {
	
	// Zapalnie odpowiednio diod
	for(uint8_t i = 7; i >3; i--){
		PORTA |= (1<<i);
		_delay_ms(1000);
	}
	
	// Gaszenie diod
	for(uint8_t i = 4; i <7; i++){
		PORTA &= ~(1<<i);
		_delay_ms(1000);
	}
	
	
}

void z3() {
	PORTA = 0;
	
	for(uint8_t i = 8; i>0; i--){
		PORTA |= (1<<(i-1));
		_delay_ms(1000);
	} 
}

void z4() {
	
	PORTA = 0;
	for(uint8_t i = 4; i>0; i--){
		PORTA |= (1<<(i-1));
		_delay_ms(1000);
	}
	
	PORTA = 0;
	for(uint8_t i = 4; i<=7; i++) {
		PORTA |= (1<<i);
		_delay_ms(1000);	
	}	
	
}

void z5() {
	
	PORTA = 0;
	for(uint8_t i = 7; i>=4; i--){
		PORTA |= (1<<i);
		_delay_ms(1000);
	}
	
	PORTA = 0;
	for(uint8_t i = 0; i<4; i++){
		PORTA |= (1<<i);
		_delay_ms(1000);
	}
}