#include<BookStystemManager.h>
char iuputWords[30];//掩码数组
int main() {//图书管理系统主函数
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	loadbook(head);	
	while (1) {
		show();
		char c = _getch();
		switch (c)
		{
	     case'1':
			//校内通道
			income(head);
			break;
			
	     case'2':
			//游客登录
			 show2(head);
			 break;
	 
	    case'0':
		system("cls");
		printf("拜拜");
		exit(0);
		break;
		default:

			printf("输入错误请重新输入\n");

			system("pause");
			system("cls");
		}
	}
	return 0;
}

//用户层
int income(Node* head) {//用户登录程序

	system("cls");

	while (1) {
		come();
		char t = getch();
		int ge;
		char admin[10], key[10];

		switch (t)
		{
			//用户登录
		case '1':
			ge = finduser();
			if (ge == 1)
				welcome2(head);
				return 1;		
		
			break;
			//用户注册
		case '2':
			logname();			
			
			system("cls");
			break;
			//管理员登录

		case '3':
			logadmian(head);
			break;

		case '0':
		{
		system("cls");
		printf("拜拜");
		exit(0);
		break;			
		}
		default:

			printf("输入错误请重新输入\n");

			system("pause");
			system("cls");

			
		}


	}
}
void logadmian(Node* head) {//管理员登录系统

	char admin[10], key[10];
	while (1) {
		printf("请输入用户名和密码:\n");
		printf("用户名:");
		gets_s(admin);
		input();
		strcpy(key, iuputWords);
		if (strcmp(admin, "666") == 0 && strcmp(key, "666") == 0) {//将管理员账密都设置为666
			system("cls");
			color(2);
			printf("密码正确，你好管理员\n");
			color(7);
			system("pause");
			system("cls");
			welcome1(head);

			break;
		}
		else {
			system("cls");
			color(4);
			printf("密码或用户名错误，请重新输入!!!\n");
			color(7);
			system("pause");
			system("cls");
			break;
		}
	}

}
void logname() {//用户注册系统
	printf("欢迎注册账号\n");
	user a, b;
	FILE* fp,*fp1;
	fp1 = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "a+");
	if (fp1 == NULL) {//因为要用r+来遍历文件搜索账号，所以要保证文件非空
		//如果文件为空直接注册省去查找账号
		fp1 = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "w");
		printf("请输入账号:\n");
		scanf("%s", a.name);
		input();
		strcpy(a.log, iuputWords);
		fp = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "a");

		fwrite(&a, sizeof(user), 1, fp);

		printf("账号注册成功！\n");
		fclose(fp);
		system("pause");

	}
	else
	fp = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "r+");
	printf("请输入账号:\n");
	scanf("%s", a.name);
	fread(&b, sizeof(user), 1, fp);
	//先输入账号，遍历文件查询是否有此账号
	while (1)
	{
		if (strcmp(a.name, b.name)) {//一直取文件中的user比对知道取完
			if (!feof(fp)) {
				fread(&b, sizeof(user), 1, fp);
			}
			else {
				break;
			}
		}
		else {
			system("cls");
			color(4);
			printf("此用户名已存在！请重新注册！\n");
			color(7);
			fclose(fp);
			system("pause");
			return;
		}
	}
	fclose(fp);

	//scanf("%s", a.log);
	input();
	strcpy(a.log, iuputWords);//掩码
	fp = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "a");

	fwrite(&a, sizeof(user), 1, fp);

	printf("账号注册成功！\n");
	fclose(fp);
	system("pause");
}
int  finduser() {//用户登录系统

	user a, b;
	FILE* fp;

	printf("请输入账号:\n");
	scanf("%s", a.name);
	input();//掩码函数

	strcpy(a.log, iuputWords);

	fp = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "r");

	fread(&b, sizeof(user), 1, fp);

	while (1) {
		//先获得账号，再遍历文件找到帐号对应的密码

		if ((strcmp(a.name, b.name) == 0)) {
			break;
		}
		else {
			if (!feof(fp)) {
				fread(&b, sizeof(user), 1, fp);
			}
			else {
				system("cls");
				color(4);
				printf("账号或密码错误\n");
				color(7);
				fclose(fp);
				system("pause");
				system("cls");

				return 0;
			}
		}
	}
	fclose(fp);
	//如果找到账号将储存在文件中的密码与输入的密码比对
	if (strcmp((a.log), (b.log)) == 0) {
		system("cls");
		color(2);
		printf("登录成功，欢迎使用\n");
		color(7);
		system("pause");
		system("cls");
		return 1;
	}
	else {
		system("cls");
		color(4);
		printf("账号或密码错误\n");
		color(7);
		system("pause");
		system("cls");
		return 0;
	}

}

