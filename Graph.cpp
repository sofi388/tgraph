
#include "Graph.h"
#define INF 999

vector<int> deg;

int Input()
{
	string s;
	while (true)
	{
		cout << endl;
		cout << ">> ";
		cin >> s;
		cin.clear();
		fflush(stdin);
		if (s.find_first_not_of("1234567890") != string::npos)
		{
			cout << "������������ ��������!\n���������� ��� ���: ";
		}
		else
			return atoi(s.c_str());
	}
}

int initCount() {
	int n = 0;
	cout << endl;
	cout << "������� ���������� ������ ����� (�� 2 �� 16): \n";
	cout << endl;
	n = Input();
	while ((n < 2) || (n > 16))
	{
		cout << endl;
		cout << "������������ ��������!\n���������� ��� ���: ";
		cout << endl;
		n = Input();
	}
	return n;
}


int ArrInit(vector<vector<int>>& arr, int n) {

  binomial_distribution <int> bern(n, 0.6); //������ 1 
  random_device rd;
  mt19937 generator(rd());
// n - ���������� ������ � �����, p - �����������
	arr.clear();

	for (int i = 0; i < n; i++)
	{
		arr.push_back(vector<int>(n, 0));
	}

	for (int i = 0; i < n; ++i)

	{		
	for (int j = i + 1; j < n; j++)

		{
			/*int p = (rand() % 100) / 100.0;
				if (p < 0.6)
					arr.at(i).at(j) = 1;
				else  arr.at(i).at(j) = 0;*/
 if (j == i + 1) arr.at(i).at(j) = 1;

		else arr.at(i).at(j) = bern(generator) % 2;
		}
	}
	return 0;
}
/*
int ArrInit(vector<vector<int>>& arr, int n) {

	arr.clear();
	for (int i = 0; i < n; i++)
	{
		arr.push_back(vector<int>(n, 0));
	}

	for (int i = 0; i < n; ++i)

	{
		for (int j = i + 1; j < n; j++)
			if (i + 1 == j) arr.at(i).at(j) = 1;
			else
			{
				double p = (rand() % 100) / 100.0;
				if (p < 0.6)
					arr.at(i).at(j) = 1;
				else  arr.at(i).at(j) = 0;
			}
	}
	return 0;
}
*/

/*������������� ������� �����*/
void initMatrVesov(vector<vector<int>>& arr, vector<vector<int>>& matrVesov, bool f) {
	matrVesov.clear();
	for (int i = 0; i < arr.size(); i++)
	{
		matrVesov.push_back(vector<int>(arr.size(), 0));
	}

	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = i + 1; j < arr.size(); j++)
			if (arr.at(i).at(j)) {
				if (f) { // ��� ������������� ����� 
					int x = rand() % 19 - 9;
					while (x == 0)
						x = rand() % 19 - 9;
					matrVesov.at(i).at(j) = x;
				}
				else matrVesov.at(i).at(j) = rand() % 9 + 1;
			}
			else matrVesov.at(i).at(j) = 0;
	}
}

/*����� ������*/
int outArr(vector<vector<int>>& arr)
{
	for (auto v : arr)
	{
		for (auto vv : v)
			if (vv == INF)
			{
				cout << 0 << "\t";
			}
			else cout << vv << "\t";
		cout << endl;
	}

	return 0;
}

void InitWithINF(vector<vector<int>>& arr, vector<vector<int>>& matrVesov, vector<vector<int>>& matrNegVesov)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (!arr[i][j])
			{
				arr[i][j] = INF;
				matrVesov[i][j] = INF;
				matrNegVesov[i][j] = INF;
			}
		}
	}


	return;
}

void InitWithNull(vector<vector<int>>& arr, vector<vector<int>>& matrVesov, vector<vector<int>>& matrNegVesov)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[i][j] == INF)
			{
				arr[i][j] = 0;
				matrVesov[i][j] = 0;
				matrNegVesov[i][j] = 0;
			}
		}
	}


	return;
}

/*����� ��������*/
int ShimbellMenu(vector<vector<int>>& arr)
{
	int x = 0;
	int ExtrPath = 0;
	cout << endl;
	cout << "\n������� ���������� ����: \n";
	cout << endl;
	x = Input();
	while ((x < 1) || (x > arr.size() - 1))
	{
		cout << endl;
		cout << "������������ ��������!\n���������� ��� ���: ";
		cout << endl;
		x = Input();
	}
	cout << endl;
	cout << "\n����� 1)������������ �����; 2)����������� �����\n";
	cout << endl;
	ExtrPath = Input();
	while ((ExtrPath < 1) || (ExtrPath > 2))
	{
		cout << endl;
		cout << "������������ ��������!\n���������� ��� ���: ";
		cout << endl;
		ExtrPath = Input();
	}

	ExtrPath--;

	cout << endl;

	Shimbell(arr, x, ExtrPath);

	return 0;
}

int Shimbell(vector<vector<int>>& arr, int n1, int ExtrPath)
{
	vector<vector<int>> buffArr(arr);

	for (int i = 1; i < n1; i++)
	{
		matrixMultiply(buffArr, arr, ExtrPath);
	}
	if (ExtrPath == 1)
	{
		cout << endl;
		cout << "���������� ���� �� " << n1 << " ����:\n" << endl;
		cout << endl;
	}
	else {
		cout << endl;
		cout << "���������� ���� �� " << n1 << " ����:\n" << endl;
		cout << endl;
	}
	outArr(buffArr);


	return 0;
}

/*����� �������� - ������ ��������� ������*/
int matrixMultiply(vector<vector<int>>& arr1, vector<vector<int>>& arr2, bool ExtrPath) {

	vector<int> buffer;

	vector<vector<int>> buffArr;
	for (int i = 0; i < arr1.size(); i++)
		buffArr.push_back(vector<int>(arr1.size(), 0));

	for (int i = 0; i < arr1.size(); i++)
	{
		for (int j = 0; j < arr1.size(); j++)
		{
			buffer.clear();
			for (int k = 0; k < arr1.size(); k++)
			{
				if ((arr1[i][k]) && (arr2[k][j]))
					buffer.push_back(arr1[i][k] + arr2[k][j]);

				else
					buffer.push_back(0);

			}
			if (ExtrPath)
			{
				int min = buffer.front();
				for (auto x : buffer)
				{
					if (((min == 0) && (x != 0)) || ((x < min) && (x != 0)))
						min = x;
				}
				buffArr[i][j] = min;
			}
			else {
				int max = 0;
				for (auto x : buffer)
				{
					if (((max == 0) && (x != 0)) || ((x > max) && (x != 0)))
						max = x;
				}
				buffArr[i][j] = max;
			}

		}
	}
	arr1 = buffArr;

	return 0;
}

