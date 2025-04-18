//  Both matrix must be same dimention  and power of 2

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

            // Calculate the C11, C12, C21, C22
            vector<vector<int>>temp1 = add_mat(p5,p4);
            vector<vector<int>>temp2 = sub_mat(temp1, p2);

            vector<vector<int>>c11 = add_mat(temp2, p6);
            vector<vector<int>>c12 = add_mat(p1,p2);
            vector<vector<int>>c21 = add_mat(p3,p4);
            temp1 = add_mat(p1, p5);
            temp2 = sub_mat(temp1, p3);
            vector<vector<int>>c22 = sub_mat(temp2, p7);

            //merging the C11, C12, C21, C22 into one matrix
            vector<vector<int>>result(row, vector<int>(col,0));
            for(int i = 0 ; i < new_row ; i++){
                for(int j = 0 ; j < new_col ; j++){
                    result[i][j] = c11[i][j];
                    result[i][j + new_col] = c12[i][j];
                    result[i + new_row][j] = c21[i][j];
                    result[i+new_row][j + new_col] = c22[i][j];
                }
            }
            return result;
        }
};

int main(){
    int n;
    cout << "Enter the size(power of 2) of the matrix" << endl;
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

    Multiplicaton m;
    vector<vector<int>> result = m.strassanMultiply(A, B);
    cout << endl << endl;
    cout << "Resultandt matrix when matrix_1 is multiplied with matrix_2" << endl << endl;
    printMatrix(result);
    

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