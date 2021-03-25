#include "lib/tela_util.c"

#INT_RDA
void RDA_isr(void) 
{
   output_toggle(PIN_D0);
   int dado = getc();
   if(dado != 0x00){
      recebeDados(dado);
   }
}


#INT_RB
void RB_isr(void)
{
   disable_interrupts(INT_RB);
   clear_interrupt(INT_RB);
   
   tmp = tc_tecla();
   if (tipoTela == 0)
   {
      telaPrincipal();
   }
   else if (tipoTela == 1)
   {
      telaCrudAdmin();
   }
   else if (tipoTela == 2)
   {
      telaIncluir();
   }
   else if (tipoTela == 3)
   {
      telaExcluir();
   }
   else if (tipoTela == 4)
   {
      telaVerificar();
   }
   else if (tipoTela == 5)
   {
     enviaDados();
     tipoTela = 0;
     printf(lcd_escreve, "\fDados Enviados");
     delay_ms(500);
   }else if(tipoTela == 6){
      telaPagar();
   }
   clear_interrupt(INT_RB);
   enable_interrupts(INT_RB);
}

void main()
{
   init_ext_eeprom();
   //apagaMemoria(); 
   lcd_ini();
   delay_ms(10);
   printf(lcd_escreve, "\f   Iniciando");
   delay_ms(1000);
   
   set_tris_b(0xF0);
   port_B_pullups(true);
   enable_interrupts(GLOBAL); 
   enable_interrupts(INT_RDA);
   enable_interrupts(INT_RB); 
   output_low(PIN_B0);
   output_low(PIN_B1);
   output_low(PIN_B2);
   output_low(PIN_B3);
   while(TRUE)
   {
       
   }
}
