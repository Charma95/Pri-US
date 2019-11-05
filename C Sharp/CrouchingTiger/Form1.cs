using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CrouchingTiger
{
    public partial class MineTrace : Form
    {
        public Bitmap drawArea;
        Bluetooth _bluetooth = new Bluetooth();
        Draw drawer;
        
        public MineTrace()
        {
            InitializeComponent();
           
        }

        private void MineTrace_Load(object sender, EventArgs e)
        {
            timer1.Start();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            
            _bluetooth.InitBluetooth();
            
        }

        private void Timer1_Tick(object sender, EventArgs e)
        {
            _bluetooth.readBluetooth();
        }
    }
}
