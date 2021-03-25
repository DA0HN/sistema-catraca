using System;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;
using System.IO.Ports;
using System.Globalization;

namespace ProjetoSerial
{

	public partial class MainForm : Form
	{
		
		
		
		public MainForm()
		{

			InitializeComponent();
			
		}
		void BtCadastroClick(object sender, EventArgs e)
		{
			Cadastro cadastro = new Cadastro();
			cadastro.Show();
			
		}
		
		void BtExcluirClick(object sender, EventArgs e)
		{
			Excluir excluir = new Excluir();
			excluir.Show();
			
		}
		
		void BtVerificaClick(object sender, EventArgs e)
		{
			Verifica verifica = new Verifica();
			verifica.Show();
		}
		
		void BtAtualizaClick(object sender, EventArgs e)
		{
			Atualiza atualiza = new Atualiza();
			atualiza.Show();
		}
		
		
	}
	
	
}
