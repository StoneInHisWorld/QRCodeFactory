#include "./include/zint_encoder.h"
#include "./include/pathDeclaration.h"
#include <fstream>

// 二维码保存目录
static const string save_root = "./fruits/";
// 文件保存扩展名
static const string file_postfix = ".bmp";
// 二维码缩放比例
static const float scale = 1;
// 二维码编码模式，其他编码模式请参考Zint库的文档
static const int mode = BARCODE_QRCODE;

void check_dir(const string& filename)
{
	// 检查目录是否存在
	fs::path p = get_directory(filename);
	if (!fs::exists(p))
	{
		fs::create_directories(p);
	}
}

int main()
{
	ZintEncoder encoder(1, BARCODE_QRCODE);
	vector<string> msgs = {"Hello world", "This is an example", "to illustrate how to use this project"};
	int index = 0;
	for (auto& msg : msgs)
	{
		const string filename = save_root + to_string(index++) + file_postfix;
		//check_dir(filename);
		encoder.encode(msg, filename);
		display_progress_bar(index - 1, msgs.size());
	}
	cout << endl;
	system("pause");
	return 0;
}