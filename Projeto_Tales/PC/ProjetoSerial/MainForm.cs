/*
 * Criado por SharpDevelop.
 * Usuário: tales
 * Data: 23/03/2021
 * Hora: 11:22
 * 
 * Para alterar este modelo use Ferramentas | Opções | Codificação | Editar Cabeçalhos Padrão.
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace ProjetoSerial
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		public MainForm()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
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
