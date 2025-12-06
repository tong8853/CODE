#include "Huffman.h"

int main() {
    string text;
    cout << "输入文本: ";
    getline(cin, text);
    
    Huffman huff(text);
    
    cout << "\n哈夫曼编码表:" << endl;
    huff.print_code();
    
    string encoded = huff.encode(text);
    cout << "\n编码结果: " << encoded << endl;
    
    string decoded = huff.decode(encoded);
    cout << "解码结果: " << decoded << endl;
    
    cout << "原始与解码是否一致: " << (text == decoded ? "是" : "否") << endl;
    return 0;
}