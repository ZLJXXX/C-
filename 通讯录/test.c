#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
void test()
{
	Contactbook cb;
	ContactbookInit(&cb);
	ContactbookDestory(&cb);
	Contact con; //结构体指针，用来添加信息

}
//编写菜单
void meau()
{
	printf("*********************************\n");
	printf("            通讯录               \n");
	printf("1.增加联系人       2.删除联系人  \n");
	printf("3.查找联系人       4.修改联系人  \n");
	printf("5.保存到文件       6.从文件中加载\n");
	printf("0.退出                           \n");
	printf("*********************************\n");
}
int main()
{
	test();
	return 0;
}