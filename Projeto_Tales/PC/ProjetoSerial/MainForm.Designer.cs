/*
 * Criado por SharpDevelop.
 * Usuário: tales
 * Data: 23/03/2021
 * Hora: 11:22
 * 
 * Para alterar este modelo use Ferramentas | Opções | Codificação | Editar Cabeçalhos Padrão.
 */
namespace ProjetoSerial
{
	partial class MainForm
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
			this.label1 = new System.Windows.Forms.Label();
			this.btCadastro = new System.Windows.Forms.Button();
			this.label2 = new System.Windows.Forms.Label();
			this.btExcluir = new System.Windows.Forms.Button();
			this.btVerifica = new System.Windows.Forms.Button();
			this.btAtualiza = new System.Windows.Forms.Button();
			this.btMonitora = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// label1
			// 
			this.label1.Font = new System.Drawing.Font("Times New Roman", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label1.Location = new System.Drawing.Point(127, 9);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(417, 62);
			this.label1.TabIndex = 0;
			this.label1.Text = "Controle Catraca";
			this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// btCadastro
			// 
			this.btCadastro.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btCadastro.Location = new System.Drawing.Point(215, 163);
			this.btCadastro.Name = "btCadastro";
			this.btCadastro.Size = new System.Drawing.Size(244, 68);
			this.btCadastro.TabIndex = 1;
			this.btCadastro.Text = "Cadastro";
			this.btCadastro.UseVisualStyleBackColor = true;
			this.btCadastro.Click += new System.EventHandler(this.BtCadastroClick);
			// 
			// label2
			// 
			this.label2.Font = new System.Drawing.Font("Times New Roman", 27.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label2.Location = new System.Drawing.Point(138, 71);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(417, 62);
			this.label2.TabIndex = 2;
			this.label2.Text = "Gerenciamento de Clientes";
			this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// btExcluir
			// 
			this.btExcluir.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btExcluir.Location = new System.Drawing.Point(215, 237);
			this.btExcluir.Name = "btExcluir";
			this.btExcluir.Size = new System.Drawing.Size(244, 68);
			this.btExcluir.TabIndex = 3;
			this.btExcluir.Text = "Excluir";
			this.btExcluir.UseVisualStyleBackColor = true;
			this.btExcluir.Click += new System.EventHandler(this.BtExcluirClick);
			// 
			// btVerifica
			// 
			this.btVerifica.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btVerifica.Location = new System.Drawing.Point(215, 311);
			this.btVerifica.Name = "btVerifica";
			this.btVerifica.Size = new System.Drawing.Size(244, 68);
			this.btVerifica.TabIndex = 4;
			this.btVerifica.Text = "Verificar";
			this.btVerifica.UseVisualStyleBackColor = true;
			this.btVerifica.Click += new System.EventHandler(this.BtVerificaClick);
			// 
			// btAtualiza
			// 
			this.btAtualiza.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btAtualiza.Location = new System.Drawing.Point(215, 500);
			this.btAtualiza.Name = "btAtualiza";
			this.btAtualiza.Size = new System.Drawing.Size(244, 86);
			this.btAtualiza.TabIndex = 5;
			this.btAtualiza.Text = "Atualizar Memoria";
			this.btAtualiza.UseVisualStyleBackColor = true;
			this.btAtualiza.Click += new System.EventHandler(this.BtAtualizaClick);
			// 
			// btMonitora
			// 
			this.btMonitora.Font = new System.Drawing.Font("Times New Roman", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btMonitora.Location = new System.Drawing.Point(215, 385);
			this.btMonitora.Name = "btMonitora";
			this.btMonitora.Size = new System.Drawing.Size(244, 68);
			this.btMonitora.TabIndex = 6;
			this.btMonitora.Text = "Monitora";
			this.btMonitora.UseVisualStyleBackColor = true;
			this.btMonitora.Click += new System.EventHandler(this.BtMonitoraClick);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(684, 611);
			this.Controls.Add(this.btMonitora);
			this.Controls.Add(this.btAtualiza);
			this.Controls.Add(this.btVerifica);
			this.Controls.Add(this.btExcluir);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.btCadastro);
			this.Controls.Add(this.label1);
			this.Name = "MainForm";
			this.Text = "ProjetoSerial";
			this.ResumeLayout(false);
		}
		private System.Windows.Forms.Button btMonitora;
		private System.Windows.Forms.Button btAtualiza;
		private System.Windows.Forms.Button btVerifica;
		private System.Windows.Forms.Button btExcluir;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Button btCadastro;
		private System.Windows.Forms.Label label1;
		
		void BtMonitoraClick(object sender, System.EventArgs e)
		{
			Monitora monitora = new Monitora();
			monitora.Show();
		}
	}
}
