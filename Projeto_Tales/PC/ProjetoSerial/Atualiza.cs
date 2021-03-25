using System;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;
using System.IO.Ports;

namespace ProjetoSerial
{

	public partial class Atualiza : Form
	{
		SerialPort serial = new SerialPort("COM3",9600);
		string banco = @".\banco.txt";
		Funcoes funcoes = new Funcoes();
		String[,] dados = new String[16,4];
		String[,] dados2 = new String[16,4];
		String[] temp;
		String[] separador = new String[] {"*"};
		String b= "";
		char r;
		int recebido = 0;
		int i = 0, f = 0;
		public Atualiza()
		{

			InitializeComponent();
			serial.Open();
			this.backgroundWorker1.RunWorkerAsync(100);
		}
		
		void BtVerificaClick(object sender, EventArgs e)
		{
//			serial.Write("B");
			Debug.WriteLine("Mostrando");
			txSaida.Enabled = true;
			txSaida.Text="";
			try{
				using (StreamReader sr = new StreamReader(banco))
				{
					String linha;
					// Lê linha por linha até o final do arquivo
					while ((linha = sr.ReadLine()) != null)
					{
						//Transforma a linha num array
						temp = linha.Split(separador,StringSplitOptions.None);
						Debug.WriteLine(linha);
						if(temp[0]!=""){
							txSaida.AppendText("Código: "+temp[0]);
							txSaida.AppendText(" / Status: "+temp[1]);
							txSaida.AppendText(" / Nome: "+temp[2]);
							txSaida.AppendText(" / Senha: "+temp[3]);
							txSaida.AppendText(System.Environment.NewLine);
						}

					}
				}
			}
			catch (Exception ex){
				Debug.WriteLine(ex.Message);
			}
		}
		
		void BtEnviaClick(object sender, EventArgs e)
		{
			dados2 = funcoes.bancoCompleto();
			serial.Write("R");
			for(f = 0;f<16;f++){
				if(dados2[f,0] != null){
					Debug.WriteLine("-"+dados2[f,0]+"-");
					serial.Write(dados2[f,0]);
					serial.Write(dados2[f,1]);
					serial.Write(dados2[f,3]);
				}
			}
			Debug.WriteLine("Finalizou o envio!");
			serial.Write("T");
			
		}
		
		void BtVoltarClick(object sender, EventArgs e)
		{
			serial.Close();
			this.Close();
		}
		
		void BackgroundWorker1DoWork(object sender, System.ComponentModel.DoWorkEventArgs e)
		{
			
			while(true){
				if(serial.BytesToRead > 0){
					r = (char)serial.ReadByte();
					Debug.WriteLine("Recebido: "+r);
					if(r == 'T'){
						i=42;
					}else if(r == 'B'){
						i=0;
						r = (char)serial.ReadByte();
					}
					if(i!=42){
						b += r.ToString();
						recebido++;
						if(recebido == 12){
							Debug.WriteLine("Recebendo banco, linha: "+i);
							Debug.WriteLine(b);
							temp = b.Split(separador,StringSplitOptions.None);
							b = "";
							dados[i,0] = temp[0];
							dados[i,1] = temp[1];
							b += temp[2];
							b += temp[3];
							b += temp[4];
							b += temp[5];
							dados[i,3] = b;
							recebido = 0;
							i++;
							b = "";
						}
						
					}
					
					funcoes.sobrescreveArquivo(dados);
				}
			}
			
			
		}
	}
}
