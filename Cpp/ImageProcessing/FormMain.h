#pragma once
#include "EdgeDetection.h"
#include "GrayScale.h"
#include "Binarization.h"
#include "GrayScale2Diff.h"
#include "ColorReversal.h"
#include "FormHistgram.h"
#include "ComImgInfo.h"
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
	/// FormMain �̊T�v
	/// </summary>
	public ref class FormMain : public System::Windows::Forms::Form
	{
	public:
		FormMain(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
			btnFileSelect->Enabled = true;
			btnAllClear->Enabled = true;
			btnStart->Enabled = false;
			btnStop->Enabled = false;
			btnSaveImage->Enabled = false;

			pictureBoxStatus->Visible = false;

			SetToolTip();

			m_bitmap = nullptr;
			m_tokenSource = nullptr;
			m_imageProcessing = nullptr;

			System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);
			m_strCurImgName = config->AppSettings->Settings["ImgTypeSelectName"]->Value;
			this->Text = "Image Processing ( " + m_strCurImgName + " )";

			sliderThresh->Enabled = m_strCurImgName == (String^)ComConstStringInfo::IMG_NAME_BINARIZATION ? true : false;
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~FormMain()
		{
			if (components)
			{
				delete components;

				delete m_bitmap;
				delete m_tokenSource;
				delete m_imageProcessing;
				delete m_histgram;
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
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
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
			/// �r�b�g�}�b�v
			/// </summary>
			Bitmap^ m_bitmap;

			/// <summary>
			/// �摜�������s�p�̏��
			/// </summary>
			ImageProcessing^ m_imageProcessing;

			/// <summary>
			/// �I�[�v�����Ă���摜�̃t�@�C������
			/// </summary>
			String^ m_strOpenFileName;

			/// <summary>
			/// �L�����Z���g�[�N��
			/// </summary>
			CancellationTokenSource^ m_tokenSource;

			/// <summary>
			/// ���ݑI�𒆂̉摜�����̖���
			/// </summary>
			String^ m_strCurImgName;

			/// <summary>
			/// �q�X�g�O�����p�̃f�[�^
			/// </summary>
			FormHistgram^ m_histgram;
		public:
			/// <summary>
			/// �r�b�g�}�b�v���擾����
			/// </summary>
			/// <returns>�r�b�g�}�b�v</returns>
			Bitmap^ GetBitmap();

			/// <summary>
			/// �Ώۂ̉摜�����I�u�W�F�N�g�����s����
			/// </summary>
			/// <param name="comImgInfo">�摜�����̐ݒ�</param>
			/// <param name="token">�L�����Z���g�[�N��</param>
			/// <returns>�摜�����̎��s���� ����/���s</returns>
			bool GoImageProcessing(ComImgInfo^ _comImgInfo, CancellationToken^ _token);

			/// <summary>
			/// �c�[���`�b�v�̐ݒ�
			/// </summary>
			void SetToolTip(void);

			/// <summary>
			/// �{�^����Enable�𐧌䂷��
			/// </summary>
			void SetButtonEnable(void);

			/// <summary>
			/// ���Ԃ�\������e�L�X�g�{�b�N�X�Ɏ��Ԃ�ݒ肷��
			/// </summary>
			/// <param name="_lTime">����</param>
			void SetTextTime(long long _lTime);

			/// <summary>
			/// �R���g���[����Enable�𐧌䂷��
			/// </summary>
			void SetControlEnable(void);

			/// <summary>
			/// �摜�������s�p�̃^�X�N
			/// </summary>
			void ExecTaskImageProcessing(void);

			/// <summary>
			/// �摜�����̃^�X�N���s
			/// </summary>
			void TaskWorkImageProcessing(void);

			/// <summary>
			/// �C���[�W�̃��[�h����
			/// </summary>
			void LoadImage(void);

			/// <summary>
			/// Form�̃N���[�Y�C�x���g
			/// </summary>
			/// <param name="sender">�I�u�W�F�N�g</param>
			/// <param name="e">FormClosing�C�x���g�̃f�[�^</param>
			void OnFormClosingFormMain(Object^ sender, FormClosingEventArgs^ e);

			/// <summary>
			/// �t�@�C���I���{�^���̃N���b�N�C�x���g
			/// </summary>
			/// <param name="sender">�I�u�W�F�N�g</param>
			/// <param name="e">�C�x���g�̃f�[�^</param>
			void OnClickBtnFileSelect(Object^ sender, EventArgs^ e);

			/// <summary>
			/// �I�[���N���A�{�^���̃N���b�N�C�x���g
			/// </summary>
			/// <param name="sender">�I�u�W�F�N�g</param>
			/// <param name="e">�C�x���g�̃f�[�^</param>
			void OnClickBtnAllClear(Object^ sender, EventArgs^ e);

			/// <summary>
			/// �X�^�[�g�{�^���̃N���b�N�C�x���g
			/// </summary>
			/// <param name="sender">�I�u�W�F�N�g</param>
			/// <param name="e">�C�x���g�̃f�[�^</param>
			void OnClickBtnStart(Object^ sender, EventArgs^ e);

			/// <summary>
			/// �X�g�b�v�{�^���̃N���b�N�C�x���g
			/// </summary>
			/// <param name="sender">�I�u�W�F�N�g</param>
			/// <param name="e">�C�x���g�̃f�[�^</param>
			void OnClickBtnStop(Object^ sender, EventArgs^ e);

			/// <summary>
			/// �摜�����̃I�u�W�F�N�g����C���[�W�̎擾
			/// </summary>
			/// <param name="_strImgName">�摜�����̖���</param>
			/// <returns>�r�b�g�}�b�v</returns>
			Bitmap^ GetImage();

			/// <summary>
			/// �C���[�W�̕ۑ��{�^���̃N���b�N�C�x���g
			/// </summary>
			/// <param name="sender">�I�u�W�F�N�g</param>
			/// <param name="e">�C�x���g�̃f�[�^</param>
			void OnClickBtnSaveImage(Object^ sender, EventArgs^ e);

			/// <summary>
			/// �q�X�g�O�����\���{�^���̃N���b�N�C�x���g
			/// </summary>
			/// <param name="sender">�I�u�W�F�N�g</param>
			/// <param name="e">�C�x���g�̃f�[�^</param>
			void OnClickBtnShowHistgram(Object^ sender, EventArgs^ e);

			/// <summary>
			/// ���j���[�̃N���b�N�C�x���g
			/// </summary>
			/// <param name="sender">�I�u�W�F�N�g</param>
			/// <param name="e">�C�x���g�̃f�[�^</param>
			void OnClickMenu(System::Object^ sender, System::EventArgs^ e);

			/// <summary>
			/// �ݒ��ʂ̏���
			/// </summary>
			void ShowSettingImageProcessing(void);

			/// <summary>
			/// 2�l����臒l�̃X���C�_�̃X�N���[���C�x���g
			/// </summary>
			/// <param name="sender">�I�u�W�F�N�g</param>
			/// <param name="e">�C�x���g�̃f�[�^</param>
			void OnScrollSliderThresh(System::Object^ sender, System::EventArgs^ e);

			/// <summary>
			/// 2�l����臒l�̃X���C�_�̃L�[�A�b�v�C�x���g
			/// </summary>
			/// <param name="sender">�I�u�W�F�N�g</param>
			/// <param name="e">�L�[�C�x���g�̃f�[�^</param>
			void OnSliderPreviewKeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);

			/// <summary>
			/// 2�l����臒l�̃X���C�_�̃}�E�X�A�b�v�C�x���g
			/// </summary>
			/// <param name="sender">�I�u�W�F�N�g</param>
			/// <param name="e">�}�E�X�{�^���C�x���g�̃f�[�^</param>
			void OnSliderMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			/// <summary>
			/// 2�l���̃X���C�_�𒲐������Ƃ��̏���
			/// </summary>
			void ExecParamAjust(void);

			/// <summary>
			/// 2�l���̃X���C�_�𒲐������Ƃ��̏���
			/// </summary>
			void ParamAjust(void);

			/// <summary>
			/// 2�l���̃X���C�_�𒲐������Ƃ��̏���
			/// </summary>
			/// <param name="_strImgName">�摜�����̖���</param>
			/// <returns>�摜������ID</returns>
			int SearchImgTypeId(String^ _strImgName);

			/// <summary>
			/// �摜�������ɕ\��������摜�̕\��/��\���̐ݒ�
			/// </summary>
			/// <param name="_bValue">�\��/��\��</param>
			void SetPictureBoxStatusVisible(bool _bValue) { pictureBoxStatus->Visible = _bValue; };

			/// <summary>
			/// �I���{�^���̗L��/�����̐ݒ�
			/// </summary>
			/// <param name="_bValue">�L��/����</param>
			void SetBtnFileSelectEnable(bool _bValue) { btnFileSelect->Enabled = _bValue; };

			/// <summary>
			/// �S�ăN���A�{�^���̗L��/�����̐ݒ�
			/// </summary>
			/// <param name="_bValue">�L��/����</param>
			void SetBtnAllClearEnable(bool _bValue) { btnAllClear->Enabled = _bValue; };

			/// <summary>
			/// �X�^�[�g�{�^���̗L��/�����̐ݒ�
			/// </summary>
			/// <param name="_bValue">�L��/����</param>
			void SetBtnStartEnable(bool _bValue) { btnStart->Enabled = _bValue; };

			/// <summary>
			/// �X�g�b�v�{�^���̗L��/�����̐ݒ�
			/// </summary>
			/// <param name="_bValue">�L��/����</param>
			void SetBtnStopEnable(bool _bValue) { btnStop->Enabled = _bValue; };

			/// <summary>
			/// �摜�ۑ��{�^���̗L��/�����̐ݒ�
			/// </summary>
			/// <param name="_bValue">�L��/����</param>
			void SetBtnSaveImageEnable(bool _bValue) { btnSaveImage->Enabled = _bValue; };

			/// <summary>
			/// �q�X�g�O�����\���{�^���̗L��/�����̐ݒ�
			/// </summary>
			/// <param name="_bValue">�L��/����</param>
			void SetBtnShowHistgramEnable(bool _bValue) { btnShowHistgram->Enabled = _bValue; };

			/// <summary>
			/// ���C�����j���[�̗L��/�����̐ݒ�
			/// </summary>
			/// <param name="_bValue">�L��/����</param>
			void SetMenuMainEnable(bool _bValue) { menuMain->Enabled = _bValue; };

			/// <summary>
			/// 臒l�̃X���C�_�̗L��/�����̐ݒ�
			/// </summary>
			/// <param name="_bValue">�L��/����</param>
			void SetSliderThreshEnable(bool _bValue) { sliderThresh->Enabled = _bValue; };

			/// <summary>
			/// 臒l�̃X���C�_�̒l�̎擾
			/// </summary>
			/// <returns>臒l�̃X���C�_�̒l</returns>
			Byte GetSliderThresh(void) { return (Byte)sliderThresh->Value; };
	};
};