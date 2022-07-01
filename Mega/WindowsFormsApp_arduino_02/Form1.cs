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

namespace WindowsFormsApp_arduino_02
{
    public partial class Form1 : Form
    {
        SerialPort ComPort = new SerialPort();
        private delegate void SetTextDelegate(string getString);

        public Form1()
        {
            InitializeComponent();
            ComPort.DataReceived += new SerialDataReceivedEventHandler(DataReceived);
        }
        
        private void DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            try
            {
                string rxd = ComPort.ReadTo("\n");
                this.BeginInvoke(new SetTextDelegate(SerialReceived), new object[] { rxd });
            }
            catch (Exception ex){}
           
        }
        private void SerialReceived(string inString)
        {
            textBox1.AppendText(inString + "\r\n");
            string Head = inString.Substring(0, 1);
            string Data = inString.Substring(1);

            if (Head == "$")
            {
                string[] PasingData = Data.Split(',');
                lblData1.Text = PasingData[0];
                lblData2.Text = PasingData[1];
                StatusLabel1.Text = "";
            }
            else
            {
                StatusLabel1.Text = inString;
            }
        }
        
        private void Form1_Load(object sender, EventArgs e)
        {
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
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (ComPort.IsOpen)
            {
                ComPort.Close();
                ComPort.Dispose();
                ComPort = null;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (button1.Text == "Connect" )
            {
                ComPort.PortName = cmbComPort.Text;
                ComPort.BaudRate = Convert.ToInt32(cmbBoardRate.Text);
                ComPort.DataBits = 8;
                ComPort.Parity = Parity.None;
                ComPort.StopBits = StopBits.One;
                ComPort.Handshake = Handshake.None;
                ComPort.Open();
                ComPort.DiscardInBuffer();
                button1.Text = "Close";
            }
            else
            {
                ComPort.Close();
                button1.Text = "Connect";
                lblData1.Text = "00";
                lblData2.Text = "00";
                StatusLabel1.Text = "";
            }
        }
    }
}
