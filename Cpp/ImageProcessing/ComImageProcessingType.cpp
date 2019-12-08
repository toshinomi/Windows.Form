#include "ComImageProcessingType.h"

/// <summary>
/// コンストラクタ
/// </summary>
ComImageProcessingType::ComImageProcessingType()
{
}

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="_nId">ID</param>
/// <param name="_strNmae">名称</param>
ComImageProcessingType::ComImageProcessingType(int _nId, String^ _strNmae)
{
	m_nId = _nId;
	m_strName = _strNmae;
}

/// <summary>
/// デスクトラクタ
/// </summary>
ComImageProcessingType::~ComImageProcessingType()
{
}

/// <summary>
/// クローン
/// </summary>
/// <returns>画像処理設定のクローン</returns>
Object^ ComImageProcessingType::Clone()
{
	return (ComImageProcessingType^)MemberwiseClone();
}