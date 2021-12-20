#include "Graph.h"

int main() {


	setlocale(LC_ALL, "Russian");
	cout << endl << endl;
	cout << "Теория графов\nЛабораторные 1 - 5\n Верещагина Софья\n3630201/90002\n";


	vector<vector<int>> matrAdg;
	vector<vector<int>> matrVesov;
	vector<vector<int>> matrNegVesov;

	vector<vector<int>> cost;
	vector<vector<int>> bandwidth;

	vector<vector<int>> EulerGr;
	vector<vector<int>> GamGr;
	vector<pair<int, int>> path;

	vector<set<int>>* ostov = nullptr;
	vector<int>pruferCode;

	char op;

	srand(time(NULL));
	int count = initCount();
	ArrInit(matrAdg, count);
	cout << endl;
	cout << "Матрица смежности: \n";
	cout << endl;
	outArr(matrAdg);

	initMatrVesov(matrAdg, matrVesov, 0);
	cout << endl;
	cout << "Матрица весов: \n";
	cout << endl;
	outArr(matrVesov);

	initMatrVesov(matrAdg, matrNegVesov, 1);
	cout << endl;
	cout << "Матрица с отрицательными весами: \n";
	cout << endl;
	outArr(matrNegVesov);
	InitWithINF(matrAdg, matrVesov, matrNegVesov);

	int q = 1;

	while (q)
	{
		cout << "\nЛабораторная 1\n";
		cout << "\nВыберите действиe\n1 - Сгенерировать новый граф\n2 - Метод Шимбелла\n3 - Возможность построения маршрута от одной вершины до другой\n";
		cout << "\nЛабораторная 2\n";
		cout << "\n4 - Алгоритм Дейкстры\n5 - Алгоритм Форда - Беллмана\n6 - Алгоритм Флойда – Уоршалла\n";
		cout << "\nЛабораторная 3\n";
		cout << "\n7 - Алгоритм Прима\n8 - Алгоритм Краскала\n9 - Матричная т. Кирхгофа\n10 - Кодирование кодом Прюфера \n11 - Декодирование кода Прюфера\n";
		cout << "\nЛабораторная 4\n";
		cout << "\n12 - Построение матрицы пропускных способностей и стоимости \n13 - Алгоритм Форда - Фалкерсона\n14 - Поток минимальной стоимости\n";
		cout << "\nЛабораторная 5\n";
		cout << "\n15 - Является ли граф Эйлеровым или Гамильтоновым \n16 - Эйлеров цикл \n17 - Гамильтонов цикл \n18 - Задача Коммивояжера\n";
		cout << "\n0 - Выход\n";

		q = Input();

		switch (q)
		{
		case 1: {int count = initCount();
			ArrInit(matrAdg, count);
			cout << endl;
			cout << "Матрица смежности: \n";
			cout << endl;
			outArr(matrAdg);

			initMatrVesov(matrAdg, matrVesov, 0);
			cout << endl;
			cout << "Матрица весов: \n";
			cout << endl;
			outArr(matrVesov);

			initMatrVesov(matrAdg, matrNegVesov, 1);
			cout << endl;
			cout << "Матрица с отрицательными весами: \n";
			cout << endl;
			outArr(matrNegVesov);
			InitWithINF(matrAdg, matrVesov, matrNegVesov);
			break; }
		case 2: {
			InitWithNull(matrAdg, matrVesov, matrNegVesov);
			cout << endl;
			cout << "1 - матрица с положительными весами\n2 - матрица с отрицательными весами\n";
			cout << endl;
			op = Input();
			bool f;
			switch (op)
			{
			case 1:
				ShimbellMenu(matrVesov);
				break;
			case 2:
				ShimbellMenu(matrNegVesov);
				break;
			}
			break;

			InitWithINF(matrAdg, matrVesov, matrNegVesov);
			break;
		}
		case 3: {
			InitWithNull(matrAdg, matrVesov, matrNegVesov);
			IsPathExist(matrAdg);
			InitWithINF(matrAdg, matrVesov, matrNegVesov);
			break;
		}
			///** 
		case 4: {
			DijkstraMenu(matrVesov);
			break;
		} 
		case 5: {
			cout << endl;
			cout << "1 - матрица с положительными весами\n2 - матрица с отрицательными весами\n";
			cout << endl;
			op = Input();
			bool f;
			switch (op)
			{
			case 1:
				BellmanFordMenu(matrVesov);
				break;
			case 2:
				BellmanFordMenu(matrNegVesov);
				break;
			}
			break;
		}
		case 6: {
			cout << endl;
			cout << "1 - матрица с положительными весами\n2 - матрица с отрицательными весами\n";
			cout << endl;
			op = Input();
			bool f;
			switch (op)
			{
			case 1:
				Warshall(matrVesov);
				break;
			case 2:
				Warshall(matrNegVesov);
				break;
			}
			break;
		} 
			 // /*
		case 7: {
			cout << endl;
			cout << "1 - матрица с положительными весами\n2 - матрица с отрицательными весами\n";
			cout << endl;
			op = Input();
			bool f;
			switch (op)
			{
			case 1:
				ChangeToUnoriented(matrAdg, matrVesov);
				if (ostov != nullptr)
					if (!ostov->empty())
						ostov->clear();
				ostov = Prim(matrAdg, matrVesov);
				ChangeToOriented(matrAdg, matrVesov);
				break;
			case 2:
				ChangeToUnoriented(matrAdg, matrNegVesov);
				if (ostov != nullptr)
					if (!ostov->empty())
						ostov->clear();
				ostov = Prim(matrAdg, matrNegVesov);
				ChangeToOriented(matrAdg, matrNegVesov);
				break;
			}
			break;
		}
		case 8: {
			cout << endl;
			cout << "1 - матрица с положительными весами\n2 - матрица с отрицательными весами\n";
			cout << endl;
			op = Input();
			bool f;
			switch (op)
			{
			case 1:
				ChangeToUnoriented(matrAdg, matrVesov);
				if (!ostov->empty())
					ostov->clear();
				ostov = Kruskal(matrAdg, matrVesov);
				ChangeToOriented(matrAdg, matrVesov);
				break;
			case 2:
				ChangeToUnoriented(matrAdg, matrNegVesov);
				if (!ostov->empty())
					ostov->clear();
				ostov = Kruskal(matrAdg, matrNegVesov);
				ChangeToOriented(matrAdg, matrNegVesov);
				break;
			}
			break;
		}
		case 9: {
			cout << endl;
			cout << "1 - матрица с положительными весами\n2 - матрица с отрицательными весами\n";
			cout << endl;
			op = Input();
			bool f;
			switch (op)
			{
			case 1:
				ChangeToUnoriented(matrAdg, matrVesov);
				Kirhgof(matrAdg, matrVesov);
				ChangeToOriented(matrAdg, matrVesov);
				break;
			case 2:
				ChangeToUnoriented(matrAdg, matrNegVesov);
				Kirhgof(matrAdg, matrNegVesov);
				ChangeToOriented(matrAdg, matrNegVesov);
				break;
			}
			break;
		}
		case 10:
			PruferCoding(ostov, pruferCode);
			break;
		case 11:
			PruferEncoding(ostov, pruferCode);
			break;
		case 12:
		{
			if (!cost.empty())
			{
				cost.clear();
				bandwidth.clear();
			}
			initCost(matrAdg, cost, bandwidth);
			break;
		}
		case 13: {
			int potok = fordFulkerson(0, matrAdg.size() - 1, cost, bandwidth, 1);
			if (potok != 0)
				cout << endl << "\nМаксимальный поток: " << potok << endl << endl;
			break; }
		case 14: //если оставить заданным - максимальный поток, то количество итераций выйдет за пределы
			MinCostMaxFlow((int)(2* fordFulkerson(0, matrAdg.size() - 1, cost, bandwidth, 0)/3), matrAdg, cost, bandwidth);
			break;	
		case 15: {
			ChangeToUnoriented(matrAdg, matrVesov);
			InitWithNull(matrAdg, matrVesov, matrNegVesov);
			if (!EulerGr.empty())
				EulerGr.clear();
			if (!GamGr.empty())
				GamGr.clear();
			if (!path.empty())
				path.clear();
			EulerGr = vector<vector<int>>(matrAdg);
			EulerGraphTrue(EulerGr);
			InitWithINF(matrAdg, matrVesov, matrNegVesov);
			GamGr = vector<vector<int>>(matrAdg);
			cout << endl;
			GamiltonTrue(GamGr, path);
			ChangeToOriented(matrAdg, matrVesov);
			break;
		}
		case 16:
			ChangeToUnoriented(matrAdg, matrVesov);
			InitWithNull(matrAdg, matrVesov, matrNegVesov);
			if (!EulerGr.empty())
				EulerGr.clear();
			EulerGr = vector<vector<int>>(matrAdg);
			Is_Euler(EulerGr);
			InitWithINF(matrAdg, matrVesov, matrNegVesov);
			ChangeToOriented(matrAdg, matrVesov);
			break;
		case 17:
			ChangeToUnoriented(matrAdg, matrVesov);
			//InitWithNull(matrAdg, matrVesov, matrNegVesov);
			if (!GamGr.empty())
				GamGr.clear();
			if (!path.empty())
				path.clear();
			GamGr = vector<vector<int>>(matrAdg);
			Is_Gam(GamGr, path);
			//InitWithINF(matrAdg, matrVesov, matrNegVesov);
			ChangeToOriented(matrAdg, matrVesov);
			break;
		case 18: {
			if (GamGr.empty())
			{
				cout << endl;
				cout << "Гамильтонов граф не задан\n";
				cout << endl;
			}
			else TSP(GamGr);
			break;
		}
		case 0: {
			break; }
		default:
			cout << endl << "\nОшибка!\nПопробуйте еще раз: " << endl;
			break;
		}

	}

	return 0;
}