# Sistema Catraca

Desenvolvido por:
- Gabriel Honda
- Carlos Henrique
- Tales Hiago

# Funcionalidades

A catraca deve ter um teclado, um LCD, memória I2C e conexão serial com computador. Ainda,
uma interface no computador para manutenção do cadastro do cliente.

## Gerais

- A senha *deve ter* 4 dígitos.
- Cada cliente *deve* ocupar 6 posições de memória, sendo uma para o código, uma para o
status, e quatro para a senha.
- No aplicativo que vai rodar no computador *deve ter* uma interface para o cadastro do
cliente. A janela de cadastro *deve ter* os campos: código, nome, idade, status e *pode ter*
endereço, tipo sanguíneo, altura e mais campos que você achar necessário.
- As informações, no computador, *devem ser* gravadas em arquivo ou banco de dados.
Gostaria que fosse num banco de dados leve tipo Sqlite ou o outro nessa linha. Na placa,
as informações deve ser gravadas numa memória externa ao microcontrolador.
- A comunicação com o computador ser dará via serial virtual.


## PIC

- O usuário / cliente
  - Ao digitar uma senha e o microcontrolador deve verificar se senha está
  cadastrada e se o status do cliente é permitido ou não permitido. Se permitido
  o sistema deve exibir uma mensagem de boas-vindas e liberar a entrada que
  será simulado acionando um dos relês da placa. Se não permitido o sistema
  exibirá uma mensagem orientado o cliente a procurar o administrador.
- O administrador via teclado e LCD.
  - Cadastrar novos clientes.
  - Excluir clientes.
  - Verificar se um cliente/senha já está cadastrado.
  - Enviar lista atualizada para o computador.

## Desktop

- O sistema.
  - O sistema deve enviar par o computador o código do cliente toda vez que entrar
  (marcador de presença).
  - O sistema que roda no computador deve gravar a presença no disco (arquivo ou
  banco de dados).

