#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;

/// <summary>
/// 画像処理設定のロジック
/// </summary>
public ref class ComImageProcessingType
{
private:
	/// <summary>
	/// ID
	/// </summary>
	int m_nId;

	/// <summary>
	/// 名称
	/// </summary>
	String^ m_strName;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	ComImageProcessingType();

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_nId">ID</param>
	/// <param name="_strNmae">名称</param>
	ComImageProcessingType(int _Id, String^ _strNmae);

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~ComImageProcessingType();

	/// <summary>
	/// IDの取得
	/// </summary>
	/// <returns>ID</returns>
	int GetId(void) { return m_nId; };

	/// <summary>
	/// IDの設定
	/// </summary>
	/// <param name="_nId">ID</param>
	void SetId(int _nId) { m_nId = _nId; };

	/// <summary>
	/// 名称の取得
	/// </summary>
	/// <returns>名称</returns>
	String^ GetName(void) { return m_strName; };

	/// <summary>
	/// 名称の設定
	/// </summary>
	/// <param name="_strName">名称</param>
	void SetName(String^ _strName) { m_strName = _strName; };

	/// <summary>
	/// クローン
	/// </summary>
	/// <returns>画像処理設定のクローン</returns>
	Object^ Clone();
};