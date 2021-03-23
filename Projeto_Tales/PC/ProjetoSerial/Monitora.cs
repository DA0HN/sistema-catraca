using System;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;

namespace ProjetoSerial
{
	public partial class Monitora : Form
	{
		string log = @".\log.txt";
		
		public Monitora()
		{

			InitializeComponent();
			
		}
		
		
		void BtCarregarClick(object sender, EventArgs e)
		{
			String linha;
			try{
				using (StreamReader sr = new StreamReader(log))
				{
					// Lê linha por linha até o final do arquivo
					while ((linha = sr.ReadLine()) != null)
					{
						txSaida.Enabled = true;
						txSaida.AppendText(linha);
						txSaida.AppendText(System.Environment.NewLine);
						
					}
				}
			}
			catch (Exception ex){
				Debug.WriteLine(ex.Message);
			}
		}
		
		void BtVoltarClick(object sender, EventArgs e)
		{
			this.Close();
		}
	}
}
