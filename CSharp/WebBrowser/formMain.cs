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
        private uint mCountWebBrowser;
        private Dictionary<uint, FormWebBrowser> mListWebBrowser;

        /// <summary>
        /// コンストラクタ
        /// </summary>
        public FormMain()
        {
            InitializeComponent();
            mListWebBrowser = new Dictionary<uint, FormWebBrowser>();
        }

        /// <summary>
        /// デスクトラクタ
        /// </summary>
        ~FormMain()
        {
            mListWebBrowser.Clear();
            mListWebBrowser = null;
            mCountWebBrowser = 0;
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
            foreach (uint key in mListWebBrowser.Keys)
            {
                FormWebBrowser form = mListWebBrowser[key];
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
            mListWebBrowser.Clear();
            mListWebBrowser = null;
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
            form.Name = mCountWebBrowser.ToString();
            form.WindowState = FormWindowState.Maximized;
            mListWebBrowser.Add(uint.Parse(form.Name), form);
            mCountWebBrowser += 1;
        }

        /// <summary>
        /// Webブラウザの情報の取得
        /// </summary>
        /// <param name="nKey">キー</param>
        /// <returns>Webブラウザ情報</returns>
        public FormWebBrowser GetFormWebBrowser(uint key)
        {
            return mListWebBrowser[key];
        }

        /// <summary>
        /// Webブラウザの情報の削除
        /// </summary>
        /// <param name="nKey">キー</param>
        public void RemoveListWebBrowser(uint key)
        {
            mListWebBrowser.Remove(key);
        }
    }
}