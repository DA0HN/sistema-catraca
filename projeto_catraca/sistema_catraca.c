#include <sistema_catraca.h>
#include <math.h>
#include <stdio.h>
#include "lib/lcd_util.c"
#include "lib/teclado_util.c"
#INCLUDE<2404.C>

unsigned char tmp;
char dado;
char senha[4];
int posicaoMemoria = 0;
byte  dispositivo1 = 0;

#INT_RB
void RB_isr(void) 
{
   disable_interrupts(INT_RB);
   clear_interrupt(INT_RB);
   
    tmp = tc_tecla();
    
   WRITE_EXT_EEPROM(0, 199);
   WRITE_EXT_EEPROM(1, 5);
   if(tmp!= 255){
    dado = tmp;
 
   }
   
  
  // printf(lcd_escreve, "\fValor: %c\n\r", dado); 
   printf(lcd_escreve, "\fPos0: %u\n\r",READ_EXT_EEPROM(0)); 
    printf(lcd_escreve, "Pos1: %d",READ_EXT_EEPROM(1)); 
   clear_interrupt(INT_RB);
   enable_interrupts(INT_RB);

   output_low(PIN_B0);
   output_low(PIN_B1);
   output_low(PIN_B2);
   output_low(PIN_B3);
}

void main()
{
  INIT_EXT_EEPROM();
 
   port_B_pullups(0xFF);
   
   lcd_ini();
   delay_ms(10);
 
   printf(lcd_escreve, "\f Teclado");
   delay_ms(1000);
   
   enable_interrupts(INT_RB);
   enable_interrupts(GLOBAL);
   output_low(PIN_B0);output_low(PIN_B1);output_low(PIN_B2);output_low(PIN_B3);
  

   while(TRUE){   
   }
}
