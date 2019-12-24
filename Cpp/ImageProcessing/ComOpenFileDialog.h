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
	OpenFileDialog^ m_openFileDialog;

public:
	/// <summary>
	/// FileNameの設定
	/// </summary>
	/// <param name="_strFileName">FileName</param>
	void SetFileName(String^ _strFileName) { m_openFileDialog->FileName = _strFileName; }

	/// <summary>
	/// FileNameの取得
	/// </summary>
	/// <returns>FileName</returns>
	String^ GetFileName(void) { return m_openFileDialog->FileName; }

	/// <summary>
	/// InitialDirectoryの設定
	/// </summary>
	/// <param name="_strInitialDirectory">InitialDirectory</param>
	void SetInitialDirectory(String^ _strInitialDirectory) { m_openFileDialog->InitialDirectory = _strInitialDirectory; }

	/// <summary>
	/// InitialDirectoryの取得
	/// </summary>
	/// <returns>InitialDirectory</returns>
	String^ GetInitialDirectory(void) { return m_openFileDialog->InitialDirectory; }

	/// <summary>
	/// Filterの設定
	/// </summary>
	/// <param name="_strFilter">Filter</param>
	void SetFilter(String^ _strFilter) { m_openFileDialog->Filter = _strFilter; }

	/// <summary>
	/// Filterの取得
	/// </summary>
	/// <returns>Filter</returns>
	String^ GetFilter(void) { return m_openFileDialog->Filter; }

	/// <summary>
	/// FilterIndexの設定
	/// </summary>
	/// <param name="_nFilterIndex">FilterIndex</param>
	void SetFilterIndex(int _nFilterIndex) { m_openFileDialog->FilterIndex = _nFilterIndex; }

	/// <summary>
	/// FilterIndexの取得
	/// </summary>
	/// <returns>FilterIndex</returns>
	int GetFilterIndex(void) { return m_openFileDialog->FilterIndex; }

	/// <summary>
	/// Titleの設定
	/// </summary>
	/// <param name="_strTitle">Title</param>
	void SetTitle(String^ _strTitle) { m_openFileDialog->Title = _strTitle; }

	/// <summary>
	/// Titleの取得
	/// </summary>
	/// <returns>Title</returns>
	String^ GetTitle(void) { return m_openFileDialog->Title; }

	/// <summary>
	/// CheckFileExistsの設定
	/// </summary>
	/// <param name="_bCheckFileExists">CheckFileExists</param>
	void SetCheckFileExists(bool _bCheckFileExists) { m_openFileDialog->CheckFileExists = _bCheckFileExists; }

	/// <summary>
	/// CheckFileExistsの取得
	/// </summary>
	/// <returns>CheckFileExists</returns>
	bool GetCheckFileExists(void) { return m_openFileDialog->CheckFileExists; }

	/// <summary>
	/// CheckPathExistsの設定
	/// </summary>
	/// <param name="_bCheckPathExists">CheckPathExists</param>
	void SetCheckPathExists(bool _bCheckPathExists) { m_openFileDialog->CheckPathExists = _bCheckPathExists; }

	/// <summary>
	/// CheckPathExistsの取得
	/// </summary>
	/// <returns>CheckPathExists</returns>
	bool GetCheckPathExists(void) { return m_openFileDialog->CheckPathExists; }

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