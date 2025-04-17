//  Both matrix must be same dimention 


#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>input_mat(int );
void printMatrix(vector<vector<int>>);
vector<vector<int>> sub_mat(vector<vector<int>>, vector<vector<int>>);
vector<vector<int>> add_mat(vector<vector<int>>, vector<vector<int>>);
class Multiplicaton{
    
    public:
        vector<vector<int>> strassanMultiply(vector<vector<int>>A , vector<vector<int>>B){
            int row = A.size();
            int col = A[0].size();
            // base condition (Smallest Sub Problem)
            if(row == 1 && col == 1){
                vector<vector<int>>result(1, vector<int>(1,0));
                result[0][0] = A[0][0] * B[0][0];
                return result;
            }
            
            // Divide the matrix 
            int new_row = row / 2;
            int new_col = col / 2;

            // define  8 matrices (a,...,f) and is assigned the respective values
            vector<vector<int>>a(new_row,vector<int>(new_col,0));
            vector<vector<int>>b(new_row,vector<int>(new_col,0));
            vector<vector<int>>c(new_row,vector<int>(new_col,0));
            vector<vector<int>>d(new_row,vector<int>(new_col,0));
            vector<vector<int>>e(new_row,vector<int>(new_col,0));
            vector<vector<int>>f(new_row,vector<int>(new_col,0));
            vector<vector<int>>g(new_row,vector<int>(new_col,0));
            vector<vector<int>>h(new_row,vector<int>(new_col,0));

            for(int i = 0 ; i < new_row ; i++){
                for(int j = 0 ; j < new_col ; j++){
                    a[i][j] = A[i][j];
                    b[i][j] = A[i][j + new_col];
                    c[i][j] = A[i+new_row][j];
                    d[i][j] = A[i + new_row][j + new_col];
                    e[i][j] = B[i][j];
                    f[i][j] = B[i][j + new_col];
                    g[i][j] = B[i + new_row][j];
                    h[i][j] = B[i + new_row][j + new_col];
                }
            }

            // Now calculate the 10 addition and Substraction terms which is will be used in calculate the strassen terms
            vector<vector<int>>t1 = sub_mat(f,h);
            vector<vector<int>>t2 = add_mat(a,b);
            vector<vector<int>>t3 = add_mat(c,d);
            vector<vector<int>>t4 = sub_mat(g,e);
            vector<vector<int>>t5 = add_mat(a,d);
            vector<vector<int>>t6 = add_mat(e,h);
            vector<vector<int>>t7 = sub_mat(b,d);
            vector<vector<int>>t8 = add_mat(g,h);
            vector<vector<int>>t9 = sub_mat(a,c);
            vector<vector<int>>t10 = add_mat(e,f);

            // Now calculate the 7 Stranssen's terms recursively
            vector<vector<int>>p1 = strassanMultiply(a,t1);
            vector<vector<int>>p2 = strassanMultiply(t2,h);
            vector<vector<int>>p3 = strassanMultiply(t3,e);
            vector<vector<int>>p4 = strassanMultiply(d,t4);
            vector<vector<int>>p5 = strassanMultiply(t5,t6);
            vector<vector<int>>p6 = strassanMultiply(t7,t8);
            vector<vector<int>>p7 = strassanMultiply(t9,t10);
        }
};

int main(){
    int n;
    cout << "Enter the size of the matrix" << endl;
    cin >> n;
    cout << "Enter the values for matirx 1" << endl << endl;
    vector<vector<int>>A = input_mat(n);
    cout << endl << endl;
    cout << "Enter the values for matirx 2" << endl << endl;
    vector<vector<int>>B = input_mat(n);
    cout << endl << endl;
    cout << "Matrix 1 is " << endl << endl;
    printMatrix(A);
    cout << endl << endl;
    cout << "Matrix 2 is " << endl << endl;
    printMatrix(B);
    

}

void printMatrix(vector<vector<int>>A){
    for(int i = 0 ; i < A.size() ; i++){
        for(int j = 0 ; j < A[i].size() ; j++){
            cout << A[i][j] << "  ";
        }
        cout << endl;
    }
}

vector<vector<int>> sub_mat(vector<vector<int>>A, vector<vector<int>>B){
    vector<vector<int>>result(A.size(), vector<int>(A.size()));
    for(int i = 0 ; i<A.size() ; i++){
        for(int j = 0 ; j < A[i].size(); j++){
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

vector<vector<int>> add_mat(vector<vector<int>>A, vector<vector<int>>B){
    vector<vector<int>>result(A.size(), vector<int>(A.size()));
    for(int i = 0 ; i<A.size() ; i++){
        for(int j = 0 ; j < A[i].size(); j++){
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

vector<vector<int>>input_mat(int n){
    vector<vector<int>>m(n,vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> m[i][j];
        }
    }
    return m;
}