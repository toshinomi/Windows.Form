#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;

/// <summary>
/// 共通関数のロジック
/// </summary>
public class ComFunc
{
public:
	/// <summary>
	/// Double型のデータからbyte型のデータへの変換
	/// </summary>
	/// <param name="_dValue">Double型のデータ</param>
	/// <returns>byte型のデータ</returns>
	static Byte DoubleToByte(double _dValue);

	/// <summary>
	/// long型のデータからbyte型のデータへの変換
	/// </summary>
	/// <param name="_lValue">long型のデータ</param>
	/// <returns>byte型のデータ</returns>
	static Byte LongToByte(long _lValue);
};