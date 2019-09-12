#include "FormSettingImageProcessing.h"
#include "ComInfo.h"

using namespace ImageProcessing;
using namespace System::Configuration;

void FormSettingImageProcessing::LoadParam(void)
{
	System::Collections::Generic::Dictionary<int, String^> items;
	System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);
	items.Add(Convert::ToInt32(config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_EDGE_ID]->Value), (String^)config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_EDGE_NAME]->Value);
	items.Add(Convert::ToInt32(config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_GRAY_SCALE_ID]->Value), (String^)config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_GRAY_SCALE_NAME]->Value);
	items.Add(Convert::ToInt32(config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_BINARIZATION_ID]->Value), (String^)config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_BINARIZATION_NAME]->Value);
	items.Add(Convert::ToInt32(config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_GRAY_SCALE_2DIFF_ID]->Value), (String^)config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_GRAY_SCALE_2DIFF_NAME]->Value);
	items.Add(Convert::ToInt32(config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_COLOR_REVERSAL_ID]->Value), (String^)config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_COLOR_REVERSAL_NAME]->Value);

	cmbBoxImageProcessingType->Items->Add((String^)config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_EDGE_NAME]->Value);
	cmbBoxImageProcessingType->Items->Add((String^)config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_GRAY_SCALE_NAME]->Value);
	cmbBoxImageProcessingType->Items->Add((String^)config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_BINARIZATION_NAME]->Value);
	cmbBoxImageProcessingType->Items->Add((String^)config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_GRAY_SCALE_2DIFF_NAME]->Value);
	cmbBoxImageProcessingType->Items->Add((String^)config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_COLOR_REVERSAL_NAME]->Value);

	for each (unsigned int nKey in items.Keys)
	{
		if (items[nKey] == (String^)config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_SELECT_NAME]->Value)
		{
			cmbBoxImageProcessingType->SelectedIndex = nKey - 1;
		}
	}

	return;
}

void FormSettingImageProcessing::SaveParam(void)
{
	System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);
	config->AppSettings->Settings[(String^)ComConstStringInfo::IMG_TYPE_SELECT_NAME]->Value = (String^)cmbBoxImageProcessingType->SelectedItem;
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