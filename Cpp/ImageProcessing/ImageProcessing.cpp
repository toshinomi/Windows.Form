#include "ImageProcessing.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="bitmap">�r�b�g�}�b�v</param>
ImageProcessing::ImageProcessing::ImageProcessing(Bitmap^ bitmap) : ComImageProcessing(bitmap)
{
    auto edgeDetection = gcnew EdgeDetection();
    arrayImageProcessing[ComInfo::ImgProc::Type::EdgeDetection] = edgeDetection;
    auto grayScale = gcnew GrayScale();
    arrayImageProcessing[ComInfo::ImgProc::Type::GrayScale] = grayScale;
    auto binarization = gcnew Binarization();
    arrayImageProcessing[ComInfo::ImgProc::Type::Binarization] = binarization;
    auto grayScale2Diff = gcnew GrayScale2Diff();
    arrayImageProcessing[ComInfo::ImgProc::Type::GrayScale2Diff] = grayScale2Diff;
    auto colorReversal = gcnew ColorReversal();
    arrayImageProcessing[ComInfo::ImgProc::Type::ColorReversal] = colorReversal;
}

/// <summary>
/// �f�X�N�g���N�^
/// </summary>
ImageProcessing::ImageProcessing::~ImageProcessing()
{
}

/// <summary>
/// ������
/// </summary>
void ImageProcessing::ImageProcessing::Init(void)
{
    this->Init();
}

/// <summary>
/// �摜�����̎��s
/// </summary>
/// <param name="imageProcessingName">�摜�����I�u�W�F�N�g�̖���</param>
/// <param name="token">�L�����Z���g�[�N��</param>
/// <returns>���s���� ����/���s</returns>
bool ImageProcessing::ImageProcessing::GoImageProcessing(String^ imageProcessingName, CancellationToken^ token)
{
    bool result = false;

    int index;
    if (imageProcessingName == (String^)ComConstStringInfo::IMG_NAME_EDGE_DETECTION)
    {
        index = ComInfo::ImgProc::Type::EdgeDetection;
        auto edgeDetection = (EdgeDetection^)arrayImageProcessing[index];
        result = edgeDetection->ImageProcessing(this->mBitmap, token);
    }
    else if (imageProcessingName == (String^)ComConstStringInfo::IMG_NAME_GRAY_SCALE)
    {
        index = ComInfo::ImgProc::Type::GrayScale;
        auto grayScale = (GrayScale^)arrayImageProcessing[index];
        result = grayScale->ImageProcessing(this->mBitmap, token);
    }
    else if (imageProcessingName == (String^)ComConstStringInfo::IMG_NAME_BINARIZATION)
    {
        index = ComInfo::ImgProc::Type::Binarization;
        auto binarization = (Binarization^)arrayImageProcessing[index];
        result = binarization->ImageProcessing(this->mBitmap, token, GetThresh());
    }
    else if (imageProcessingName == (String^)ComConstStringInfo::IMG_NAME_GRAY_SCALE_2DIFF)
    {
        index = ComInfo::ImgProc::Type::GrayScale2Diff;
        auto grayScale2Diff = (GrayScale2Diff^)arrayImageProcessing[index];
        result = grayScale2Diff->ImageProcessing(this->mBitmap, token);
    }
    else if (imageProcessingName == (String^)ComConstStringInfo::IMG_NAME_COLOR_REVERSAL)
    {
        index = ComInfo::ImgProc::Type::ColorReversal;
        auto colorReversal = (ColorReversal^)arrayImageProcessing[index];
        result = colorReversal->ImageProcessing(this->mBitmap, token);
    }

	return result;
}