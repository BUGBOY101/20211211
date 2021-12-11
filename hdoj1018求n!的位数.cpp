#define	_CRT_SECURE_NO_WARNINGS 1

//hdoj 1018求n!的位数
//暴力一定会wa,数据太大

#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n, i, N;
	while (cin >> N) {
		while (N--) {
			cin >> n;
			double sum = 0;
			for (i = 1; i <= n; i++)
				sum += log10(i);//log10(n!)=求n!的位数
			cout << int(sum) + 1 << endl;
		}
	}
}

//方法二-斯特林公式
#include<iostream>
#include<cmath>
using namespace std;
#define pi 3.14159
#define e exp(1)
int main() {
	int n, N;
	while (cin >> N) {
		while (N--) {
			cin >> n;
			double sum = 0;
			if (n != 0)
				sum = log10(2 * pi * n) / 2 + n * (log10(n / e));
			cout << (int)sum + 1 << endl;
		}
	}
}