
// calculatorDlg.h : ͷ�ļ�
//

#pragma once


// CcalculatorDlg �Ի���
class CcalculatorDlg : public CDialogEx
{
// ����
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCULATOR_DIALOG };

	double num1;
	double num2;
	double result;
	int cal;
	int cal2;
	int point;
	int click;
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedplus();
	CString var1;
	afx_msg void OnBnClickedone();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedtwo();
	afx_msg void OnBnClickedthree();
	afx_msg void OnBnClickedfour();
	afx_msg void OnBnClickedfive();
	afx_msg void OnBnClickedsix();
	afx_msg void OnBnClickedseven();
	afx_msg void OnBnClickedeight();
	afx_msg void OnBnClickednine();
	afx_msg void OnBnClickedzero();
	afx_msg void OnBnClickedpoint();
	afx_msg void OnBnClickedequal();
	afx_msg void OnBnClickedclear();
	afx_msg void OnBnClickedsub();
	afx_msg void OnBnClickedmultip();
	afx_msg void OnBnClickeddivision();
	afx_msg void OnBnClickedreturn();
};
