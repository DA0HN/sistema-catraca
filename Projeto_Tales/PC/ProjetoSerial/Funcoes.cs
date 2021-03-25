using System;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;

namespace ProjetoSerial
{
	public class Funcoes
	{
		public Funcoes(){
			CarregaArquivo();
		}
		string banco = @".\banco.txt";
		String[,] dados = new String[16,4];
		String[] separador = new String[] {"*"};
		String[] temp;
		String linha;
		
		int i = 0, encontrou = 42;
		
		public void salvaDados(){
			System.IO.File.WriteAllText(banco,string.Empty);
			using (StreamWriter writer = new StreamWriter(banco, true)){
				
				for(int a=0;a<16;a++){
					linha = "";
					for(int b=0;b<4;b++){
						if(dados[a,0]!=""){
							linha += dados[a,b];
							linha += "*";
						}else{
							linha = "";
						}
					}
					writer.WriteLine(linha);
				}
			}
		}
		
		public void CarregaArquivo(){
			try{
				using (StreamReader sr = new StreamReader(banco))
				{
					// Lê linha por linha até o final do arquivo
					while ((linha = sr.ReadLine()) != null)
					{
						//Transforma a linha num array
						temp = linha.Split(separador,StringSplitOptions.None);
						
						for(int a=0;a<temp.Length-1;a++){
							dados[i,a] = temp[a];
						}
						i++;
					}
				}
			}
			catch (Exception ex){
				Debug.WriteLine(ex.Message);
			}

		}
		public void sobrescreveArquivo(String[,] arquivo){
			dados = arquivo;
			salvaDados();
		}
		
		public String[,] bancoCompleto(){
			return dados;
		}
		
		public String[] BuscaCod(String valor){
			String[] temp = new string[3];
			for(int a = 0;a<16;a++){
				if(valor == dados[a,0]){
					temp = new string[]{dados[a,1],dados[a,2],dados[a,3]};
					encontrou = a;
					return temp;
				}
			}
			encontrou = 42;
			temp = new string[]{"Dados Não Encontrados"};
			return temp;
		}
		
		public void atualizaDados(String[] temp){
			if(encontrou!=42){
				dados[encontrou,1] = temp[0];
				dados[encontrou,2] = temp[1];
				dados[encontrou,3] = temp[2];
				salvaDados();
				CarregaArquivo();
			}
		}
		
		public bool temNaMemoria(String code){
			for(int a = 0;a<10;a++){
				if(dados[a,0]==code)
					return false;
			}
			return true;
		}
		
		public int adicionaDados(String[] temp){
			Debug.WriteLine("Adicionando");
			for(int a=0;a<16;a++){
				if(dados[a,0]==""){
					for(int b=0;b<4;b++){
						dados[a,b]=temp[b];
					}
					break;
				}
				if(a+1==17)
					return 1;
			}
			
			salvaDados();
			CarregaArquivo();
			return 0;
		}
		
		public void mostraDados(){
			for(int a = 0;a<16;a++){
				linha = "";
				for(int b = 0; b<4;b++){
					linha += dados[a,b];
				}
			}
		}
		
		public void excluir(){
			if(encontrou!=42){
				for(int a =0;a<4;a++)
					dados[encontrou,a] = "";
				salvaDados();
			}
		}
	}
}