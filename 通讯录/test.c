#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
void test()
{
	Contactbook cb;
	ContactbookInit(&cb);
	ContactbookDestory(&cb);
	Contact con; //�ṹ��ָ�룬���������Ϣ

}
//��д�˵�
void meau()
{
	printf("*********************************\n");
	printf("            ͨѶ¼               \n");
	printf("1.������ϵ��       2.ɾ����ϵ��  \n");
	printf("3.������ϵ��       4.�޸���ϵ��  \n");
	printf("5.���浽�ļ�       6.���ļ��м���\n");
	printf("0.�˳�                           \n");
	printf("*********************************\n");
}
int main()
{
	test();
	return 0;
}