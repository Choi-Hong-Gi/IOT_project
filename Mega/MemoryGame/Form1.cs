using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace MemoryGame
{
    public partial class Form1 : Form
    {
        SerialPort ComPort = new SerialPort();
        private delegate void SetTextDelegate(string getString);

        int level = 1;
        static int cnt = 3;
        int speed = 700;
        int pushed = 0;
        string keyIn = "";
        int enter = 0;
        int[] boxSequence;
        int[] boxPush;


        public Form1()
        {
            InitializeComponent();
            ComPort.DataReceived += new SerialDataReceivedEventHandler(DataReceived);
        }
        private void DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            try
            {
                toolStripLabel1.Text = "Connected";
                string rxd = ComPort.ReadTo("\n");
                this.BeginInvoke(new SetTextDelegate(SerialReceived), new object[] { rxd });
            }
            catch { toolStripLabel1.Text = "Connection Failed"; }
        }

        private void SerialReceived(string inString)
        {
            try
            {
                string Head = inString.Substring(0, 1);
                string Data = inString.Substring(1, inString.Length - 1);
                if (Head == "@")
                {
                    string PasingData = Data;
                    keyIn = PasingData;

                    if (enter == 1)
                    {
                        getKeys(keyIn);
                        pressKeys(keyIn);
                    }
                    // Level up
                    if (pushed == cnt)
                    {
                        enter = 0;
                        LevelUp(cmp(boxSequence, boxPush));
                        button1.Enabled = true;
                        
                    }
                }
            }
            catch
            {
                //
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            label1.Visible = false;
            label2.Visible = false;
            label3.Visible = true;
            cmbComPort.Items.Clear();
            var portName = System.IO.Ports.SerialPort.GetPortNames();
            cmbComPort.Items.AddRange(portName);
            cmbComPort.SelectedIndex = cmbComPort.Items.Count - 1;
            cmbBoardRate.Items.Clear();
            cmbBoardRate.Items.Add("9600");
            cmbBoardRate.Items.Add("19200");
            cmbBoardRate.Items.Add("57600");
            cmbBoardRate.Items.Add("115200");
            cmbBoardRate.SelectedIndex = 0;
            toolStripLabel1.Text = "-/-";
        }

        private void LevelUp(bool cmp)
        {
            if (cmp)
            {
                level += 1;
                cnt += 1;
                speed -= 50;
                pushed = 0;
                if (speed < 100) speed = 100;

                label1.Visible = false;
                label2.Visible = false;
                label1.Text = "Level: " + level.ToString();
                label2.Text = "( " + pushed.ToString() + "/" + cnt.ToString() + " )";
                label3.Text = "Great job!";
                label3.Visible = true;

                Delay(2000);

                label1.Visible = true;
                label2.Visible = true;
                label3.Text = "Press the 'Start' button";
                label3.Visible = false;

            }
            else
            {
                level = 1;
                cnt = 3;
                pushed = 0;
                speed = 700;

                label1.Visible = false;
                label2.Visible = false;
                label1.Text = "Level: " + level.ToString();
                label2.Text = "( " + pushed.ToString() + "/" + cnt.ToString() + " )";
                label3.Text = "실패ㅠㅠ";
                label3.Visible = true;

                Delay(2000);

                label1.Visible = true;
                label2.Visible = true;
                label3.Text = "Press the 'Start' button";
                label3.Visible = false;
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (ComPort.IsOpen)
            {
                ComPort.Close();
            }
            ComPort.Dispose();
            ComPort = null;
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            if (btnConnect.Text == "Connect")
            {
                ComPort.PortName = cmbComPort.Text;
                ComPort.BaudRate = Convert.ToInt32(cmbBoardRate.Text);
                ComPort.DataBits = 8;
                ComPort.Parity = Parity.None;
                ComPort.StopBits = StopBits.One;
                ComPort.Handshake = Handshake.None;
                try
                {
                    ComPort.Open();
                }
                catch
                { 
                    toolStripLabel1.Text = "Connection Failed!"; 
                }
                ComPort.DiscardInBuffer();
                toolStripLabel1.Text = "--";
                btnConnect.Text = "Disconnect";
            }
            else
            {
                ComPort.Close();
                btnConnect.Text = "Connect";
                toolStripLabel1.Text = "-/-";
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (btnConnect.Text == "Disconnect")
            {
                boxSequence = new int[cnt];
                boxPush = new int[cnt];
                for(int i = 0; i < boxPush.Length;i++)
                {
                    boxPush[i] = 0;
                }

                label3.Visible = false;
                label1.Text = "Level: " + level.ToString();
                label1.Visible = true;
                label2.Text = "( " + pushed.ToString() + "/" + cnt.ToString() + " )";
                label2.Visible = true;
                button1.Enabled = false;
                StartGame(cnt, speed, boxSequence);

                enter = 1;
                
            }
            else
            {
                label3.Text = "Check Connection First";
                Delay(1000);
                label3.Text = "Press the 'Start' button";
            }
        }

        private bool cmp(int [] boxSequence, int [] boxPush)
        {
            int TorF = 0;

            for (int i = 0; i < boxSequence.Length; i++)
            {
                if (boxSequence[i] != boxPush[i] + 1)
                    TorF = 1;
            }
            if (TorF == 1)
                return false;
            else
                return true;
        }

        private void getKeys(string key)
        {
            boxPush[pushed] = Convert.ToInt16(key);
            pushed++;
            label2.Text = "( " + pushed.ToString() + "/" + cnt.ToString() + " )";
        }

        private void pressKeys(string key)
        {
            try
            {
                int keyInt = Convert.ToInt16(key);
                switch (keyInt)
                {
                    case 0:
                        btn1.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn1.BackColor = Color.White;
                        break;
                    case 1:
                        btn2.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn2.BackColor = Color.White;
                        break;
                    case 2:
                        btn3.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn3.BackColor = Color.White;
                        break;
                    case 3:
                        btn4.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn4.BackColor = Color.White;
                        break;
                    case 4:
                        btn5.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn5.BackColor = Color.White;
                        break;
                    case 5:
                        btn6.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn6.BackColor = Color.White;
                        break;
                    case 6:
                        btn7.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn7.BackColor = Color.White;
                        break;
                    case 7:
                        btn8.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn8.BackColor = Color.White;
                        break;
                    case 8:
                        btn9.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn9.BackColor = Color.White;
                        break;
                    case 9:
                        btn10.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn10.BackColor = Color.White;
                        break;
                    case 10:
                        btn11.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn11.BackColor = Color.White;
                        break;
                    case 11:
                        btn12.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn12.BackColor = Color.White;
                        break;
                    case 12:
                        btn13.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn13.BackColor = Color.White;
                        break;
                    case 13:
                        btn14.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn14.BackColor = Color.White;
                        break;
                    case 14:
                        btn15.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn15.BackColor = Color.White;
                        break;
                    case 15:
                        btn16.BackColor = Color.LawnGreen;
                        Delay(speed);
                        btn16.BackColor = Color.White;
                        break;

                    default: break;
                }
            }
            catch
            {
                //
            }
        }

        private void StartGame( int cnt, int speed, int[] boxSequence )
        {
            Random rnd = new Random();

            for (int i = 0; i < cnt; i++)
            {
                boxSequence[i] = rnd.Next(1, 17);
            }

            for (int i = 0; i < cnt; i++)
            {
                Delay(100);
                switch (boxSequence[i])
                {
                    case 1:
                        btn1.BackColor = Color.Tomato;
                        Delay(speed);
                        btn1.BackColor = Color.White;
                        break;
                    case 2:
                        btn2.BackColor = Color.Tomato;
                        Delay(speed);
                        btn2.BackColor = Color.White;
                        break;
                    case 3:
                        btn3.BackColor = Color.Tomato;
                        Delay(speed);
                        btn3.BackColor = Color.White;
                        break;
                    case 4:
                        btn4.BackColor = Color.Tomato;
                        Delay(speed);
                        btn4.BackColor = Color.White;
                        break;
                    case 5:
                        btn5.BackColor = Color.Tomato;
                        Delay(speed);
                        btn5.BackColor = Color.White;
                        break;
                    case 6:
                        btn6.BackColor = Color.Tomato;
                        Delay(speed);
                        btn6.BackColor = Color.White;
                        break;
                    case 7:
                        btn7.BackColor = Color.Tomato;
                        Delay(speed);
                        btn7.BackColor = Color.White;
                        break;
                    case 8:
                        btn8.BackColor = Color.Tomato;
                        Delay(speed);
                        btn8.BackColor = Color.White;
                        break;
                    case 9:
                        btn9.BackColor = Color.Tomato;
                        Delay(speed);
                        btn9.BackColor = Color.White;
                        break;
                    case 10:
                        btn10.BackColor = Color.Tomato;
                        Delay(speed);
                        btn10.BackColor = Color.White;
                        break;
                    case 11:
                        btn11.BackColor = Color.Tomato;
                        Delay(speed);
                        btn11.BackColor = Color.White;
                        break;
                    case 12:
                        btn12.BackColor = Color.Tomato;
                        Delay(speed);
                        btn12.BackColor = Color.White;
                        break;
                    case 13:
                        btn13.BackColor = Color.Tomato;
                        Delay(speed);
                        btn13.BackColor = Color.White;
                        break;
                    case 14:
                        btn14.BackColor = Color.Tomato;
                        Delay(speed);
                        btn14.BackColor = Color.White;
                        break;
                    case 15:
                        btn15.BackColor = Color.Tomato;
                        Delay(speed);
                        btn15.BackColor = Color.White;
                        break;
                    case 16:
                        btn16.BackColor = Color.Tomato;
                        Delay(speed);
                        btn16.BackColor = Color.White;
                        break;
                }
            }
        }

        public void Delay(int ms)
        {
            DateTime dateTimeNow = DateTime.Now;
            TimeSpan duration = new TimeSpan(0, 0, 0, 0, ms);
            DateTime dateTimeAdd = dateTimeNow.Add(duration);
            while (dateTimeAdd >= dateTimeNow)
            {
                System.Windows.Forms.Application.DoEvents();
                dateTimeNow = DateTime.Now;
            }
            return;
        }


    }
}
