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

// hàm khoi tao cây nhi phân tìm kiem
void KhoiTaoCay(TREE &t)
{
	t = NULL;
}

// hàm thêm 1 cái phan tu vào cây
void ThemNodeVaoCay(TREE &t, int x)
{
	// neu cây rong
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
		// neu phan tu thêm vào mà nho hon nút goc thì se duyet qua bên trái
		if (x < t->data)
		{
			ThemNodeVaoCay(t->pLeft, x);
		}
			// neu phan tu thêm vào mà lon hon nút goc thì se duyet qua bên phai
		else if (x > t->data)
		{
			ThemNodeVaoCay(t->pRight, x);
		}
	}
}

// hàm xuat phan tu trong cây nhi phân tìm kiem
void NLR(TREE t)
{
	if (t != NULL)
	{
		// x? lí
		cout << t->data << "  ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

// neu node có ton tai trong cây thì tra ve cái node dó - còn không ton tai thì tra ve NULL
NODE* TimKiem(TREE t, int x)
{ 
	// n?u cây r?ng
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		// neu phan tu con tìm kiem mà nho hon node goc thì duyet(de quy) sang bên trái de tìm
		if (x < t->data)
		{
			TimKiem(t->pLeft, x);
		}
		else if (x > t->data) // duyet sang bên phai
		{
			TimKiem(t->pRight, x);
		}
		else // <=> t->data == x
		{
			return t; // tra ve node con tìm kiem
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

