#pragma once



// CBZInspectView �t�H�[�� �r���[

class CBZInspectView : public CFormView
{
	DECLARE_DYNCREATE(CBZInspectView)

protected:
	CBZInspectView();           // ���I�����Ŏg�p����� protected �R���X�g���N�^
	virtual ~CBZInspectView();

public:
	enum { IDD = IDD_BZINSPECTVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitialUpdate();
};


