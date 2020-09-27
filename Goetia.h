#ifndef GOETIA_H
#define GOETIA_H


extern "C" {
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
}
#include <algorithm>
#include <chrono>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>
#include <queue>
#include <random>
#include <regex>
#include <utility>
#include <vector>
#ifndef _MANAGED
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <thread>
#endif

#ifdef __APPLE__
#include <TargetConditionals.h>
#if TARGET_OS_MAC
#define MAC_OS
#include <dirent.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cmath>
#endif
#elif _WIN64
#define WIN_OS
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS 1
#include <direct.h>
#include <io.h>
#include <math.h>
#include <sys/timeb.h>
#include <windows.h>
#define execv _execv
#define popen _popen
#define pclose _pclose
#define chdir _chdir
#define mkdir _mkdir
#define rmdir _rmdir
#define S_ISDIR(X) ((X&0170000)==0040000)
#define S_IRWXU 0x0700
#define S_IRWXG 0x0070
#define S_IRWXO 0x0007
#pragma warning(disable:4996)
#elif _WIN32
#define WIN_OS
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS 1
#include <direct.h>
#include <io.h>
#include <math.h>
#include <sys/timeb.h>
#include <windows.h>
#define execv _execv
#define popen _popen
#define pclose _pclose
#define chdir _chdir
#define mkdir _mkdir
#define rmdir _rmdir
#define S_ISDIR(X) ((X&0170000)==0040000)
#define S_IRWXU 0x0700
#define S_IRWXG 0x0070
#define S_IRWXO 0x0007
#pragma warning(disable:4996)
#elif __linux__
#define OS_TYPE LINUX_OS
#define LINUX_OS
#include <dirent.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cmath>
#elif __unix__
#define UNIX_OS
#include <dirent.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cmath>
#endif

extern std::vector<std::string> LIB_JPEG_C = {
	"jcapimin","jcapistd","jccoefct","jccolor","jcdctmgr","jchuff","jcinit",
	"jcmainct","jcmarker","jcmaster","jcomapi","jcparam","jcphuff","jcprepct",
	"jcsample","jctrans","jdapimin","jdapistd","jdatadst","jdatasrc","jdcoefct",
	"jdcolor","jddctmgr","jdhuff","jdinput","jdmainct","jdmarker","jdmaster",
	"jdmerge","jdphuff","jdpostct","jdsample","jdtrans","jerror","jfdctflt",
	"jfdctfst","jfdctint","jidctflt","jidctfst","jidctint","jidctred","jmemmgr",
	"jmemnobs","jquant1","jquant2","jutils"
};
extern std::vector<std::string> LIB_PNG_C = {
	"png","pngerror","pngget","pngmem","pngpread","pngread","pngrio","pngrtran",
	"pngrutil","pngset","pngtrans","pngwio","pngwrite","pngwtran","pngwutil"
};
extern std::vector<std::string> LIB_TIFF_C = {
	"tif_aux", "tif_close", "tif_codec", "tif_color", "tif_compress", "tif_dir",
	"tif_dirinfo", "tif_dirread", "tif_dirwrite", "tif_dumpmode", "tif_error",
	"tif_extension", "tif_fax3", "tif_fax3sm", "tif_flush", "tif_getimage",
	"tif_jbig", "tif_jpeg", "tif_jpeg_12", "tif_luv", "tif_lzw", "tif_next",
	"tif_ojpeg", "tif_open", "tif_packbits", "tif_pixarlog", "tif_predict",
	"tif_print", "tif_read", "tif_strip", "tif_swab", "tif_thunder", "tif_tile",
	"tif_version", "tif_warning", "tif_write", "tif_zip"
};
extern std::vector<std::string> LIB_SQLITE_C = {
	"sqlite3"
};
extern std::vector<std::string> LIB_Z_C = {
	"adler32","compress","crc32","deflate","gzclose","gzlib","gzread",
	"gzwrite","infback","inffast","inflate","inftrees","trees","uncompr", "zutil"
};
extern std::vector<std::string> LIB_CURL_C = {
	
};
extern std::vector<std::string> CRYPTO_C = {
	"md5"
};
extern std::vector<std::string> SLIB_BASIC_CPP = {
	"char","exception","string","sutf8","time"
};
extern std::vector<std::string> SLIB_SOBJ_CPP = {
	"sarray","scolumn","sdata","sdate","sdictionary",
	"siter","snumber","sobject","sstring","stable", "stext", "svoid"
};
extern std::vector<std::string> SLIB_SIO_CPP = {
	"sfile","sio"
};
extern std::vector<std::string> SLIB_SUTIL_CPP = {
	"schrono","scode","sdb","sjson","ssys","sthread",
	"sxmldoc","sxmlnode"
};
extern std::vector<std::string> SLIB_SNET_CPP = {
	"snet"
};
extern std::vector<std::string> SLIB_SMEDIA_CPP = {
	"scanvas","scolor","sfigure","sgraphic","simage",
	"sline2d","smedia","smedio","smovie","spaint","spixel",
	"spolygon","srect"
};
extern std::vector<std::string> SLIB_SAPP_CPP = {
	"sapp", "scuiapp"
};
extern std::vector<std::string> SLIB_SNODEAPP_CPP = {
	"sapp", "snodeapp"
};

extern std::vector<std::string> SLIB_SBI_CPP = {
	"sbalign","sbam","sbannot","sbextend",
	"sbioinfoutil","sbioseq","sbioseqlist","sbquery",
	"sbsearch","sbseqio","sbsequtil","scigar",
	"sfastq","sgff","sngsdata","svarfilter",
	"svariant","svarlist","svarutil"
};

#ifdef WIN_OS
extern std::string INCLUDE_PATH = "C:\\ProgramData\\slib\\include";
extern std::string STATIC_LIB_PATH = " C:\\ProgramData\\slib\\lib\\static";
extern std::string DYNAMIC_LIB_PATH = " C:\\ProgramData\\slib\\lib\\dynamic";




#else
extern std::string INCLUDE_PATH = " -I../include";
extern std::string LIB_PATH = "/usr/local/lib";
extern std::string SOBJ_LIB_PATH = " -L/usr/local/lib -lsobj";

extern std::string CPP_VERSION = " -std=c++11";
extern std::string LD_PATH = " -ld";
extern std::string PTHREAD_LIB_PATH = " -lpthread";
extern std::string CURL_LIB_PATH = " -lcurl";
extern std::string SHARED_FLAG = " -fPIC";

extern std::string LIB_CRYPTO = "../src/3rd/crypto/";
extern std::string LIB_CURL = "../src/3rd/curl/";
extern std::string LIB_JPEG = "../src/3rd/libjpeg/";
extern std::string LIB_PNG = "../src/3rd/libpng/";
extern std::string LIB_TIFF = "../src/3rd/libtiff/";
extern std::string LIB_SQLITE = "../src/3rd/sqlite/";
extern std::string LIB_Z = "../src/3rd/zlib/";
extern std::string CRYPTO = "../src/3rd/crypto/";

extern std::string UNIQUE_LIBTIFF_C = "tif_unix";

extern std::string SLIB_BASIC = "../src/sbasic/";
extern std::string SLIB_SOBJ = "../src/sobj/";
extern std::string SLIB_SIO = "../src/sio/";
extern std::string SLIB_SUTIL = "../src/sutil/";
extern std::string SLIB_SNET = "../src/snet/";
extern std::string SLIB_SMEDIA = "../src/smedia/";
extern std::string SLIB_SBIOINFO = "../src/sbioinfo/";
extern std::string SLIB_SAPP = "../src/sapp/";



#endif
#endif