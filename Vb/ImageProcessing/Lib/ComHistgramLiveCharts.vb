Imports LiveCharts
Imports LiveCharts.Wpf

''' <summary>
''' ライブチャートのヒストグラム表示のロジック
''' </summary>
Public Class ComHistgramLiveCharts : Inherits ComCharts
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
    Public Function DrawHistgram() As List(Of LineSeries)
        MyBase.InitHistgram()

        MyBase.CalHistgram()

        Dim lineSeriesChartOriginal = New LineSeries() With
        {
            .Values = New ChartValues(Of Integer),
            .Title = "Original Image"
        }

        Dim lineSeriesChartAfter = New LineSeries() With
        {
            .Values = New ChartValues(Of Integer),
            .Title = "After Image"
        }

        For index As Integer = 0 To (MyBase.mHistgram.Length >> 1) - 1 Step 1
            lineSeriesChartOriginal.Values.Add(mHistgram(ComInfo.PictureType.Original, index))
            lineSeriesChartAfter.Values.Add(mHistgram(ComInfo.PictureType.After, index))
        Next

        Dim items = New List(Of LineSeries)
        items.Add(lineSeriesChartOriginal)
        items.Add(lineSeriesChartAfter)

        Return items

    End Function
End Class