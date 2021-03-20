#include <stdio.h>
#include <stdlib.h>

#define LINHA 16
#define COLUNA 6
unsigned char memoriaNull = 0xFF;

unsigned char dados[LINHA][COLUNA];
unsigned int id;

void salvaMemoria(){ // salva todos os dados alterados na memoria
 int contador = 0;
 for(int i = 0; i < LINHA; i++){
   for(int j = 0; j < COLUNA; j++){
      write_ext_eeprom(contador, dados[i][j]);
      contador++;
   }
 }
}

int consultaId(){
    int id = dados[0][0] - '0';
    dados[0][0] = (id + 1) + '0';
    return id;
}


void apagaMemoria(){ //apaga todos os dados da memoria
  for(int i = 0; i < LINHA; i++){
   for(int j = 0; j < COLUNA; j++){
      dados[i][j] = memoriaNull;
   }
 }
 salvaMemoria();
}

void carregaMemoria(){ //carrega dados da memoria para a matriz "dados"
 int contador = 0;
 for(int i = 0; i < LINHA; i++){
   for(int j = 0; j < COLUNA; j++){
     dados[i][j] = read_ext_eeprom(contador);
      contador++;
   }
 }
}

int verificaPosicaoNula(){ //verifica se existe posições nulas para cadastro
   for(int i = 1; i < LINHA; i++){
      if(dados[i][0] == memoriaNull){
         return i;
      }
   }
   return (-1);
}

void novoUsuario(unsigned char cadastro[4]){ //cadastras um novo usuario na memoria
    int posicaoLinha = verificaPosicaoNula();
    dados[posicaoLinha][0] = consultaId() + '0'; //id do usuario
    dados[posicaoLinha][1] = '0';    //status
        if(posicaoLinha == (-1)){
            printf(lcd_escreve, "\fErro!\n\r"); 
            printf(lcd_escreve, "Memoria Cheia!!"); 
            delay_ms(2000);          
        }else{
             for(int i =2;i<6;i++){
                dados[posicaoLinha][i] = cadastro[i-2];
            }
            salvaMemoria();
        }
}

void excluiUsuario(unsigned char cadastro[4]){ //exclui um usuario da memoria
    for(int i = 1; i < LINHA; i++){
        if(dados[i][2] == cadastro[0] && dados[i][3] == cadastro[1] &&  dados[i][4] == cadastro[2] &&  dados[i][5] == cadastro[3]){
            for(int j = 0; j < COLUNA; j++){
                dados[i][j] = memoriaNull;
            }
        }
    }
    salvaMemoria();
}



int verificaUsuario(unsigned char cadastro[4]){
   if(cadastro[0] == dados[0][1] && cadastro[1] == dados[0][2] && cadastro[2] == dados[0][3] && cadastro[3] == dados[0][4]){
         printf(lcd_escreve, "\fBem Vindo Admin!"); 
         delay_ms(2000);
         return 1;
   }else{
      for(int i = 1; i < LINHA; i++){
         if(dados[i][2] == cadastro[0] && dados[i][3] == cadastro[1] &&  dados[i][4] == cadastro[2] &&  dados[i][5] == cadastro[3]){
            return 0;
         }else if (i == (LINHA -1)){
            return (-1);
         }
      }     
   }
}

void configuracaoMemoria(){// configurações inicias da memoria
      if(dados[0][0] == memoriaNull){
         dados[0][0] = '1';
         dados[0][1] = '0';dados[0][2] = '0';dados[0][3] = '0';dados[0][4] = '0';//senha do admin
         salvaMemoria();
      }   
}
