#include "FormHistgram.h"
#include "ComInfo.h"
#include "ComSaveFileDialog.h"
#include <string>

using namespace ImageProcessing;

/// <summary>
/// グラフの描画
/// </summary>
void FormHistgram::DrawHistgram(void)
{
	InitHistgram();

	CalHistgram();

	chart->Titles->Clear();
	chart->Series->Clear();
	chart->ChartAreas->Clear();
	if (mChartArea != nullptr)
	{
		delete mChartArea;
		mChartArea = gcnew ChartArea();
	}
	chart->ChartAreas->Add(mChartArea);
	if (mSeriesLineOriginal != nullptr)
	{
		delete mSeriesLineOriginal;
		mSeriesLineOriginal = nullptr;
	}
	mSeriesLineOriginal = gcnew Series();
	mSeriesLineOriginal->ChartType = SeriesChartType::Line;
	mSeriesLineOriginal->LegendText = "Original";
	mSeriesLineOriginal->BorderWidth = 2;

	if (mSeriesLineAfter != nullptr)
	{
		delete mSeriesLineAfter;
		mSeriesLineAfter = nullptr;
	}
	mSeriesLineAfter = gcnew Series();
	mSeriesLineAfter->ChartType = SeriesChartType::Line;
	mSeriesLineAfter->LegendText = "After";
	mSeriesLineAfter->BorderWidth = 2;
#ifdef DEBUG
	int nHistgram0[ComInfo::RGP_MAX];
	int nHistgram1[ComInfo::RGP_MAX];
	memset(nHistgram0, 0, sizeof(int) * ComInfo::RGP_MAX);
	memset(nHistgram1, 0, sizeof(int) * ComInfo::RGP_MAX);
	memcpy(nHistgram0, m_nHistgram[ComInfo::PictureType::Type::Original], sizeof(int) * ComInfo::RGP_MAX);
	memcpy(nHistgram1, m_nHistgram[ComInfo::PictureType::Type::After], sizeof(int) * ComInfo::RGP_MAX);
#endif // DEBUG
	for (int i = 0; i < ComInfo::RGB_MAX; i++)
	{
		mSeriesLineOriginal->Points->AddXY(i, mHistgram[ComInfo::Picture::Type::Original][i]);
		mSeriesLineAfter->Points->AddXY(i, mHistgram[ComInfo::Picture::Type::After][i]);
	}
	chart->Series->Add(mSeriesLineOriginal);
	chart->Series->Add(mSeriesLineAfter);
}

/// <summary>
/// イメージからヒストグラム用のデータ算出
/// </summary>
void FormHistgram::CalHistgram(void)
{
	int widthSize = mBitmapOrg->Width;
	int heightSize = mBitmapOrg->Height;

	BitmapData^ bitmapDataOrg = mBitmapOrg->LockBits(System::Drawing::Rectangle(0, 0, widthSize, heightSize), ImageLockMode::ReadOnly, PixelFormat::Format32bppArgb);
	BitmapData^ bitmapDataAfter;
	if (mBitmapAfter != nullptr)
	{
		bitmapDataAfter = mBitmapAfter->LockBits(System::Drawing::Rectangle(0, 0, widthSize, heightSize), ImageLockMode::ReadOnly, PixelFormat::Format32bppArgb);
	}

	int indexWidth;
	int indexHeight;

	for (indexHeight = 0; indexHeight < heightSize; indexHeight++)
	{
		for (indexWidth = 0; indexWidth < widthSize; indexWidth++)
		{
			Byte* pixel = (Byte*)bitmapDataOrg->Scan0.ToPointer() + indexHeight * bitmapDataOrg->Stride + indexWidth * 4;
			Byte grayScale = (Byte)((pixel[(int)ComInfo::Pixel::Type::B] + pixel[(int)ComInfo::Pixel::Type::G] + pixel[(int)ComInfo::Pixel::Type::R]) / 3);

			mHistgram[ComInfo::Picture::Type::Original][grayScale] += 1;

			if (mBitmapAfter != nullptr)
			{
				pixel = (Byte*)bitmapDataAfter->Scan0.ToPointer() + indexHeight * bitmapDataAfter->Stride + indexWidth * 4;
				grayScale = (Byte)((pixel[(int)ComInfo::Pixel::Type::B] + pixel[(int)ComInfo::Pixel::Type::G] + pixel[(int)ComInfo::Pixel::Type::R]) / 3);

				mHistgram[ComInfo::Picture::Type::After][grayScale] += 1;
			}
		}
	}
	mBitmapOrg->UnlockBits(bitmapDataOrg);
	if (mBitmapAfter != nullptr)
	{
		mBitmapAfter->UnlockBits(bitmapDataAfter);
	}
}

/// <summary>
/// ヒストグラム用のデータ初期化
/// </summary>
void FormHistgram::InitHistgram(void)
{
	if (mHistgram == nullptr)
	{
		mHistgram = new int* [ComInfo::Picture::Type::MAX];
	}
	for (int index = 0; index < ComInfo::Picture::Type::MAX; index++)
	{
		mHistgram[index] = new int[ComInfo::RGB_MAX];
	}

	for (int index = 0; index < ComInfo::RGB_MAX; index++)
	{
		mHistgram[ComInfo::Picture::Type::Original][index] = 0;
		mHistgram[ComInfo::Picture::Type::After][index] = 0;
	}
}

/// <summary>
/// メニューのクリック
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormHistgram::OnClickMenu(System::Object^ sender, System::EventArgs^ e)
{
	String^ strHeader = sender->ToString();

	if (strHeader == (String^)ComConstStringInfo::MENU_SAVE_CSV)
	{
		SaveCsv();
	}

	return;
}

/// <summary>
/// CSVファイル保存
/// </summary>
void FormHistgram::SaveCsv(void)
{
	ComSaveFileDialog^ saveDialog = gcnew ComSaveFileDialog();
	saveDialog->SetFilter("CSV|*.csv");
	saveDialog->SetTitle("Save the csv file");
	saveDialog->SetFileName("default.csv");
	if (saveDialog->ShowDialog() == true)
	{
		String^ strDelmiter = ",";
		StringBuilder^ stringBuilder = gcnew StringBuilder();
#ifdef DEBUG
		int nHistgram0[ComInfo::RGP_MAX];
		int nHistgram1[ComInfo::RGP_MAX];
		memset(nHistgram0, 0, sizeof(int) * ComInfo::RGP_MAX);
		memset(nHistgram1, 0, sizeof(int) * ComInfo::RGP_MAX);
		memcpy(nHistgram0, m_nHistgram[ComInfo::PictureType::Original], sizeof(int) * ComInfo::RGP_MAX);
		memcpy(nHistgram1, m_nHistgram[ComInfo::PictureType::After], sizeof(int) * ComInfo::RGP_MAX);
#endif // DEBUG
		for (int nIdx = 0; nIdx < ComInfo::RGB_MAX; nIdx++)
		{
			stringBuilder->Append(nIdx)->Append(strDelmiter);
			stringBuilder->Append(mHistgram[ComInfo::Picture::Type::Original][nIdx])->Append(strDelmiter);
			stringBuilder->Append(mHistgram[ComInfo::Picture::Type::After][nIdx])->Append(strDelmiter);
			stringBuilder->Append(Environment::NewLine);
		}
		if (!saveDialog->StreamWrite(stringBuilder->ToString()))
		{
			MessageBox::Show(this, "Save CSV File Error", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		delete stringBuilder;
	}
	delete saveDialog;

	return;
}