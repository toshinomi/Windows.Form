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
    /// MainFormのロジック
    /// </summary>
    public partial class FormMain : Form
    {
        private uint m_nCountWebBrowser;
        private Dictionary<uint, FormWebBrowser> m_listWebBrowser;

        /// <summary>
        /// コンストラクタ
        /// </summary>
        public FormMain()
        {
            InitializeComponent();
            m_listWebBrowser = new Dictionary<uint, FormWebBrowser>();
        }

        /// <summary>
        /// デスクトラクタ
        /// </summary>
        ~FormMain()
        {
            m_listWebBrowser.Clear();
            m_listWebBrowser = null;
            m_nCountWebBrowser = 0;
        }

        /// <summary>
        /// FormMainのロードイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        public void OnLoadFormMain(object sender, EventArgs e)
        {
            SetFormMain();
            SetFormChild();
        }

        /// <summary>
        /// メニューの新規ウィンドウを開くのクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        public void OnClickMenuFileNewOpen(object sender, EventArgs e)
        {
            SetFormChild();
        }

        /// <summary>
        /// メニューの重ねて表示のクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        public void OnClickMenuWindowCascade(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.Cascade);
        }

        /// <summary>
        /// メニューの上下に並べて表示のクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        public void OnClickMenuWindowTileHorizontal(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.TileHorizontal);
        }

        /// <summary>
        /// メニューの左右に並べて表示のクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        public void OnClickMenuWindowTileVertical(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.TileVertical);
        }

        /// <summary>
        /// メニューの終了のクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        public void OnClickMenuFileEnd(object sender, EventArgs e)
        {
            foreach (uint nKey in m_listWebBrowser.Keys)
            {
                FormWebBrowser form = m_listWebBrowser[nKey];
                form = null;
            }
            this.Close();
        }

        /// <summary>
        /// Formのクローズイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">FormClosedイベントのデータ</param>
        public void OnFormClosedFormMain(object sender, FormClosedEventArgs e)
        {
            m_listWebBrowser.Clear();
            m_listWebBrowser = null;
        }

        /// <summary>
        /// FormMainの設定
        /// </summary>
        public void SetFormMain()
        {
            this.Size = new Size(1000, 600);
        }

        /// <summary>
        /// FormMainの子ウィンドウの設定
        /// </summary>
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

        /// <summary>
        /// Webブラウザの情報の取得
        /// </summary>
        /// <param name="nKey">キー</param>
        /// <returns>Webブラウザ情報</returns>
        public FormWebBrowser GetFormWebBrowser(uint nKey)
        {
            return m_listWebBrowser[nKey];
        }

        /// <summary>
        /// Webブラウザの情報の削除
        /// </summary>
        /// <param name="nKey">キー</param>
        public void RemoveListWebBrowser(uint nKey)
        {
            m_listWebBrowser.Remove(nKey);
        }
    }
}