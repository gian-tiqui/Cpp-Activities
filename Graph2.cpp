#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void dfs_iteration(map<int, vector<int>> graph, int source);

void dfs(map<int, vector<int>> graph, int source);

void bfs(map<int, vector<int>> graph, int source);

int main() {
	
	map<int, vector<int>> graph;
	vector<int> one{2, 3}, two{4}, three{5}, four{6}, five, six;
	
	graph.insert(pair<int, vector<int>>(1, one));
	graph.insert(pair<int, vector<int>>(2, two));
	graph.insert(pair<int, vector<int>>(3, three));
	graph.insert(pair<int, vector<int>>(4, four));
	graph.insert(pair<int, vector<int>>(5, five));
	graph.insert(pair<int, vector<int>>(6, six));
	
	cout<<"Graph: \n";
	for (auto i : graph) {
		cout<<i.first<<": ";
		for (auto j : i.second) 
			cout<<j<<" ";
		cout<<endl;
	}

	cout<<"\nDFS(Iterative): \n";
	dfs_iteration(graph, 1);
	cout<<"\nDFS(Recursion): \n";
	dfs(graph, 1);
	cout<<"\nBFS: \n";
	bfs(graph, 1);
	
	return 0;
}

void dfs_iteration(map<int, vector<int>> graph, int source) {
	
	stack<int> s;
	s.push(source);
	
	while(!s.empty()) {
		
		int curr = s.top();
		s.pop();
		
		cout<<curr<<"\n";
		
		for (auto neighbor: graph.at(curr)) s.push(neighbor);		
	}
	
}

void dfs(map<int, vector<int>> graph, int source) {
	cout<<source<<"\n";
	for (auto neighbor : graph.at(source)) dfs(graph, neighbor);
}

void bfs(map<int, vector<int>> graph, int source) {

	queue<int> q;
	
	q.push(source);
	
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		
		cout<<curr<<"\n";
		for (auto neighbor : graph.at(curr)) q.push(neighbor);
	}

}