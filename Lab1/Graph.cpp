/*
    Taylor, Charlie

    February 10, 2021

    CS A200
    Lab 1
*/

#include "Graph.h"

using namespace std;

// Definition function operator<<
ostream& operator<<(ostream& out, Graph& print)
{
    out << "COURSES:";
    map<int, set<int>>::iterator it;
    for(it = print.graph->begin(); it != print.graph->end(); ++it)
    {
        out << COURSE_PREFIX << it->first << "\n";
        for(const auto& prereq : it->second)
        {
            out << prereq << "\n";
        }
    }
    return out;
}

// Definition default constructor
Graph::Graph()
{
    graph = new map<int, set<int>>;
    numOfCourses = 0;
}

// Definition copy constructor
// Add "noexcept" at the end of the header.
Graph::Graph(const Graph& other) noexcept
{
    clearGraph();
    delete graph;
    graph = new map<int, set<int>>(*(other.graph));
    numOfCourses = other.numOfCourses;
    //map<int, set<int>>::iterator it = other.graph->begin();
    //map<int, set<int>>::iterator end = other.graph->end();

    //for(; it != end; ++it)
    //{
    //    graph->insert(*it);
    //}
}

// Definition function operator=
// Add "noexcept" at the end of the header.
Graph& Graph::operator=(const Graph& rhd) noexcept
{
    if(this == &rhd)
    {
        return *this;
    }
    else
    {
        clearGraph();
        map<int, set<int>>::iterator it;
        for(it = rhd.graph->begin(); it != rhd.graph->end(); ++it)
        {
            graph->insert(make_pair(it->first, it->second));
        }
        numOfCourses = rhd.numOfCourses;
    }
}

// Definition destructor
Graph::~Graph()
{
    clearGraph();
}

// Definition function createGraph
void Graph::createGraph(vector<vector<int>> list)
{
    for(const auto& subList : list)
    {
        set<int> temp;
        vector<int>::const_iterator it = subList.cbegin() + 1;
        for(; it != subList.cend(); ++it)
        {
            temp.insert(*it);
        }
        graph->insert(make_pair(subList[0], temp));
    }
}

// Definition function isEmpty
bool Graph::isEmpty() const
{
    return !numOfCourses;
}

// Definition function printAllCourses
void Graph::printAllCourses() const
{
    map<int, set<int>>::const_iterator it = graph->begin();
    for(; it != graph->end(); ++it)
    {
        cout << it->first << "\n";
    }
}

// Definition function printPrerequisites
void Graph::printPrerequisites(int course) const
{
    set<int>::iterator it;
    cout << COURSE_PREFIX << course;
    for(it = (*graph)[course].begin(); it != (*graph)[course].end(); ++it)
    {
        cout << *it << "\n";
    }
}

// Definition function clearGraph
void Graph::clearGraph()
{
    graph->clear();
}

