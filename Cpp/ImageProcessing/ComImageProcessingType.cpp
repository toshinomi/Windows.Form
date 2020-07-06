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
/// <param name="id">ID</param>
/// <param name="name">名称</param>
ComImageProcessingType::ComImageProcessingType(int id, String^ name)
{
	mId = id;
	mName = name;
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