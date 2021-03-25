using System;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;

namespace ProjetoSerial
{
	public partial class Excluir : Form
	{
		Funcoes funcoes = new Funcoes();
		String[] temp;
		
		public Excluir()
		{

			InitializeComponent();

		}
		
		void BtVoltarClick(object sender, EventArgs e)
		{
			this.Close();
		}
		
		void BtExcluirClick(object sender, EventArgs e)
		{
			funcoes.excluir();
			clearCampos();
			txCodigo.Text = "";
		}
		
		void BtVerificaClick(object sender, EventArgs e)
		{
			clearCampos();
			temp = funcoes.BuscaCod(txCodigo.Text);
			lbStatus.Text = temp[0];
			if(lbStatus.Text.Length == 1){
				lbNome.Text = temp[1];
				lbSenha.Text = temp[2];
			}
		}
		void clearCampos(){
			lbNome.Text = "";
			lbSenha.Text = "";
			lbStatus.Text = "";
		}
	}
}
