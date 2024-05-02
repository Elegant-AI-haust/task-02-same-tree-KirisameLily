//国教自动化233吴家宝231425070323 WeChat:w18539512122
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }
    if (p == nullptr || q == nullptr)
    {
        return false;
    }
    if (p->val != q->val)
    {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    bool result = isSameTree(p, q);
    cout << (result ? "true" : "false") << endl;

    delete p->left; // 清理内存
    delete p->right;
    delete p;

    delete q->left;
    delete q->right;
    delete q;

    return 0;
}
