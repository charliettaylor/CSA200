#include "Graph.h"

#include <iostream>
#include <string> 
#include <vector>

using namespace std;

void printGraph(const Graph&);

int main()
{
	vector <int> courses =
	{ 100, 140, 150, 170, 200, 216, 220, 250, 265, 272 };

	vector<vector <int>> graph1Data = {
		{ 100 },
		{ 140, 100 },
		{ 150, 140 },
		{ 170, 100 },
		{ 200, 150, 265 },
		{ 216, 100 },
		{ 220, 216, 250 },
		{ 250, 150 },
		{ 265 },
		{ 272, 170 },
	};

	{
		cout << "TEST: default constructor, createGraph,"
			<< " isEmpty, printAllCourses\n\n";;
		Graph graph;
		graph.createGraph(graph1Data);
		printGraph(graph);
	}

	cout << "\n==================================================\n";

	{
		cout << "TEST: clearGraph\n\n";;
		Graph graph1;
		graph1.createGraph(graph1Data);
		printGraph(graph1);

		cout << "\nEmpty graph...\n";
		graph1.clearGraph();
		cout << endl;
		printGraph(graph1);
	}

	cout << "\n==================================================\n";

	{
		cout << "TEST: printPrerequisites\n\n";;
		Graph graph1;
		graph1.createGraph(graph1Data);
		printGraph(graph1);
		cout << endl;

		for (auto const &i : courses)
		{
			cout << "CS A" << i << " - Prerequisites: ";
			graph1.printPrerequisites(i);
			cout << endl;
		}
	}

	cout << "\n==================================================\n";

	{
		cout << "TEST: copy constructor\n\n";;
		Graph graph1;
		graph1.createGraph(graph1Data);
		cout << "Graph 1 - ";
		printGraph(graph1);
		cout << endl;

		cout << "Creating new graph using copy constructor...\n";
		Graph newGraph(graph1);
		cout << "Emptying graph 1...\n";
		graph1.clearGraph();
		cout << "Check graph 1 (should be empty)...\n";
		cout << "Graph 1 - ";
		printGraph(graph1);
		cout << "Checking new graph...\n";
		printGraph(newGraph);

	}

	cout << "\n==================================================\n";

	{
		cout << "TEST: overloaded assignment operator\n\n";;
		Graph graph1;
		graph1.createGraph(graph1Data);
		cout << "Graph 1 - ";
		printGraph(graph1);
		cout << endl;

		cout << "Creating new graph with new set of courses...\n";
		vector<vector<int>> newGraphData = {
			{ 300 },
			{ 301, 300 },
		};
		Graph newGraph;
		newGraph.createGraph(newGraphData);
		cout << "New graph - ";
		printGraph(newGraph);
		cout << "\nCopying graph 1 into new graph "
			<< "using overloaded assignment operator...\n";
		newGraph = move(graph1);
		cout << "\nEmptying graph 1...";
		cout << "\nCheck graph 1 (should be empty)...\n";
		cout << "Graph 1 - ";
		printGraph(graph1);
		cout << "\nChecking new graph...\n";
		printGraph(newGraph);

	}

	cout << "\n==================================================\n";

	{
		cout << "TEST: overloaded insertion operator\n\n";;
		Graph graph;
		graph.createGraph(graph1Data);
		cout << graph;
	}

	cout << "\n==================================================\n";


	cout << endl;
	return 0;
}

void printGraph(const Graph& graph)
{
	if (graph.isEmpty())
		cerr << "Graph is empty.\n";
	else
	{
		cout << "COURSES:\n";
		graph.printAllCourses();
	}
}