#include <2404.c>

void init_m(){
   init_ext_eeprom();
   delay_ms(10);
}

void loadM(unsigned char dados[16][5]){ //ok
 int count = 0;
 for(int i = 0;i<16;i++){
   for(int f = 0;f<6;f++){
      dados[i][f] = READ_EXT_EEPROM(count);
      count++;
   }
 }
}
 
void saveM(unsigned char dados[16][5]){ //ok
 int count = 0;
 for(int i = 0;i<16;i++){
   for(int f = 0;f<6;f++){
      WRITE_EXT_EEPROM(count, dados[i][f]);
      count++;
   }
 }
}

void printM(int x,unsigned char dados[16][5]){ //ok // X é o referencial da matriz
   printf(lcd_escreve,"\f Cadastro: %c%c \n",dados[x][0],dados[x][1]);
   printf(lcd_escreve,"\r Senha: ");
   for(int y=2;y<6;y++){
      printf(lcd_escreve,"%c",dados[x][y]);
   }   
}
int cadastradoU(unsigned char user[2],unsigned char dados[16][5]){
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

void editaSM(int pos, unsigned char nova[4],unsigned char dados[16][5]){ //ok // pos é o referencial do usuário e nova é a nova senha.
   for(int i = 0;i<4;i++){
      dados[pos][i+2] = nova[i];
   }
   saveM(dados);
}
int verificaNovo(unsigned char dados[16][5]){
   for(int i = 0;i<16;i++){
      if(dados[i][0] == '-')
         return i; 
   }
   return 42; 
}

void novoCM(unsigned char nova[6],unsigned char dados[16][5]){ //ok // pos é o referencial do usuário e nova é o cadastro novo
   int pos = verificaNovo(dados);
   if(pos !=42){
      for(int i = 0;i<6;i++){
         dados[pos][i] = nova[i];
      }
      saveM(dados);
   }else{
      printf(lcd_escreve,"\f Erro!\n");
      printf(lcd_escreve,"\r Memoria Cheia!\n");
   }
}

int verificaS(unsigned char senha[4],unsigned char dados[16][5]){ //ok
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

void apagaM(int pos,unsigned char dados[16][5]){
   for(int i=0;i<6;i++){
      dados[pos][i] = '-';
   }
   saveM(dados);
}

void zeraTudo(unsigned char dados[16][5]){
 for(int i = 0;i<16;i++){
   for(int f = 0;f<6;f++){
      dados[i][f] = '-';
   }
 }
 saveM(dados);
}
