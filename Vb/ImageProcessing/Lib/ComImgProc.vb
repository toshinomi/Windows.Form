Imports System.Threading

Public MustInherit Class ComImgProc
    Protected m_bitmap As Bitmap
    Protected m_bitmapAfter As Bitmap

    Public Sub New(ByVal _bitmap As Bitmap)
        m_bitmap = _bitmap
    End Sub

    Public Overridable Sub Init()
        m_bitmap = Nothing
        m_bitmapAfter = Nothing
    End Sub

    Public Property Bitmap() As Bitmap
        Get
            Return m_bitmap
        End Get
        Set(ByVal value As Bitmap)
            m_bitmap = value
        End Set
    End Property

    Public Property BitmapAfter() As Bitmap
        Get
            Return m_bitmapAfter
        End Get
        Set(ByVal value As Bitmap)
            m_bitmapAfter = value
        End Set
    End Property

    Public MustOverride Function GoImgProc(ByVal _token As CancellationToken) As Boolean
End Class