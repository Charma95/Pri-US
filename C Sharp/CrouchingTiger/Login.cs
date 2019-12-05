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
    public partial class Login : Form
    {
        MineTrace parent;
        const string username1 = "levc2315";
        const string username2 = "dufn2703";
        const string username3 = "lamf2309";
        const string username4 = "loro0801";
        const string username5 = "mily1001";
        const string username6 = "phas2401";
        const string username7 = "stpc3503";
        const string femme = "laplusbelle";
        const string password = "crouching123";

        public Login(MineTrace Parent)
        {
            InitializeComponent();
            parent = Parent;
        }
        public Login()
        {

        }

        private void Login_Load(object sender, EventArgs e)
        {
            
        }

        private void buttonEnter_Click(object sender, EventArgs e)
        {
            switch((string)textBox1.Text)
            {
                case username1: parent.Enabled = true;
                    break;
                case username2:
                    parent.Enabled = true;
                    break;
                case username3:
                    parent.Enabled = true;
                    break;
                case username4:
                    parent.Enabled = true;
                    break;
                case username5:
                    parent.Enabled = true;
                    break;
                case username6:
                    parent.Enabled = true;
                    break;
                case username7:
                    parent.Enabled = true;
                    break;
                case femme: parent.Enabled = true;
                    break;
                default: DialogResult dialog = MessageBox.Show("Wrong username. Please try again!", "Error username", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
                    break;

            }
            
                if(textBox2.Text == password)
                {
                    parent.Enabled = true;
                    this.Hide();
                }
                else
                {
                    DialogResult dialog =  MessageBox.Show("Wrong password. Please try again!", "Error password", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
                }
          
        }

        private void textBox2_TextChanged(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)Keys.Enter)
            {
                buttonEnter_Click(sender, e);
            }
            textBox2.PasswordChar = '*';

        }


    }
}
