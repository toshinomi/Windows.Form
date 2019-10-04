Imports LiveCharts
Imports LiveCharts.Wpf

Public Class ComHistgramLiveCharts : Inherits ComCharts
    Public ReadOnly Property Histgram() As Integer(,)
        Get
            Return MyBase.m_nHistgram
        End Get
    End Property

    Public Property BitmapOrg() As Bitmap
        Set(value As Bitmap)
            MyBase.m_bitmapOrg = value
        End Set
        Get
            Return MyBase.m_bitmapOrg
        End Get
    End Property

    Public Property BitmapAfter() As Bitmap
        Set(value As Bitmap)
            MyBase.m_bitmapAfter = value
        End Set
        Get
            Return MyBase.m_bitmapAfter
        End Get
    End Property

    Public Sub New()
    End Sub

    Protected Overrides Sub Finalize()
        MyBase.Finalize()
    End Sub

    Public Function DrawHistgram() As List(Of LineSeries)
        MyBase.InitHistgram()

        MyBase.CalHistgram()

        Dim lineSeriesChart1 = New LineSeries() With
        {
            .Values = New ChartValues(Of Integer),
            .Title = "Original Image"
        }

        Dim lineSeriesChart2 = New LineSeries() With
        {
            .Values = New ChartValues(Of Integer),
            .Title = "After Image"
        }

        For nIdx As Integer = 0 To (MyBase.m_nHistgram.Length >> 1) - 1 Step 1
            lineSeriesChart1.Values.Add(m_nHistgram(ComInfo.PictureType.Original, nIdx))
            lineSeriesChart2.Values.Add(m_nHistgram(ComInfo.PictureType.After, nIdx))
        Next

        Dim items = New List(Of LineSeries)
        items.Add(lineSeriesChart1)
        items.Add(lineSeriesChart2)

        Return items

    End Function
End Class
