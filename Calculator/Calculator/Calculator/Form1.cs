using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    public partial class Form1 : Form
    {
        string strKeyin;
        double NumA, NumB;
        string Cmd;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            strKeyin = "";
            textBox1.Text = strKeyin;
            NumA = 0;
            NumB = 0;
            Cmd = "";
        }

        private void Math()
        {
            try
            {
                textBox2.Text = "=";

                double result;

                switch (Cmd)
                {
                    case "+":
                        result = NumA + NumB;
                        break;
                    case "-":
                        result = NumA - NumB;
                        break;
                    case "*":
                        result = NumA * NumB;
                        break;
                    case "/":
                        if (NumB == 0)
                            result = 0;
                        else
                            result = NumA / NumB;
                        break;
                    default:
                        result = 0;
                        break;
                }

                strKeyin = Convert.ToString(result);
                textBox1.Text = strKeyin;
                NumB = 0;
                NumA = result;
                Cmd = "";
            }
            catch
            {
                
            }
        }

        private void btn1_Click(object sender, EventArgs e)
        {
            try
            {
                if (strKeyin == "0")
                    strKeyin = "";
                if (NumA == 0)
                    textBox2.Text = "";
                strKeyin += "1";
                textBox1.Text = strKeyin;
            }
            catch
            {

            }
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            try
            {


                if (strKeyin == "0")
                    strKeyin = "";
                if (NumA == 0)
                    textBox2.Text = "";
                strKeyin += "2";
                textBox1.Text = strKeyin;
            }
            catch
            {

            }
        }

        private void btn3_Click(object sender, EventArgs e)
        {
            try
            {
                if (strKeyin == "0")
                    strKeyin = "";
                if (NumA == 0)
                    textBox2.Text = "";
                strKeyin += "3";
                textBox1.Text = strKeyin;
            }
            catch
            {

            }
        }

        private void btn4_Click(object sender, EventArgs e)
        {
            try
            {
                if (strKeyin == "0")
                    strKeyin = "";
                if (NumA == 0)
                    textBox2.Text = "";
                strKeyin += "4";
                textBox1.Text = strKeyin;
            }
            catch
            {

            }
        }

        private void btn5_Click(object sender, EventArgs e)
        {
            try
            {
                if (strKeyin == "0")
                    strKeyin = "";
                if (NumA == 0)
                    textBox2.Text = "";
                strKeyin += "5";
                textBox1.Text = strKeyin;
            }
            catch
            {

            }
        }

        private void btn6_Click(object sender, EventArgs e)
        {
            try
            {
                if (strKeyin == "0")
                    strKeyin = "";
                if (NumA == 0)
                    textBox2.Text = "";
                strKeyin += "6";
                textBox1.Text = strKeyin;
            }
            catch
            {

            }
        }

        private void btn7_Click(object sender, EventArgs e)
        {
            try
            {
                if (strKeyin == "0")
                    strKeyin = "";
                if (NumA == 0)
                    textBox2.Text = "";
                strKeyin += "7";
                textBox1.Text = strKeyin;
            }
            catch
            {

            }
        }

        private void btn8_Click(object sender, EventArgs e)
        {
            try
            {
                if (strKeyin == "0")
                    strKeyin = "";
                if (NumA == 0)
                    textBox2.Text = "";
                strKeyin += "8";
                textBox1.Text = strKeyin;
            }
            catch
            {

            }
        }

        private void btn9_Click(object sender, EventArgs e)
        {
            try
            {
                if (strKeyin == "0")
                    strKeyin = "";
                if (NumA == 0)
                    textBox2.Text = "";
                strKeyin += "9";
                textBox1.Text = strKeyin;
            }
            catch
            {

            }
        }

        private void btnPlus_Click(object sender, EventArgs e)
        {
            try
            {
                if (strKeyin != "" && strKeyin != "-")
                    NumA = Convert.ToDouble(strKeyin);
                NumB = 0;
                Cmd = "+";
                strKeyin = "";

                textBox2.Text = "+";
            }
            catch
            {

            }
        }

        private void btnMinus_Click(object sender, EventArgs e)
        {
            try
            {
                if (strKeyin != "" && strKeyin != "-")
                    NumA = Convert.ToDouble(strKeyin);
                NumB = 0;
                Cmd = "-";
                strKeyin = "";

                textBox2.Text = "-";
            }
            catch
            {

            }
        }

        private void btnMulti_Click(object sender, EventArgs e)
        {
            try
            {
                if (strKeyin != "" && strKeyin != "-")
                    NumA = Convert.ToDouble(strKeyin);
                NumB = 0;
                Cmd = "*";
                strKeyin = "";

                textBox2.Text = "*";
            }
            catch
            {

            }
        }

        private void btnDevide_Click(object sender, EventArgs e)
        {
            try
            {
                if (strKeyin != "" && strKeyin != "-")
                    NumA = Convert.ToDouble(strKeyin);
                NumB = 0;
                Cmd = "/";
                strKeyin = "";

                textBox2.Text = "/";
            }
            catch
            {

            }
        }

        private void btnEqu_Click(object sender, EventArgs e)
        {
            try
            {
                if (Cmd != "" && strKeyin != "")
                {
                    NumB = Convert.ToDouble(strKeyin);
                    Math();
                }
            }
            catch
            {

            }
        }

        private void btn00_Click(object sender, EventArgs e)
        {
            try
            {
                if (NumA == 0)
                    textBox2.Text = "";

                if (strKeyin == "")
                    strKeyin += "0";
                else if (strKeyin == "0")
                    strKeyin += "";
                else
                    strKeyin += "00";

                textBox1.Text = strKeyin;
            }
            catch
            {

            }
        }

        private void btn0_Click(object sender, EventArgs e)
        {
            try
            {
                if (NumA == 0)
                    textBox2.Text = "";

                if (strKeyin == "")
                    strKeyin += "0";
                else if (strKeyin == "0")
                    strKeyin += "";
                else
                    strKeyin += "0";
                textBox1.Text = strKeyin;
            }
            catch
            {

            }
        }

        private void btnDot_Click(object sender, EventArgs e)
        {
            try
            {
                if (strKeyin == "")
                    strKeyin += "0.";
                else if (strKeyin.Contains("."))
                    strKeyin += "";
                else
                    strKeyin += ".";
                textBox1.Text = strKeyin;
            }
            catch
            {

            }
        }

        private void btnAC_Click(object sender, EventArgs e)
        {
            try
            {
                strKeyin = "";
                textBox1.Text = strKeyin;
                textBox2.Text = strKeyin;
                NumA = 0;
                NumB = 0;
                Cmd = "";
            }
            catch
            {

            }
        }

        private void btnBS_Click(object sender, EventArgs e)
        {
            try
            {
                if (strKeyin.Length > 0)
                    strKeyin = strKeyin.Substring(0, strKeyin.Length - 1);
                if (NumA != 0)
                {
                    string numA = Convert.ToString(NumA);
                    numA = numA.Substring(0, numA.Length - 1);
                    if (numA.IndexOf(".") == numA.Length - 1)
                        numA = numA.Replace(".", "");
                    if (numA == "-")
                        numA = "0";
                    if (numA != "")
                        NumA = Convert.ToDouble(numA);
                }
                textBox1.Text = strKeyin;
            }
            catch
            {

            }
        }

        private void btnC_Click(object sender, EventArgs e)
        {
            try
            {
                strKeyin = "";
                textBox1.Text = strKeyin;
                textBox2.Text = strKeyin;
                NumA = 0;
                NumB = 0;
                Cmd = "";
            }
            catch
            {

            }
        }

    }
}