/*����� � �������*/
bool dfs(int u, int t, vector<bool>& visited, vector<vector<int>>& arr)
{
	if (u == t)
		return true;
	visited.at(u) = true;
	int k = 0;
	for (auto v : arr.at(u))
	{
		if (v && !visited.at(k))
		{
			if (dfs(k, t, visited, arr))
				return true;
		}
		k++;
	}
	return false;
}

/*�������� ������������� ��������*/
int IsPathExist(vector<vector<int>>& arr)
{
	int n1 = 0, n2 = 0;
	cout << endl;
	cout << "������� ����� ������ �������: \n";
	n1 = Input();
	while ((n1 < 1) || (n1 > arr.size()))
	{
		cout << endl;
		cout << "������������ ��������!\n���������� ��� ���: ";
		n1 = Input();
	}
	cout << endl;
	cout << "������� ����� ������ �������: \n";
	n2 = Input();
	while ((n2 < 1) || (n2 > arr.size()))
	{
		cout << endl;
		cout << "������������ ��������!\n���������� ��� ���: ";
		cout << endl;
		n2 = Input();
	}

	vector<bool> visited(arr.size(), false);

	if (n1 == n2)
	{
		cout << endl;
		cout << "��������� ������� ���������\n";
		cout << endl;
	}
	else if (dfs(n1 - 1, n2 - 1, visited, arr)) {
		cout << endl;
		cout << "���� �� ������� " << n1 << " � ������� " << n2 << " ����������\n" << endl;
		cout << endl;

	}
	else {
		cout << endl;
		cout << "���� �� ������� " << n1 << " � ������� " << n2 << " �� ����������\n" << endl;
		cout << endl;
	}
	return 0;
}
/*�������� ��������*/
void DijkstraMenu(vector<vector<int>> arr)
{

	int z = 0, a = 0, b = 0;
	int c = 0;
	cout << endl;
	cout << "������� ��������� �������\n";
	cout << endl;
	int AllPath = 1;
	a = Input();
	while ((a < 1) || (a > arr.size()))
	{
		cout << endl;
		cout << "������������ ��������!\n���������� ��� ���: ";
		cout << endl;
		a = Input();
	}
	cout << "������� �������� �������\n";
	c = Input();
	while ((c < 1) || (c > arr.size()))
	{
		cout << endl;
		cout << "������������ ��������!\n���������� ��� ���: ";
		cout << endl;
		c = Input();
	}

	Dijkstra(arr, a, c);
	return;
}

/*
void ShortestPath(int a, int c) 
{


}*/
void Dijkstra(vector<vector<int>> arr, int a, int c)
{
	vector<bool> visited;
	vector<int> D;
	vector<int> Path(arr.size(), 0); //��� ���� ����� ��������� ��������� a � c
	vector<int> p(arr.size(), -1);
	int it = 0;
	for (auto v : arr.at(a - 1))
	{
		D.push_back(v);
		visited.push_back(false);
	}
	D.at(a - 1) = 0;

	visited.at(a - 1) = true;
	int index = 0, u = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		int min = INF;

		for (int j = 0; j < arr.size(); j++)
		{
			if ((!visited[j]) && (D[j] < min))
			{
				min = D[j]; // j - �������, D[j] - ���� ����
				index = j; //

			}
			it++;
		}

		u = index;
		visited.at(u) = true;

		for (int j = 0; j < arr.size(); j++)
		{
			if (!visited.at(j) && arr.at(u).at(j) != INF && D.at(u) != INF && (D.at(u) + arr.at(u).at(j) < D.at(j)))
			{
				D.at(j) = D.at(u) + arr.at(u).at(j);
				Path.at(j) == u;
			}

		}

	}
	cout << endl;
	cout << "�������� ��������:\t\n";

	for (int i = 0; i < arr.size(); i++)
	{
		cout << a << " - " << "�� ������� �����: " << i + 1 << " = " << D[i] << endl;
	}
	cout << endl;
	cout << endl << "���������� ��������:" << it << endl;

	//�������������� ����
	vector<int> ver;// ������ ���������� ������
	int end = c; // ������ �������� �������

	int VER[16] = {0};
	VER[0] = end;
	//ver.at(0) = end + 1; // ��������� ������� - �������� �������
	int k = 1;
	int weight = D.at(end); // ����������� ����������

	while (end != 0)
	{
		for (int i = 0; i < arr.size(); i++)
			if (arr.at(i).at(end) != 0) // ���� ����� ���� (������� ����� �������)
		{
				int tmp = weight - arr.at(i).at(end);
				if (tmp == D.at(i))
				{
					weight = tmp;
					end = i;
					VER[k] = i + 1;
		        	//ver.at(k) = i + 1;
					k++;

				}
		}
	}




	cout << "�� ������� " << a << " � ������� " << c << "\n";
	/*
	for (int i = 0; i < ver.size(); i++)
	{
		cout << ver.at(i) << endl;
	}
	//*/
	
	for (int i = 0; i < 16; i++)
	{
		cout << VER[i] << endl;
	}
	
	cout << endl;
}

/*�������� ��������-�����*/
void BellmanFordMenu(vector<vector<int>> arr)
{
	int a = 0;
	cout << endl;
	cout << "������� ��������� �������\n";
	cout << endl;

	while ((a < 1) || (a > arr.size()))
		while (!(cin >> a) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << endl;
			cout << "������! ������� ��� ���!\n";
			cout << endl;
			fflush(stdin);
		}

	vector<int>b = BellmanFord(arr, a, 1);
	return;
}

