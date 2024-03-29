#ifndef KEYEXTEND_H
#define KEYEXTEND_H

#include<bitset>
using namespace std;

typedef bitset<8> byte;
typedef bitset<32> word;

extern byte S[256]; //S-盒
extern byte inv_S[256];
extern word rcon[10]; //轮系数Rcon，用来和S盒的计算结果做异或与
extern byte encry_s[4 * 4];
extern byte decry_s[4 * 4];

//定义种子密钥长度以及扩展轮数
const int Nr = 10;//轮数 
const int Nk = 4; //种子密钥有四个字 

//密钥扩展 相关函数
// 1 四个字节转换成一个字 
word Word(byte b0, byte b1, byte b2, byte b3);
// 2 字移位 
word CycWord(word rw);
// 3 S盒替换 
word SubWord(word sw);
// 4 密钥扩展 
void KeyExpansion(byte key[4 * Nk], word w[4 * (Nr + 1)]);
// 加密使用的列混合数组


#endif