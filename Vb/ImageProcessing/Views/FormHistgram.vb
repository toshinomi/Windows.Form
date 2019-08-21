Imports System.Windows.Media.Imaging
Imports ImageProcessing.ComInfo
Imports LiveCharts
Imports LiveCharts.Wpf
Imports System.Runtime.InteropServices.Marshal
Imports System.Drawing.Imaging

Public Class FormHistgram
    Protected m_nHistgram(ComInfo.PictureType.MAX - 1, ComInfo.RGB_MAX - 1) As Integer
    Private m_bitmapOrg As Bitmap
    Private m_bitmapAfter As Bitmap
    Private m_bIsOpen As Boolean

    Public Property BitmapOrg() As Bitmap
        Set(value As Bitmap)
            m_bitmapOrg = value
        End Set
        Get
            Return m_bitmapOrg
        End Get
    End Property

    Public Property BitmapAfter() As Bitmap
        Set(value As Bitmap)
            m_bitmapAfter = value
        End Set
        Get
            Return m_bitmapAfter
        End Get
    End Property

    Public Property IsOpen() As Boolean
        Set(value As Boolean)
            m_bIsOpen = value
        End Set
        Get
            Return m_bIsOpen
        End Get
    End Property

    Public Sub New()

        ' この呼び出しはデザイナーで必要です。
        InitializeComponent()

        ' InitializeComponent() 呼び出しの後で初期化を追加します。

    End Sub

    Public Sub DrawHistgram()
        Dim graphData = New GraphData()

        InitHistgram()

        CalHistgram()

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

        For nIdx As Integer = 0 To (m_nHistgram.Length >> 1) - 1 Step 1
            lineSeriesChart1.Values.Add(m_nHistgram(ComInfo.PictureType.Original, nIdx))
            lineSeriesChart2.Values.Add(m_nHistgram(ComInfo.PictureType.After, nIdx))
        Next
        chart.Series.Clear()
        chart.Series.Add(lineSeriesChart1)
        chart.Series.Add(lineSeriesChart2)

        Return
    End Sub

    Public Sub InitHistgram()
        For nIdx As Integer = 0 To (m_nHistgram.Length >> 1) - 1 Step 1
            m_nHistgram(ComInfo.PictureType.Original, nIdx) = 0
            m_nHistgram(ComInfo.PictureType.After, nIdx) = 0
        Next
    End Sub

    Public Sub CalHistgram()
        Dim nWidthSize As Integer = m_bitmapOrg.Width
        Dim nHeightSize As Integer = m_bitmapOrg.Height

        Dim bitmapDataOrg = m_bitmapOrg.LockBits(New Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb)
        Dim bitmapDataAfter As BitmapData = Nothing
        If (m_bitmapAfter IsNot Nothing) Then
            bitmapDataAfter = m_bitmapAfter.LockBits(New Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadOnly, PixelFormat.Format32bppArgb)
        End If

        Dim nIdxWidth As Integer
        Dim nIdxHeight As Integer

        For nIdxHeight = 0 To nHeightSize - 1 Step 1
            For nIdxWidth = 0 To nWidthSize - 1 Step 1
                Dim pAdr As IntPtr = bitmapDataOrg.Scan0
                Dim nPos As Integer = nIdxHeight * bitmapDataOrg.Stride + nIdxWidth * 4
                Dim nPixelB As Integer = ReadByte(pAdr, nPos + ComInfo.Pixel.B)
                Dim nPixelG As Integer = ReadByte(pAdr, nPos + ComInfo.Pixel.G)
                Dim nPixelR As Integer = ReadByte(pAdr, nPos + ComInfo.Pixel.R)

                Dim nGrayScale As Integer = (nPixelB + nPixelG + nPixelR) / 3

                m_nHistgram(ComInfo.PictureType.Original, nGrayScale) += 1

                If (m_bitmapAfter IsNot Nothing) Then
                    pAdr = bitmapDataAfter.Scan0
                    nPos = nIdxHeight * bitmapDataAfter.Stride + nIdxWidth * 4

                    nPixelB = ReadByte(pAdr, nPos + ComInfo.Pixel.B)
                    nPixelG = ReadByte(pAdr, nPos + ComInfo.Pixel.G)
                    nPixelR = ReadByte(pAdr, nPos + ComInfo.Pixel.R)

                    nGrayScale = (nPixelB + nPixelG + nPixelR) / 3

                    m_nHistgram(ComInfo.PictureType.After, nGrayScale) += 1
                End If
            Next
        Next
    End Sub
End Class