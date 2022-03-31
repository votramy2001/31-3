#include<iostream>
using namespace std;
struct node
{
	int data; 
	struct node *pLeft; 
	struct node *pRight; 
};
typedef struct node NODE;
typedef NODE* TREE;

// h�m khoi tao c�y nhi ph�n t�m kiem
void KhoiTaoCay(TREE &t)
{
	t = NULL;
}

// h�m th�m 1 c�i phan tu v�o c�y
void ThemNodeVaoCay(TREE &t, int x)
{
	// neu c�y rong
	if (t == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		// neu phan tu th�m v�o m� nho hon n�t goc th� se duyet qua b�n tr�i
		if (x < t->data)
		{
			ThemNodeVaoCay(t->pLeft, x);
		}
			// neu phan tu th�m v�o m� lon hon n�t goc th� se duyet qua b�n phai
		else if (x > t->data)
		{
			ThemNodeVaoCay(t->pRight, x);
		}
	}
}

// h�m xuat phan tu trong c�y nhi ph�n t�m kiem
void NLR(TREE t)
{
	if (t != NULL)
	{
		// x? l�
		cout << t->data << "  ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

// neu node c� ton tai trong c�y th� tra ve c�i node d� - c�n kh�ng ton tai th� tra ve NULL
NODE* TimKiem(TREE t, int x)
{ 
	// n?u c�y r?ng
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		// neu phan tu con t�m kiem m� nho hon node goc th� duyet(de quy) sang b�n tr�i de t�m
		if (x < t->data)
		{
			TimKiem(t->pLeft, x);
		}
		else if (x > t->data) // duyet sang b�n phai
		{
			TimKiem(t->pRight, x);
		}
		else // <=> t->data == x
		{
			return t; // tra ve node con t�m kiem
		}
	}

}

// ham nhap cay nhi phan tim kiem
void Menu(TREE &t)
{
	int luachon;
	while(true)
	{
		system("cls");
		cout << "\n\n\t\t ============ MENU ============";
		cout << "\n1. Nhap phan tu";
		cout << "\n2. Duyet cay";
		cout << "\n3. Tim kiem phan tu trong cay";
		cout << "\n0. Thoat";
		cout << "\n\n\t\t =============  END  =============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri: ";
			cin >> x;
			ThemNodeVaoCay(t, x);
		}
		else if (luachon == 2)
		{
			cout << "\n\t CAY NHI PHAN TIM KIEM\n";
			NLR(t);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\nNhap phan tu can tim kiem: ";
			cin >> x;
			NODE *p = TimKiem(t, x);
			if (p == NULL)
			{
				cout << "\nPhan tu " << x << " khong ton tai trong cay\n";
			}
			else
			{
				cout << "\nPhan tu " << x << " co ton tai trong cay\n";
			}
			system("pause");
		}
	
		else
		{
			break;
		}
	}
}


int main()
{
	TREE t;
	KhoiTaoCay(t);
	Menu(t);

	system("pause");
	return 0;
}

