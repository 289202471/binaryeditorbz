// ProgressDialog.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "BZ.h"
#include "ProgressDialog.h"


// CProgressDialog �_�C�A���O

IMPLEMENT_DYNAMIC(CProgressDialog, CDialog)

CProgressDialog::CProgressDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CProgressDialog::IDD, pParent)
{

}

CProgressDialog::~CProgressDialog()
{
}

void CProgressDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProgressDialog, CDialog)
END_MESSAGE_MAP()


// CProgressDialog ���b�Z�[�W �n���h��
