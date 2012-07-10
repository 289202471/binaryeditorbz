// BZInspectView.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "BZ.h"
#include "BZInspectView.h"


// CBZInspectView

IMPLEMENT_DYNCREATE(CBZInspectView, CFormView)

CBZInspectView::CBZInspectView()
	: CFormView(CBZInspectView::IDD)
{

}

CBZInspectView::~CBZInspectView()
{
}

void CBZInspectView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBZInspectView, CFormView)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CBZInspectView �f�f

#ifdef _DEBUG
void CBZInspectView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CBZInspectView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBZInspectView ���b�Z�[�W �n���h��

int CBZInspectView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	if(options.xSplitStruct == 0)
		options.xSplitStruct = lpCreateStruct->cx;

	return 0;
}

void CBZInspectView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �����ɓ���ȃR�[�h��ǉ����邩�A�������͊�{�N���X���Ăяo���Ă��������B
}