vector<int> BellmanFord(vector<vector<int>> arr, int vershina, bool Print)
{
	vector<edge> e; (arr.size() * arr.size());//������ ��� ��� ���
	vector<int> d(arr.size(), INF);//������ ���������� �� �������, ����������� inf ������ ��� ���� ���� �� ����������, �� ���������� == �������������
	vector<int> p(arr.size(), -1);
	vector<int> path;
	int count = 0;


	for (int i = 0; i < arr.size(); i++)//�������������� ������ ���� ���
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[i][j] < INF)
			{
				e.push_back(edge(i, j, arr[i][j]));
				count++;//������� ���������� ���
			}
		}

	d[vershina - 1] = 0;//���������� �� ������� � ��� �� ����� ���� 
	int it = 0;
	for (int i = 0; i < arr.size(); ++i) {//�������� �� ���� ��������
		for (int j = 0; j < count; ++j) {//���������� ��� ���� 
			if (d[e[j].getA()] < (INF - 100)) {//���� ���������� �� �������(1), �� ������� ������� ��� ����,  ������ �������������
				if (d[e[j].getB()] > d[e[j].getA()] + e[j].getCost()) {//���� ���������� �� �������(2), � ������� ���� ��� ����, ������ ����� ���������� �� ������� (1) � ���� ���� ����
					d[e[j].getB()] = d[e[j].getA()] + e[j].getCost();//�� �������� �� �������
					p[e[j].getB()] = e[j].getA();
				}
			}
			it++;//������� ��������
		}
	}


	if (Print) {
		cout << endl;
		cout << "\n�������� ��������-�����.\n";
		cout << endl;

		for (int i = 0; i < d.size(); i++)
			cout << "�� ������� �����: " << i + 1 << " - " << "��� �����: " << d[i] << endl << endl;

		cout << endl << "���������� ��������:" << it << endl << endl;
	}
	else {
		for (int cur = arr.size() - 1; cur != -1; cur = p[cur])
			path.push_back(cur);
		reverse(path.begin(), path.end());
	}
	return path;

}

/*�������� ������-��������*/
void  Warshall(vector<vector<int>>& arr)
{
	int it = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[i][j] == 0 && i != j)
				arr[i][j] = 999;
		}
	}

	for (int i = 0; i < arr.size(); i++) {

		for (int j = 0; j < arr.size(); j++) {

			for (int k = 0; k < arr.size(); k++) {

				if (arr[i][k] + arr[k][j] < arr[i][j])
					arr[i][j] = arr[i][k] + arr[k][j];

				it++;
			}
		}

	}

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[i][j] >= 900)
				cout << 0 << "\t";
			else
				cout << arr[i][j] << "\t";

		}
		cout << endl;
	}
	cout << endl << "���������� ��������:" << it << endl << endl;

}


//3 ������������

void ChangeToUnoriented(vector<vector<int>>& arr, vector<vector<int>>& matrixVesov)
{
	for (int i = 0; i < arr.size(); i++)
		for (int j = 0; j < arr.size(); j++)
		{
			arr[j][i] = arr[i][j];
			matrixVesov[j][i] = matrixVesov[i][j];
		}

	return;
}

void ChangeToOriented(vector<vector<int>>& arr, vector<vector<int>>& matrixVesov)
{
	for (int i = 0; i < arr.size(); i++)
		for (int j = 0; j <= i; j++)
		{
			arr[i][j] = INF;
			matrixVesov[i][j] = INF;
		}

	return;
}

/*�������� ��������*/
vector<set<int>>* Kruskal(vector<vector<int>>& arr, vector<vector<int>>& matrixVesov)
{

	int it = 0, m = 0;
	int count = 0;
	for (int i = 0; i < arr.size(); i++)
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[i][j] > 0 && arr[i][j] < (INF / 2))
				m++;
		}
	m = m / 2;//���������� �����

	vector < edge> g;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i; j < arr.size(); j++)
			if (matrixVesov[i][j] < 500)
			{
				g.push_back(edge(i, j, matrixVesov[i][j]));
				count++;

			}
	}
	int cost = 0;
	vector < pair<int, int> > res;

	sort(g.begin(), g.end());

	vector<int> tree_id(arr.size());
	for (int i = 0; i < arr.size(); ++i)
		tree_id[i] = i;
	for (int i = 0; i < m; ++i)
	{
		int a = g[i].getA(), b = g[i].getB(), l = g[i].getCost();
		if (tree_id[a] != tree_id[b])
		{
			cost += l;

			res.push_back(make_pair(a, b));

			int old_id = tree_id[a], new_id = tree_id[b];


			for (int j = 0; j < arr.size(); ++j)
			{
				if (tree_id[j] == old_id)
				{
					tree_id[j] = new_id;

				}
				it++;
			}

		}

	}
	vector<set<int>>* ostov = new vector<set<int>>(arr.size());
	for_each(res.begin(), res.end(), [&](pair<int, int> x)
		{
			ostov->at(x.first).insert(x.second);
			ostov->at(x.second).insert(x.first);
			if (x.first > x.second)
			{
				cout << x.second + 1 << " --> " << x.first + 1 << endl;
			}
			else
			{
				cout << x.first + 1 << " --> " << x.second + 1 << endl;
			}
		});
	cout << endl;
	cout << "\n��������� ������������ ������: " << cost << endl;
	cout << endl;
	cout << "���������� ��������:" << it << endl;
	cout << endl;

	return ostov;

}

/*�������� �����*/
vector<set<int>>* Prim(vector<vector<int>>& arr, vector<vector<int>>& matrixVesov)
{
	int it = 0;

	int cost = 0;
	vector<bool> used(arr.size());//������ ������, ����� ������� ������
	vector<int> min_e(arr.size(), INF), sel_e(arr.size(), -1);
	min_e[0] = 0;//������������� ��������� ������ �������
	vector<set<int>>* ostov = new vector<set<int>>(arr.size());
	for (int i = 0; i < arr.size(); ++i)//���������� ��� �������
	{
		int v = -1;
		for (int j = 0; j < arr.size(); ++j)//���� 
			if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
			{
				v = j;
			}
		if (min_e[v] == INF)
		{
			cout << endl;
			cout << "��� ��������� ������!";
			cout << endl;
			exit(0);
		}

		used[v] = true;


		for (int to = 0; to < arr.size(); ++to)
		{
			if (matrixVesov[v][to] < min_e[to])
			{
				min_e[to] = matrixVesov[v][to];
				sel_e[to] = v;

			}
			it++;
		}


		if (sel_e[v] != -1)
		{
			ostov->at(sel_e[v]).insert(v);
			ostov->at(v).insert(sel_e[v]);
			if ((sel_e[v] + 1) > (v + 1))
			{
				cout << v + 1 << " --> " << sel_e[v] + 1 << endl;
			}
			else
			{
				cout << sel_e[v] + 1 << " --> " << v + 1 << endl;

			}
			cost += matrixVesov[sel_e[v]][v];

		}

	}
	cout << endl;
	cout << "\n��������� ������������ ������: " << cost << endl;
	cout << endl;
	cout << "���������� ��������:" << it << endl;
	cout << endl;

	return ostov;
}

