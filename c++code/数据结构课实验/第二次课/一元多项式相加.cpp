#include <iostream>
using namespace std;

// 多项式项的结构
struct Term {
    int coeff;      // 系数
    int exp;        // 指数
    Term* next;

    Term(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};

class Polynomial {
private:
    Term* head;

public:
    Polynomial() : head(nullptr) {}

    // 按指数降序插入项，若指数相同则合并系数
    void addTerm(int coeff, int exp) {
        if (coeff == 0) return; // 系数为0不插入

        if (!head || head->exp < exp) {
            // 插入到头部
            Term* newNode = new Term(coeff, exp);
            newNode->next = head;
            head = newNode;
        } else if (head->exp == exp) {
            // 合并同类项
            head->coeff += coeff;
            if (head->coeff == 0) {
                Term* temp = head;
                head = head->next;
                delete temp;
            }
        } else {
            Term* prev = head;
            Term* curr = head->next;

            while (curr && curr->exp > exp) {
                prev = curr;
                curr = curr->next;
            }

            if (curr && curr->exp == exp) {
                // 合并
                curr->coeff += coeff;
                if (curr->coeff == 0) {
                    prev->next = curr->next;
                    delete curr;
                }
            } else {
                // 插入新节点
                Term* newNode = new Term(coeff, exp);
                prev->next = newNode;
                newNode->next = curr;
            }
        }
    }

    // 打印多项式
    void print() const {
        if (!head) {
            cout << "0";
            return;
        }

        Term* p = head;
        bool first = true;
        while (p) {
            if (p->coeff > 0 && !first) cout << " + ";
            else if (p->coeff < 0) cout << " - ";

            int absCoeff = abs(p->coeff);
            if (p->exp == 0) {
                cout << absCoeff;
            } else if (p->exp == 1) {
                if (absCoeff == 1) cout << "x";
                else cout << absCoeff << "x";
            } else {
                if (absCoeff == 1) cout << "x^" << p->exp;
                else cout << absCoeff << "x^" << p->exp;
            }

            first = false;
            p = p->next;
        }
    }

    // 析构函数，释放内存
    ~Polynomial() {
        Term* p = head;
        while (p) {
            Term* temp = p;
            p = p->next;
            delete temp;
        }
    }

    // 友元函数：相加两个多项式
    friend Polynomial addPolynomials(const Polynomial& p1, const Polynomial& p2);
};

// 多项式相加函数
Polynomial addPolynomials(const Polynomial& p1, const Polynomial& p2) {
    Polynomial result;
    Term* t1 = p1.head;
    Term* t2 = p2.head;

    while (t1 && t2) {
        if (t1->exp > t2->exp) {
            result.addTerm(t1->coeff, t1->exp);
            t1 = t1->next;
        } else if (t1->exp < t2->exp) {
            result.addTerm(t2->coeff, t2->exp);
            t2 = t2->next;
        } else {
            result.addTerm(t1->coeff + t2->coeff, t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        }
    }

    while (t1) {
        result.addTerm(t1->coeff, t1->exp);
        t1 = t1->next;
    }

    while (t2) {
        result.addTerm(t2->coeff, t2->exp);
        t2 = t2->next;
    }

    return result;
}

// 示例主函数
int main() {
    Polynomial p1, p2;

    // p1 = 3x^4 + 5x^2 + 6x + 2
    p1.addTerm(3, 4);
    p1.addTerm(5, 2);
    p1.addTerm(6, 1);
    p1.addTerm(2, 0);

    // p2 = -2x^4 + 4x^3 + 5x + 1
    p2.addTerm(-2, 4);
    p2.addTerm(4, 3);
    p2.addTerm(5, 1);
    p2.addTerm(1, 0);

    cout << "p1 = ";
    p1.print();
    cout << endl;

    cout << "p2 = ";
    p2.print();
    cout << endl;

    Polynomial p3 = addPolynomials(p1, p2);
    cout << "p1 + p2 = ";
    p3.print();
    cout << endl;

    return 0;
}