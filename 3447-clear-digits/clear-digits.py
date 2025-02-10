class Solution(object):
    def clearDigits(self, s):
        st = []
        for ch in s:
            if ch.isdigit() and st:
                st.pop()
            else:
                st.append(ch)
        
        return "".join(st)
        