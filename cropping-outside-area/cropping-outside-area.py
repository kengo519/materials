import cv2
import numpy as np
from PIL import Image

if __name__ == "__main__":
    img = cv2.imread("test.jpg")

    black = [0, 0, 0]
    tmp_color = [12, 34, 56]
    change_color = [255, 0, 0]

    img = np.where(img == black, tmp_color, img)
    img = np.array(img, dtype=np.uint8)

    # Pillow型への変換
    pil_img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    pil_img = Image.fromarray(pil_img)

    crop_img = pil_img.crop((120, -100, 1190, 950))

    # OpenCVで使用可能なnumpy型への変換
    cv_crop_img = np.array(crop_img, dtype=np.uint8)
    cv_crop_img = cv2.cvtColor(cv_crop_img, cv2.COLOR_RGB2BGR)

    cv_crop_img = np.where(cv_crop_img == black, change_color, cv_crop_img)
    cv_crop_img = np.where(cv_crop_img == tmp_color, black, cv_crop_img)
    cv_crop_img = np.array(cv_crop_img, dtype=np.uint8)

    cv2.imshow("crop", cv_crop_img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
