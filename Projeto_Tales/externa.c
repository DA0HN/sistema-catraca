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

#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, ERRORS)

unsigned char dados[16][5];

void main()
{   
   lcd_ini();
   delay_ms(50);
   init_m();
   
   loadM(dados);
//!   saveM(dados);
//!
//!   zeraTudo(dados); //2D = '-'
//!
//!   unsigned char nova[] = {'0','1','2','6','8','9'};
//!   novoCM(nova,dados);
//!
   unsigned char senha[] = {'2','6','8','9'};
   int selecionado = verificaS(senha,dados);
   
   if(selecionado!=42){
      printf(lcd_escreve,"\f Liberado!\n");
      printf(lcd_escreve,"\r Usuario: %c%c",dados[selecionado][0],dados[selecionado][1]);
   }else{
      printf(lcd_escreve," \f Bloqueado!\n");
   } 
//!
//!   unsigned char user[] = {'0','1'};   
//!   printM(cadastradoU(user,dados),dados);
//!   
     
}


