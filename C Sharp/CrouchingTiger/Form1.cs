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



namespace CrouchingTiger
{
    public partial class MineTrace : Form
    {


        Login logger = new Login();
        Bluetooth bluetooth = new Bluetooth();
        string port;
        static int line = 0;
        Int16 count = 0;
        char column = ' ';
        static int index = 0;
        static string inputString;
        string outputstring;
        static string oldIndata;
        public MineTrace()
        {
            InitializeComponent();
            logger = new Login(this);
        }

        private void MineTrace_Load(object sender, EventArgs e)
        {
            WindowState = FormWindowState.Maximized;
            MineTrace.ActiveForm.Enabled = false;
            logger.TopMost = true;
            logger.Show();
            pBMine.Location = new Point(890, 532);
            pbGif.Visible = false;
        }

        private void Timer1_Tick(object sender, EventArgs e)
        {
            inputString = bluetooth.Indata;
            rtbTerminal.ForeColor = Color.LawnGreen;
            rtbTerminal.Text += inputString;
        }
    
        public void MoveMine()
        {
          
            try
            {
                switch (bluetooth.Indata[1])
                {
                    case '1':
                        line = 1;
                        break;
                    case '2':
                        line = 2;
                        break;
                    case '3':
                        line = 3;
                        break;
                    case '4':
                        line = 4;
                        break;
                    case '5':
                        line = 5;
                        break;
                    case '6':
                        line = 6;
                        break;
                    case '7':
                        line = 7;
                        break;
                    default: line = 1;
                        break;
                }
                
                column = bluetooth.Indata[0];
            }
            catch (Exception e)
            { }

            if (line <= 7)
            {

                switch (column)
                {
                    case 'A':
                        index = 1;
                        break;
                    case 'B':
                        index = 2;
                        break;
                    case 'C':
                        index = 3;
                        break;
                    case 'D':
                        index = 4;
                        break;
                    case 'E':
                        index = 5;
                        break;
                    case 'F':
                        index = 6;
                        break;
                    case 'G':
                        index = 7;
                        break;
                    default:
                        pBMine.Location = new Point(pBMine.Location.X, pBMine.Location.Y );
                        break;
                }
            }
            outputstring = column + line.ToString();
        }


        private void Button1_Click(object sender, EventArgs e)
        { 
            bluetooth.BluetoothInit(port);
            toolStripStatusLabel1.Text = " Connected to Pri-US...";
            timer1.Start();
            button1.Enabled = false;
            pbGif.Visible = true;
        }

        private void BtnStop_Click(object sender, EventArgs e)
        {
            
            toolStripStatusLabel1.Text = " Not connected to Pri-US...";
            bluetooth.closeBluetooth();
            button1.Enabled = true;
        }

        private void cbbPorts_Click(object sender, EventArgs e)
        {
            int i = 0;
            if (cbbPorts.Items.Count == 0)
            {
                string[] portList = SerialPort.GetPortNames();
                try
                {
                    foreach (string s in portList)
                    {
                        cbbPorts.Items.Add(portList[i]);
                        i++;
                    }
                }
                catch { };
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            rtbOutput.Text = "";
            
        }

        private void cbbPorts_SelectedIndexChanged(object sender, EventArgs e)
        {
            port = cbbPorts.Text;
        }

        private void btnRefresh_Click(object sender, EventArgs e)
        {
            MoveMine();
            pBMine.Location = new Point(890, 532);
            if(line == 0 || index == 0)
            {
                line = 1;
                index = 1;
            }
            pBMine.Location = new Point(pBMine.Location.X - ((index - 1) * 80), pBMine.Location.Y - ((line - 1) * 68));
            rtbOutput.Text += "La mine est dans la section " + outputstring + " " + DateTime.Now.ToString("yyyy/MM/dd HH:mm:ss\n");   
        }

        private void btnLog_Click(object sender, EventArgs e)
        {
            rtbOutput.Text += "\n\nCette séquence est enregistré par :" + logger.textBox1.Text;
                count = 1;
                string nomdeFichier = DateTime.Now.ToString("yyyy/MM/dd HH-mm");
                //string chemin = @"C:\Travail\Logs";

                SaveFileDialog saveFile = new SaveFileDialog();


                saveFile.DefaultExt = "*.log";
                saveFile.Filter = "Log Files |*.log";
                saveFile.FileName = nomdeFichier;



                if (saveFile.ShowDialog() == System.Windows.Forms.DialogResult.OK && saveFile.FileName.Length > 0)
                {
                    try
                    {
                        rtbOutput.SaveFile(saveFile.FileName, RichTextBoxStreamType.PlainText);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message);
                    }
                }

            
        }

        private void btnGo_Click(object sender, EventArgs e)
        {
            bluetooth.BluetoothWrite("1");
        }

        private void MineTrace_FormClosing(object sender, FormClosingEventArgs e)
        {
            if(rtbOutput.Text != string.Empty)
            {
                if (count == 1)
                {
                    this.Close();
                }
                else
                {
                    DialogResult dialog = MessageBox.Show("Are you sure you want to close without saving?", "Save current workprogress", MessageBoxButtons.YesNo, MessageBoxIcon.Hand);
                    if (dialog == DialogResult.Yes)
                    {
                        rtbOutput.Text = string.Empty;
                        this.Close();
                    }
                    else
                    {
                        btnLog_Click(sender, e);
                    }
                }
            }
        }
    }
}
