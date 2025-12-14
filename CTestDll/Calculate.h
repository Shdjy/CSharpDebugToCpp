#pragma  once

#ifdef CTESTDLL_EXPORTS
#define CTEST_API __declspec(dllexport)
#else
#define CTEST_API __declspec(dllimport)
#endif

class Calculate
{
public:
	int Add(int a, int b);
};

// C 风格导出函数
extern "C"
{
	CTEST_API Calculate* CreateCalculate();
	CTEST_API void DestroyCalculate(Calculate* calc);
	CTEST_API int Calculate_Add(Calculate* calc, int a, int b);
	CTEST_API void TriggerCrash();
}
