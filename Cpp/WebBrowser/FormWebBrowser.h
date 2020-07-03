#pragma once

namespace WebBrowser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// FormWebBrowser の概要
	/// </summary>
	public ref class FormWebBrowser : public System::Windows::Forms::Form
	{
	public:
		FormWebBrowser(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			m_strUrl = "";
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~FormWebBrowser()
		{
			if (components)
			{
				delete components;

				m_toolTip = nullptr;
			}
		}
	private: System::Windows::Forms::Panel^ panelUrl;
	private: System::Windows::Forms::Panel^ panelWebBrowser;
	private: System::Windows::Forms::Button^ buttonBack;
	private: System::Windows::Forms::Button^ buttonForward;
	private: System::Windows::Forms::Button^ buttonRefresh;
	private: System::Windows::Forms::Label^ labelUrl;
	private: System::Windows::Forms::TextBox^ textUrl;
	private: System::Windows::Forms::WebBrowser^ webBrowser;
	protected:

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormWebBrowser::typeid));
			this->panelUrl = (gcnew System::Windows::Forms::Panel());
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			this->buttonForward = (gcnew System::Windows::Forms::Button());
			this->buttonRefresh = (gcnew System::Windows::Forms::Button());
			this->labelUrl = (gcnew System::Windows::Forms::Label());
			this->textUrl = (gcnew System::Windows::Forms::TextBox());
			this->panelWebBrowser = (gcnew System::Windows::Forms::Panel());
			this->webBrowser = (gcnew System::Windows::Forms::WebBrowser());
			this->panelUrl->SuspendLayout();
			this->panelWebBrowser->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelUrl
			// 
			this->panelUrl->Controls->Add(this->buttonBack);
			this->panelUrl->Controls->Add(this->buttonForward);
			this->panelUrl->Controls->Add(this->buttonRefresh);
			this->panelUrl->Controls->Add(this->labelUrl);
			this->panelUrl->Controls->Add(this->textUrl);
			this->panelUrl->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelUrl->Location = System::Drawing::Point(0, 0);
			this->panelUrl->Margin = System::Windows::Forms::Padding(2);
			this->panelUrl->Name = L"panelUrl";
			this->panelUrl->Size = System::Drawing::Size(480, 45);
			this->panelUrl->TabIndex = 0;
			// 
			// buttonBack
			// 
			this->buttonBack->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonBack.Image")));
			this->buttonBack->Location = System::Drawing::Point(0, 0);
			this->buttonBack->Margin = System::Windows::Forms::Padding(2);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(45, 43);
			this->buttonBack->TabIndex = 1;
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew System::EventHandler(this, &FormWebBrowser::OnClickBack);
			// 
			// buttonForward
			// 
			this->buttonForward->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonForward.Image")));
			this->buttonForward->Location = System::Drawing::Point(44, 0);
			this->buttonForward->Margin = System::Windows::Forms::Padding(2);
			this->buttonForward->Name = L"buttonForward";
			this->buttonForward->Size = System::Drawing::Size(45, 43);
			this->buttonForward->TabIndex = 2;
			this->buttonForward->UseVisualStyleBackColor = true;
			this->buttonForward->Click += gcnew System::EventHandler(this, &FormWebBrowser::OnClickForward);
			// 
			// buttonRefresh
			// 
			this->buttonRefresh->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonRefresh.Image")));
			this->buttonRefresh->Location = System::Drawing::Point(88, 0);
			this->buttonRefresh->Margin = System::Windows::Forms::Padding(2);
			this->buttonRefresh->Name = L"buttonRefresh";
			this->buttonRefresh->Size = System::Drawing::Size(45, 43);
			this->buttonRefresh->TabIndex = 3;
			this->buttonRefresh->UseVisualStyleBackColor = true;
			this->buttonRefresh->Click += gcnew System::EventHandler(this, &FormWebBrowser::OnClickRefresh);
			// 
			// labelUrl
			// 
			this->labelUrl->AutoSize = true;
			this->labelUrl->Location = System::Drawing::Point(136, 6);
			this->labelUrl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelUrl->Name = L"labelUrl";
			this->labelUrl->Size = System::Drawing::Size(27, 12);
			this->labelUrl->TabIndex = 4;
			this->labelUrl->Text = L"URL";
			// 
			// textUrl
			// 
			this->textUrl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textUrl->Location = System::Drawing::Point(136, 23);
			this->textUrl->Margin = System::Windows::Forms::Padding(2);
			this->textUrl->Name = L"textUrl";
			this->textUrl->Size = System::Drawing::Size(338, 19);
			this->textUrl->TabIndex = 5;
			this->textUrl->Text = L"https://www.bing.com/";
			this->textUrl->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormWebBrowser::OnKeyDownTextUrl);
			// 
			// panelWebBrowser
			// 
			this->panelWebBrowser->Controls->Add(this->webBrowser);
			this->panelWebBrowser->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelWebBrowser->Location = System::Drawing::Point(0, 45);
			this->panelWebBrowser->Margin = System::Windows::Forms::Padding(2);
			this->panelWebBrowser->Name = L"panelWebBrowser";
			this->panelWebBrowser->Size = System::Drawing::Size(480, 255);
			this->panelWebBrowser->TabIndex = 6;
			// 
			// webBrowser
			// 
			this->webBrowser->Dock = System::Windows::Forms::DockStyle::Fill;
			this->webBrowser->Location = System::Drawing::Point(0, 0);
			this->webBrowser->Margin = System::Windows::Forms::Padding(2);
			this->webBrowser->MinimumSize = System::Drawing::Size(12, 13);
			this->webBrowser->Name = L"webBrowser";
			this->webBrowser->ScriptErrorsSuppressed = true;
			this->webBrowser->Size = System::Drawing::Size(480, 255);
			this->webBrowser->TabIndex = 7;
			this->webBrowser->Navigated += gcnew System::Windows::Forms::WebBrowserNavigatedEventHandler(this, &FormWebBrowser::OnNavigatedWebBrowser);
			// 
			// FormWebBrowser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(480, 300);
			this->Controls->Add(this->panelWebBrowser);
			this->Controls->Add(this->panelUrl);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"FormWebBrowser";
			this->Text = L"https://www.bing.com/";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FormWebBrowser::OnFormClosedFormWebBrowser);
			this->Load += gcnew System::EventHandler(this, &FormWebBrowser::OnLoadFormWebBrowser);
			this->panelUrl->ResumeLayout(false);
			this->panelUrl->PerformLayout();
			this->panelWebBrowser->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		const String ^ HOME_URL = "https://www.bing.com/";
		String ^ mUrl;
		ToolTip ^ mToolTip;
	public:
		void OnFormClosedFormWebBrowser(Object ^ sender, FormClosedEventArgs ^ e);
		void OnLoadFormWebBrowser(Object ^ sender, EventArgs ^ e);
		void OnClickBack(Object ^ sender, EventArgs ^ e);
		void OnClickForward(Object ^ sender, EventArgs ^ e);
		void OnClickRefresh(Object ^ sender, EventArgs ^ e);
		void OnKeyDownTextUrl(Object ^ sender, KeyEventArgs ^ e);
		void OnNavigatedWebBrowser(Object ^ sender, WebBrowserNavigatedEventArgs ^ e);
		void SetInitToolTip(void);
		void HomeWebBrowser(void);
};
}
