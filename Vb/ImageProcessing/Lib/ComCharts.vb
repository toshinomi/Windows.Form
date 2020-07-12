Imports System.Drawing.Imaging
Imports System.Runtime.InteropServices.Marshal
Imports System.Text

''' <summary>
''' チャートのロジック
''' </summary>
Public MustInherit Class ComCharts
    Protected mHistgram(ComInfo.PictureType.MAX - 1, ComInfo.RGB_MAX - 1) As Integer
    Protected mBitmapOrg As Bitmap
    Protected mBitmapAfter As Bitmap

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
        MyBase.Finalize()
    End Sub

    ''' <summary>
    ''' イメージからヒストグラム用のデータ算出
    ''' </summary>
    Public Sub CalHistgram()
        Dim widthSize = mBitmapOrg.Width
        Dim heightSize = mBitmapOrg.Height

        Dim bitmapDataOrg = mBitmapOrg.LockBits(New Rectangle(0, 0, widthSize, heightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb)
        Dim bitmapDataAfter As BitmapData = Nothing
        If (mBitmapAfter IsNot Nothing) Then
            bitmapDataAfter = mBitmapAfter.LockBits(New Rectangle(0, 0, widthSize, heightSize), ImageLockMode.ReadOnly, PixelFormat.Format32bppArgb)
        End If

        Dim indexWidth As Integer
        Dim indexHeight As Integer

        For indexHeight = 0 To heightSize - 1 Step 1
            For indexWidth = 0 To widthSize - 1 Step 1
                Dim position = indexHeight * bitmapDataOrg.Stride + indexWidth * 4
                Dim pixelB = ReadByte(bitmapDataOrg.Scan0, position + ComInfo.Pixel.B)
                Dim pixelG = ReadByte(bitmapDataOrg.Scan0, position + ComInfo.Pixel.G)
                Dim pixelR = ReadByte(bitmapDataOrg.Scan0, position + ComInfo.Pixel.R)

                Dim grayScale As Integer = (pixelB + pixelG + pixelR) / 3

                mHistgram(ComInfo.PictureType.Original, grayScale) += 1

                If (mBitmapAfter IsNot Nothing) Then
                    position = indexHeight * bitmapDataAfter.Stride + indexWidth * 4

                    pixelB = ReadByte(bitmapDataAfter.Scan0, position + ComInfo.Pixel.B)
                    pixelG = ReadByte(bitmapDataAfter.Scan0, position + ComInfo.Pixel.G)
                    pixelR = ReadByte(bitmapDataAfter.Scan0, position + ComInfo.Pixel.R)

                    grayScale = (pixelB + pixelG + pixelR) / 3

                    mHistgram(ComInfo.PictureType.After, grayScale) += 1
                End If
            Next
        Next
    End Sub

    ''' <summary>
    ''' ヒストグラム用のデータ初期化
    ''' </summary>
    Public Sub InitHistgram()
        For index As Integer = 0 To (mHistgram.Length >> 1) - 1 Step 1
            mHistgram(ComInfo.PictureType.Original, index) = 0
            mHistgram(ComInfo.PictureType.After, index) = 0
        Next
    End Sub

    ''' <summary>
    ''' ヒストグラム用のデータCSV保存
    ''' </summary>
    ''' <returns>CSV保存の結果 成功/失敗</returns>
    Public Function SaveCsv() As Boolean
        Dim result = True
        Dim saveDialog = New ComSaveFileDialog()
        saveDialog.Filter = "CSV|*.csv"
        saveDialog.Title = "Save the csv file"
        saveDialog.FileName = "default.csv"
        If (saveDialog.ShowDialog() = True) Then
            Dim delmiter = ","
            Dim stringBuilder = New StringBuilder()
            For nIdx As Integer = 0 To (mHistgram.Length >> 1) - 1
                stringBuilder.Append(nIdx).Append(delmiter)
                stringBuilder.Append(mHistgram(0, nIdx)).Append(delmiter)
                stringBuilder.Append(mHistgram(1, nIdx)).Append(delmiter)
                stringBuilder.Append(Environment.NewLine)
            Next
            If (saveDialog.SreamWrite(stringBuilder.ToString()) = False) Then
                result = False
            End If
        End If

        Return result
    End Function
End Class
