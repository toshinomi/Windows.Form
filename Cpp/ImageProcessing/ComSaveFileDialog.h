#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Text;
using namespace System::Threading::Tasks;
using namespace System::Windows::Forms;

/// <summary>
/// ファイルセーブのロジック
/// </summary>
public ref class ComSaveFileDialog
{
protected:
	/// <summary>
	/// セーブファイルダイアログ
	/// </summary>
	SaveFileDialog^ mSaveFileDialog;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	ComSaveFileDialog(void);

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~ComSaveFileDialog(void);

	/// <summary>
	/// FileNameの取得
	/// </summary>
	/// <returns>FileName</returns>
	String^ GetFileName(void) { return mSaveFileDialog->FileName; };

	/// <summary>
	/// FileNameの設定
	/// </summary>
	/// <param name="fileName">FileName</param>
	void SetFileName(String^ fileName) { mSaveFileDialog->FileName = fileName; };

	/// <summary>
	/// InitialDirectoryの取得
	/// </summary>
	/// <returns>InitialDirectory</returns>
	String^ GetInitialDirectory(void) { return mSaveFileDialog->InitialDirectory; };

	/// <summary>
	/// InitialDirectoryの設定
	/// </summary>
	/// <param name="initDirectory">InitialDirectory</param>
	void SetInitialDirectory(String^ initDirectory) { mSaveFileDialog->InitialDirectory = initDirectory; };
	
	/// <summary>
	/// Filterの取得
	/// </summary>
	/// <returns>Filter</returns>
	String^ GetFilter(void) { return mSaveFileDialog->Filter; };

	/// <summary>
	/// Filterの設定
	/// </summary>
	/// <param name="filter">Filter</param>
	void SetFilter(String^ filter) { mSaveFileDialog->Filter = filter; };

	/// <summary>
	/// FilterIndexの取得
	/// </summary>
	/// <returns>FilterIndex</returns>
	int GetFilterIndex(void) { return mSaveFileDialog->FilterIndex; };

	/// <summary>
	/// FilterIndexの設定
	/// </summary>
	/// <param name="filterIndex">FilterIndex</param>
	void SetFilterIndex(int filterIndex) { mSaveFileDialog->FilterIndex = filterIndex; };

	/// <summary>
	/// Titleの取得
	/// </summary>
	/// <returns>Title</returns>
	String^ GetTitle(void) { return mSaveFileDialog->Title; };

	/// <summary>
	/// Titleの設定
	/// </summary>
	/// <param name="title">Title</param>
	void SetTitle(String^ title) { mSaveFileDialog->Title = title; };

	/// <summary>
	/// CheckFileExistsの取得
	/// </summary>
	/// <returns>CheckFileExists</returns>
	bool GetCheckFileExists(void) { return mSaveFileDialog->CheckFileExists; };

	/// <summary>
	/// CheckFileExistsの設定
	/// </summary>
	/// <param name="checkFileExists">CheckFileExists</param>
	void SetCheckFileExists(bool checkFileExists) { mSaveFileDialog->CheckFileExists = checkFileExists; };

	/// <summary>
	/// CheckPathExistsの取得
	/// </summary>
	/// <returns>CheckPathExists</returns>
	bool GetCheckPathExists(void) { return mSaveFileDialog->CheckPathExists; };

	/// <summary>
	/// CheckPathExistsの設定
	/// </summary>
	/// <param name="checkPathExists">CheckPathExists</param>
	void SetCheckPathExists(bool checkPathExists) { mSaveFileDialog->CheckPathExists = checkPathExists; };

	/// <summary>
	/// ダイアログの表示
	/// </summary>
	/// <returns>結果 成功/失敗</returns>
	bool ShowDialog(void);

	/// <summary>
	/// ストリームの書込み
	/// </summary>
	/// <param name="_str">ファイル名称</param>
	/// <returns>実行結果 成功/失敗</returns>
	bool StreamWrite(String^ _str);
};