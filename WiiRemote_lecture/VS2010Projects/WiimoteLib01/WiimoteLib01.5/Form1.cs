using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using WiimoteLib;

namespace WiimoteLib01._5
{
	public partial class Form1 : Form
	{
		Wiimote wm = new Wiimote();
		public Form1()
		{
			Control.CheckForIllegalCrossThreadCalls = false;
			InitializeComponent();
			wm.WiimoteChanged += wm_WiimoteChanged;
			wm.Connect();
		}
		private void wm_WiimoteChanged(object sender, WiimoteChangedEventArgs args) {
			WiimoteState ws = args.WiimoteState;
			this.DrawForms(ws);
			if (ws.ButtonState.A) { wm.SetRumble(true); }
			if (ws.ButtonState.B == true) { wm.SetRumble(false); }
		}
		public void DrawForms(WiimoteState ws) {
			this.label1.Text = "Rumble：" + (ws.Rumble);
		}
	}
}
