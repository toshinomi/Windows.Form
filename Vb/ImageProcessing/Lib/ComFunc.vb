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
        Dim ConvertValue As Byte = 0

        If (value > 255.0) Then
            ConvertValue = 255
        ElseIf (value < 0) Then
            ConvertValue = 0
        Else
            ConvertValue = CByte(value)
        End If

        Return ConvertValue
    End Function

    ''' <summary>
    ''' long型のデータからbyte型のデータへの変換
    ''' </summary>
    ''' <param name="value">long型のデータ</param>
    ''' <returns>byte型のデータ</returns>
    Public Shared Function LongToByte(value As Long) As Byte
        Dim ConvertValue As Byte = 0

        If (value > 255) Then
            ConvertValue = 255
        ElseIf (value < 0) Then
            ConvertValue = 0
        Else
            ConvertValue = CByte(value)
        End If

        Return ConvertValue
    End Function
End Class