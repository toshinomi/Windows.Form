#include "ComImageProcessingType.h"

using namespace ImageProcessing;

ComImageProcessingType::ComImageProcessingType()
{
}

ComImageProcessingType::ComImageProcessingType(int _Id, String^ _Nmae)
{
	m_Id = _Id;
	m_Name = _Nmae;
}

ComImageProcessingType::~ComImageProcessingType()
{
}

Object^ ComImageProcessingType::Clone()
{
	return (ComImageProcessingType^)MemberwiseClone();
}