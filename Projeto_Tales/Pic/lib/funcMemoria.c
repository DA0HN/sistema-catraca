#include <2404.c>

unsigned char dados[16][6];

void init_m(){
   init_ext_eeprom();
   delay_ms(10);
}

//Mensagem de erro padrão é 42

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
//Fazer if do erro
void consultaM(int x){ //ok // X é o referencial da matriz
   printf(lcd_escreve,"\f Cadastro: %c \n",dados[x][0]);
   printf(lcd_escreve,"\r Senha: ");
   for(int y=2;y<6;y++){
      printf(lcd_escreve,"%c",dados[x][y]);
   }   
}
//Fazer if do erro
char consultaVetor(int x){
   char temp[6];
   for(int a = 0;a<6;a++){
      temp[a] = dados[x][a];
   }
   return temp;
}
int cadastradoU(unsigned char user[1]){
   for(int i = 0;i<16;i++){
      if (user[0] == dados[i][0]){
         return i;  
      }
   }
   return 42;
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
      loadM();
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

int verificaC(char cadastro){ //ok
   for(int i = 0;i<16;i++){
      if (cadastro == dados[i][0]){
         return i;
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

void mudarValorM(int x, int y, char valor){
   dados[x][y] = valor;
   saveM();
}
