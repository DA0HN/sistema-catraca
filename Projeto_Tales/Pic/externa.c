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

#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, ERRORS, STREAM=PORT1)

unsigned char tmp;
char lt = '-';
int passoSenha = 0, passoCadastro = 0, passo = 0, passoSerial = 0;
unsigned char senhaDigitada[] = {'-','-','-','-'};
unsigned char cadastro[] = {'-','-','-','-','-','-'};
int modoAdm = 42, usuarioSenha = 43, menuAdm = 5, modo = 0, i =0, f = 0;
char serialDados[10];
char seralCompare[] = {'b','a','n','c','o'};
void clearD(){
   passoSenha = 0;
   senhaDigitada[0] = senhaDigitada[1] = senhaDigitada[2] = senhaDigitada[3] = '-';
}

int liberaUser(){
   delay_ms(100);
   int selecionado = verificaS(senhaDigitada);
   
   if(selecionado!=42){
      putc(valorM(selecionado,0));
      putc('*');
      if(valorM(selecionado,1) == '0'){
        printf(lcd_escreve,"\f Bem Vindo!\n");
        mudarValorM(selecionado,1,'1');
        putc('1');
      }else{
        printf(lcd_escreve,"\f Ate breve!\n");
        mudarValorM(selecionado,1,'0');
        putc('0');
      }
      return valorM(selecionado,0);
   }else{
      printf(lcd_escreve," \f Desconhecido!\n");
      printf(lcd_escreve," \r Bloqueado!\n");
      modoAdm = 42;
      modo = 0;
      return 42;
   }   
   clearD();
}

