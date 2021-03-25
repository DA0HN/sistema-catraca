using System;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;

namespace ProjetoSerial
{
	public partial class Verifica : Form
	{

		Funcoes funcoes = new Funcoes();
		String[] temp;
		
		public Verifica()
		{
			InitializeComponent();

		}
		
		void BtVerificaClick(object sender, EventArgs e)
		{
			clearCampos();
			temp = funcoes.BuscaCod(txCodigo.Text);
			txStatus.Text = temp[0];
			if(txStatus.TextLength == 1){
				txNome.Text = temp[1];
				txSenha.Text = temp[2];
			}
		}
		
		void BtSalvarClick(object sender, EventArgs e)
		{
			if(txSenha.Text !=""){
				temp = new string[]{txStatus.Text, txNome.Text, txSenha.Text};
				funcoes.atualizaDados(temp);
				while(funcoes.temNaMemoria(txCodigo.Text)){
					funcoes.adicionaDados(temp);
				}
				lbErro.Text = "Atualizado com Sucesso";
				clearCampos();
			}else{
				txNome.Text = "Pesquise Primeiro";
			}
		}
		
		void clearCampos(){
			txNome.Text = "";
			txSenha.Text = "";
			txStatus.Text = "";
		}
		
		void BtVoltarClick(object sender, EventArgs e)
		{
			this.Close();
		}
		
	}
}

