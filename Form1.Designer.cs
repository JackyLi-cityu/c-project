namespace group20
{
	partial class Form1
	{
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		/// <param name="disposing">如果應該處置受控資源則為 true，否則為 false。</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form 設計工具產生的程式碼

		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		private void InitializeComponent()
		{
			this.enterButton = new System.Windows.Forms.Button();
			this.textBox1 = new System.Windows.Forms.TextBox();
			this.textBox2 = new System.Windows.Forms.TextBox();
			this.UserButton = new System.Windows.Forms.Label();
			this.PasswordButton = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// enterButton
			// 
			this.enterButton.Location = new System.Drawing.Point(328, 285);
			this.enterButton.Name = "enterButton";
			this.enterButton.Size = new System.Drawing.Size(75, 23);
			this.enterButton.TabIndex = 0;
			this.enterButton.Text = "enter";
			this.enterButton.UseVisualStyleBackColor = true;
			this.enterButton.Click += new System.EventHandler(this.Button1_Click);
			// 
			// textBox1
			// 
			this.textBox1.Location = new System.Drawing.Point(319, 110);
			this.textBox1.Name = "textBox1";
			this.textBox1.Size = new System.Drawing.Size(100, 22);
			this.textBox1.TabIndex = 1;
			this.textBox1.TextChanged += new System.EventHandler(this.TextBox1_TextChanged);
			// 
			// textBox2
			// 
			this.textBox2.Location = new System.Drawing.Point(319, 183);
			this.textBox2.Name = "textBox2";
			this.textBox2.Size = new System.Drawing.Size(100, 22);
			this.textBox2.TabIndex = 2;
			// 
			// UserButton
			// 
			this.UserButton.AutoSize = true;
			this.UserButton.Font = new System.Drawing.Font("新細明體", 12F);
			this.UserButton.Location = new System.Drawing.Point(220, 113);
			this.UserButton.Name = "UserButton";
			this.UserButton.Size = new System.Drawing.Size(57, 16);
			this.UserButton.TabIndex = 3;
			this.UserButton.Text = "User ID";
			// 
			// PasswordButton
			// 
			this.PasswordButton.AutoSize = true;
			this.PasswordButton.Font = new System.Drawing.Font("新細明體", 12F);
			this.PasswordButton.Location = new System.Drawing.Point(220, 186);
			this.PasswordButton.Name = "PasswordButton";
			this.PasswordButton.Size = new System.Drawing.Size(67, 16);
			this.PasswordButton.TabIndex = 4;
			this.PasswordButton.Text = "Password";
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(800, 450);
			this.Controls.Add(this.PasswordButton);
			this.Controls.Add(this.UserButton);
			this.Controls.Add(this.textBox2);
			this.Controls.Add(this.textBox1);
			this.Controls.Add(this.enterButton);
			this.Name = "Form1";
			this.Text = "Form1";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Button enterButton;
		private System.Windows.Forms.TextBox textBox1;
		private System.Windows.Forms.TextBox textBox2;
		private System.Windows.Forms.Label UserButton;
		private System.Windows.Forms.Label PasswordButton;
	}
}

