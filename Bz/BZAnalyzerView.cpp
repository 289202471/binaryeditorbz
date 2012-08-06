// BZAnalyzerView.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "BZ.h"
#include "BZAnalyzerView.h"
#include "ProgressDialog.h"
#include "zlib.h"


// CBZAnalyzerView

IMPLEMENT_DYNCREATE(CBZAnalyzerView, CFormView)

CBZAnalyzerView::CBZAnalyzerView()
	: CFormView(CBZAnalyzerView::IDD)
{

}

CBZAnalyzerView::~CBZAnalyzerView()
{
}

void CBZAnalyzerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDP_ANALYZE_PERCENT, m_progress);
	DDX_Control(pDX, IDL_ANALYZE_RESULT, m_resultList);
	DDX_Control(pDX, IDC_ANALYZE_TYPE, m_combo_analyzetype);
}

BEGIN_MESSAGE_MAP(CBZAnalyzerView, CFormView)
	ON_BN_CLICKED(IDB_ANALYZE_START, &CBZAnalyzerView::OnBnClickedAnalyzeStart)
END_MESSAGE_MAP()


// CBZAnalyzerView �f�f

#ifdef _DEBUG
void CBZAnalyzerView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CBZAnalyzerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBZAnalyzerView ���b�Z�[�W �n���h��

void CBZAnalyzerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �����ɓ���ȃR�[�h��ǉ����邩�A�������͊�{�N���X���Ăяo���Ă��������B
	if(m_combo_analyzetype.GetCount()==0)
	{
		m_combo_analyzetype.InsertString(0, "zlib (deflate����)");
		m_combo_analyzetype.SetCurSel(0);

		m_resultList.DeleteAllItems();
		m_resultList.InsertColumn(0, "Address", LVCFMT_LEFT, 80);
		m_resultList.InsertColumn(1, "Size", LVCFMT_LEFT, 80);
	}
}

void CBZAnalyzerView::OnBnClickedAnalyzeStart()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	m_resultList.DeleteAllItems();

	CProgressDialog dlgProgress;
	dlgProgress.DoModal();

	m_resultList.InsertItem(0, "0x00000000");
	m_resultList.SetItemText(0, 1, "5000");
}
