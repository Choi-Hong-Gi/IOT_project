
namespace Calculator
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btn00 = new System.Windows.Forms.Button();
            this.btnBS = new System.Windows.Forms.Button();
            this.btnC = new System.Windows.Forms.Button();
            this.btnAC = new System.Windows.Forms.Button();
            this.btnDevide = new System.Windows.Forms.Button();
            this.btnMulti = new System.Windows.Forms.Button();
            this.btnMinus = new System.Windows.Forms.Button();
            this.btnPlus = new System.Windows.Forms.Button();
            this.btnEqu = new System.Windows.Forms.Button();
            this.btn0 = new System.Windows.Forms.Button();
            this.btnDot = new System.Windows.Forms.Button();
            this.btn3 = new System.Windows.Forms.Button();
            this.btn2 = new System.Windows.Forms.Button();
            this.btn1 = new System.Windows.Forms.Button();
            this.btn6 = new System.Windows.Forms.Button();
            this.btn5 = new System.Windows.Forms.Button();
            this.btn4 = new System.Windows.Forms.Button();
            this.btn9 = new System.Windows.Forms.Button();
            this.btn8 = new System.Windows.Forms.Button();
            this.btn7 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btn00);
            this.groupBox1.Controls.Add(this.btnBS);
            this.groupBox1.Controls.Add(this.btnC);
            this.groupBox1.Controls.Add(this.btnAC);
            this.groupBox1.Controls.Add(this.btnDevide);
            this.groupBox1.Controls.Add(this.btnMulti);
            this.groupBox1.Controls.Add(this.btnMinus);
            this.groupBox1.Controls.Add(this.btnPlus);
            this.groupBox1.Controls.Add(this.btnEqu);
            this.groupBox1.Controls.Add(this.btn0);
            this.groupBox1.Controls.Add(this.btnDot);
            this.groupBox1.Controls.Add(this.btn3);
            this.groupBox1.Controls.Add(this.btn2);
            this.groupBox1.Controls.Add(this.btn1);
            this.groupBox1.Controls.Add(this.btn6);
            this.groupBox1.Controls.Add(this.btn5);
            this.groupBox1.Controls.Add(this.btn4);
            this.groupBox1.Controls.Add(this.btn9);
            this.groupBox1.Controls.Add(this.btn8);
            this.groupBox1.Controls.Add(this.btn7);
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.Location = new System.Drawing.Point(10, 50);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(217, 243);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            // 
            // btn00
            // 
            this.btn00.Location = new System.Drawing.Point(7, 194);
            this.btn00.Name = "btn00";
            this.btn00.Size = new System.Drawing.Size(46, 39);
            this.btn00.TabIndex = 11;
            this.btn00.Text = "00";
            this.btn00.UseVisualStyleBackColor = true;
            this.btn00.Click += new System.EventHandler(this.btn00_Click);
            // 
            // btnBS
            // 
            this.btnBS.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.btnBS.Location = new System.Drawing.Point(111, 14);
            this.btnBS.Name = "btnBS";
            this.btnBS.Size = new System.Drawing.Size(46, 39);
            this.btnBS.TabIndex = 18;
            this.btnBS.Text = "BS";
            this.btnBS.UseVisualStyleBackColor = false;
            this.btnBS.Click += new System.EventHandler(this.btnBS_Click);
            // 
            // btnC
            // 
            this.btnC.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.btnC.Location = new System.Drawing.Point(59, 14);
            this.btnC.Name = "btnC";
            this.btnC.Size = new System.Drawing.Size(46, 39);
            this.btnC.TabIndex = 17;
            this.btnC.Text = "C";
            this.btnC.UseVisualStyleBackColor = false;
            this.btnC.Click += new System.EventHandler(this.btnC_Click);
            // 
            // btnAC
            // 
            this.btnAC.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.btnAC.Location = new System.Drawing.Point(7, 14);
            this.btnAC.Name = "btnAC";
            this.btnAC.Size = new System.Drawing.Size(46, 39);
            this.btnAC.TabIndex = 16;
            this.btnAC.Text = "AC";
            this.btnAC.UseVisualStyleBackColor = false;
            this.btnAC.Click += new System.EventHandler(this.btnAC_Click);
            // 
            // btnDevide
            // 
            this.btnDevide.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.btnDevide.Location = new System.Drawing.Point(163, 149);
            this.btnDevide.Name = "btnDevide";
            this.btnDevide.Size = new System.Drawing.Size(46, 39);
            this.btnDevide.TabIndex = 15;
            this.btnDevide.Text = "/";
            this.btnDevide.UseVisualStyleBackColor = false;
            this.btnDevide.Click += new System.EventHandler(this.btnDevide_Click);
            // 
            // btnMulti
            // 
            this.btnMulti.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.btnMulti.Location = new System.Drawing.Point(163, 104);
            this.btnMulti.Name = "btnMulti";
            this.btnMulti.Size = new System.Drawing.Size(46, 39);
            this.btnMulti.TabIndex = 14;
            this.btnMulti.Text = "*";
            this.btnMulti.UseVisualStyleBackColor = false;
            this.btnMulti.Click += new System.EventHandler(this.btnMulti_Click);
            // 
            // btnMinus
            // 
            this.btnMinus.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.btnMinus.Location = new System.Drawing.Point(163, 59);
            this.btnMinus.Name = "btnMinus";
            this.btnMinus.Size = new System.Drawing.Size(46, 39);
            this.btnMinus.TabIndex = 13;
            this.btnMinus.Text = "-";
            this.btnMinus.UseVisualStyleBackColor = false;
            this.btnMinus.Click += new System.EventHandler(this.btnMinus_Click);
            // 
            // btnPlus
            // 
            this.btnPlus.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.btnPlus.Location = new System.Drawing.Point(163, 14);
            this.btnPlus.Name = "btnPlus";
            this.btnPlus.Size = new System.Drawing.Size(46, 39);
            this.btnPlus.TabIndex = 12;
            this.btnPlus.Text = "+";
            this.btnPlus.UseVisualStyleBackColor = false;
            this.btnPlus.Click += new System.EventHandler(this.btnPlus_Click);
            // 
            // btnEqu
            // 
            this.btnEqu.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.btnEqu.Location = new System.Drawing.Point(163, 194);
            this.btnEqu.Name = "btnEqu";
            this.btnEqu.Size = new System.Drawing.Size(46, 39);
            this.btnEqu.TabIndex = 11;
            this.btnEqu.Text = "=";
            this.btnEqu.UseVisualStyleBackColor = false;
            this.btnEqu.Click += new System.EventHandler(this.btnEqu_Click);
            // 
            // btn0
            // 
            this.btn0.Location = new System.Drawing.Point(59, 194);
            this.btn0.Name = "btn0";
            this.btn0.Size = new System.Drawing.Size(46, 39);
            this.btn0.TabIndex = 10;
            this.btn0.Text = "0";
            this.btn0.UseVisualStyleBackColor = true;
            this.btn0.Click += new System.EventHandler(this.btn0_Click);
            // 
            // btnDot
            // 
            this.btnDot.Location = new System.Drawing.Point(111, 194);
            this.btnDot.Name = "btnDot";
            this.btnDot.Size = new System.Drawing.Size(46, 39);
            this.btnDot.TabIndex = 9;
            this.btnDot.Text = ".";
            this.btnDot.UseVisualStyleBackColor = true;
            this.btnDot.Click += new System.EventHandler(this.btnDot_Click);
            // 
            // btn3
            // 
            this.btn3.Location = new System.Drawing.Point(111, 149);
            this.btn3.Name = "btn3";
            this.btn3.Size = new System.Drawing.Size(46, 39);
            this.btn3.TabIndex = 8;
            this.btn3.Text = "3";
            this.btn3.UseVisualStyleBackColor = true;
            this.btn3.Click += new System.EventHandler(this.btn3_Click);
            // 
            // btn2
            // 
            this.btn2.Location = new System.Drawing.Point(59, 149);
            this.btn2.Name = "btn2";
            this.btn2.Size = new System.Drawing.Size(46, 39);
            this.btn2.TabIndex = 7;
            this.btn2.Text = "2";
            this.btn2.UseVisualStyleBackColor = true;
            this.btn2.Click += new System.EventHandler(this.btn2_Click);
            // 
            // btn1
            // 
            this.btn1.Location = new System.Drawing.Point(7, 149);
            this.btn1.Name = "btn1";
            this.btn1.Size = new System.Drawing.Size(46, 39);
            this.btn1.TabIndex = 6;
            this.btn1.Text = "1";
            this.btn1.UseVisualStyleBackColor = true;
            this.btn1.Click += new System.EventHandler(this.btn1_Click);
            // 
            // btn6
            // 
            this.btn6.Location = new System.Drawing.Point(111, 104);
            this.btn6.Name = "btn6";
            this.btn6.Size = new System.Drawing.Size(46, 39);
            this.btn6.TabIndex = 5;
            this.btn6.Text = "6";
            this.btn6.UseVisualStyleBackColor = true;
            this.btn6.Click += new System.EventHandler(this.btn6_Click);
            // 
            // btn5
            // 
            this.btn5.Location = new System.Drawing.Point(59, 104);
            this.btn5.Name = "btn5";
            this.btn5.Size = new System.Drawing.Size(46, 39);
            this.btn5.TabIndex = 4;
            this.btn5.Text = "5";
            this.btn5.UseVisualStyleBackColor = true;
            this.btn5.Click += new System.EventHandler(this.btn5_Click);
            // 
            // btn4
            // 
            this.btn4.Location = new System.Drawing.Point(7, 104);
            this.btn4.Name = "btn4";
            this.btn4.Size = new System.Drawing.Size(46, 39);
            this.btn4.TabIndex = 3;
            this.btn4.Text = "4";
            this.btn4.UseVisualStyleBackColor = true;
            this.btn4.Click += new System.EventHandler(this.btn4_Click);
            // 
            // btn9
            // 
            this.btn9.Location = new System.Drawing.Point(111, 59);
            this.btn9.Name = "btn9";
            this.btn9.Size = new System.Drawing.Size(46, 39);
            this.btn9.TabIndex = 2;
            this.btn9.Text = "9";
            this.btn9.UseVisualStyleBackColor = true;
            this.btn9.Click += new System.EventHandler(this.btn9_Click);
            // 
            // btn8
            // 
            this.btn8.Location = new System.Drawing.Point(59, 59);
            this.btn8.Name = "btn8";
            this.btn8.Size = new System.Drawing.Size(46, 39);
            this.btn8.TabIndex = 1;
            this.btn8.Text = "8";
            this.btn8.UseVisualStyleBackColor = true;
            this.btn8.Click += new System.EventHandler(this.btn8_Click);
            // 
            // btn7
            // 
            this.btn7.Location = new System.Drawing.Point(7, 59);
            this.btn7.Name = "btn7";
            this.btn7.Size = new System.Drawing.Size(46, 39);
            this.btn7.TabIndex = 0;
            this.btn7.Text = "7";
            this.btn7.UseVisualStyleBackColor = true;
            this.btn7.Click += new System.EventHandler(this.btn7_Click);
            // 
            // textBox1
            // 
            this.textBox1.Enabled = false;
            this.textBox1.Font = new System.Drawing.Font("굴림", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.textBox1.Location = new System.Drawing.Point(43, 12);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(184, 32);
            this.textBox1.TabIndex = 2;
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // textBox2
            // 
            this.textBox2.Enabled = false;
            this.textBox2.Font = new System.Drawing.Font("굴림", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.textBox2.Location = new System.Drawing.Point(12, 12);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(32, 32);
            this.textBox2.TabIndex = 4;
            this.textBox2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.ClientSize = new System.Drawing.Size(239, 302);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.textBox1);
            this.Name = "Form1";
            this.Text = "Calculator";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btn00;
        private System.Windows.Forms.Button btnBS;
        private System.Windows.Forms.Button btnC;
        private System.Windows.Forms.Button btnAC;
        private System.Windows.Forms.Button btnDevide;
        private System.Windows.Forms.Button btnMulti;
        private System.Windows.Forms.Button btnMinus;
        private System.Windows.Forms.Button btnPlus;
        private System.Windows.Forms.Button btnEqu;
        private System.Windows.Forms.Button btn0;
        private System.Windows.Forms.Button btnDot;
        private System.Windows.Forms.Button btn3;
        private System.Windows.Forms.Button btn2;
        private System.Windows.Forms.Button btn1;
        private System.Windows.Forms.Button btn6;
        private System.Windows.Forms.Button btn5;
        private System.Windows.Forms.Button btn4;
        private System.Windows.Forms.Button btn9;
        private System.Windows.Forms.Button btn8;
        private System.Windows.Forms.Button btn7;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
    }
}

