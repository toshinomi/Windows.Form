#include "ComImageProcessingType.h"

ComImageProcessingType::ComImageProcessingType()
{
}

ComImageProcessingType::ComImageProcessingType(int _nId, String^ _strNmae)
{
	m_nId = _nId;
	m_strName = _strNmae;
}

ComImageProcessingType::~ComImageProcessingType()
{
}

Object^ ComImageProcessingType::Clone()
{
	return (ComImageProcessingType^)MemberwiseClone();
}