void color(int c)//变色函数
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);

}
void input() {//掩码功能实现
	printf("请输入密码:\n");

	for (int i = 0; i < 14; ) {
		iuputWords[i] = _getch();
		if (iuputWords[i] == '\r') {
			iuputWords[i] = '\0';
			break;
		}
		else if (iuputWords[i] == '\b' && i > 0) {
			i--;
			printf("\b \b");
		}
		else
		{
			i++;
			printf("*");
		}
	}

}
//界面展现
void show2(Node* head) {
	system("cls");
	while (1) {


		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*西安邮电大学图书管理系统*\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      欢迎访问          *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      1.打印图书信息    *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      2.统计图书数量    *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      3.按照首字母排序  *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      0.退出系统        *\n");
		printf("\t\t\t\t\t**************************\n");
		char c = _getch();
		switch (c)
		{
		case'1':
			printfbook(head);
			break;
		case'2':
			coutbook(head);
			break;
		case'3':
			sort3(head);
			break;
		case'0':
			//退出
			system("cls");
			printf("拜拜\n");
			system("pause");
			system("cls");
			return ;
			

		default:
			printf("请重新输入\n");
		}
	}
}
void welcome1(Node* head) {
	while (1) {
		printf("\t\t\t\t\t*********************************\n");
		printf("\t\t\t\t\t* 西安邮电图书管理系统(管理员页)*\n");
		printf("\t\t\t\t\t*********************************\n");
		printf("\t\t\t\t\t*        选择功能列表           *\n");
		printf("\t\t\t\t\t*********************************\n");
		printf("\t\t\t\t\t*        1.录入图书信息         *\n");
		printf("\t\t\t\t\t*        2.打印图书信息         *\n");
		printf("\t\t\t\t\t*        3.统计图书数量         *\n");
		printf("\t\t\t\t\t*        4.查找图书信息         *\n");
		printf("\t\t\t\t\t*        5.修改图书信息         *\n");
		printf("\t\t\t\t\t*        6.删除图书信息         *\n");
		printf("\t\t\t\t\t*        7.借阅次数排序         *\n");
		printf("\t\t\t\t\t*        8.图书筛选系统         *\n");
		printf("\t\t\t\t\t*        9.学生账号管理         *\n");
		printf("\t\t\t\t\t*        a.按照首字母排序       *\n");
		printf("\t\t\t\t\t*        0.退出系统             *\n");
		printf("\t\t\t\t\t*********************************\n");
		/*Node* head = (Node*)malloc(sizeof(Node));
		head->next = NULL;*/
		char c = _getch();
		switch (c)
		{
		case'1':
			inputbook(head);
			break;
		case'2':
			printfbook(head);
			break;
		case'3':
			coutbook(head);
			break;
		case'4':
			find(head);
			break;
		case'5':
			changebook(head);
			break;
		case'6':
			delshow(head);
			break;
		case'7':
			sort(head);
			break;
		case'8':
			shaixuan(head);
			break;
		case'9':
			adminpeo();
			break;
		case'a':
			sort3(head);
			break;
		case'0':
			//退出
			system("cls");
			printf("拜拜\n");
			return;

		default:
			color(4);
			printf("请重新输入\n");
			color(7);
			system("pause");
			system("cls");
		}
	}
}
void welcome2(Node* head) {
	while (1) {
		printf("\t\t\t\t\t*********************************\n");
		printf("\t\t\t\t\t*      西安邮电图书管理系统     *\n");
		printf("\t\t\t\t\t*********************************\n");
		printf("\t\t\t\t\t*        选择功能列表           *\n");
		printf("\t\t\t\t\t*********************************\n");		
		printf("\t\t\t\t\t*        1.打印图书信息         *\n");
		printf("\t\t\t\t\t*        2.统计图书数量         *\n");
		printf("\t\t\t\t\t*        3.查找图书信息         *\n");
		printf("\t\t\t\t\t*        4.借阅排行榜           *\n");
		printf("\t\t\t\t\t*        5.图书筛选系统         *\n");
		printf("\t\t\t\t\t*        6.按照首字母排序       *\n");
		printf("\t\t\t\t\t*        0.退出系统             *\n");
		printf("\t\t\t\t\t*********************************\n");
		/*Node* head = (Node*)malloc(sizeof(Node));
		head->next = NULL;*/
		char b = _getch();
		switch (b)
		{
		case'1':
			printfbook(head);
			break;
		case'2':
			coutbook(head);
			break;
		case'3':
			find(head);
			break;
		case'4':
			sort(head);
			break;
		case'5':
			shaixuan(head);
			break;
		case'6':
			sort3(head);
			break;
		case'0':
			//退出
			system("cls");
			printf("拜拜\n");
			return;

		default:
			color(4);
			printf("请重新输入\n");
			color(7);
			system("pause");
			system("cls");
		}
	}
}
void come()//用户登录界面
{
	printf("\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t*      用户登录系统      *\n");
	printf("\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t*      1.用户登录        *\n");
	printf("\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t*      2.用户注册        *\n");
	printf("\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t*      3.管理员登录      *\n");
	printf("\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t*      0.退出系统        *\n");
	printf("\t\t\t\t\t**************************\n");
}
void show() {//游客师生选择通道
	printf("\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t*西安邮电大学图书管理系统*\n");
	printf("\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t*      1.师生通道        *\n");
	printf("\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t*      2.游客模式        *\n");
	printf("\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t*      0.退出系统        *\n");
	printf("\t\t\t\t\t**************************\n");
}
//图书管理系统功能区
void inputbook(Node* head) {
	//尾插法来创建
	Node* fresh = (Node*)malloc(sizeof(Node));
	fresh->next = NULL;
	printf("请输入图书的序号，名称，借阅次数：");
	scanf("%d%s%d",&fresh->book.number,fresh->book.name,&fresh->book.times);
	Node* move = head;
	while (move->next != NULL) {
		move = move->next;
	}
	move->next = fresh;
	savebook(head);
	color(2);
	printf("添加完成\n");
	color(7);
	system("pause");
	system("cls");	
}
void printfbook(Node* head) {
	//创建游标来遍历链表
	Node* move = head->next;
	printf("编号    名称                      借阅次数    \n");
	while (move != NULL) {
	
	printf("编号：%d 名称：%-20s借阅次数: %d\n", move->book.number, move->book.name,move->book.times);
		move = move->next;
	}
	system("pause");
	system("cls");
}


