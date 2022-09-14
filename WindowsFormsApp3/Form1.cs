using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DateTime dateFrom = monthCalendar1.SelectionStart.AddHours(1);
            DateTime dateTo = monthCalendar2.SelectionStart.AddHours(1);

            int ID = 24768;

            int sec = 1658195101;

            while (ID >= 24674)
            {
                //richTextBox1.Text += $"INSERT INTO LOG VALUES ({ID}, {sec}, 2138, 0, 2, 0);\n";
                richTextBox1.Text += $"UPDATE LOG SET TIMESTAMP = {sec} WHERE ID = {ID};\n";

                //dateFrom = dateFrom.AddDays(1);
                ID--;
                sec -= 86400;
            }
        }
    }
}
