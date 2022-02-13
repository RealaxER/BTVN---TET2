#include<iostream>
using namespace std;
#define MAX 100
void Nhap(int a[], int n);
void Mang_con(int Me[], int n, int Con[], int m);
void Xuat(int a[], int n);
void Xoa(int a[], int& n, int vitri);
int Max(int a[], int n);
void Demcon(int Me[], int n, int Con[], int m);
void Them(int a[], int& n, int vitri, int x);
void Bai1cs(int a[], int n);
void Xuatnguoc(int a[], int n);
void Bai1(int a[], int n);
void Bai2(int a[], int n);
void Bai3(int a[], int n);
void Bai4(int a[], int n);

int main()
{
	int a[MAX];
	int n;
	do { cout << "Nhap n : " << endl; cin >> n; } while (n <= 0 && n > MAX);
	int b[MAX];
	int m;
	do { cout << "Nhap m : " << endl; cin >> m; } while (m <= 0 && m > MAX);
	Nhap(a, n);
	//Nhap(b, m);
	//Mangcon(a,n,b,m);    kiểm tra xem có là mảng con không 
	//Demcon(a, n, b, m);  đếm xem số lần xuất hiện
	//Them(a, n, 2, 100);
	//Bai1cs(a, n);
//	Bai1(a,n);
	//Bai2(a, n);
	//Bai3(a, n);
	Bai4(a, n);
	system("pause");

}

void Nhap(int a[], int n)
{
	cout << "\n\n\t\t  NHAP MANG " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap gia tri thu : " << i << " : " << endl;
		cin >> a[i];
	}
}
void Xuat(int a[],int n)
{
	cout << "\n\n\t\t XUAT MANG " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}
int Max(int a[], int n)
{
	int max = a[0];
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			temp = i;
		}
	}
	return temp;
}
void Mang_con(int Me[], int n, int Con[], int m)
{
	int Kiemtra = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Con[i] == Me[j])
			{
				Kiemtra ++;
				break;
			}
		}
	}
	if (Kiemtra == m)
	{
		cout << "Day la mang con : " << endl;
	}
	else
	{
		cout << "Khong la mang con " << endl;
	}
}
void Xoa(int a[], int &n, int vitri)
{
	for (int i = vitri; i < n; i++) 
	{
		a[i] = a[i+1]; 
	}
	n--;
}
void Them(int a[], int& n, int vitri, int x)
{
	for (int i = n ; i > vitri; i--)
	{
		a[i] = a[i - 1];
	}
	a[vitri] = x;
	n++;
}
void Demcon(int Me[], int n, int Con[], int m)
{
	int Kiemtra = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = i+1; j < m ; j++)
		{
			if (Con[i] == Con[j])
			{
				Xoa(Con, m, j);
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Con[i] == Me[j])
			{
				Kiemtra++;
			}
		}
		cout << " Gia tri " << Con[i] << " xuat hien :  " << Kiemtra << " lan " << endl;
		Kiemtra = 0;
	}
}
void Xuatnguoc(int a[], int n)
{
	for (int i = n-1; i >=0; i--)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void Bai1cs(int a[], int n)
{
	int b[MAX];
	int m = 0 ;
	int vitri = 0;
	cout << "XUAT" << endl;
	for (int i = 0; i<n ; i++)
	{
		Them(b, m, vitri, a[i]);
		vitri;
		Xuatnguoc(b, m) ;
	}
}
void Bai1(int a[], int n) {
	int b[MAX];
	int m = 0;
	bool kiemtra = false;
	int vitri = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i + 1] > a[i])
		{
			Them(b, m, vitri, a[i]);
			kiemtra = true;
			vitri++;
		}
		else 
		{
			if (kiemtra == true)
			{
				Them(b, m, vitri, a[i]);
				vitri = 0;
				kiemtra = false;
				Xuat(b, m);
				m = 0;
			}
		}
	}
}
void Bai2(int a[], int n)
{
	int M;
	do {
	cout << "Nhap M : " << endl;
	cin >> M;
	} while (M <= 0);
	int S = 0;
	int b[MAX];
	int m = 0, vitri = 0;
	for (int i = 0; i < n; i++)
	{
		S = a[i];
		Them(b, m, vitri, a[i]);
		vitri++;
		for (int j = 0; j < n; j++)
		{
			if (j == i)
			{
				continue;
			}
			S = S + a[j];
			Them(b, m, vitri, a[j]);
			vitri++;
			if (S < M)
			{
				continue;
			}
			else if (S == M)
			{
				Xuat(b, m);
				vitri = m = 0;
				S = a[i];
			}
			else
			{
				vitri--;
				m--;
				S = S - a[j];
				if (S == M)
				{
					Xuat(b, m);
					vitri = m = 0;
					S = a[i];
				}
			}
		}
		vitri = m = 0;
	}
}
void Bai3(int a[], int n)
{
	int b[MAX];
	int m = 0;
	int vitri = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			Xuat(b, m);
			vitri = 0;
			m = 0;
		}
		if (a[i] > 0)
		{
			Them(b, m, vitri, a[i]);
			vitri++;
		}
		else
		{
			if (a[i - 1] > 0)
			{
				Xuat(b, m);
				vitri = 0;
				m = 0;
			}
			continue;
		}
	}
}
void Bai4(int a[], int n)
{
	int b[MAX];
	int m = 0,k=0;
	int vitri = 0,dem = 0;
	int kiemtra = 0;
	int c[MAX];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			dem++;
		}
		else
		{
			if (a[i - 1] > 0)
			{
				Them(c,k,vitri,dem);
				vitri++;
			}
			continue;
		}
	}
	int vtmax = Max(c, k);
	cout << "cocai lol " << vtmax << endl;

	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			Them(b, m, vitri, a[i]);
			vitri++;
		}
		else
		{
			if (a[i - 1] > 0)
			{
				if (kiemtra == vtmax)
				{
					Xuat(b, m);
				}
				kiemtra++;
				vitri = m = 0;
			}
			continue;
		}
	}
} // bai 5 em dừng ở đây thôi ạ quá mệt mỏi rồi :(((
