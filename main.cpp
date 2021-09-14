#include <iostream>
#include "ZlibPack.h"

void TestZlib(const char *src);

void Dump(char *buf, int len);

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::string str = "zlib is designed to be a free, general-purpose, legally unencumbered -- that is, not covered by any patents -- lossless data-compression library for use on virtually any computer hardware and operating system. The zlib data format is itself portable across platforms. Unlike the LZW compression method used in Unix compress(1) and in the GIF image format, the compression method currently used in zlib essentially never expands the data. (LZW can double or triple the file size in extreme cases.) zlib's memory footprint is also independent of the input data and can be reduced, if necessary, at some cost in compression. A more precise, technical discussion of both points is available on another page.";
    TestZlib(str.c_str());
    str = "非阻塞模型会让用户进程一直轮询调用系统函数，频繁地做内核态切换。想要做优化其实也比较简单，我们假想个业务场景，A业务系统会调用B的基础服务查询单个用户的信息。随着业务的发展，A的逻辑变复杂了，需要查100个用户的信息。很明显，A希望B提供一个批量查询的接口，用集合作为入参，一次性把数据传递过去就省去了频繁的系统间调用。";
    TestZlib(str.c_str());
//    unsigned long strl = str.length() + 1;
//    std::cout << strl << std::endl;
//    std::cout << str << std::endl;
//    char *cbuf = NULL;
//    unsigned long clen = 0;
//    clen = compressBound(strl);
//    cbuf = (char *) malloc(sizeof(char) * clen);
//    int iRet= compress(reinterpret_cast<Bytef *>(cbuf), &clen, reinterpret_cast<const Bytef *>(str.c_str()), strl);
//    int x = strlen(cbuf);
//
//    char* ubuf=NULL;
//    unsigned long ulen = 1024*1024;
//    ubuf = (char *) malloc(sizeof(char) *ulen);
//    iRet=uncompress((Bytef*)ubuf, &ulen, reinterpret_cast<const Bytef *>(cbuf), 64*1024);
//    int y = strlen(ubuf);
//    std::string ustr(ubuf);
//    std::cout << ustr << std::endl;
    return 0;
}

void TestZlib(const char *src) {
    ZlibPack zlibPack;
    std::string sprev = src;
    std::cout << sprev << std::endl;
    std::string snext;
    bool bRet = zlibPack.Compress(sprev, snext);
    std::cout << snext.length() << " " << snext << std::endl;
    std::string dprev = snext;
    std::string dnext;
    bRet = zlibPack.DeCompress(dprev, dnext);
    std::cout << sprev << std::endl;

    const char *buf = src;
    printf("%s\n", buf);
    char *cbuf = nullptr;
    cbuf = (char *) malloc(sizeof(char) * MAX_ZLIB_SIZE);
    unsigned long clen;
    unsigned long ulen;
    bRet = zlibPack.Compress(buf, cbuf, clen);
    printf("%s\n", cbuf);

    std::string shex = zlibPack.BufToHexString(cbuf, clen);
    Dump(cbuf,clen);
    printf("%s\n",shex.c_str());
    char* hbuf=zlibPack.HexStringtoBuf(shex);
    char *uhbuf = nullptr;
    uhbuf = (char *) malloc(sizeof(char) * MAX_ZLIB_SIZE);
    bRet = zlibPack.DeCompress(hbuf, uhbuf, ulen);
    printf("%s\n", uhbuf);

    char *ubuf = nullptr;
    ubuf = (char *) malloc(sizeof(char) * MAX_ZLIB_SIZE);
    bRet = zlibPack.DeCompress(cbuf, ubuf, ulen);
    printf("%s\n", ubuf);
}

void Dump(char *buf, int len) {
    for (int i = 0; i < len; ++i) {
        if (i % 8 == 0) printf("  ");
        if (i % 32 == 0) printf("\n");
        printf("%02x", (unsigned char) buf[i]);
    }
    printf("\n");
}