void coutbook(Node* head) {
	//创建游标遍历链表来计数
	int cout = 0;
	Node* move = head->next;
	while (move != NULL) {
		cout++;
		move = move->next;

	}
	color(2);
	printf("图书总数为：%d\n", cout);
	color(7);
	system("pause");
	system("cls");

}

void find(Node* head) {
	//图书查找系统
	system("cls");
	while (1) {
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      图书查找系统      *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*    请选择您的查找方式  *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      1.按序号查找      *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      2.按名称查找      *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      3.组合查找      *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      0.退出系统        *\n");
		printf("\t\t\t\t\t**************************\n");
		char c = _getch();
		switch (c)
		{
		case'1'://按序号查找
			numfind(head);
			break;
		case'2'://按书名查找
			namefind(head);
			break;
		case'3':
			zuhe(head);
		case'0':
			//退出
			system("cls");			
			return;

		default:
			color(4);
			printf("请重新输入\n");
			color(7);
			break;
		}
	}
}

void numfind(Node* head){//按序号查找
	printf("请输入要查找的图书的序号：");
	int booknum;
	scanf_s("%d", &booknum);
	Node* move = head->next;
	//创建游标遍历链表，将读取到的序号逐一比对
	while (move != NULL) {
		if (booknum == move->book.number) {
			color(2);
			printf("找到该图书\n");
			color(7);
			printf("编号：%d 名称： %s 借阅次数：%d\n", move->book.number, move->book.name, move->book.times);
			system("pause");
			system("cls");
			return;
		}
		move = move->next;
	}
	color(4);
	printf("未找到图书信息\n");
	color(7);
	system("pause");
	system("cls");
}

