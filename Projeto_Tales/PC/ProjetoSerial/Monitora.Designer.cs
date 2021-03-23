/*
 * Criado por SharpDevelop.
 * Usuário: tales
 * Data: 23/03/2021
 * Hora: 12:14
 * 
 * Para alterar este modelo use Ferramentas | Opções | Codificação | Editar Cabeçalhos Padrão.
 */
namespace ProjetoSerial
{
	partial class Monitora
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.label2 = new System.Windows.Forms.Label();
			this.txSaida = new System.Windows.Forms.TextBox();
			this.btVoltar = new System.Windows.Forms.Button();
			this.btCarregar = new System.Windows.Forms.Button();
			this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
			this.SuspendLayout();
			// 
			// label2
			// 
			this.label2.Font = new System.Drawing.Font("Times New Roman", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label2.Location = new System.Drawing.Point(120, 18);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(417, 73);
			this.label2.TabIndex = 6;
			this.label2.Text = "Monitora Clientes";
			this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// txSaida
			// 
			this.txSaida.Enabled = false;
			this.txSaida.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txSaida.Location = new System.Drawing.Point(58, 94);
			this.txSaida.Multiline = true;
			this.txSaida.Name = "txSaida";
			this.txSaida.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
			this.txSaida.Size = new System.Drawing.Size(565, 350);
			this.txSaida.TabIndex = 7;
			// 
			// btVoltar
			// 
			this.btVoltar.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btVoltar.Location = new System.Drawing.Point(231, 520);
			this.btVoltar.Name = "btVoltar";
			this.btVoltar.Size = new System.Drawing.Size(244, 53);
			this.btVoltar.TabIndex = 27;
			this.btVoltar.Text = "Voltar";
			this.btVoltar.UseVisualStyleBackColor = true;
			this.btVoltar.Click += new System.EventHandler(this.BtVoltarClick);
			// 
			// btCarregar
			// 
			this.btCarregar.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btCarregar.Location = new System.Drawing.Point(231, 461);
			this.btCarregar.Name = "btCarregar";
			this.btCarregar.Size = new System.Drawing.Size(244, 53);
			this.btCarregar.TabIndex = 28;
			this.btCarregar.Text = "Carregar";
			this.btCarregar.UseVisualStyleBackColor = true;
			this.btCarregar.Click += new System.EventHandler(this.BtCarregarClick);
			// 
			// Monitora
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(684, 611);
			this.Controls.Add(this.btCarregar);
			this.Controls.Add(this.btVoltar);
			this.Controls.Add(this.txSaida);
			this.Controls.Add(this.label2);
			this.Name = "Monitora";
			this.Text = "Monitora";
			this.ResumeLayout(false);
			this.PerformLayout();
		}
		private System.IO.Ports.SerialPort serialPort1;
		private System.Windows.Forms.Button btCarregar;
		private System.Windows.Forms.Button btVoltar;
		private System.Windows.Forms.TextBox txSaida;
		private System.Windows.Forms.Label label2;
	}
}
