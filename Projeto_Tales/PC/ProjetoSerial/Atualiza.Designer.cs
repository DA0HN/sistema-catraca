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
	partial class Atualiza
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
			this.btVerifica = new System.Windows.Forms.Button();
			this.txSaida = new System.Windows.Forms.TextBox();
			this.btEnvia = new System.Windows.Forms.Button();
			this.btVoltar = new System.Windows.Forms.Button();
			this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
			this.SuspendLayout();
			// 
			// label2
			// 
			this.label2.Font = new System.Drawing.Font("Times New Roman", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label2.Location = new System.Drawing.Point(114, 26);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(417, 73);
			this.label2.TabIndex = 7;
			this.label2.Text = "Atualizar banco";
			this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// btVerifica
			// 
			this.btVerifica.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btVerifica.Location = new System.Drawing.Point(213, 405);
			this.btVerifica.Name = "btVerifica";
			this.btVerifica.Size = new System.Drawing.Size(244, 53);
			this.btVerifica.TabIndex = 29;
			this.btVerifica.Text = "Verificar Banco";
			this.btVerifica.UseVisualStyleBackColor = true;
			this.btVerifica.Click += new System.EventHandler(this.BtVerificaClick);
			// 
			// txSaida
			// 
			this.txSaida.Enabled = false;
			this.txSaida.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txSaida.Location = new System.Drawing.Point(49, 102);
			this.txSaida.Multiline = true;
			this.txSaida.Name = "txSaida";
			this.txSaida.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
			this.txSaida.Size = new System.Drawing.Size(565, 297);
			this.txSaida.TabIndex = 30;
			// 
			// btEnvia
			// 
			this.btEnvia.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btEnvia.Location = new System.Drawing.Point(213, 464);
			this.btEnvia.Name = "btEnvia";
			this.btEnvia.Size = new System.Drawing.Size(244, 53);
			this.btEnvia.TabIndex = 31;
			this.btEnvia.Text = "Envia Banco";
			this.btEnvia.UseVisualStyleBackColor = true;
			// 
			// btVoltar
			// 
			this.btVoltar.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btVoltar.Location = new System.Drawing.Point(213, 523);
			this.btVoltar.Name = "btVoltar";
			this.btVoltar.Size = new System.Drawing.Size(244, 53);
			this.btVoltar.TabIndex = 32;
			this.btVoltar.Text = "Voltar";
			this.btVoltar.UseVisualStyleBackColor = true;
			// 
			// Atualiza
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(684, 611);
			this.Controls.Add(this.btVoltar);
			this.Controls.Add(this.btEnvia);
			this.Controls.Add(this.txSaida);
			this.Controls.Add(this.btVerifica);
			this.Controls.Add(this.label2);
			this.Name = "Atualiza";
			this.Text = "Atualiza";
			this.ResumeLayout(false);
			this.PerformLayout();
		}
		private System.IO.Ports.SerialPort serialPort1;
		private System.Windows.Forms.Button btVoltar;
		private System.Windows.Forms.Button btEnvia;
		private System.Windows.Forms.TextBox txSaida;
		private System.Windows.Forms.Button btVerifica;
		private System.Windows.Forms.Label label2;
	}
}
