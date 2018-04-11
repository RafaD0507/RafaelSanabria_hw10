#include <iostream>
#include <cstdlib>

double **matrix_product(double **A, double **B, int filas_A, int col_A, int filas_B, int col_B);
double **get_Matrix(int M, int N);

int main(){
  //Aqui se introduce la info de las matrices
  int f_A;
  int c_A;
  int f_B;
  int c_B;
  std::cout<<"Ingrese el numero de filas de la matriz A: "<<std::endl;
  std::cin>>f_A;
  std::cout<<"Ingrese el numero de columnas de la matriz A: "<<std::endl;
  std::cin>>c_A;
  std::cout<<"Ingrese el numero de filas de la matriz B: "<<std::endl;
  std::cin>>f_B;
  std::cout<<"Ingrese el numero de columnas de la matriz B: "<<std::endl;
  std::cin>>c_B;
  if(c_A != f_B){
    //Se verifica que se pueda multiplicar
    std::cout<<"El numero de columnas en A no coindice con el numero de filas en B"<<std::endl;
    return 0;
  }
  else{
    //Se llenan las matrices y se efectua la multiplicacion
    std::cout<<"Introduzca la matriz A"<<std::endl;
    double **A = get_Matrix(f_A, c_A);
    std::cout<<"Introduzca la matriz B"<<std::endl;
    double **B = get_Matrix(f_B, c_B);

    double **multi = matrix_product(A, B, f_A, c_A, f_B, c_B);
    std::cout<<"El producto de estas dos matrices es: "<<std::endl;
    //Se imprime la matriz
    for(int i=0; i<f_A; i++){
      for(int j=0; j<c_B; j++){
	std::cout<<multi[i][j]<<" ";
      }
      std::cout<<std::endl;
    }
    
  }
  return 0;
      
}
double **matrix_product(double **A, double **B, int filas_A, int col_A, int filas_B, int col_B){
  //Se inicializa la matriz
  double **producto = new double*[filas_A];
  for(int i=0; i<filas_A; i++){
    producto[i] = new double[col_B];
  }
  //Se llena la matriz con el producto A*B
  for(int i=0; i<filas_A; i++){
    for(int j=0; j<col_B; j++ ){
      double resultado;
      resultado = 0;
      for(int k=0; k<col_A; k++){
	resultado += A[i][k]*B[k][j];
      }
      producto[i][j]=resultado;
    }
  }
  return producto;
}

double **get_Matrix(int M, int N){
  //Se imprime info sobre la matriz
  std::cout<<"La dimension M es: "<< M << std::endl;
  std::cout<<"La dimension N es: "<< N << std::endl;
  double **la_matriz = new double*[M];
  //Se inicializa la matriz
  for(int i=0; i<M; i++){
    la_matriz[i] = new double[N];
  }
  //Se llena la matriz
  for(int i=0; i<M; i++){
    for(int j=0; j<N; j++){
      double var;
      std::cout<<"Ingrese el elemento "<<i<<", "<<j<<std::endl;
      std::cin>>var;
      la_matriz[i][j] = var;
    }
  }
  //Se imprime la matriz
  std::cout<<"Su matriz es:"<<std::endl;
  for(int i=0; i<M; i++){
    for(int j=0; j<N; j++){
      std::cout<<la_matriz[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
  return la_matriz;
}