void namefind(Node* head) {//按书名查找
	printf("请输入要查找的图书的名称：");
	char booknum[15];
	gets_s(booknum);
	Node* move = head->next;
	while (move != NULL) {
		if (!(strcmp(booknum, move->book.name))) {
			
			color(2);
			printf("找到该图书\n");
			color(7);
			printf("编号：%d 名称： %s 借阅次数：%d\n", move->book.number, move->book.name, move->book.times);
			system("pause");
			system("cls");
			return;
		}
		move = move->next;
	}
	color(4);
	printf("未找到图书信息\n");
	color(7);
	system("pause");
	system("cls");
}

void  savebook(Node* head) {//保存图书函数
	FILE* file = fopen("./book.info", "w");
	//打开文件如果不存在就创建
	if (file == NULL) {
		color(4);		
		printf("打开文件失败\n");		
		color(7);
		return;
	}
	Node* move = head->next;
	while (move != NULL) {
		if (fwrite(&move->book, sizeof(Book), 1, file) != 1) {
			color(4);
			printf("保存%s出现错误\n", move->book.name);
			color(7);
		}
		move = move->next;

	}
	fclose(file);
}
void zuhe(Node* head) {
	printf("请输入要查找的图书的名称：");
	char booknumE[15];
	gets_s(booknumE);
	printf("请输入要查找的图书的序号：");
	int booknum;
	scanf_s("%d", &booknum);
	Node* move = head->next;
	while (move != NULL) {
		if ((booknum == move->book.number)&&!(strcmp(booknumE, move->book.name))) {

			color(2);
			printf("找到该图书\n");
			color(7);
			printf("编号：%d 名称： %s 借阅次数：%d\n", move->book.number, move->book.name, move->book.times);
			system("pause");
			system("cls");
			return;
		}
		move = move->next;
	}
	color(4);
	printf("未找到图书信息\n");
	color(7);
	system("pause");
	system("cls");
}

void loadbook(Node* head) {//加载图书函数
	FILE* file = fopen("./book.info", "r");
	if (!file) {
		color(2);			
		printf("没有图书文件，跳过读取\n");
		color(7);
		return;
	}
	Node* fresh =(Node*) malloc(sizeof(Node));
	fresh->next = NULL;
	Node* move = head;
	while (fread(&fresh->book, sizeof(Book), 1, file) == 1) {
		move->next = fresh;
		move = fresh;
		fresh =(Node*) malloc(sizeof(Book));
		fresh->next = NULL;
	}
	free(fresh);
	fclose(file);
	printf("\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t*");
	color(2);		
	printf("       读取成功         ");
	color(7);
	printf("*\n");
	printf("\t\t\t\t\t**************************\n");
	printf("\n");
}

void changebook(Node* head) {//修改函数
	//先遍历找到要修改的结点在修改
	printf("请输入要修改的图书编号\n");
	int booknum;
	scanf("%d", &booknum);
	Node* move = head->next;
	while (move != NULL) {
		if (move->book.number == booknum) {
			printf("您将要修改的图书是编号为%2d的%-8s      借阅次数为%4d\n", move->book.number, move->book.name,move->book.times);		
			printf("请输入图书名称，借阅次数\n");
			scanf("%s%s%d", move->book.name,&move->book.times);
			savebook(head);
			printf("修改成功\n");
			printfbook(head);
			system("pause");
			system("cls");
			return;

		}		
		move = move->next;
	}
	printf("没有找到图书信息\n");
		system("pause");
		system("cls");
}

void delshow(Node* head) {//删除系统
	system("cls");
	while (1) {
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      图书删除系统      *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      1.按序号删除        *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      2.按名称删除        *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      0.退出系统        *\n");
		printf("\t\t\t\t\t**************************\n");
		char c = _getch();
		switch (c)
		{
		case'1':
			numdel(head);
			break;
		case'2':
			namedel(head);
			break;
		case'0':
			//退出
			system("cls");
			printf("拜拜\n");
			return;

		default:
			color(4);
			printf("请重新输入\n");
			color(7);
			system("pause");
			system("cls");
		}
	}
}

