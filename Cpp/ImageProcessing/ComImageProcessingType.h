#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;

namespace ImageProcessing
{
	public ref class ComImageProcessingType
	{
	private:
		int m_Id;
		String^ m_Name;
	public:
		ComImageProcessingType();
		ComImageProcessingType(int _Id, String^ _Nmae);
		~ComImageProcessingType();
		Object^ Clone();
	};
}