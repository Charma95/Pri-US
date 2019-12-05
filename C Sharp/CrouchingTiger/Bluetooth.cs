using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.IO.Ports;
using System.Windows.Forms;

namespace CrouchingTiger
{
    class Bluetooth
    {
        SerialPort _sp = new SerialPort();
        
        public Bluetooth()
        {
            
        }
        //public void resetPort()
        //{

        //}
        public void BluetoothInit(string portName)
        {
           

            /* Setting port parameters */
            _sp.PortName = portName;
            _sp.BaudRate = 9600;
            _sp.Parity = 0;
            _sp.DataBits = 8;
            _sp.StopBits = StopBits.One;
            _sp.Handshake = Handshake.None;

            _sp.WriteTimeout = 4000;
            _sp.ReadTimeout = 5000;
            _sp.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

            if(_sp.IsOpen)
            {
                MessageBox.Show("This port is already used");
            }
            else
            {
                _sp.Open();
            }

        }
        public void closeBluetooth()
        {
            _sp.Close();
        }

        private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            MineTrace mine = new MineTrace();
            Indata = (string)_sp.ReadExisting();
            if (Indata != null)
            {
               // mine.MoveMine();
            }
        }

        public void BluetoothWrite(string text)
        {
            _sp.Write(text);
        }

        private string indata;

        public string Indata { get => indata; set => indata = value; }
    }
}
