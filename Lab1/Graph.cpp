/*
    Taylor, Charlie

    February 19, 2021

    CS A200
    Lab 1: Graphs
*/

#include "Graph.h"

using namespace std;

// Definition function operator<<
ostream& operator<<(ostream& out, const Graph& otherGraph)
{
    for(const auto& course : *otherGraph.graph)
    {
        out << COURSE_PREFIX << course.first << ": ";
        if(course.second.empty())
        {
            out << "No prerequisites.";
        }
        else
        {
            for(const auto& prereq : course.second)
            {
                out << COURSE_PREFIX << prereq << " ";
            }
        }
        out << "\n";
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
Graph::Graph(const Graph& otherGraph) noexcept
{
    graph = new map<int, set<int>>;
    numOfCourses = otherGraph.numOfCourses;
    if(numOfCourses > 0)
    {
        *graph = *otherGraph.graph;
    }
}

// Definition function operator=
// Add "noexcept" at the end of the header.
Graph& Graph::operator=(const Graph& otherGraph) noexcept
{
    if(this == &otherGraph)
    {
        cerr << "Attempted self-assignment\n";
    }
    else
    {
        numOfCourses = otherGraph.numOfCourses;
        *graph = *otherGraph.graph;
    }
    return *this;
}

// Definition destructor
Graph::~Graph()
{
    delete graph;
    graph = nullptr;
}

// Definition function createGraph
void Graph::createGraph(const vector<vector<int>>& graphList)
{
    for(const vector<int>& subList : graphList)
    {
        set<int> temp = {};
        if(subList.size() > 1)
        {
            vector<int>::const_iterator it = ++subList.cbegin();
            vector<int>::const_iterator end = subList.cend();
            while(it != end)
            {
                temp.insert(*it);
                ++it;
            }
            graph->insert(make_pair(subList[0], temp));
        }
        else
        {
            graph->insert(make_pair(subList[0], temp));
        }
    }
    numOfCourses = static_cast<int>(graphList.size());
}

// Definition function isEmpty
bool Graph::isEmpty() const
{
    return numOfCourses < 1;
}

// Definition function printAllCourses
void Graph::printAllCourses() const
{
    for(const auto& course : *graph)
    {
        cout << COURSE_PREFIX << course.first << "\n";
    }
}

// Definition function printPrerequisites
void Graph::printPrerequisites(int course) const
{
    if((*graph)[course].empty())
    {
        cout << "No prerequisites.";
    }
    else
    {
        for(const auto& prereq : (*graph)[course])
        {
            cout << prereq << " ";
        }
    }
}

// Definition function clearGraph
void Graph::clearGraph()
{
    graph->clear();
    numOfCourses = 0;
}
