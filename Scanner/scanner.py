import os
import PIL.Image as IMAGE
from PIL import Image
from pyzbar import pyzbar

def enlarge_image(image, scale_factor):
    width, height = image.size
    new_size = (int(width * scale_factor), int(height * scale_factor))
    return image.resize(new_size, Image.Resampling.BICUBIC)

if __name__ == "__main__":
    # 读取图像
    img_root = "../Generator/fruits/"
    for filename in next(os.walk("../Generator/fruits"))[2]:
        image = IMAGE.open(os.path.join(img_root, filename))
        # 识别二维码
        barcodes = pyzbar.decode(image)
        # 输出结果
        for barcode in barcodes:
            data = barcode.data.decode("utf-8")
            print("内容:", data)
            print("类型:", barcode.type)
