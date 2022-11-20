#include <iostream>
#include <fstream>
#include "Graph.h"
#include <queue>
#include <vector>

void print(int** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			std::cout << *(*(arr + i) + j) << "  ";
		std::cout << std::endl;
	}
}

void task(Graph& gr) {

	int s = gr.getsize();
	int** arr = gr.getmatrix();

	std::queue<int> que;
	std::vector<bool> vec(s);
	for (auto val : vec)
	{
		val = false;
	}
	int cur = 2;
	que.push(cur);
	vec[cur] = true;
	while (!que.empty())
	{
		cur = que.front();
		que.pop();
		for (int j = 0; j < s; ++j)
		{
			if (1 == arr[cur][j] && vec.at(j) != true)
			{
				vec.at(j) = true;
				que.push(j);
			}
		}
	}
	bool ret = true;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i] != true)
		{
			ret = false;
			break;
		}
	}
	int edges = 0;
	for (int i = 0; i < s; ++i)
	{
		for (int j = 0; j < s; ++j)
		{
			if (arr[i][j] == 1)
			{
				++edges;
			}
		}
	}
	edges /= 2;

	bool e;
	if (edges == s - 1) { e = true; }
	else { e = false; }
	std::cout << "\nGraph is tree : " << (ret && e ? "YES!" : "NO!") << std::endl;

}

void main()
{

	int size;
	std::fstream file("data.txt");
	file >> size;
	std::cout << size << std::endl;
	Graph Gr(size);
	int** array = new int* [size];
	for (int i = 0; i < size; ++i)
		*(array + i) = new int[size];
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++) {
			file >> array[i][j];
		}
	}
	print(array, size);
	Graph TopG(array, size);
	std::cout << std::endl;
	task(TopG);


}