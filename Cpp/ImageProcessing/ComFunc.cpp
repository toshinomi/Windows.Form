#include "ComFunc.h"

/// <summary>
/// Double�^�̃f�[�^����byte�^�̃f�[�^�ւ̕ϊ�
/// </summary>
/// <param name="value">Double�^�̃f�[�^</param>
/// <returns>byte�^�̃f�[�^</returns>
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
/// long�^�̃f�[�^����byte�^�̃f�[�^�ւ̕ϊ�
/// </summary>
/// <param name="value">long�^�̃f�[�^</param>
/// <returns>byte�^�̃f�[�^</returns>
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