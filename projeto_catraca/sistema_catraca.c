#include <sistema_catraca.h>
#include <math.h>
#include <stdio.h>
#INCLUDE<2404.C>
#include "lib/lcd_util.c"
#include "lib/teclado_util.c"
#include "lib/memoria_util.c"

unsigned char tmp;
char senha[4];
int posicaoSenha = 0;

#INT_RB
void RB_isr(void) 
{
   disable_interrupts(INT_RB);
   clear_interrupt(INT_RB);
   
    tmp = tc_tecla();
 
   if(tmp!= 255){
      if(posicaoSenha == 4){
         posicaoSenha = 0;
      }
      
      //implementar verifica posições nulas do vetor
      if(tmp == 'D'){    
         verificaUsuario(senha);    
         senha[0] = senha[1] = senha[2] = senha[3] = '\0';
      }else{
         senha[posicaoSenha] = tmp;
         posicaoSenha++;
      }
   }
   
   printf(lcd_escreve, "\f Academia C & G\n"); 
   printf(lcd_escreve, "\r  Senha: %s", senha); 

   clear_interrupt(INT_RB);
   enable_interrupts(INT_RB);

   output_low(PIN_B0);
   output_low(PIN_B1);
   output_low(PIN_B2);
   output_low(PIN_B3);
}

void main()
{
   
   init_ext_eeprom();
   //apagaMemoria();
   carregaMemoria();
   configuracaoMemoria();
   
   
   lcd_ini();
   delay_ms(10);
 
   printf(lcd_escreve, "\f Teclado");
   delay_ms(1000);
   
   set_tris_b(0xF0);
   port_B_pullups(true);
   enable_interrupts(INT_RB);
   enable_interrupts(GLOBAL);
   output_low(PIN_B0);output_low(PIN_B1);output_low(PIN_B2);output_low(PIN_B3);
  

   while(TRUE){  
      
   
   }
}
