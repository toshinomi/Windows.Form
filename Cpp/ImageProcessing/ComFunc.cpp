#include "ComFunc.h"

Byte ImageProcessing::ComFunc::DoubleToByte(double _dValue)
{
	Byte byteCnvValue = 0;

	if (_dValue > 255.0)
	{
		byteCnvValue = 255;
	}
	else if (_dValue < 0)
	{
		byteCnvValue = 0;
	}
	else
	{
		byteCnvValue = (Byte)_dValue;
	}

	return byteCnvValue;
}
