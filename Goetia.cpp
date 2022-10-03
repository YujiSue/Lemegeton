#include "Goetia.h"

int main(int argc, const char** argv) {
	bool shared = false;
	bool lsobj = false;
	bool lsapp = false;
	bool lsnapp = false;
	//bool lsphys = false;
	//bool lsbio = false;
	//bool lschem = false;
	//bool lsbrain = false;
	bool lsscience = false;
	bool lsbioinfo = false;
	int res = 0;
	std::string op, cmd;
	std::vector<std::string> args;
	++argv;
	for (auto i = 1; i < argc; ++i) {
		op = argv[0];
		if (op[0] == '-') {
			if (op[1] == '-') {
				op = op.substr(2);
				if (op == "shared") shared = true;
			}
			else {
				op = op.substr(1);
				const char* c = op.c_str();
				while (*c != '\0') {
					switch (*c)
					{
					case 's':
						shared = true;
						break;
					case 'O':
						lsobj = true;
						break;
					case 'A':
						lsapp = true;
						break;
					case 'N':
						lsnapp = true;
						break;
						/*
					case 'P':
						lsphys = true;
						break;
					case 'B':
						lsbio = true;
						break;
					case 'C':
						lschem = true;
						break;
					case 'E':
						lsbrain = true;
						break;
						*/
					case 'S':
						lsscience = true;
						break;
					case 'I':
						lsbioinfo = true;
						break;
					default:
						break;
					}
					++c;
				}
			}
		}
		else args.push_back(op);
		++argv;
	}

#ifdef MAC_OS
	std::string home = getenv("HOME");
	std::string workspace = home + "/slib";
	res = chdir(home.c_str());
	res = system("mkdir slib");
	res = chdir(workspace.c_str());
	res = system("curl -Lk -o slib.zip https://github.com/YujiSue/slib/archive/master.zip");
	res = system("unzip ./slib.zip");
	workspace += "/slib-master";
	res = chdir(workspace.c_str());
	res = system("mkdir build");
	workspace += "/build";
	res = chdir(workspace.c_str());
#elif defined(WIN_OS)
	std::string home = getenv("USERPROFILE") + std::string("\\AppData\\Local");
	std::string workspace = home + "\\slib\\slib-master";
	chdir(home.c_str());
	system((std::string("bitsadmin /transfer download https://github.com/YujiSue/slib/archive/master.zip ") + home + "\\slib.zip").c_str());
	system((std::string("powershell - command \"Expand-Archive -Force") + home + "\\slib.zip " + home + "\\slib\"").c_str());
	chdir(workspace.c_str());
	mkdir("build");
	workspace += "/build";
	chdir(workspace.c_str());
#else
	std::string home = getenv("HOME");
	std::string workspace = home + "/slib";
	res = chdir(home.c_str());
	res = mkdir("slib", 0777);
	res = chdir(workspace.c_str());
	res = system("wget --output-document ./master.zip https://github.com/YujiSue/slib/archive/master.zip");
	res = system("unzip ./*.zip");
	workspace += "/slib-master";
	res = chdir(workspace.c_str());
	res = mkdir("build", 0777);
	workspace += "/build";
	res = chdir(workspace.c_str());
#endif
#ifdef WIN_OS
	if (lsobj) {



		cl.exe / EHsc / utf - 8 / I"  \slib\include" / c Goetia.cpp
			link "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib""kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" Goetia.obj

			cmd = "gcc" + INCLUDE_PATH + LD_PATH + PTHREAD_LIB_PATH + SHARED_FLAG +
			" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
		sfor(LIB_Z_C) cmd += " " + LIB_Z + $E + ".c";
		sfor(LIB_TIFF_C) cmd += " " + LIB_TIFF + $E + ".c";
		cmd += " " + LIB_TIFF + UNIQUE_LIBTIFF_C + ".c";
		sfor(LIB_PNG_C) cmd += " " + LIB_PNG + $E + ".c";
		sfor(LIB_JPEG_C) cmd += " " + LIB_JPEG + $E + ".c";
		sfor(LIB_SQLITE_C) cmd += " " + LIB_SQLITE + $E + ".c";
		std::cout << cmd << std::endl;
		system(cmd.c_str());
		if (shared) {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH + SHARED_FLAG +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sfor(SLIB_BASIC_CPP) cmd += " " + SLIB_BASIC + $E + ".cpp";
			sfor(SLIB_SOBJ_CPP) cmd += " " + SLIB_SOBJ + $E + ".cpp";
			sfor(SLIB_SIO_CPP) cmd += " " + SLIB_SIO + $E + ".cpp";
			sfor(SLIB_SUTIL_CPP) cmd += " " + SLIB_SUTIL + $E + ".cpp";
			sfor(SLIB_SNET_CPP) cmd += " " + SLIB_SNET + $E + ".cpp";
			sfor(SLIB_SMEDIA_CPP) cmd += " " + SLIB_SMEDIA + $E + ".cpp";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			cmd = "g++" + CPP_VERSION + CURL_LIB_PATH + " -shared -o libsobj.so";
			sfor(LIB_Z_C) cmd += " " + $E + ".o";
			sfor(LIB_TIFF_C) cmd += " " + $E + ".o";
			cmd += " " + UNIQUE_LIBTIFF_C + ".o";
			sfor(LIB_PNG_C) cmd += " " + $E + ".o";
			sfor(LIB_JPEG_C) cmd += " " + $E + ".o";
			sfor(LIB_SQLITE_C) cmd += " " + $E + ".o";
			sfor(SLIB_BASIC_CPP) cmd += " " + $E + ".o";
			sfor(SLIB_SOBJ_CPP) cmd += " " + $E + ".o";
			sfor(SLIB_SIO_CPP) cmd += " " + $E + ".o";
			sfor(SLIB_SUTIL_CPP) cmd += " " + $E + ".o";
			sfor(SLIB_SNET_CPP) cmd += " " + $E + ".o";
			sfor(SLIB_SMEDIA_CPP) cmd += " " + $E + ".o";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			system("rm -r ./*.o");
		}
		else {
			cmd = "gcc -shared -o libshelper.so";
			sfor(LIB_Z_C) cmd += " " + $E + ".o";
			sfor(LIB_TIFF_C) cmd += " " + $E + ".o";
			cmd += " " + UNIQUE_LIBTIFF_C + ".o";
			sfor(LIB_PNG_C) cmd += " " + $E + ".o";
			sfor(LIB_JPEG_C) cmd += " " + $E + ".o";
			sfor(LIB_SQLITE_C) cmd += " " + $E + ".o";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			system("rm -r ./*.o");
			cmd = "g++ " + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sfor(SLIB_BASIC_CPP) cmd += " " + SLIB_BASIC + $E + ".cpp";
			sfor(SLIB_SOBJ_CPP) cmd += " " + SLIB_SOBJ + $E + ".cpp";
			sfor(SLIB_SIO_CPP) cmd += " " + SLIB_SIO + $E + ".cpp";
			sfor(SLIB_SUTIL_CPP) cmd += " " + SLIB_SUTIL + $E + ".cpp";
			sfor(SLIB_SNET_CPP) cmd += " " + SLIB_SNET + $E + ".cpp";
			sfor(SLIB_SMEDIA_CPP) cmd += " " + SLIB_SMEDIA + $E + ".cpp";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			system("ar rcs libsobj.a ./*.o");
			system("rm -r ./*.o");
		}
	}


#elif defined(UNIX_OS) || defined(LINUX_OS)

	if (lsobj) {
		cmd = "gcc" + INCLUDE_PATH + LD_PATH + PTHREAD_LIB_PATH + SHARED_FLAG +
			" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
		sfor(LIB_Z_C) cmd += " " + LIB_Z + $E + ".c";
		sfor(LIB_TIFF_C) cmd += " " + LIB_TIFF + $E + ".c";
		cmd += " " + LIB_TIFF + UNIQUE_LIBTIFF_C + ".c";
		sfor(LIB_PNG_C) cmd += " " + LIB_PNG + $E + ".c";
		sfor(LIB_JPEG_C) cmd += " " + LIB_JPEG + $E + ".c";
		sfor(LIB_SQLITE_C) cmd += " " + LIB_SQLITE + $E + ".c";
		sfor(CRYPTO_C) cmd += " " + CRYPTO + $E + ".c";
		std::cout << cmd << std::endl;
		res = system(cmd.c_str());
		if (shared) {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH + SHARED_FLAG +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sfor(SLIB_BASIC_CPP) cmd += " " + SLIB_BASIC + $E + ".cpp";
			sfor(SLIB_SMATH_CPP) cmd += " " + SLIB_SMATH + $E + ".cpp";
			sfor(SLIB_SOBJ_CPP) cmd += " " + SLIB_SOBJ + $E + ".cpp";
			sfor(SLIB_SIO_CPP) cmd += " " + SLIB_SIO + $E + ".cpp";
			sfor(SLIB_SUTIL_CPP) cmd += " " + SLIB_SUTIL + $E + ".cpp";
			sfor(SLIB_SNET_CPP) cmd += " " + SLIB_SNET + $E + ".cpp";
			sfor(SLIB_SMEDIA_CPP) cmd += " " + SLIB_SMEDIA + $E + ".cpp";
			std::cout << cmd << std::endl;
			res = system(cmd.c_str());
			cmd = "g++" + CPP_VERSION + CURL_LIB_PATH + " -shared -o libsobj.so";
			sfor(LIB_Z_C) cmd += " " + $E + ".o";
			sfor(LIB_TIFF_C) cmd += " " + $E + ".o";
			cmd += " " + UNIQUE_LIBTIFF_C + ".o";
			sfor(LIB_PNG_C) cmd += " " + $E + ".o";
			sfor(LIB_JPEG_C) cmd += " " + $E + ".o";
			sfor(LIB_SQLITE_C) cmd += " " + $E + ".o";
			sfor(CRYPTO_C) cmd += " " + $E + ".o";
			sfor(SLIB_BASIC_CPP) cmd += " " + $E + ".o";
			sfor(SLIB_SMATH_CPP) cmd += " " + $E + ".o";
			sfor(SLIB_SOBJ_CPP) cmd += " " + $E + ".o";
			sfor(SLIB_SIO_CPP) cmd += " " + $E + ".o";
			sfor(SLIB_SUTIL_CPP) cmd += " " + $E + ".o";
			sfor(SLIB_SNET_CPP) cmd += " " + $E + ".o";
			sfor(SLIB_SMEDIA_CPP) cmd += " " + $E + ".o";
			std::cout << cmd << std::endl;
			res = system(cmd.c_str());
			res = system("rm -r ./*.o");
		}
		else {
			cmd = "gcc -shared -o libshelper.so";
			sfor(LIB_Z_C) cmd += " " + $E + ".o";
			sfor(LIB_TIFF_C) cmd += " " + $E + ".o";
			cmd += " " + UNIQUE_LIBTIFF_C + ".o";
			sfor(LIB_PNG_C) cmd += " " + $E + ".o";
			sfor(LIB_JPEG_C) cmd += " " + $E + ".o";
			sfor(LIB_SQLITE_C) cmd += " " + $E + ".o";
			sfor(CRYPTO_C) cmd += " " + $E + ".o";
			std::cout << cmd << std::endl;
			res = system(cmd.c_str());
			res = system("rm -r ./*.o");
			cmd = "g++ " + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sfor(SLIB_BASIC_CPP) cmd += " " + SLIB_BASIC + $E + ".cpp";
			sfor(SLIB_SMATH_CPP) cmd += " " + SLIB_SMATH + $E + ".cpp";
			sfor(SLIB_SOBJ_CPP) cmd += " " + SLIB_SOBJ + $E + ".cpp";
			sfor(SLIB_SIO_CPP) cmd += " " + SLIB_SIO + $E + ".cpp";
			sfor(SLIB_SUTIL_CPP) cmd += " " + SLIB_SUTIL + $E + ".cpp";
			sfor(SLIB_SNET_CPP) cmd += " " + SLIB_SNET + $E + ".cpp";
			sfor(SLIB_SMEDIA_CPP) cmd += " " + SLIB_SMEDIA + $E + ".cpp";
			std::cout << cmd << std::endl;
			res = system(cmd.c_str());
			res = system("ar rcs libsobj.a ./*.o");
			res = system("rm -r ./*.o");
		}
	}
	if (lsapp) {
		if (shared) {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH + SHARED_FLAG +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sfor(SLIB_SAPP_CPP) cmd += " " + SLIB_SAPP + $E + ".cpp";
			std::cout << cmd << std::endl;
			res = system(cmd.c_str());
			cmd = "g++ " + CPP_VERSION + " -shared -o libsapp.so";
			sfor(SLIB_SAPP_CPP) cmd += " " + $E + ".o";
			std::cout << cmd << std::endl;
			res = system(cmd.c_str());
			res = system("rm -r ./*.o");
		}
		else {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sfor(SLIB_SAPP_CPP) cmd += " " + SLIB_SAPP + $E + ".cpp";
			std::cout << cmd << std::endl;
			res = system(cmd.c_str());
			res = system("ar rcs libsapp.a ./*.o");
			res = system("rm -r ./*.o");
		}
	}
	if (lsnapp) {
		if (shared) {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH + SHARED_FLAG +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sfor(SLIB_SNODEAPP_CPP) cmd += " " + SLIB_SAPP + $E + ".cpp";
			std::cout << cmd << std::endl;
			res = system(cmd.c_str());
			cmd = "g++ " + CPP_VERSION + " -shared -o libsnodeapp.so";
			sfor(SLIB_SNODEAPP_CPP) cmd += " " + $E + ".o";
			std::cout << cmd << std::endl;
			res = system(cmd.c_str());
			res = system("rm -r ./*.o");
		}
		else {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sfor(SLIB_SNODEAPP_CPP) cmd += " " + SLIB_SAPP + $E + ".cpp";
			std::cout << cmd << std::endl;
			res = system(cmd.c_str());
			res = system("ar rcs libsnodeapp.a ./*.o");
			res = system("rm -r ./*.o");
		}
	}
	if (lsbioinfo) {
		if (shared) {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH + SHARED_FLAG +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sfor(SLIB_SBI_CPP) cmd += " " + SLIB_SBIOINFO + $E + ".cpp";
			std::cout << cmd << std::endl;
			res = system(cmd.c_str());
			cmd = "g++ " + CPP_VERSION + " -shared -o libsbioinfo.so";
			sfor(SLIB_SBI_CPP) cmd += " " + $E + ".o";
			std::cout << cmd << std::endl;
			res = system(cmd.c_str());
			res = system("rm -r ./*.o");
		}
		else {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sfor(SLIB_SBI_CPP) cmd += " " + SLIB_SBIOINFO + $E + ".cpp";
			std::cout << cmd << std::endl;
			res = system(cmd.c_str());
			res = system("ar rcs libsbioinfo.a ./*.o");
			res = system("rm -r ./*.o");
		}
	}
	
	struct stat buf;
	res = stat("/usr/local/include/slib", &buf);
	if (res) {
		res = system("sudo mkdir /usr/local/include/slib");
	}
	res = system("sudo cp -f ../include/*.h /usr/local/include/slib");
	if (lsobj) {
		res = system("sudo cp -fr ../include/curl /usr/local/include/slib");
		res = system("sudo cp -fr ../include/libjpeg /usr/local/include/slib");
		res = system("sudo cp -fr ../include/libpng /usr/local/include/slib");
		res = system("sudo cp -fr ../include/libtiff /usr/local/include/slib");
		res = system("sudo cp -fr ../include/sbasic /usr/local/include/slib");
		res = system("sudo cp -fr ../include/sio /usr/local/include/slib");
		res = system("sudo cp -fr ../include/smath /usr/local/include/slib");
		res = system("sudo cp -fr ../include/smedia /usr/local/include/slib");
		res = system("sudo cp -fr ../include/snet /usr/local/include/slib");
		res = system("sudo cp -fr ../include/sobj /usr/local/include/slib");
		res = system("sudo cp -fr ../include/sqlite /usr/local/include/slib");
		res = system("sudo cp -fr ../include/sutil /usr/local/include/slib");
		res = system("sudo cp -fr ../include/zlib /usr/local/include/slib");
		res = system("sudo cp -fr ../include/crypto /usr/local/include/slib");
	}
	if (lsapp) {
		res = system("sudo cp -fr ../include/sapp /usr/local/include/slib");
	}
	if (lsnapp) {
		res = system("sudo cp -fr ../include/sapp /usr/local/include/slib");
		res = system("sudo cp -fr ../include/node /usr/local/include/slib");
	}
	if (lsbioinfo) {
		res = system("sudo cp -fr ../include/sbioinfo /usr/local/include/slib");
	}
	if (lsscience) {
		res = system("sudo cp -fr ../include/sscience /usr/local/include/slib");
	}
	res = system("sudo cp -f ./* /usr/local/lib");
	res = chdir(home.c_str());
	res = system("rm -r ./slib");
#endif
	return 0;
}
