/**
 * @brief   zlib 压缩 解压类实现
 * @author  zibai
 * @date    Created in 上午11:48 2021/9/6  
 * @revise  Revised in 上午11:48 2021/9/6
 * @version v1.0.0
 **/

#include <cstring>
#include <string>
#include <zlib.h>
#include "ZlibPack.h"

ZlibPack::ZlibPack() {

}

ZlibPack::~ZlibPack() {

}

bool ZlibPack::Compress(const char *pbuf, char *cbuf, unsigned long &len) {
    if (pbuf == NULL || cbuf == NULL) {
        return false;
    }
    unsigned long plen = strlen(pbuf);                //源长度
    if (plen == 0) {
        return false;
    }
    len = compressBound(plen);                       //压缩缓存长度
    //char* buf = nullptr;                                  //创建缓冲区
    //buf = (char *) malloc(sizeof(char) * len);  //申请空间
    //if(buf ==nullptr) {
    //  return false;
    //}
    int iRet = compress((Bytef *) cbuf, &len, (const Bytef *) pbuf, plen);  //压缩
    if (iRet != Z_OK) {
        return false;
    }
    //memcpy(cbuf, buf, strlen(buf));
    return true;
}

bool ZlibPack::Compress(std::string &sprev, std::string &snext) {
    unsigned long plen = sprev.length() + 1;
    unsigned long clen = compressBound(plen);     //压缩缓存长度
    char *cbuf = nullptr;                         //创建缓冲区
    cbuf = (char *) malloc(sizeof(char) * clen);  //申请空间
    if (cbuf == nullptr) {
        return false;
    }
    int iRet = compress((Bytef *) cbuf, &clen, (const Bytef *) sprev.c_str(), plen);  //压缩
    if (iRet != Z_OK) {
        return false;
    }
    snext = std::string(cbuf);
    return true;
}

bool ZlibPack::DeCompress(const char *pbuf, char *ubuf, unsigned long &len) {
    if (pbuf == NULL) {
        return false;
    }
    unsigned long slen = strlen(pbuf);
    if (slen == 0) {
        return false;
    }

    //ubuf=nullptr;                                    //解压缓冲区
    len = 1024 * 1024;                                 //缓冲区大小
    //ubuf=(char *) malloc(sizeof(char) * len);       //申请空间
    int iRet = uncompress((Bytef *) ubuf, &len, (const Bytef *) pbuf, len);
    if (iRet != Z_OK) {
        return false;
    }
    return true;
}

bool ZlibPack::DeCompress(std::string &sprev, std::string &snext) {
    char *ubuf = nullptr;                              //解压缓冲区
    unsigned long ulen = 1024 * 1024;                  //缓冲区大小
    ubuf = (char *) malloc(sizeof(char) * ulen);  //申请空间
    int iRet = uncompress((Bytef *) ubuf, &ulen, (const Bytef *) sprev.c_str(), ulen);
    if (iRet != Z_OK) {
        return false;
    }
    snext = std::string(ubuf);
    return true;
}