from ultralytics import YOLO
import os
import logging

# 配置日志（存入平台指定目录）
log_path = "/project/train/log/train_log.log"
logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s - %(levelname)s - %(message)s",
    handlers=[logging.FileHandler(log_path), logging.StreamHandler()]
)
logger = logging.getLogger(__name__)

try:
    # 加载YOLO模型（分类任务用yolov8n-cls.pt，检测任务用yolov8n.pt）
    model = YOLO("yolov8n-cls.pt")

    # 启动训练
    results = model.train(
    # 1. 数据增强：提升模型泛化性（针对果蔬不同光照/角度场景）
    data="/project/train/src_repo/project-7-tenant-943-model-code-u2iw/data_config.yaml",
    augment=True,  # 开启YOLO默认增强（旋转、缩放、色域抖动等）
    hsv_h=0.015,   # 色相抖动幅度（0-1，果蔬颜色是关键特征，适度增强）
    hsv_s=0.7,     # 饱和度抖动
    hsv_v=0.4,     # 明度抖动
    degrees=10.0,  # 旋转角度（±10度，模拟拍摄角度偏差）
    flipud=0.2,    # 上下翻转概率（20%，避免样本方向单一）
    fliplr=0.5,    # 左右翻转概率（50%，增强对称性）

    # 2. 训练策略：平衡精度与效率
    epochs=80,     # 减少轮次（原100轮可能过拟合，先看验证集精度拐点）
    batch=16,      # 增大批次（T4卡可支持16，提升GPU利用率）
    imgsz=512,     # 减小图像尺寸（果蔬目标较大，512足够，加速训练）
    device=0,

    # 3. 正则化：抑制过拟合（小数据集必备）
    weight_decay=0.0005,  # 权重衰减（减少权重过大）
    dropout=0.2,          #  dropout概率（仅分类模型有效，随机丢弃20%神经元）
    patience=15,          # 早停策略（15轮无提升则停止，节省时间）

    # 4. 优化器与学习率：加速收敛
    optimizer="AdamW",    # 替换默认SGD，AdamW在小数据上收敛更快
    lr0=0.001,            # 初始学习率（比默认0.01小，避免震荡）
    lrf=0.01,             # 最终学习率因子（lr0 * lrf）
    warmup_epochs=3,      # 热身训练（前3轮缓慢提升学习率，稳定训练）

    # 5. 结果保存：聚焦关键指标
    save=True,
    save_dir="/project/train/result-graphs/fruit_maturity",
    project="/project/train",
    name="fruit_maturity_model",
    val=True,             # 每轮验证（默认开启，确保及时监控过拟合）
    plots=True            # 生成混淆矩阵、PR曲线（便于分析类别差异）
)

    # 移动最优模型到平台要求的models目录
    best_model = os.path.join(
        "/project/train/result-graphs/fruit_maturity/weights", 
        "best.pt"
    )
    target_model = "/project/train/models/best.pt"
    os.rename(best_model, target_model)
    logger.info(f"模型训练完成，保存路径：{target_model}")

except Exception as e:
    logger.error(f"训练失败：{str(e)}", exc_info=True)
    raise