#pragma once
#include "EdgeDetection.h"
#include "GrayScale.h"
#include "Binarization.h"
#include "GrayScale2Diff.h"
#include "ColorReversal.h"
#include "FormHistgram.h"
#include "ComImageProcessingInfo.h"
#include "ComInfo.h"
#include "ComDelegate.h"
#include "ComOpenFileDialog.h"
#include "ComSaveFileDialog.h"
#include "FormSettingImageProcessing.h"
#include "FormHistgram.h"
#include "ComInfo.h"
#include "ImageProcessing.h"

namespace ImageProcessing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Configuration;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Drawing::Imaging;
	using namespace System::Diagnostics;
	using namespace System::Threading::Tasks;

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
			btnFileSelect->Enabled = true;
			btnAllClear->Enabled = true;
			btnStart->Enabled = false;
			btnStop->Enabled = false;
			btnSaveImage->Enabled = false;

			pictureBoxStatus->Visible = false;

			SetToolTip();

			mBitmap = nullptr;
			mTokenSource = nullptr;
			mImageProcessing = nullptr;

			System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);
			mCurrentImageProcessingName = config->AppSettings->Settings["ImgTypeSelectName"]->Value;
			this->Text = "Image Processing ( " + mCurrentImageProcessingName + " )";

			sliderThresh->Enabled = mCurrentImageProcessingName == (String^)ComConstStringInfo::IMG_NAME_BINARIZATION ? true : false;
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

				delete mBitmap;
				delete mTokenSource;
				delete mImageProcessing;
				delete mHistgram;
			}
		}
	private: System::Windows::Forms::ToolTip^ toolTipBtnStop;
	protected:
	private: System::Windows::Forms::Label^ labelTime;
	private: System::Windows::Forms::Label^ labelTimeUnit;
	private: System::Windows::Forms::GroupBox^ groupBoxProcessingInfo;
	private: System::Windows::Forms::TextBox^ textBoxTime;
	private: System::Windows::Forms::ToolTip^ toolTipBtnStart;
	private: System::Windows::Forms::ToolTip^ toolTipBtnAllClear;
	private: System::Windows::Forms::PictureBox^ pictureBoxStatus;
	private: System::Windows::Forms::Label^ labelAfterImage;
	private: System::Windows::Forms::PictureBox^ pictureBoxAfter;
	private: System::Windows::Forms::ToolTip^ toolTipBtnFileSelect;
	private: System::Windows::Forms::Label^ labelOriginalImage;
	private: System::Windows::Forms::GroupBox^ groupBoxImageOutput;
	private: System::Windows::Forms::PictureBox^ pictureBoxOriginal;
	private: System::Windows::Forms::Button^ btnStop;
	private: System::Windows::Forms::Button^ btnAllClear;
	private: System::Windows::Forms::Button^ btnStart;
	private: System::Windows::Forms::GroupBox^ groupBoxOperation;
	private: System::Windows::Forms::Button^ btnFileSelect;
	private: System::Windows::Forms::Button^ btnShowHistgram;
	private: System::Windows::Forms::Button^ btnSaveImage;
	private: System::Windows::Forms::ToolTip^ toolTipBtnSaveImage;
	private: System::Windows::Forms::ToolTip^ toolTipBtnShowHistgram;
	private: System::Windows::Forms::MenuStrip^ menuMain;

	private: System::Windows::Forms::ToolStripMenuItem^ fileFToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ endXToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ settingOToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ imageProcessingToolStripMenuItem;
	private: System::Windows::Forms::Label^ labelThresh;
	private: System::Windows::Forms::Label^ labelValue;
	private: System::Windows::Forms::TrackBar^ sliderThresh;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMain::typeid));
			this->toolTipBtnStop = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->labelTime = (gcnew System::Windows::Forms::Label());
			this->labelTimeUnit = (gcnew System::Windows::Forms::Label());
			this->groupBoxProcessingInfo = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxTime = (gcnew System::Windows::Forms::TextBox());
			this->toolTipBtnStart = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTipBtnAllClear = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->pictureBoxStatus = (gcnew System::Windows::Forms::PictureBox());
			this->labelAfterImage = (gcnew System::Windows::Forms::Label());
			this->pictureBoxAfter = (gcnew System::Windows::Forms::PictureBox());
			this->toolTipBtnFileSelect = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->labelOriginalImage = (gcnew System::Windows::Forms::Label());
			this->groupBoxImageOutput = (gcnew System::Windows::Forms::GroupBox());
			this->labelThresh = (gcnew System::Windows::Forms::Label());
			this->labelValue = (gcnew System::Windows::Forms::Label());
			this->sliderThresh = (gcnew System::Windows::Forms::TrackBar());
			this->pictureBoxOriginal = (gcnew System::Windows::Forms::PictureBox());
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->btnAllClear = (gcnew System::Windows::Forms::Button());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->groupBoxOperation = (gcnew System::Windows::Forms::GroupBox());
			this->btnShowHistgram = (gcnew System::Windows::Forms::Button());
			this->btnSaveImage = (gcnew System::Windows::Forms::Button());
			this->btnFileSelect = (gcnew System::Windows::Forms::Button());
			this->toolTipBtnSaveImage = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTipBtnShowHistgram = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->menuMain = (gcnew System::Windows::Forms::MenuStrip());
			this->fileFToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->endXToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingOToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->imageProcessingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBoxProcessingInfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxStatus))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAfter))->BeginInit();
			this->groupBoxImageOutput->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderThresh))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOriginal))->BeginInit();
			this->groupBoxOperation->SuspendLayout();
			this->menuMain->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelTime
			// 
			this->labelTime->AutoSize = true;
			this->labelTime->Location = System::Drawing::Point(37, 32);
			this->labelTime->Name = L"labelTime";
			this->labelTime->Size = System::Drawing::Size(52, 21);
			this->labelTime->TabIndex = 3;
			this->labelTime->Text = L"Time";
			// 
			// labelTimeUnit
			// 
			this->labelTimeUnit->AutoSize = true;
			this->labelTimeUnit->Location = System::Drawing::Point(208, 63);
			this->labelTimeUnit->Name = L"labelTimeUnit";
			this->labelTimeUnit->Size = System::Drawing::Size(35, 21);
			this->labelTimeUnit->TabIndex = 5;
			this->labelTimeUnit->Text = L"ms";
			// 
			// groupBoxProcessingInfo
			// 
			this->groupBoxProcessingInfo->Controls->Add(this->labelTime);
			this->groupBoxProcessingInfo->Controls->Add(this->labelTimeUnit);
			this->groupBoxProcessingInfo->Controls->Add(this->textBoxTime);
			this->groupBoxProcessingInfo->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->groupBoxProcessingInfo->Location = System::Drawing::Point(12, 464);
			this->groupBoxProcessingInfo->Name = L"groupBoxProcessingInfo";
			this->groupBoxProcessingInfo->Size = System::Drawing::Size(249, 113);
			this->groupBoxProcessingInfo->TabIndex = 4;
			this->groupBoxProcessingInfo->TabStop = false;
			this->groupBoxProcessingInfo->Text = L"Processing Infomation";
			// 
			// textBoxTime
			// 
			this->textBoxTime->Location = System::Drawing::Point(41, 56);
			this->textBoxTime->Name = L"textBoxTime";
			this->textBoxTime->ReadOnly = true;
			this->textBoxTime->Size = System::Drawing::Size(154, 28);
			this->textBoxTime->TabIndex = 4;
			this->textBoxTime->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// pictureBoxStatus
			// 
			this->pictureBoxStatus->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxStatus.Image")));
			this->pictureBoxStatus->Location = System::Drawing::Point(696, 180);
			this->pictureBoxStatus->Name = L"pictureBoxStatus";
			this->pictureBoxStatus->Size = System::Drawing::Size(202, 200);
			this->pictureBoxStatus->TabIndex = 7;
			this->pictureBoxStatus->TabStop = false;
			// 
			// labelAfterImage
			// 
			this->labelAfterImage->AutoSize = true;
			this->labelAfterImage->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelAfterImage->Location = System::Drawing::Point(536, 35);
			this->labelAfterImage->Name = L"labelAfterImage";
			this->labelAfterImage->Size = System::Drawing::Size(111, 21);
			this->labelAfterImage->TabIndex = 1;
			this->labelAfterImage->Text = L"After Image";
			// 
			// pictureBoxAfter
			// 
			this->pictureBoxAfter->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBoxAfter->Location = System::Drawing::Point(540, 63);
			this->pictureBoxAfter->Name = L"pictureBoxAfter";
			this->pictureBoxAfter->Size = System::Drawing::Size(498, 456);
			this->pictureBoxAfter->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxAfter->TabIndex = 6;
			this->pictureBoxAfter->TabStop = false;
			// 
			// labelOriginalImage
			// 
			this->labelOriginalImage->AutoSize = true;
			this->labelOriginalImage->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelOriginalImage->Location = System::Drawing::Point(19, 35);
			this->labelOriginalImage->Name = L"labelOriginalImage";
			this->labelOriginalImage->Size = System::Drawing::Size(132, 21);
			this->labelOriginalImage->TabIndex = 0;
			this->labelOriginalImage->Text = L"Original Image";
			// 
			// groupBoxImageOutput
			// 
			this->groupBoxImageOutput->Controls->Add(this->labelThresh);
			this->groupBoxImageOutput->Controls->Add(this->labelValue);
			this->groupBoxImageOutput->Controls->Add(this->sliderThresh);
			this->groupBoxImageOutput->Controls->Add(this->pictureBoxStatus);
			this->groupBoxImageOutput->Controls->Add(this->labelAfterImage);
			this->groupBoxImageOutput->Controls->Add(this->pictureBoxAfter);
			this->groupBoxImageOutput->Controls->Add(this->labelOriginalImage);
			this->groupBoxImageOutput->Controls->Add(this->pictureBoxOriginal);
			this->groupBoxImageOutput->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->groupBoxImageOutput->Location = System::Drawing::Point(267, 38);
			this->groupBoxImageOutput->Name = L"groupBoxImageOutput";
			this->groupBoxImageOutput->Size = System::Drawing::Size(1065, 539);
			this->groupBoxImageOutput->TabIndex = 5;
			this->groupBoxImageOutput->TabStop = false;
			this->groupBoxImageOutput->Text = L"Image Output";
			// 
			// labelThresh
			// 
			this->labelThresh->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelThresh->Location = System::Drawing::Point(654, 28);
			this->labelThresh->Name = L"labelThresh";
			this->labelThresh->Size = System::Drawing::Size(150, 28);
			this->labelThresh->TabIndex = 13;
			this->labelThresh->Text = L"Threshold( 0 - 255 )";
			this->labelThresh->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelValue
			// 
			this->labelValue->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelValue->Location = System::Drawing::Point(999, 28);
			this->labelValue->Name = L"labelValue";
			this->labelValue->Size = System::Drawing::Size(40, 28);
			this->labelValue->TabIndex = 12;
			this->labelValue->Text = L"0";
			this->labelValue->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// sliderThresh
			// 
			this->sliderThresh->AutoSize = false;
			this->sliderThresh->LargeChange = 1;
			this->sliderThresh->Location = System::Drawing::Point(810, 30);
			this->sliderThresh->Maximum = 255;
			this->sliderThresh->Name = L"sliderThresh";
			this->sliderThresh->Size = System::Drawing::Size(183, 28);
			this->sliderThresh->TabIndex = 11;
			this->sliderThresh->Scroll += gcnew System::EventHandler(this, &FormMain::OnScrollSliderThresh);
			this->sliderThresh->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FormMain::OnSliderPreviewKeyUp);
			this->sliderThresh->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FormMain::OnSliderMouseUp);
			// 
			// pictureBoxOriginal
			// 
			this->pictureBoxOriginal->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBoxOriginal->Location = System::Drawing::Point(23, 63);
			this->pictureBoxOriginal->Name = L"pictureBoxOriginal";
			this->pictureBoxOriginal->Size = System::Drawing::Size(498, 456);
			this->pictureBoxOriginal->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxOriginal->TabIndex = 4;
			this->pictureBoxOriginal->TabStop = false;
			// 
			// btnStop
			// 
			this->btnStop->BackColor = System::Drawing::Color::White;
			this->btnStop->Enabled = false;
			this->btnStop->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnStop->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->btnStop->Location = System::Drawing::Point(31, 223);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(192, 40);
			this->btnStop->TabIndex = 4;
			this->btnStop->Text = L"Stop";
			this->btnStop->UseVisualStyleBackColor = false;
			this->btnStop->Click += gcnew System::EventHandler(this, &FormMain::OnClickBtnStop);
			// 
			// btnAllClear
			// 
			this->btnAllClear->BackColor = System::Drawing::Color::White;
			this->btnAllClear->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnAllClear->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->btnAllClear->Location = System::Drawing::Point(31, 106);
			this->btnAllClear->Name = L"btnAllClear";
			this->btnAllClear->Size = System::Drawing::Size(192, 40);
			this->btnAllClear->TabIndex = 1;
			this->btnAllClear->Text = L"All Clear";
			this->btnAllClear->UseVisualStyleBackColor = false;
			this->btnAllClear->Click += gcnew System::EventHandler(this, &FormMain::OnClickBtnAllClear);
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::Color::White;
			this->btnStart->Enabled = false;
			this->btnStart->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnStart->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->btnStart->Location = System::Drawing::Point(31, 164);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(192, 40);
			this->btnStart->TabIndex = 2;
			this->btnStart->Text = L"Start\r\n";
			this->btnStart->UseVisualStyleBackColor = false;
			this->btnStart->Click += gcnew System::EventHandler(this, &FormMain::OnClickBtnStart);
			// 
			// groupBoxOperation
			// 
			this->groupBoxOperation->Controls->Add(this->btnShowHistgram);
			this->groupBoxOperation->Controls->Add(this->btnSaveImage);
			this->groupBoxOperation->Controls->Add(this->btnStop);
			this->groupBoxOperation->Controls->Add(this->btnAllClear);
			this->groupBoxOperation->Controls->Add(this->btnStart);
			this->groupBoxOperation->Controls->Add(this->btnFileSelect);
			this->groupBoxOperation->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->groupBoxOperation->Location = System::Drawing::Point(12, 38);
			this->groupBoxOperation->Name = L"groupBoxOperation";
			this->groupBoxOperation->Size = System::Drawing::Size(249, 408);
			this->groupBoxOperation->TabIndex = 3;
			this->groupBoxOperation->TabStop = false;
			this->groupBoxOperation->Text = L"Operation";
			// 
			// btnShowHistgram
			// 
			this->btnShowHistgram->BackColor = System::Drawing::Color::White;
			this->btnShowHistgram->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnShowHistgram->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->btnShowHistgram->Location = System::Drawing::Point(31, 340);
			this->btnShowHistgram->Name = L"btnShowHistgram";
			this->btnShowHistgram->Size = System::Drawing::Size(192, 40);
			this->btnShowHistgram->TabIndex = 6;
			this->btnShowHistgram->Text = L"Show Histgram...";
			this->btnShowHistgram->UseVisualStyleBackColor = false;
			this->btnShowHistgram->Click += gcnew System::EventHandler(this, &FormMain::OnClickBtnShowHistgram);
			// 
			// btnSaveImage
			// 
			this->btnSaveImage->BackColor = System::Drawing::Color::White;
			this->btnSaveImage->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSaveImage->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->btnSaveImage->Location = System::Drawing::Point(31, 282);
			this->btnSaveImage->Name = L"btnSaveImage";
			this->btnSaveImage->Size = System::Drawing::Size(192, 40);
			this->btnSaveImage->TabIndex = 5;
			this->btnSaveImage->Text = L"Save Image...";
			this->btnSaveImage->UseVisualStyleBackColor = false;
			this->btnSaveImage->Click += gcnew System::EventHandler(this, &FormMain::OnClickBtnSaveImage);
			// 
			// btnFileSelect
			// 
			this->btnFileSelect->BackColor = System::Drawing::Color::White;
			this->btnFileSelect->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnFileSelect->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->btnFileSelect->Location = System::Drawing::Point(31, 50);
			this->btnFileSelect->Name = L"btnFileSelect";
			this->btnFileSelect->Size = System::Drawing::Size(192, 40);
			this->btnFileSelect->TabIndex = 0;
			this->btnFileSelect->Text = L"File Select...";
			this->btnFileSelect->UseVisualStyleBackColor = false;
			this->btnFileSelect->Click += gcnew System::EventHandler(this, &FormMain::OnClickBtnFileSelect);
			// 
			// menuMain
			// 
			this->menuMain->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileFToolStripMenuItem,
					this->settingOToolStripMenuItem
			});
			this->menuMain->Location = System::Drawing::Point(0, 0);
			this->menuMain->Name = L"menuMain";
			this->menuMain->Size = System::Drawing::Size(1344, 24);
			this->menuMain->TabIndex = 6;
			this->menuMain->Text = L"menuStrip1";
			// 
			// fileFToolStripMenuItem
			// 
			this->fileFToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->endXToolStripMenuItem });
			this->fileFToolStripMenuItem->Name = L"fileFToolStripMenuItem";
			this->fileFToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->fileFToolStripMenuItem->Text = L"File(&F)";
			// 
			// endXToolStripMenuItem
			// 
			this->endXToolStripMenuItem->Name = L"endXToolStripMenuItem";
			this->endXToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->endXToolStripMenuItem->Text = L"End(&X)";
			this->endXToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::OnClickMenu);
			// 
			// settingOToolStripMenuItem
			// 
			this->settingOToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->imageProcessingToolStripMenuItem });
			this->settingOToolStripMenuItem->Name = L"settingOToolStripMenuItem";
			this->settingOToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->settingOToolStripMenuItem->Text = L"Setting(&O)";
			// 
			// imageProcessingToolStripMenuItem
			// 
			this->imageProcessingToolStripMenuItem->Name = L"imageProcessingToolStripMenuItem";
			this->imageProcessingToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->imageProcessingToolStripMenuItem->Text = L"Image Processing";
			this->imageProcessingToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::OnClickMenu);
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(1344, 611);
			this->Controls->Add(this->groupBoxProcessingInfo);
			this->Controls->Add(this->groupBoxImageOutput);
			this->Controls->Add(this->groupBoxOperation);
			this->Controls->Add(this->menuMain);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuMain;
			this->MaximizeBox = false;
			this->Name = L"FormMain";
			this->Text = L"Image Processing";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormMain::OnFormClosingFormMain);
			this->groupBoxProcessingInfo->ResumeLayout(false);
			this->groupBoxProcessingInfo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxStatus))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAfter))->EndInit();
			this->groupBoxImageOutput->ResumeLayout(false);
			this->groupBoxImageOutput->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderThresh))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOriginal))->EndInit();
			this->groupBoxOperation->ResumeLayout(false);
			this->menuMain->ResumeLayout(false);
			this->menuMain->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			/// <summary>
			/// ビットマップ
			/// </summary>
			Bitmap^ mBitmap;

			/// <summary>
			/// 画像処理実行用の情報
			/// </summary>
			ImageProcessing^ mImageProcessing;

			/// <summary>
			/// オープンしている画像のファイル名称
			/// </summary>
			String^ mOpenFileName;

			/// <summary>
			/// キャンセルトークン
			/// </summary>
			CancellationTokenSource^ mTokenSource;

			/// <summary>
			/// 現在選択中の画像処理の名称
			/// </summary>
			String^ mCurrentImageProcessingName;

			/// <summary>
			/// ヒストグラム用のデータ
			/// </summary>
			FormHistgram^ mHistgram;
		public:
			/// <summary>
			/// ビットマップを取得する
			/// </summary>
			/// <returns>ビットマップ</returns>
			Bitmap^ GetBitmap();

			/// <summary>
			/// 対象の画像処理オブジェクトを実行する
			/// </summary>
			/// <param name="comImageProcessingInfo">画像処理の設定</param>
			/// <param name="token">キャンセルトークン</param>
			/// <returns>画像処理の実行結果 成功/失敗</returns>
			bool GoImageProcessing(ComImgInfo^ comImageProcessingInfo, CancellationToken^ token);

			/// <summary>
			/// ツールチップの設定
			/// </summary>
			void SetToolTip(void);

			/// <summary>
			/// ボタンのEnableを制御する
			/// </summary>
			void SetButtonEnable(void);

			/// <summary>
			/// 時間を表示するテキストボックスに時間を設定する
			/// </summary>
			/// <param name="time">時間</param>
			void SetTextTime(long long time);

			/// <summary>
			/// コントロールのEnableを制御する
			/// </summary>
			void SetControlEnable(void);

			/// <summary>
			/// 画像処理実行用のタスク
			/// </summary>
			void ExecTaskImageProcessing(void);

			/// <summary>
			/// 画像処理のタスク実行
			/// </summary>
			void TaskWorkImageProcessing(void);

			/// <summary>
			/// イメージのロード処理
			/// </summary>
			void LoadImage(void);

			/// <summary>
			/// Formのクローズイベント
			/// </summary>
			/// <param name="sender">オブジェクト</param>
			/// <param name="e">FormClosingイベントのデータ</param>
			void OnFormClosingFormMain(Object^ sender, FormClosingEventArgs^ e);

			/// <summary>
			/// ファイル選択ボタンのクリックイベント
			/// </summary>
			/// <param name="sender">オブジェクト</param>
			/// <param name="e">イベントのデータ</param>
			void OnClickBtnFileSelect(Object^ sender, EventArgs^ e);

			/// <summary>
			/// オールクリアボタンのクリックイベント
			/// </summary>
			/// <param name="sender">オブジェクト</param>
			/// <param name="e">イベントのデータ</param>
			void OnClickBtnAllClear(Object^ sender, EventArgs^ e);

			/// <summary>
			/// スタートボタンのクリックイベント
			/// </summary>
			/// <param name="sender">オブジェクト</param>
			/// <param name="e">イベントのデータ</param>
			void OnClickBtnStart(Object^ sender, EventArgs^ e);

			/// <summary>
			/// ストップボタンのクリックイベント
			/// </summary>
			/// <param name="sender">オブジェクト</param>
			/// <param name="e">イベントのデータ</param>
			void OnClickBtnStop(Object^ sender, EventArgs^ e);

			/// <summary>
			/// 画像処理のオブジェクトからイメージの取得
			/// </summary>
			/// <param name="_strImgName">画像処理の名称</param>
			/// <returns>ビットマップ</returns>
			Bitmap^ GetImage();

			/// <summary>
			/// イメージの保存ボタンのクリックイベント
			/// </summary>
			/// <param name="sender">オブジェクト</param>
			/// <param name="e">イベントのデータ</param>
			void OnClickBtnSaveImage(Object^ sender, EventArgs^ e);

			/// <summary>
			/// ヒストグラム表示ボタンのクリックイベント
			/// </summary>
			/// <param name="sender">オブジェクト</param>
			/// <param name="e">イベントのデータ</param>
			void OnClickBtnShowHistgram(Object^ sender, EventArgs^ e);

			/// <summary>
			/// メニューのクリックイベント
			/// </summary>
			/// <param name="sender">オブジェクト</param>
			/// <param name="e">イベントのデータ</param>
			void OnClickMenu(System::Object^ sender, System::EventArgs^ e);

			/// <summary>
			/// 設定画面の処理
			/// </summary>
			void ShowSettingImageProcessing(void);

			/// <summary>
			/// 2値化の閾値のスライダのスクロールイベント
			/// </summary>
			/// <param name="sender">オブジェクト</param>
			/// <param name="e">イベントのデータ</param>
			void OnScrollSliderThresh(System::Object^ sender, System::EventArgs^ e);

			/// <summary>
			/// 2値化の閾値のスライダのキーアップイベント
			/// </summary>
			/// <param name="sender">オブジェクト</param>
			/// <param name="e">キーイベントのデータ</param>
			void OnSliderPreviewKeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);

			/// <summary>
			/// 2値化の閾値のスライダのマウスアップイベント
			/// </summary>
			/// <param name="sender">オブジェクト</param>
			/// <param name="e">マウスボタンイベントのデータ</param>
			void OnSliderMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			/// <summary>
			/// 2値化のスライダを調整したときの処理
			/// </summary>
			void ExecParamAjust(void);

			/// <summary>
			/// 2値化のスライダを調整したときの処理
			/// </summary>
			void ParamAjust(void);

			/// <summary>
			/// 画像処理中に表示させる画像の表示/非表示の設定
			/// </summary>
			/// <param name="value">表示/非表示</param>
			void SetPictureBoxStatusVisible(bool value) { pictureBoxStatus->Visible = value; };

			/// <summary>
			/// 選択ボタンの有効/無効の設定
			/// </summary>
			/// <param name="value">有効/無効</param>
			void SetBtnFileSelectEnable(bool value) { btnFileSelect->Enabled = value; };

			/// <summary>
			/// 全てクリアボタンの有効/無効の設定
			/// </summary>
			/// <param name="value">有効/無効</param>
			void SetBtnAllClearEnable(bool value) { btnAllClear->Enabled = value; };

			/// <summary>
			/// スタートボタンの有効/無効の設定
			/// </summary>
			/// <param name="value">有効/無効</param>
			void SetBtnStartEnable(bool value) { btnStart->Enabled = value; };

			/// <summary>
			/// ストップボタンの有効/無効の設定
			/// </summary>
			/// <param name="value">有効/無効</param>
			void SetBtnStopEnable(bool value) { btnStop->Enabled = value; };

			/// <summary>
			/// 画像保存ボタンの有効/無効の設定
			/// </summary>
			/// <param name="value">有効/無効</param>
			void SetBtnSaveImageEnable(bool value) { btnSaveImage->Enabled = value; };

			/// <summary>
			/// ヒストグラム表示ボタンの有効/無効の設定
			/// </summary>
			/// <param name="value">有効/無効</param>
			void SetBtnShowHistgramEnable(bool value) { btnShowHistgram->Enabled = value; };

			/// <summary>
			/// メインメニューの有効/無効の設定
			/// </summary>
			/// <param name="value">有効/無効</param>
			void SetMenuMainEnable(bool value) { menuMain->Enabled = value; };

			/// <summary>
			/// 閾値のスライダの有効/無効の設定
			/// </summary>
			/// <param name="value">有効/無効</param>
			void SetSliderThreshEnable(bool value) { sliderThresh->Enabled = value; };

			/// <summary>
			/// 閾値のスライダの値の取得
			/// </summary>
			/// <returns>閾値のスライダの値</returns>
			Byte GetSliderThresh(void) { return (Byte)sliderThresh->Value; };
	};
};