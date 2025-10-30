# 激活平台YOLO虚拟环境（按baseline路径）
source /project/train/env/yolo/bin/activate

# 切换到训练脚本所在目录
cd /project/train/src_repo/project-7-tenant-943-model-code-u2iw/

# 执行训练脚本
python3 train.py

# 训练完成后，复制最优模型到平台要求的/models目录（必须步骤）
cp /project/train/result-graphs/ssp/weights/best.pt /project/train/models/