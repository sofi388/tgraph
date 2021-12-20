
#pragma once
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <utility>
#include <iostream>
#include <deque>
#include <queue>
#include <fstream>
#include <conio.h>
#include <vector>
#include <ctime>
#include <algorithm>
#include <set>
#include <map>
#include <random>
#include <stack>

using namespace std;

int Input();
int initCount();

//void printMenu();

int ArrInit(vector<vector<int>>& arr, int n);
//int random_generator();


//1 лабораторная
void initMatrVesov(vector<vector<int>>& arr, vector<vector<int>>& matrVesov, bool f);
void InitWithINF(vector<vector<int>>& arr, vector<vector<int>>& matrVesov, vector<vector<int>>& matrNegVesov);
void InitWithNull(vector<vector<int>>& arr, vector<vector<int>>& matrVesov, vector<vector<int>>& matrNegVesov);
int outArr(vector<vector<int>>& arr);
int matrixMultiply(vector<vector<int>>& arr1, vector<vector<int>>& arr2, bool ExtrPath);
int Shimbell(vector<vector<int>>& arr, int n1, int ExtrPath);
int ShimbellMenu(vector<vector<int>>& arr);
int IsPathExist(vector<vector<int>>& arr);
bool dfs(int u, int t, vector<bool>& visited, vector<vector<int>>& arr);

class edge {
	int a, b, cost;
public:
	edge(int m_a, int m_b, int m_cost) { a = m_a; b = m_b; cost = m_cost; }
	int getA() { return a; }
	int getB() { return b; }
	int getCost() { return cost; }
	bool operator < (const edge& other) { return cost < other.cost; }
};


//2 лабораторная
void DijkstraMenu(vector<vector<int>> arr);
void Dijkstra(vector<vector<int>> arr, int a, int c);
void BellmanFordMenu(vector<vector<int>> arr);
vector<int> BellmanFord(vector<vector<int>> arr, int a, bool Print);
void  Warshall(vector<vector<int>>& arr);



//3 лабораторная
void ChangeToUnoriented(vector<vector<int>>& arr, vector<vector<int>>& matrixVesov);
void ChangeToOriented(vector<vector<int>>& arr, vector<vector<int>>& matrixVesov);
vector<set<int>>* Kruskal(vector<vector<int>>& arr, vector<vector<int>>& matrixVesov);
vector<set<int>>* Prim(vector<vector<int>>& arr, vector<vector<int>>& matrixVesov);
void Kirhgof(vector<vector<int>>& arr, vector<vector<int>>& matrixVesov);
int findMinor(vector<vector<int>>& buffer, int x, int y);
void PruferCoding(vector<set<int>>* ostov, vector<int>& pruferCode);
void PruferEncoding(vector<set<int>>* ostov, vector<int>& pruferCode);


//4 лабораторная
void initCost(vector<vector<int>> arr, vector<vector<int>>& cost, vector<vector<int>>& bandwidth);
int fordFulkerson(int s, int t, vector<vector<int>>& cost, vector<vector<int>>& bandwidth, bool Print);
bool bfs(vector<vector<int>> rGraph, int s, int t, vector<int>& parent);
void MinCostMaxFlow(int b, vector<vector<int>>& arr, vector<vector<int>>& costArr, vector<vector<int>>& bandwidthArr);


//5 лабораторная
void EulerGraphTrue(vector<vector<int>> EulerGr);
int Euler(vector<vector<int>> gr);
void Is_Euler(vector<vector<int>>& EulerGr);
void GamiltonTrue(vector<vector<int>>& GamGr, vector<pair<int, int>>& path);
bool gamilton(vector<vector<int>>& GamGr, vector<pair<int, int>>& path);
void Is_Gam(vector<vector<int>>& GamGr, vector<pair<int, int>>& path);
void TSP(vector<vector<int>>& GamGr);