# -*- coding:utf-8 -*-


# Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
#
#
# Note:
#
# If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
# All airports are represented by three capital letters (IATA code).
# You may assume all tickets form at least one valid itinerary.
#
#
#
#
#     Example 1:
#     tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
#     Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
#
#
#     Example 2:
#     tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
#     Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
#     Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
#
#
# Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.


class Solution(object):
    def recursive(self, m, cur, remaining):
        if remaining==0:
            return []
        if cur not in m:
            return None
        cur_list=m[cur]
        for i in cur_list:
            nl=cur_list[:]
            nl.remove(i)
            m[cur]=nl
            r=self.recursive(m,i,remaining-1)
            if r is not None:
                r.insert(0,i)
                return r
        m[cur]=cur_list
        return None
        
    
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        m={}
        total=0
        for l in tickets:
            total+=1
            if l[0] in m:
                m[l[0]].append(l[1])
            else:
                m[l[0]]=[l[1]]
        for k in m:
            m[k].sort()
        res=self.recursive(m,'JFK',total)
        res.insert(0,'JFK')
        return res
