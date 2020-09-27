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
	chdir(home.c_str());
	system("mkdir slib");
	chdir(workspace.c_str());
	system("curl -Lk -o slib.zip https://github.com/YujiSue/slib/archive/master.zip");
	system("unzip ./slib.zip");
	workspace += "/slib-master";
	chdir(workspace.c_str());
	system("mkdir build");
	workspace += "/build";
	chdir(workspace.c_str());
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
	chdir(home.c_str());
	mkdir("slib");
	chdir(workspace.c_str());
	system("wget --output-document ./master.zip https://github.com/YujiSue/slib/archive/master.zip");
	system("unzip ./*.zip");
	workspace += "/slib-master";
	chdir(workspace.c_str());
	mkdir("build");
	workspace += "/build";
	chdir(workspace.c_str());

#ifdef WIN_OS
	if (lsobj) {



		cl.exe / EHsc / utf - 8 / I"  \slib\include" / c Goetia.cpp
			link "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib""kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" Goetia.obj

			cmd = "gcc" + INCLUDE_PATH + LD_PATH + PTHREAD_LIB_PATH + SHARED_FLAG +
			" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
		sforeach(LIB_Z_C) cmd += " " + LIB_Z + E_ + ".c";
		sforeach(LIB_TIFF_C) cmd += " " + LIB_TIFF + E_ + ".c";
		cmd += " " + LIB_TIFF + UNIQUE_LIBTIFF_C + ".c";
		sforeach(LIB_PNG_C) cmd += " " + LIB_PNG + E_ + ".c";
		sforeach(LIB_JPEG_C) cmd += " " + LIB_JPEG + E_ + ".c";
		sforeach(LIB_SQLITE_C) cmd += " " + LIB_SQLITE + E_ + ".c";
		std::cout << cmd << std::endl;
		system(cmd.c_str());
		if (shared) {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH + SHARED_FLAG +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sforeach(SLIB_BASIC_CPP) cmd += " " + SLIB_BASIC + E_ + ".cpp";
			sforeach(SLIB_SOBJ_CPP) cmd += " " + SLIB_SOBJ + E_ + ".cpp";
			sforeach(SLIB_SIO_CPP) cmd += " " + SLIB_SIO + E_ + ".cpp";
			sforeach(SLIB_SUTIL_CPP) cmd += " " + SLIB_SUTIL + E_ + ".cpp";
			sforeach(SLIB_SNET_CPP) cmd += " " + SLIB_SNET + E_ + ".cpp";
			sforeach(SLIB_SMEDIA_CPP) cmd += " " + SLIB_SMEDIA + E_ + ".cpp";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			cmd = "g++" + CPP_VERSION + CURL_LIB_PATH + " -shared -o libsobj.so";
			sforeach(LIB_Z_C) cmd += " " + E_ + ".o";
			sforeach(LIB_TIFF_C) cmd += " " + E_ + ".o";
			cmd += " " + UNIQUE_LIBTIFF_C + ".o";
			sforeach(LIB_PNG_C) cmd += " " + E_ + ".o";
			sforeach(LIB_JPEG_C) cmd += " " + E_ + ".o";
			sforeach(LIB_SQLITE_C) cmd += " " + E_ + ".o";
			sforeach(SLIB_BASIC_CPP) cmd += " " + E_ + ".o";
			sforeach(SLIB_SOBJ_CPP) cmd += " " + E_ + ".o";
			sforeach(SLIB_SIO_CPP) cmd += " " + E_ + ".o";
			sforeach(SLIB_SUTIL_CPP) cmd += " " + E_ + ".o";
			sforeach(SLIB_SNET_CPP) cmd += " " + E_ + ".o";
			sforeach(SLIB_SMEDIA_CPP) cmd += " " + E_ + ".o";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			system("rm -r ./*.o");
		}
		else {
			cmd = "gcc -shared -o libshelper.so";
			sforeach(LIB_Z_C) cmd += " " + E_ + ".o";
			sforeach(LIB_TIFF_C) cmd += " " + E_ + ".o";
			cmd += " " + UNIQUE_LIBTIFF_C + ".o";
			sforeach(LIB_PNG_C) cmd += " " + E_ + ".o";
			sforeach(LIB_JPEG_C) cmd += " " + E_ + ".o";
			sforeach(LIB_SQLITE_C) cmd += " " + E_ + ".o";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			system("rm -r ./*.o");
			cmd = "g++ " + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sforeach(SLIB_BASIC_CPP) cmd += " " + SLIB_BASIC + E_ + ".cpp";
			sforeach(SLIB_SOBJ_CPP) cmd += " " + SLIB_SOBJ + E_ + ".cpp";
			sforeach(SLIB_SIO_CPP) cmd += " " + SLIB_SIO + E_ + ".cpp";
			sforeach(SLIB_SUTIL_CPP) cmd += " " + SLIB_SUTIL + E_ + ".cpp";
			sforeach(SLIB_SNET_CPP) cmd += " " + SLIB_SNET + E_ + ".cpp";
			sforeach(SLIB_SMEDIA_CPP) cmd += " " + SLIB_SMEDIA + E_ + ".cpp";
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
		sforeach(LIB_Z_C) cmd += " " + LIB_Z + E_ + ".c";
		sforeach(LIB_TIFF_C) cmd += " " + LIB_TIFF + E_ + ".c";
		cmd += " " + LIB_TIFF + UNIQUE_LIBTIFF_C + ".c";
		sforeach(LIB_PNG_C) cmd += " " + LIB_PNG + E_ + ".c";
		sforeach(LIB_JPEG_C) cmd += " " + LIB_JPEG + E_ + ".c";
		sforeach(LIB_SQLITE_C) cmd += " " + LIB_SQLITE + E_ + ".c";
		sforeach(CRYPTO_C) cmd += " " + CRYPTO + E_ + ".c";
		std::cout << cmd << std::endl;
		system(cmd.c_str());
		if (shared) {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH + SHARED_FLAG +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sforeach(SLIB_BASIC_CPP) cmd += " " + SLIB_BASIC + E_ + ".cpp";
			sforeach(SLIB_SOBJ_CPP) cmd += " " + SLIB_SOBJ + E_ + ".cpp";
			sforeach(SLIB_SIO_CPP) cmd += " " + SLIB_SIO + E_ + ".cpp";
			sforeach(SLIB_SUTIL_CPP) cmd += " " + SLIB_SUTIL + E_ + ".cpp";
			sforeach(SLIB_SNET_CPP) cmd += " " + SLIB_SNET + E_ + ".cpp";
			sforeach(SLIB_SMEDIA_CPP) cmd += " " + SLIB_SMEDIA + E_ + ".cpp";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			cmd = "g++" + CPP_VERSION + CURL_LIB_PATH + " -shared -o libsobj.so";
			sforeach(LIB_Z_C) cmd += " " + E_ + ".o";
			sforeach(LIB_TIFF_C) cmd += " " + E_ + ".o";
			cmd += " " + UNIQUE_LIBTIFF_C + ".o";
			sforeach(LIB_PNG_C) cmd += " " + E_ + ".o";
			sforeach(LIB_JPEG_C) cmd += " " + E_ + ".o";
			sforeach(LIB_SQLITE_C) cmd += " " + E_ + ".o";
			sforeach(CRYPTO) cmd += " " + E_ + ".o";
			sforeach(SLIB_BASIC_CPP) cmd += " " + E_ + ".o";
			sforeach(SLIB_SOBJ_CPP) cmd += " " + E_ + ".o";
			sforeach(SLIB_SIO_CPP) cmd += " " + E_ + ".o";
			sforeach(SLIB_SUTIL_CPP) cmd += " " + E_ + ".o";
			sforeach(SLIB_SNET_CPP) cmd += " " + E_ + ".o";
			sforeach(SLIB_SMEDIA_CPP) cmd += " " + E_ + ".o";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			system("rm -r ./*.o");
		}
		else {
			cmd = "gcc -shared -o libshelper.so";
			sforeach(LIB_Z_C) cmd += " " + E_ + ".o";
			sforeach(LIB_TIFF_C) cmd += " " + E_ + ".o";
			cmd += " " + UNIQUE_LIBTIFF_C + ".o";
			sforeach(LIB_PNG_C) cmd += " " + E_ + ".o";
			sforeach(LIB_JPEG_C) cmd += " " + E_ + ".o";
			sforeach(LIB_SQLITE_C) cmd += " " + E_ + ".o";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			system("rm -r ./*.o");
			cmd = "g++ " + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sforeach(SLIB_BASIC_CPP) cmd += " " + SLIB_BASIC + E_ + ".cpp";
			sforeach(SLIB_SOBJ_CPP) cmd += " " + SLIB_SOBJ + E_ + ".cpp";
			sforeach(SLIB_SIO_CPP) cmd += " " + SLIB_SIO + E_ + ".cpp";
			sforeach(SLIB_SUTIL_CPP) cmd += " " + SLIB_SUTIL + E_ + ".cpp";
			sforeach(SLIB_SNET_CPP) cmd += " " + SLIB_SNET + E_ + ".cpp";
			sforeach(SLIB_SMEDIA_CPP) cmd += " " + SLIB_SMEDIA + E_ + ".cpp";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			system("ar rcs libsobj.a ./*.o");
			system("rm -r ./*.o");
		}
	}
	if (lsbioinfo) {
		if (shared) {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH + SHARED_FLAG +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sforeach(SLIB_SBI_CPP) cmd += " " + SLIB_SBIOINFO + E_ + ".cpp";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			cmd = "g++ " + CPP_VERSION + " -shared -o libsbioinfo.so";
			sforeach(SLIB_SBI_CPP) cmd += " " + E_ + ".o";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			system("rm -r ./*.o");
		}
		else {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sforeach(SLIB_SBI_CPP) cmd += " " + SLIB_SBIOINFO + E_ + ".cpp";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			system("ar rcs libsbioinfo.a ./*.o");
			system("rm -r ./*.o");
		}
	}
	if (lsapp) {
		if (shared) {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH + SHARED_FLAG +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sforeach(SLIB_SAPP_CPP) cmd += " " + SLIB_SAPP + E_ + ".cpp";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			cmd = "g++ " + CPP_VERSION + " -shared -o libsapp.so";
			sforeach(SLIB_SAPP_CPP) cmd += " " + E_ + ".o";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			system("rm -r ./*.o");
		}
		else {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sforeach(SLIB_SAPP_CPP) cmd += " " + SLIB_SAPP + E_ + ".cpp";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			system("ar rcs libsapp.a ./*.o");
			system("rm -r ./*.o");
		}
	}
	if (lsnapp) {
		if (shared) {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH + SHARED_FLAG +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sforeach(SLIB_SNODEAPP_CPP) cmd += " " + SLIB_SAPP + E_ + ".cpp";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			cmd = "g++ " + CPP_VERSION + " -shared -o libsnodeapp.so";
			sforeach(SLIB_SNODEAPP_CPP) cmd += " " + E_ + ".o";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			system("rm -r ./*.o");
		}
		else {
			cmd = "g++" + CPP_VERSION + INCLUDE_PATH + PTHREAD_LIB_PATH +
				" -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -c";
			sforeach(SLIB_SNODEAPP_CPP) cmd += " " + SLIB_SAPP + E_ + ".cpp";
			std::cout << cmd << std::endl;
			system(cmd.c_str());
			system("ar rcs libsnodeapp.a ./*.o");
			system("rm -r ./*.o");
		}
	}

#endif
	int res;
	struct stat buf;
	res = stat("/usr/local/include/slib", &buf);
	if (res) {
		system("mkdir /usr/local/include/slib");
		system("sudo cp -f ../include/*.h /usr/local/include/slib");
	}
	if (lsobj) {
		system("sudo cp -fr ../include/curl /usr/local/include/slib");
		system("sudo cp -fr ../include/libjpeg /usr/local/include/slib");
		system("sudo cp -fr ../include/libpng /usr/local/include/slib");
		system("sudo cp -fr ../include/libtiff /usr/local/include/slib");
		system("sudo cp -fr ../include/sbasic /usr/local/include/slib");
		system("sudo cp -fr ../include/sio /usr/local/include/slib");
		system("sudo cp -fr ../include/smath /usr/local/include/slib");
		system("sudo cp -fr ../include/smedia /usr/local/include/slib");
		system("sudo cp -fr ../include/snet /usr/local/include/slib");
		system("sudo cp -fr ../include/sobj /usr/local/include/slib");
		system("sudo cp -fr ../include/sqlite /usr/local/include/slib");
		system("sudo cp -fr ../include/sutil /usr/local/include/slib");
		system("sudo cp -fr ../include/zlib /usr/local/include/slib");
		system("sudo cp -fr ../include/crypto /usr/local/include/slib");
	}
	if (lsapp) {
		system("sudo cp -fr ../include/sapp /usr/local/include/slib");
	}
	if (lsnapp) {
		system("sudo cp -fr ../include/sapp /usr/local/include/slib");
		system("sudo cp -fr ../include/node /usr/local/include/slib");
	}
	if (lsbioinfo) {
		system("sudo cp -fr ../include/sbioinfo /usr/local/include/slib");
	}
	if (lsscience) {
		system("sudo cp -fr ../include/sscience /usr/local/include/slib");
	}
	system("sudo cp -f ./* /usr/local/lib");
	chdir(home.c_str());
	system("rm -r ./slib");

#endif
	return 0;
}
