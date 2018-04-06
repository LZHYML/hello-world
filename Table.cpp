#include <iostream>
#include <cstdlib>		//包含itoa()
#include <string>		//包含strcpy()
#include <windows.h>	//包含system()、COORD、HANDLE
#define R 10	//最大行数
#define C 14	//最大列数
#define W 10	//字符串最大长度
using namespace std;

class Table
{
public:
  Table(int r = 5, int c = 10, int w = 4);
  void show();							//打印
  void addRow(int x = 1);				//在第X列新增一行
  void addColumn(int y = 1);			//在第y列新增一列
  void set(int r, int c, char s[]);		//在r行c列写入字符串
  void set(int x, int y, int digit);	//在x行y列写入数字
  void delRow(int x = 1);				//删除第x行
  void delColumn(int y = 1);			//删除第y列
private:
  int row, column, width;				//行数、列数、单元格宽度
  char str[R+1][C+1][W+1];				//单元格内容存储地址
  void Pos(int x, int y);				//移动光标
};

int main() {
  Table tb;
  tb.show();
  tb.addRow();
  tb.show();
  tb.addColumn();
  tb.show();
  Table tb1(5,5);
  tb1.show();
  tb1.set(1,1,30);
  tb1.set(2,2,"hello");
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(1);
  tb1.show();
  return 0;
}

//【光标坐标】
void Table::Pos(int x, int y)	
{
	COORD pos;
	HANDLE hOutput;
	pos.X = 2*y - 1;	//列
	pos.Y = x;			//行
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}

//【构造函数】初始化：行、列、宽、单元格内容
Table::Table(int r, int c, int w)
{
	system("cls");
	if(r>R || c>C || r<1 || c<1 || w<2)
	{
		Pos(28,15);
		cout<<"初始化数据非法！恢复默认初始化";
		Pos(28,2);
		system("pause");
		r = 5;
		c = 10;
		w = 4;
	}
	row = r;
	column = c;
	width = w;
	for(int i = 0; i <= row; i++)
		for(int j = 0; j <= column; j++)
			strcpy(str[i][j], "\0");
}

//【展示】清屏，打印：表格、单元格内容
void Table::show()
{
	system("cls");//打印前清屏
	//[打印表格]
	for(int c = 1; c <= width*column+1; c++)
	{
		for(int r = 1; r <= 2*row+1; r++)
		{
			if(c == 1)
			{
				if(r == 1)
				{
					Pos(r,c);
					cout<<"┏";
				}
				else if(r == 2*row+1)
				{
					Pos(r,c);
					cout<<"┗";
				}
				else if(r%2==1)
				{
					Pos(r,c);
					cout<<"┣";
				}
				else
				{
					Pos(r,c);
					cout<<"┃";
				}
			}
			else if(c == width*column+1)
			{
				if(r == 1)
				{
					Pos(r,c);
					cout<<"┓";
				}
				else if(r == 2*row+1)
				{
					Pos(r,c);
					cout<<"┛";
				}
				else if(r%2==1)
				{
					Pos(r,c);
					cout<<"┫";
				}
				else
				{
					Pos(r,c);
					cout<<"┃";
				}		
			}
			else if(c%width==1)
			{
				if(r == 1)
				{
					Pos(r,c);
					cout<<"┳";
				}
				else if(r == 2*row+1)
				{
					Pos(r,c);
					cout<<"┻";
				}
				else if(r%2==1)
				{
					Pos(r,c);
					cout<<"╋";
				}
				else
				{
					Pos(r,c);
					cout<<"┃";
				}
			}
			else if(r%2==1)
			{
				Pos(r,c);
				cout<<"━";
			}
		}
	}
	//[填充内容]
	for(int r = 1; r <= row; r++)
	{
		for(int c = 1; c <= column; c++)
		{
			Pos(2*r,2+width*(c-1));
			cout<<str[r][c];
		}
	}
	Pos(28,2);
	system("pause");
}

void Table::addRow(int x)
{
	if(x > row+1 || x < 1)
	{
		Pos(28,15);
		cout<<"非法加行，操作无效！";
		Pos(28,2);
		system("pause");
		return;
	}
	if(row >= R)
	{
		Pos(28,15);
		cout<<"已到达最大行数，加行操作无效！";
		Pos(28,2);
		system("pause");
		return;
	}
	row++;
	int r,c;
	for(c = 1; c <= column; c++)
	{
		for(r = row; r > x; r--)
			strcpy(str[r][c],str[r-1][c]);
		strcpy(str[r][c], "\0");
	}
}

void Table::addColumn(int y)
{
	if(y > column+1 || y < 1)
	{
		Pos(28,15);
		cout<<"非法加列，操作无效！";
		Pos(28,2);
		system("pause");
		return;
	}
	if(column >= C)
	{
		Pos(28,15);
		cout<<"已到达最大列数，加列操作无效！";
		Pos(28,2);
		system("pause");
		return;
	}
	int r,c;
	column++;
	for(r = 1; r <= row; r++)
	{
		for(c = column; c > y; c--)
			strcpy(str[r][c],str[r][c-1]);
		strcpy(str[r][c], "\0");
	}
}

void Table::set(int r, int c, char s[])
{
	if(r>row || c>column || r<1 || c<1)
	{
		Pos(28,15);
		cout<<"所加元素不在表格内，操作无效！";
		Pos(28,2);
		system("pause");
		return;
	}
	strcpy(str[r][c], s);
}

void Table::set(int x, int y, int digit)
{
	if(x>row || y>column || x<1 || y<1)
	{
		Pos(28,15);
		cout<<"所加元素不在表格内，操作无效！";
		Pos(28,2);
		system("pause");
		return;
	}
	itoa(digit, str[x][y], 10);
}

void Table::delRow(int x)
{
	if(x>row || x<1)
	{
		Pos(28,15);
		cout<<"所减行不在表格内，操作无效！";
		Pos(28,2);
		system("pause");
		return;
	}
	if(row <= 1)
	{
		Pos(28,15);
		cout<<"已到达最小行数，减行操作无效！";
		Pos(28,2);
		system("pause");
		return;
	}
	int r,c;
	row--;
	for(c = 1; c <= column; c++)
	{
		for(r = x; r <= row; r++)
			strcpy(str[r][c], str[r+1][c]);
		strcpy(str[r][c], "\0");
	}
}

void Table::delColumn(int y)
{
	if(y>column || y<1)
	{
		Pos(28,15);
		cout<<"所减列不在表格内，操作无效！";
		Pos(28,2);
		system("pause");
		return;
	}
	if(column <= 1)
	{
		Pos(28,15);
		cout<<"已到达最小列数，减列操作无效！";
		Pos(28,2);
		system("pause");
		return;
	}
	int r,c;
	column--;
	for(r = 1; r <= row; r++)
	{
		for(c = y; c <= column; c++)
			strcpy(str[r][c], str[r][c+1]);
		strcpy(str[r][c], "\0");
	}
}
