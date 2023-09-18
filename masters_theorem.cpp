// Input format
//  3
//  T(n)=3T(n/2)+(n^2)*(logn)^0
//  T(n)=4T(n/2)+(n^2)*(logn)^0
//  T(n)=3T(n/2)+(n^1)*(logn)^0F
#include <bits/stdc++.h>
using namespace std;

int a, b, k, p;

void f(string s)
{
	string A = "", B = "", K = "", P = "";
	int i = 0;
	while (s[i] != '=')
		i++;
	i++;
	while (s[i] != 'T')
	{
		A.push_back(s[i]);
		i++;
	}

	while (s[i] != '/')
		i++;
	i++;
	while (s[i] != ')')
	{
		B += s[i++];
	}

	while (s[i] != '^')
		i++;
	i++;
	while (s[i] != ')')
	{
		K += s[i++];
	}

	while (s[i] != '^')
		i++;
	i++;
	while (i < s.size())
	{
		P += s[i++];
	}

	a = stoi(A);
	b = stoi(B);
	k = stoi(K);
	p = stoi(P);

	cout << a << endl;
	cout << b << endl;
	cout << k << endl;
	cout << p << endl;

	cout << endl;
}
int main()
{
	string s;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> s;
		f(s);
		if (a > b && b != 0)
		{
			double logValue = log10(a) / log10(b); // logb(a) = log10(a)*logb(10)  == log10(a)/log10(b)
			cout << logValue << endl;
			if (logValue > k)
			{
				cout << s << "\t\tO(n^" << logValue << ")\t\tcase\t1 "
					 << "\n";
			}

			else if (logValue == k)
			{
				if (p > -1)
					cout << s << "\t\tO(n^" << k << " (log^" << p + 1 << ")n\t\tcase\t2"
						 << "\n";
				else if (p == -1)
					cout << s << "\t\tO(n^" << k << " loglogn)\t\tcase\t2"
						 << "\n";
				else
					cout << s << "\t\tO(n^" << k << ")\t\tcase\t2"
						 << "\n";
			}

			else
			{
				if (p >= 0)
				{
					cout << s << "\t\tO(n^" << k << " (logn)^" << p << ")\t\tcase\t3 "
						 << "\n";
				}
				else
				{
					cout << s << "\t\tO(n^" << k << ")\t\tcase\t"
						 << "\n";
				}
			}
		}
		else{
			cout<<"Master's Theorem is not applicable!!"<<endl;
		}
	}
}
