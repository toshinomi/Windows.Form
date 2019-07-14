#include "FormSettingImageProcessing.h"

using namespace ImageProcessing;
using namespace System::Configuration;

void FormSettingImageProcessing::SaveParam(void)
{
	//m_items = gcnew List<ComImageProcessingType^>();
	//m_items->Add(gcnew ComImageProcessingType(ImgTypeEdgeId, ImgTypeEdgeName));
	//m_items->Add(gcnew ComImageProcessingType(ImgTypeGrayScaleId, ImgTypeGrayScaleName));
	//m_items.Add(new ComImageProcessingType(Properties.Settings.Default.ImgTypeBinarizationId, Properties.Settings.Default.ImgTypeBinarizationName));
	//m_items.Add(new ComImageProcessingType(Properties.Settings.Default.ImgTypeGrayScale2DiffId, Properties.Settings.Default.ImgTypeGrayScale2DiffName));
	//m_items.Add(new ComImageProcessingType(Properties.Settings.Default.ImgTypeColorReversalId, Properties.Settings.Default.ImgTypeColorReversalName));

	String^ name = ::ConfigurationManager::AppSettings["ImgTypeEdgeId"];
}
