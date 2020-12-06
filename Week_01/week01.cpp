//移动零
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		for (int i = 0, j = 0; i < nums.size(); ++i) {
			if (nums[i] != 0) {
				nums[j] = nums[i];
				if (i != j) {
					nums[i] = 0;
				}
				j++;
			}
		}
	}
};

//加一
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		reverse(digits.begin(), digits.end());
		digits[0]++;
		int i = 0;
		while (digits[i] == 10) {
			digits[i++] = 0;
			if (i == digits.size()) {
				digits.push_back(1);
			}
			else digits[i]++;
		}
		reverse(digits.begin(), digits.end());
		return digits;
	}
};

//两数之和
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> a;
		map<int, int> b;
		for (int i = 0; i < nums.size(); ++i) {
			if (b.count(nums[i]) > 0) {
				a = { b[nums[i]],i };
				return a;
			}
			b[target - nums[i]] = i;
		}
		return a;
	}
};

//删除排序数组中的重复项
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2)return nums.size();
		int j = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] == nums[i - 1]) {
				continue;
			}
			else nums[j++] = nums[i];
		}
		return j;
	}
};

//合并两个有序链表
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)return l2;
		if (l2 == nullptr)return l1;
		ListNode* dummyHead = new ListNode(1);
		ListNode* preHead = dummyHead;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				preHead->next = l1;
				l1 = l1->next;
			}
			else {
				preHead->next = l2;
				l2 = l2->next;
			}
			preHead = preHead->next;
		}
		if (!l1) preHead->next = l2;
		if (!l2) preHead->next = l1;
		return dummyHead->next;
	}
}
};