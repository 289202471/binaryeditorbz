// BZDoc.h : interface of the CBZDoc class
//
/////////////////////////////////////////////////////////////////////////////

#define FILE_MAPPING	// ###1.60

enum UndoMode {	UNDO_INS, UNDO_OVR, UNDO_DEL };

class CBZDoc : public CDocument
{
public: // create from serialization only
	CBZDoc();
	DECLARE_DYNCREATE(CBZDoc)

// Attributes
private:
	LPBYTE	m_pData; //���������̃A�h���X�B�t�@�C�����A�h���X��0�ɓ�����A�h���X�������B�����������I�ȃt�@�C���}�b�s���O�̏ꍇ������B���̏ꍇm_pData����}�b�s���O�̈悪�n�܂��Ă���Ƃ͌���Ȃ��Am_pData�͋[���I�ȃA�h���X�ɂȂ��Ă���
	DWORD	m_dwTotal;
	LPBYTE	m_pUndo;
	DWORD	m_dwUndo;
	DWORD	m_dwUndoSaved;		// ###1.54
	CDWordArray m_arrMarks;

	DWORD	m_dwAllocationGranularity;
public:
	BOOL	m_bReadOnly;

	LPBYTE	GetDocPtr() ; // { return m_pData; }
	DWORD	GetDocSize() { return m_dwTotal; }
#ifdef FILE_MAPPING
	HANDLE	m_hMapping;
	CFile*	m_pFileMapping;
	CBZDoc* m_pDupDoc;
	LPBYTE	m_pMapStart;	// ###1.61�@�}�b�s���O�̈��[�i���������̃A�h���X�j
	DWORD   m_dwFileOffset; //�f�[�^�t�@�C���̃}�b�s���O�J�n�A�h���X�i�t�@�C�����̃A�h���X�j
	DWORD	m_dwMapSize; //�f�[�^�t�@�C���̃}�b�s���O�T�C�Y
#endif //FILE_MAPPING
	DWORD	m_dwBase;		// ###1.63

// Operations
public:
	BOOL	CopyToClipboard(DWORD dwPtr, DWORD dwSize);
	DWORD	PasteFromClipboard(DWORD dwPtr, BOOL bIns);
	void	InsertData(DWORD dwPtr, DWORD dwSize, BOOL bIns);
	void	DeleteData(DWORD dwPtr, DWORD dwSize);
	void	StoreUndo(DWORD dwPtr, DWORD dwSize, UndoMode mode);
	DWORD	DoUndo();
	void	TouchDoc();		// ###1.54
	void	DuplicateDoc(CBZDoc* pDstDoc);
	void	SetMark(DWORD dwPtr);
	BOOL	CheckMark(DWORD dwPtr);
	DWORD	JumpToMark(DWORD dwPtr);
#ifdef FILE_MAPPING
	_inline DWORD	GetFileOffsetFromFileMappingPointer(LPBYTE pConv) { return pConv-m_pData; }
	_inline LPBYTE	GetFileMappingPointerFromFileOffset(DWORD dwFileOffset) { return dwFileOffset+m_pData; }

	BOOL	IsFileMapping() { return m_hMapping != NULL; }
	LPBYTE  QueryMapView(LPBYTE pBegin, DWORD dwOffset) { return m_pMapStart ? QueryMapView1(pBegin, dwOffset) : pBegin; }
	BOOL    IsOutOfMap(LPBYTE p) { return m_pMapStart ? IsOutOfMap1(p) : FALSE; }
	DWORD	GetMapSize() { return m_pMapStart ? m_dwFileOffset + m_dwMapSize : m_dwTotal; }
private:
	BOOL     MapView();
	LPBYTE  QueryMapView1(LPBYTE pBegin, DWORD dwOffset);
	BOOL    IsOutOfMap1(LPBYTE p);
#endif //FILE_MAPPING

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBZDoc)
	public:
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	protected:
	//}}AFX_VIRTUAL

#ifdef FILE_MAPPING
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void ReleaseFile(CFile* pFile, BOOL bAbort);
	virtual BOOL SaveModified();
#endif //FILE_MAPPING

// Implementation
public:
	virtual ~CBZDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	DWORD GetFileLength(CFile* pFile, BOOL bErrorMsg = FALSE);	// ###1.60

// Generated message map functions
protected:
	//{{AFX_MSG(CBZDoc)
	afx_msg void OnEditReadOnly();
	afx_msg void OnUpdateEditReadOnly(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditUndo(CCmdUI* pCmdUI);
	afx_msg void OnEditReadOnlyOpen();
	afx_msg void OnUpdateEditReadOnlyOpen(CCmdUI* pCmdUI);
	//}}AFX_MSG
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
