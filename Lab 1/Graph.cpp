/*
    Taylor, Charlie

    February 10, 2021

    CS A200
    Lab 1
*/

#include "Graph.h"

using namespace std;

// Definition function operator<<
ostream& operator<<(ostream& out, map<int, set<int>> courses)
{
    out << "COURSES:";
    for(auto const &i : courses)
    {
        printPrerequisites(i.second);
    }
}

// Definition default constructor
Graph::Graph()
{
    map<int, set<int>> * graph = new map<int, set<int>>;
    numOfCourses = 0;
}

// Definition copy constructor
// Add "noexcept" at the end of the header.
Graph::Graph(const Graph& other) noexcept
{

}

// Definition function operator=
// Add "noexcept" at the end of the header.
Graph& Graph::operator=(const Graph& graph) noexcept
{

}

// Definition destructor
Graph::~Graph()
{
    clearGraph();
}

// Definition function createGraph
void Graph::createGraph(std::vector<std::vector<int>>)
{

}

// Definition function isEmpty
bool Graph::isEmpty() const
{
    return !numOfCourses;
}

// Definition function printAllCourses
void Graph::printAllCourses() const
{

}

// Definition function printPrerequisites
void Graph::printPrerequisites(int course) const
{
    map<int, set<int>>::iterator it;
    cout << COURSE_PREFIX << course;
    for(it = graph.begin(); it != graph.end(); ++it)
    {

    }
}

// Definition function clearGraph
void Graph::clearGraph()
{

}

