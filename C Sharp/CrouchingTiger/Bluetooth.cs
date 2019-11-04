using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;

namespace CrouchingTiger
{
    class Bluetooth
    {
        SerialPort _sp = new SerialPort();

        public enum Errors
        {
            NONE,
            INIT_ERROR,
            BUFFER_OVERFLOW,
            SEND_ERROR,
            READ_ERROR
        }

        public Errors InitBluetooth()
        {
            

            Errors errorBt = Errors.NONE;

            _sp.PortName = "COM10";   /* This is the port that I set in the bluetooth settings */
            _sp.BaudRate = 38400;
            _sp.Parity = Parity.None;
            _sp.StopBits = StopBits.One;
            _sp.DataBits = 8;
            _sp.Handshake = Handshake.None;
            _sp.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

            _sp.ReadTimeout = 1000;
            _sp.WriteTimeout = 1000;

            _sp.Open();

            if (_sp.IsOpen != true)
            {
                errorBt = Errors.INIT_ERROR;
            }
            return errorBt;
        }

        private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            indata += _sp.ReadExisting();
            
        }

        public Errors readBluetooth()
        {
            MineTrace _mine = new MineTrace();
            _mine.rtbOutput.Text += indata;
            return Errors.NONE;
        }

        Errors writeBluetooth(string message, int length)
        {
            Errors errors = Errors.NONE;
            

            return errors;
        }

        private string indata;
        
    }
}
