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
/// <param name="_nId">ID</param>
/// <param name="_strNmae">����</param>
ComImageProcessingType::ComImageProcessingType(int _nId, String^ _strNmae)
{
	m_nId = _nId;
	m_strName = _strNmae;
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