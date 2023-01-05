#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#define N 21
#include<iostream>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#include <stdio.h>
#include <stdlib.h>
#include <ege.h>
#include <graphics.h>
#include <thread>
using namespace std;
int mouse=GetAsyncKeyState(VK_LBUTTON)&0x8000;
int mainum;
bool last_6,main_1,window_s,sight_p,kcb_1,idark_1;
void idark();
int blue();
POINT Windowpos()
{
	POINT pt;
	GetCursorPos(&pt);
	HWND h=GetForegroundWindow();
	ScreenToClient(h,&pt);
	pt.x/=8;pt.y/=16;
	return pt; 
}

int n,p,zj=0,tk=0,jtl=0,q=200,y,t,s1,s2,c,c1,c2;
int car[10005][10005]= {0};
void maint();
int timer();
int mains();
int xl(int x) {
	int i;
	cout<<"----------------------"<<endl;
	cout<<"|";
	if(x<=3)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);
	for(i=0; i<x; i++)
		cout<<"▉";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	for(int i=0; i<10-x; i++)cout<<"  ";
	cout<<"|"<<endl;
	cout<<"----------------------";
	return i;
}
void dj(int x,int x2,int n) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	system("cls");
	cout<<"--------------------------------|"<<endl;
	xl(x);
	cout<<"    玩家  |"<<endl;
	cout<<"--------------------------------|"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED);
	if(tk==1)
		cout<<"            头盔"<<endl;
	if(zj==1)
		cout<<"    装甲"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	xl(x2);
	cout<<"   敌人 |"<<endl;
	cout<<"--------------------------------|-------------------------------------------"<<endl;
	cout<<"                     第"<<t<<"轮                   ↑"<<endl;
	cout<<"--------------------------------|-------------------------------------------"<<endl;
	if(tk>=1&&x<=5) {
		x++;
		cout<<"头盔抵挡一次伤害"<<endl;
		tk--;
	}
	if(zj>=1&&x<=5) {
		x++;
		cout<<"装甲抵挡一次伤害"<<endl;
		zj--;
	}
	if(x<=0) {
		cout<<"你输了!";
		system("pause");
		maint();
	}
	
	else if(x2<=0) {
		cout<<"你赢了!";
		system("pause");
		q+=100;
		maint();
	}
	
	if(n==1||n==4) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED);
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|             ▉                                    |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                        |                          |"<<endl;
		cout<<"|                     -- 0 --                       |"<<endl;
		cout<<"|                        |                          |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"未击中"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_GREEN);
	}
	if(n==2||n==5) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                        |                          |"<<endl;
		cout<<"|                     -- 1 --                       |"<<endl;
		cout<<"|                        |                          |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"击中"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	} else if(n==3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_BLUE);
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                        |                          |"<<endl;
		cout<<"|                     -- 1 --                       |"<<endl;
		cout<<"|                        |                          |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"|                                                   |"<<endl;
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"加血"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	cout<<"1.枪 2.刀";
	if(jtl==1)
		cout<<"3. 加特林";
	cout<<endl;
	//while(1){
	cout<<"->";
	//}
	cin>>p;
	n=rand()%5+1;
	if(n==1||n==4) {
		x--;
		t++;
		dj(x,x2,n);
	} else if(n==2||n==5) {
		if(jtl==1&&p==3)x2--;
		x2--;
		t++;
		dj(x,x2,n);
		
	} else {
		if(x<10)
			x++;
		if(x2<10)
			x2++;
		t++;
		dj(x,x2,n);
		
	}
}
int main();
int sd(int x) {
	system("cls");
	cout<<"          |           钱：";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);
	cout<<q;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout<<"      |"<<endl;
	cout<<endl;
	cout<<"          -------------------------"<<endl;
	cout<<"          | 1.装甲 50 | 2.头盔 50 |"<<endl;
	cout<<"          -------------------------"<<endl;
	cout<<"          |3.加特林200|           |"<<endl;
	cout<<"          -------------------------"<<endl;
	cout<<"          |";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |FOREGROUND_INTENSITY | BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE |BACKGROUND_RED);
	cout<<"         0.退出        ";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout<<"|"<<endl;
	cout<<"          -------------------------"<<endl;
	cin>>p;
	if(p==0) {
		maint();
	}
	if(p==1) {
		if(q>=50) {
			cout<<"已购买并装上"<<endl;
			zj++;
			q=q-50;
			sd(x);
		} else
			cout<<"钱不够"<<endl;
		sd(x);
	}
	if(p==2)
		if(q>=50) {
		cout<<"已购买并装上"<<endl;
		tk++;
		q=q-50;
		sd(x);
	} else
		cout<<"钱不够"<<endl;
	if(p==3)
		if(q>=200) {
		cout<<"已购买并装上"<<endl;
		jtl=1;
		q=q-200;
		sd(x);
	} else
		cout<<"钱不够"<<endl;
	sd(x);
	return p;
}

