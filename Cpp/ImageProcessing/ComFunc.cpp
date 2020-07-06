#include "ComFunc.h"

/// <summary>
/// Double型のデータからbyte型のデータへの変換
/// </summary>
/// <param name="value">Double型のデータ</param>
/// <returns>byte型のデータ</returns>
Byte ComFunc::DoubleToByte(double value)
{
	Byte nCnvValue = 0;

	if (value > 255.0)
	{
		nCnvValue = 255;
	}
	else if (value < 0)
	{
		nCnvValue = 0;
	}
	else
	{
		nCnvValue = (Byte)value;
	}

	return nCnvValue;
}

/// <summary>
/// long型のデータからbyte型のデータへの変換
/// </summary>
/// <param name="value">long型のデータ</param>
/// <returns>byte型のデータ</returns>
Byte ComFunc::LongToByte(long value)
{
	Byte nCnvValue = 0;

	if (value > 255)
	{
		nCnvValue = 255;
	}
	else if (value < 0)
	{
		nCnvValue = 0;
	}
	else
	{
		nCnvValue = (Byte)value;
	}

	return nCnvValue;
}