/*��������� ������� ��������*/
void Kirhgof(vector<vector<int>>& arr, vector<vector<int>>& matrixVesov)
{

	int count = 0;
	vector<vector<int>> buffer(arr.size(), vector<int>(arr.size()));
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
			if (arr[i][j] == INF)
				buffer[i][j] = 0;
			else
			{
				buffer[i][j] = -arr[i][j];
				count++;
			}
		buffer[i][i] = count;
		count = 0;
	}

	cout << "\n������� ��������: \n";
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
			cout << buffer[i][j] << '\t';
		cout << endl;
	}

	int minor = 1;

	vector<vector<int>> arr2(arr.size() - 1, vector<int>(arr.size() - 1));
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = 1; j < arr.size(); j++)
		{
			arr2[i - 1][j - 1] = buffer[i][j];
		}
	}

	for (int i = 0; i < arr.size() - 1; i++)
		minor += arr2[0][i] * pow(-1, (1 + i + 1)) * findMinor(arr2, 0, i);


	if (arr.size() != 2)
		minor -= 1;
	cout << endl << "\n���������� �������� �������� ����� �� ������� �������� = " << abs(minor) << endl << endl;

}

/*����� ������*/
int findMinor(vector<vector<int>>& buffer, int x, int y)
{
	int minor = 0;

	vector<vector<int>> arr(buffer.size() - 1, vector<int>(buffer.size() - 1));
	int k = 0, f = 0;
	for (int i = 0; i < buffer.size(); i++)
	{
		f = 0;
		for (int j = 0; j < buffer.size(); j++)
		{
			if ((i != x) && (j != y))
			{
				arr[k][f] = buffer[i][j];
				f++;
			}
		}
		if (i != x)
			k++;
	}
	if ((buffer.size() - 1) == 1)
	{
		minor = arr[0][0];
	}
	else
	{
		for (int i = 0; i < buffer.size() - 1; i++)
		{
			minor += arr[0][i] * pow(-1, (1 + i + 1)) * findMinor(arr, 0, i);
		}
	}
	return minor;
}

/*����������� �������*/
void PruferCoding(vector<set<int>>* ostov, vector<int>& pruferCode)
{
	if (ostov == nullptr)
	{
		cout << endl;
		cout << "\n������! ��������� ����� ������!\n";
		cout << endl;
		return;
	}
	if (ostov->size() == 2)
	{
		cout << "1" << endl;
		return;
	}
	if (pruferCode.size() == (ostov->size() - 2))
	{
		cout << endl;
		cout << "\n��� �������: " << endl;
		cout << endl;
		for (int i = 0; i < ostov->size() - 2; i++)
			cout << pruferCode.at(i) + 1 << ' ';
		cout << endl;
		return;
	}
	vector<bool> visited(ostov->size());

	while (pruferCode.size() != ostov->size() - 2)
	{
		for (int i = 0; i < ostov->size(); i++)
		{
			if (!visited[i])
				if (ostov->at(i).size() == 1)
				{
					visited[i] = true;
					for (int j = 0; j < ostov->size(); j++)
					{
						ostov->at(i).clear();
						auto iter = ostov->at(j).find(i);
						if (iter != ostov->at(j).end())
						{
							ostov->at(j).erase(*iter);
							pruferCode.push_back(j);

							break;
						}

					}
					break;
				}
		}
	}
	cout << endl;
	cout << "\n��� �������: " << endl;
	cout << endl;
	for (int i = 0; i < ostov->size() - 2; i++)
		cout << pruferCode.at(i) + 1 << ' ';
	cout << endl;
}

/*������������� �������*/
void PruferEncoding(vector<set<int>>* ostov, vector<int>& pruferCode)
{
	if (ostov == nullptr)
	{
		cout << endl;
		cout << "\n������! ��������� ����� ������!\n";
		cout << endl;
		return;
	}
	if (ostov->size() == 2)
	{
		cout << endl;
		cout << "\n������������� �������:" << endl;
		cout << endl;
		cout << 1 << " --> " << 2 << endl;
		return;
	}
	if (pruferCode.size() < (ostov->size() - 2))
	{
		cout << endl;
		cout << "\n������! ��������� ����������� �������!\n";
		cout << endl;
		return;
	}
	cout << endl;
	cout << "\n������������� �������:" << endl;
	cout << endl;
	deque<int> v;
	bool b = false;
	for (int i = 0; i < ostov->size(); i++)
		v.push_back(i);
	int index = 0;
	while (v.size() != 2)
	{
		bool b = false;
		for (int i = 0; i < pruferCode.size(); i++)
			if (pruferCode.at(i) == v.at(index))
				b = true;
		if (b)
		{
			index++;
			b = false;
		}
		else
		{
			auto iter = v.begin() + index;
			cout << v.at(index) + 1 << " - " << pruferCode.at(0) + 1 << endl;
			v.erase(iter);
			pruferCode.erase(pruferCode.begin());
			index = 0;
			b = false;
		}
	}
	cout << v.at(0) + 1 << " --> " << v.at(1) + 1 << endl;
}


/*������������� ������� ���������*/
void initCost(vector<vector<int>> arr, vector<vector<int>>& cost, vector<vector<int>>& bandwidth) {

	if (cost.size()) return;

	for (int i = 0; i < arr.size(); i++) {
		cost.push_back(vector<int>(arr.size(), 0));
		bandwidth.push_back(vector<int>(arr.size(), 0));
	}
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[i][j] < (INF / 2)) {
				bandwidth[i][j] = rand() % 11 + 2;
				cost[i][j] = rand() % 11 + 2;
			}
			else {
				bandwidth[i][j] = 0;
				cost[i][j] = INF;
			}
		}
	}
	cout << endl;
	cout << "\n������� ���������: " << endl;
	outArr(cost);
	cout << endl;
	cout << "\n������� ���������� ������������: " << endl;
	outArr(bandwidth);
	cout << endl;
}