int gb() {
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
int print_f(int m) {
	
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=m; j++) {
			cout<<car[i][j];
		}
		cout<<endl;
	}
}
int qz(int x,int q) {
	if(x==0) {
		cout<<"你输了...";
		maint();
	}
	if(car[27][28]!=2) {
		cout<<"你赢了!";
		q+=100;
		maint();
	}
	if(n==27||y==28) {
		for(int i=1; i<=30; i++)
			car[n][i]=3;
		car[27][28]=2;
		x--;
	}
	if(n<1||n>30||y<1||y>30)
		n=y=15;
	system("cls");
	cout<<n<<y<<endl;
	xl(x);
	cout<<endl;
	print_f(30);
	cin>>p;
	if(p==8)
		
		if(n!=0) {
		car[n][y]=0;
		n--;
		car[n][y]=1;
		qz(x,q);
	}
	
	if(p==5)
		if(n!=30) {
		car[n][y]=0;
		n++;
		car[n][y]=1;
		qz(x,q);
	}
	
	if(p==4)
		if(y!=0) {
		car[n][y]=0;
		--y;
		car[n][y]=1;
		qz(x,q);
	}
	
	if(p==6) {
		if(y!=30) {
			car[n][y]=0;
			++y;
			car[n][y]=1;
			qz(x,q);
		}
	}
	
	system("pause");
	
	
}
void Go(int x,int y);
void maint() {
	cout<<"登录账号密码:";
	string zhmm;
	cin>>zhmm;
	if(zhmm!="樊锶宸")
		mains();
	gb();
	int m = 0, t1 = 0, x = 10, p;
	memset(car,0,sizeof(car));
	system("cls");
	cout<<"0.退出 1.枪战 2.商店 3.签到 4.对战 5.打字 6.植物大战僵尸"<<endl;
	cin>>p;
	if(p==6)
	{
		Go(15,15);
		cout<<"请下载植物大战僵尸.exe";
		
		system("start 植物大战僵尸.exe");
	}
	if(p==1) {
		n=rand()%30+1;
		y=rand()%30+1;
		car[n][y]=1;
		car[27][28]=2;
		qz(x,q);
	}
	if(p==2) {
		while(1) {
			sd(x);
			if(p==0)
				break;
			int p = 0;
			maint();
		}
	}
	if(p==3) {
		SYSTEMTIME sys;
		GetLocalTime( &sys );
		cout<<"OK";
		freopen("qd.log","r",stdin);
		freopen("qd.log","w",stdout);
		string xq;int nuq;
		cin>>nuq;
		for(int i;i<=nuq;i++)
			cin>>xq,cout<<xq;
		cout<<"签到"<<' '<<nuq+1<<' '<<sys.wMonth<<' '<<sys.wDay<<' '<<sys.wHour<<' '<<sys.wMinute;
		exit(0);
	}
	if(p==4) {
		dj(10,10,0);
	}
	if(p==0) {
		mains();
	}
	if(p==5) {
		while(1) {
			cout<<"|";
			system("cls");
			Sleep(10);
		}
		
	}
}
int print_gj() {
	printf(" ╪╪╪╪╪╪╧╧╧╧╧╧╧╧╪╪╪╪╪╪\n");
	printf("╔═════╧╧关 机 ╧╧═════╗\n");
	printf("║※1.实现10分钟内的定时关闭计算机  ║\n");
	printf("║※2.立即关闭计算机　              ║\n");
	printf("║※3.注销计算机　                  ║\n");
	printf("║※0.退出系统　                    ║\n");
	printf("║※4.问题    　                    ║\n");
	printf("╚═════════════════╝\n");
	return 0;
}
void gotoxy(int x,int y) {
	//位置函数
	COORD pos;
	pos.X=2*x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void color(int a) { //颜色函数
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void init(int apple[2]) { //初始化函数（初始化围墙、显示信息、苹果）
	int i,j;//初始化围墙
	int wall[N+2][N+2]= {{0}};
	for(i=1; i<=N; i++) {
		for(j=1; j<=N; j++)
			wall[i][j]=1;
	}
	color(11);
	for(i=0; i<N+2; i++) {
		for(j=0; j<N+2; j++) {
			if(wall[i][j])
				cout<<"  ";
			else cout<<"□" ;
		}
		cout<<endl;
	}
	gotoxy(N+3,1);//显示信息
	color(20);
	cout<<"按 W S A D 移动方向"<<endl;
	gotoxy(N+3,2);
	color(20);
	cout<<"按任意键暂停"<<endl;
	gotoxy(N+3,3);
	color(20);
	cout<<"得分："<<endl;
	apple[0]=rand()%N+1;//苹果
	apple[1]=rand()%N+1;
	gotoxy(apple[0],apple[1]);
	color(12);
	cout<<"●"<<endl;
}
int tyu2,yhmm=0;
char x[3];
long long s,z;
double b1,b2,b3,b4,b5,b6,b7,b8,b9,b0,l,v,u,r,ew,er,hj,jk;
int a,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,b,i,d,T,m,e,qq=0,ww=0,xyz,qwe,ert,wer,rty,tyu,yui,qqq;
const int MOD=1000000;















////////////////////////////////////////////////////////////////






int blue(int n);
int last6();
int windows();
void Go(int x,int y);

/*
HWND GetConsoleHwnd(void)
{
#define MY_BUFSIZE 1024 // Buffer size for console window titles.
	HWND hwndFound; // This is what is returned to the caller.
	char pszNewWindowTitle[MY_BUFSIZE]; // Contains fabricated
	// WindowTitle.
	char pszOldWindowTitle[MY_BUFSIZE]; // Contains original
	// WindowTitle.
	// Fetch current window title.
	GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);
	// Format a "unique" NewWindowTitle.
	wsprintf(pszNewWindowTitle,"%d/%d",
		GetTickCount(),
		GetCurrentProcessId());
	// Change current window title.
	SetConsoleTitle(pszNewWindowTitle);
	// Ensure window title has been updated.
	Sleep(40);
	// Look for NewWindowTitle.
	hwndFound=FindWindow(NULL, pszNewWindowTitle);
	// Restore original window title.
	SetConsoleTitle(pszOldWindowTitle);
	return(hwndFound);
}
*/
int main2();
int mains() {
	if(!last_6)
		return 0;
	system("cls");
	if(mainum>=100)
	{
		blue(3);
	}
	color(3);
	system("date /T");
	system("time /T");
	color(7);
	cout<<"1.计算 2.游戏 3.百度 4.聊天"<<endl;
	cout<<"5.更多功能 6.重启 7.窗口 8.more"<<endl;
	mainum++;
	cin>>y;
	if(y==6)
	{
		last6();
	}
	if(y==7)
	{
		windows();
	}
	if(y==2) {
		cout<<"1.锤子剪刀布 2.猜数字 3.贪吃蛇 4.更多"<<endl;
		cin>>d;
		if(d==1) {
			for(i=1; i<=1000000; i++) {
				cout<<"1.锤子 2.剪刀 3.布"<<endl;
				cin>>a;
				cout<<"上一轮你比电脑"<<qq<<":"<<ww<<endl;
				srand((unsigned)time(NULL));
				b=rand()%3+1;
				if(a==b)
					cout<<"你和电脑出得相同，平"<<endl;
				else if(a==1&&b==2) {
					cout<<"电脑出剪刀，胜"<<endl;
					qq=qq+1;
				}//1.锤子 2.剪刀 3.布
				else if(a==1&&b==3) {
					cout<<"电脑出布，输"<<endl;
					ww=ww+1;
				} else if(a==2&&b==1) {
					cout<<"电脑出锤子，输"<<endl;
					ww=ww+1;
				} else if(a==2&&b==3) {
					cout<<"电脑出布，胜"<<endl;
					qq=qq+1;
				} else if(a==3&&b==1) {
					cout<<"电脑出锤子，胜"<<endl;
					qq=qq+1;
				} else if(a==3&&b==2) {
					cout<<"电脑出剪刀，输"<<endl;
					ww=ww+1;
				}
				cout<<"本轮你比电脑"<<qq<<":"<<ww<<endl;
				if(ww==10||qq==10)
					break;
			}
			system("pause");
			system("cls");
			system("time");
		}//游戏d
		if(d==2) {
			for(i=1; i<=1000000; i++) {
				srand((unsigned)time(NULL));
				b=rand()%3+1;
				cin>>e;
				if(e==b) {
					cout<<"恭喜恭喜，对了！！"<<endl;
					break;
				} else if(e<b)
					cout<<"小了。。。"<<endl;
				else if(e>b)
					cout<<"大了。。。"<<endl;
			}
			system("pause");
		} else if(d==3) {
			system("cls");
			int i,j;
			int** snake=NULL;
			int apple[2];
			int score=0;
			int tail[2];
			int len=3;
			char ch='p';
			srand((unsigned)time(NULL));
			init(apple);
			snake=(int**)realloc(snake,sizeof(int*)*len);
			for(i=0; i<len; i++)
				snake[i]=(int*)malloc(sizeof(int)*2);
			for(i=0; i<len; i++) {
				snake[i][0]=N/2;
				snake[i][1]=N/2+i;
				gotoxy(snake[i][0],snake[i][1]);
				color(14);
				cout<<"★"<<endl;
			}
			while(1) { //进入消息循环
				tail[0]=snake[len-1][0];
				tail[1]=snake[len-1][1];
				gotoxy(tail[0],tail[1]);
				color(11);
				cout<<"■"<<endl;
				for(i=len-1; i>0; i--) {
					snake[i][0]=snake[i-1][0];
					snake[i][1]=snake[i-1][1];
					gotoxy(snake[i][0],snake[i][1]);
					color(14);
					cout<<"■"<<endl;
				}
				if(kbhit()) {
					gotoxy(0,N+2);
					//ch=getche();
				}
				switch(ch) {
				case 'w':
					snake[0][1]--;
					break;
				case 's':
					snake[0][1]++;
					break;
				case 'a':
					snake[0][0]--;
					break;
				case 'd':
					snake[0][0]++;
					break;
				default:
					break;
				}
				gotoxy(snake[0][0],snake[0][1]);
				color(14);
				cout<<"■"<<endl;
				Sleep(abs(200-0.5*score));
				if(snake[0][0]==apple[0]&&snake[0][1]==apple[1]) { //吃掉苹果后蛇分数加1，蛇长加1
					score++;
					len++;
					snake=(int**)realloc(snake,sizeof(int*)*len);
					snake[len-1]=(int*)malloc(sizeof(int)*2);
					apple[0]=rand()%N+1;
					apple[1]=rand()%N+1;
					gotoxy(apple[0],apple[1]);
					color(12);
					cout<<"●"<<endl;
					gotoxy(N+5,3);
					color(20);
					cout<<score<<endl;
				}
				if(snake[0][1]==0||snake[0][1]==N||snake[0][0]==0||snake[0][0]==N) { //撞到围墙后失败
					gotoxy(N/2,N/2);
					color(30);
					system("cls");
					for(i=0; i<=100; i++) {
						cout<<"     ";
					}
					system("color 4C");
					cout<<"             失败！！！"<<endl;
					cout<<"       |          |"<<endl;
					cout<<"        |        |"<<endl;
					cout<<"         |      |"<<endl;
					cout<<"          |    |"<<endl;
					cout<<"           |  |"<<endl;
					cout<<"            ||"<<endl;
					cout<<"           |  |"<<endl;
					cout<<"          |    |"<<endl;
					cout<<"         |      |"<<endl;
					cout<<"        |        |"<<endl;
					cout<<"       |          |"<<endl;
					
					cout<<"                                       得分:"<<score;
					
					for(i=0; i<len; i++)
						free(snake[i]);
					Sleep(INFINITE);
					exit(0);
				}
			}
			return 0;
		} else {
			system("mode con cols=1000 lines=100");
			maint();
		}
		
	}
	
	//游戏
	else if(y==1) {
		cout<<"1.+ 2.- 3.* 4./ 5.! 6.√￣ 7.㎡ 8.分解质因数"<<endl;
		cin>>q;
		if(q==1) {
			cout<<"请输入2个数："<<endl;
			cin>>l>>v;
			cout<<l+v<<endl;
			system("pause");
		} else if(q==2) {
			cout<<"请输入2个数："<<endl;
			cin>>u>>r;
			cout<<u+r<<endl;
			system("pause");
		} else if(q==3) {
			cout<<"请输入2个数："<<endl;
			cin>>ew>>er;
			cout<<ew*er<<endl;
			system("pause");
		} else if(q==4) {
			cout<<"请输入2个数："<<endl;
			cin>>hj>>jk;
			cout<<hj/jk;
			system("pause");
		} else if(q==5) {
			cout<<"n*(n-1)*...*1 请输入1个数(n)："<<endl;
			scanf("%lld",&a1);
			s=1;
			for(i=1; i<=a1; i++) {
				s=s*(s+1);
			}
			cout<<s<<endl;
		} else if(q==6) {
			cout<<"请输入1个数,进行开方运算"<<endl;
			cin>>a0;
			sqrt(a0);
			cout<<a0<<endl;
		} else if(q==7) {
			cout<<"请输入2个数，n的m次方："<<endl;
			long long x9,y9,ans=1,cnt=x9;
			cin>>x9>>y9;
			while(y9) {
				if(y9&1) {
					ans*=cnt;
				}
				cnt*=cnt;
				y9>>=1;
			}
			cout<<ans;
		} else if(q==9) {
			cout<<"1.多元一次方程 2.一元二次方程"<<endl;
			cin>>qq;
			if(qq==1) {
				cout<<"n元一次(1≤n≤3)"<<endl;
				cin>>qq;
				if (qq == 1) {
					cout<<"开始"<<endl;
					cin>>a;
					cout<<"x+";
					cin>>b;
					cout<<"=";
					cin>>c;
					cout<<fixed<<setprecision(100)<<c/(a+b);
				}
				if (qq == 2) {
					cout<<"开始"<<endl;
					cin>>a1;
					cout<<"x+";
					cin>>b1;
					cout<<"y=";
					cin>>c1;
					cin>>a2;
					cout<<"x+";
					cin>>b2;
					cout<<"y=";
					cin>>c2;
				}
				
			} else if(qq==2) {
				cout<<"开始"<<endl;
				cin>>a;
				cout<<"x^2+";
				cin>>b;
				cout<<"x+";
				cin>>c;
				cout<<"=0"<<endl;
				cout<<a<<"x^2+"<<b<<"x+"<<c<<"=0";
				cout<<endl;
				if((b*b-4*a*c)>=0) {
					cout<<"△="<<fixed<<setprecision(100)<<b*b-4*a*c<<endl;
					cout<<"x1="<<fixed<<setprecision(100)<<(-b*b-sqrt(b*b-4*a*c)/2/a)<<endl;
					cout<<"x2="<<fixed<<setprecision(100)<<(-b*b+sqrt(b*b-4*a*c)/2/a)<<endl;
				} else {
					cout<<"无解";
				}
			}
		} else if(q==8) {
			cin>>a0;
			cout<<a0<<"=1";
			if(a0%2==0)
				cout<<"*2";
			for(int i=3; i<=sqrt(a0); i+=2) {
				if(a0%i==0)
					cout<<"*"<<i;
			}
			cout<<endl;
			cout<<a0<<"有质因数:";
			for(int i=1; i<=a0; i++) {
				if(a0%i==0)
					cout<<' '<<i;
			}
		}
	} 
	else if(y==3) {
		cout<<"1.百度 2.360 3.bing 4.google\n";
		cin>>xyz;
		cout<<"请输入您要搜索的内容：";
		if(xyz==1)
		{
			char t[10],cmd[2000]="start https://www.baidu.com/s?word=";
			cin>>t;
			system(strcat(cmd,t));
		}
		else if(xyz==3)
		{
			char t[10],cmd[2000]="start https://www.bing.com/search?q=";
			cin>>t;
			system(strcat(cmd,t));
		}
		else if(xyz==2)
		{
			char t[10],cmd[2000]="start https://www.so.com/s?q=";
			cin>>t;
			system(strcat(cmd,t));
		}
		else if(xyz==4)
		{
			char t[10],cmd[2000]="start https://www.google.com.hk/search?client=";
			color(12);cout<<"<请注意，由于Google退出中国大陆,可能无法访问>";
			cin>>t;
			system(strcat(cmd,t));
		}
		//HWND hWnd=FindWindow("ConsoleWindowClass",NULL);
		//ShowWindow(hWnd,SW_HIDE);\
		//GetConsoleHwnd();
		system("pause");
	} 
	else if(y==4) {
		cout<<"1.微信 2.电话 3.便签"<<endl;
		cin>>qwe;
		if(qwe==1) {
			cout<<"“＋”"<<endl;
			cin>>wer;
			cout<<"．．．．．．．．．．．．"<<endl;
			system("start https://wx.qq.com"); 
			system("pause");
		} else if(qwe==2) {
			cin>>ert;
			cout<<"正在呼出。。。"<<endl;
			for(i==1; i<=100; i++)
				cout<<" "<<endl;
			cout<<"请插卡"<<endl;
			system("pause");
		} else if(qwe==3) {
			char*rty;
			scanf("&d","rty");
			freopen("未命名","r",stdout);
			printf("&d","rty");
		}
		
		system("pause");
	} 
	else if(y==5) {
		cout<<"1.大小 2.关机 3.时间 4.网络 5.锁屏 6.退出登录"<<endl;
		cin>>yui;
		if(yui==1) {
			cout<<"1.音量 2.屏幕"<<endl;
			cin>>qqq;
			if(qqq==1)
				cin>>i;
			else
				cin>>a;
			system("pause");
		} else if(yui==2) {
			system("title C语言关机程序");//设置cmd窗口标题
			system("mode con cols=48 lines=25");//窗口宽度高度
			system("color 0B");
			system("date /T");
			system("TIME /T");
			char cmd[20]="shutdown -s -t ";
			char t[5]="0";
			print_gj();
			int c;
			scanf("%d",&c);
			getchar();
			switch(c) {
			case 1:
				printf("您想在多少秒后自动关闭计算机？（0~600）\n");
				scanf("%s",t);
				system(strcat(cmd,t));
				break;
			case 2:
				system("shutdown -p");
				break;
			case 3:
				system("shutdown -l");
				break;
			case 0:
				break;
			case 4:
				system("mode con cols=1000 lines=100");
				system("shutdown -?");
				break;
			default:
				printf("Error!\n");
			}
			system("pause");
			exit(0);
		} 
		else if(yui==3) {
			cout<<"1.时区 2.时间制 3.计时 4.闹钟"<<endl;
			cin>>a;
			if(a==1) {
				cout<<"1.English 2.中国"<<endl;
				cin>>i;
				cout<<"OK"<<endl;
				system("pause");
			} else if(a==2) {
				cout<<"1.(24) 2.(12)"<<endl;
				cin>>i;
				system("pause");
				system("time");
			} 
			else if(a==3)
			{
				timer();
				SYSTEMTIME sys;
				GetLocalTime( &sys );
				int tst1=sys.wMinute;
				int tst2=sys.wHour;
				color(15);
				while(1)
				{
					SYSTEMTIME sys;
					GetLocalTime( &sys );
					cout<<sys.wHour-tst1<<"小时"<<sys.wMinute<<"分钟"<<sys.wSecond<<"秒",system("cls");
					Sleep(100);
				}
				
			}
			else
			{
				int x,y,z;
				cout<<"小时:";cin>>x;cout<<"分钟:";cin>>y;cout<<"秒:";cin>>z;
				timer();
				SYSTEMTIME sys;
				GetLocalTime( &sys );
				int tst1=sys.wHour;
				int tst2=sys.wMinute;
				int tst3=sys.wSecond;
				while(1){
					SYSTEMTIME sys;
					GetLocalTime( &sys );
					if(sys.wHour-tst1>=x && sys.wMinute-tst2>=y)
					{
						Sleep(sys.wSecond*100);
						cout<<"到时";
						break;
					}
					else
						continue;
				}
				
				MessageBox(NULL,TEXT("您设定的闹钟到时了"),TEXT("到时"),MB_ICONEXCLAMATION);
				main2(); 
				//MessageBox(m_hWnd,_T(),_T,  ); 
			}
			//				cout<<"已启动  2.停止"<<endl;
			//			const int MOD=1000000;
			//			int a,n,s=0;
			//			scanf("%d",&n);
			//			for(int i=1; i<=n; ++i) {
			//				int factorial=1;
			//				for(int j=1; j<=i; ++j)
			//					factorial=(factorial*j%MOD);
			//				s=(s+factorial)%MOD;
			//			}
			printf("%d\n",s);
			scanf("%d",&a);
			printf("Time used=%.21f\n",(double)clock()/CLOCKS_PER_SEC);
		}
		if(yui==4) {
			cout<<"1.WiFi 2.移动 3.蓝牙"<<endl;
			cin>>d;
			if(d==1) {
				cout<<"正在刷新"<<endl;
				cout<<"附件没有可连接WiFi"<<endl;
				system("pause");
			} else if(d==2) {
				cout<<"你还没有购买，没有移动网！"<<endl;
			} else {
				cout<<"1.开 2.关"<<endl;
				cin>>i;
				if(i==1)
					cout<<"已经打开"<<endl;
				else
					cout<<"已经关闭"<<endl;
			}
		} else if(yui==5) {
			for(i==1; i>=1;) {
				cout<<" "<<endl;
			}
		}
		else if(yui==6)
		{
			main2();
		}
	}
	else if(y==8)
	{
		cout<<"1.更新 2.idarkSP 3.文件加密 4.文件解密";
		int y8;
		cin>>y8;
		if(y8==1)
			system("upd.exe");
		if(y8==2)
		{
			system("cd C:\\Program Files\\Windows Defender\\");
			system("MpCmdRun -Scan -ScanType 3 -File 2");
		}
		if(y8==3)
		{
			system("md \\1file"); 
			cout<<"请将加密文件放程序目录中的1flle文件夹";
			system("pause");
			system("rar a -pIidarkissOSafe here 1file");
			system("ren here.rar here.idk");
			system("cls");
			cout<<"加密文件在程序目录here.idk";
			system("pause");
		}
		if(y8==4)
		{
			cout<<"请将加密文件here.idk放程序目录";
			system("ren here.idk here.rar");
			system("unrar e -pIidarkissOSafe here.rar");
			
			system("cls");
			cout<<"文件在程序目录";
			system("pause");
		}
	} 
	mains();
}
int main2(){
	system("cls");
	cout<<"正在开机"<<endl;
	Sleep(1000);
	cout<<"请输入3位用户名："<<endl;
	cin>>x;
	cout<<"请输入4位密码："<<endl;
	char ch,str[100];
	int i=0;
	while(1) {
		ch=getch();
		if(ch!=13) {
			str[i]=ch;
			i++;
			printf("*");//" "中可定义。
		} else {
			break;
		}
	}
	printf("\n");
	if(x[0]=='1') {
		freopen("yhmm","r",stdin);
		cin>>yhmm;
		if(yhmm==1) {
			mains();
		} else
			return 0;
	} else if(x[0]!='f'||x[1]!='s'||x[2]!='c'||str[0]!='0'||str[1]!='4'||str[2]!='2'||str[3]!='1')
		//if(z!=1)
	{
		cout<<"密码/用户名不对      ";
		system("color 0C");
		cout<<"[1.免费注册]"<<endl;
		cin>>tyu;
		if (tyu == 1) {
			system("cls");
			cout<<"请输入手机号：";
			long long syt;
			cin>>tyu2;
			if(/*(tyu2<19000000000)&&(tyu2>12111111111)*/tyu2!=0) {
				system("color 02");
				cout<<"|  √|"<<endl;
				cout<<"|成功|"<<endl;
			} else {
				cout<<"请输入正确的手机号"<<endl;
			}
		} else {
			cout<<"请再试一遍:";
			cout<<"请输入3位用户名："<<endl;
			cin>>x;
			cout<<"请输入4位密码："<<endl;
			cin>>z;
			
		}
	}
	//freopen("yhmm","w",stdout);
	//cout<<1;
	mains();
}
struct Button{
	int x,y,color;
	const char *name;
	int len;
};
void GetPos(POINT &pt){
	HWND hwnd=GetForegroundWindow();
	GetCursorPos(&pt);
	ScreenToClient(hwnd,&pt);
	pt.y=pt.y/16,pt.x=pt.x/16;
}
void gto(int x,int y)
{
	COORD pos;pos.X=y*2;pos.Y=x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

Button NewButton(int x,int y,int color,const char *name){
	Button t;
	t.x=x,t.y=y,t.name=name;
	t.color=color;
	t.len=strlen(name);
	return t;
}
bool Preserve(Button A){
	gto(A.x,A.y),color(A.color),printf("%s",A.name);
	POINT pt;
	GetPos(pt);
	if(pt.y==A.x&&(pt.x>=A.y&&pt.x<=A.y+A.len/2)){
		color(A.color);
		gto(A.x,A.y),printf("%s",A.name);
		if(KEY_DOWN(MOUSE_MOVED)) return 1;
	}
	return 0;
}
int kcb(int n); 
POINT Windowpos1()
{
	POINT pt;
	GetCursorPos(&pt);
	HWND h=GetForegroundWindow();
	ScreenToClient(h,&pt);
	pt.x/=8;pt.y/=16;
	return pt; 
}
void Go(int x,int y)
{
	COORD coord;
	coord.X=y;
	coord.Y=x;
	HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(a,coord); 
}
struct node{
	long long many,score;
	bool life;
}player;
int timer()
{
	SYSTEMTIME sys;
	GetLocalTime( &sys );
	printf( "%4d年%02d月%02d日 %02d:%02d:%02d\n",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond);
	sys.wHour%=12;
	if(sys.wHour==12)
		printf(
			"┏┳┳┳┓\n"
			"┣  ┃  ┫\n"
			"┣  ╋  ┫\n"
			"┣      ┫\n"
			"┗┻┻┻┛");
	if(sys.wHour==1)
		printf(
			"┏┳┳┳┓\n"
			"┣    ┃┫\n"
			"┣  ╋  ┫\n"
			"┣      ┫\n"
			"┗┻┻┻┛");
	if(sys.wHour==2)
		printf(
			"┏┳┳┳┓\n"
			"┣    ━┫\n"
			"┣  ╋  ┫\n"
			"┣      ┫\n"
			"┗┻┻┻┛");
	if(sys.wHour==3)
		printf(
			"┏┳┳┳┓\n"
			"┣      ┫\n"
			"┣  ╋━┫\n"
			"┣      ┫\n"
			"┗┻┻┻┛");
	if(sys.wHour==4)
		printf(
			"┏┳┳┳┓\n"
			"┣      ┫\n"
			"┣  ╋  ┫\n"
			"┣    ━┫\n"
			"┗┻┻┻┛");
	if(sys.wHour==5)
		printf(
			"┏┳┳┳┓\n"
			"┣      ┫\n"
			"┣  ╋  ┫\n"
			"┣    ┃┫\n"
			"┗┻┻┻┛");
	if(sys.wHour==6)
		printf(
			"┏┳┳┳┓\n"
			"┣      ┫\n"
			"┣  ╋  ┫\n"
			"┣  ┃  ┫\n"
			"┗┻┻┻┛");
	if(sys.wHour==7)
		printf(
			"┏┳┳┳┳┳┓\n"
			"┣     ┫\n"
			"┣  ╋  ┫\n"
			"┣┃    ┫\n"
			"┗┻┻┳┳┻┛");
	if(sys.wHour==8)
		printf(
			"┏┳┳┳┓\n"
			"┣      ┫\n"
			"┣  ╋  ┫\n"
			"┣━    ┫\n"
			"┗┻┻┻┛");
	if(sys.wHour==9)
		printf(
			"┏┳┳┳┓\n"
			"┣      ┫\n"
			"┣━╋  ┫\n"
			"┣      ┫\n"
			"┗┻┻┻┛");
	if(sys.wHour==10)
		printf(
			"┏┳┳┳┓\n"
			"┣━    ┫\n"
			"┣  ╋  ┫\n"
			"┣      ┫\n"
			"┗┻┻┻┛");
	if(sys.wHour==11)
		printf(
			"┏┳┳┳┓\n"
			"┣┃    ┫\n"
			"┣  ╋  ┫\n"
			"┣      ┫\n"
			"┗┻┻┻┛\n");
	cout<<"\n       ";color(1);
	for(int i=1;i<=30;i++)
	{
		if(i%7==0)
			cout<<'\n';
		if(i==sys.wDay)
			color(10);
		
		cout<<i<<' ';
		color(1);
	}
	
}
int blue();
//{
//	timer();
////	char t[10],cmd[2000]="start https://www.bing.com/search?q=";
////	cin>>t;
////	system(strcat(cmd,t));
//	return 0;
//}
void power()
{
	int f1[13]={13,14,15,14,13,12,11,12,13,14,15,16,15};
	int f2[13]={13,14,15,16,17,16,15,14,13,14,15,16,17};
	for(int j=1;j<=10;j++)
		for(int i=0;i<=13;i++)
	{
		Go(13,15);
		cout<<"正在开机"; 
		Go(f1[i],f2[i]);
		color(10);
		cout<<"·";
		system("cls");
		color(7);
	}
	
}

int last6()
{
	last_6=true;
	bool std=true;
	while(std)
	{
		power();
		color(7);
		main2();
		if(!last_6)
		{
			return 0;
		}
	}
	
}
int kcb(int n);
int first();
int windows()
{
	window_s=true;int mo;
	POINT pt=Windowpos1();
	if(!window_s)return 0;
	
	if(last_6)
	{
		Go(160,20);
		color(14);
		Go(161,36);
		printf("┏━━━━┓");
		Go(162,37);
		printf("┃最新版 6┃");
		Go(163,38);
		printf("┗━━━━┛");
	}
	if(main_1)
	{
		Go(164,21);
		color(14);
		Go(165,46);
		printf("┏━━━━┓");
		Go(166,46);
		printf("┃系统关键┃");
		Go(167,46);
		printf("┗━━━━┛");
	}
	if(kcb_1)
	{
		Go(168,20);
		color(14);
		Go(169,56);
		printf("┏━━━━┓");
		Go(170,56);
		printf("┃网课程表┃");
		Go(171,56);
		printf("┗━━━━┛");
		
	}
	color(10);
	Go(169,56);
	printf("┏━━━━┓");
	Go(170,56);
	printf("┃idark┃");
	Go(171,56);
	printf("┗━━━━┛"); 
	cin>>mo;
	if(mo==0){
		window_s=0; 
	}
	else if(mo==2){
		main_1=0; 
	}
	else if(mo==1){
		last_6=0; 
	}
	else if(mo==3){
		kcb_1=0; 
	}
	else if(mo==4){
		idark_1=0;
	}
	else
	{
		first();
	}
	if(!window_s)
		return 0;
}
int first()
{
	POINT pt=Windowpos1();
	Go(20,20);
	color(14),cout<<"1   ->";
	Go(21,36);
	printf("┏---------┓");
	Go(22,36);
	printf("┃最新版 6┃");
	Go(23,36);
	printf("┗---------┛");
	Go(24,20);
	color(14),cout<<"2   ->";
	Go(25,36);
	printf("┏---------┓");
	Go(26,36);
	printf("┃窗口管理┃");
	Go(27,36);
	printf("┗---------┛");
	Go(28,20);
	color(14),cout<<"3   ->";
	Go(29,36);
	printf("┏---------┓");
	Go(30,36);
	printf("┃网课程表┃");
	Go(31,36);
	printf("┗---------┛");
	color(14),cout<<"4   ->";
	Go(32,36);
	printf("┏---------┓");
	Go(33,36);
	printf("┃idarkone┃");
	Go(34,36);
	printf("┗---------┛");
	
	
	
	int mo;
	cin>>mo;
	if(mo==1)
		last6();
	else if(mo==2)
		windows();
	else if(mo==3)
		kcb(1);
	else if(mo==4)
		idark();
}
void coun_fighter();
void idark()
{		
	system("cls");
	Go(20,20);
	cout<<"开机中"; 
	for(int jm=1;jm<=100;jm++)
		Go(22,jm),cout<<"<",Sleep(200);
	for(int im=1;im<=100000;im++)
	{
		
		Go(15,15);
		cout<<"点击以安装驱动"; 
		POINT pt = {0,0};
		GetCursorPos(&pt);
		Go(pt.y/14,pt.x/14);
		cout<<"↖";
		system("cls");
		if(KEY_DOWN(VK_LBUTTON) && pt.y/14==15 && pt.x/14)
			break; 
	}
	Go(20,20);
	cout<<"安装驱动中"; 
	for(int jm=1;jm<=20;jm++)
		Go(22,jm),cout<<"<",Sleep(100);
	for(int im=1;im<=100000;im++)
	{
		POINT pt = {0,0};
		GetCursorPos(&pt);
		Go(pt.y/14,pt.x/14);
		cout<<"↖";
		system("cls");
		if(KEY_DOWN(VK_LBUTTON) && pt.y/14<=15 && pt.x/14<=15)
			break; 
		Go(10,10);
		cout<<"countries";
		Go(12,12);
		cout<<"fight";
	}
	coun_fighter();
	//blue(2);
	
	first();
}
int kcb(int n)
{
	kcb_1=true;
	int fm[10]={30,10,0,10,10,0,50};
	int fh[10]={7,8,9,10,11,14,14};
	int ys;
	SYSTEMTIME sys;
	GetLocalTime( &sys );
	cout<<"1.课程表 2.窗口 3.n 4.教师端\n";
	cin>>ys;
	if(ys==1)
	{
		while(n<=6)
		{
			SYSTEMTIME sys;
			GetLocalTime( &sys );
			if(!kcb_1)
				return 0;
			if(sys.wHour==fh[n] && sys.wMinute==fm[n])
			{
				MessageBox(NULL,TEXT("上课了"),TEXT("到时"),MB_ICONEXCLAMATION);
				n++;
				kcb(n);
			}
			
		}
	}
	else if(ys==3)
	{
		cin>>n;
		while(n<=6)
		{
			system("cls");
			SYSTEMTIME sys;
			GetLocalTime( &sys );
			if(!kcb_1)
				return 0;
			if(sys.wHour>=fh[n] && sys.wMinute>=fm[n])
			{
				MessageBox(NULL,TEXT("上课了"),TEXT("到时"),MB_ICONEXCLAMATION);
				n++;
				kcb(n);
			}
			
		}
	}
	else if(ys==2)
		windows();
	else if(ys==4)
	{
		int xsn;
		cout<<"____个科目\r\b\r";
		cin>>ys;
		cout<<"____个学生\r\b\r";
		cin>>xsn;
		struct node_1{
			string name;
			int bj,xh,cj[50];
		}xs[1001];
		cout<<"姓名   班级   学号   成绩\n";
		for(int i=1;i<=xsn;i++)
		{
			cin>>xs[i].name>>xs[i].bj>>xs[i].xh;
			for(int j=1;j<=ys;j++)
			{
				cin>>xs[i].cj[j];
			}
		}
		cout<<"\n\n 1.导出 2.排序\n";
		cin>>ys;
		if(ys==1)
		{
			freopen("成绩.csv","w",stdout);
			cout<<"姓名,班级,学号,成绩\n";
			for(int i=1;i<=xsn;i++)
			{
				cout<<xs[i].name<<','<<xs[i].bj<<','<<xs[i].xh;
				for(int j=1;j<=ys;j++)
				{
					cout<<','<<xs[i].cj[j];
				}
				cout<<endl;
			}
			exit(0);
		}
		else
		{
			//			sort(xs,xs+1000);
		}
	}
	if(!kcb_1)
		return 0;
	
}
int sightp()
{
	sight_p=true;
	int f1[20]={13,13,14,15,16,17,18,19,19,16,16,16,15,17,16,16,16,15,17};
	int f2[20]={14,13,12,11,11,11,12,13,14,15,16,17,16,16,19,20,21,20,20};
	Button A=NewButton(10,10,303,"开机");
	while(1){
		if(Preserve(A))
		{
			if(!sight_p)
			{
				return 0;
			}
			for(int i=1;i<=19;i++)
			{
				Go(f1[i],f2[i]);
				color(i*100);
				cout<<" ";
				Sleep(500);
			}
			Go(30,1);
			color(7);
			timer();
			return 0;
		}
		else
			color(10);
	}
}
int blue(int n)
{
	system("cls");
	system("color 19");
	cout<<"A problem has been detected and last_7 has been shut down to prevent damage to your comprter.\nDRIVER-IRQL-NOT-Less-or-equal \n";
	cout<<"If this is the first time you're seen this stop error screen,restart your computer. \n";
	cout<<"If this screen appears again,follow these steps: Check to make sure any mew hardware or software is properly installed. \n";
	cout<<"If this is a new installation,ask your hard ware or software manuacturer for any windows updates you might need. \n";
	cout<<"If problems continue,disable or remove any newly installed hard ware or software. \nDisable BIOS memory options such as caching or shadowing.\n";
	cout<<"If you need to use safte Mode to remore or disable components,restart your computer,press Ctrl+C to select Advacnced Startup Options,and then select safe Mode. \n";
	cout<<"Technical information: ***stop:";
	cout<<"0x0000000"<<n;
	cout<<"\nretime:            ";
	
	for(int iti=99;iti>=1;iti--)
		cout<<"\b\b"<<iti,Sleep(1000);
	freopen("data.log","a",stdout);
	SYSTEMTIME sys;
	GetLocalTime( &sys );
	printf( "%4d年%02d月%02d日 %02d:%02d:%02d\n",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond);
	cout<<n<<endl;
	exit(0);
}
int main0()
{
	main_1=true;
	sightp();
	sight_p=0;
	color(7);
	first();
	windows();
	
	if(!main_1)
	{
		blue(0);
		return 0;
	}
	main0();
}
int main()
{
	
	//main0();
	coun_fighter();
}



















////////////////////////////////////////////////////



mouse_msg coun_mouse;





bool coun_disif=1;
int money;
long long sumt,coun_ntime;
void coun_time(int n)
{
	if (n == 0)
		coun_ntime = 0;
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	coun_ntime += sys.wDay * 3600 * 24 + sys.wHour * 3600 + sys.wMinute * 60 + sys.wSecond - sumt;
	sumt=sys.wDay*3600*24+sys.wHour*3600+sys.wMinute*60+sys.wSecond;
	
	Sleep(2000);
	coun_time(1);
}



struct coun{
	string name[10];
	int x, y;
	enum color = GREEN, bcolor = BLACK;
}dis[1405][805];
struct coun_w{
	string name;
	int x,y,z;
	int blood,f,money,per,oil;//f=truct
}T90;

void coun_display()
{
	if(coun_disif)
	{
		system("cls");
		for(int i=1;i<=100;i++)
			for(int j=1;j<=50;j++)
		{
			//Go(i,j*2);
			setcolor(dis[i][j].color);
			//printf("%s",dis[i][j].name[1].c_str());
			//color(dis[i][j].color);
			//printf("%s",dis[i][j].name[1].c_str());
			outtextxy( i, j,dis[i][j].name[1].c_str());
			setcolor(YELLOW);
			outtextxy(coun_mouse.x, coun_mouse.y,'+');
		}
		
		Sleep(90);
		coun_display();
	}
	
}


void coun_fighter()
{
	initgraph(640, 480, 0);
	thread th2(coun_time,0);
	thread th3(coun_display);
	for(int i=1;!KEY_DOWN(20);delay_fps(60))
	{
//		system("cls");
		//for(int i=1;i<=1400;i++)
		//	for(int j=1;j<=800;j++)
		//{
			//Go(i,j*2);
			
		//}
		//POINT pt = {0,0};
		//GetCursorPos(&pt);
		//Go(pt.y/10,pt.x/5);
		//color(6); 
		//printf("%s","+");
		
		Sleep(90);
		if(KEY_DOWN(VK_LBUTTON) || KEY_DOWN(8))
		{
			dis[pt.y/10][pt.x/10].name[1]="坦";
			dis[pt.y/10][pt.x/10].color=3;
			money=money-100;
		}
		//		color(2);Go(120, 90);
		//		printf("已经用时 %d",coun_ntime);
		
	}
	coun_disif=0;
} 
