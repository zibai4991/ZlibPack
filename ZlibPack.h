/**
 * @brief   zlib压缩 解压封装
 * @author  zibai
 * @date    Created in 上午11:48 2021/9/6  
 * @revise  Revised in 上午11:48 2021/9/6
 * @version v1.0.0
 **/

#ifndef ZLIBPACK_ZLIBPACK_H
#define ZLIBPACK_ZLIBPACK_H

#include <zconf.h>

#define MAX_ZLIB_SIZE 1024*1024   //1MB

/**
 * @description  zlib压缩解压类
 * @author  zibai
 * @date    Created in 上午11:48 2021/9/6
 **/
class ZlibPack {

public:
    /**
     * @brief 构造函数
     */
    ZlibPack();

    /**
     * @brief 析构函数
     */
    ~ZlibPack();

    /**
     * @brief 压缩
     *
     * @param pbuf：压缩前字节
     * @param cbuf：压缩后字节
     * @param len ：压缩后长度
     * @return 返回压缩状态
     *   @retval true : 压缩成功
     *   @retval false: 压缩失败
     */
    bool Compress(const char *pbuf, char *cbuf, unsigned long &len);

    /**
     * @brief 压缩字符串
     *
     * @param sprev ：压缩前字符串
     * @param snext ：压缩后字符串
     * @return 返回压缩状态
     *   @retval true : 压缩成功
     *   @retval false: 压缩失败
     */
    bool Compress(std::string &sprev, std::string &snext);

    /**
     * @brief 解压
     *
     * @param pbuf：解压前字节
     * @param ubuf：解压后字节
     * @param len ：解压后长度
     * @return 返回解压状态
     *   @retval true : 解压成功
     *   @retval false: 解压失败
     */
    bool DeCompress(const char *pbuf, char *ubuf, unsigned long &len);

    /**
     * @brief 解压字符串
     *
     * @param sprev ：解压前字符串
     * @param snext ：解压后字符串
     * @return 返回解压状态
     *   @retval true : 解压成功
     *   @retval false: 解压失败
     */
    bool DeCompress(std::string &sprev, std::string &snext);

    /**
     * @brief  字节流转十六进制字符串
     *
     * @param buf ：字节指针
     * @param len ：字节长度
     * @return 返回转换后的字符串
     */
    std::string BufToHexString(char *buf, unsigned int len);

    /**
     * @brief  十六进制字符串转字节流
     *
     * @param str ：十六进制字符串
     * @return  返回字节流
     */
    char* HexStringtoBuf(std::string& str);

private:
    /**
     * @brief  十六进制字节转整数
     *
     * @param ch：十六进制字节
     * @return  返回数值
     */
    int HexCharToInt(char ch);
};


#endif //ZLIBPACK_ZLIBPACK_H
