#include <iostream>

using namespace std;

//并查集的实现
//http://www.mathblog.dk/disjoint-set-data-structure/

// The Disjoint-set data structure
class DisjointSet {
 
public:
	int count;     // The number of elements in the collection.
 
private:
	int* parent;   // The parent of each element in the collection.
	int* rank;    //集合树高度，用于路径压缩优化The rank of each element in the collection.
 
public:
	DisjointSet(int size) 
	{
        count = size;
        parent = new int[count];
        rank = new int[count];
        // Initially, all elements are in their own set.
        for (int i = 0; i < count; i++) 
		{
            parent[i] = i;
			rank[i] = 0;
        }
    }
 
    ~DisjointSet()
	{
		delete[] parent;
		delete[] rank;
	}

	int Find(int i);
	void Union(int i, int j);

	//采用路径压缩优化的函数
	int FindX(int i);
	void UnionX(int i, int j);
};

// Finds the representative of the set that i is an element of
int DisjointSet::Find(int i) 
{ 
    // If i is the parent of itself
    if (parent[i] == i) 
	{
        // Then i is the representative of his set
        return i;
    }
    else 
	{ // Else if i is not the parent of itself
 
        // Then i is not the representative of his set,
        // so we recursively call Find on its parent
        return Find(parent[i]);
    }
}

// Unites the set that includes i and the set that includes j
void DisjointSet::Union(int i, int j) 
{
    // Find the representatives (or the root nodes) for the set that includes i
    int irep = Find(i),
        // And do the same for the set that includes j
        jrep = Find(j);
 
    // Make the parent of i's representative be j's representative
    // (effectively moving all of i's set into j's set)
    parent[irep] = jrep;
}


//path compression

// Finds the representative of the set that i is an element of
int DisjointSet::FindX(int i) 
{
    // If i is the parent of itself
    if (parent[i] == i) 
	{
        // Then i is the representative of his set
        return i;
    }
    else 
	{ // Else if i is not the parent of itself
 
        // Then i is not the representative of his set,
        // so we recursively call Find on it's parent, and save it in our result variable
        int result = Find(parent[i]);
 
        // We then cache the result by moving i's node directly under the representative of his set
        parent[i] = result;
 
        // And then we return the result
        return result;
    }
}

// Unites the set that includes i and the set that includes j
void DisjointSet::UnionX(int i, int j) 
{ 
    // Find the representatives (or the root nodes) for the set that includes i
    int irep = Find(i);
    // And do the same for the set that includes j
    int jrep = Find(j);
    // Get the rank of i's tree
    int irank = rank[irep];
    // Get the rank of j's tree
    int jrank = rank[jrep];
 
    // Elements are in the same set, no need to unite anything.
    if (irep == jrep)
        return;
 
    // If i's rank is less than j's rank
    if (irank < jrank) 
	{
        // Then move i under j
        parent[irep] = jrep;
 
    } // Else if j's rank is less than i's rank
    else if (jrank < irank) 
	{
        // Then move j under i
        parent[jrep] = irep;
 
    } // Else if their ranks are the same
    else 
	{
        // Then move i under j (doesn't matter which one goes where)
        parent[irep] = jrep;
        // And increment the the result tree's rank by 1
        rank[jrep]++;
    }
}


