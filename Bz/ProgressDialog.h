#pragma once


// CProgressDialog �_�C�A���O

class CProgressDialog : public CDialog
{
	DECLARE_DYNAMIC(CProgressDialog)

public:
	CProgressDialog(CWnd* pParent = NULL);   // �W���R���X�g���N�^
	virtual ~CProgressDialog();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_PROGRESSDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
};