/*�������� �����-�����������*/
int fordFulkerson(int s, int t, vector<vector<int>>& cost, vector<vector<int>>& bandwidth, bool Print)
{

	if ((cost.empty()) || (bandwidth.empty())) {
		cout << endl;
		cout << "������� ���������� ������������ � ��������� �� �������������!" << endl;
		cout << endl;
		return 0;
	}
	else {
		int u, v;

		vector<vector<int>>potok(cost.size(), vector<int>(cost.size(), 0));

		vector<vector<int>> rGraph(cost.size(), vector<int>(cost.size(), 0));

		for (u = 0; u < cost.size(); u++) {//��������� ������ ������ ����������� ������������, ����� ����� ��� �����

			for (v = 0; v < cost.size(); v++) {
				if (bandwidth[u][v] > (INF / 2)) {
					rGraph[u][v] = 0;
				}
				else {
					rGraph[u][v] = bandwidth[u][v];
				}
			}
		}

		vector<int> parent(cost.size());

		int max_flow = 0;//������������ �����

		while (bfs(rGraph, s, t, parent))//���� ���������� ���� �� ������ ������� � ���������, ���� "��������" � ������� parent
		{

			int path_flow = INT_MAX;//����� ����
			for (v = t; v != s; v = parent[v])//���� � �������� ������� �� ����
			{
				u = parent[v];//������ ������ � ��� �������
				path_flow = min(path_flow, rGraph[u][v]);//�������� ����������� ���������� ����������� �� ����� ����

			}

			for (v = t; v != s; v = parent[v])//����� ���� �������
			{
				u = parent[v];//������ ������ � �������
				rGraph[u][v] -= path_flow;//�������� �� ���������� ����������� ��������� �����
				rGraph[v][u] += path_flow;// ����������, �� �������
				if (potok[u][v] != 0)// ��������� � ������� ������ ��� ��������
					potok[u][v] += path_flow;
				else
					potok[u][v] = path_flow;
			}

			max_flow += path_flow;//��������� �������� ������������� ������
		}
		if (Print) {
			cout << endl;
			cout << "������� ������ : " << endl;
			outArr(potok);
			cout << endl;
		}

		return max_flow;
	}
}

/*����� � ������*/
bool bfs(vector<vector<int>> rGraph, int s, int t, vector<int>& parent)
{
	vector<bool> visited(rGraph.size(), false);//������ ���������� ������

	deque <int> q;
	q.push_back(s);//��������� � ��� ������ �������
	visited[s] = true;//�� ��� ������, �� �� �� ������
	parent[s] = -1;//�� ��� ������, �� ����� ��� ��� ������

	while (!q.empty())
	{
		int u = q.front();//����� ������ ������� u 
		q.pop_front();//������� ��� �� ����

		for (int v = 0; v < rGraph.size(); v++)//�������� �� ���� ��������
		{
			if (visited[v] == false && rGraph[u][v] > 0)//���� �� � ��� �� ���� � � ���� ���� �  ��� �� ������� u 
			{
				q.push_back(v);//��������� � ���
				parent[v] = u;//�������� ������ ������ � ��� �������
				visited[v] = true;//��������, ��� ������ ��
			}
		}
	}
	bool res = (visited[t] == true);//���� ����� �� �����


	return res;
}

/*����� ����������� ���������*/
void MinCostMaxFlow(int b, vector<vector<int>>& arr, vector<vector<int>>& costArr, vector<vector<int>>& bandwidthArr)
{
	//flFord = false;

	vector<vector<int>> matrPotok(arr.size(), vector<int>(arr.size(), 0));


	if ((costArr.empty()) || (bandwidthArr.empty())) {
		cout << endl;
		cout << "������� ���������� ������������ � ��������� �� �������������!" << endl;
		return;
	}
	else {
		int maxflow = 0;
		int flow = 0;
		int sigma = INF;
		int result = 0;
		int m = 0;
		vector<vector<int>> modifiedCostsArr(costArr);
		map<int, pair<vector<int>, int>> tempMap;
		map<vector<int>, pair<int, int>> temporary;
		set<pair<int, int>> resultVertex;// ��������� ���
		vector<vector<int>> f(arr.size(), vector<int>(arr.size(), 0));
		vector<int> k;

		for (int i = 0; i < arr.size(); i++)
			for (int j = 0; j < arr.size(); j++)
			{
				if (arr[i][j])
					m++;//���������� �����
			}



		while (maxflow < b) {//���� ��������� ��������� ����� ������ ���������
			vector<int> path = BellmanFord(modifiedCostsArr, 1, 0);//�������� �������� ����� ��� ����������������� ������� ���������,
																   //�������� ������� ���� ����������� ����� �� 
																   //������ � �����
			for (int i = 0; i < path.size() - 1; i++) {
				sigma = min(sigma, bandwidthArr[path.at(i)][path.at(i + 1)]);//�������� ����������� �����, ������� ����� ������� �� ����� ����
				if (resultVertex.find(pair<int, int>(path.at(i), path.at(i + 1))) == resultVertex.end()) {//���� �� ����� � ��������� ���
					resultVertex.insert(pair<int, int>(path.at(i), path.at(i + 1)));//���������

				}
			}

			flow = min(sigma, (b - maxflow));//���� ��������� ����� ����� ������ �����������, �� ��������
			k.push_back(flow);//��������� ��� � ������
			int tempCost = 0;//
			for (int i = 0; i < path.size() - 1; i++)
			{
				tempCost += costArr[path.at(i)][path.at(i + 1)];//������� ���������
			}
			if (temporary.find(path) == temporary.end()) {//���� ������ ���� ���
				temporary[path] = pair<int, int>(flow, tempCost);//�� ��������� ��� � 
			}
			else {
				temporary[path].first += flow;//���������� �����
			}
			for (int i = 0; i < path.size() - 1; i++) {//�������� ���� ����
				f.at(path[i]).at(path[i + 1]) += flow;//���������� ����� � �������
				if (f.at(path[i]).at(path[i + 1]) == bandwidthArr[path[i]][path[i + 1]]) {//���� ��� ��������, �� ��������, ��� ������ ���������
					modifiedCostsArr[path[i]][path[i + 1]] = INF;//�.�. ������ ������������� � ������� ����������� ���������
					modifiedCostsArr[path[i + 1]][path[i]] = INF;
				}
				else
				{
					if (f.at(path[i]).at(path[i + 1]) >= 0) {//���� ����� �������������
						modifiedCostsArr[path[i]][path[i + 1]] = costArr[path[i]][path[i + 1]];//�� ��������� � ������������ ������� �������� �� ������� ����������
						modifiedCostsArr[path[i + 1]][path[i]] = -modifiedCostsArr[path[i]][path[i + 1]];//������� � �������
					}
				}
			}

			maxflow += flow;//��������� �������� ������
		}
		int min = INF;
		vector<pair<int, pair<vector<int>, int >>> tempVect;//tempVect[j].first-����������, tempVect[j].second.first-������ ���� ������, tempVect[j].second.second - �����   
		for (auto i = temporary.begin(); i != temporary.end(); i++)//�������� �� ��������� ���
										//i->second.second-��������� , i->first -����, i->second.first - �����
		{
			tempVect.push_back(pair<int, pair<vector<int>, int>>(i->second.second, pair<vector<int>, int>(i->first, i->second.first)));
		}
		//
		for (int i = 0; i < tempVect.size() - 1; i++)
		{
			for (int j = 0; j < tempVect.size() - 1; j++)
			{
				if (tempVect[j].first > tempVect[j + 1].first)//��������� �� ����������� ����������
					swap(tempVect[j], tempVect[j + 1]);
			}
		}

		vector<int> vecPotok;
		//vector<vector<int>> vecPath;
		vector<int> vecMatr;
		int ur = 0;
		for (int i = 0; i < tempVect.size(); i++)
		{
			cout << endl;
			cout << endl << "���� ������: " << endl;
			for (int j = 0; j < tempVect[i].second.first.size() - 1; j++)//������� ���� ������
			{
				cout << tempVect[i].second.first[j] + 1 << " - ";
				vecMatr.push_back(tempVect[i].second.first[j]);

			}
			cout << tempVect[i].second.first[tempVect[i].second.first.size() - 1] + 1;
			vecMatr.push_back(tempVect[i].second.first[tempVect[i].second.first.size() - 1]);
			//vecPath.push_back(vecMatr);
			cout << endl;
			cout << endl << "�����, ����� ��������� ����: " << tempVect[i].second.second << endl;
			for (int l = 0; l < vecMatr.size() - 1; l++)
			{
				if (vecMatr[l] < vecMatr[l + 1] && matrPotok[vecMatr[l]][vecMatr[l + 1]] == 0)
					matrPotok[vecMatr[l]][vecMatr[l + 1]] = tempVect[i].second.second;
				else
					if (vecMatr[l] < vecMatr[l + 1])
						for (int k = 0; k < tempVect[i].second.first.size() - 1; k++)
						{
							for (int j = 0; j < tempVect[i].second.first.size() - 1; j++)
							{
								if (tempVect[k].second.first.at(j) == vecMatr[l] && tempVect[k].second.first.at(j + 1) == vecMatr[l + 1] &&
									matrPotok[vecMatr[l]][vecMatr[l + 1]] + tempVect[i].second.second <= bandwidthArr[vecMatr[l]][vecMatr[l + 1]])
									matrPotok[vecMatr[l]][vecMatr[l + 1]] += tempVect[i].second.second;
							}
						}
			}
			vecMatr.clear();
			vecPotok.push_back(tempVect[i].second.second);
		}


		cout << endl;
		for_each(resultVertex.begin(), resultVertex.end(), [&result, &f, &costArr](pair<int, int> x) {result += f.at(x.first).at(x.second) * costArr[x.first][x.second]; });


		cout << endl << "�������� �����:" << b << endl << endl << endl;
		cout << "����������� ��������� ��������� ������: " << result << endl << endl;
		cout << "������� ���������:" << endl;
		outArr(costArr);
		cout << endl << "������� ������:" << endl;

		outArr(matrPotok);
	}
}


