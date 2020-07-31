#include "ComFunc.h"

/// <summary>
/// Double�^�̃f�[�^����byte�^�̃f�[�^�ւ̕ϊ�
/// </summary>
/// <param name="value">Double�^�̃f�[�^</param>
/// <returns>byte�^�̃f�[�^</returns>
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
/// long�^�̃f�[�^����byte�^�̃f�[�^�ւ̕ϊ�
/// </summary>
/// <param name="value">long�^�̃f�[�^</param>
/// <returns>byte�^�̃f�[�^</returns>
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