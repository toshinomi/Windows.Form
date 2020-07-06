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
	int mId;

	/// <summary>
	/// 名称
	/// </summary>
	String^ mName;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	ComImageProcessingType();

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="Id">ID</param>
	/// <param name="Nmae">名称</param>
	ComImageProcessingType(int Id, String^ Nmae);

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~ComImageProcessingType();

	/// <summary>
	/// IDの取得
	/// </summary>
	/// <returns>ID</returns>
	int GetId(void) { return mId; };

	/// <summary>
	/// IDの設定
	/// </summary>
	/// <param name="id">ID</param>
	void SetId(int id) { mId = id; };

	/// <summary>
	/// 名称の取得
	/// </summary>
	/// <returns>名称</returns>
	String^ GetName(void) { return mName; };

	/// <summary>
	/// 名称の設定
	/// </summary>
	/// <param name="name">名称</param>
	void SetName(String^ name) { mName = name; };

	/// <summary>
	/// クローン
	/// </summary>
	/// <returns>画像処理設定のクローン</returns>
	Object^ Clone();
};