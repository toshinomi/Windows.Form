using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

/// <summary>
/// ファイルセーブのロジック
/// </summary>
class ComSaveFileDialog
{
    protected SaveFileDialog mSaveFileDialog;

    /// <summary>
    /// ファイル名称
    /// </summary>
    public string FileName
    {
        set { mSaveFileDialog.FileName = value; }
        get { return mSaveFileDialog.FileName; }
    }

    /// <summary>
    /// ファイルダイアログに表示される初期ディレクトリ
    /// </summary>
    public string InitialDirectory
    {
        set { mSaveFileDialog.InitialDirectory = value; }
        get { return mSaveFileDialog.InitialDirectory; }
    }

    /// <summary>
    /// ファイルの種類のフィルタ
    /// </summary>
    public string Filter
    {
        set { mSaveFileDialog.Filter = value; }
        get { return mSaveFileDialog.Filter; }
    }

    /// <summary>
    /// 現在選択中のフィルタのインデックス
    /// </summary>
    public int FilterIndex
    {
        set { mSaveFileDialog.FilterIndex = value; }
        get { return mSaveFileDialog.FilterIndex; }
    }

    /// <summary>
    /// ファイルダイアログに表示されるタイトル
    /// </summary>
    public string Title
    {
        set { mSaveFileDialog.Title = value; }
        get { return mSaveFileDialog.Title; }
    }

    /// <summary>
    /// 存在しないファイルを指定した場合に警告を表示するかどうかの値
    /// </summary>
    public bool CheckFileExists
    {
        set { mSaveFileDialog.CheckFileExists = value; }
        get { return mSaveFileDialog.CheckFileExists; }
    }

    /// <summary>
    /// 無効なパスとファイルを入力した場合に警告を表示するかどうかの値
    /// </summary>
    public bool CheckPathExists
    {
        set { mSaveFileDialog.CheckPathExists = value; }
        get { return mSaveFileDialog.CheckPathExists; }
    }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    public ComSaveFileDialog() : base()
    {
        mSaveFileDialog = new SaveFileDialog();
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~ComSaveFileDialog()
    {
    }

    /// <summary>
    /// ダイアログの表示
    /// </summary>
    /// <returns>結果 成功/失敗</returns>
    public bool ShowDialog()
    {
        bool result = false;

        if (mSaveFileDialog.ShowDialog() == DialogResult.OK)
        {
            result = true;
        }

        return result;
    }

    /// <summary>
    /// ストリームの書込み
    /// </summary>
    /// <param name="fileName">ファイル名称</param>
    /// <returns>実行結果 成功/失敗</returns>
    public bool StreamWrite(string fileName)
    {
        Stream stream;
        bool result = true;
        try
        {
            stream = mSaveFileDialog.OpenFile();
        }
        catch (Exception)
        {
            result = true;
            return result;
        }
        StreamWriter streamWriter = new StreamWriter(stream, Encoding.GetEncoding("UTF-8"));
        streamWriter.Write(fileName);
        streamWriter.Close();
        stream.Close();

        return result;
    }
}