void lcdMSG(int msg){
   switch (msg){
      case 1:
         printf(lcd_escreve," \f Digite a Senha:!\n");
         printf(lcd_escreve," \r Senha:     ");
         printf(lcd_escreve,senhaDigitada);
         break;
      case 2:
         printf(lcd_escreve," \f Academia IFMT\n");
         printf(lcd_escreve," \r Digite a senha! ");
         break;
      case 3:
         printf(lcd_escreve," \f     Modo ADM");
         printf(lcd_escreve," \r Digite a senha! ");
         break;
      case 4:
         printf(lcd_escreve," \f Acesso ADM\n");
         printf(lcd_escreve," \r # Mostra Menu");
         break;
      case 5:
         printf(lcd_escreve," \f A: Cadastro\n");
         printf(lcd_escreve," \r B: Excluir ");
         menuAdm = 6;
         break;
      case 6:
         printf(lcd_escreve," \f C: Verifica\n");
         printf(lcd_escreve," \r D: EnviaPC ");
         menuAdm = 7;
         break;
       case 7:
         printf(lcd_escreve," \f *: Sair");
         menuAdm = 5;
         break;
       case 8:
         printf(lcd_escreve," \f Cadastro\n");
         printf(lcd_escreve," \r D: EnviaPC ");
         break;
      case 9:
         printf(lcd_escreve," \f Digite Cadastro!\n");
         printf(lcd_escreve," \r Dados: ");
         printf(lcd_escreve,cadastro);
         break;
      case 10:
         printf(lcd_escreve," \f Cadastro:");
         printf(lcd_escreve,cadastro);
         printf(lcd_escreve," \r A: Sim #: Nao ");
         break;
      case 11:
         printf(lcd_escreve," \f Excluir Cadastro!\n");
         printf(lcd_escreve," \r Codigo: ");
         printf(lcd_escreve,lt);
         break;
      case 12:
         printf(lcd_escreve," \f Cadastro:");
         for(int a = 0;a<6;a++){
            cadastro[a] = valorM(verificaC(lt),a);
         } 
         printf(lcd_escreve,cadastro);
         printf(lcd_escreve," \r A: Sim #: Nao ");
         break;
      case 13:
         printf(lcd_escreve," \f Verifica Cadastro!\n");
         printf(lcd_escreve," \r Codigo: ");
         printf(lcd_escreve,lt);
         break; 
      case 14:
         printf(lcd_escreve," \f Verifica Senha!\n");
         printf(lcd_escreve," \r Senha:     ");
         printf(lcd_escreve,senhaDigitada);
         break;
      case 15:
         printf(lcd_escreve," \f A: Senha\n");
         printf(lcd_escreve," \r B: Codigo ");
         break; 
      case 16:
         printf(lcd_escreve," \f Esse codigo \n");
         printf(lcd_escreve," \r ja esta em uso! ");
         break;         
         
      default:
      
         break; 
   }
}
void enviaBanco(){
   disable_interrupts(INT_RTCC);
   clear_interrupt(INT_RTCC);
   disable_interrupts(INT_RB);
   clear_interrupt(INT_RB);
   putc('B');
   printf(lcd_escreve," \f Enviando \n");
   printf(lcd_escreve," \r Banco ");
   for(int i = 0;i<16;i++){
      for(int f = 0;f<6;f++){
         char enviando = valorM(i,f);
         if(enviando !='-'){
            putc(enviando);
         }
         putc('*');
      }
   }
   putc('T');
   printf(lcd_escreve," \f Envio \n");
   printf(lcd_escreve," \r Concluido ");
   lcdMSG(2);
   clear_interrupt(INT_RTCC);
   enable_interrupts(INT_RTCC);
   clear_interrupt(INT_RB);
   enable_interrupts(INT_RB);
}
#INT_RTCC
void  RTCC_isr(void) 
{     
   disable_interrupts(INT_RTCC);
   clear_interrupt(INT_RTCC);
  
   
      while(kbhit()){                              
         lt = getc();                                                           
         if(lt == 'B'){
            enviaBanco();
            lt = ' ';
         }else if(lt == 'R'){
            printf(lcd_escreve," \f Recebendo \n");
            disable_interrupts(INT_RB);
            clear_interrupt(INT_RB);
            passo = 0;
         }else if(lt == 'T'){
            printf(lcd_escreve," \f Memoria \n");
            printf(lcd_escreve," \r Atualizada \n");
            saveM();
            loadM();
            passo = 1;
            
            delay_ms(200);
            clear_interrupt(INT_RB);
            enable_interrupts(INT_RB); 
         }
         if(passo == 0){
            mudarValorM(i,f,lt);
            f++;
            if(f == 6){
               i++;
               f = 0;
            }
         }
   }

  
  clear_interrupt(INT_RTCC);
  enable_interrupts(INT_RTCC);
}

