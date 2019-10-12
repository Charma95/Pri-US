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

        Errors InitBluetooth(SerialPort port)
        {
            Errors errorBt = Errors.NONE;

            _sp.PortName = "COM6";   /* This is the port that I set in the bluetooth settings */
            _sp.BaudRate = 115200;
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
            string indata = _sp.ReadExisting();

            throw new NotImplementedException();
        }

        Errors readBluetooth()
        {

            return Errors.NONE;
        }

        Errors writeBluetooth(string message, int length)
        {
            Errors errors = Errors.NONE;
            

            return errors;
        }
    }
}
