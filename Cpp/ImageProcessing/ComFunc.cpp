#include "ComFunc.h"

/// <summary>
/// Double型のデータからbyte型のデータへの変換
/// </summary>
/// <param name="value">Double型のデータ</param>
/// <returns>byte型のデータ</returns>
Byte ComFunc::DoubleToByte(double value)
{
	Byte convertValue = 0;

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
		convertValue = (Byte)value;
	}

	return convertValue;
}

/// <summary>
/// long型のデータからbyte型のデータへの変換
/// </summary>
/// <param name="value">long型のデータ</param>
/// <returns>byte型のデータ</returns>
Byte ComFunc::LongToByte(long value)
{
	Byte convertValue = 0;

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
		convertValue = (Byte)value;
	}

	return convertValue;
}