void numdel(Node* head) {//按编号删除
	printf("请输入要删除的图书编号\n");
	int booknum = 0;
	scanf("%d", &booknum);
	Node* move = head;
	while (move->next != NULL) {
		if (move->next->book.number == booknum) {
			Node* tmp = move->next;
			move->next = move->next->next;
			system("cls");
			color(2);
			printf("已经找到该图书确认删除吗？\n");
			color(7);
			printf("\t\t\t\t\t**************************\n");
			printf("\t\t\t\t\t*     1.确认删除         *\n");
			printf("\t\t\t\t\t*     2.取消删除         *\n");			
			printf("\t\t\t\t\t**************************\n");
			while (1) {
				char c = _getch();
				switch (c)
				{					
				case'1':
					free(tmp);
					tmp = NULL;
					savebook(head);
					printf("删除成功\n");
					printfbook(head);
					system("pause");
					system("cls");
					return;					
				case'2':
					color(2);
					printf("取消删除成功\n");
					color(7);
					system("pause");
					system("cls");
					return;
				default:
					color(4);
					printf("请重新输入\n");
					color(7);
					system("pause");
					system("cls");
					break;
				}
			}					
		}
		move = move->next;
	}
	printf("没有找到图书信息\n");
	system("pause");
	system("cls");
}

void namedel(Node* head) {//按名称删除

	printf("请输入要删除的图书名称\n");
	char booknum[15];
	gets_s(booknum);
	Node* move = head;
	while (move->next != NULL) {
		if (!(strcmp(move->next->book.name, booknum))) {
			Node* tmp = move->next;
			move->next = move->next->next;
			system("cls");
			color(2);
			printf("已经找到该图书确认删除吗？\n");
			color(7);
			printf("\t\t\t\t\t**************************\n");
			printf("\t\t\t\t\t*     1.确认删除         *\n");
			printf("\t\t\t\t\t*     2.取消删除         *\n");
			printf("\t\t\t\t\t**************************\n");
			while (1) {
				char c = _getch();
				switch (c)
				{
				case'1':
					free(tmp);
					tmp = NULL;
					savebook(head);
					printf("删除成功\n");
					printfbook(head);
					system("pause");
					system("cls");
					return;
				case'2':
					color(2);
					printf("取消删除成功\n");
					color(7);
					system("pause");
					system("cls");
					return;
				default:
					color(4);
					printf("请重新输入\n");
					color(7);
					system("pause");
					system("cls");
					break;
				}
			}
		}
		move = move->next;
	}
	color(4);
	printf("没有找到图书信息\n");
	color(7);
	system("pause");	
	system("cls");
}

