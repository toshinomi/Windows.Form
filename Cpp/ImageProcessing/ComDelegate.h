#pragma once
using namespace System;
using namespace System::Drawing;

namespace ImageProcessing
{
	namespace ComDelegate
	{
		delegate void DelegateSetBool(bool _bValue);
		delegate bool DelegateGetBool(void);
		delegate void DelegateSetByte(Byte _nValue);
		delegate Byte DelegateGetByte(void);
		delegate void DelegateSetInt(int _nValue);
		delegate int DelegateGetInt(void);
		delegate void DelegateSetLong(long _lValue);
		delegate long DelegateGetLong(void);
		delegate void DelegateSetDouble(double _dValue);
		delegate double DelegateGetDouble(void);
		delegate void DelegateSetLongLong(long long _llValue);
		delegate long long DelegateGetLongLong(void);
		delegate void  DelegateSetBitmap(Bitmap^ _bitmap);
		delegate Bitmap^ DelegateGetBitmap(void);
		delegate void DelegateSetControlEnable(void);
		delegate void DelegateSetControlVisible(void);
	};
}