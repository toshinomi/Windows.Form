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
	/// <param name="value">Double型のデータ</param>
	/// <returns>byte型のデータ</returns>
	static Byte DoubleToByte(double value);

	/// <summary>
	/// long型のデータからbyte型のデータへの変換
	/// </summary>
	/// <param name="value">long型のデータ</param>
	/// <returns>byte型のデータ</returns>
	static Byte LongToByte(long value);
};