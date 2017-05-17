# -*- coding:utf-8 -*-


# Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
#
#
# For example,
#
# 123 -> "One Hundred Twenty Three"
# 12345 -> "Twelve Thousand Three Hundred Forty Five"
# 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"


class Solution(object):
    def numStr2Words(self, num):
        l = len(num)
        if int(num) == 0:
            return ''
        small = {0: '', 1: 'One', 2: 'Two', 3: 'Three', 4: 'Four', 5: 'Five', 6: 'Six', 7: 'Seven', 8: 'Eight', 9: 'Nine',
                 10: 'Ten', 11: 'Eleven', 12: 'Twelve', 13: 'Thirteen', 14: 'Fourteen', 15: 'Fifteen', 16: 'Sixteen',
                 17: 'Seventeen', 18: 'Eighteen', 19: 'Nineteen', 20: 'Twenty', 30: 'Thirty', 40: 'Forty', 50: 'Fifty',
                 60: 'Sixty', 70: 'Seventy', 80: 'Eighty', 90: 'Ninety'}
        if l == 1:
            return small[int(num)]
        elif l == 2:
            n = int(num)
            if n in small:
                return small[n]
            else:
                low = n % 10
                high = n - low
                return small[high] + ' ' + small[low]
        elif l == 3:
            if num[0] == '0':
                return self.numStr2Words(num[1:]).strip()
            else:
                return (self.numStr2Words(num[0]) + ' Hundred ' + self.numStr2Words(num[1:])).strip()
        elif l > 3 and l < 7:
            if int(num[:l - 3]) == 0:
                return self.numStr2Words(num[l - 3:]).strip()
            else:
                return (self.numStr2Words(num[:l - 3]) + ' Thousand ' + self.numStr2Words(num[l - 3:])).strip()
        elif l > 6 and l < 10:
            if int(num[:l - 6]) == 0:
                return self.numStr2Words(num[l - 6:]).strip()
            else:
                return (self.numStr2Words(num[:l - 6]) + ' Million ' + self.numStr2Words(num[l - 6:])).strip()
        elif l > 9:
            if int(num[:l - 9]) == 0:
                return self.numStr2Words(num[l - 9:]).strip()
            else:
                return (self.numStr2Words(num[:l - 9]) + ' Billion ' + self.numStr2Words(num[l - 9:])).strip()
    
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return 'Zero'
        else:
            return self.numStr2Words(str(num))
        
