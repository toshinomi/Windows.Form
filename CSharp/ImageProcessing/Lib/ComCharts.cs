using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;

/// <summary>
/// チャートのロジック
/// </summary>
abstract class ComCharts
{
    protected int[,] mHistgram;
    protected Bitmap mBitmapOrg;
    protected Bitmap mBitmapAfter;

    /// <summary>
    /// コンストラクタ
    /// </summary>
    public ComCharts()
    {
        mHistgram = new int[(int)ComInfo.PictureType.MAX, ComInfo.RGB_MAX];
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~ComCharts()
    {
    }

    /// <summary>
    /// イメージからヒストグラム用のデータ算出
    /// </summary>
    public void CalHistgram()
    {
        int widthSize = mBitmapOrg.Width;
        int heightSize = mBitmapOrg.Height;

        BitmapData bitmapDataOrg = mBitmapOrg.LockBits(new Rectangle(0, 0, widthSize, heightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
        BitmapData bitmapDataAfter = null;
        if (mBitmapAfter != null)
        {
            bitmapDataAfter = mBitmapAfter.LockBits(new Rectangle(0, 0, widthSize, heightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
        }

        int indexWidth;
        int indexHeight;

        unsafe
        {
            for (indexHeight = 0; indexHeight < heightSize; indexHeight++)
            {
                for (indexWidth = 0; indexWidth < widthSize; indexWidth++)
                {
                    byte* pixel = (byte*)bitmapDataOrg.Scan0 + indexHeight * bitmapDataOrg.Stride + indexWidth * 4;
                    byte grayScale = (byte)((pixel[(int)ComInfo.Pixel.B] + pixel[(int)ComInfo.Pixel.G] + pixel[(int)ComInfo.Pixel.R]) / 3);

                    mHistgram[(int)ComInfo.PictureType.Original, grayScale] += 1;

                    if (mBitmapAfter != null)
                    {
                        pixel = (byte*)bitmapDataAfter.Scan0 + indexHeight * bitmapDataAfter.Stride + indexWidth * 4;
                        grayScale = (byte)((pixel[(int)ComInfo.Pixel.B] + pixel[(int)ComInfo.Pixel.G] + pixel[(int)ComInfo.Pixel.R]) / 3);

                        mHistgram[(int)ComInfo.PictureType.After, grayScale] += 1;
                    }
                }
            }
            mBitmapOrg.UnlockBits(bitmapDataOrg);
            if (mBitmapAfter != null)
            {
                mBitmapAfter.UnlockBits(bitmapDataAfter);
            }
        }
    }

    /// <summary>
    /// ヒストグラム用のデータ初期化
    /// </summary>
    public void InitHistgram()
    {
        for (int index = 0; index < (mHistgram.Length >> 1); index++)
        {
            mHistgram[(int)ComInfo.PictureType.Original, index] = 0;
            mHistgram[(int)ComInfo.PictureType.After, index] = 0;
        }
    }

    /// <summary>
    /// ヒストグラム用のデータCSV保存
    /// </summary>
    /// <returns>CSV保存の結果 成功/失敗</returns>
    public bool SaveCsv()
    {
        bool result = true;
        var saveDialog = new ComSaveFileDialog
        {
            Filter = "CSV|*.csv",
            Title = "Save the csv file",
            FileName = "default.csv"
        };
        if (saveDialog.ShowDialog() == true)
        {
            string delmiter = ",";
            StringBuilder stringBuilder = new StringBuilder();
            for (int index = 0; index < (mHistgram.Length >> 1); index++)
            {
                stringBuilder.Append(index).Append(delmiter);
                stringBuilder.Append(mHistgram[(int)ComInfo.PictureType.Original, index]).Append(delmiter);
                stringBuilder.Append(mHistgram[(int)ComInfo.PictureType.After, index]).Append(delmiter);
                stringBuilder.Append(Environment.NewLine);
            }
            if (!saveDialog.StreamWrite(stringBuilder.ToString()))
            {
                result = false;
            }
        }

        return result;
    }
}
