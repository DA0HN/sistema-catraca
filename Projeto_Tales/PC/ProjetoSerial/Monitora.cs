using System;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;
using System.IO.Ports;
using System.Globalization;

namespace ProjetoSerial
{
	public partial class Monitora : Form
	{
		string log = @".\log.txt";
		SerialPort serial = new SerialPort("COM3",9600);
		String linha;
		
		
		public Monitora()
		{
			InitializeComponent();
			serial.Open();
			this.backgroundWorker1.RunWorkerAsync(100);
		}
		
		
		void BtCarregarClick(object sender, EventArgs e)
		{
			
			try{
				txSaida.Text = "";
				txSaida.Enabled = true;
				using (StreamReader sr = new StreamReader(log))
				{
					// Lê linha por linha até o final do arquivo
					while ((linha = sr.ReadLine()) != null)
					{
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
			serial.Close();
			this.Close();
		}		
		
		void BackgroundWorker1DoWork(object sender, System.ComponentModel.DoWorkEventArgs e)
		{
			try{
				int recebido = 0;
				Funcoes funcoes = new Funcoes();
				var culture = new CultureInfo("pt-BR");
				String b= "";
				String[] temp;
				String[] temp2;
				String[] separador = new String[] {"*"};
				while(true){
					if(serial.BytesToRead > 0){
						char r = (char)serial.ReadByte();
						b += r.ToString();
						recebido++;
						if(recebido == 3){
							DateTime localDate = DateTime.Now;
							temp = b.Split(separador,StringSplitOptions.None);
							b = localDate.ToString(culture);
							temp2 = funcoes.BuscaCod(temp[0]);
							b += ": ";
							b += temp2[1];
							if(temp[1] == "1"){
								b+= " -> Entrou";
								//temp[1] = "1";
								
							}else{
								b+= " -> Saiu";
								//temp[1] = "0";
							}
							using (StreamWriter writer = new StreamWriter(log, true)){
								writer.WriteLine(b);
							}
							
							Debug.WriteLine(b);
							recebido = 0;
							funcoes.atualizaDados(temp);
							b = "";
						}
						
					}
					
				}
			}catch(IOException ex){
				Debug.WriteLine(ex);
			}
		}
	}
}

