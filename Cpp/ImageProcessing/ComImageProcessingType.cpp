#include "ComImageProcessingType.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
ComImageProcessingType::ComImageProcessingType()
{
}

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="id">ID</param>
/// <param name="name">����</param>
ComImageProcessingType::ComImageProcessingType(int id, String^ name)
{
	mId = id;
	mName = name;
}

/// <summary>
/// �f�X�N�g���N�^
/// </summary>
ComImageProcessingType::~ComImageProcessingType()
{
}

/// <summary>
/// �N���[��
/// </summary>
/// <returns>�摜�����ݒ�̃N���[��</returns>
Object^ ComImageProcessingType::Clone()
{
	return (ComImageProcessingType^)MemberwiseClone();
}