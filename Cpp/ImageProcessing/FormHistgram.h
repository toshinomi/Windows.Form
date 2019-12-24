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
	/// FormHistgram の概要
	/// </summary>
	public ref class FormHistgram : public System::Windows::Forms::Form
	{
	public:
		FormHistgram(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			chart->ContextMenuStrip = contextMenu;
			m_chartArea = gcnew ChartArea();
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
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
		/// ヒストグラムデータ
		/// </summary>
		int** m_nHistgram;

		/// <summary>
		/// オリジナルのビットマップ
		/// </summary>
		Bitmap^ m_bitmapOrg;

		/// <summary>
		/// 画像処理後のビットマップ
		/// </summary>
		Bitmap^ m_bitmapAfter;

		/// <summary>
		/// オープン状態
		/// </summary>
		bool m_bIsOpen;

		/// <summary>
		/// オリジナルのヒストグラムのデータ
		/// </summary>
		Series^ m_seriesLineOriginal;

		/// <summary>
		/// 画像処理後のヒストグラムのデータ
		/// </summary>
		Series^ m_seriesLineAfter;

		/// <summary>
		/// グラフエリア
		/// </summary>
		ChartArea^ m_chartArea;
	public:
		/// <summary>
		/// オリジナルのビットマップの取得
		/// </summary>
		/// <returns>ビットマップ</returns>
		Bitmap^ GetBitmapOrg(void) { return m_bitmapOrg; };

		/// <summary>
		/// オリジナルのビットマップの設定
		/// </summary>
		/// <param name="_bitmap">ビットマップ</param>
		void SetBitmapOrg(Bitmap^ _bitmap) { m_bitmapOrg = _bitmap; }

		/// <summary>
		/// 画像処理後のビットマップの取得
		/// </summary>
		/// <returns>ビットマップ</returns>
		Bitmap^ GetBitmapAfter(void) { return m_bitmapAfter; };

		/// <summary>
		/// オリジナルのビットマップの設定
		/// </summary>
		/// <param name="_bitmap">ビットマップ</param>
		void SetBitmapAfter(Bitmap^ _bitmap) { m_bitmapAfter = _bitmap; }

		/// <summary>
		/// ヒストグラム画面のオープン状態の取得
		/// </summary>
		/// <returns>ヒストグラム画面のオープン状態</returns>
		bool GetIsOpen(void) { return m_bIsOpen; };

		/// <summary>
		/// ヒストグラム画面のオープン状態の設定
		/// </summary>
		/// <param name="_isOpen">ストグラム画面のオープン状態</param>
		void SetIsOpen(bool _isOpen) { m_bIsOpen = _isOpen; };

		/// <summary>
		/// オリジナルのヒストグラムのデータ情報の取得
		/// </summary>
		/// <returns>オリジナルのヒストグラムのデータ情報</returns>
		Series^ GetSeriesLineOriginal(void) { return m_seriesLineOriginal; };

		/// <summary>
		/// オリジナルのヒストグラムのデータ情報の設定
		/// </summary>
		/// <param name="_series">オリジナルのヒストグラムのデータ情報</param>
		void SetSeriesLineOriginal(Series^ _series) { m_seriesLineOriginal = _series; };

		/// <summary>
		/// 画像処理後のヒストグラムのデータ情報の取得
		/// </summary>
		/// <returns>画像処理後のヒストグラムのデータ情報</returns>
		Series^ GetSeriesLineAfter(void) { return m_seriesLineAfter; };

		/// <summary>
		/// 画像処理後のヒストグラムのデータ情報の設定
		/// </summary>
		/// <param name="_series">画像処理後のヒストグラムのデータ情報</param>
		void SetSeriesLineAfter(Series^ _series) { m_seriesLineAfter = _series; };

		/// <summary>
		/// グラフの描画
		/// </summary>
		void DrawHistgram(void);

		/// <summary>
		/// イメージからヒストグラム用のデータ算出
		/// </summary>
		void CalHistgram(void);

		/// <summary>
		/// ヒストグラム用のデータ初期化
		/// </summary>
		void InitHistgram(void);

		/// <summary>
		/// メニューのクリック
		/// </summary>
		/// <param name="sender">オブジェクト</param>
		/// <param name="e">イベントのデータ</param>
		void OnClickMenu(System::Object^ sender, System::EventArgs^ e);

		/// <summary>
		/// CSVファイル保存
		/// </summary>
		void SaveCsv(void);
	};
}
