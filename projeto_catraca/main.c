#include <main.h>
#include<stdio.h>
#include "mod_lcd.c"
#include "teclado.c"

unsigned char tmp;
char senha[4];
int posicao = 0;


#INT_RB
void RB_isr(void) 
{
   disable_interrupts(INT_RB);
   clear_interrupt(INT_RB);
   
    tmp = tc_tecla();
   
   if(tmp!= 255){
     if(posicao > 3){
      // incluir na memoria antes de resetar
         posicao = 0;
         senha = "\0";
     }
     
     senha[posicao] = tmp;
     posicao++;
   }
   
   //printf(lcd_escreve, "\fValor: %c\n", valor); 
   printf(lcd_escreve, "\fSenha: %s", senha); 
   clear_interrupt(INT_RB);
   enable_interrupts(INT_RB);

   output_low(PIN_B0);
   output_low(PIN_B1);
   output_low(PIN_B2);
   output_low(PIN_B3);
}

void main()
{
   port_B_pullups(0xFF);
   
   lcd_ini();
   delay_ms(10);
 
   printf(lcd_escreve, "\f Teclado");
   delay_ms(1000);
   
   enable_interrupts(INT_RB);
   enable_interrupts(GLOBAL);
   output_low(PIN_B0);output_low(PIN_B1);output_low(PIN_B2);output_low(PIN_B3);
  

   while(TRUE){
     
      delay_ms(1000);
   }
}
