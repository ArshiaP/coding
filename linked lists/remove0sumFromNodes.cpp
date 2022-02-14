// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

// explanation

//  https://snowan.gitbook.io/study-notes/leetcode/english-solution/1171.remove-zero-sum-consecutive-nodes-from-linked-list-en#:~:text=Given%20the%20head%20of%20a,there%20are%20no%20such%20sequences.&text=After%20doing%20so%2C%20return%20the,may%20return%20any%20such%20answer.&text=(Note%20that%20in%20the%20examples,are%20serializations%20of%20ListNode%20objects.)

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode
{
  int val;
  struct ListNode *next;
};

void append(struct ListNode **head, int node_val)
{
  struct ListNode *newNode = new ListNode;
  struct ListNode *last = *head;
  newNode->val = node_val;
  newNode->next = NULL;
  if (*head == NULL)
  {
    *head = newNode;
    return;
  }
  while (last->next != NULL)
    last = last->next;
  last->next = newNode;
  return;
}

void displayList(struct ListNode *ListNode)
{
  while (ListNode != NULL)
  {
    cout << ListNode->val << " => ";
    ListNode = ListNode->next;
  }
  if (ListNode == NULL)
    cout << "null";
}

ListNode *removeZeroSumSublists(ListNode *head)
{
  ListNode *dummy = new ListNode;
  dummy->next = head;
  unordered_map<int, ListNode *> m;
  m[0] = dummy;
  int sum = 0;
  while (head)
  {
    sum += head->val;
    m[sum] = head; 
    //if sum is repeating, that means a sublist of 0 is encountered. hence the new value is the pointer to the node of the last element in the sublist which equals to 0
    head = head->next;
  }
  head = dummy;
  sum = 0;
  while (head)
  {
    sum += head->val;
    ListNode *temp = m[sum];
    if (temp != head)
    {
      head->next = temp->next;
      //temp will point to the last element in the sublist. this line skips through all the elements in the sublist.
    }
    head = head->next;
  }
  return dummy->next;
}


int main()
{
  struct ListNode *head = NULL;
  append(&head, 2);
  append(&head, 2);
  append(&head, -2);
  append(&head, 1);
  append(&head, -1);
  append(&head, -1);
  // append(&head, 5);
  // append(&head, -6);
  // displayList(head);
  struct ListNode *result = removeZeroSumSublists(head);
  displayList(result);
}