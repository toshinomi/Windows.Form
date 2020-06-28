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
    /// <param name="dValue">Double型のデータ</param>
    /// <returns>byte型のデータ</returns>
    static public byte DoubleToByte(double dValue)
    {
        byte nCnvValue = 0;

        if (dValue > 255.0)
        {
            nCnvValue = 255;
        }
        else if (dValue < 0)
        {
            nCnvValue = 0;
        }
        else
        {
            nCnvValue = (byte)dValue;
        }

        return nCnvValue;
    }

    /// <summary>
    /// long型のデータからbyte型のデータへの変換
    /// </summary>
    /// <param name="lValue">long型のデータ</param>
    /// <returns>byte型のデータ</returns>
    static public byte LongToByte(long lValue)
    {
        byte nCnvValue = 0;
            
        if (lValue > 255)
        {
            nCnvValue = 255;
        }
        else if (lValue < 0)
        {
            nCnvValue = 0;
        }
        else
        {
            nCnvValue = (byte)lValue;
        }

        return nCnvValue;
    }
}