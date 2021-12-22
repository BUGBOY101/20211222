#define	_CRT_SECURE_NO_WARNINGS 1


//#include<iostream>
//using namespace std;
//#define N 100005
//int a[N];
//int main() {
//	int k, n, i, count = 0, flag = 0, m;
//	cin >> n >> k;
//	for (i = 0; i <= k; i++) {
//		cin >> a[i];
//	}
//	m = n;
//	for (i = 0; i <= k; i++) {
//		if (a[i] > n) {
//			flag = 1;
//			break;
//		}
//		m -= a[i];
//		if (m < a[i + 1]) {
//			count++;
//			m = n;
//		}
//	}
//	if (flag == 1)
//		cout << "No Solution!" << endl;
//	else
//		cout << count << endl;
//
//}

//#include<iostream>
//#include<algorithm>
//#define MAXN 100005
//using namespace std;
//bool cmp(int x, int y) {
//	return x > y;
//}
//int a[MAXN], b[MAXN], c[MAXN];
//int main() {
//	int k, i, j, sum1, sum2;
//	cin >> k;
//	for (i = 0; i < k; i++) {
//		cin >> a[i];
//	}
//	for (i = 0; i < k; i++) {
//		b[i] = a[i];
//		c[i] = a[i];
//	}
//	sum1 = 0;
//	sort(b, b + k, cmp);
//	for (i = 0; i < k - 1; i++) {
//		sum1 += b[i] + b[i + 1] - 1;
//		b[i + 1] = b[i] + b[i + 1];
//	}
//	sum2 = 0;
//	for (i = 0; i < k - 1;i++) {
//		sort(c+i, c + k);
//		sum2 += c[i] + c[i + 1] - 1;
//		c[i + 1] = c[i] + c[i + 1];
//	}
//	cout << sum1 <<" " << sum2 << endl;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct node {
//	int w;
//	int p;
//	double bi;
//}f[1000005];
//bool cmp(node a, node b) {
//	if (a.w == b.w)
//		return a.bi > b.bi;
//	else
//		return a.w < b.w;
//}
//int main() {
//	int n, m, i, sum;
//	cin >> n >> m;
//	for (i = 0; i < n; i++) {
//		cin >> f[i].w >> f[i].p;
//		f[i].bi = (double)f[i].p / f[i].w;
//	}
//	sort(f, f + n, cmp);
//	i = 0;
//	sum = 0;
//	if (m > n)
//		m = n;
//	for (i = 0; i < m; i++) {
//		sum += f[i].p;
//	}
//	cout << sum << endl;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct node {
//	char name[20];
//	double start;
//	double end;
//}act[10005];
//bool cmp(node a, node b) {
//	return a.end < b.end;
//}
//int main() {
//	int n, i,j, sum;
//	cin >> n;
//	for (i = 0; i < n; i++) {
//		cin >> act[i].name >> act[i].start >> act[i].end;
//	}
//	sort(act, act + n, cmp);
//	i = 0;
//	sum = 1;
//	for (j = 2; j < n; j++) {
//		if (act[j].start >= act[i].end) {
//			i = j;
//			sum++;
//		}
//	}
//	cout << sum << endl;
//}

//合并有序数组

//#include<iostream>
//#include<algorithm>
//using namespace std;
//void merge2(int a[], int m, int b[], int n) {
//	int i = m - 1, j = n - 1, p = m + n - 1;
//	while (i>=0 && j>=0) {
//		a[p--] = a[i] > b[j] ? a[i--] : b[j--];
//	}
//	while (j >= 0) {
//		a[p--] = b[j--];
//	}
//}
//void merge(int a[], int m, int b[], int n) {
//	int i=0, j=0, p = 0;
//	int c[200];
//	while(i<m&&j<n) {
//		c[p++] = a[i] < b[j] ? a[i++] : b[j++];
//	}
//	while (i < m) {
//		c[p++] = a[i++];
//	}
//	while (j < n) {
//		c[p++] = b[j++];
//	}
//	for (i = 0; i < m + n; i++)
//		a[i] = c[i];
//}
//int main() {
//	int a[100] = { 1,2,3,4,5,6,7,8,9,10 };
//	int b[4] = { 2,4,6,8 };
//	int i;
//	merge2(a, 10, b, 4);
//	for (i = 0; i < 14; i++)
//		cout << a[i] << " ";
//	cout << endl;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct node {
//	int start;
//	int end;
//	int b;
//}act[10005];
//bool cmp(node a, node b) {
//	if (a.start == b.start)
//		return a.end < b.end;
//	else
//		return a.start<b.start;
//}
//int main() {
//	int k, i, j, sum;
//	cin >> k;
//	for (i = 1; i <= k; i++) {
//		cin >> act[i].start >> act[i].end;
//		act[i].b = 0;//标记
//	}
//	act[0].start = -1;
//	act[0].end = -1;
//	sort(act + 1, act + k + 1, cmp);
//	sum = 1;
//	act[1].b = 1;//第一个会场
//	for (i = 1; i <= k; i++) {
//		if (act[i].b == 0) {//时间有冲突的，会场数+1
//			sum++;
//			act[i].b = sum;
//		}
//		for (j = i+1; j <= k; j++) {
//			if (act[j].start >= act[i].end&&act[j].b==0) {
//				act[j].b = act[i].b;//可以在同一会场进行
//				act[i].end = act[j].end;
//			}
//		}
//	}
//	cout << sum << endl;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//bool cmp(int& x, int& y) {
//	return x < y;
//}
//int main() {
//	int T, n, time, i;
//	int t[1005];
//	cin >> T;
//	while (T--) {
//		cin >> n;
//		memset(t, 0, sizeof(t));
//		for (i = 0; i < n; i++) {
//			cin >> t[i];
//		}
//		sort(t, t + n, cmp);
//		time = 0;
//		while (n > 3) {
//			time += min(t[0] + 2 * t[1] + t[n - 1], 2 * t[0] + t[n - 1] + t[n - 2]);
//			n -= 2;
//		}
//		if (n == 3)
//			time += t[0] + t[1] + t[2];
//		if (n == 2)
//			time += t[1];
//		if (n == 1)
//			time += t[0];
//		cout << time << endl;
//	}
//}