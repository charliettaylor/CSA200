#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

const std::string COURSE_PREFIX = "CS A";

class Graph
{
	// Declaration friend function operator<<
	friend std::ostream& operator<<(std::ostream& out, Graph& graph);

public:
	// Declaration default constructor
	Graph();

	// Declarations for the Big Three
	Graph(const Graph& other) noexcept;
	Graph& operator=(const Graph& graph) noexcept;
	~Graph();
	// Declaration function createGraph
	void createGraph(std::vector<std::vector<int>>);

	// Declaration function isEmpty
	bool isEmpty() const;

	// Declarations of print functions
	void printAllCourses() const;
	void printPrerequisites(int course) const;
	// Declaration function clearGraph
	void clearGraph();

private:
	std::map<int, std::set<int>> * graph;
    int numOfCourses;
};

#endif