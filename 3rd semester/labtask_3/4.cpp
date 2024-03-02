#include <iostream>
using namespace std;

const int grid = 9;
void displayGrid(int sudoku[grid][grid]){
   
    for(int i = 0; i<grid; i++){
        for(int j = 0; j<grid; j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int sudoku[grid][grid]= {{3,0,0,4,5,0,0,1,5},{3,0,0,4,5,0,0,1,5},{3,0,0,4,5,0,0,1,5},{3,0,0,4,5,0,0,1,5},{3,0,0,4,5,0,0,1,5},{3,0,0,4,5,0,0,1,5},{3,0,0,4,5,0,0,1,5},{3,0,0,4,5,0,0,1,5}};
    displayGrid(sudoku);
}