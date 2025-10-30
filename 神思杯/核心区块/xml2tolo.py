import xml.etree.ElementTree as ET
import os

classes = ["WhiteStage", "TurningStage", "MatureStage", "RipeStage"] 
xml_dir = "/home/data/train/labels_xml"  # 临时XML目录
txt_dir = "/home/data/train/labels"      # 转换后TXT存放目录

os.makedirs(txt_dir, exist_ok=True)

def convert(size, box):
    dw = 1.0 / size[0]
    dh = 1.0 / size[1]
    x = (box[0] + box[1]) / 2.0 * dw
    y = (box[2] + box[3]) / 2.0 * dh
    w = (box[1] - box[0]) * dw
    h = (box[3] - box[2]) * dh
    return (x, y, w, h)

for xml_file in os.listdir(xml_dir):
    if not xml_file.endswith(".xml"):
        continue
    xml_path = os.path.join(xml_dir, xml_file)
    txt_path = os.path.join(txt_dir, xml_file.replace(".xml", ".txt"))
    
    tree = ET.parse(xml_path)
    root = tree.getroot()
    size = root.find("size")
    width = int(size.find("width").text)
    height = int(size.find("height").text)
    
    with open(txt_path, "w") as out_file:
        for obj in root.iter("object"):
            cls = obj.find("name").text
            if cls not in classes:
                continue
            cls_id = classes.index(cls)
            bndbox = obj.find("bndbox")
            xmin = float(bndbox.find("xmin").text)
            xmax = float(bndbox.find("xmax").text)
            ymin = float(bndbox.find("ymin").text)
            ymax = float(bndbox.find("ymax").text)
            bb = convert((width, height), (xmin, xmax, ymin, ymax))
            out_file.write(f"{cls_id} {bb[0]:.6f} {bb[1]:.6f} {bb[2]:.6f} {bb[3]:.6f}\n")