/*���� ������� ����*/
void EulerGraphTrue(vector<vector<int>> EulerGr)
{
	int versh = EulerGr.size();
	if (versh == 2) {
		cout << endl;
		cout << "\n� ����� 2 �������! ������� ���� ����������!" << endl << endl;

		return;
	}


	bool flag = 0;

	if (!Euler(EulerGr))

		cout << endl << "\n���� �� �������� ���������!\n" << endl;

	else cout << endl << "���� �������� ���������!" << endl << endl;
}

/*������� ����*/
int Euler(vector<vector<int>> gr) {


	int n = gr.size();//���������� ������


	vector<int> degree;//������ �������� ������

	for (int i = 0; i < n; i++) {

		int sst = 0;

		for (int j = 0; j < n; j++) {

			if (gr[i][j] != 0) sst++;//������� ������� ��� ���� �� �������
		}

		degree.push_back(sst);//��������� � ������
	}

	int count = 0;

	for (int i = 0; i < n; i++) {

		if (degree[i] == 0) {//���� ������� ������� ����� ����

			count = 1;//������ ����� ���

			deg.clear();//������ ��������� ������, � ������� ����� �������� ����, �������� ���������, ����� ��� ����, ����� ��������� ����
			for (int i = 0; i < gr.size(); i++)

				deg.push_back(i);//�������, ��� ��� ������� 

			break;
		}


		if (degree[i] % 2 != 0) {//���� ������� ������� ��������

			count++;//������� ��

			deg.push_back(i);//�������, ��� ���� ����� ������ �������� ����, ����� �������� ����
		}
	}

	if (count > 0) return 0;//���� ����� ��� 

	int min = 100; int ind = 0;

	for (int i = 0; i < n; i++) {

		if (min > degree[i]) {

			min = degree[i];//����������� �� �������� ������

			ind = i;//����� ���� �������
		}
	}

	//������� ����!
	vector<int> res;

	stack<int> s;

	s.push(ind);//��������� � ���� ������� � ����������� ��������

	while (!s.empty()) {

		int i = s.top();//����� �������� �� �����

		if (degree[i] == 0) {//���� ���� �� ����

			s.pop();

			res.push_back(i);//��������� � ������ ����������
		}

		else {

			for (int j = 0; j < n; j++) {//�������� �� ��������� �������� 

				if (gr[i][j] != 0) {//���� ���� ����������

					gr[i][j] = 0;//�������� ��� ������

					gr[j][i] = 0;//�� ���� �� ���������������, �� � ��� �������

					degree[i] -= 1;//��������� ������� ��������������� ������

					degree[j] -= 1;

					s.push(j);//��������� � ���������

					break;
				}
			}
		}
	}

	if (res.size() != 0) {//������� ���������

		cout << endl << "������� ����: ";

		for (size_t i = res.size() - 1; i != 0; i--)

			cout << res[i] + 1 << "-";

		cout << res[0] + 1;
	}

	cout << endl << endl;


	return res.size();//���������� ������, � ������� �������� ����
}

/*���� ����������� ���� */
void GamiltonTrue(vector<vector<int>>& GamGr, vector<pair<int, int>>& path)
{

	if (GamGr.size() == 2) {

		cout << endl << "\n������ ������ ����. ����������� ���� �� ����� ������������" << endl << endl;

		return;
	}

	if (gamilton(GamGr, path))
	{
		cout << endl;
		cout << "���� �������� �������������!\n";
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "���� �� �������� �������������!\n";
		cout << endl;
	}
}

