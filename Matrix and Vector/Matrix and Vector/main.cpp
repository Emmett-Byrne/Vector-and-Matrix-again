#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 


#include "MyVector3D.h"
#include "MyMatrix3.h"
#include <SFML\Graphics.hpp>
#include <string.h>

void testConstructors();

const double PI = 3.14159265359;

int main()
{
	testConstructors();
	std::system("pause");
	return EXIT_SUCCESS;
}

void testConstructors()
{
	MyMatrix3 matrixA{};
	MyMatrix3 matrixB{};
	

	std::cout << "-------- default constructor--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ 0, 0, 0 ] [ 0, 0, 0 ] [ 0, 0, 0 ] }" << std::endl;
	matrixA = MyMatrix3{ 1.1,2.2,3.3,-4.4,5.5,6.6,7.7,8.8,9.9 };
	std::cout << "-------- 9 doubles constructor--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ 1.1, 2.2, 3.3 ] [ -4.4, 5.5, 6.6 ] [ 7.7, 8.8, 9.9 ] }" << std::endl;

	MyVector3D vector1(2.1, 4.6, 7.1);
	MyVector3D vector2(8.2, 9.1, 5.4);
	MyVector3D vector3(3.0, -4.7, 1.2);
	matrixA = MyMatrix3{ vector1, vector2, vector3 };
	std::cout << "-------- 3 Vectors Constructor--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ 2.1, 4.6, 7.1 ] [ 8.2, 9.1, 5.4 ] [ 3.0, -4.7, 1.2 ] }" << std::endl;

	matrixB = MyMatrix3{ 1,-1,1.1,2.6,-2.5,0,3,6,1 };
	matrixA = matrixA + matrixB;
	std::cout << "-------- Matrix Addition--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ 3.1, 3.6, 8.2 ] [ 10.8, 6.6, 5.4 ] [ 6.0, 1.3, 2.2 ] }" << std::endl;
	std::cout << "========================================" << std::endl;

	matrixA = MyMatrix3{ vector1, vector2, vector3 };
	matrixA = matrixA - matrixB;
	std::cout << "-------- Matrix Subtraction--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ 1.1, 5.6, 6 ] [ 5.6, 11.6, 5.4 ] [ 0, -10.7, 0.2 ] }" << std::endl;
	std::cout << "========================================" << std::endl;

	matrixA = MyMatrix3{ vector1, vector2, vector3 };
	matrixA = matrixA * matrixB;
	// calculator used: https://matrix.reshish.com/multCalculation.php
	std::cout << "-------- Matrix multiplication--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ 35.36, 28.999999999999993, 9.41 ] [ 48.06, 1.4500000000000064, 14.42 ] [ -5.620000000000001, 15.95, 4.5 ] }" << std::endl;
	std::cout << "========================================" << std::endl;

	matrixA = MyMatrix3{ vector1, vector2, vector3 };
	MyVector3D result = matrixA * vector1;
	// calculator used: https://www.symbolab.com/solver/matrix-vector-calculator/%5Cbegin%7Bpmatrix%7D2.1%264.6%267.1%5C%5C%208.2%269.1%265.4%5C%5C%203.0%26-4.7%261.2%5Cend%7Bpmatrix%7D%5Cbegin%7Bpmatrix%7D2.1%5C%5C%204.6%5C%5C%207.1%5Cend%7Bpmatrix%7D
	std::cout << "-------- Vector multiplication--------------" << std::endl;
	std::cout << result.toString() << std::endl;
	std::cout << "{ [ 75.98, 97.42, -6.8 ] }" << std::endl;
	std::cout << "========================================" << std::endl;

	matrixA = matrixA * 2.1;
	std::cout << "-------- scaler multiplication--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ 4.41, 9.66, 14.91 ] [ 17.22, 19.11, 11.34 ] [ 6.3, -9.87, 2.52 ] }" << std::endl;
	std::cout << "========================================" << std::endl;

	matrixA = MyMatrix3{ vector1, vector2, vector3 };
	matrixA = matrixA.transpose();
	std::cout << "-------- Transpose--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ 2.1, 8.2, 3 ] [ 4.6, 9.1, -4.7 ] [ 7.1, 5.4, 1.2 ] }" << std::endl;
	std::cout << "========================================" << std::endl;

	matrixA = MyMatrix3{ vector1, vector2, vector3 };
	double resultDet = matrixA.determinant();
	//calculator used: https://matrix.reshish.com/detCalculation.php
	std::cout << "-------- Determinate--------------" << std::endl;
	std::cout << resultDet << std::endl;
	std::cout << "{ -361.9779999999999 }" << std::endl;
	std::cout << "========================================" << std::endl;

	matrixA = matrixA.Inverse();
	//calculator used: https://matrix.reshish.com/inverCalculation.php
	std::cout << "-------- Inverse--------------" << std::endl; //--------------------------Unfinished----------------------------
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ -0.10028233760062766, 0.10743746857543834, 0.10986855554757469 ] [ -0.017570128571349763, 0.05188160606445698, -0.12951063324290427 ] [ 0.1818895070971165, -0.065390714352806, 0.05141196426302151 ] }" << std::endl;
	std::cout << "========================================" << std::endl;
	

	matrixA = MyMatrix3{ vector1, vector2, vector3 };
	MyVector3D rowVect = matrixA.row(1);
	std::cout << "-------- Row--------------" << std::endl;
	std::cout << rowVect.toString() << std::endl;
	std::cout << "[ 2.1, 4.6, 7.1 ]" << std::endl;
	std::cout << "========================================" << std::endl;

	MyVector3D colVect = matrixA.column(1);
	std::cout << "-------- Column--------------" << std::endl;
	std::cout << colVect.toString() << std::endl;
	std::cout << "[ 2.1, 4.6, 7.1 ]" << std::endl;
	std::cout << "========================================" << std::endl;


	std::cout << "-------- equality --------------" << std::endl;
	if (matrixA == matrixA)
	{
		std::cout << "A == A is true" << std::endl;
	}
	if (matrixA == matrixB)
	{
		std::cout << "A == B is false" << std::endl;
	}
	std::cout << "========================================" << std::endl;


	std::cout << "-------- equality --------------" << std::endl;
	if (matrixA != matrixA)
	{
		std::cout << "A != A is false" << std::endl;
	}
	if (matrixA != matrixB)
	{
		std::cout << "A != B is true" << std::endl;
	}
	std::cout << "========================================" << std::endl;

	matrixA = MyMatrix3::rotationZ(70 * PI / 180);
	std::cout << "-------- Rotation Z --------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ 0.34202, -0.939693, 0 ] [ 0.939693, 0.34202, 0 ] [ 0, 0, 1 ] }" << std::endl;
	std::cout << "========================================" << std::endl;

	matrixA = MyMatrix3::rotationY(20 * PI / 180);
	std::cout << "-------- Rotation Y --------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ 0.939693, 0, 0.34202 ] [ 0, 1, 0 ] [ -0.34202, 0, 0.939693 ] }" << std::endl;
	std::cout << "========================================" << std::endl;

	matrixA = MyMatrix3::rotationX(130 * PI / 180);
	std::cout << "-------- Rotation X--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ 1, 0, 0 ] [ 0, -0.642788, -0.766044 ] [ 0, 0.766044, -0.642788 ] }" << std::endl;
	std::cout << "========================================" << std::endl;

	matrixA = MyMatrix3::translation(3, 5);
	std::cout << "-------- Translation--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "========================================" << std::endl;


	matrixA = MyMatrix3::scale(5, 1);
	std::cout << "-------- Scale--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "========================================" << std::endl;
	}
