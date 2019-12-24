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
	SaveFileDialog^ m_saveFileDialog;
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
	String^ GetFileName(void) { return m_saveFileDialog->FileName; };

	/// <summary>
	/// FileNameの設定
	/// </summary>
	/// <param name="_strFileName">FileName</param>
	void SetFileName(String^ _strFileName) { m_saveFileDialog->FileName = _strFileName; };

	/// <summary>
	/// InitialDirectoryの取得
	/// </summary>
	/// <returns>InitialDirectory</returns>
	String^ GetInitialDirectory(void) { return m_saveFileDialog->InitialDirectory; };

	/// <summary>
	/// InitialDirectoryの設定
	/// </summary>
	/// <param name="_strInitialDirectory">InitialDirectory</param>
	void SetInitialDirectory(String^ _strInitDirectory) { m_saveFileDialog->InitialDirectory = _strInitDirectory; };
	
	/// <summary>
	/// Filterの取得
	/// </summary>
	/// <returns>Filter</returns>
	String^ GetFilter(void) { return m_saveFileDialog->Filter; };

	/// <summary>
	/// Filterの設定
	/// </summary>
	/// <param name="_strFilter">Filter</param>
	void SetFilter(String^ _nFilter) { m_saveFileDialog->Filter = _nFilter; };

	/// <summary>
	/// FilterIndexの取得
	/// </summary>
	/// <returns>FilterIndex</returns>
	int GetFilterIndex(void) { return m_saveFileDialog->FilterIndex; };

	/// <summary>
	/// FilterIndexの設定
	/// </summary>
	/// <param name="_nFilterIndex">FilterIndex</param>
	void SetFilterIndex(int _nFilterIndex) { m_saveFileDialog->FilterIndex = _nFilterIndex; };

	/// <summary>
	/// Titleの取得
	/// </summary>
	/// <returns>Title</returns>
	String^ GetTitle(void) { return m_saveFileDialog->Title; };

	/// <summary>
	/// Titleの設定
	/// </summary>
	/// <param name="_strTitle">Title</param>
	void SetTitle(String^ _strTitle) { m_saveFileDialog->Title = _strTitle; };

	/// <summary>
	/// CheckFileExistsの取得
	/// </summary>
	/// <returns>CheckFileExists</returns>
	bool GetCheckFileExists(void) { return m_saveFileDialog->CheckFileExists; };

	/// <summary>
	/// CheckFileExistsの設定
	/// </summary>
	/// <param name="_bCheckFileExists">CheckFileExists</param>
	void SetCheckFileExists(bool _bCheckFileExists) { m_saveFileDialog->CheckFileExists = _bCheckFileExists; };

	/// <summary>
	/// CheckPathExistsの取得
	/// </summary>
	/// <returns>CheckPathExists</returns>
	bool GetCheckPathExists(void) { return m_saveFileDialog->CheckPathExists; };

	/// <summary>
	/// CheckPathExistsの設定
	/// </summary>
	/// <param name="_bCheckPathExists">CheckPathExists</param>
	void SetCheckPathExists(bool _bCheckPathExists) { m_saveFileDialog->CheckPathExists = _bCheckPathExists; };

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