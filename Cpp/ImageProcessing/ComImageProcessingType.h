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
	int mId;

	/// <summary>
	/// ����
	/// </summary>
	String^ mName;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	ComImageProcessingType();

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="Id">ID</param>
	/// <param name="Nmae">����</param>
	ComImageProcessingType(int Id, String^ Nmae);

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~ComImageProcessingType();

	/// <summary>
	/// ID�̎擾
	/// </summary>
	/// <returns>ID</returns>
	int GetId(void) { return mId; };

	/// <summary>
	/// ID�̐ݒ�
	/// </summary>
	/// <param name="id">ID</param>
	void SetId(int id) { mId = id; };

	/// <summary>
	/// ���̂̎擾
	/// </summary>
	/// <returns>����</returns>
	String^ GetName(void) { return mName; };

	/// <summary>
	/// ���̂̐ݒ�
	/// </summary>
	/// <param name="name">����</param>
	void SetName(String^ name) { mName = name; };

	/// <summary>
	/// �N���[��
	/// </summary>
	/// <returns>�摜�����ݒ�̃N���[��</returns>
	Object^ Clone();
};