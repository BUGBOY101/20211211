#define	_CRT_SECURE_NO_WARNINGS 1

//hdoj1013

#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char s[1000];//����ת�����ַ������
	int sum, i, a;
	while (cin >> s) {
		if (strcmp(s, "0") == 0)//s[0]=='0'
			break;
		sum = 0;
		for (i = 0; i < strlen(s); i++)
			sum += s[i] - '0';
		
		while (sum > 9) {//��Ҫ���ж�һ��a��sum�Ƿ����9
			a = 0;
			while (sum) {
				a += sum % 10;//ģ10��10�������
				sum /= 10;
			}
			sum = a;
		}
		cout << sum << endl;
	}
}