void sort(Node* head) {//排序函数'
	printf("降序排序\n");
	for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
		for (Node* move = head->next; move->next != NULL; move = move->next) {
			if (move->book.times < move->next->book.times) {
				Book temp = move->book;
				move->book = move->next->book;
				move->next->book = temp;
			}

		}
	}
	Node* move = head->next;
	printf("编号    名称                      借阅次数    \n");
	while (move != NULL) {

		printf("编号：%d 名称：%-8s           借阅次数: %d\n", move->book.number, move->book.name, move->book.times);
		move = move->next;
	}
	sort2(head);
}
void sort2(Node* head) {//排序函数
	printf("升序排序为\n");
	for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
		for (Node* move = head->next; move->next != NULL; move = move->next) {
			if (move->book.times > move->next->book.times) {
				Book temp = move->book;
				move->book = move->next->book;
				move->next->book = temp;
			}

		}
	}
	printfbook(head);
}
void shaixuan(Node* head) {//筛选系统
	system("cls");
	while (1) {
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*    欢迎来到筛选系统    *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      1.范围筛选        *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      2.中英文筛选        *\n");
		printf("\t\t\t\t\t**************************\n");
		printf("\t\t\t\t\t*      0.退出系统        *\n");
		printf("\t\t\t\t\t**************************\n");


		char t  = _getch();
		switch (t)
		{
		case'1':
			fanwei(head);
			break;
		case'2':
			zongying(head);
			break;
		case'0':
			//退出
			system("cls");
			printf("拜拜\n");
			return;

		default:
			color(4);
			printf("请重新输入\n");
			color(7);
			system("pause");
			system("cls");
		}
	}
}
void fanwei(Node* head) {//按范围筛选
	
	int a ,b;
	int cout = 0;
	Node* move = head->next;
	printf("请输入范围");
	scanf("%d %d" ,&a,&b);				
	while (move != NULL) {
		if (fanwei(move->book.times,a,b)==1) {
			printf("编号：%d 名称： %s 借阅次数：%d\n", move->book.number, move->book.name, move->book.times);
			cout++;
		}
		move = move->next;
	}
	color(2);
	printf("筛选完毕共有%d个图书符合条件\n",cout);
	color(7);
	system("pause");
	system("cls");

}
void zongying(Node* head) {//中英文书筛选
	printf("中英筛选开始\n");
	printf("\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t********英文书目录********\n");
	int cout2 = 0;
	Node* move = head->next;
	while (move != NULL) {
		if (judge(move->book.name[0]) == 1) {
			printf("编号：%d 名称： %s 借阅次数：%d\n", move->book.number, move->book.name, move->book.times);
			cout2++;
		}
		move = move->next;
	}
	printf("\t\t\t\t\t**************************\n");
	color(2);
	printf("\t\t\t\t\t筛选完毕共有%d个图书为英文书\n", cout2);
	color(7);
	printf("\t\t\t\t\t**************************\n");
	printf("\n");
	int cout = 0;
	Node* move1 = head->next;
	while (move1 != NULL) {
		cout++;
		move1 = move1->next;
	}

	Node* move2 = head->next;
	printf("\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t********中文书目录********\n");
	while (move2 != NULL) {
		if (!judge((move2->book.name[0]))) {
			printf("编号：%d 名称： %s 借阅次数：%d\n", move2->book.number, move2->book.name, move2->book.times);

		}
		move2 = move2->next;
	} 
	int c = cout - cout2;
	printf("\t\t\t\t\t**************************\n");
	color(2);
	printf("\t\t\t\t\t筛选完毕共有%d个图书为中文书\n", c);
	color(7);
	printf("\t\t\t\t\t**************************\n");
	system("pause");
	system("cls");
}

