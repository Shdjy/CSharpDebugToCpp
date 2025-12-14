using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace C_App1
{
    public partial class Form1 : Form
    {
        [DllImport("CTestDll.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr CreateCalculate();

        [DllImport("CTestDll.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void DestroyCalculate(IntPtr calc);

        [DllImport("CTestDll.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int Calculate_Add(IntPtr calc, int a, int b);
        [DllImport("CTestDll.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void TriggerCrash();
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            IntPtr calc = CreateCalculate();
            int result = Calculate_Add(calc, 10, 20);
            MessageBox.Show("Result is " + result.ToString());
            DestroyCalculate(calc);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            TriggerCrash();

        }
    }
}
