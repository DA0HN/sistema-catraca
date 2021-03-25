/*
 * Criado por SharpDevelop.
 * Usuário: tales
 * Data: 23/03/2021
 * Hora: 11:26
 * 
 * Para alterar este modelo use Ferramentas | Opções | Codificação | Editar Cabeçalhos Padrão.
 */
namespace ProjetoSerial
{
	partial class Cadastro
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
			this.label2 = new System.Windows.Forms.Label();
			this.txNome = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.txCodigo = new System.Windows.Forms.TextBox();
			this.label4 = new System.Windows.Forms.Label();
			this.txStatus = new System.Windows.Forms.TextBox();
			this.label5 = new System.Windows.Forms.Label();
			this.txSenha = new System.Windows.Forms.TextBox();
			this.btCadastro = new System.Windows.Forms.Button();
			this.btVoltar = new System.Windows.Forms.Button();
			this.lbErro = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// label2
			// 
			this.label2.Font = new System.Drawing.Font("Times New Roman", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label2.Location = new System.Drawing.Point(125, 21);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(417, 158);
			this.label2.TabIndex = 1;
			this.label2.Text = "Cadastro de novo Cliente";
			this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// txNome
			// 
			this.txNome.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txNome.Location = new System.Drawing.Point(184, 233);
			this.txNome.Name = "txNome";
			this.txNome.Size = new System.Drawing.Size(358, 38);
			this.txNome.TabIndex = 2;
			// 
			// label1
			// 
			this.label1.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label1.Location = new System.Drawing.Point(89, 233);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(89, 38);
			this.label1.TabIndex = 3;
			this.label1.Text = "Nome:";
			// 
			// label3
			// 
			this.label3.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label3.Location = new System.Drawing.Point(89, 277);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(100, 38);
			this.label3.TabIndex = 5;
			this.label3.Text = "Codigo:";
			// 
			// txCodigo
			// 
			this.txCodigo.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txCodigo.Location = new System.Drawing.Point(195, 277);
			this.txCodigo.MaxLength = 1;
			this.txCodigo.Name = "txCodigo";
			this.txCodigo.Size = new System.Drawing.Size(347, 38);
			this.txCodigo.TabIndex = 4;
			// 
			// label4
			// 
			this.label4.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label4.Location = new System.Drawing.Point(89, 321);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(89, 38);
			this.label4.TabIndex = 7;
			this.label4.Text = "Status:";
			// 
			// txStatus
			// 
			this.txStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txStatus.Location = new System.Drawing.Point(184, 321);
			this.txStatus.MaxLength = 1;
			this.txStatus.Name = "txStatus";
			this.txStatus.Size = new System.Drawing.Size(358, 38);
			this.txStatus.TabIndex = 6;
			// 
			// label5
			// 
			this.label5.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label5.Location = new System.Drawing.Point(89, 365);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(89, 38);
			this.label5.TabIndex = 9;
			this.label5.Text = "Senha:";
			// 
			// txSenha
			// 
			this.txSenha.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txSenha.Location = new System.Drawing.Point(184, 365);
			this.txSenha.MaxLength = 4;
			this.txSenha.Name = "txSenha";
			this.txSenha.Size = new System.Drawing.Size(358, 38);
			this.txSenha.TabIndex = 8;
			// 
			// btCadastro
			// 
			this.btCadastro.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btCadastro.Location = new System.Drawing.Point(193, 450);
			this.btCadastro.Name = "btCadastro";
			this.btCadastro.Size = new System.Drawing.Size(244, 68);
			this.btCadastro.TabIndex = 10;
			this.btCadastro.Text = "Salvar";
			this.btCadastro.UseVisualStyleBackColor = true;
			this.btCadastro.Click += new System.EventHandler(this.BtCadastroClick);
			// 
			// btVoltar
			// 
			this.btVoltar.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btVoltar.Location = new System.Drawing.Point(193, 524);
			this.btVoltar.Name = "btVoltar";
			this.btVoltar.Size = new System.Drawing.Size(244, 68);
			this.btVoltar.TabIndex = 11;
			this.btVoltar.Text = "Voltar";
			this.btVoltar.UseVisualStyleBackColor = true;
			this.btVoltar.Click += new System.EventHandler(this.BtVoltarClick);
			// 
			// lbErro
			// 
			this.lbErro.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lbErro.ForeColor = System.Drawing.Color.Red;
			this.lbErro.Location = new System.Drawing.Point(71, 157);
			this.lbErro.Name = "lbErro";
			this.lbErro.Size = new System.Drawing.Size(572, 76);
			this.lbErro.TabIndex = 12;
			this.lbErro.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// Cadastro
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(684, 611);
			this.Controls.Add(this.btVoltar);
			this.Controls.Add(this.btCadastro);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.txSenha);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.txStatus);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.txCodigo);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.txNome);
			this.Controls.Add(this.lbErro);
			this.Controls.Add(this.label2);
			this.Name = "Cadastro";
			this.Text = "Cadastro";
			this.ResumeLayout(false);
			this.PerformLayout();
		}
		private System.Windows.Forms.Label lbErro;
		private System.Windows.Forms.Button btVoltar;
		private System.Windows.Forms.Button btCadastro;
		private System.Windows.Forms.TextBox txSenha;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.TextBox txStatus;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.TextBox txCodigo;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.TextBox txNome;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label1;
	}
}
