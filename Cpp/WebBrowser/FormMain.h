#pragma once
#include "FormWebBrowser.h"

namespace WebBrowser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace WebBrowser;

	/// <summary>
	/// FormMain の概要
	/// </summary>
	public ref class FormMain : public System::Windows::Forms::Form
	{
	public:
		FormMain(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			System::Collections::Generic::Dictionary<unsigned int, FormWebBrowser^>(m_listWebBrowser);
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~FormMain()
		{
			if (components)
			{
				delete components;

				m_listWebBrowser.Clear();
				m_nCountWebBrowser = 0;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ menuFile;
	private: System::Windows::Forms::ToolStripMenuItem^ menuFile_NewOpen;
	private: System::Windows::Forms::ToolStripMenuItem^ menuFile_End;
	private: System::Windows::Forms::ToolStripMenuItem^ menuWindow;
	private: System::Windows::Forms::ToolStripMenuItem^ menuWindow_Cascade;
	private: System::Windows::Forms::ToolStripMenuItem^ menuWindow_TileHorizontal;
	private: System::Windows::Forms::ToolStripMenuItem^ menuWindow_TileVertical;

	protected:

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMain::typeid));
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->menuFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuFile_NewOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuFile_End = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuWindow = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuWindow_Cascade = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuWindow_TileHorizontal = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuWindow_TileVertical = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->menuFile, this->menuWindow });
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(480, 24);
			this->menuStrip->TabIndex = 1;
			this->menuStrip->Text = L"menuStrip1";
			// 
			// menuFile
			// 
			this->menuFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuFile_NewOpen,
					this->menuFile_End
			});
			this->menuFile->Name = L"menuFile";
			this->menuFile->Size = System::Drawing::Size(67, 20);
			this->menuFile->Text = L"ファイル(&F)";
			// 
			// menuFile_NewOpen
			// 
			this->menuFile_NewOpen->Name = L"menuFile_NewOpen";
			this->menuFile_NewOpen->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->menuFile_NewOpen->Size = System::Drawing::Size(227, 22);
			this->menuFile_NewOpen->Text = L"新規ウィンドウを開く(&N)";
			this->menuFile_NewOpen->Click += gcnew System::EventHandler(this, &FormMain::OnClickMenuFileNewOpen);
			// 
			// menuFile_End
			// 
			this->menuFile_End->Name = L"menuFile_End";
			this->menuFile_End->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->menuFile_End->Size = System::Drawing::Size(227, 22);
			this->menuFile_End->Text = L"終了(&X)";
			this->menuFile_End->Click += gcnew System::EventHandler(this, &FormMain::OnClickMenuFileEnd);
			// 
			// menuWindow
			// 
			this->menuWindow->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->menuWindow_Cascade,
					this->menuWindow_TileHorizontal, this->menuWindow_TileVertical
			});
			this->menuWindow->Name = L"menuWindow";
			this->menuWindow->Size = System::Drawing::Size(80, 20);
			this->menuWindow->Text = L"ウィンドウ(&W)";
			// 
			// menuWindow_Cascade
			// 
			this->menuWindow_Cascade->Name = L"menuWindow_Cascade";
			this->menuWindow_Cascade->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt)
				| System::Windows::Forms::Keys::E));
			this->menuWindow_Cascade->Size = System::Drawing::Size(244, 22);
			this->menuWindow_Cascade->Text = L"重ねて表示(&E)";
			this->menuWindow_Cascade->Click += gcnew System::EventHandler(this, &FormMain::OnClickMenuWindowCascade);
			// 
			// menuWindow_TileHorizontal
			// 
			this->menuWindow_TileHorizontal->Name = L"menuWindow_TileHorizontal";
			this->menuWindow_TileHorizontal->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt)
				| System::Windows::Forms::Keys::H));
			this->menuWindow_TileHorizontal->Size = System::Drawing::Size(244, 22);
			this->menuWindow_TileHorizontal->Text = L"上下に並べて表示(&H)";
			this->menuWindow_TileHorizontal->Click += gcnew System::EventHandler(this, &FormMain::OnClickMenuWindowTileHorizontal);
			// 
			// menuWindow_TileVertical
			// 
			this->menuWindow_TileVertical->Name = L"menuWindow_TileVertical";
			this->menuWindow_TileVertical->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt)
				| System::Windows::Forms::Keys::T));
			this->menuWindow_TileVertical->Size = System::Drawing::Size(244, 22);
			this->menuWindow_TileVertical->Text = L"左右に並べて表示(&T)";
			this->menuWindow_TileVertical->Click += gcnew System::EventHandler(this, &FormMain::OnClickMenuWindowTileVertical);
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(480, 300);
			this->Controls->Add(this->menuStrip);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"FormMain";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FormMain::OnFormClosedFormMain);
			this->Load += gcnew System::EventHandler(this, &FormMain::OnLoadFormMain);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		unsigned int mCountWebBrowser;
		System::Collections::Generic::Dictionary<unsigned int, FormWebBrowser^> mListWebBrowser;
	public:
		void OnLoadFormMain(Object^ sender, EventArgs^ e);
		void OnClickMenuFileNewOpen(Object^ sender, EventArgs^ e);
		void OnClickMenuWindowCascade(Object^ sender, EventArgs^ e);
		void OnClickMenuWindowTileHorizontal(Object^ sender, EventArgs^ e);
		void OnClickMenuWindowTileVertical(Object^ sender, EventArgs^ e);
		void OnClickMenuFileEnd(Object^ sender, EventArgs^ e);
		void OnFormClosedFormMain(Object^ sender, FormClosedEventArgs^ e);
		void SetFormMain(void);
		void SetFormChild(void);

		FormWebBrowser^ GetFormWebBrowser(unsigned int key)
		{
			return mListWebBrowser[key];
		}

		void RemoveListWebBrowser(unsigned int key)
		{
			mListWebBrowser.Remove(key);
		}
};
}
