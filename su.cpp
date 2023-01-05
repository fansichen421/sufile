#include <graphics.h>
#include <bits/stdc++.h>
#include <ege.h>
using namespace std;

int main() {
	initgraph(640, 480, 0);
	MUSIC music;
	music.OpenFile("su1990.mp3");
	music.Play();
	DWORD playStatus = music.GetPlayStatus();
	if(playStatus == MUSIC_MODE_NOT_OPEN){
		cout<<1;
	}
	if(playStatus == MUSIC_MODE_NOT_READY){
		cout<<2;
	}
	getch();
	music.Close();
	closegraph();
	return 0;
}

