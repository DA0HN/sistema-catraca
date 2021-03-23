#include <sistema_catraca.h>
#include <math.h>
#include <stdio.h>
#include <2404.c>
#include "lib/lcd_util.c"
#include "lib/teclado_util.c"
#include "lib/memoria_util.c"

unsigned char tmp;
char senha[4];
int posicaoSenha = 0;
int tipoTela = 0;
int comandoAdmin = 0;


int lin = 1;
int col = 0;
char ch;

void telaStatus()
{
   if (status(senha) == 0)
   {
      printf(lcd_escreve, "\f   Bem Vindo! ");
   }
   else
   {
      printf(lcd_escreve, "\f  Volte Sempre! ");
   }
   output_high(PIN_C0);
   alteraStatus(senha);
   delay_ms(2000);
   output_low(PIN_C0);
}

void limpaSenha()
{
   senha[0] = senha[1] = senha[2] = senha[3] = '\0';
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
      int usuario = verificaUsuario(senha);
      if (usuario == 0)
      {
         telaStatus();
         tipoTela = 0;
      }
      else if (usuario == 1)
      {
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
   printf(lcd_escreve, "\f1-Inc   2-Exc\n\r3-Verif  4-Atul");
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
      printf(lcd_escreve, "\fVerifica Pessoa");
      tipoTela = 4;
   }
   else if (comandoAdmin == 4)
   {
      printf(lcd_escreve, "\fEnvia Dados \n\rp/ Computador");
      tipoTela = 5;
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
      novoUsuario(senha);
      printf(lcd_escreve, "\f    Cadastro\n\r   Realizado");
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
      excluiUsuario(senha);
      printf(lcd_escreve, "\fExclusao Realizada");
      delay_ms(2000);
      limpaSenha();
      tipoTela = 0;
   }
   else
   {
      senha[posicaoSenha++] = tmp;
   }
}


void telaVerificar()
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
      if(verificaUsuario(senha) == 0){
         printf(lcd_escreve, "\fUsuario Valido");
      }else{
         printf(lcd_escreve, "\fUsuario Invalido");
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
