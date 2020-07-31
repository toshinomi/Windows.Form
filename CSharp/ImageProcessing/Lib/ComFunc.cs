using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/// <summary>
/// 共通関数のロジック
/// </summary>
public class ComFunc
{
    /// <summary>
    /// Double型のデータからbyte型のデータへの変換
    /// </summary>
    /// <param name="value">Double型のデータ</param>
    /// <returns>byte型のデータ</returns>
    static public byte DoubleToByte(double value)
    {
        byte convertValue;
        if (value > 255.0)
        {
            convertValue = 255;
        }
        else if (value < 0)
        {
            convertValue = 0;
        }
        else
        {
            convertValue = (byte)value;
        }

        return convertValue;
    }

    /// <summary>
    /// long型のデータからbyte型のデータへの変換
    /// </summary>
    /// <param name="value">long型のデータ</param>
    /// <returns>byte型のデータ</returns>
    static public byte LongToByte(long value)
    {
        byte convertValue;
        if (value > 255)
        {
            convertValue = 255;
        }
        else if (value < 0)
        {
            convertValue = 0;
        }
        else
        {
            convertValue = (byte)value;
        }

        return convertValue;
    }
}