#INT_RB
void RB_isr(void) 
{
   disable_interrupts(INT_RB);
   clear_interrupt(INT_RB);
   
   tmp = tc_tecla();
 
   if(tmp!= 255){   
      if(tmp == '*' && modoAdm == 42){
         modoAdm = 1;
         lcdMSG(3);
      }else if(tmp == '#' && modoAdm == 2){
         lcdMSG(menuAdm);
      }else if(tmp == '*' && modoAdm == 2){
         modoAdm = 42;
         modo = 0;
         
      }else if(tmp == 'A' && modoAdm == 2){ //Menus A
         modo = 1;
         modoAdm = 3;
         lcdMSG(9);
      }else if(tmp == 'B' && modoAdm == 2){ //Menu B
         modo = 2;
         modoAdm = 4;
         lcdMSG(11);
       
      }else if(tmp == 'C' && modoAdm == 2){ //Menu C
         modoAdm = 5;
         lcdMSG(15);
         
      }else if(tmp == 'D' && modoAdm == 2){ //Menu D
         enviaBanco();
         
      }else if(tmp == 'A' && modoAdm == 3){ //Opção do Menu A -> A
         if(verificaC(cadastro[0])==42){
            novoCM(cadastro);
         }else{
            lcdMSG(16);
            delay_ms(200);
         }
         modoAdm = 2;
         lcdMSG(4);
         for(int a = 0;a<6;a++){
            cadastro[a] = '-';
         }
      }else if(tmp == '#' && modoAdm == 3){ //Opção do Menu A -> #
         for(int a = 0;a<6;a++){
            cadastro[a] = '-';
         }           
         modoAdm = 2;
         lcdMSG(4); 
      }else if(tmp == 'A' && modoAdm == 4){ //Opção do Menu B -> A
         apagaM(verificaC(lt));
         modoAdm = 2;
         lcdMSG(4); 
      }else if(tmp == '#' && modoAdm == 4){ //Opção do Menu B -> #
         for(int a = 0;a<6;a++){
            cadastro[a] = '-';
         }
         modoAdm = 2;
         lcdMSG(4); 
      }else if(tmp == 'A' && modoAdm == 5){ //Opção do Menu C -> A 
         modo = 4;
         lcdMSG(14);
      }else if(tmp == 'B' && modoAdm == 5){ //Opção do Menu C -> B
         lcdMSG(13);
         modo = 3;
      }else if(tmp == '#' && modoAdm == 5){ //Opção do Menu C -> Voltar
         modoAdm = 2;
         senhaDigitada[0] = senhaDigitada[1] = senhaDigitada[2] = senhaDigitada[3] = '-';
         modo = 0;
         passo = 0;
         lcdMSG(4); 
      }else if(tmp != '*' && tmp != '#' && tmp != 'A' && tmp != 'B' && tmp != 'C' && tmp != 'D' && modo == 0){ //Modo normal espera senha
         senhaDigitada[passoSenha] = tmp;
         passoSenha++;
      }else if(tmp != '*' && tmp != '#' && tmp != 'A' && tmp != 'B' && tmp != 'C' && tmp != 'D' && modo == 1){ //Modo menu A, espera novo cadastro
         cadastro[passoCadastro] = tmp;
         passoCadastro++;
      }else if(tmp != '*' && tmp != '#' && tmp != 'A' && tmp != 'B' && tmp != 'C' && tmp != 'D' && modo == 2){ //Modo menu B, espera código
         lt = tmp;
         consultaM(cadastradoU(lt));
      }else if(tmp != '*' && tmp != '#' && tmp != 'A' && tmp != 'B' && tmp != 'C' && tmp != 'D' && modo == 3){ //Modo menu C, espera código
         lt = tmp;
         consultaM(verificaC(lt));
      }else if(tmp != '*' && tmp != '#' && tmp != 'A' && tmp != 'B' && tmp != 'C' && tmp != 'D' && modo == 4){ //Modo menu C, espera senha
         senhaDigitada[passo] = tmp;
         passo++;
         lcdMSG(14);
      }
      delay_ms(50);
   }

   if(passoSenha == 4){
      usuarioSenha = liberaUser();
      clearD();
      delay_ms(250);
      if(modoAdm == 1 && usuarioSenha == '0'){
         modoAdm = 2;
         lcdMSG(4);         
      }else{
         lcdMSG(2);
      } 
   }else if(passoSenha>0 && modo == 0){
      lcdMSG(1);
   }else if(modoAdm == 42 && passoSenha<1){
      lcdMSG(2);
   }
    if(passoCadastro == 6){
      passoCadastro = 0;
      lcdMSG(10);
   }else if(passoCadastro > 0){
      lcdMSG(9);
   }
   if(passo == 4){
      consultaM(verificaS(senhaDigitada));
      
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
   
   zeraTudo(); //2D = '-'
   loadM();
   
   //Cadastra novo usuário partir do seguinte vetor: Numero cadastro, Status, senha[4];
   unsigned char nova[] = {'0','0','8','9','8','9'};
   novoCM(nova);
   
   output_low(PIN_B0);output_low(PIN_B1);output_low(PIN_B2);output_low(PIN_B3);
   set_tris_b(0xF0);
   port_B_pullups(true);
   
   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);
   enable_interrupts(INT_RB);
   
}
