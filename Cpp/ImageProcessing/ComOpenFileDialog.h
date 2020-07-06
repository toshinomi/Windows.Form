#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;
using namespace System::Windows::Forms;

/// <summary>
/// ファイルオープンのロジック
/// </summary>
public ref class ComOpenFileDialog
{
protected:
	/// <summary>
	/// オープンファイルダイアログ
	/// </summary>
	OpenFileDialog^ mOpenFileDialog;

public:
	/// <summary>
	/// FileNameの設定
	/// </summary>
	/// <param name="_strFileName">fileName</param>
	void SetFileName(String^ fileName) { mOpenFileDialog->FileName = fileName; }

	/// <summary>
	/// FileNameの取得
	/// </summary>
	/// <returns>FileName</returns>
	String^ GetFileName(void) { return mOpenFileDialog->FileName; }

	/// <summary>
	/// InitialDirectoryの設定
	/// </summary>
	/// <param name="initialDirectory">InitialDirectory</param>
	void SetInitialDirectory(String^ initialDirectory) { mOpenFileDialog->InitialDirectory = initialDirectory; }

	/// <summary>
	/// InitialDirectoryの取得
	/// </summary>
	/// <returns>InitialDirectory</returns>
	String^ GetInitialDirectory(void) { return mOpenFileDialog->InitialDirectory; }

	/// <summary>
	/// Filterの設定
	/// </summary>
	/// <param name="filter">Filter</param>
	void SetFilter(String^ filter) { mOpenFileDialog->Filter = filter; }

	/// <summary>
	/// Filterの取得
	/// </summary>
	/// <returns>Filter</returns>
	String^ GetFilter(void) { return mOpenFileDialog->Filter; }

	/// <summary>
	/// FilterIndexの設定
	/// </summary>
	/// <param name="filterIndex">FilterIndex</param>
	void SetFilterIndex(int filterIndex) { mOpenFileDialog->FilterIndex = filterIndex; }

	/// <summary>
	/// FilterIndexの取得
	/// </summary>
	/// <returns>FilterIndex</returns>
	int GetFilterIndex(void) { return mOpenFileDialog->FilterIndex; }

	/// <summary>
	/// Titleの設定
	/// </summary>
	/// <param name="title">Title</param>
	void SetTitle(String^ title) { mOpenFileDialog->Title = title; }

	/// <summary>
	/// Titleの取得
	/// </summary>
	/// <returns>Title</returns>
	String^ GetTitle(void) { return mOpenFileDialog->Title; }

	/// <summary>
	/// CheckFileExistsの設定
	/// </summary>
	/// <param name="checkFileExists">CheckFileExists</param>
	void SetCheckFileExists(bool checkFileExists) { mOpenFileDialog->CheckFileExists = checkFileExists; }

	/// <summary>
	/// CheckFileExistsの取得
	/// </summary>
	/// <returns>CheckFileExists</returns>
	bool GetCheckFileExists(void) { return mOpenFileDialog->CheckFileExists; }

	/// <summary>
	/// CheckPathExistsの設定
	/// </summary>
	/// <param name="checkPathExists">CheckPathExists</param>
	void SetCheckPathExists(bool checkPathExists) { mOpenFileDialog->CheckPathExists = checkPathExists; }

	/// <summary>
	/// CheckPathExistsの取得
	/// </summary>
	/// <returns>CheckPathExists</returns>
	bool GetCheckPathExists(void) { return mOpenFileDialog->CheckPathExists; }

	/// <summary>
	/// コンストラクタ
	/// </summary>
	ComOpenFileDialog();

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~ComOpenFileDialog();

	/// <summary>
	/// ダイアログの表示
	/// </summary>
	/// <returns>結果 成功/失敗</returns>
	bool ShowDialog();
};