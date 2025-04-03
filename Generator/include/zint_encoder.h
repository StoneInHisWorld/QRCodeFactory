#pragma once
#include "declaration.h"

// ZintEncoder类，用于将文本信息编码为条形码
class ZintEncoder {
private:
	// Zint库的符号结构体指针
	struct zint_symbol* my_symbol;
	// 编码输出图片的缩放比例
	float scale;
	// 编码模式
	int mode;

public:
	// 构造函数，初始化my_symbol指针，并设置缩放比例和模式
	ZintEncoder(float scale = 1, int mode = BARCODE_QRCODE) {
		this->my_symbol = ZBarcode_Create();
		this->scale = scale;
		this->mode = mode;
		my_symbol->symbology = mode;
		my_symbol->scale = scale;
	};

	// 将"text"包含的信息根据模式编码，并保存到"ofile_name"文件中
	void encode(string text, string ofile_name) {
		strcpy_s(my_symbol->outfile, ofile_name.c_str());
		ZBarcode_Encode_and_Print(my_symbol, (const unsigned char*)text.c_str(), 0, 0);
		this->refresh(this->scale, this->mode);
	};

	// 刷新条形码的缩放比例和模式
	void refresh(int scale = 1, int mode = BARCODE_QRCODE) {
		ZBarcode_Delete(my_symbol);
		this->my_symbol = ZBarcode_Create();
		my_symbol->symbology = mode;
		my_symbol->scale = scale;
	};

	~ZintEncoder() {
		ZBarcode_Delete(my_symbol);
	};
};