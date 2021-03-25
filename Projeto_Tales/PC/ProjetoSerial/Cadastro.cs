using System;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;

namespace ProjetoSerial
{
	public partial class Cadastro : Form{
		
		Funcoes funcoes = new Funcoes();
		String[] temp;
		
		public Cadastro(){
			InitializeComponent();
		}
		
		void BtCadastroClick(object sender, EventArgs e){
			temp = funcoes.BuscaCod(txCodigo.Text);
			
			if(temp.Length!=1){
				lbErro.Text = "Código ja em uso!";
			}else{
				temp = new string[]{txCodigo.Text, txStatus.Text,txNome.Text,txSenha.Text};
				if(funcoes.adicionaDados(temp)==1){
					lbErro.Text = "Sem espaço na memoria!";
				}else{
					while(funcoes.temNaMemoria(txCodigo.Text)){
					      	funcoes.adicionaDados(temp);
					      }
					      lbErro.Text = "Cadastrado com Sucesso";
					      clearCampos();
					}
			}
		}
		
		void BtVoltarClick(object sender, EventArgs e){
			this.Close();
		}
		
		void clearCampos(){
			txCodigo.Text = "";
			txNome.Text = "";
			txSenha.Text = "";
			txStatus.Text = "";
		}
	}
}
