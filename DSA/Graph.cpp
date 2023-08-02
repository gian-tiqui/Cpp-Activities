#include <iostream>
#include <vector>

using namespace std;

class Node{
	
	private:
		int v;
		vector<int> *l;
	
	public:
		Node(int num){
			v = num;
			l = new vector<int>[v];
		}
		
		void add_edge(int x, int y){
			l[x].push_back(y);
			l[y].push_back(x);
		}
		
		void print_adjacent(){
			for (int i = 0; i < v; i++){
				cout<<"Vertex "<<i<<"->";
				for (int n: l[i]){
					cout<<n<<" ";
				}
				cout<<endl;
			}
		}
};

int main(){
	
	Node g(4);
	
	g.add_edge(0, 1);
	g.add_edge(0, 2);
	g.add_edge(2, 3);
	g.add_edge(1, 2);
	
	g.print_adjacent();
	
	return 0;
}