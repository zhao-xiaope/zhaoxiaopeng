#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int GetIne(int x, int p)
{
    for (int i = 0; i<p; i++)
    {
        if (x*i%p == 1)
        {
            x = i;
            break;
        }
    }
    return x;
}
int main()
{
    /*
    (1)    仿射密码
    参数选取：模数n=26+10=36，k2为学号后2位；k1为与学号后2位最近的素数。
    加解密：加密自己名字的全拼和学号，再解密。
    */
    int n = 36;
    string m, c;
    int buff[32], len = 0, k1 = 0, k2 = 0,k = 0;
    cout << "输入明文：" << endl;
    cin >> m;
    cout << "输入k1:";
    cin >> k1;
    cout << "输入k2:";
    cin >> k2;
    //把明文转化成10进制整数,0-9,a-z分别代表十进制0-36
    for (int i = 0; m[i] != '\0'; i++)
    {
        //字母转10进制整数
        if (m[i] > '9')
            buff[i] = m[i] - 87;
        else
            buff[i] = m[i] - 48;//0ASCII为48
        len++;
    }
    //加密运算,C=k1*m+k2 mod n;
    for (int i = 0; i < len; i++)
    {
        buff[i] = (buff[i] * k1 + k2) % n;
    }
    //把数字对应为密文空间内的字符
    for (int i = 0; i < len; i++)
    {
        if (buff[i] < 10)
            m[i] = buff[i] + 48;
        else
            m[i] = buff[i] + 87;

    }
    cout << "密文为：" << endl;
    for (int i = 0; i<len; i++)
    {
        cout << m[i];
    }
    cout << endl;
    //解密,M=(C-k2)*k1^(-1)
    for (int i = 0; m[i] != '\0'; i++)
    {
        //字母转10进制整数
        if (m[i] > '9')
            buff[i] = m[i] - 87;
        else
            buff[i] = m[i] - 48;//0ASCII为48
        len++;
    }
    //解密运算,M=(C-k2)*k1^(-1)
    k = GetIne(k1, n);
    for (int i = 0; i < len; i++)
    {
        buff[i] = ((buff[i] - k2)*k) % n;
        if (buff[i] < 0)
            buff[i] += n;
        //buff[i] = (buff[i] * k1 + k2) % n;
    }
    //把数字对应为明文空间内的字符
    for (int i = 0; i < len; i++)
    {
        if (buff[i] < 10)
            m[i] = buff[i] + 48;
        else
            m[i] = buff[i] + 87;

    }
    cout << "明文为：" << endl;
    for (int i = 0; i<len; i++)
    {
        cout << m[i];
    }
    cout << endl;
    system("pause");
    return 0;
}
