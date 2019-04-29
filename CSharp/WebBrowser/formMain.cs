using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WebBrowser
{
    public partial class FormMain : Form
    {
        private uint m_nCountWebBrowser;
        private Dictionary<uint, FormWebBrowser> m_listWebBrowser;

        public FormMain()
        {
            InitializeComponent();
            m_listWebBrowser = new Dictionary<uint, FormWebBrowser>();
        }

        ~FormMain()
        {
            m_listWebBrowser.Clear();
            m_listWebBrowser = null;
            m_nCountWebBrowser = 0;
        }

        public void OnLoadFormMain(object sender, EventArgs e)
        {
            SetFormMain();
            SetFormChild();
        }

        public void OnClickMenuFileNewOpen(object sender, EventArgs e)
        {
            SetFormChild();
        }

        public void OnClickMenuWindowCascade(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.Cascade);
        }

        public void OnClickMenuWindowTileHorizontal(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.TileHorizontal);
        }

        public void OnClickMenuWindowTileVertical(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.TileVertical);
        }

        public void OnClickMenuFileEnd(object sender, EventArgs e)
        {
            foreach (uint nKey in m_listWebBrowser.Keys)
            {
                FormWebBrowser form = m_listWebBrowser[nKey];
                form = null;
            }
            this.Close();
        }

        public void OnFormClosedFormMain(object sender, FormClosedEventArgs e)
        {
            m_listWebBrowser.Clear();
            m_listWebBrowser = null;
        }

        public void SetFormMain()
        {
            this.Size = new Size(1000, 600);
        }

        public void SetFormChild()
        {
            FormWebBrowser form = new FormWebBrowser();
            form.MdiParent = this;
            form.WindowState = FormWindowState.Minimized;
            form.Show();
            form.Name = m_nCountWebBrowser.ToString();
            form.WindowState = FormWindowState.Maximized;
            m_listWebBrowser.Add(uint.Parse(form.Name), form);
            m_nCountWebBrowser += 1;
        }

        public FormWebBrowser GetFormWebBrowser(uint nKey)
        {
            return m_listWebBrowser[nKey];
        }

        public void RemoveListWebBrowser(uint nKey)
        {
            m_listWebBrowser.Remove(nKey);
        }
    }
}