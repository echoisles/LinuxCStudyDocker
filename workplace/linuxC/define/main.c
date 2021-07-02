#include <stdio.h>
#define TEST_NUM  6
#define VAR2STR(var) #var
#define JOIN(x, y) x##y

int main(int argv, char* argc[])
{
 printf("%s: %d\n",VAR2STR(TEST_NUM),JOIN(TEST_, NUM));
 return 0;
}
//运行结果
//TEST_NUM: 6

//#及##在这一段代码里的作用表现为:
//#将紧接后面的元素(遇到空白视为一个元素),转化为字符串,而##则起到连结的作用.
//
//因此，__SOCKADDR_COMMON (sin_)实际展开为sa_family_t sin_family
