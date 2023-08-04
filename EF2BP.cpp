﻿// EF2BP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "tetrahedral.h"

#include <Eigen\Dense>
using namespace std;
using namespace Eigen;

using namespace std;


void EF2BP_sim(FEM &a, FEM &b);

int main()
{
    // test Eigen 
    //Matrix2d a;
    //a << 1, 2,
    //    3, 4;
    //MatrixXd b(2, 2);
    //b << 2, 3,
    //    1, 4;
    //cout << "a + b =\n" << a + b << endl;
    //cout << "a - b =\n" << a - b << endl;
    //cout << "Doing a += b;" << endl;
    //a += b;
    //cout << "Now a =\n" << a << endl;
    //cout << "a^T=  " << a.transpose() << endl;
    //cout << "a*b= " << a * b << endl;
    //Vector3d v(1, 2, 3);
    //Vector3d w(1, 0, 0);
    //cout << "-v + w - v =\n" << -v + w - v << endl;
    //cout << v << endl;
    //cout << v.transpose() << endl;
    //system("pause");




    FEM BodyA;// need to state the struct variable quantity before the main function
    FEM BodyB;
    EF2BP_sim(BodyA, BodyB);

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件