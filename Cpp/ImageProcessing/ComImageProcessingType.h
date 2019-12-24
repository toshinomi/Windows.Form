#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;

/// <summary>
/// �摜�����ݒ�̃��W�b�N
/// </summary>
public ref class ComImageProcessingType
{
private:
	/// <summary>
	/// ID
	/// </summary>
	int m_nId;

	/// <summary>
	/// ����
	/// </summary>
	String^ m_strName;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	ComImageProcessingType();

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_nId">ID</param>
	/// <param name="_strNmae">����</param>
	ComImageProcessingType(int _Id, String^ _strNmae);

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~ComImageProcessingType();

	/// <summary>
	/// ID�̎擾
	/// </summary>
	/// <returns>ID</returns>
	int GetId(void) { return m_nId; };

	/// <summary>
	/// ID�̐ݒ�
	/// </summary>
	/// <param name="_nId">ID</param>
	void SetId(int _nId) { m_nId = _nId; };

	/// <summary>
	/// ���̂̎擾
	/// </summary>
	/// <returns>����</returns>
	String^ GetName(void) { return m_strName; };

	/// <summary>
	/// ���̂̐ݒ�
	/// </summary>
	/// <param name="_strName">����</param>
	void SetName(String^ _strName) { m_strName = _strName; };

	/// <summary>
	/// �N���[��
	/// </summary>
	/// <returns>�摜�����ݒ�̃N���[��</returns>
	Object^ Clone();
};