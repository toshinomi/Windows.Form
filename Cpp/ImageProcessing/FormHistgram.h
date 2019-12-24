#pragma once

namespace ImageProcessing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// FormHistgram �̊T�v
	/// </summary>
	public ref class FormHistgram : public System::Windows::Forms::Form
	{
	public:
		FormHistgram(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
			chart->ContextMenuStrip = contextMenu;
			m_chartArea = gcnew ChartArea();
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~FormHistgram()
		{
			if (components)
			{
				delete components;
			}
			if (m_nHistgram != nullptr)
			{
				for (int i = 0; i < 2; i++)
				{
					delete[] m_nHistgram[i];
				}
				delete[] m_nHistgram;
				m_nHistgram = nullptr;
			}
			delete m_seriesLineOriginal;
			delete m_seriesLineAfter;
			delete m_chartArea;
			m_seriesLineOriginal = nullptr;
			m_seriesLineAfter = nullptr;
			m_chartArea = nullptr;
			m_bIsOpen = false;
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ saveCsvToolStripMenuItem;
	private: System::ComponentModel::IContainer^ components;
	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormHistgram::typeid));
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->contextMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->saveCsvToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->contextMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart
			// 
			this->chart->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->chart->BackColor = System::Drawing::Color::LightSteelBlue;
			this->chart->BackImageTransparentColor = System::Drawing::Color::White;
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(12, 12);
			this->chart->Name = L"chart";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart->Series->Add(series1);
			this->chart->Size = System::Drawing::Size(776, 426);
			this->chart->TabIndex = 0;
			this->chart->Text = L"chart1";
			// 
			// contextMenu
			// 
			this->contextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->saveCsvToolStripMenuItem });
			this->contextMenu->Name = L"contextMenu";
			this->contextMenu->Size = System::Drawing::Size(128, 26);
			// 
			// saveCsvToolStripMenuItem
			// 
			this->saveCsvToolStripMenuItem->Name = L"saveCsvToolStripMenuItem";
			this->saveCsvToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			this->saveCsvToolStripMenuItem->Text = L"Save Csv...";
			this->saveCsvToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormHistgram::OnClickMenu);
			// 
			// FormHistgram
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(800, 450);
			this->Controls->Add(this->chart);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FormHistgram";
			this->Text = L"Histgram";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->contextMenu->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		/// <summary>
		/// �q�X�g�O�����f�[�^
		/// </summary>
		int** m_nHistgram;

		/// <summary>
		/// �I���W�i���̃r�b�g�}�b�v
		/// </summary>
		Bitmap^ m_bitmapOrg;

		/// <summary>
		/// �摜������̃r�b�g�}�b�v
		/// </summary>
		Bitmap^ m_bitmapAfter;

		/// <summary>
		/// �I�[�v�����
		/// </summary>
		bool m_bIsOpen;

		/// <summary>
		/// �I���W�i���̃q�X�g�O�����̃f�[�^
		/// </summary>
		Series^ m_seriesLineOriginal;

		/// <summary>
		/// �摜������̃q�X�g�O�����̃f�[�^
		/// </summary>
		Series^ m_seriesLineAfter;

		/// <summary>
		/// �O���t�G���A
		/// </summary>
		ChartArea^ m_chartArea;
	public:
		/// <summary>
		/// �I���W�i���̃r�b�g�}�b�v�̎擾
		/// </summary>
		/// <returns>�r�b�g�}�b�v</returns>
		Bitmap^ GetBitmapOrg(void) { return m_bitmapOrg; };

		/// <summary>
		/// �I���W�i���̃r�b�g�}�b�v�̐ݒ�
		/// </summary>
		/// <param name="_bitmap">�r�b�g�}�b�v</param>
		void SetBitmapOrg(Bitmap^ _bitmap) { m_bitmapOrg = _bitmap; }

		/// <summary>
		/// �摜������̃r�b�g�}�b�v�̎擾
		/// </summary>
		/// <returns>�r�b�g�}�b�v</returns>
		Bitmap^ GetBitmapAfter(void) { return m_bitmapAfter; };

		/// <summary>
		/// �I���W�i���̃r�b�g�}�b�v�̐ݒ�
		/// </summary>
		/// <param name="_bitmap">�r�b�g�}�b�v</param>
		void SetBitmapAfter(Bitmap^ _bitmap) { m_bitmapAfter = _bitmap; }

		/// <summary>
		/// �q�X�g�O������ʂ̃I�[�v����Ԃ̎擾
		/// </summary>
		/// <returns>�q�X�g�O������ʂ̃I�[�v�����</returns>
		bool GetIsOpen(void) { return m_bIsOpen; };

		/// <summary>
		/// �q�X�g�O������ʂ̃I�[�v����Ԃ̐ݒ�
		/// </summary>
		/// <param name="_isOpen">�X�g�O������ʂ̃I�[�v�����</param>
		void SetIsOpen(bool _isOpen) { m_bIsOpen = _isOpen; };

		/// <summary>
		/// �I���W�i���̃q�X�g�O�����̃f�[�^���̎擾
		/// </summary>
		/// <returns>�I���W�i���̃q�X�g�O�����̃f�[�^���</returns>
		Series^ GetSeriesLineOriginal(void) { return m_seriesLineOriginal; };

		/// <summary>
		/// �I���W�i���̃q�X�g�O�����̃f�[�^���̐ݒ�
		/// </summary>
		/// <param name="_series">�I���W�i���̃q�X�g�O�����̃f�[�^���</param>
		void SetSeriesLineOriginal(Series^ _series) { m_seriesLineOriginal = _series; };

		/// <summary>
		/// �摜������̃q�X�g�O�����̃f�[�^���̎擾
		/// </summary>
		/// <returns>�摜������̃q�X�g�O�����̃f�[�^���</returns>
		Series^ GetSeriesLineAfter(void) { return m_seriesLineAfter; };

		/// <summary>
		/// �摜������̃q�X�g�O�����̃f�[�^���̐ݒ�
		/// </summary>
		/// <param name="_series">�摜������̃q�X�g�O�����̃f�[�^���</param>
		void SetSeriesLineAfter(Series^ _series) { m_seriesLineAfter = _series; };

		/// <summary>
		/// �O���t�̕`��
		/// </summary>
		void DrawHistgram(void);

		/// <summary>
		/// �C���[�W����q�X�g�O�����p�̃f�[�^�Z�o
		/// </summary>
		void CalHistgram(void);

		/// <summary>
		/// �q�X�g�O�����p�̃f�[�^������
		/// </summary>
		void InitHistgram(void);

		/// <summary>
		/// ���j���[�̃N���b�N
		/// </summary>
		/// <param name="sender">�I�u�W�F�N�g</param>
		/// <param name="e">�C�x���g�̃f�[�^</param>
		void OnClickMenu(System::Object^ sender, System::EventArgs^ e);

		/// <summary>
		/// CSV�t�@�C���ۑ�
		/// </summary>
		void SaveCsv(void);
	};
}
