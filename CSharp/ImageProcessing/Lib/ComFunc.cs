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
        byte ConvertValue;
        if (value > 255.0)
        {
            ConvertValue = 255;
        }
        else if (value < 0)
        {
            ConvertValue = 0;
        }
        else
        {
            ConvertValue = (byte)value;
        }

        return ConvertValue;
    }

    /// <summary>
    /// long型のデータからbyte型のデータへの変換
    /// </summary>
    /// <param name="value">long型のデータ</param>
    /// <returns>byte型のデータ</returns>
    static public byte LongToByte(long value)
    {
        byte ConvertValue;
        if (value > 255)
        {
            ConvertValue = 255;
        }
        else if (value < 0)
        {
            ConvertValue = 0;
        }
        else
        {
            ConvertValue = (byte)value;
        }

        return ConvertValue;
    }
}