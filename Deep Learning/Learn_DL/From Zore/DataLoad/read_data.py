from torch.utils.data import Dataset, ConcatDataset  # 添加ConcatDataset导入
from PIL import Image
import os

class MyData(Dataset):     
    def __init__(self,root_dir,label_dir):    # 该魔术方法当创建一个事例对象时，会自动调用该函数
        self.root_dir = root_dir # self.root_dir 相当于类中的全局变量
        self.label_dir = label_dir     
        self.path = os.path.join(self.root_dir,self.label_dir) # 字符串拼接，根据是Windows或Lixus系统情况进行拼接               
        self.img_path = os.listdir(self.path) # 获得路径下所有图片的地址
        
    def __getitem__(self,idx):
        img_name = self.img_path[idx]
        img_item_path = os.path.join(self.root_dir,self.label_dir,img_name)            
        img = Image.open(img_item_path)
        label = self.label_dir
        return img, label
    
    def __len__(self):
        return len(self.img_path)
    
root_dir = "Data/FirstTypeData/train"
ants_label_dir = "ants"
bees_label_dir = "bees"
ants_dataset = MyData(root_dir, ants_label_dir)
bees_dataset = MyData(root_dir, bees_label_dir)
print(len(ants_dataset))
print(len(bees_dataset))
train_dataset = ConcatDataset([ants_dataset, bees_dataset]) # 使用ConcatDataset正确合并数据集     
print(len(train_dataset))

img,label = train_dataset[200]
print("label:",label)
img.show()  # 注释掉show方法，因为不是所有环境都支持