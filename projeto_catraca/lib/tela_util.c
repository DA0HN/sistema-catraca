#include <main.h>
#include <2404.c>
#include "lib/lcd_util.c"
#include "lib/teclado_util.c"
#include "lib/memoria_util.c"

unsigned char tmp;
char senha[4];
int posicaoSenha = 0;
int tipoTela = 0;
int comandoAdmin = 0;

void limpaSenha()
{
   senha[0] = senha[1] = senha[2] = senha[3] = '\0';
}

void telaStatus()
{
   if(verificaStatus(senha) == 0){
      printf(lcd_escreve, "\f Procure o Admin ");
   }
   else if (verificaStatus(senha) == 1)
   {
      printf(lcd_escreve, "\f   Liberado! ");  
      output_high(PIN_C0);
   }
   else
   {
      printf(lcd_escreve, "\f Senha invalida!! ");
   }
   
   delay_ms(2000);
   output_low(PIN_C0);
}

void telaPrincipal()
{
   printf(lcd_escreve, "\f Academia C & G\n");
   printf(lcd_escreve, "\r  Senha: %s", senha);
   if (tmp == 255)
      return;

   if (posicaoSenha == 4)
   {
      posicaoSenha = 0;
   }
   if (tmp == 'D')
   {
      int usuario = verificaTipoUsuario(senha);
      if (usuario == 2)
      {       
         telaStatus();
         tipoTela = 0;
      }
      else if (usuario == 1)
      {
         printf(lcd_escreve, "\fBem Vindo Admin!");
         delay_ms(2000);
         tipoTela = 1;
      }
      else
      {
         printf(lcd_escreve, "\f Senha invalida!! ");
         delay_ms(2000);
         tipoTela = 0;
      }
      limpaSenha();
   }
   else
   {
      senha[posicaoSenha++] = tmp;
   }
}

void telaCrudAdmin()
{
   printf(lcd_escreve, "\f1-Inc 2-Exc 3-Pg\n\r4-Verif  5-Atul");
   if (tmp == 255)
      return;
   comandoAdmin = tmp - '0';
   if (comandoAdmin == 1)
   {
      printf(lcd_escreve, "\f Incluir Pessoa");
      tipoTela = 2;
   }
   else if (comandoAdmin == 2)
   {
      printf(lcd_escreve, "\fExcluir Pessoa");
      tipoTela = 3;
   }
    else if (comandoAdmin == 3)
   {
      printf(lcd_escreve, "\f   Fazendo\n\r   Pagamento");
      tipoTela = 6;
   }
   else if (comandoAdmin == 4)
   {
      printf(lcd_escreve, "\f   Verifica\n\r   Pagamento");
      tipoTela = 4;
   }
   else if (comandoAdmin == 5)
   {
      printf(lcd_escreve, "\fEnvia Dados \n\rp/ Computador");
      tipoTela = 5;
   }
   else if (comandoAdmin == 9)
   {
      printf(lcd_escreve, "\f   Memoria\n\r   Apagada");
      tipoTela = 0;
      apagaMemoria();
   }
   limpaSenha();
   delay_ms(2000);
   comandoAdmin = 0;
}

void telaIncluir()
{
   printf(lcd_escreve, "\fInf. p/ incluir\n\rSenha: %s", senha);
   if (tmp == 255)
      return;
   if (posicaoSenha == 4)
   {
      posicaoSenha = 0;
   }
   if (tmp == 'D')
   {     
      if(novoUsuario(senha) == 1){
         printf(lcd_escreve, "\f    Cadastro\n\r   Realizado");        
      }else if(novoUsuario(senha) == 0){
         printf(lcd_escreve, "\f  Usuario ja\n\r  Existente");
      }else{
         printf(lcd_escreve, "\fMemoria Cheia");
      }
      delay_ms(2000);
      limpaSenha();
      tipoTela = 0;
   }
   else
   {
      senha[posicaoSenha++] = tmp;
   }
}

void telaExcluir()
{
   printf(lcd_escreve, "\fInf. p/ excluir\n\rSenha: %s", senha);
   if (tmp == 255)
      return;
   if (posicaoSenha == 4)
   {
      posicaoSenha = 0;
   }
   if (tmp == 'D')
   {
      if(excluirUsuario(senha) == 1){
         printf(lcd_escreve, "\f   Exclusao\n\r   Realizada");
      }else{
         printf(lcd_escreve, "\f Senha invalida!! ");
      }
      delay_ms(2000);
      limpaSenha();
      tipoTela = 0;
   }
   else
   {
      senha[posicaoSenha++] = tmp;
   }
}

void telaVerificar() // arrumar essa tela
{
   printf(lcd_escreve, "\fInf. p/ verificar\n\rSenha: %s", senha);
   if (tmp == 255)
      return;
   if (posicaoSenha == 4)
   {
      posicaoSenha = 0;
   }
   if (tmp == 'D')
   {
      if(verificaSenha(senha) == (-1)){
         printf(lcd_escreve, "\f Senha invalida!! ");
      }else if(verificaStatus(senha) == 1){
         printf(lcd_escreve, "\fMensalidade Paga!");
      }else{
         printf(lcd_escreve, "\f Pague a \n\r Mensalidade");
      }
      delay_ms(2000);
      limpaSenha();
      tipoTela = 0;
   }
   else
   {
      senha[posicaoSenha++] = tmp;
   }
}

void telaPagar(){
   printf(lcd_escreve, "\fInf. p/ pagar\n\rSenha: %s", senha);
   if (tmp == 255)
      return;
   if (posicaoSenha == 4)
   {
      posicaoSenha = 0;
   }
   if (tmp == 'D')
   {
      if(alteraStatus(senha) == 1){
         printf(lcd_escreve, "\f   Pagamento\n\r   Realizado");
      }else{
         printf(lcd_escreve, "\f Senha invalida!! ");
      }
      delay_ms(2000);
      limpaSenha();
      tipoTela = 0;
   }
   else
   {
      senha[posicaoSenha++] = tmp;
   }
}
