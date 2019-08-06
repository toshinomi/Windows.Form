#include "FormSettingImageProcessing.h"

using namespace ImageProcessing;
using namespace System::Configuration;

void FormSettingImageProcessing::LoadParam(void)
{
	System::Collections::Generic::Dictionary<int, String^> items;
	System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);
	items.Add(Convert::ToInt32(config->AppSettings->Settings["ImgTypeEdgeId"]->Value), (String^)config->AppSettings->Settings["ImgTypeEdgeName"]->Value);
	items.Add(Convert::ToInt32(config->AppSettings->Settings["ImgTypeGrayScaleId"]->Value), (String^)config->AppSettings->Settings["ImgTypeGrayScaleName"]->Value);
	items.Add(Convert::ToInt32(config->AppSettings->Settings["ImgTypeBinarizationId"]->Value), (String^)config->AppSettings->Settings["ImgTypeBinarizationName"]->Value);
	items.Add(Convert::ToInt32(config->AppSettings->Settings["ImgTypeGrayScale2DiffId"]->Value), (String^)config->AppSettings->Settings["ImgTypeGrayScale2DiffName"]->Value);
	items.Add(Convert::ToInt32(config->AppSettings->Settings["ImgTypeColorReversalId"]->Value), (String^)config->AppSettings->Settings["ImgTypeColorReversalName"]->Value);

	cmbBoxImageProcessingType->Items->Add((String^)config->AppSettings->Settings["ImgTypeEdgeName"]->Value);
	cmbBoxImageProcessingType->Items->Add((String^)config->AppSettings->Settings["ImgTypeGrayScaleName"]->Value);
	cmbBoxImageProcessingType->Items->Add((String^)config->AppSettings->Settings["ImgTypeBinarizationName"]->Value);
	cmbBoxImageProcessingType->Items->Add((String^)config->AppSettings->Settings["ImgTypeGrayScale2DiffName"]->Value);
	cmbBoxImageProcessingType->Items->Add((String^)config->AppSettings->Settings["ImgTypeColorReversalName"]->Value);

	for each (unsigned int nKey in items.Keys)
	{
		if (items[nKey] == (String^)config->AppSettings->Settings["ImgTypeSelectName"]->Value)
		{
			cmbBoxImageProcessingType->SelectedIndex = nKey - 1;
		}
	}

	return;
}

void FormSettingImageProcessing::SaveParam(void)
{
	System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);
	config->AppSettings->Settings["ImgTypeSelectName"]->Value = (String^)cmbBoxImageProcessingType->SelectedItem;
	config->Save();

	return;
}

void FormSettingImageProcessing::OnClickOk(System::Object^ sender, System::EventArgs^ e)
{
	SaveParam();
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	Close();
}

void FormSettingImageProcessing::OnClickCancel(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	Close();
}