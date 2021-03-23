#include <stdio.h>
#include <stdlib.h>

#define LINHA 16
#define COLUNA 6
unsigned char memoriaNull = 0xFF; //FF 

unsigned char dados[LINHA][COLUNA]; //matriz que receber os dados da memoria

void salvaMemoria() //salva todos os dados alterados na memoria
{  
   int contador = 0;
   for (int i = 0; i < LINHA; i++)
   {
      for (int j = 0; j < COLUNA; j++)
      {
         write_ext_eeprom(contador, dados[i][j]);
         contador++;
      }
   }
}

int verificaPosicaoNula() //verifica se existe posicoes nulas para cadastro
{ 
   for (int i = 1; i < LINHA; i++)
   {
      if (dados[i][0] == memoriaNull)
      {
         return i;
      }
   }
   return (-1);
}

int verificaSenha(unsigned char cadastro[4], int linhaDado) //verifica se a senha existe na matriz
{
   return (dados[linhaDado][2] == cadastro[0] 
      && dados[linhaDado][3] == cadastro[1] 
      && dados[linhaDado][4] == cadastro[2] 
      && dados[linhaDado][5] == cadastro[3]
   );
}

int recuperaId() //guarda o ultimo ID para cadastrar o proximo
{  
   int linhaNula = verificaPosicaoNula();
   if(linhaNula == 1){
      return 1;
   }
   return (1 +dados[linhaNula -1][0]) - '0';
  
}

void apagaColunaMemoria(int linhaDado) //apaga um usuario definido por linha
{
   for (int j = 0; j < COLUNA; j++)
   {
      dados[linhaDado][j] = memoriaNull;
   }
}

void apagaMemoria() //apaga todos os dados da memoria
{ 
   for (int i = 0; i < LINHA; i++)
   {
      apagaColunaMemoria(i);
   }
   salvaMemoria();
}

void carregaMemoria() //carrega dados da memoria para a matriz 
{ 
   int contador = 0;
   for (int i = 0; i < LINHA; i++)
   {
      for (int j = 0; j < COLUNA; j++)
      {
         dados[i][j] = read_ext_eeprom(contador);
         contador++;
      }
   }
}

void enviaDados(){ //envia os dados da matriz via serial
   fprintf(PORT1, "I\n\r");
   for(int i = 1; i < LINHA; i++){
      output_toggle(PIN_D1);
      for(int j = 0; j < COLUNA; j++){
         output_toggle(PIN_D2);
         if(dados[i][j] != memoriaNull){
            if(j == 5){
               fprintf(PORT1, "%d\n\r", dados[i][j] - '0');  
            }else{       
               fprintf(PORT1, "%d,", dados[i][j] - '0');             
            }
         }
      }
    //fprintf(PORT1, "\n\r"); 
      delay_ms(500);
    }
    fprintf(PORT1, "F\n\r"); 
    output_low(PIN_D1);
    output_low(PIN_D2);
}



int verificaUsuario(unsigned char cadastro[4]) // verifica se o usuario e um admin, cliente ou nao existe
{
   if (verificaSenha(cadastro, 0))
   {
      printf(lcd_escreve, "\fBem Vindo Admin!");
      delay_ms(2000);
      return 1;
   }
   for (int i = 1; i < LINHA; i++)
   {
      if (verificaSenha(cadastro, i))
      {
         return 0;
      }
   }
   return (-1);
}

void novoUsuario(unsigned char cadastro[4]) // cria um novo usuario e atualiza a memoria
{ //cadastras um novo usuario na memoria
   int posicaoLinha = verificaPosicaoNula();
   dados[posicaoLinha][0] = recuperaId() + '0'; //id do usuario
   dados[posicaoLinha][1] = '0';                //status

   if (posicaoLinha == (-1))
   {
      printf(lcd_escreve, "\fErro!\n\r");
      printf(lcd_escreve, "Memoria Cheia!!");
      delay_ms(2000);
      return;
   }

   if(verificaUsuario(cadastro) == 0){
      printf(lcd_escreve, "\f   Erro!\n\r");
      printf(lcd_escreve, "Usuario Existente");
      delay_ms(2000);
      return;
   }
   for (int i = 2; i < COLUNA; i++)
   {
      dados[posicaoLinha][i] = cadastro[i - 2];
   }
   salvaMemoria();
}

void excluiUsuario(unsigned char cadastro[4]) // exclui um usuario e atualiza a memoria
{ //exclui um usuario da memoria
   for (int i = 1; i < LINHA; i++)
   {
      if (verificaSenha(cadastro, i))
      {
         apagaColunaMemoria(i);
      }
   }
   salvaMemoria();
}


void configuracaoMemoria() // faz as configuracoes iniciais da memoria
{
   if (dados[0][2] == memoriaNull)
   {
      dados[0][0] = '-';
      dados[0][1] = '-';
      dados[0][2] = '0';
      dados[0][3] = '0';
      dados[0][4] = '0';
      dados[0][5] = '0';
      salvaMemoria();
   }
}

void alteraStatus(unsigned char cadastro[4]) // altera os status do cliente quando entra/sai na catraca
{
   for (int i = 1; i < LINHA; i++)
   {
      if (verificaSenha(cadastro, i))
      {
         if (dados[i][1] == '0')
         {
            dados[i][1] = 1 + '0';
         }
         else if (dados[i][1] == '1')
         {
            dados[i][1] = 0 + '0';
         }
         salvaMemoria();
         return;
      }
   }
}

int status(unsigned char cadastro[4]) //verifica o status atual do cliente
{
   for (int i = 1; i < LINHA; i++)
   {
      if (verificaSenha(cadastro, i))
      {
         return dados[i][1] - '0';
      }
   }
   return -1;
}



void recebeDados(char ch, int line, int col){ //recebe os dados via serial e armazena na memoria
   dados[line][col] = ch;
   salvaMemoria();
}