/*����������� ����*/
bool gamilton(vector<vector<int>>& GamGr, vector<pair<int, int>>& path) {

	int versh = GamGr.size();
	int ok = 0;


	path = vector<pair<int, int>>(GamGr.size());//������� ��� ���� �� ����� �������
	for (int i = 0; i < GamGr.size(); i++)
	{
		path[i].first = i;
		for (int j = 0; j < GamGr.size(); j++)
		{
			if (GamGr[i][j] == 1)
			{
				ok++;
			}

		}
		path[i].second = ok;
		ok = 0;
	}

	for (int i = 0; i < GamGr.size(); i++) {

		if (path[i].second < ((GamGr.size() / 2))) {//���� �� �����-�� ������� ��� ��� ���� �� � ��������

			return false;//�� ���� �� �������� �����������
		}
	}
	bool isHamiltonCicle = true;
	deque<int> que;
	for (int i = 0; i < GamGr.size(); i++) {
		que.push_back(i);//��������� ������� � ���
	}
	do {
		isHamiltonCicle = true;
		//cost = 0;
		if (GamGr[que.at(GamGr.size() - 1)][que.at(0)] > (INF / 2)) {//���� �� ���������� ���� �� ��������� � ������
			isHamiltonCicle = false;
		}
		else {
			for (int i = 0; i < GamGr.size() - 1; i++) {//�������� �� ����� ����
				if (GamGr[que.at(i)][que.at(i + 1)] > (INF / 2)) {//���� ��� ���� � �������� �������
					isHamiltonCicle = false;//�� ��� �����
				}
			}
		}
		if (isHamiltonCicle) {//���� ���� ����, �� ������� ���� 
			cout << endl;
			cout << "����������� ����:" << endl << endl;
			cout << que.at(0) + 1;

			for (int i = 1; i < que.size(); i++)
			{
				cout << " ->" << que.at(i) + 1;

			}


			cout << " -> " << que.at(0) + 1;
			cout << "\n";
			//cout << "\n���: " << cost << endl << endl;
			//if (cost < minCost) {
				//res.clear();
				//res.resize(que.size());
				//copy(que.begin(), que.end(), res.begin());
				//minCost = cost;
			//}
			break;
		}
		//������������ ��������� ��������� [first,last] � ��������������� ������� ������������
	} while (next_permutation(que.begin(), que.end()) && isHamiltonCicle);
	return isHamiltonCicle;
}

/*�������� �������� �� ���� ���������*/
void Is_Euler(vector<vector<int>>& EulerGr) {
	int versh = EulerGr.size();
	int n = versh;

	if (versh == 2) {
		cout << endl;
		cout << "\n� ����� 2 �������! ������� ���� �� ����� ������������!" << endl << endl;

		return;
	}

	int eu = Euler(EulerGr);//�������� �� ���� ���������

	bool flag = 0;

	while (!eu) {//���� ���

		flag = 1;
		vector<int> degree1;//������ �������� ������ 
		for (int i = 0; i < n; i++) {

			int sst = 0;

			for (int j = 0; j < n; j++) {

				if (EulerGr[i][j] != 0) sst++;
			}

			degree1.push_back(sst);
		}

		srand(time(NULL));

		bool isChanged = false;

		for (int i = 0; i < deg.size(); i++) {//�������� �� ���� ���������, ������� ��������� � �������-��������

			for (int j = i + 1; j < deg.size(); j++) {//������ ������ ������� �����������, �� ���� �����������������

				if (EulerGr[deg[i]][deg[j]] == 0) {//���� ��� �����

					EulerGr[deg[i]][deg[j]] = 1;//���������

					EulerGr[deg[j]][deg[i]] = 1;

					cout << endl << "��������� ����� " << deg[i] + 1 << "-" << deg[j] + 1 << endl << endl;

					isChanged = true;//�������� ���������

					break;
				}

				if (EulerGr[deg[i]][deg[j]] == 1) {//���� ����� ���� 


					EulerGr[deg[i]][deg[j]] = 0;//������� ���, ��������� ��������

					EulerGr[deg[j]][deg[i]] = 0;

					cout << endl << "������� ����� " << deg[i] + 1 << "-" << deg[j] + 1 << endl << endl;

					if (degree1[deg[i]] == 1 && degree1[deg[j]] % 2 != 0 && degree1[deg[j]] != 1)//������� ����� ������� ����� 1, ������� ������ �������� � �� ����� 1
					{
						if (deg[i] != n - 1)//��������� �����  
						{
							EulerGr[deg[i]][n - 1] = 1;
							EulerGr[n - 1][deg[i]] = 1;
							cout << endl;
							cout << "��������� �����: " << deg[i] + 1 << "-" << n << endl << endl;
						}
						else
						{
							EulerGr[deg[i]][0] = 1;
							EulerGr[0][deg[i]] = 1;
							cout << endl;
							cout << "��������� �����: " << 1 << "-" << deg[i] + 1 << endl << endl;
						}
						if (deg[i] != n - 2)
						{
							EulerGr[deg[i]][n - 2] = 1;
							EulerGr[n - 2][deg[i]] = 1;
							cout << endl;
							cout << "��������� �����: " << deg[i] + 1 << "-" << n - 1 << endl << endl;
						}
						else
						{
							EulerGr[deg[i]][0] = 1;
							EulerGr[0][deg[i]] = 1;
							cout << endl;
							cout << "��������� �����: " << 1 << "-" << deg[i] + 1 << endl << endl;
						}

					}

					if (degree1[deg[j]] == 1 && degree1[deg[i]] % 2 != 0 && degree1[deg[i]] != 1)//���������� ���������� ���������, ������ � �������� �������
					{
						if (deg[j] != n - 1 && EulerGr[deg[i]][deg[j]] == 0)
						{
							EulerGr[deg[j]][n - 1] = 1;
							EulerGr[n - 1][deg[i]] = 1;
							cout << endl << "��������� �����: " << deg[j] + 1 << "-" << n << endl << endl;
						}
						else
						{
							EulerGr[deg[j]][0] = 1;
							EulerGr[0][deg[j]] = 1;
							cout << endl << "��������� �����: " << 1 << "-" << deg[j] + 1 << endl << endl;
						}
						if (deg[j] != n - 2 && EulerGr[deg[i]][deg[j]] == 0)
						{
							EulerGr[deg[j]][n - 2] = 1;
							EulerGr[n - 2][deg[j]] = 1;
							cout << endl << "��������� �����: " << deg[j] + 1 << "-" << n - 1 << endl << endl;
						}
						else
						{
							EulerGr[deg[j]][0] = 1;
							EulerGr[0][deg[j]] = 1;
							cout << endl << "��������� �����: " << 1 << "-" << deg[j] + 1 << endl << endl;
						}
					}
					isChanged = true;//�������� ���������
					break;
				}
			}
			if (isChanged)
				break;
		}

		deg.clear();//������� ������ ��������� ������

		eu = Euler(EulerGr);//���������
	}

	if (flag) {//���� ������ ����

		cout << endl << "���������� �������: " << endl << endl;

		outArr(EulerGr);
	}
	cout << endl;

	deg.clear();
}

