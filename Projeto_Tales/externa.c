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

#include "kbd_ext_board2.c"
#include <mod_lcd.c>

#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, ERRORS)

#include <2404.c>

unsigned char dados[16][5];

void loadM(){ //ok
 int count = 0;
 for(int i = 0;i<16;i++){
   for(int f = 0;f<6;f++){
      //dados[i][f] = f;
      dados[i][f] = READ_EXT_EEPROM(count);
      count++;
   }
 }
}
 
void saveM(){ //ok
 int count = 0;
 for(int i = 0;i<16;i++){
   for(int f = 0;f<6;f++){
      WRITE_EXT_EEPROM(count, dados[i][f]);
      count++;
   }
 }
}

void printM(int x){ //ok // X é o referencial da matriz
   printf(lcd_escreve,"\f Cadastro: %d \n",x);
   printf(lcd_escreve,"\r Senha: ");
   for(int y=2;y<6;y++){
      printf(lcd_escreve,"%c",dados[x][y]);
   }   
}
int cadastradoU(unsigned char user[2]){
   int encontrou = 0;
    for(int i = 0;i<16;i++){
       encontrou = 0;
      for(int f = 0;f<2;f++){
         if (user[f] == dados[i][f]){
            encontrou++;
            if(encontrou == 2)
               return i;
         }
      }
    }
    return 42;
}

void editaSM(int pos, unsigned char nova[4]){ //ok // pos é o referencial do usuário e nova é a nova senha.
   for(int i = 0;i<4;i++){
      dados[pos][i+2] = nova[i];
   }
   saveM();
}
int verificaNovo(){
   for(int i = 0;i<16;i++){
      if(dados[i][0] == '-')
         return i; 
   }
   return 42; 
}

void novoCM(unsigned char nova[6]){ //ok // pos é o referencial do usuário e nova é o cadastro novo
   int pos = verificaNovo();
   if(pos !=42){
      for(int i = 0;i<6;i++){
         dados[pos][i] = nova[i];
      }
      saveM();
   }else{
      printf(lcd_escreve,"\f Erro!\n");
      printf(lcd_escreve,"\r Memoria Cheia!\n");
   }
}

int verificaS(unsigned char senha[4]){ //ok
int encontrou = 0;
 for(int i = 0;i<16;i++){
    encontrou = 0;
   for(int f = 0;f<4;f++){
      if (senha[f] == dados[i][f+2]){
         encontrou++;
         if(encontrou == 4)
            return i;
      }
   }
 }
 return 42;
}

void apagaM(int pos){
   for(int i=0;i<6;i++){
      dados[pos][i] = '-';
   }
   saveM();
}

void zeraTudo(){
 for(int i = 0;i<16;i++){
   for(int f = 0;f<6;f++){
      dados[i][f] = '-';
   }
 }
 saveM();
}

void main()
{   
   lcd_ini();
   delay_ms(50);
   init_ext_eeprom();
   delay_ms(10);
   
   loadM();
   //saveM();

   //zeraTudo(); //2D = '-'

//!   unsigned char nova[] = {'0','1','2','6','8','9'};
//!   novoCM(nova);


  
//!   unsigned char senha[] = {'2','6','8','0'};
//!   int selecionado = verificaS(senha);
//!   
//!   if(selecionado!=42){
//!      printf(lcd_escreve,"\f Liberado!\n");
//!      printf(lcd_escreve,"\r Usuario: %c%c",dados[selecionado][0],dados[selecionado][1]);
//!   }else{
//!      printf(lcd_escreve," \f Bloqueado!\n");
//!   } 
   
//!   printM(0);
//!   
//!   unsigned char user[] = {'0','1'};
//!   int selecionado = cadastradoU(user);
//!   if(selecionado!=42){
//!      printf(lcd_escreve,"\f Localizado!\n");
//!   }else{
//!        printf(lcd_escreve," \f N localizado!\n");
//!   } 
     
}


