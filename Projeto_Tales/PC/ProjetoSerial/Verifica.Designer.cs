namespace ProjetoSerial
{
	partial class Verifica
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
			this.btVerifica = new System.Windows.Forms.Button();
			this.label3 = new System.Windows.Forms.Label();
			this.txCodigo = new System.Windows.Forms.TextBox();
			this.label5 = new System.Windows.Forms.Label();
			this.txSenha = new System.Windows.Forms.TextBox();
			this.label4 = new System.Windows.Forms.Label();
			this.txStatus = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.txNome = new System.Windows.Forms.TextBox();
			this.btVoltar = new System.Windows.Forms.Button();
			this.btSalvar = new System.Windows.Forms.Button();
			this.label6 = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// label2
			// 
			this.label2.Font = new System.Drawing.Font("Times New Roman", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label2.Location = new System.Drawing.Point(125, 18);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(417, 73);
			this.label2.TabIndex = 5;
			this.label2.Text = "Verifica Clientes";
			this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// btVerifica
			// 
			this.btVerifica.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btVerifica.Location = new System.Drawing.Point(252, 351);
			this.btVerifica.Name = "btVerifica";
			this.btVerifica.Size = new System.Drawing.Size(216, 40);
			this.btVerifica.TabIndex = 19;
			this.btVerifica.Text = "Verificar";
			this.btVerifica.UseVisualStyleBackColor = true;
			this.btVerifica.Click += new System.EventHandler(this.BtVerificaClick);
			// 
			// label3
			// 
			this.label3.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label3.Location = new System.Drawing.Point(104, 166);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(100, 38);
			this.label3.TabIndex = 17;
			this.label3.Text = "Codigo:";
			// 
			// txCodigo
			// 
			this.txCodigo.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txCodigo.Location = new System.Drawing.Point(210, 166);
			this.txCodigo.MaxLength = 1;
			this.txCodigo.Name = "txCodigo";
			this.txCodigo.Size = new System.Drawing.Size(68, 38);
			this.txCodigo.TabIndex = 16;
			// 
			// label5
			// 
			this.label5.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label5.Location = new System.Drawing.Point(104, 298);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(89, 38);
			this.label5.TabIndex = 25;
			this.label5.Text = "Senha:";
			// 
			// txSenha
			// 
			this.txSenha.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txSenha.Location = new System.Drawing.Point(199, 298);
			this.txSenha.MaxLength = 4;
			this.txSenha.Name = "txSenha";
			this.txSenha.Size = new System.Drawing.Size(358, 38);
			this.txSenha.TabIndex = 24;
			// 
			// label4
			// 
			this.label4.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label4.Location = new System.Drawing.Point(104, 254);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(89, 38);
			this.label4.TabIndex = 23;
			this.label4.Text = "Status:";
			// 
			// txStatus
			// 
			this.txStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txStatus.Location = new System.Drawing.Point(199, 254);
			this.txStatus.MaxLength = 1;
			this.txStatus.Name = "txStatus";
			this.txStatus.Size = new System.Drawing.Size(358, 38);
			this.txStatus.TabIndex = 22;
			// 
			// label1
			// 
			this.label1.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label1.Location = new System.Drawing.Point(104, 210);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(89, 38);
			this.label1.TabIndex = 21;
			this.label1.Text = "Nome:";
			// 
			// txNome
			// 
			this.txNome.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txNome.Location = new System.Drawing.Point(199, 210);
			this.txNome.Name = "txNome";
			this.txNome.Size = new System.Drawing.Size(358, 38);
			this.txNome.TabIndex = 20;
			// 
			// btVoltar
			// 
			this.btVoltar.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btVoltar.Location = new System.Drawing.Point(236, 493);
			this.btVoltar.Name = "btVoltar";
			this.btVoltar.Size = new System.Drawing.Size(244, 53);
			this.btVoltar.TabIndex = 26;
			this.btVoltar.Text = "Voltar";
			this.btVoltar.UseVisualStyleBackColor = true;
			this.btVoltar.Click += new System.EventHandler(this.BtVoltarClick);
			// 
			// btSalvar
			// 
			this.btSalvar.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btSalvar.Location = new System.Drawing.Point(252, 397);
			this.btSalvar.Name = "btSalvar";
			this.btSalvar.Size = new System.Drawing.Size(216, 40);
			this.btSalvar.TabIndex = 27;
			this.btSalvar.Text = "Salvar";
			this.btSalvar.UseVisualStyleBackColor = true;
			this.btSalvar.Click += new System.EventHandler(this.BtSalvarClick);
			// 
			// label6
			// 
			this.label6.Font = new System.Drawing.Font("Times New Roman", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label6.Location = new System.Drawing.Point(140, 110);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(417, 73);
			this.label6.TabIndex = 28;
			this.label6.Text = "Digite o Codigo do cliente";
			this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// Verifica
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(697, 608);
			this.Controls.Add(this.btSalvar);
			this.Controls.Add(this.btVoltar);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.txSenha);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.txStatus);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.txNome);
			this.Controls.Add(this.btVerifica);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.txCodigo);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label6);
			this.Name = "Verifica";
			this.Text = "Verifica";
			this.ResumeLayout(false);
			this.PerformLayout();
		}
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.Button btSalvar;
		private System.Windows.Forms.Button btVoltar;
		private System.Windows.Forms.TextBox txNome;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox txStatus;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.TextBox txSenha;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.TextBox txCodigo;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Button btVerifica;
		private System.Windows.Forms.Label label2;
	}
}
