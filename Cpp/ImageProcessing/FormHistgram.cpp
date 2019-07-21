#include "FormHistgram.h"
#include "ComInfo.h"
#include "ComSaveFileDialog.h"
#include <string>

using namespace ImageProcessing;

void FormHistgram::DrawHistgram(void)
{
	InitHistgram();

	CalHistgram();

	chart->Series->Clear();
	Series^ seriesLine = gcnew Series();
	seriesLine->ChartType = SeriesChartType::Line;
	seriesLine->LegendText = "Original";
	seriesLine->BorderWidth = 2;

	Series^ seriesLine2 = gcnew Series();
	seriesLine2->ChartType = SeriesChartType::Line;
	seriesLine2->LegendText = "After";
	seriesLine2->BorderWidth = 2;
#ifdef DEBUG
	int nHistgram0[256];
	int nHistgram1[256];
	memset(nHistgram0, 0, sizeof(int) * 256);
	memset(nHistgram1, 0, sizeof(int) * 256);
	memcpy(nHistgram0, m_nHistgram[0], sizeof(int) * 256);
	memcpy(nHistgram1, m_nHistgram[1], sizeof(int) * 256);
#endif // DEBUG
	for (int i = 0; i < 256; i++)
	{
		seriesLine->Points->AddXY(i, m_nHistgram[0][i]);
		seriesLine2->Points->AddXY(i, m_nHistgram[1][i]);
	}
	chart->Series->Add(seriesLine);
	chart->Series->Add(seriesLine2);
}

void FormHistgram::CalHistgram(void)
{
	int nWidthSize = m_bitmapOrg->Width;
	int nHeightSize = m_bitmapOrg->Height;

	BitmapData^ bitmapDataOrg = m_bitmapOrg->LockBits(System::Drawing::Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode::ReadOnly, PixelFormat::Format32bppArgb);
	BitmapData^ bitmapDataAfter;
	if (m_bitmapAfter != nullptr)
	{
		bitmapDataAfter = m_bitmapAfter->LockBits(System::Drawing::Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode::ReadOnly, PixelFormat::Format32bppArgb);
	}

	int nIdxWidth;
	int nIdxHeight;

	for (nIdxHeight = 0; nIdxHeight < nHeightSize; nIdxHeight++)
	{
		for (nIdxWidth = 0; nIdxWidth < nWidthSize; nIdxWidth++)
		{
			Byte* pPixel = (Byte*)bitmapDataOrg->Scan0.ToPointer() + nIdxHeight * bitmapDataOrg->Stride + nIdxWidth * 4;
			Byte nGrayScale = (Byte)((pPixel[(int)ComInfo::Pixel::B] + pPixel[(int)ComInfo::Pixel::G] + pPixel[(int)ComInfo::Pixel::R]) / 3);

			m_nHistgram[0][nGrayScale] += 1;

			if (m_bitmapAfter != nullptr)
			{
				pPixel = (Byte*)bitmapDataAfter->Scan0.ToPointer() + nIdxHeight * bitmapDataAfter->Stride + nIdxWidth * 4;
				nGrayScale = (Byte)((pPixel[(int)ComInfo::Pixel::B] + pPixel[(int)ComInfo::Pixel::G] + pPixel[(int)ComInfo::Pixel::R]) / 3);

				m_nHistgram[1][nGrayScale] += 1;
			}
		}
	}
	m_bitmapOrg->UnlockBits(bitmapDataOrg);
	if (m_bitmapAfter != nullptr)
	{
		m_bitmapAfter->UnlockBits(bitmapDataAfter);
	}
}

void FormHistgram::InitHistgram(void)
{
	if (m_nHistgram == nullptr)
	{
		m_nHistgram = new int* [2];
	}
	for (int i = 0; i < 2; i++)
	{
		m_nHistgram[i] = new int[256];
	}

	for (int nIdx = 0; nIdx < 256; nIdx++)
	{
		m_nHistgram[0][nIdx] = 0;
		m_nHistgram[1][nIdx] = 0;
	}
}

void FormHistgram::OnClickMenu(System::Object^ sender, System::EventArgs^ e)
{
	String^ strHeader = sender->ToString();

	if (strHeader == (String^)ComConstStringInfo::MENU_SAVE_CSV)
	{
		SaveCsv();
	}

	return;
}

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
		int nHistgram0[256];
		int nHistgram1[256];
		memset(nHistgram0, 0, sizeof(int) * 256);
		memset(nHistgram1, 0, sizeof(int) * 256);
		memcpy(nHistgram0, m_nHistgram[0], sizeof(int) * 256);
		memcpy(nHistgram1, m_nHistgram[1], sizeof(int) * 256);
#endif // DEBUG
		for (int nIdx = 0; nIdx < 256; nIdx++)
		{
			stringBuilder->Append(nIdx)->Append(strDelmiter);
			stringBuilder->Append(m_nHistgram[0][nIdx])->Append(strDelmiter);
			stringBuilder->Append(m_nHistgram[1][nIdx])->Append(strDelmiter);
			stringBuilder->Append(Environment::NewLine);
		}
		saveDialog->StreamWrite(stringBuilder->ToString());
		delete stringBuilder;
	}
	delete saveDialog;

	return;
}