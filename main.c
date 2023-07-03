#include "utils.h"
#include "aes.h"
#include <stdio.h>

int main() {
    // case 1
    const uint8_t key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    const uint8_t pt[16]={0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34};
    uint8_t ct[16] = {0};     // 外部申请输出数据内存，用于加密后的数据
    uint8_t plain[16] = {0};  // 外部申请输出数据内存，用于解密后的数据

    aesEncrypt(key, 16, pt, ct, 16); // 加密
    printHex(pt, 16, "plain data:"); // 打印初始明文数据
    //printf("expect cipher:\n39 25 84 1D 02 DC 09 FB DC 11 85 97 19 6A 0B 32\n");  // 正常加密后的数据内容

    printHex(ct, 16, "after encryption:");  // 打印加密后的密文

    aesDecrypt(key, 16, ct, plain, 16);       // 解密
    printHex(plain, 16, "after decryption:"); // 打印解密后的明文数据

    return 0;
}