/*�������� �������� �� ���� �������������*/
void Is_Gam(vector<vector<int>>& GamGr, vector<pair<int, int>>& path) {


	int versh = GamGr.size();
	int n = versh;
	int c = 0;
	bool flagGam = true;
	vector<int> v0;
	bool flag = false; //���� �������� ����������� ����
	bool add = false;
	bool first = 1;//��������� ��������� 1 ���
	bool f = false;

	if (n < 3) {
		cout << endl << "\n���� ������ ������� �������������! ������ ������ ����!" << endl << endl;
		return;
	}

	while (flagGam)
	{
		if (gamilton(GamGr, path))
		{
			cout << endl;
			cout << "���� �������� �������������!" << endl;
			cout << endl;
			flagGam = false;
			flag = true;
			break;
		}
		else
		{
			cout << endl;
			cout << "���������� ��������� ����!" << endl;
			cout << endl;
			add = false;
			while (!flag)
			{

				for (int i = 0; i < n; i++)
				{

					if (path[i].second < n / 2 && !add)
					{
						v0.push_back(path[i].first);
					}
				}
				for (int i = 0; i < v0.size(); i++)
				{
					for (int j = 0; j < n; j++)
					{
						if (!add)
						{
							if (GamGr[v0[i]][j] == 999 && v0[i] != j)
							{
								if (v0.size() == 2 && GamGr[v0[i]][v0[i + 1]] == INF)
								{
									GamGr[v0[i]][v0[i + 1]] = 1;
									GamGr[v0[i + 1]][v0[i]] = 1;
									if (v0[i] + 1 < v0[i + 1] + 1)
										cout << endl << "��������� ����� " << v0[i] + 1 << " - " << v0[i + 1] + 1 << endl << endl;
									else
										cout << endl << "��������� ����� " << v0[i + 1] + 1 << " - " << v0[i] + 1 << endl << endl;
									add = true;
									f = true;
								}
								else {
									GamGr[v0[i]][j] = 1;
									GamGr[j][v0[i]] = 1;
									if (v0[i] + 1 < j + 1)
										cout << endl << "��������� ����� " << v0[i] + 1 << " - " << j + 1 << endl << endl;
									else
										cout << endl << "��������� ����� " << j + 1 << " - " << v0[i] + 1 << endl << endl;
									add = true;
									f = true;
								}
							}
						}
					}
				}
				flag = gamilton(GamGr, path);
				add = false;
				v0.clear();
			}
		}
	}

	if (f)
	{
		cout << endl;
		cout << "���������� �������:" << endl;
		outArr(GamGr);
		cout << endl;
	}
	cout << endl;
}


/*������ ������������*/
void TSP(vector<vector<int>>& GamGr)
{
	vector<vector<int>> GamGrVes = vector<vector<int>>(GamGr.size(), vector<int>(GamGr.size(), 0));

	int n = GamGr.size();
	for (int i = 0; i < n; ++i)

	{
		for (int j = i + 1; j < n; j++)

		{
			if (GamGr[i][j] == 999)
			{
				GamGrVes[i][j] = 0;
				GamGrVes[j][i] = 0;
			}
			else
			{
				GamGrVes[i][j] = rand() % 9 + 1;

				GamGrVes[j][i] = rand() % 8 + 1;
			}

		}
	}
	cout << endl;
	cout << "������� ��������� ������������ �����:" << endl;
	outArr(GamGrVes);
	cout << endl;

	if (n < 3)
	{
		cout << endl;
		cout << "\n������ 3 ������! ���������� ������ ������ ������������!\n";
		cout << endl;
		return;
	}
	int cost = 0;
	int minCost = INF * n;
	deque<int> que;
	deque<int> res;

	ofstream f;
	f.open("Text.txt", ofstream::out);

	cout << endl;
	cout << "����� ������������� ��������\n1 - �� �����\n2 - � ����\n";
	int op = Input();
	bool flag;
	switch (op)
	{
	case 1:
		flag = false;
		break;
	case 2:
		flag = true;
		break;
	}

	bool isHamiltonCicle = true;
	for (int i = 0; i < n; i++) {
		que.push_back(i);
	}
	do {
		isHamiltonCicle = true;
		cost = 0;
		if (GamGr[que.at(n - 1)][que.at(0)] > (INF / 2)) {
			isHamiltonCicle = false;
		}
		else {
			for (int i = 0; i < n - 1; i++) {
				if (GamGr[que.at(i)][que.at(i + 1)] > (INF / 2)) {
					isHamiltonCicle = false;
				}
				else {
					cost += GamGrVes[que.at(i)][que.at(i + 1)];
				}
			}
		}
		if (isHamiltonCicle) {

			cost += GamGrVes[que.at(n - 1)][que.at(0)];
			if (flag)
			{
				cout << endl;
				f << "����������� ����:" << endl;
				f << que.at(0) + 1;
				for (int i = 1; i < que.size(); i++)
				{
					f << " -> " << que.at(i) + 1;
				}
				f << " -> " << que.at(0) + 1;
				f << "\n";
				f << endl << "\n���: " << cost << endl << endl;
			}
			else
			{
				cout << endl;
				cout << "����������� ����:" << endl;
				cout << que.at(0) + 1;
				for (int i = 1; i < que.size(); i++)
				{
					cout << " -> " << que.at(i) + 1;
				}
				cout << " -> " << que.at(0) + 1;
				cout << "\n";
				cout << endl << "\n���: " << cost << endl << endl;
			}
			if (cost < minCost) {
				res.clear();
				res.resize(que.size());
				copy(que.begin(), que.end(), res.begin());
				minCost = cost;
			}
		}

	} while (next_permutation(que.begin(), que.end()));

	//f.close();

	cout << endl << "����������� ����������� ����: " << endl;
	cout << res.at(0) + 1;
	for (int i = 1; i < res.size(); i++)
	{
		cout << " -> " << res.at(i) + 1;
	}
	cout << " -> " << res.at(0) + 1;
	cout << endl << "\n���: " << minCost << endl << endl;
}


