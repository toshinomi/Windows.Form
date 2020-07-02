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
    /// <summary>
    /// FormWebBrowserのロジック
    /// </summary>
    public partial class FormWebBrowser : Form
    {
        private const string HOME_URL = "https://www.bing.com/";
        private string mUrl;
        private ToolTip mToolTip;

        /// <summary>
        /// コンストラクタ
        /// </summary>
        public FormWebBrowser()
        {
            InitializeComponent();
            mUrl = "";
        }

        /// <summary>
        /// デスクトラクタ
        /// </summary>
        ~FormWebBrowser()
        {
            mToolTip = null;
        }

        /// <summary>
        /// Formのクローズイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">FormClosedイベントのデータ</param>
        public void OnFormClosedFormWebBrowser(object sender, FormClosedEventArgs e)
        {
            FormMain formMain = (FormMain)this.MdiParent;
            FormWebBrowser form = formMain.GetFormWebBrowser(uint.Parse(this.Name));
            form = null;
            formMain.RemoveListWebBrowser(uint.Parse(this.Name));
        }

        /// <summary>
        /// FormWebBrowserのロードイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        public void OnLoadFormWebBrowser(object sender, EventArgs e)
        {
            SetInitToolTip();
            HomeWebBrowser();
        }

        /// <summary>
        /// 前のページに戻すクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        public void OnClickBack(object sender, EventArgs e)
        {
            if (webBrowser.CanGoBack == true)
            {
                webBrowser.GoBack();
            }
        }

        /// <summary>
        /// 次のページに移動クリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        public void OnClickForward(object sender, EventArgs e)
        {
            if (webBrowser.CanGoForward == true)
            {
                webBrowser.GoForward();
            }
        }

        /// <summary>
        /// 更新のクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        public void OnClickRefresh(object sender, EventArgs e)
        {
            webBrowser.Refresh();
        }

        /// <summary>
        /// URL入力のテキストボックスのキーダウンイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">キーイベントのデータ</param>
        public void OnKeyDownTextUrl(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                mUrl = textUrl.Text;
                webBrowser.Navigate(mUrl);
            }
        }

        /// <summary>
        /// WebBrowserのNavigatedイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">WebBrowserNavigatedイベントのデータ</param>
        public void OnNavigatedWebBrowser(object sender, WebBrowserNavigatedEventArgs e)
        {
            textUrl.Text = webBrowser.Url.AbsoluteUri;
            this.Text = webBrowser.Url.AbsoluteUri;
        }

        /// <summary>
        /// ツールチップの設定
        /// </summary>
        public void SetInitToolTip()
        {
            mToolTip = new ToolTip();
            mToolTip.SetToolTip(textUrl, "URL入力後、Enterキーを押してください!!!");
        }

        /// <summary>
        /// ホームの処理
        /// </summary>
        public void HomeWebBrowser()
        {
            Uri uri = new Uri(HOME_URL);
            webBrowser.Navigate(uri);
            textUrl.Text = mUrl;
            this.Text = mUrl;
        }
    }
}