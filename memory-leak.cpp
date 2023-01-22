#include <windows.h>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void kill() {
    int i;
    char* p;
    for (i = 0; i < 10000000; i++) { // 100 ぐらいじゃないと PC落ちる
        p = (char*)malloc(sizeof(char) * 100000000);
    }
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    int i;
	thread thr1;
    vector<thread> threads;
    for (i = 0; i < 100000000000; i++) {
        threads.push_back(thread(kill));
    }
    for (thread& th : threads) {
        th.join();
    }
};