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
    public partial class FormWebBrowser : Form
    {
        private const string HOME_URL = "https://www.bing.com/";
        private string m_strUrl;
        private ToolTip m_toolTip;

        public FormWebBrowser()
        {
            InitializeComponent();
            m_strUrl = "";
        }

        ~FormWebBrowser()
        {
            m_toolTip = null;
        }

        public void OnFormClosedFormWebBrowser(object sender, FormClosedEventArgs e)
        {
            FormMain formMain = (FormMain)this.MdiParent;
            FormWebBrowser form = formMain.GetFormWebBrowser(uint.Parse(this.Name));
            form = null;
            formMain.RemoveListWebBrowser(uint.Parse(this.Name));
        }

        public void OnLoadFormWebBrowser(object sender, EventArgs e)
        {
            SetInitToolTip();
            HomeWebBrowser();
        }

        public void OnClickBack(object sender, EventArgs e)
        {
            if (webBrowser.CanGoBack == true)
            {
                webBrowser.GoBack();
            }
        }

        public void OnClickForward(object sender, EventArgs e)
        {
            if (webBrowser.CanGoForward == true)
            {
                webBrowser.GoForward();
            }
        }

        public void OnClickRefresh(object sender, EventArgs e)
        {
            webBrowser.Refresh();
        }

        public void OnKeyDownTextUrl(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                m_strUrl = textUrl.Text;
                webBrowser.Navigate(m_strUrl);
            }
        }

        public void OnNavigatedWebBrowser(object sender, WebBrowserNavigatedEventArgs e)
        {
            textUrl.Text = webBrowser.Url.AbsoluteUri;
            this.Text = webBrowser.Url.AbsoluteUri;
        }

        public void SetInitToolTip()
        {
            m_toolTip = new ToolTip();
            m_toolTip.SetToolTip(textUrl, "URL入力後、Enterキーを押してください!!!");
        }

        public void HomeWebBrowser()
        {
            Uri uri = new Uri(HOME_URL);
            webBrowser.Navigate(uri);
            textUrl.Text = m_strUrl;
            this.Text = m_strUrl;
        }
    }
}