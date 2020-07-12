Imports OxyPlot
Imports OxyPlot.Series

''' <summary>
''' OXYプロットのヒストグラム表示のロジック
''' </summary>
Public Class ComHistgramOxyPlot : Inherits ComCharts
    ''' <summary>
    ''' プロットモデル
    ''' </summary>
    Public Property PModel() As PlotModel

    ''' <summary>
    ''' ヒストグラム用の2次元配列データ　配列の1次元：オリジナルのデータ、配列の2次元：画像処理後のデータ
    ''' </summary>
    Public ReadOnly Property Histgram() As Integer(,)
        Get
            Return MyBase.mHistgram
        End Get
    End Property

    ''' <summary>
    ''' オリジナルのビットマップ
    ''' </summary>
    Public Property BitmapOrg() As Bitmap
        Set(value As Bitmap)
            MyBase.mBitmapOrg = value
        End Set
        Get
            Return MyBase.mBitmapOrg
        End Get
    End Property

    ''' <summary>
    ''' 画像処理後のビットマップ
    ''' </summary>
    Public Property BitmapAfter() As Bitmap
        Set(value As Bitmap)
            MyBase.mBitmapAfter = value
        End Set
        Get
            Return MyBase.mBitmapAfter
        End Get
    End Property

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()
        PModel = New PlotModel()
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
        MyBase.Finalize()
    End Sub

    ''' <summary>
    ''' ヒストグラムの描画データ処理
    ''' </summary>
    ''' <returns>ヒストグラムのデータ</returns>
    Public Function DrawHistgram() As PlotModel
        MyBase.InitHistgram()

        MyBase.CalHistgram()

        Dim dataListOriginal = New List(Of DataPoint)

        For index As Integer = 0 To (MyBase.mHistgram.Length >> 1) - 1 Step 1
            Dim DataPoint = New DataPoint(index, MyBase.mHistgram(ComInfo.PictureType.Original, index))
            dataListOriginal.Add(DataPoint)
        Next

        Dim seriesOriginal = New LineSeries() With
        {
            .Title = "Original",
            .ItemsSource = dataListOriginal
        }
        PModel.Series.Add(seriesOriginal)

        Dim dataListAfter = New List(Of DataPoint)

        For index As Integer = 0 To (MyBase.mHistgram.Length >> 1) - 1 Step 1
            Dim DataPoint = New DataPoint(index, MyBase.mHistgram(ComInfo.PictureType.After, index))
            dataListAfter.Add(DataPoint)
        Next

        Dim seriesAfter = New LineSeries() With
        {
            .Title = "After",
            .ItemsSource = dataListAfter
        }
        PModel.Series.Add(seriesAfter)

        Return PModel
    End Function
End Class