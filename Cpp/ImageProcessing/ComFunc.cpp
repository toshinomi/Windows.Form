#include "ComFunc.h"

/// <summary>
/// Double型のデータからbyte型のデータへの変換
/// </summary>
/// <param name="_dValue">Double型のデータ</param>
/// <returns>byte型のデータ</returns>
Byte ComFunc::DoubleToByte(double _dValue)
{
	Byte nCnvValue = 0;

	if (_dValue > 255.0)
	{
		nCnvValue = 255;
	}
	else if (_dValue < 0)
	{
		nCnvValue = 0;
	}
	else
	{
		nCnvValue = (Byte)_dValue;
	}

	return nCnvValue;
}

/// <summary>
/// long型のデータからbyte型のデータへの変換
/// </summary>
/// <param name="_lValue">long型のデータ</param>
/// <returns>byte型のデータ</returns>
Byte ComFunc::LongToByte(long _lValue)
{
	Byte nCnvValue = 0;

	if (_lValue > 255)
	{
		nCnvValue = 255;
	}
	else if (_lValue < 0)
	{
		nCnvValue = 0;
	}
	else
	{
		nCnvValue = (Byte)_lValue;
	}

	return nCnvValue;
}