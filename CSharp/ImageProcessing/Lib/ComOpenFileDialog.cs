using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

/// <summary>
/// ファイルオープンのロジック
/// </summary>
public class ComOpenFileDialog
{
    protected OpenFileDialog mOpenFileDialog;

    /// <summary>
    /// ファイル名称
    /// </summary>
    public string FileName
    {
        set { mOpenFileDialog.FileName = value; }
        get { return mOpenFileDialog.FileName; }
    }

    /// <summary>
    /// ファイルダイアログに表示される初期ディレクトリ
    /// </summary>
    public string InitialDirectory
    {
        set { mOpenFileDialog.InitialDirectory = value; }
        get { return mOpenFileDialog.InitialDirectory; }
    }

    /// <summary>
    /// ファイルの種類のフィルタ
    /// </summary>
    public string Filter
    {
        set { mOpenFileDialog.Filter = value; }
        get { return mOpenFileDialog.Filter; }
    }

    /// <summary>
    /// 現在選択中のフィルタのインデックス
    /// </summary>
    public int FilterIndex
    {
        set { mOpenFileDialog.FilterIndex = value; }
        get { return mOpenFileDialog.FilterIndex; }
    }

    /// <summary>
    /// ファイルダイアログに表示されるタイトル
    /// </summary>
    public string Title
    {
        set { mOpenFileDialog.Title = value; }
        get { return mOpenFileDialog.Title; }
    }

    /// <summary>
    /// 存在しないファイルを指定した場合に警告を表示するかどうかの値
    /// </summary>
    public bool CheckFileExists
    {
        set { mOpenFileDialog.CheckFileExists = value; }
        get { return mOpenFileDialog.CheckFileExists; }
    }

    /// <summary>
    /// 無効なパスとファイルを入力した場合に警告を表示するかどうかの値
    /// </summary>
    public bool CheckPathExists
    {
        set { mOpenFileDialog.CheckPathExists = value; }
        get { return mOpenFileDialog.CheckPathExists; }
    }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    public ComOpenFileDialog()
    {
        mOpenFileDialog = new OpenFileDialog();
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~ComOpenFileDialog()
    {
    }

    /// <summary>
    /// ダイアログの表示
    /// </summary>
    /// <returns>結果 成功/失敗</returns>
    public bool ShowDialog()
    {
        bool result = false;

        if (mOpenFileDialog.ShowDialog() == DialogResult.OK)
        {
            result = true;
        }

        return result;
    }
}