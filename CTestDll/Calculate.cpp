#include "pch.h"
#include "Calculate.h"

// 类成员实现
int Calculate::Add(int a, int b)
{
	return a + b;
}

// C 风格导出函数实现
Calculate* CreateCalculate()
{
	return new Calculate();
}

void DestroyCalculate(Calculate* calc)
{
	delete calc;
}

int Calculate_Add(Calculate* calc, int a, int b)
{
	return calc->Add(a, b);
}

void TriggerCrash()
{
	 int* p = nullptr;
	 *p = 42; // 故意访问野指针
}

