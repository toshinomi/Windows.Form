''' <summary>
''' 共通関数のロジック
''' </summary>
Public Class ComFunc
    ''' <summary>
    ''' Double型のデータからbyte型のデータへの変換
    ''' </summary>
    ''' <param name="value">Double型のデータ</param>
    ''' <returns>byte型のデータ</returns>
    Public Shared Function DoubleToByte(value As Double) As Byte
        Dim convertValue As Byte = 0

        If (value > 255.0) Then
            convertValue = 255
        ElseIf (value < 0) Then
            convertValue = 0
        Else
            convertValue = CByte(value)
        End If

        Return convertValue
    End Function

    ''' <summary>
    ''' long型のデータからbyte型のデータへの変換
    ''' </summary>
    ''' <param name="value">long型のデータ</param>
    ''' <returns>byte型のデータ</returns>
    Public Shared Function LongToByte(value As Long) As Byte
        Dim convertValue As Byte = 0

        If (value > 255) Then
            convertValue = 255
        ElseIf (value < 0) Then
            convertValue = 0
        Else
            convertValue = CByte(value)
        End If

        Return convertValue
    End Function
End Class