int judge(char a) {
	if (a >= 'a' && a <= 'z' || a > 'A' && a < 'Z') {
		return 1;
	}
	else
		return 0;
}
int fanwei(int a, int b, int c) {
	if (a <= c && a > b) {
		return 1;
	}
	else 
		return 0;
}
void adminpeo() {//管理员界面
	system("cls");
	while (1)
	{
		printf("\t**************************\n");
		printf("\t*     学生账号管理系统   *\n");
		printf("\t**************************\n");
		printf("\t*    1.显示人员信息      *\n");
		printf("\t**************************\n");
		printf("\t*    2.删除学生信息      *\n");
		printf("\t**************************\n");
		printf("\t*    0.退出系统          *\n");
		printf("\t**************************\n");

		FILE* fp, * fp1, * fp3;
		user a, b;
		int flag = 1;
		char t = getch();

switch (t) {

		case '2': {
			system("cls");

			printadmin();
			printf("请输入要删除的学生账号");
			char c[10];
			scanf("%s", c);
			fp3 = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "r");

			fread(&b, sizeof(user), 1, fp3);

			while (1) {

				if ((strcmp(c, b.name) == 0)) {
					break;
				}
				else {
					if (!feof(fp3)) {
						fread(&b, sizeof(user), 1, fp3);
					}
					else {
						system("cls");
						color(4);
						color(7);
						fclose(fp3);
						flag = 0;
					}
				}
			}
			if (flag == 0) {
				printf("该学生不存在\n");
			}
			else {
				fp = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "r+");

				fp1 = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\linshi.txt", "w+");
				while (fread(&b, sizeof(user), 1, fp) == 1)
				{

					if (strcmp(b.name, c) != 0)//不是要删除的内容
					{
						fwrite(&b, sizeof(user), 1, fp1);

					}
				}
				fclose(fp);
				fclose(fp1);
				fp1 = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\linshi.txt", "r");

				fp = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "w+");//刷新 用户 文件

				while (fread(&a, sizeof(user), 1, fp1) == 1)
				{
					fwrite(&a, sizeof(user), 1, fp);
				}

				fclose(fp);
				fclose(fp1);
				color(2);
				printf("删除成功！！！\n");
				color(7);
				break;
			}
		}
		
		
		case '1': {
			printadmin();
			break;
		}		
		case '0':
			system("cls");
			return;
		default:
			color(4);
			printf("输入错误请重新输入");
			color(7);
			system("pause");
			system("cls");
		}
	}

}
void deladmin() {
	FILE* fp, * fp1, * fp3;
	user a, b;
	/*FILE* fp, * ft;
	user b;
	FILE* fp1;
	int flag = 1;
	char set[20];
	int index = 0;
	printadmin();
	printf("请输入要删除的学生：");
	scanf("%s", set);
	fp1 = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "r");

	fread(&b, sizeof(user), 1, fp1);

	while (1) {

		if ((strcmp(set, b.name) == 0)) {
			break;
		}
		else {
			if (!feof(fp1)) {
				fread(&b, sizeof(user), 1, fp1);
			}
			else {
				fclose(fp1);
				flag = 0;
				break;
			}
		}
	}
	fclose(fp1);


	if (flag == 1) {
		char key[20];
		fp = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "r");
		ft = fopen("d:\\temp.txt", "a+");
		if (fp == NULL || ft == NULL) {
			printf("错误！\n");
			return;
		}
		while (fread(key, sizeof(key), 1, fp)) {
			if (strcmp(key, set) != 0) {
				fwrite(key, sizeof(key), 1, ft);
				index++;
			}
			else {
				rewind(fp);
				fseek(fp, sizeof(key) * (index + 2), 0);
			}

		}
		fclose(fp);
		fclose(ft);
		remove("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt");
		rename("d:\\temp.txt", "C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt");
		color(2);
		printf("学生账号信息删除成功！\n");
		color(7);
		printadmin();
		system("cls");
	}
	else
		system("cls");
	color(4);
	printf("没有该学生\n");
	color(7);
	system("pause");
	system("cls");*/
	fp3 = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "r");

	int num = 1;
	system("cls");
	printf("人员信息如下:\n");
	printf("\t用户名 \t密码\n");

	while (fread(&b, sizeof(user), 1, fp3) == 1)
	{

		printf("\t%d %s \t%s\n", num, b.name, b.log);
		num++;
	}
	rewind(fp3);
	fclose(fp3);
	char c[10];
	fp = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "r+");

	fp1 = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\linshi.txt", "w+");

	scanf("%s", c);

	while (fread(&b, sizeof(user), 1, fp) == 1)
	{

		if (strcmp(b.name, c) != 0)//不是要删除的内容
		{
			fwrite(&b, sizeof(user), 1, fp1);

		}
	}
	fclose(fp);
	fclose(fp1);
	fp1 = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\linshi.txt", "r");

	fp = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "w+");//刷新 用户 文件

	while (fread(&a, sizeof(user), 1, fp1) == 1)
	{
		fwrite(&a, sizeof(user), 1, fp);
	}

	fclose(fp);
	fclose(fp1);
	color(2);
	printf("删除成功！！！\n");
	color(7);
}
void printadmin() {
	FILE* fp;
	user  b;
	fp = fopen("C:\\Users\\21673\\source\\repos\\图书管理系统\\name.txt", "r");
	int num = 1;

	system("cls");

	printf("人员信息如下:\n");

	printf("\t用户名        \t密码\n");
	while (fread(&b, sizeof(user), 1, fp) == 1)
	{

		printf("\t%d %-10s \t%s\n", num, b.name, b.log);
		num++;
	}
		fclose(fp);

		system("pause");
		system("cls");
	}
void sort3(Node* head) {//排序函数
	for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
		for (Node* move = head->next; move->next != NULL; move = move->next) {
			if (strcmp(move->book.name,move->next->book.name)>0) {
				Book temp = move->book;
				move->book = move->next->book;
				move->next->book = temp;
			}

		}
	}
	printfbook(head);
}




	
