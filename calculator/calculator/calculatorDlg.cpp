
// calculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg �Ի���




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
	, var1(_T("0"))
	, click(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, var1);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_plus, &CcalculatorDlg::OnBnClickedplus)
	ON_BN_CLICKED(IDC_one, &CcalculatorDlg::OnBnClickedone)
	ON_EN_CHANGE(IDC_EDIT1, &CcalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_two, &CcalculatorDlg::OnBnClickedtwo)
	ON_BN_CLICKED(IDC_three, &CcalculatorDlg::OnBnClickedthree)
	ON_BN_CLICKED(IDC_four, &CcalculatorDlg::OnBnClickedfour)
	ON_BN_CLICKED(IDC_five, &CcalculatorDlg::OnBnClickedfive)
	ON_BN_CLICKED(IDC_six, &CcalculatorDlg::OnBnClickedsix)
	ON_BN_CLICKED(IDC_seven, &CcalculatorDlg::OnBnClickedseven)
	ON_BN_CLICKED(IDC_eight, &CcalculatorDlg::OnBnClickedeight)
	ON_BN_CLICKED(IDC_nine, &CcalculatorDlg::OnBnClickednine)
	ON_BN_CLICKED(IDC_zero, &CcalculatorDlg::OnBnClickedzero)
	ON_BN_CLICKED(IDC_point, &CcalculatorDlg::OnBnClickedpoint)
	ON_BN_CLICKED(IDC_equal, &CcalculatorDlg::OnBnClickedequal)
	ON_BN_CLICKED(IDC_clear, &CcalculatorDlg::OnBnClickedclear)
	ON_BN_CLICKED(IDC_sub, &CcalculatorDlg::OnBnClickedsub)
	ON_BN_CLICKED(IDC_multip, &CcalculatorDlg::OnBnClickedmultip)
	ON_BN_CLICKED(IDC_division, &CcalculatorDlg::OnBnClickeddivision)
	ON_BN_CLICKED(IDC_return, &CcalculatorDlg::OnBnClickedreturn)
END_MESSAGE_MAP()


// CcalculatorDlg ��Ϣ�������

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CcalculatorDlg::OnBnClickedone()
{
	UpdateData(true);
	if(cal2==1)
	{
		var1="";
		var1 = var1 + '1' ;
		cal2=2;
	}
	else
	{
		var1=var1 + '1';
	}
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedtwo()
{
	UpdateData(true);
	if(cal2==1)
	{
		var1="";
		var1 = var1 + '2' ;
		cal2=2;
	}
	else
	{
		var1=var1 + '2';
	}
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedthree()
{
	UpdateData(true);
	if(cal2==1)
	{
		var1="";
		var1 = var1 + '3' ;
		cal2=2;
	}
	else
	{
		var1=var1 + '3';
	}
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedfour()
{
	UpdateData(true);

	if(cal2==1)
	{
		var1="";
		var1 = var1 + '4' ;
		cal2=2;
	}
	else
	{
		var1=var1 + '4';
	}
		
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedfive()
{
	UpdateData(true);
	
	if(cal2==1)
	{
		var1="";
		var1 = var1 + '5' ;
		cal2=2;
	}
	else
	{
		var1=var1 + '5';
	}
		
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedsix()
{
	UpdateData(true);
	if(cal2==1)
	{
		var1="";
		var1 = var1 + '6' ;
		cal2=2;
	}
	else
	{
		var1=var1 + '6';
	}
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedseven()
{
	UpdateData(true);

	if(cal2==1)
	{
		var1="";
		var1 = var1 + '7' ;
		cal2=2;
	}
	else
	{
		var1=var1 + '7';
	}
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedeight()
{

	UpdateData(true);
	
	if(cal2==1)
	{
		var1="";
		var1 = var1 + '8' ;
		cal2=2;
	}
	else
	{
		var1=var1 + '8';
	}
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickednine()
{
	UpdateData(true);
	
	if(cal2==1)
	{
		var1="";
		var1 = var1 + '9' ;
		cal2=2;
	}
	else
	{
		var1=var1 + '9';
	}
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedzero()
{
	UpdateData(true);
	if(var1[0]!='0')
	{
		if(cal2==1)
		{
			var1="";
			var1 = var1 + '0' ;
			cal2=2;
		}
		else
		{
			var1=var1 + '0';
		}
	}
	
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedpoint()
{
	UpdateData(true);
	point=var1.Find(_T("."),0);
	if(point==-1)
	{
		var1 = var1 + '.' ;
	}
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedequal()
{
	UpdateData(true);
	num2=_tstof(var1);
	if(cal==1)
	{
		result = num1 + num2;
		var1.Format(_T("%f"),result);
	}
	if(cal==2)
	{
		result = num1 - num2;
		var1.Format(_T("%f"),result);
	}
	if(cal==3)
	{
		result = num1 * num2;
		var1.Format(_T("%f"),result);
	}
	if(cal==4)
	{
		result = num1 / num2;
		var1.Format(_T("%f"),result);
	}
	var1.TrimRight('0');
	var1.TrimRight('.');

	UpdateData(false);
	cal=0;
	cal2=1;
	click=0;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedclear()
{
	UpdateData(true);
	var1="";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CcalculatorDlg::OnBnClickedplus()
{
	if(click==0)
	{
	num1=_tstof(var1);
	var1="";
	cal=1;
	cal2=1;
	click++;
	}
	else
	{
	num2=_tstof(var1);
	result=num1+num2;

	cal=1;
	cal2=1;
	click++;
	var1.Format(_T("%f"),result);
	num1=_tstof(var1);

	}
	var1.TrimRight('0');
	var1.TrimRight('.');
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedsub()
{
	num1=_tstof(var1);
	var1="";
	cal=2;
	cal2=1;
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedmultip()
{
	num1=_tstof(var1);
	var1="";
	cal=3;
	cal2=1;
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickeddivision()
{
	UpdateData(true);
	num1=_tstof(var1);
	var1="";
	cal=4;
	cal2=1;
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedreturn()
{
	UpdateData(true);
	var1=var1.Left(var1.GetLength()-1);
	cal2=2;
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
