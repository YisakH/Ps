class Solution(object):
    def removeOccurrences(self, s, part):
        st = []
        for ch in s:
            st.append(ch)

            while len(st) >= len(part) and "".join(st[-len(part):]) == part:
                st = st[:-len(part)]
        
        return "".join(st)
        