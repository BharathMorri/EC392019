#include <avr/io.h> 
 
#include <util/delay.h> 
 
#include <stdbool.h> 
 
 
 
 
int main (void) 
 
{ 
 bool A,B; 
 
 bool D ; 
 
//identifyinng pins 8,9 as inputs and pin13 as output  
 DDRB = 0b11111100; //AB 
 
//identifyinng pins 2,3 as ouputs   
 DDRD = 0b00000110; 
 
 //PORTD = 0b11000000; 
 
 //PORTB = 0b00000011; 
 
 while(1){ 
 
    
  //Gnerate clock 
  PORTB = ((1 <<  PB5)); 
 
  _delay_ms (1000L); 
 
  //Read inputs 
  A = (PINB & (1 << PINB0)) == (1 << PINB0); 
 
  B = (PINB & (1 << PINB1)) == (1 << PINB1); 
   
  //Implement combinational logicto havedesired state trnsitios 
  D=!(A&&B); 
 
//Write to the output 
  PORTD = (D << 2); 
  PORTD |= (2<< 3); 
 
   
 
  //Generate clock 
  PORTB = ((0 <<  PB5)); 
  
  _delay_ms (1000L); 
  D=0; 
  PORTD = (D << 2); 
  PORTD |= (2<< 3); 
 
 } 
  
return 0; 
 
}
