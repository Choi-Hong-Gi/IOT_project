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

namespace WindowsFormsApp_arduino
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
            string rxd = ComPort.ReadTo("\n");
            this.BeginInvoke(new SetTextDelegate(SerialReceived), new object[] {rxd});
        }

        private void SerialReceived(string inString)
        {
            textBox1.AppendText(inString + "\r\n" );
        }

        private void Form1_Load(object sender, EventArgs e) // 폼 더블클릭
        {
            ComPort.PortName = "COM4";
            ComPort.BaudRate = 9600;
            ComPort.DataBits = 8;
            ComPort.Parity = Parity.None; //데이터 완결성 평가
            ComPort.StopBits = StopBits.One; // 한 비트 사용
            ComPort.Handshake = Handshake.None; // 미사용
            ComPort.Open();
            ComPort.DiscardInBuffer();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e) // 폼 클로징 이벤트
        {
            ComPort.Close(); // 닫기
            ComPort.Dispose(); // 삭제
            ComPort = null; // 널 값 초기화
        }
    }
}
