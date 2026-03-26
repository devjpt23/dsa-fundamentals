#pragma once

#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

// A lightweight singly-linked list implementation inspired by common
// LeetCode-style APIs. This is intentionally separate from the
// course-provided `LinkedList` type in `linkedlist.h`.

template <typename T>
class ListChain {
 private:
  struct ListNode {
    T value;
    ListNode* next;

    explicit ListNode(const T& v) : value(v), next(nullptr) {
    }
    ListNode(const T& v, ListNode* n) : value(v), next(n) {
    }
  };

  size_t length_;
  ListNode* head_;

 public:
  ListChain() : length_(0), head_(nullptr) {
  }

  ListChain(const ListChain& other) : length_(0), head_(nullptr) {
    ListNode* curr = other.head_;
    if (!curr) {
      return;
    }

    head_ = new ListNode(curr->value);
    ListNode* tail = head_;
    curr = curr->next;

    while (curr) {
      tail->next = new ListNode(curr->value);
      tail = tail->next;
      curr = curr->next;
    }
    length_ = other.length_;
  }

  ListChain& operator=(const ListChain& other) {
    if (this == &other) {
      return *this;
    }
    purge();

    ListNode* curr = other.head_;
    if (!curr) {
      return *this;
    }

    head_ = new ListNode(curr->value);
    ListNode* tail = head_;
    curr = curr->next;

    while (curr) {
      tail->next = new ListNode(curr->value);
      tail = tail->next;
      curr = curr->next;
    }
    length_ = other.length_;
    return *this;
  }

  ~ListChain() {
    purge();
  }

  bool is_empty() const {
    return head_ == nullptr;
  }

  size_t length() const {
    return length_;
  }

  void prepend(const T& value) {
    head_ = new ListNode(value, head_);
    ++length_;
  }

  void append(const T& value) {
    ListNode* node = new ListNode(value);
    if (!head_) {
      head_ = node;
      ++length_;
      return;
    }

    ListNode* curr = head_;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = node;
    ++length_;
  }

  T remove_front() {
    if (!head_) {
      throw runtime_error("remove_front from empty ListChain");
    }
    ListNode* old = head_;
    T v = old->value;
    head_ = old->next;
    delete old;
    --length_;
    return v;
  }

  T remove_back() {
    if (!head_) {
      throw runtime_error("remove_back from empty ListChain");
    }

    if (!head_->next) {
      T v = head_->value;
      delete head_;
      head_ = nullptr;
      --length_;
      return v;
    }

    ListNode* curr = head_;
    ListNode* prev = nullptr;
    while (curr->next) {
      prev = curr;
      curr = curr->next;
    }
    T v = curr->value;
    prev->next = nullptr;
    delete curr;
    --length_;
    return v;
  }

  T& at_position(size_t index) const {
    if (index >= length_) {
      throw out_of_range("ListChain index out of range");
    }
    ListNode* curr = head_;
    for (size_t i = 0; i < index; ++i) {
      curr = curr->next;
    }
    return curr->value;
  }

  size_t locate(const T& value) const {
    size_t idx = 0;
    ListNode* curr = head_;
    while (curr) {
      if (curr->value == value) {
        return idx;
      }
      curr = curr->next;
      ++idx;
    }
    return static_cast<size_t>(-1);
  }

  void erase_last_match(const T& value) {
    if (locate(value) == static_cast<size_t>(-1)) {
      throw invalid_argument("value not found in ListChain");
    }

    ListNode* curr = head_;
    ListNode* prev = nullptr;
    ListNode* last = nullptr;
    ListNode* before_last = nullptr;

    while (curr) {
      if (curr->value == value) {
        last = curr;
        before_last = prev;
      }
      prev = curr;
      curr = curr->next;
    }

    if (!last) {
      return;
    }

    if (last == head_) {
      head_ = last->next;
    } else if (before_last) {
      before_last->next = last->next;
    }

    delete last;
    --length_;
  }

  void insert_before_index(size_t index, const T& value) {
    if (index >= length_) {
      throw out_of_range("insert_before_index out of range");
    }

    if (index == 0) {
      prepend(value);
      return;
    }

    ListNode* curr = head_;
    ListNode* prev = nullptr;
    for (size_t i = 0; i < index; ++i) {
      prev = curr;
      curr = curr->next;
    }

    ListNode* node = new ListNode(value, curr);
    prev->next = node;
    ++length_;
  }

  void drop_every_other() {
    ListNode* curr = head_;
    while (curr && curr->next) {
      ListNode* victim = curr->next;
      curr->next = victim->next;
      delete victim;
      --length_;
      curr = curr->next;
    }
  }

  string as_string() const {
    stringstream ss;
    ss << "[";
    ListNode* curr = head_;
    size_t idx = 0;
    while (curr) {
      ss << curr->value;
      if (idx + 1 < length_) {
        ss << ", ";
      }
      curr = curr->next;
      ++idx;
    }
    ss << "]";
    return ss.str();
  }

  void purge() {
    ListNode* curr = head_;
    while (curr) {
      ListNode* next = curr->next;
      delete curr;
      curr = next;
    }
    head_ = nullptr;
    length_ = 0;
  }

  // Expose raw head pointer for algorithm-style functions (e.g. LeetCode).
  void* raw_head() const {
    return head_;
  }
};
