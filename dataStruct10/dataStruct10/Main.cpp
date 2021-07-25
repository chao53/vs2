#include"InfectGraph.h";

using namespace std;

int main() {
	int n;
	cin >> n;
	InfectGraph G1(n);
	int w;
	for (int y = 0;y < n;y++) {
		int x = 0;
		while (cin >> w)
		{
			G1.change(y, x, w);
			x++;
			if (cin.get() == '\n') {
				break;
			}
		}
	}
	int n2;
	cin >> n2;
	G1.setSourseNum(n2);
	for (int i = 0;i < n2;i++) {
		int v;
		cin >> v;
		G1.setSourse(v);
	}

	cout<<G1.solustion();
}