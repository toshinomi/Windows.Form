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
		int m_nId;
		String^ m_strName;
	public:
		ComImageProcessingType();
		ComImageProcessingType(int _Id, String^ _strNmae);
		~ComImageProcessingType();
		// Id
		int GetId(void) { return m_nId; };
		void SetId(int _nId) { m_nId = _nId; };
		// Name
		String^ GetName(void) { return m_strName; };
		void SetName(String^ _strName) { m_strName = _strName; };
		Object^ Clone();
	};
}