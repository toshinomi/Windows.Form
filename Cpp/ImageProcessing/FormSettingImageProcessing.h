#pragma once
#include "ComImageProcessingType.h"

namespace ImageProcessing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms;

	/// <summary>
	/// FormSettingImageProcessing の概要
	/// </summary>
	public ref class FormSettingImageProcessing : public System::Windows::Forms::Form
	{
	public:
		FormSettingImageProcessing(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			LoadParam();
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~FormSettingImageProcessing()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnOk;
	protected:
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::ComboBox^ cmbBoxImageProcessingType;
	private: System::Windows::Forms::Label^ labelImageProcessingType;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormSettingImageProcessing::typeid));
			this->btnOk = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->cmbBoxImageProcessingType = (gcnew System::Windows::Forms::ComboBox());
			this->labelImageProcessingType = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnOk
			// 
			this->btnOk->BackColor = System::Drawing::SystemColors::Window;
			this->btnOk->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->btnOk->Location = System::Drawing::Point(215, 213);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(126, 37);
			this->btnOk->TabIndex = 7;
			this->btnOk->Text = L"OK";
			this->btnOk->UseVisualStyleBackColor = false;
			this->btnOk->Click += gcnew System::EventHandler(this, &FormSettingImageProcessing::OnClickOk);
			// 
			// btnCancel
			// 
			this->btnCancel->BackColor = System::Drawing::SystemColors::Window;
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->btnCancel->Location = System::Drawing::Point(347, 213);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(126, 37);
			this->btnCancel->TabIndex = 6;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = false;
			this->btnCancel->Click += gcnew System::EventHandler(this, &FormSettingImageProcessing::OnClickCancel);
			// 
			// cmbBoxImageProcessingType
			// 
			this->cmbBoxImageProcessingType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbBoxImageProcessingType->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->cmbBoxImageProcessingType->FormattingEnabled = true;
			this->cmbBoxImageProcessingType->Location = System::Drawing::Point(229, 15);
			this->cmbBoxImageProcessingType->Name = L"cmbBoxImageProcessingType";
			this->cmbBoxImageProcessingType->Size = System::Drawing::Size(244, 28);
			this->cmbBoxImageProcessingType->TabIndex = 5;
			// 
			// labelImageProcessingType
			// 
			this->labelImageProcessingType->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelImageProcessingType->Location = System::Drawing::Point(12, 10);
			this->labelImageProcessingType->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->labelImageProcessingType->Name = L"labelImageProcessingType";
			this->labelImageProcessingType->Size = System::Drawing::Size(209, 36);
			this->labelImageProcessingType->TabIndex = 4;
			this->labelImageProcessingType->Text = L"Image Processing Type";
			this->labelImageProcessingType->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// FormSettingImageProcessing
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(484, 261);
			this->Controls->Add(this->btnOk);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->cmbBoxImageProcessingType);
			this->Controls->Add(this->labelImageProcessingType);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FormSettingImageProcessing";
			this->Text = L"Setting Image Processing";
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
	public:
		/// <summary>
		/// 設定の読込
		/// </summary>
		void LoadParam(void);

		/// <summary>
		/// 設定の保存
		/// </summary>
		void SaveParam(void);

		/// <summary>
		/// 画像処理タイプのコンボボックス情報の取得
		/// </summary>
		/// <returns>画像処理タイプのコンボボックス情報</returns>
		ComboBox^ GetCmbBoxImageProcessingType(void) { return cmbBoxImageProcessingType; };
	private:
		/// <summary>
		/// OKボタンのクリックイベント
		/// </summary>
		/// <param name="sender">オブジェクト</param>
		/// <param name="e">イベントのデータ</param>
		void OnClickOk(System::Object^ sender, System::EventArgs^ e);

		/// <summary>
		/// Cancelボタンのクリックイベント
		/// </summary>
		/// <param name="sender">オブジェクト</param>
		/// <param name="e">イベントのデータ</param>
		void OnClickCancel(System::Object^ sender, System::EventArgs^ e);
	};
}