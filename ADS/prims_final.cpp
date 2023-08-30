#include <iostream>
#include <climits>
using namespace std;

class Graph {
    int n;
    int cost[10][10];
public:
    Graph() {
        cout << "Enter the number of vertices: " << endl;
        cin >> n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cost[i][j] = INT_MAX;
            }
        }
    }

    void create();
    void display();
    int prims();
};

void Graph::create() {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            cout << "Enter the cost for " << i << " " << j << ": ";
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];
        }
    }
}

void Graph::display() {
    cout << "Cost matrix is:" << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(cost[i][j] == INT_MAX) {
                cout << "INF\t";
            } else {
                cout << cost[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int Graph::prims() {
    int stv, i, j, k, r=0, min, nearest[10], t[9][2], mincost=0;
    cout << "Enter the starting vertex: " << endl;
    cin >> stv;
    nearest[stv] = -1;

    for(i=0; i<n; i++) {
        if(i!=stv) {
            nearest[i] = stv;
        }
    }

    r = 0;

    for(i=0; i<n-1; i++) {
        min = INT_MAX;
        for(k=0; k<n; k++) {
            if(nearest[k]!=-1 && cost[k][nearest[k]]<min) {
                j = k;
                min = cost[k][nearest[k]];
            }
        }

        t[r][0] = j;
        t[r][1] = nearest[j];
        r++;

        mincost += cost[j][nearest[j]];

        nearest[j] = -1;

        for(k=0; k<n; k++) {
            if(nearest[k]!=-1 && cost[k][nearest[k]]>cost[k][j]) {
                nearest[k] = j;
            }
        }
    }

    cout << "\n\nResultant Array: " << endl;
    cout << "Start \t|\tDest\t|" << endl;

    for(i=0; i<n-1; i++) {
        for(j=0; j<2; j++) {
            cout << t[i][j] << "\t\t";
        }
        cout << endl;
    }

    return mincost;
}

int main() {
    Graph g;
    g.create();
    g.display();
    int x = g.prims();
    cout << "\n\nThe minimum cost is: " << x << endl;

    return 0;
}
