#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;

/// <summary>
/// ���ʊ֐��̃��W�b�N
/// </summary>
public class ComFunc
{
public:
	/// <summary>
	/// Double�^�̃f�[�^����byte�^�̃f�[�^�ւ̕ϊ�
	/// </summary>
	/// <param name="value">Double�^�̃f�[�^</param>
	/// <returns>byte�^�̃f�[�^</returns>
	static Byte DoubleToByte(double value);

	/// <summary>
	/// long�^�̃f�[�^����byte�^�̃f�[�^�ւ̕ϊ�
	/// </summary>
	/// <param name="value">long�^�̃f�[�^</param>
	/// <returns>byte�^�̃f�[�^</returns>
	static Byte LongToByte(long value);
};