Imports System.Threading

Namespace ImageProcessing
    Public MustInherit Class ComImgProc
        Protected m_bitmap As Bitmap

        Public Sub New(ByVal _bitmap As Bitmap)
            m_bitmap = _bitmap
        End Sub

        Public Property Bitmap() As Bitmap
            Get
                Return m_bitmap
            End Get
            Set(ByVal value As Bitmap)
                m_bitmap = value
            End Set
        End Property

        Public MustOverride Function GoImgProc(ByVal _token As CancellationToken) As Boolean
    End Class
End Namespace