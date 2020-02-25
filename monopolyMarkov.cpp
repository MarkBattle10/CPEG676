template<typename T>
Class Matrix{
    int row;
    int col;
    //T **matrix;
  public:
    Matrix(int rows, int cols){
      T matrix[rows][cols];
      
    }
    /*{
      T matrix[rows][cols];
      for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
          
        }
      }
    }*/
    ~Matrix();
    T matrixMult(T row, T col){
      return row*col;
    };
}

int main(){
  Matrix *mat = new Matrix(5, 5);
  
  int iMatrix[5][5];
  //int iCol[5];
  double dMatrix[5][5];
  //double dCol[5];
  for(int i=0; i<5;i++){
    for(int j=0;j<5;j++){
      iMatrix[i][j] = i+j;
      dMatrix[i][j] = 0.0++;
      cout << mat->matrixMult<int>(
    }  
  }
  delete mat;
  
  return 0;
}
  
  
  
  
}
