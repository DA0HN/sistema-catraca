#include <2404.c>

unsigned char dados[16][6];

void init_m(){
   init_ext_eeprom();
   delay_ms(10);
}

void loadM(){ //ok
 int count = 0;
 for(int i = 0;i<16;i++){
   for(int f = 0;f<6;f++){
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

void consultaM(int x){ //ok // X é o referencial da matriz
   printf(lcd_escreve,"\f Cadastro: %c \n",dados[x][0]);
   printf(lcd_escreve,"\r Senha: ");
   for(int y=2;y<6;y++){
      printf(lcd_escreve,"%c",dados[x][y]);
   }   
}

int cadastradoU(unsigned char user[1]){
   int encontrou = 0;
    for(int i = 0;i<16;i++){
       encontrou = 0;
      for(int f = 0;f<1;f++){
         if (user[f] == dados[i][f]){
            encontrou++;
            if(encontrou == 1)
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

int verificaVazio(){
   for(int i = 0;i<16;i++){
      if(dados[i][0] == '-')
         return i; 
   }
   return 42; 
}

void novoCM(unsigned char nova[6]){ //ok // pos é o referencial do usuário e nova é o cadastro novo
   int pos = verificaVazio();
   if(pos != 42){
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

//
void zeraTudo(){
 for(int i = 0;i<16;i++){
   for(int f = 0;f<6;f++){
      dados[i][f] = '-';
   }
 }
 saveM();
}

unsigned char valorM(int x,int y){
   unsigned char valor = dados[x][y];
   return valor;
}

