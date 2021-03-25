unsigned char memoriaNull = 0xFF; 
int posicaoMemoria = 0;
#define tamUsuario 6
#define tamMemoria 255

int isPosicaoMemoriaNull(){
   int contador = 0;
   while(contador < tamMemoria){ //percorre ate o tamanho maximo da memoria 
      if(read_ext_eeprom(contador) == memoriaNull){
         return contador;
      }
      contador++;
   }
   return (-1);
}


 salvaMemoria(unsigned char usuario[6]){
   int isNull = isPosicaoMemoriaNull();
   if(isNull == (-1)){
      return (-1);
   }else{
      for(int i = 0; i < tamUsuario; i++){ 
         write_ext_eeprom(isNull++, usuario[i]);  
      }
   }
}

void apagaMemoria(){
   int contador = 0;
   while(contador < tamMemoria){
      write_ext_eeprom(contador++, memoriaNull);  
   }
}

int idUsuario(){
   int isNull = isPosicaoMemoriaNull();
   if(isNull == 0){
      return 1 + '0';
   }else{
      return (read_ext_eeprom(isNull - 6)) + 1;
   }
}

int verificaSenha(unsigned char senha[4]){
   int i =2, j = 3, k = 4, l = 5;
   while(l < tamMemoria){
      if(senha[0] == read_ext_eeprom(i) &&
           senha[1] == read_ext_eeprom(j) &&
           senha[2] == read_ext_eeprom(k) &&
           senha[3] == read_ext_eeprom(l)){
         return i;
      }
      i += 7;
      j += 7;
      k += 7;
      l += 7;
   }
   return (-1);
}

int verificaTipoUsuario(unsigned char senha[4]){
   if(senha[0] == '0' && senha[1] == '0' && senha[2] == '0' && senha[3] == '0'){
      return 1;
   }else if(verificaSenha(senha) != (-1)){
       return 2;
   }else{
      return (-1);
   }
}

int novoUsuario(unsigned char senha[4]){ 

   char usuario[6];
   int isNullEmpty = isPosicaoMemoriaNull();

   if(isNullEmpty == (-1)){
      return (-1);
   }else if(verificaSenha(senha) == (-1)){ 
      usuario[0] = idUsuario();    
      usuario[1] = 1 + '0'; 
      usuario[2] = senha[0];
      usuario[3] = senha[1];
      usuario[4] = senha[2];
      usuario[5] = senha[3];
      salvaMemoria(usuario);
      return 1;
   }else{
      return 0;
   }
}

int excluirUsuario(unsigned char senha[4]){
   int i = verificaSenha(senha);
   if(i != (-1)){
      write_ext_eeprom(i - 2, memoriaNull);
      write_ext_eeprom(i - 1, memoriaNull); 
      write_ext_eeprom(i, memoriaNull); 
      write_ext_eeprom(i + 1, memoriaNull); 
      write_ext_eeprom(i + 2, memoriaNull); 
      write_ext_eeprom(i + 3, memoriaNull); 
      return 1;
   }  
   return 0;
}

int alteraStatus(unsigned char senha[4]){  
   int posicao = verificaSenha(senha);
   int status =  read_ext_eeprom(posicao - 1) - '0';
   if(posicao != (-1)){
      if(status == 0){
         write_ext_eeprom(posicao - 1, 1 + '0');
      }else{
         write_ext_eeprom(posicao - 1, 0 + '0');         
      }
      return 1;
   }
   return 0;
}

int verificaStatus(unsigned char senha[4]){
   int posicao = verificaSenha(senha);
   if(posicao != (-1)){
      return read_ext_eeprom(posicao - 1) - '0';
   }
   return (-1);
}

void enviaDados(){ //envia os dados da matriz via serial     
      int contador = 0;
      int posicao = isPosicaoMemoriaNull();
      int contUsuario = 0;
      while(contador < posicao){
      
         if(contUsuario < 5){
            fprintf(PORT1, "%d,", read_ext_eeprom(contador) - '0'); 
            contUsuario++;
         }else{
            fprintf(PORT1, "%d\n\r",  read_ext_eeprom(contador) - '0');
            contUsuario = 0;
         }
         output_toggle(PIN_D1);
         delay_ms(500);
         contador++;
      }
      
      fprintf(PORT1, "update\n\r");
      output_toggle(PIN_D1);
}      
            
void recebeDados(int ch){//recebe os dados via serial e armazena na memoria
   if(ch == 'I'){
      posicaoMemoria = 0;
      apagaMemoria();    
   }else{
      write_ext_eeprom(posicaoMemoria, ch);     
      posicaoMemoria++;
   }
}                        
            
         
   
    
   
 


