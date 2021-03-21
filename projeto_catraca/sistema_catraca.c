#include <sistema_catraca.h>
#include <math.h>
#include <stdio.h>
#INCLUDE < 2404.C>
#include "lib/lcd_util.c"
#include "lib/teclado_util.c"
#include "lib/memoria_util.c"

unsigned char tmp;
char senha[4];
int posicaoSenha = 0;
int tipoTela = 0;
int comandoAdmin = 0;

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
   printf(lcd_escreve, "\f1- Incluir\n\r2- Excluir");
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

#INT_RB
void RB_isr(void)
{
   disable_interrupts(INT_RB);
   clear_interrupt(INT_RB);

   tmp = tc_tecla();
   if (tipoTela == 0)
   {
      telaPrincipal();
   }
   else if (tipoTela == 1)
   {
      telaCrudAdmin();
   }
   else if (tipoTela == 2)
   {
      telaIncluir();
   }
   else if (tipoTela == 3)
   {
      telaExcluir();
   }

   clear_interrupt(INT_RB);
   enable_interrupts(INT_RB);
   output_low(PIN_B0);
   output_low(PIN_B1);
   output_low(PIN_B2);
   output_low(PIN_B3);
}

void main()
{

   init_ext_eeprom();
   //apagaMemoria();
   carregaMemoria();
   //configuracaoMemoria();

   lcd_ini();
   delay_ms(10);

   printf(lcd_escreve, "\f Teclado");
   delay_ms(1000);

   set_tris_b(0xF0);
   port_B_pullups(true);
   enable_interrupts(INT_RB);
   enable_interrupts(GLOBAL);
   output_low(PIN_B0);
   output_low(PIN_B1);
   output_low(PIN_B2);
   output_low(PIN_B3);

   while (TRUE)
   {
   }
}
