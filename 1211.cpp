#define	_CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n, i;
	while (cin >> n) {
		double sum = 0;
		for (i = 1; i <= n; i++) {
			sum += log10(i);
		}
		cout << (int)sum + 1;
	}
}

#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int p1, p2, q1, q2, r1, r2, n;
	cin >> n;
	while (n--) {
		cin >> p1 >> p2 >> q1 >> q2 >> r1 >> r2;
		int x = (r1 * p1 * q2);
		int y = (r1 * p1 * q2) + fabs((r2 - r1) * (q2 - q1)) * p2;
		while(x % 10 == 0 && y % 10 == 0) {
			x /= 10;
			y /= 10;
		}
		if (y == 1)
			cout << x << endl;
		else
			printf("%d/%d", x, y);
	}
}

#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int a[5] = { 6,2,4,8 }, n=0;
	char s[190];
	cin >> s;
	int i;
	if (strcmp(s,"0")==0) {
		cout << "1" << endl;
	}
	else {
		for (i = 0; i < strlen(s); i++) {
			n = (n * 10 + (s[i] - '0')) % 4;
		}
		cout << a[n] << endl;
	}
}

#include<iostream>
using namespace std;
int main() {
	int t, x, n, m, flag;
	cin >> t;
	while (t--) {
		cin >> x >> n >> m;
		flag = 0;
		if (x <= 40) {
			while (m--) {
				x -= 10;
				if (x <= 0) {
					flag = 1;
					break;
				}
			}
				
			while (n--) {
				x = x / 2 + 10;
				if (x <= 0) {
					flag = 1;
					break;
				}
			}
		}
		else {
			while (n--) {
				x = x / 2 + 10;
				if (x <= 0) {
					flag = 1;
					break;
				}
			}
				
			while (m--) {
				x -= 10;
				if (x <= 0) {
					flag = 1;
					break;
				}
			}
		}
		
		if (flag == 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}

#include <stdio.h>  
#include <string.h>  
char a[20];
int num[20][20], len, ans;

int getnum(int x, int y) {
    int sum = 0, i, t = 1;
    for (i = y; i >= x; i--) {
        sum += (a[i] - '0') * t;
        t *= 10;
    }
    return sum;
}

void dfs2(int y, int sum1, int sum2) {
    if (y >= len) {
        if (sum1 == sum2)
            ans++;
        return;
    }
    for (int i = y; i < len; i++)
        dfs2(i + 1, sum1, sum2 + num[y][i]);
}

void dfs1(int x, int sum, int mid) {
    if (x >= mid)
        dfs2(mid, sum, 0);
    for (int i = x; i < mid; i++)
        dfs1(i + 1, sum + num[x][i], mid);
}

int main() {
    int i, j;
    while (~scanf("%s", a)) {
        if (strcmp(a, "END") == 0)
            break;
        len = strlen(a);
        memset(num, 0, sizeof(num));
        for (i = 0; i < len; i++) {
            for (j = i; j < len; j++)
                num[i][j] = getnum(i, j);
        }
        ans = 0;
        for (i = 1; i < len; i++)
            dfs1(0, 0, i);
        printf("%d\n", ans);
    }
    return 0;
}

#include<iostream>
using namespace std;
void f(int n) {
	int s = 2;
	n = s++;
	cout << n;
}
int main() {
	int a = 1;
	f(a);
	cout << a;
}

double my_sqrt1(int n) {

	double low = 1, high = n / 2 + 1, mid, lastmid;

	mid = (low + high) / 2;

	do {

		if (mid * mid < n)

			low = mid;

		else

			high = mid;

		lastmid = mid;

		mid = (low + high) / 2;



	} while (fabs(high - low) > 1e-6);

	return mid;

}

#include<iostream>

using namespace std;

double my_sqrt(double n) {
	double x = n;
	while (fabs(x * x - n) > 1e-6) {
		x = (x + n / x) / 2;
	}
	return x;
}
double fun(int n) {
	//求n以内(不包括n)同时能被5与11整除的所有自然数之和的平方根s（保留三位小数）
	int i;

	double sum = 0;

	for (i = 55; i < n; i++) {

		if (i % 55 == 0)

			sum += my_sqrt(i);

	}

	return sum;

}

int main() {

	int n;
	
	cin >> n;

	double sum = fun(n);

	printf("%.3lf\n", sum);

}



#include<iostream>
using namespace std;
struct {
	char name[21];
	int score;
}stu[101];
int main() {
	int n, i, max = 0, k = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> stu[i].score >> stu[i].name;
		if (stu[i].score > max) {
			max = stu[i].score;
			k = i;
		}	
	}
	cout << stu[k].name << endl;
}

//大数取模
#include<iostream>
using namespace std;
int main() {
	int a[10] = { 0 }, i, j = 0, k, n, c, count = 0;
	char s[31];
	cin >> s;
	n = strlen(s);
	for (k = 2; k <= 9; k++) {
		c = 0;
		for (i = 0; i < n; i++) {
			c = (c * 10 + s[i] - '0') % k;
		}
		if (c == 0) {
			a[j++] = k;
			count++;
		}
	}
	if (count == 0)
		cout << "none" << endl;
	else {
		for (i = 0; i < count; i++) {
			if (i != count - 1) {
				cout << a[i] << " ";
			}
			else if (i == count - 1)
				cout << a[i] << endl;
		}
	}
}


//#include<iostream>
#include<cmath>
using namespace std;
double my_sqrt(double n) {
	double x = n;
	if (x < 0)
		return -1;
	while (fabs(x-n/x)>1e-6) {
		x = (x + n / x) / 2;
	}
	return x;
}
int main() {
	double x;
	while(cin>>x)
		printf("%.3lf\n", my_sqrt(x));
}