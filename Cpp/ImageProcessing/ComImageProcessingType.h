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
		// Id
		int GetId(void) { return m_Id; };
		void SetId(int _Id) { m_Id = _Id; };
		// Name
		String^ GetName(void) { return m_Name; };
		void SetName(String^ _Name) { m_Name = _Name; };
		Object^ Clone();
	};
}