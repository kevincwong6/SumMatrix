#include <iostream>
#include <string>
#include <vector>

using namespace std;
void printM(string msg, vector<vector<int>> m)
{
    int rowCnt = m.size();
    int colCnt = m[0].size();

    cout << msg << ":" << endl;
    for (int i = 0; i < rowCnt; i++)
    {
        for (int j = 0; j < colCnt; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> SumMatrix(vector<vector<int>> orig) {
    vector<vector<int>> res = orig; // use copy constructor to initialize res with all values from orig
    int rowCnt = orig.size();
    int colCnt = orig[0].size();

    for (int i = 1; i < colCnt; i++) // prepare for the first row
    {   // the first result row = previous result col + curr col from the original table
        res[0][i] = res[0][i - 1] + orig[0][i];
    }

    for (int i = 1; i < rowCnt; i++) // prepare for the first col
    {
        res[i][0] = res[i - 1][0] + orig[i][0];
    }

    for (int rowIdx = 1; rowIdx < rowCnt; rowIdx++) // process each row starting from row idx 1
    {
        for (int colIdx = 1; colIdx < colCnt; colIdx++) // process each row starting from col idx 1
        {
            // sum = curr row of previous col + prev row of curr col -
            //       the overlap between (curr row of previous col) & (prev row of curr col) +
            //       the curr col / row value from the orig matrix
            res[rowIdx][colIdx] = res[rowIdx][colIdx - 1] + res[rowIdx-1][colIdx] -
                                  res[rowIdx - 1][colIdx - 1] +
                                  orig[rowIdx][colIdx];
        }
    }
   return res;
}

void testCaseSumMatrix(vector<vector<int>> a)
{
    vector<vector<int>> b = SumMatrix(a);

    printM("input", a);
    printM("output", b);
}

void UnitTestSumMatrix()
{
    vector<vector<int>> a{ {1, 2, 3}, {3,4, 5} };
    testCaseSumMatrix(a);

    a = { {3, 3, 3},  {3, 3, 3},  {3, 3, 3} };
    testCaseSumMatrix(a);
}

int main()
{
    UnitTestSumMatrix();

    return 0;
}