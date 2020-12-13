//��Ч����ĸ��λ��
class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length())return false;
		map<char, int>a;
		for (int i = 0; i < s.length(); ++i) {
			a[s[i]]++;
			a[t[i]]--;
		}
		for (int i = 0; i < t.length(); ++i) {
			if (a[s[i]] != 0)return false;
		}
		return true;
	}
};

//��������ǰ�����
class Solution {
public:
	void preorder(TreeNode* root, vector<int>& result) {
		if (root == nullptr) {
			return;
		}
		result.push_back(root->val);
		preorder(root->left, result);
		preorder(root->right, result);
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int>res;
		preorder(root, res);
		return  res;
	}
};

// ǰk����ƵԪ��
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int>a;//��ϣ���¼����
		vector<int>b;//��������
		vector<int>res;//���
		for (int i; i < nums.size(); ++i) {
			a[nums[i]]++;
		}
		for (auto& i : a) {
			b.emplace_back(i.second);
		}
		sort(b.begin(), b.end());

		for (auto& i : a) {
			if (i.second >= b[b.size() - k])
				res.emplace_back(i.first);
		}
		return res;
	}
};