#include "Graph.h"
Graph::Graph(int n)
{
	size = n;
	matrix = new int* [size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++)
			matrix[i][j] = 0;
	}
}

Graph::Graph(int** a, int n)
{
	size = n;
	matrix = new int* [size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++)
			matrix[i][j] = a[i][j];
	}
}

Graph::~Graph()
{
	delete[] matrix;
}

//Graph::Graph(const Graph& gr)
//{
//	size = gr.size;
//	matrix = new int* [size];
//	for (int i = 0; i < size; i++)
//	{
//		matrix[i] = new int[size];
//		for (int j = 0; j < size; j++)
//			matrix[i][j] = matrix[i][j];
//	}
//}

Graph& Graph::operator=(const Graph& gr)
{
	if (this == &gr) return *this;
	delete[] matrix;
	size = gr.size;
	int** matrix = new int* [size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++)
			matrix[i][j] = gr.matrix[i][j];
	}
	return *this;
}

int Graph::getsize()
{
	return size;
}

int** Graph::getmatrix()
{
	return matrix;
}

bool Graph::add_edge(int line, int column)
{
	if (matrix[line][column] == 0)
	{
		matrix[line][column] = 1;
		matrix[column][line] = 1;
		return 1;
	}
	return 0;
}

bool Graph::remove_edge(int line, int column)
{
	if (matrix[line][column] == 1)
	{
		matrix[line][column] = 0;
		matrix[column][line] = 0;
		return 1;
	}
	return 0;
}

void Graph::add_vertex()
{
	++size;
	int** arr = new int* [size];
	for (int i = 0; i < size - 1; i++)
	{
		arr[i] = new int[size];
		for (int j = 0; j < size - 1; j++)
			arr[i][j] = matrix[i][j];
		arr[i][size - 1] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		arr[size - 1][i] = 0;
	}
	matrix = new int* [size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++)
			matrix[i][j] = arr[i][j];
	}
	delete[] arr;
}

bool Graph::remove_vertex(int n)
{
	if (n > size) return false;
	for (int i = 0; i < size; i++)
		for (int j = n; j < size - 1; j++)
			matrix[i][j] = matrix[i][j + 1];
	for (int i = 0; i < size - 1; i++)
		for (int j = n; j < size - 1; j++)
			matrix[j][i] = matrix[j + 1][i];
	int** arr = new int* [--size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
		for (int j = 0; j < size; j++)
			arr[i][j] = matrix[i][j];
	}
	matrix = new int* [size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++)
			matrix[i][j] = arr[i][j];
	}
	delete[] arr;
	return true;
}

bool Graph::check_edge(int n1, int n2)
{
	return matrix[n1][n2];
}

std::ostream& operator<<(std::ostream& on, const Graph& gr)
{
	for (int i = 0; i < gr.size; i++)
	{
		for (int j = 0; j < gr.size; j++)
			on << gr.matrix[i][j] << ' ';
		on << '\n';
	}
	return on;
}
