/*
    Taylor, Charlie

    February 10, 2021

    CS A200
    Lab 1: Graphs
*/

#include "Graph.h"

using namespace std;

// Definition function operator<<
ostream& operator<<(ostream& out, Graph& print)
{
    map<int, set<int>>::iterator it;
    for(it = print.graph->begin(); it != print.graph->end(); ++it)
    {
        out << COURSE_PREFIX << it->first << ": ";
        if(it->second.empty())
        {
            out << "No prerequisites.";
        }
        else
        {
            for(const auto& prereq : it->second)
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
Graph::Graph(const Graph& other) noexcept
{
    graph = new map<int, set<int>>;
    numOfCourses = other.numOfCourses;
    if(numOfCourses > 0)
    {
        map<int, set<int>>::const_iterator it = other.graph->cbegin();
        map<int, set<int>>::const_iterator end = other.graph->cend();
        for(; it != end; ++it)
        {
            graph->insert(*it);
        }
    }
}

// Definition function operator=
// Add "noexcept" at the end of the header.
Graph& Graph::operator=(const Graph& rhd) noexcept
{
    if(this == &rhd)
    {
        cerr << "Attempted self-assignment\n";
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
    return *this;
}

// Definition destructor
Graph::~Graph()
{
    clearGraph();
    delete graph;
    graph = nullptr;
}

// Definition function createGraph
void Graph::createGraph(vector<vector<int>> list)
{
    for(const vector<int>& subList : list)
    {
        if(subList.size() > 1)
        {
            set<int> temp;
            vector<int>::const_iterator it = subList.cbegin() + 1;
            for(; it != subList.cend(); ++it)
            {
                temp.insert(*it);
            }
            graph->insert(make_pair(subList[0], temp));
        }
        else
        {
            set<int> temp;
            graph->insert(make_pair(subList[0], temp));
        }
    }
    numOfCourses = static_cast<int>(list.size());
}

// Definition function isEmpty
bool Graph::isEmpty() const
{
    return numOfCourses < 1;
}

// Definition function printAllCourses
void Graph::printAllCourses() const
{
    map<int, set<int>>::const_iterator it = graph->cbegin();
    for(; it != graph->cend(); ++it)
    {
        cout << COURSE_PREFIX << it->first << "\n";
    }
}

// Definition function printPrerequisites
void Graph::printPrerequisites(int course) const
{
    set<int>::iterator it;
    if((*graph)[course].empty())
    {
        cout << "No prerequiisites.";
    }
    else
    {
        set<int>::const_iterator it = (*graph)[course].cbegin();
        set<int>::const_iterator end = (*graph)[course].cend();
        for(; it != end; ++it)
        {
            cout << *it << " ";
        }
    }
}

// Definition function clearGraph
void Graph::clearGraph()
{
    graph->clear();
    numOfCourses = 0;
}
