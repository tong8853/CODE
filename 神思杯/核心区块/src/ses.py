import torch
import json
import os
from ultralytics import YOLO
from PIL import Image
import numpy as np

# 类别映射（与data_config.yaml完全一致）
CLASS_MAP = {
    0: {"label": "WhiteStage", "class": 0},
    1: {"label": "TurningStage", "class": 1},
    2: {"label": "MatureStage", "class": 2},
    3: {"label": "RipeStage", "class": 3}
}

class ModelInference:
    def __init__(self):
        # 模型状态初始化（平台要求的3种状态）
        self.status = "initializing"
        self.model_path = "/project/train/models/best.pt"
        self.model = None
        try:
            # 加载模型
            self.model = YOLO(self.model_path)
            self.device = "cuda:0" if torch.cuda.is_available() else "cpu"
            self.status = "ready"  # 加载成功，状态设为就绪
            print(f"模型加载成功，使用设备：{self.device}")
        except Exception as e:
            self.status = "abnormal"  # 加载失败，状态设为异常
            print(f"模型加载失败：{str(e)}")

    def init(self, model_path):
        """平台要求的初始化接口（参数为模型目录路径）"""
        self.__init__()  # 调用构造函数重新初始化

    def get_status(self):
        """平台要求的获取模型状态接口"""
        return self.status

    def process_image(self, image_path, *args, **kwargs):
        """平台要求的推理接口（输入图片路径，输出JSON格式结果）"""
        # 若模型未就绪，返回空结果
        if self.status != "ready":
            return {"classifications": [], "objects": [], "segmentations": []}

        try:
            # 读取图片并推理
            image = Image.open(image_path).convert("RGB")
            results = self.model(image, imgsz=640, device=self.device)

            # 解析分类结果（按平台接口标准构造返回格式）
            probs = results[0].probs.data.cpu().numpy()
            max_prob_idx = np.argmax(probs)
            pred_info = CLASS_MAP[max_prob_idx]

            # 构造平台要求的JSON结构（classifications为必填，其他可选）
            result = {
                "classifications": [
                    {
                        "class": pred_info["class"],  # 分类类型（整数）
                        "prob": round(float(probs[max_prob_idx]), 4),  # 置信度（float）
                        "label": pred_info["label"]  # 标签（字符串）
                    }
                ],
                "objects": [],  # 分类任务无需目标检测，留空
                "segmentations": []  # 无需分割，留空
            }
            return result

        except Exception as e:
            print(f"推理报错：{str(e)}")
            return {"classifications": [], "objects": [], "segmentations": []}