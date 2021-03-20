#include <16F877A.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES XT                       //Crystal osc <= 4mhz for PCM/PCH , 3mhz to 10 mhz for PCD
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected

#use delay(crystal=20000000)

#ifndef lcd_enable                                                             
   #define lcd_enable     pin_e1      // pino enable do LCD
   #define lcd_rs         pin_e2      // pino rs do LCD
   #define lcd_d4         pin_d4      // pino de dados d4 do LCD
   #define lcd_d5         pin_d5      // pino de dados d5 do LCD
   #define lcd_d6         pin_d6      // pino de dados d6 do LCD
   #define lcd_d7         pin_d7      // pino de dados d7 do LCD
#endif

#include "lib/mod_lcd.c"
#include "lib/kbd_ext_board2.c"
#include "lib/funcMemoria.c"

//#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, Serial)
unsigned char tmp;
int countSs = 0;
unsigned char senhaDigitada[] = {'-','-','-','-'};
void clearD(){
   countSs = 0;
   senhaDigitada[0] = senhaDigitada[1] = senhaDigitada[2] = senhaDigitada[3] = '-';
}
int msgTela[] = {0,1,0};
void mostraTela(int mostra){
   if(mostra == 1){
      if(msgTela[0] == 1){
         printf(lcd_escreve, "\f ControleEntrada\n"); 
         printf(lcd_escreve, "\r  Senha: %s", senhaDigitada);
         msgTela[0] = 0;
         msgTela[1] = 1;
         
      }
   }else if(mostra == 2){
      if(msgTela[1] == 1){
         printf(lcd_escreve, "\f    Academia\n"); 
         printf(lcd_escreve, "\r Dig sua Senha");
         msgTela[1] = 0;
         msgTela[0] = 1;
      }
   }else if(mostra == 3){
      if(msgTela[2] == 1){
         printf(lcd_escreve, "\f    Adm\n"); 
         printf(lcd_escreve, "\r Dig sua Senha");
         msgTela[2] = 0;
         msgTela[0] = 1;
         msgTela[1] = 1;
      }
   }
}
void liberaUser(){
   delay_ms(100);
   int selecionado = verificaS(senhaDigitada);
   if(selecionado!=42){
      printf(lcd_escreve,"\f Liberado!\n");
      printf(lcd_escreve,"\r Usuario: %c",valorM(selecionado,0));
   }else{
      printf(lcd_escreve," \f Desconhecido!\n");
      printf(lcd_escreve," \r Bloqueado!\n");
   }   
   msgTela[3] = 0;
   delay_ms(500);
   clearD();
}
#INT_RB
void RB_isr(void) 
{
   disable_interrupts(INT_RB);
   clear_interrupt(INT_RB);
   
    tmp = tc_tecla();
 
   if(tmp!= 255){   
      if(tmp == '*'){
         msgTela[2] = 1;
         mostraTela(3);
      }else{
         senhaDigitada[countSs] = tmp;
         countSs++;
         delay_ms(50);
      }
   }
   if(countSs>0){
      msgTela[0] = 1;
      mostraTela(1);
      delay_ms(10);
   }else{ 
      mostraTela(2);
   }
   
   if(countSs == 4){
      liberaUser();
   }

  
   output_low(PIN_B0);
   output_low(PIN_B1);
   output_low(PIN_B2);
   output_low(PIN_B3);
   clear_interrupt(INT_RB);
   enable_interrupts(INT_RB);
}

void main()
{   
   lcd_ini();
   delay_ms(50);
   init_m();

     
   //Carrega os arquivos da memoria interna para uma matriz
//!   loadM();
   //Salva a matriz na memoria interna
//!   saveM();
   //Limpa toda a memoria interna
   zeraTudo(); //2D = '-'
   loadM();
   //Cadastra novo usuário partir do seguinte vetor: Numero cadastro, Status, senha[4];
   unsigned char nova[] = {'5','1','8','9','8','9'};
   novoCM(nova);
//!   
//!   //Verifica se a senha esta no cadastro, retorna a linha da matriz em que ela se encontra ou o valor 42
//!   unsigned char senha[] = {'8','9','8','9'};
//! 
   //
//!   unsigned char user[] = {'9'};   
//!   consultaM(cadastradoU(user,dados),dados);


   output_low(PIN_B0);output_low(PIN_B1);output_low(PIN_B2);output_low(PIN_B3);
   set_tris_b(0xF0);
   port_B_pullups(true);
   
   enable_interrupts(GLOBAL);
   enable_interrupts(INT_RB);
   
  
   while(true){

   }
}
