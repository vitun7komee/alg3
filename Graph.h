#pragma once
#pragma once
#include <iostream>
class Graph
{
	int size;
	int** matrix;
public:
	//Graph()/* { size = 0; }*/;
	Graph(int n);
	Graph(int** a, int n);
	~Graph();
	//Graph(const Graph& gr);
	Graph& operator=(const Graph& gr);
	int getsize();
	int** getmatrix();
	bool add_edge(int line, int column);
	bool remove_edge(int line, int column);
	void add_vertex();
	bool remove_vertex(int n);
	bool check_edge(int n1, int n2);
	friend std::ostream& operator<<(std::ostream& on, const Graph& gr);
};
