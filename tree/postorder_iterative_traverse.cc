// Binary Tree를 탐색할 때 pre, in, post order로 구현할 수 있음
// 각각의 경우 재귀적으로 구현하는 건 쉽지만, 반복적으로 구현하는 건 생각보다 어려움

// post-order (iterative)
// 1. Two stack 을 이용하는 방법
// postorder의 경우 left->right->root 순으로 탐색(또는 출력)되는 것을 이용해서
// 첫번째 stack에 | left | right | root | 순으로 쌓여서 꺼내면 root->right->left
// 순서가 되도록 함.
// 이 때, 꺼내면서 두 번째 stack에 값을 집어넣으면, 나중에 이 stack을 순차적으로 꺼내면
// 원하는 결과값이 됨
vector<int> postorderTraversal(TreeNode* root) {
      vector<int> ans;
      if (!root) return ans;

      stack<TreeNode*> stk;
      stk.push(root);
      stack<int> out;
      while (!stk.empty()) {
        TreeNode* node = stk.top(); stk.pop();
        out.push(node->val);
        if (node->left) stk.push(node->left);
        if (node->right) stk.push(node->right);
      }
      while(!out.empty()) {
        int v = out.top(); out.pop();
        ans.push_back(v);
      }
      return ans;
