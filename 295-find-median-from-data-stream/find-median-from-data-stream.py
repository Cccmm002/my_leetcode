# -*- coding:utf-8 -*-


# Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
# For example,
#
# [2,3,4], the median is 3
#
# [2,3], the median is (2 + 3) / 2 = 2.5
#
# Design a data structure that supports the following two operations:
#
#
# 	void addNum(int num) - Add a integer number from the data stream to the data structure.
# 	double findMedian() - Return the median of all elements so far.
#
#
# Example:
#
#
# addNum(1)
# addNum(2)
# findMedian() -> 1.5
# addNum(3) 
# findMedian() -> 2
#
#


class MaxHeapObj(object):
    def __init__(self, val): self.val = val
    def __lt__(self, other): return self.val > other.val
    def __eq__(self, other): return self.val == other.val
    def __str__(self): return str(self.val)

class MinHeap(object):
    def __init__(self): 
        self.h = []
    def heappush(self,x): 
        heapq.heappush(self.h, x)
    def heappop(self): 
        return heapq.heappop(self.h)
    def heaptop(self):
        return self.h[0]
    def __getitem__(self,i): 
        return self.h[i]
    def __len__(self): 
        return len(self.h)
    
class MaxHeap(MinHeap):
    def heappush(self,x): 
        heapq.heappush(self.h,MaxHeapObj(x))
    def heappop(self): 
        return heapq.heappop(self.h).val
    def heaptop(self):
        return self.h[0].val
    def __getitem__(self,i): 
        return self.h[i].val

class MedianFinder(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.small = MaxHeap()
        self.large = MinHeap()

    def addNum(self, num):
        """
        :type num: int
        :rtype: void
        """
        if num < self.findMedian():
            self.small.heappush(num)
            if len(self.small) > len(self.large) + 1:
                self.large.heappush(self.small.heaptop())
                self.small.heappop()
        else:
            self.large.heappush(num)
            if len(self.large) > len(self.small) + 1:
                self.small.heappush(self.large.heaptop())
                self.large.heappop()

    def findMedian(self):
        """
        :rtype: float
        """
        small_length, large_length = len(self.small), len(self.large)
        if small_length == 0 and large_length == 0:
            return 0
        if small_length == large_length:
            return (float(self.small.heaptop()) + float(self.large.heaptop()))/2.0;
        elif small_length > large_length:
            return float(self.small.heaptop())
        else:
            return float(self.large.heaptop())


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
