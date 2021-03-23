/*
 * Criado por SharpDevelop.
 * Usuário: tales
 * Data: 23/03/2021
 * Hora: 11:34
 * 
 * Para alterar este modelo use Ferramentas | Opções | Codificação | Editar Cabeçalhos Padrão.
 */
namespace ProjetoSerial
{
	partial class Excluir
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
			this.btExcluir = new System.Windows.Forms.Button();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.txCodigo = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.label4 = new System.Windows.Forms.Label();
			this.label5 = new System.Windows.Forms.Label();
			this.label6 = new System.Windows.Forms.Label();
			this.btVerifica = new System.Windows.Forms.Button();
			this.btVoltar = new System.Windows.Forms.Button();
			this.lbNome = new System.Windows.Forms.Label();
			this.lbStatus = new System.Windows.Forms.Label();
			this.lbSenha = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// btExcluir
			// 
			this.btExcluir.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btExcluir.Location = new System.Drawing.Point(239, 468);
			this.btExcluir.Name = "btExcluir";
			this.btExcluir.Size = new System.Drawing.Size(244, 53);
			this.btExcluir.TabIndex = 3;
			this.btExcluir.Text = "Exluir";
			this.btExcluir.UseVisualStyleBackColor = true;
			this.btExcluir.Click += new System.EventHandler(this.BtExcluirClick);
			// 
			// label2
			// 
			this.label2.Font = new System.Drawing.Font("Times New Roman", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label2.Location = new System.Drawing.Point(151, 42);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(417, 73);
			this.label2.TabIndex = 4;
			this.label2.Text = "Exluir Clientes";
			this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label3
			// 
			this.label3.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label3.Location = new System.Drawing.Point(254, 185);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(100, 38);
			this.label3.TabIndex = 7;
			this.label3.Text = "Codigo:";
			// 
			// txCodigo
			// 
			this.txCodigo.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txCodigo.Location = new System.Drawing.Point(360, 185);
			this.txCodigo.MaxLength = 1;
			this.txCodigo.Name = "txCodigo";
			this.txCodigo.Size = new System.Drawing.Size(72, 38);
			this.txCodigo.TabIndex = 6;
			// 
			// label1
			// 
			this.label1.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label1.Location = new System.Drawing.Point(126, 325);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(89, 38);
			this.label1.TabIndex = 9;
			this.label1.Text = "Nome:";
			// 
			// label4
			// 
			this.label4.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label4.Location = new System.Drawing.Point(126, 369);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(89, 38);
			this.label4.TabIndex = 11;
			this.label4.Text = "Status:";
			// 
			// label5
			// 
			this.label5.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label5.Location = new System.Drawing.Point(126, 413);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(89, 38);
			this.label5.TabIndex = 13;
			this.label5.Text = "Senha:";
			// 
			// label6
			// 
			this.label6.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label6.Location = new System.Drawing.Point(185, 138);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(324, 47);
			this.label6.TabIndex = 14;
			this.label6.Text = "Digite o Código";
			this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// btVerifica
			// 
			this.btVerifica.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btVerifica.Location = new System.Drawing.Point(254, 229);
			this.btVerifica.Name = "btVerifica";
			this.btVerifica.Size = new System.Drawing.Size(216, 40);
			this.btVerifica.TabIndex = 15;
			this.btVerifica.Text = "Verificar";
			this.btVerifica.UseVisualStyleBackColor = true;
			this.btVerifica.Click += new System.EventHandler(this.BtVerificaClick);
			// 
			// btVoltar
			// 
			this.btVoltar.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btVoltar.Location = new System.Drawing.Point(239, 527);
			this.btVoltar.Name = "btVoltar";
			this.btVoltar.Size = new System.Drawing.Size(244, 53);
			this.btVoltar.TabIndex = 16;
			this.btVoltar.Text = "Voltar";
			this.btVoltar.UseVisualStyleBackColor = true;
			this.btVoltar.Click += new System.EventHandler(this.BtVoltarClick);
			// 
			// lbNome
			// 
			this.lbNome.BackColor = System.Drawing.SystemColors.ButtonHighlight;
			this.lbNome.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lbNome.Location = new System.Drawing.Point(239, 325);
			this.lbNome.Name = "lbNome";
			this.lbNome.Size = new System.Drawing.Size(329, 38);
			this.lbNome.TabIndex = 17;
			// 
			// lbStatus
			// 
			this.lbStatus.BackColor = System.Drawing.SystemColors.ButtonHighlight;
			this.lbStatus.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lbStatus.Location = new System.Drawing.Point(239, 369);
			this.lbStatus.Name = "lbStatus";
			this.lbStatus.Size = new System.Drawing.Size(329, 38);
			this.lbStatus.TabIndex = 18;
			// 
			// lbSenha
			// 
			this.lbSenha.BackColor = System.Drawing.SystemColors.ButtonHighlight;
			this.lbSenha.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lbSenha.Location = new System.Drawing.Point(239, 413);
			this.lbSenha.Name = "lbSenha";
			this.lbSenha.Size = new System.Drawing.Size(329, 38);
			this.lbSenha.TabIndex = 19;
			// 
			// Excluir
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(697, 608);
			this.Controls.Add(this.lbSenha);
			this.Controls.Add(this.lbStatus);
			this.Controls.Add(this.lbNome);
			this.Controls.Add(this.btVoltar);
			this.Controls.Add(this.btVerifica);
			this.Controls.Add(this.label6);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.txCodigo);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.btExcluir);
			this.Name = "Excluir";
			this.Text = "Excluir";
			this.ResumeLayout(false);
			this.PerformLayout();
		}
		private System.Windows.Forms.Label lbSenha;
		private System.Windows.Forms.Label lbStatus;
		private System.Windows.Forms.Label lbNome;
		private System.Windows.Forms.Button btVoltar;
		private System.Windows.Forms.Button btVerifica;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox txCodigo;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Button btExcluir;
	}
}
