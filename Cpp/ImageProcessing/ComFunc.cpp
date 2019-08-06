#include "ComFunc.h"

using namespace ImageProcessing;

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